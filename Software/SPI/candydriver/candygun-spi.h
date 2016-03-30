#ifndef CANDYGUN_SPI_H
#define CANDYGUN_SPI_H
#include <linux/spi/spi.h>

struct spi_device* candygun_get_device(void);
int candygun_spi_read_reg8(struct spi_device *spi, u8 addr, u8* value);
int candygun_spi_read_reg16(struct spi_device *spi, u8 addr, u16* value);
int candygun_spi_write_reg8(struct spi_device *spi, u8 addr, u8 data);
int candygun_spi_init(void);
void candygun_spi_exit(void);

#endif

