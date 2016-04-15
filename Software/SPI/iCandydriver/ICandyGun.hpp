#include "candygun.c"

class Icandygun{
	public:
		virtual bool SPITest();
		virtual bool I2CTest();
		virtual bool WiiTest();
}
