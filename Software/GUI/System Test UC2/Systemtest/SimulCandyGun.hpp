#include "ICandyGun.hpp"
#include <cstdlib>
#include <time.h>

#pragma once

using namespace std;

class SimulCandyGun : public ICandyGun
{
public:
    virtual bool SPITest();
	virtual bool I2CTest();
	virtual bool NunchuckTest();
};
