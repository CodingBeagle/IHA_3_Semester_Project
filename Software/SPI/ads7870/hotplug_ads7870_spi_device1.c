#include <linux/init.h>
#include <linux/module.h>
#include <linux/spi/spi.h>
#include <linux/platform_data/spi-omap2-mcspi.h>
#include <asm/uaccess.h>
#include <linux/spi/spi.h>

MODULE_AUTHOR("PHM@IHA");
MODULE_LICENSE("Dual BSD/GPL");

static struct spi_device *slave_spi_device;

/* 
 * OMAP CPU SPI controller config
 */
static struct omap2_mcspi_device_config mcspi_config = {
  .turbo_mode	    = 0,
  .single_channel   = 1,  /* 0: slave, 1: master */
};

/* 
 * Slave Device Config
 */
statgic struct spi_board_info slave_spi_board_info = {
  .modalias	    = "ads7870", /*must be the same in driver and device*/
  .bus_num	    = 1, /*SPI1 from the OMAP*/
  .chip_select	    = 0, /*SPI1_CS0_CMOS*/
  .max_speed_hz	    = 15000000, /*max 20 MHz - 15 MHz to be safe*/
  .controller_data  = &mcspi_config,
  .mode             = SPI_MODE_3, /* Clock polarity - CPOL/CPHA = 11 */
};

static int hotplug_spi_init(void)
{
  int bus_num;
  struct spi_master *slaves_spi_master;

  printk(KERN_ALERT "Adding SPI Device: %s, bus: %i, chip-sel: %i\n", 
	 slave_spi_board_info.modalias, slave_spi_board_info.bus_num, slave_spi_board_info.chip_select);
  
  /* Add the slave SPI device to the SPI bus
   *
   * These methods are used to hot-plug spi devices.
   * SPI devices are by nature NOT hot-pluggable, as
   * they cannot be probed for functionality etc. SPI
   * devices are normally cold-plugged during boot, that
   * is, they are added in the board description file:
   * /arch/arm/mach-omap2/board-devkit8000.c
   * Using this method we actually doing "hot" cold-plugging
   * adding devices using a kernel module.
   * Note that it is crusial that driver and device uses
   * the same name alias. If not, the device and driver
   * will not be paired and the probe method in the driver
   * not be called.
   */ 
  bus_num = slave_spi_board_info.bus_num;
  slaves_spi_master = spi_busnum_to_master(bus_num);
  slave_spi_device = spi_new_device(slaves_spi_master,
				    &slave_spi_board_info);
  if(slave_spi_device < 0) {
    printk(KERN_ALERT "Unsuccesful creating a new device\n");
    return -1;
  }
    
  return 0;
}

static void hotplug_spi_exit(void)
{
  printk(KERN_ALERT "Removing SPI Device: %s, bus: %i, chip-sel: %i\n", 
	 slave_spi_board_info.modalias, slave_spi_board_info.bus_num, slave_spi_board_info.chip_select);
  spi_unregister_device(slave_spi_device);
}

module_init(hotplug_spi_init);
module_exit(hotplug_spi_exit);
