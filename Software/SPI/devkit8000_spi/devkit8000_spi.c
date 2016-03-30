#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/uaccess.h>        //copy_to_user
#include <linux/module.h>

// SPI driver til semesterprojekt 3 //

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Driver for Devkit8000 SPI");
MODULE_AUTHOR("E3PRJ3 - group3 - TR);

#define SPI_MAJOR_NUMBER 97    //driver reference
#define SPI_MINOR_NUMBER 0     //device reference
#define NUM_OF_MINORS 1        //We will only have one SPI device

/*Evt. SPI relaterede defines (buffer/bit/bytetal/Pins)*/
static struct spi_device *devkit8000_spi_device = NULL;

static struct cdev devkit_spi_Dev;
struct file_operations devkit_spi_Fops;
dev_t devno = 0;


//******************************************************************
// spi_driver (global)
//******************************************************************
static struct spi_driver devkit8000_spi_driver = {
    .driver{
        .name = "devkit8000_spi",   //must be the same as modalias in hotplug
        .bus = &spi_bus_type,       //???
        .owner = THIS_MODULE,
    },
    .probe = devkit8000_spi_probe,
    .remove = devkit8000_spi_remove
};


//******************************************************************
// init function
//******************************************************************

static int devkit8000_spi_init(void)
{
    int err;
    
    // request SPI
    err = spi_register_driver(&devkit8000_spi_driver);
    if(err<0)
    { 
        printk(KERN_ALERT "Error %d registering the devkit 8000 SPI driver\n", err);
        goto err_exit;
    }
    
    // specification of major & minor numbers
    devno = MKDEV(SPI_MAJOR_NUMBER, SPI_MINOR_NUMBER);
    
    // allocating device numbers
    err = register_chrdev_region(devno, NUM_OF_MINORS, "SPI_device");
    if(err != 0)
    {
        printk(KERN_ALERT "Error register chardev region (%d, %d), error %d\n", MAJOMAJOR_NUMBER, SPI_MINOR_NUMBER, err);
        goto err_spi_init;
    }
    
    // cdev init
    cdev_init(&devkit_spi_Dev, &devkit_spi_Fops);
    
    // add cdev (tells the kernel about the cdev structure)
    err = cdev_add(&devkit_spi_Dev, devno, NUM_OF_MINORS);
    if(err != 0)
    {
        printk(KERN_ALERT "Error add cdev, error %d\n", err);
        goto err_dev_unregister;
    }
    
    return 0;
    
    // error handling
    err_dev_unregister:
    unregister_chrdev_region(devno, NUM_OF_MINORS);
    
    err_spi_init:
    devkit8000_spi_exit();
    
    err_exit:
    return err;
}


//******************************************************************
// probe function
//******************************************************************
static int devkit8000_spi_probe(struct spi_device *spi)
{
    u16 value;
    
    printk(KERN_DEBUG "New SPI device: %s using chip select: %i\n", 
           spi->modalias, spi->chip_select);
    
    spi->bits_per_word = 16;   // command 2bit, addr 6bit, data 8bit 
    spi_setup(spi);     // implements the parameters
    
    // only one device
    devkit8000_spi_device = spi;
    
    printk(KERN_DEBUG "Probing SPI\n"); // to see when probefunction is called

    return 0;
}


//******************************************************************
// exit function
//******************************************************************
static void devkit8000_spi_exit(void)
{
    printk("Devkit 8000 SPI driver exit\n");
    
    // delete cdev
    cdev_del(&devkit_spi_Dev);
    
    // unregiter device
    unregister_chrdev_region(devno, NUM_OF_MINORS);
    
    // Free SPI
    spi_unregister_driver(&devkit8000_spi_driver);
}


//******************************************************************
// remove function
//******************************************************************
static int devkit8000_spi_remove(struct spi_device *spi)
{
    devkit8000_spi_device = NULL;
    
    printk(KERN_ALERT "Removing SPI device %s on chip select %i\n", 
           spi->modalias, spi->chip_select);
    
    return 0;
}


