#include <linux/err.h>
#include <linux/ctype.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/input.h>
#include <linux/module.h>
#include "ads7870.h"
#include "ads7870-spi.h"

#define ADS7870_MAJOR       64
#define ADS7870_MINOR        0
#define MAXLEN              64
#define NBR_ADC_CH           8
#define COMPLIMENTARY_BIT   11

#define MODULE_DEBUG 0

/* Char Driver Globals */
static struct cdev ads7870Dev;
struct file_operations ads7870_Fops;
static int devno;

/* Pointer to SPI Device */
static struct spi_device *ads7870_spi_device = NULL;

/* Macro to handle Errors */
#define ERRGOTO(label, ...)                     \
  {                                             \
  printk (__VA_ARGS__);                         \
  goto label;                                   \
  } while(0)

/* 
 * LOCAL METHODS
 */
int ads7870_convert(u8 channel, s16* value)
{
  /* Start A/D Conversion on ADS7870 */
  /* See data sheet */
  u8 status;
  int err = ads7870_spi_write_reg8(ads7870_spi_device, 
				   ADS7870_GAINMUX, 
                                   ADS7870_GAIN_1X | 
                                   ADS7870_CH_SINGLE_ENDED |
                                   (channel & 0x07)| 
                                   ADS7870_CONVERT);

  if(err)
    return err;
  
  /* poll ADS7870 status register until "conversion done" flag is set */
  do
  {
    err = ads7870_spi_read_reg8(ads7870_spi_device, ADS7870_GAINMUX, &status);
  }
  while((!err) && ( (status & ADS7870_CONVERT) > 0));

  /* Read 16-bit conversion result */
  /* Actual result is signed but value */
  /*returned is unsinged and must be casted */
  err = ads7870_spi_read_reg16(ads7870_spi_device, ADS7870_RESULTLO, (u16*)value);

  /* Check if input voltage was out of range */
  /* and the internal amplifier made overflow */
  if(*value & ADS7870_RESULTLO_OVR)
    printk(KERN_ALERT "ADS7870: Error! PGA Out of Range\n");

  /* Right-align result, lower 4-bits are zero */
  *value = *value >> 4; 

  //  if(MODULE_DEBUG)
  printk(KERN_DEBUG "ADS7870: Channel %i result: %i mV\n", channel, *value);

  return err;
}

/*
 * PUBLIC METHODS
 */

static int __init ads7870_cdrv_init(void)
{
  int err; 
  
  printk("ADS7870 driver initializing\n");  

  /* Register SPI Driver */
  err=ads7870_spi_init();
  if(err)
    ERRGOTO(error, "Failed SPI Initialization\n");
  
  /* Allocate chrdev region */
  devno = MKDEV(ADS7870_MAJOR, ADS7870_MINOR);
  err = register_chrdev_region(devno, NBR_ADC_CH, "ads7870");  
  if(err)
    ERRGOTO(err_spi_init, "Failed registering char region (%d,%d) +%d, error %d\n",
            ADS7870_MAJOR, ADS7870_MINOR, NBR_ADC_CH, err);
  
  /* Register Char Device */
  cdev_init(&ads7870Dev, &ads7870_Fops);
  err = cdev_add(&ads7870Dev, devno, NBR_ADC_CH);
  if (err)
    ERRGOTO(err_register, "Error %d adding ADS7870 device\n", err);
  
  return 0;
  
  err_register:
  unregister_chrdev_region(devno, NBR_ADC_CH);

  err_spi_init:
  ads7870_spi_exit();
  
  error:
  return err;
}

static void __exit ads7870_cdrv_exit(void)
{
  printk("ads7870 driver Exit\n");
  cdev_del(&ads7870Dev);

  unregister_chrdev_region(devno, NBR_ADC_CH);

  ads7870_spi_exit();
}

int ads7870_cdrv_open(struct inode *inode, struct file *filep)
{
  int major = imajor(inode);
  int minor = iminor(inode);

  printk("Opening ADS7870 Device [major], [minor]: %i, %i\n", major, minor);

  /* Check if minor number is within range */
  if (minor > NBR_ADC_CH-1)
  {
    printk("Minor no out of range (0-%i): %i\n", NBR_ADC_CH, minor);
    return -ENODEV;
  }

  /* Check if a ads7870 device is registered */
  if(!(ads7870_spi_device=ads7870_get_device()))
    return -ENODEV;
  
  return 0;
}

int ads7870_cdrv_release(struct inode *inode, struct file *filep)
{
  int major = imajor(inode);
  int minor = iminor(inode);

  printk("Closing ADS7870 Device [major], [minor]: %i, %i\n", major, minor);

  if ((minor > NBR_ADC_CH-1) || !(ads7870_spi_device=ads7870_get_device()))
    return -ENODEV;
    
  return 0;
}

ssize_t ads7870_cdrv_write(struct file *filep, const char __user *ubuf, 
                           size_t count, loff_t *f_pos)
{
  int minor, len, value;
  char kbuf[MAXLEN];    
    
  minor = iminor(filep->f_inode);

  printk(KERN_ALERT "Writing to ads7870 [Minor] %i \n", minor);
    
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

  /* Legacy file ptr f_pos. Used to support 
   * random access but in char drv we dont! 
   * Move it the length actually  written 
   * for compability */
  *f_pos += len;

  /* return length actually written */
  return len;
}

ssize_t ads7870_cdrv_read(struct file *filep, char __user *ubuf, 
                          size_t count, loff_t *f_pos)
{
  int minor, len;
  char resultBuf[MAXLEN];
  s16 result;
  int err;
    
  minor = iminor(filep->f_inode);

  if(MODULE_DEBUG)
    printk(KERN_ALERT "Reading from ads7870 [Minor] %i \n", minor);
    
  /* Perform A/D Conversion */
  err = ads7870_convert((minor & 0xff), &result);
  if(err)
    return -EFAULT;
  
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



struct file_operations ads7870_Fops = 
{
  .owner   = THIS_MODULE,
  .open    = ads7870_cdrv_open,
  .release = ads7870_cdrv_release,
  .write   = ads7870_cdrv_write,
  .read    = ads7870_cdrv_read,
};

module_init(ads7870_cdrv_init);
module_exit(ads7870_cdrv_exit);

MODULE_AUTHOR("Peter Hoegh Mikkelsen <phm@iha.dk>");
MODULE_LICENSE("GPL");

