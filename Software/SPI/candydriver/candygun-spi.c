#include <linux/err.h>
#include <linux/spi/spi.h>
#include <linux/module.h>

#define MODULE_DEBUG 1

/* Candy Gun Device Data */
struct candygun {
  int revision;
};

/* The read data from the SPI bus */
u8 receivedData = 0;

/* We are only using ONE SPI device so far */
static struct spi_device *candygun_spi_device = NULL;

/* Method to retrieve SPI device pointer */
struct spi_device* candygun_get_device(void){
  return candygun_spi_device;
}

int candygun_spi_read(struct spi_device *spi, u8* value)
{
	struct spi_transfer t[2];
	struct spi_message m;

  /* Check for valid spi device */
  if(!spi)
    return -ENODEV;

	/* Init Message struct */
	memset(t, 0, sizeof(t));
	spi_message_init(&m);
	m.spi = spi;

	/* Configure tx/rx buffers */
	t[0].tx_buf = NULL;
	t[0].rx_buf = &receivedData;
	t[0].len = 1;
  t[0].delay_usecs = 150;

	spi_message_add_tail(&t[0], &m);

	/* Transmit SPI Data (blocking) */
	spi_sync(m.spi, &m);

	if(MODULE_DEBUG)
	  printk(KERN_DEBUG "Candygun: Read value from SPI bus: %x\n", receivedData);

  /* Return read SPI bus value to user */
  //(*value) = receivedData;

	return receivedData;
}

/*
 * Candy Gun SPI Write 8-bit Register
 * Writes 8-bit content to register at 
 * the provided CANDYGUN address
 */
int candygun_spi_write(struct spi_device *spi, u8 addr, u8 data)
{
  struct spi_transfer t[1];
  struct spi_message m;

  /* Check for valid spi device */
    if(!spi)
    return -ENODEV;

  /* Init Message */
  memset(&t, 0, sizeof(t)); 
  spi_message_init(&m);
  m.spi = spi;

  if(MODULE_DEBUG)
    printk(KERN_DEBUG "candygun: Writing value to SPI Bus: %02x\n", data);

  /* Configure tx/rx buffers */
  t[0].tx_buf = &data;
  t[0].rx_buf = NULL;
  t[0].len = 1; //Tranfers size in bytes

  /* Add spi message to transaction */
  spi_message_add_tail(&t[0], &m);

  /* Transmit SPI Data (blocking) */
  spi_sync(m.spi, &m);

  return 0;
}

/*
 * CANDYGUN Probe
 * Used by the SPI Master to probe the device
 * when an SPI device is registered.
 */
static int candygun_spi_probe(struct spi_device *spi)
{  
  printk(KERN_DEBUG "New SPI device: %s using chip select: %i\n",
	 spi->modalias, spi->chip_select);
  
  spi->bits_per_word = 8;  // For PSoC communication, we only need 8 bit for the communication protocol
  spi_setup(spi);

  /* In this case we assume just one device */ 
  candygun_spi_device = spi;  
 
  //err = candygun_spi_read_reg8(spi, ADS7870_ID, &value);
  printk(KERN_DEBUG "Probing candy gun\n");

  return 0;
}

/*
 * Candygun Remove
 * Called when the SPI device is removed
 */
static int candygun_remove(struct spi_device *spi)
{  
  candygun_spi_device = 0;
  
  printk (KERN_ALERT "Removing SPI device %s on chip select %i\n", 
	  spi->modalias, spi->chip_select);

  return 0;
}

/*
  SPI Driver description struct
*/
static struct spi_driver candygun_spi_driver = {
  .driver = {
    .name = "candygun",
    .bus = &spi_bus_type,
    .owner = THIS_MODULE,
  },
  .probe = candygun_spi_probe,
  .remove = candygun_remove,
};

/*
 * CANDYGUN SPI Init
 * Registers the spi driver with the SPI host
 */
int candygun_spi_init(void)
{
  int err;

  err = spi_register_driver(&candygun_spi_driver);
  
  if(err<0)
    printk (KERN_ALERT "Error %d registering the candygun SPI driver\n", err);
  
  return err;
}

/*
 * ADS7870 SPI Exit
 * Exit routine called from character driver.
 * Unregisters the driver from the SPI host
 */
void candygun_spi_exit(void)
{
  spi_unregister_driver(&candygun_spi_driver); 
}
