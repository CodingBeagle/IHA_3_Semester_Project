#include <linux/err.h>
#include <linux/ctype.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/input.h>
#include <linux/module.h>
#include "candygun.h"
#include "candygun-spi.h"

//#define CANDYGUN_MAJOR_NUMBER 97    //driver reference
//#define CANDYGUN_MINOR_NUMBER 0     //device reference
#define NUM_OF_MINORS 1        //We will only have one SPI device

#define MAXLEN              64
#define COMPLIMENTARY_BIT   11
#define MODULE_DEBUG 1

/* Char Driver Globals */
static struct cdev candygunDev;
struct file_operations candygun_Fops;
dev_t devno;

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

  my_SPI_Device = class_create(THIS_MODULE, "my_SPI_Device");
  if(my_SPI_Device == NULL)
  {
    printk(KERN_DEBUG"Failed to create class...\n");
    ERRGOTO(err_spi_init, "Failed registering char region error %d\n", err);
  }    

  candygun = device_create(my_SPI_Device, NULL, devno, NULL, "candygun");
  if(IS_ERR(candygun))
  {
    printk(KERN_DEBUG"Failed to create device...\n");
    ERRGOTO(err_spi_init, "Failed registering char region error %d\n", err);
  }

    
  
  return 0;
  
  err_register:
  unregister_chrdev_region(devno, NUM_OF_MINORS);

  err_spi_init:
  candygun_spi_exit();
  
  error:
  return err;
}

static void __exit candygun_cdrv_exit(void)
{
  printk("Candy gun driver Exit\n");

  device_destroy(my_SPI_Device, devno);
  class_destroy(my_SPI_Device);

  cdev_del(&candygunDev);

  unregister_chrdev_region(devno, NUM_OF_MINORS);

  candygun_spi_exit();
}

int candygun_cdrv_open(struct inode *inode, struct file *filep)
{
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

int candygun_cdrv_release(struct inode *inode, struct file *filep)
{
  int major = imajor(inode);
  int minor = iminor(inode);

  printk("Closing Candy Gun Device [major], [minor]: %i, %i\n", major, minor);

  if ((minor > NUM_OF_MINORS) || !(candygun_spi_device=candygun_get_device()))
    return -ENODEV;
    
  return 0;
}

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

  /*
   * Do something
   */


    candygun_spi_write_reg8(candygun_spi_device, 0x01, value);


  
  /* Legacy file ptr f_pos. Used to support 
   * random access but in char drv we dont! 
   * Move it the length actually  written 
   * for compability */
  *f_pos += len;

  /* return length actually written */
  return len;
}

ssize_t candygun_cdrv_read(struct file *filep, char __user *ubuf, 
                          size_t count, loff_t *f_pos)
{
  int minor, len;
  char resultBuf[MAXLEN];
  u8 result = 0;
  //int err ;
    
  minor = iminor(filep->f_inode);

  if(MODULE_DEBUG)
    printk(KERN_ALERT "Reading from candygun [Minor] %i \n", minor);
    
  /* Perform A/D Conversion */
  candygun_spi_read_reg8(candygun_spi_device, 0xF1, &result);

    //err = ads7870_convert((minor & 0xff), &result);
  //if(err)
  //  return -EFAULT;
  
  /* Convert to string and copy to user space */
  //  len = snprintf(resultBuf, sizeof resultBuf, "%d\n", result);
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

MODULE_AUTHOR("Tenna Rasmussen");
MODULE_LICENSE("GPL");

