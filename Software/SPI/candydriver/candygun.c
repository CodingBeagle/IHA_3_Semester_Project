#include <linux/err.h>
#include <linux/ctype.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/input.h>
#include <linux/module.h>
#include "candygun-spi.h"

#define NUM_OF_MINORS 1

/* MAXLEN is the max amount of bytes that are allowed to be copied from user space on write */
#define MAXLEN 64
#define MODULE_DEBUG 1

/* Char Driver Globals */
static struct cdev candygunDev;
struct file_operations candygun_Fops;
dev_t devno;

/* 
  Class and Device structs are used for dynamic allocation of device nodes
  and major numbers
*/
struct class* my_SPI_Device;   
struct device* candygun; 

/* Pointer to SPI Device */
static struct spi_device *candygun_spi_device = NULL;

/* Macro to handle Errors */
#define ERRGOTO(label, ...)                     \
  {                                             \
  printk (__VA_ARGS__);                         \
  goto label;                                   \
  } while(0)


/*
 * PUBLIC METHODS
 */

/* Kernel Module Initialize method. This is run when inserting the module into the kernel */
static int __init candygun_cdrv_init(void)
{
  int err; 
  
  printk("candygun driver initializing\n");  

  /* Register SPI Driver */
  err=candygun_spi_init();
  if(err)
    ERRGOTO(error, "Failed SPI Initialization\n");
  
  /* Allocate chrdev region */
  if(alloc_chrdev_region(&devno, 0, NUM_OF_MINORS, "my_Spi_Device") < 0)
  {
    printk(KERN_DEBUG"Failed to allocate major and minor number");

    ERRGOTO(err_spi_init, "Failed registering char region error %d\n", err);
  }
  
  /* Register Char Device */
  cdev_init(&candygunDev, &candygun_Fops);
  candygunDev.owner = THIS_MODULE;
  err = cdev_add(&candygunDev, devno, 1);
  if (err != 0)
  {
    printk(KERN_ALERT "Failed to add cdev...\n");
    ERRGOTO(err_register, "Error %d adding candy gun device\n", err);
  }

  /* Create class */
  my_SPI_Device = class_create(THIS_MODULE, "my_SPI_Device");
  if(my_SPI_Device == NULL)
  {
    printk(KERN_DEBUG"Failed to create class...\n");
    ERRGOTO(err_spi_init, "Failed registering char region error %d\n", err);
  }    

  /* Create device */
  candygun = device_create(my_SPI_Device, NULL, devno, NULL, "candygun");
  if(IS_ERR(candygun))
  {
    printk(KERN_DEBUG"Failed to create device...\n");
    ERRGOTO(err_spi_init, "Failed registering char region error %d\n", err);
  }
 
  return 0;
  
  /* Error Handling Region */
  err_register:
  unregister_chrdev_region(devno, NUM_OF_MINORS);

  err_spi_init:
  candygun_spi_exit();
  
  error:
  return err;
}

/* Kernel module exit method. This is run when removing the kernel module from the kernel */
static void __exit candygun_cdrv_exit(void)
{
  printk("Candy gun driver Exit\n");

  /* Destroy class and device */
  device_destroy(my_SPI_Device, devno);
  class_destroy(my_SPI_Device);

  /* Delete cdev struct */
  cdev_del(&candygunDev);

  /* Unregister chrdev region in order to release its memory usage */
  unregister_chrdev_region(devno, NUM_OF_MINORS);

  /*  */
  candygun_spi_exit();
}

/* Kernel module open method. This is run when the node is opened (for example when reading or writing)  */
int candygun_cdrv_open(struct inode *inode, struct file *filep)
{
  /* Retrieve major and minor number */
  int major = imajor(inode);
  int minor = iminor(inode);

  printk("Opening Candy Gun Device [major], [minor]: %i, %i\n", major, minor);

  /* Check if minor number is within range */
  if (minor > NUM_OF_MINORS)
  {
    printk("Minor no out of range (0-%i): %i\n", NUM_OF_MINORS, minor);
    return -ENODEV;
  }

  /* Check if a candygun device is registered */
  if(!(candygun_spi_device=candygun_get_device()))
    return -ENODEV;
  
  return 0;
}

/* Kernel Module release method. This method is called when the kernel module is closed */
int candygun_cdrv_release(struct inode *inode, struct file *filep)
{
  /* Retrieve major and minor number */
  int major = imajor(inode);
  int minor = iminor(inode);

  printk("Closing Candy Gun Device [major], [minor]: %i, %i\n", major, minor);

  if ((minor > NUM_OF_MINORS) || !(candygun_spi_device=candygun_get_device()))
    return -ENODEV;
    
  return 0;
}

/* Kernel Module write method. This method is called when writing to the device node related to this driver */
ssize_t candygun_cdrv_write(struct file *filep, const char __user *ubuf, 
                           size_t count, loff_t *f_pos)
{
  int minor, len, value;
  char kbuf[MAXLEN];    
    
  minor = iminor(filep->f_inode);

  printk(KERN_ALERT "Writing to candy gun [Minor] %i \n", minor);
    
  /* Limit copy length to MAXLEN allocated andCopy from user */
  len = count < MAXLEN ? count : MAXLEN;
  if(copy_from_user(kbuf, ubuf, len))
    return -EFAULT;
	
  /* Pad null termination to string */
  kbuf[len] = '\0';   

  if(MODULE_DEBUG)
    printk("string from user: %s\n", kbuf);

  /* Convert sting to int */
  sscanf(kbuf,"%i", &value);
  if(MODULE_DEBUG)
    printk("value %i\n", value);

    // Write user value to the SPI bus
    candygun_spi_write(candygun_spi_device, 0x01, value);
  
  /* Legacy file ptr f_pos. Used to support 
   * random access but in char drv we dont! 
   * Move it the length actually  written 
   * for compability */
  *f_pos += len;

  /* return length actually written */
  return len;
}

/* Kernel Module read method. This method is called when reading the device node related to this driver */
ssize_t candygun_cdrv_read(struct file *filep, char __user *ubuf, 
                          size_t count, loff_t *f_pos)
{
  int minor, len;
  char resultBuf[MAXLEN];
  u8 result = 0;
    
  minor = iminor(filep->f_inode);

  if(MODULE_DEBUG)
    printk(KERN_ALERT "Reading from candygun [Minor] %i \n", minor);
    
  /* Read value from SPI Bus */
  candygun_spi_read(candygun_spi_device, 0xF1, &result);

  /* Convert to string and copy to user space */
  /* Convert integer to string limited to "count" size. Returns
   * length excluding NULL termination */
  len = snprintf(resultBuf, count, "%d\n", result);
  len++;

  /* Copy data to user space */
  if(copy_to_user(ubuf, resultBuf, len))
    return -EFAULT;

  /* Move fileptr */
  *f_pos += len;

  return len;
}

struct file_operations candygun_Fops = 
{
  .owner   = THIS_MODULE,
  .open    = candygun_cdrv_open,
  .release = candygun_cdrv_release,
  .write   = candygun_cdrv_write,
  .read    = candygun_cdrv_read,
};

module_init(candygun_cdrv_init);
module_exit(candygun_cdrv_exit);

MODULE_AUTHOR("Semester Projekt Gruppe 3");
MODULE_LICENSE("GPL");

