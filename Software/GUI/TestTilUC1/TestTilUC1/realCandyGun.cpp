#include "realCandyGun.hpp"
#include <QFile>

#define BUFSIZEREAD 10
#define BUFSIZEWRITE 3

using namespace std;

bool CandyGun::SPITest()
{
	int fd;		//file handler
    char spiResult[BUFSIZEREAD] = "";

	//open candygun file
    fd = open("/dev/candygun", O_RDWR);
    if (fd == -1)
	{
        close(fd);
		return 0;
	}

	else
	{
		//send start SPI-test to PSoC
        char* spiTestCommand = "241";
        write(fd, spiTestCommand, BUFSIZEREAD);

        sleep(2);

		//read result of SPI-test from PSoC
        read(fd, spiResult, BUFSIZEWRITE);
	}



    if (strncmp(spiResult, "209", 3) == 0) // SPI-test SUCCES
    {
        close(fd);
        return 1;
    }
	else // SPI-test FAIL
    {
        close(fd);
        return 0;
    }
}

bool CandyGun::I2CTest()
{
	int fd;		//file handler
    char i2cResult[BUFSIZEREAD];

	//open candygun file
    fd = open("/dev/candygun", O_RDWR);
	if (fd == -1)
	{
        close(fd);
		return 0;
	}

	else
	{
		//send start I2C-test to PSoC
        write(fd, "242", BUFSIZEWRITE);

        sleep(2);

		//read result of I2C-test from PSoC
		read(fd, i2cResult, BUFSIZEREAD);

	}

	close(fd);

    if (strncmp(i2cResult, "210", 3) == 0) // I2C-test SUCCES
    {
        close(fd);
		return 1;
    }
	else //if i2cResult == 194 - I2C-test FAIL
    {
        close(fd);
        return 0;
    }
}

bool CandyGun::NunchuckTest()
{
	int fd;		//file handler
    char nunchuckResult[BUFSIZEREAD];
    int i = 0;

	//open candygun file
    fd = open("/dev/candygun", O_RDWR);
	if (fd == -1)
	{
        close(fd);
		return 0;
	}

	else
	{
		//send start Nunchuck-test to PSoC
        write(fd, "251", BUFSIZEWRITE);

		sleep(1);

        while ((strncmp(nunchuckResult, "211", 3) != 0) && i < 15)
            {
                sleep(1);

                //Read Nunchuck-test result from PSoC
                read(fd, nunchuckResult, BUFSIZEREAD);

                i++;
            }
	}

	close(fd);

    if (strncmp(nunchuckResult, "211", 3) == 0) // Nunchuck-test SUCCES
		return 1;
	else //if nunchuckRsult == 195 - Nunchuck-test FAIL
		return 0;
}
