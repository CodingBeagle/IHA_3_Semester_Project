#pragma once 

using namespace std;

class ICandyGun
{
public:
	virtual bool SPITest() = 0;
	virtual bool I2CTest() = 0;
	virtual bool NunchuckTest() = 0;
};
