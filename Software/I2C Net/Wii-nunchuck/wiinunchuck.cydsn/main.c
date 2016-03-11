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
#define nunchuckUnitAddress 0x52


uint8 transferErrorStatus;
uint8 readNunchuckError;
uint8 writeNunchuckError;
//Creates the buffer for the recieved data.
uint8 slaveReadBuffer[6];
// Create buffer for decoded data
uint8 exactData[6];

uint8 stuff[2] = {0x40, 0x00};

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Starts the I2C component on the PSoC.
    I2C_1_Start();
    
    // Set slave buffers for write and read
    //I2C_1_I2CSlaveInitReadBuf(slaveReadBuffer,6);
    
    // Initialize debug 
    DebugLEDGreen_Write(1);
    DebugLEDRed_Write(1);
    
    int sendHandshake = 0;

    for(;;)
    {
        I2C_1_I2CMasterClearStatus();
        if (!sendHandshake)
        {
            transferErrorStatus = I2C_1_I2CMasterSendStart(nunchuckUnitAddress, I2C_1_I2C_WRITE_XFER_MODE);
            if(transferErrorStatus == I2C_1_I2C_MSTR_NO_ERROR)
            {            

                    if(I2C_1_I2CMasterWriteByte(0x40) != I2C_1_I2C_MSTR_NO_ERROR)
                    {
                        DebugLEDRed_Write(0x40);
                    }
                    else
                    {
                        if (I2C_1_I2CMasterWriteByte(0x00) != I2C_1_I2C_MSTR_NO_ERROR)
                        {
                            DebugLEDRed_Write(0);
                        }
                        else
                        {
                            //DebugLEDGreen_Write(!DebugLEDGreen_Read());
                            sendHandshake = 1;
                        }
                    }

            }
            else
            {
             //DebugLEDGreen_Write(1);
             //DebugLEDRed_Write(0);
            }
        }
        else
        {   I2C_1_I2CMasterClearStatus();         
            writeNunchuckError = I2C_1_I2CMasterSendStart(nunchuckUnitAddress, I2C_1_I2C_WRITE_XFER_MODE);
            if (writeNunchuckError == I2C_1_I2C_MSTR_NO_ERROR)
            {
                uint32 err = I2C_1_I2CMasterWriteByte(0x00);
                
                if(err != I2C_1_I2C_MSTR_NO_ERROR)
                {
                    
                }
                else
                {
                  DebugLEDGreen_Write(!DebugLEDGreen_Read());
                }
            }
            I2C_1_I2CMasterSendStop();
            
            CyDelay(200);
            
            I2C_1_I2CMasterClearStatus();
            readNunchuckError = I2C_1_I2CMasterSendStart(nunchuckUnitAddress, I2C_1_I2C_READ_XFER_MODE);
            if (readNunchuckError == I2C_1_I2C_MSTR_NO_ERROR)
            {
                uint8 XAxisValue = I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA);
                uint8 YAxisValue = I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA);
                uint8 XAxisAccValue = I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA);
                uint8 YAxisAccValue = I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA);
                uint8 ZAxisAccValue = I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA);
                uint8 ButtonStates = I2C_1_I2CMasterReadByte(I2C_1_I2C_NAK_DATA);
                
                uint8 exactDataTest = (XAxisValue ^ 0x17) + 0x17 - 15;
                uint8 exactDataTest2 = (YAxisValue ^ 0x17) + 0x17;
                
                int dummylol = 0;
                
                /*
                if (err == I2C_1_I2C_MSTR_NO_ERROR)
                {
                    DebugLEDGreen_Write(!DebugLEDGreen_Read());
                }
                else
                {
                    DebugLEDRed_Write(!DebugLEDRed_Read());   
                }
                */
            }
        }
        I2C_1_I2CMasterSendStop();
        CyDelay(200);
    }
    
    return 0;
}

/* [] END OF FILE */
