#include "CandyGun.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <QFile>
#include "ui_systemtester.h"

#define BUFSIZEREAD 4
#define BUFSIZEWRITE 3
#define MAX_BUFFER_SIZE 10

using namespace std;


//Delay function
void CandyGun::delay( int mSecsToWait )
{
    //Adds the selected amount of msecs to the current systemclock into waittime
    QTime waitTime = QTime::currentTime().addMSecs( mSecsToWait );
    //While the systemclock is less than the waittime, the loop is processing, allowing the gui to update
    //which would've failed with sleep();
    while( QTime::currentTime() < waitTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}


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

    delay(1000);

    fileHandle = open("/dev/candygun", O_RDWR);

    char spiTestResult[MAX_BUFFER_SIZE] = "";
    read(fileHandle, spiTestResult, MAX_BUFFER_SIZE);

    close(fileHandle);

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
    delay(2000);

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
    delay(5000);

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
