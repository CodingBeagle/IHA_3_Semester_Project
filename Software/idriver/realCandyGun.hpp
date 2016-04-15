#include "ICandyGun.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

class CandyGun : public ICandyGun
{
public:
	virtual bool SPITest();
	virtual bool I2CTest();
	virtual bool NunchuckTest();
};