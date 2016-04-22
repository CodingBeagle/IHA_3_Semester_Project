#include "SimulCandyGun.hpp"

using namespace std;

bool SimulCandyGun::SPITest()
{
	srand(time(0));
	if (rand() % 2)
		return true;
	else
		return false;
}

bool SimulCandyGun::I2CTest()
{
	srand(time(0));
	if (rand() % 2)
		return true;
	else
		return false;
}

bool SimulCandyGun::NunchuckTest()
{
	srand(time(0));
	if (rand() % 2)
		return true;
	else
		return false;
}
