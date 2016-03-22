#include "CommunicationProtocol.h"
#include "Project.h"

void sendData(uint32 Adress, uint8 CommandType, uint8* buffer, uint8 bufferSize)
{
    int readError = 0;
    int i;
    I2C_1_I2CMasterClearStatus();
    readError = I2C_1_I2CMasterSendStart(Adress, I2C_1_I2C_WRITE_XFER_MODE);
    if (readError == I2C_1_I2C_MSTR_NO_ERROR)
    {
        // Send command type
        I2C_1_I2CMasterWriteByte(CommandType);
        
        // Send Nunchuck data from the buffer.
        for(i = 0; i < bufferSize; i++)
        {
            I2C_1_I2CMasterWriteByte(buffer[i]);
        }
        
        //Debug LED. Lights up if no error.
        DebugLEDGreen_Write(0);
    }
    else
    {
        // Debug LED. Turns off if error occurs.
        DebugLEDGreen_Write(1);
    }
    I2C_1_I2CMasterSendStop();
    I2C_1_I2CMasterClearStatus();
}


void receiveData(uint8* buffer)
{
    if (I2C_1_I2CSlaveStatus() == I2C_1_I2C_SSTAT_WR_CMPLT)
        {
             if ((int)slaveWritebuffer[0] == NunchuckDataCommand)
             {
                //debugLEDRed_Write(!debugLEDRed_Read());
                x = (int)slaveWritebuffer[1];
                y = (int)slaveWritebuffer[2];
                z = (int)slaveWritebuffer[3];
                
                I2C_1_I2CSlaveClearWriteBuf();
             }
            I2C_1_I2CSlaveClearReadStatus();
        }
}


