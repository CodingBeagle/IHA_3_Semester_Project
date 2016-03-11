/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

// Define unit address for nunchuck
#define nunchuckUnitAddress 0x52;


uint8 transferErrorStatus;
//Creates the buffer for the recieved data.
uint8 slaveReadBuffer[6];
uint8 slaveWriteBuffer[6];
// Create buffer for decoded data
uint8 exactData[6];

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Starts the I2C component on the PSoC.
    I2C_1_Start();
    
    // Set slave buffers for write and read
    I2C_1_I2CSlaveInitWriteBuf(slaveWriteBuffer, 6);
    I2C_1_I2CSlaveInitReadBuf(slaveReadBuffer,6);
    
    // Initialize debug 
    DebugLEDGreen_Write(1);
    DebugLEDRed_Write(1);   
    int isMaster = 1;

    for(;;)
    {
        if(isMaster == 1)
        {
          transferErrorStatus = I2C_1_I2CMasterSendStart(nunchuckUnitAddress, I2C_1_I2C_WRITE_XFER_MODE);
           if(transferErrorStatus == I2C_1_I2C_MSTR_NO_ERROR)
           {
                if(I2C_1_I2CMasterWriteByte(0x00) == I2C_1_I2C_MSTR_NO_ERROR)
                {
                    DebugLEDRed_Write(0);
                    isMaster = 0;
                }
            }  
        }
        else if (isMaster == 0)
        {
            DebugLEDGreen_Write(0);
        }
    }
    
    return 0;
}

/* [] END OF FILE */
