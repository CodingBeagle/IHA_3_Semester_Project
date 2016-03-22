#ifndef COMMUNICATIONPROTOCOL_H
#define COMMUNICATIONPROTOCOL_H
#include "Project.h"    
    
//Define different adresses and commands
#define PSoC0UnitAdress 0x08
#define PSoC1UnitAdress 0x09
#define PSoC2UnitAdress 0x10

#define NunchuckDataCommand 42
#define slaveBufferMaxSize 4

    
// Sends data to the Adress with a commandtype ID
// The buffer contains the data to send (eg. Nunchuck readings)
void sendData(uint32 Adress, uint8 CommandType, uint8* buffer, uint8 bufferSize);

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
    
    
    
    