#ifndef COMMUNICATIONPROTOCOL_H
#define COMMUNICATIONPROTOCOL_H
#include "Project.h"    
    
//Define different adresses and commands
#define PSoC0UnitAddress 0x08
#define PSoC1UnitAddress 0x09
#define PSoC2UnitAddress 0x10

#define NunchuckData 0xA2
#define I2CTestRequest 0x29
#define I2CTestACK 0x28
#define slaveBufferMaxSize 4

    
// Sends data to the Address with a commandtype ID
// The buffer contains the data to send (eg. Nunchuck readings)
void sendData(uint32 Address, uint8 CommandType, uint8* buffer, uint8 bufferSize);

// Initialize initReceiveData to slaveWriteBuffer with a size of slaveBufferMaxSize (4)
void initReceiveData();


// Receive data will make the device listen to the I2C network
// If a match occurs it will compare the commandtype with known values,
// and process the data accordingly.
// The received data will be saved into the buffer.
void receiveData(uint8* buffer);


uint8 slaveWriteBuffer[slaveBufferMaxSize];
uint8 slaveReadBuffer[slaveBufferMaxSize];

#endif
    
    
    
    