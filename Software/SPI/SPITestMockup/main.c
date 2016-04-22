#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define O_RDWR 02

#define MAX_BUFFER_SIZE 10

int main(void)
{
	char spiTestCommand1[] = "241";
	char spiTestCommand2[] = "242";
	char spiTestCommand3[] = "243";

	// Open Candygun file
	int fileHandle = open("/dev/candygun", O_RDWR);

	// Test SPI
	printf("Testing SPI...\n");

	//char* spiTestCommand = "241";
	write(fileHandle, spiTestCommand1, 3);

	close(fileHandle);

	sleep(2);

	fileHandle = open("/dev/candygun", O_RDWR);

	char spiTestResult[MAX_BUFFER_SIZE] = "";
	read(fileHandle, spiTestResult, MAX_BUFFER_SIZE);

	close(fileHandle);
	sleep(1);

	if (strncmp(spiTestResult, "209", 3) == 0)
	{
		printf("Spi Test Succeeded!\n");
	}
	else
	{
		printf("Spi Test Failed!\n");
		return -1;
	}

	fileHandle = open("/dev/candygun", O_RDWR);

	printf("Testing I2C...\n");

	//spiTestCommand = "242";
	write(fileHandle, spiTestCommand2, 3);

	close(fileHandle);
	sleep(2);

	fileHandle = open("/dev/candygun", O_RDWR);

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

	close(fileHandle);

	printf("Testing Wii-Nunchuck...\n");
	printf("Please press the Z button within 6 seconds...\n");
	//spiTestCommand = "243";

	fileHandle = open("/dev/candygun", O_RDWR);

	write(fileHandle, spiTestCommand3, 3);

	int counter = 0;

	close(fileHandle);
	sleep(6);

	fileHandle = open("/dev/candygun", O_RDWR);

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

	close(fileHandle);

	return 0;
}