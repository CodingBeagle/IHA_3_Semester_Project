#include "realCandyGun.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <QFile>
#include "ui_systemtester.h"

#define BUFSIZEREAD 4
#define BUFSIZEWRITE 3
#define MAX_BUFFER_SIZE 10

using namespace std;

bool CandyGun::SPITest()
{
    char spiTestCommand1[] = "241";

    // Open Candygun file
    int fileHandle = open("/dev/candygun", O_RDWR);

    if (fileHandle == -1)
    {
        return -1;
    }

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
        return 1;
    }

    return 0;
}

bool CandyGun::I2CTest()
{
    char spiTestCommand2[] = "242";

    int fileHandle = open("/dev/candygun", O_RDWR);

    write(fileHandle, spiTestCommand2, 3);

    close(fileHandle);
    sleep(2);

    fileHandle = open("/dev/candygun", O_RDWR);

    char spiTestResult[MAX_BUFFER_SIZE] = "";
    read(fileHandle, spiTestResult, MAX_BUFFER_SIZE);

    close(fileHandle);

    if (strncmp(spiTestResult, "210", 3) == 0)
    {
        return 1;
    }

    return 0;
}

bool CandyGun::NunchuckTest()
{
    char spiTestCommand3[] = "243";

    int fileHandle = open("/dev/candygun", O_RDWR);

    write(fileHandle, spiTestCommand3, 3);

    close(fileHandle);
    sleep(5);

    fileHandle = open("/dev/candygun", O_RDWR);

    char spiTestResult[MAX_BUFFER_SIZE] = "";
    read(fileHandle, spiTestResult, MAX_BUFFER_SIZE);

    close(fileHandle);

    if (strncmp(spiTestResult, "211", 3) == 0)
    {
        return 1;
    }

    return 0;
}
