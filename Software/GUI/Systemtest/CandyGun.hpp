#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

class CandyGun
{
public:
    bool SPITest();
    bool I2CTest();
    bool NunchuckTest();
};
