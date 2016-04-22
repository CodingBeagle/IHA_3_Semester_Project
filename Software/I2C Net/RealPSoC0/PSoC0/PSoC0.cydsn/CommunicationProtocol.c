#include "CommunicationProtocol.h"
#include "Project.h"

void sendData(uint32 Address, uint8 CommandType, uint8* buffer, uint8 bufferSize)
{
    int readError = 0;
    int i;
    I2C_1_I2CMasterClearStatus();
    readError = I2C_1_I2CMasterSendStart(Address, I2C_1_I2C_WRITE_XFER_MODE);
    if (readError == I2C_1_I2C_MSTR_NO_ERROR)
    {
        // Send command type
        I2C_1_I2CMasterWriteByte(CommandType);
        
        // Send Nunchuck data from the buffer.
        for(i = 0; i < bufferSize; i++)
        {
            I2C_1_I2CMasterWriteByte(buffer[i]);
        }
    }
    I2C_1_I2CMasterSendStop();
    I2C_1_I2CMasterClearStatus();
}

void initReceiveData()
{
    //Set slave write buffer
    I2C_1_I2CSlaveInitWriteBuf(slaveWriteBuffer, slaveBufferMaxSize);
    //Set slave read buffer
    I2C_1_I2CSlaveInitReadBuf(slaveReadBuffer, slaveBufferMaxSize);
}


void receiveData(uint8* receivedDataBuffer)
{
    if (I2C_1_I2CSlaveStatus() == I2C_1_I2C_SSTAT_WR_CMPLT)
    {
        int i;
        for(i = 0; i<slaveBufferMaxSize; i++)
        {
            receivedDataBuffer[i] = (int)slaveWriteBuffer[i];
        }
        
        I2C_1_I2CSlaveClearWriteBuf();
    }
    
    I2C_1_I2CSlaveClearReadStatus();
}


