#ifndef SPICOMMUNICATION_H
#define SPICOMMUNICATION_H
#include "Project.h"
#include <time.h>
    
    
#define START_SPI_TEST 0xF1
#define START_I2C_TEST 0xF2
#define START_NUNCHUCK_TEST 0xF3
#define SPI_OK 0xD1
#define I2C_OK 0xD2
#define I2C_FAIL 0xC2
#define NUNCHUCK_OK 0xD3
#define NUNCHUCK_FAIL 0xC3


int testI2C;
int testNunchuck;
clock_t testNunchuckTimer, diff;


//Completes the SPI test by writing SPI_OK to the outgoing spi register 
void completeSPITest();

//Enables the I2C test by setting testI2C to 1 
void startI2CTest();

//Runs through the I2C test if testI2C is set to 1.
void completeI2CTest();

//Enables the Nunchuck test by setting testNunchuck to 1
void startNunchuckTest();

//Runs through the Nunchuck test if testNunchuck is set to 1
void completeNunchuckTest(uint8 *dataBuffer);



#endif