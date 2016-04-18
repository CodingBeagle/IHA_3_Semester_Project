#include "realCandyGun.hpp"

#define BUFSIZEREAD = 4
#define BUFSIZEWRITE = 3

using namespace std;

bool ICandyGunSPI::SPITest()
{
	int fd;		//file handler
	char* spiResult[BUFSIZE];

	//open candygun file
	fd = open("dev/candygun", O_RDWR);
	if (fd == -1)
	{
		return 0;
	}

	else
	{
		//send start SPI-test to PSoC
		fd = write(fd, "241", BUFSIZEWRITE);
		if (fd == -1)
		{
			return 0;
		}

		sleep(1);

		//read result of SPI-test from PSoC
		read(fd, spiResult, BUFSIZEREAD);
		if (fd == -1)
		{
			return 0;
		}
	}

	close(fd);

	if (spiResult == "209") // SPI-test SUCCES
		return 1;
	else // SPI-test FAIL
		return 0;
}

bool ICandyGunSPI::I2CTest()
{
	int fd;		//file handler
	char* i2cResult[BUFSIZEREAD];

	//open candygun file
	fd = open("dev/candygun", O_RDWR);
	if (fd == -1)
	{
		return 0;
	}

	else
	{
		//send start I2C-test to PSoC
		fd = write(fd, "242", BUFSIZEWRITE);
		if (fd == -1)
		{
			return 0;
		}

		sleep(1);

		//read result of I2C-test from PSoC
		read(fd, i2cResult, BUFSIZEREAD);
		if (fd == -1)
		{
			return 0;
		}
	}

	close(fd);

	if (i2cResult == "210") // I2C-test SUCCES
		return 1;
	else //if i2cResult == 194 - I2C-test FAIL
		return 0;
}

bool ICandyGunSPI::NunchuckTest()
{
	int fd;		//file handler
	char* nunchuckResult[BUFSIZEREAD];
	int i = 0;

	//open candygun file
	fd = open("dev/candygun", O_RDWR);
	if (fd == -1)
	{
		return 0;
	}

	else
	{
		//send start Nunchuck-test to PSoC
		fd = write(fd, "251", BUFSIZEWRITE);
		if (fd == -1)
		{
			return 0;
		}

		while (nunchuckResult != "211" && i < 15)
		{
			sleep(1);

			//Read Nunchuck-test result from PSoC
			read(fd, nunchuckResult, BUFSIZEREAD);
			
			i++;
		}
	}

	close(fd);

	if (nunchuckResult == "211") // Nunchuck-test SUCCES
		return 1;
	else //if nunchuckRsult == 195 - Nunchuck-test FAIL
		return 0;
}