#include "SimulCandyGun.hpp"
#include "CandyGun.hpp"
#include <iostream>


using namespace std;

int main()
{
	ICandyGun* theGun;
	//theGun = new realCandyGun(); // For-real candy gun
	theGun = new SimulCandyGun(); // For test

	cout << theGun->SPITest() << endl;
}
