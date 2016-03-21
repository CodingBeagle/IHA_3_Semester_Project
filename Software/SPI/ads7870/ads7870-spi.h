#ifndef ADS7870_SPI_H
#define ADS7870_SPI_H
#include <linux/spi/spi.h>

struct spi_device* ads7870_get_device(void);
int ads7870_spi_read_reg8(struct spi_device *spi, u8 addr, u8* value);
int ads7870_spi_read_reg16(struct spi_device *spi, u8 addr, u16* value);
int ads7870_spi_write_reg8(struct spi_device *spi, u8 addr, u8 data);
int ads7870_spi_init(void);
void ads7870_spi_exit(void);

#endif

