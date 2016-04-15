#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define O_RDWR 02

#define MAX_BUFFER_SIZE 10

int main(void)
{
	// Open Candygun file
	int fileHandle = open("/dev/candygun", O_RDWR);

	// Test SPI
	printf("Testing SPI...\n");

	char* spiTestCommand = "241";
	write(fileHandle, spiTestCommand, 3);

	sleep(1);

	char spiTestResult[MAX_BUFFER_SIZE] = "";
	read(fileHandle, spiTestResult, MAX_BUFFER_SIZE);

	if (strncmp(spiTestResult, "209", 3) == 0)
	{
		printf("Spi Test Succeeded!\n");
	}
	else
	{
		printf("Spi Test Failed!\n");
		return -1;
	}

	printf("Testing I2C...\n");

	spiTestCommand = "242";
	write(fileHandle, spiTestCommand, 3);

	sleep(2);

	read(fileHandle, spiTestResult, MAX_BUFFER_SIZE);

	if (strncmp(spiTestResult, "210", 3) == 0)
	{
		printf("I2C Test Succeeded!\n");
	}
	else
	{
		printf("I2C Test Failed!\n");
		return -1;
	}

	printf("Testing Wii-Nunchuck...\n");
	printf("Please press the Z button within 6 seconds...\n");
	spiTestCommand = "243";
	write(fileHandle, spiTestCommand, 3);

	int counter = 0;

	sleep(6);

	read(fileHandle, spiTestResult, MAX_BUFFER_SIZE);

	if (strncmp(spiTestResult, "211", 3) == 0)
	{
		printf("Wii-Nunchuck Test Succeeded!\n");
	}
	else
	{
		printf("Wii-Nunchuck Test Failed!\n");
		return -1;
	}

	return 0;
}