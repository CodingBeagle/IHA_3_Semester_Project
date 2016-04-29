#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <QTime>

class CandyGun
{
public:
    bool SPITest();
    bool I2CTest();
    bool NunchuckTest();
    static void delay(int ms);
};
