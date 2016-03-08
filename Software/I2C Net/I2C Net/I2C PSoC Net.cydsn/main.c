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

//Defines the adresses of the I2C components on the network.
#define PSoC0UnitAdress 0x08
#define PSoC1UnitAdress 0x09
#define PSoC2UnitAdress 0x10

//Creates the buffer for the recieved data.
uint8 recievedDataBuffer[2];
uint8 transferErrorStatus;

uint8 slaveWritebuffer[1];
uint8 slaveReadBuffer[1];

uint8 isMaster = 1;

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    //Starts the I2C component on the PSoC.
    I2C_1_Start();
    
    //Init slave buffers.
    //Set slave write buffer
    I2C_1_I2CSlaveInitWriteBuf(slaveWritebuffer, 1);
    //Set slave read buffer
    I2C_1_I2CSlaveInitReadBuf(slaveReadBuffer, 1);
    
    
    //Turn off LEDS
    DebugLedGreen_Write(1);
    DebugLedRed_Write(1);
    
    for(;;)
    {
        if(isMaster == 1)
        {
        
           transferErrorStatus = I2C_1_I2CMasterSendStart(PSoC2UnitAdress, I2C_1_I2C_WRITE_XFER_MODE);
           if(transferErrorStatus == I2C_1_I2C_MSTR_NO_ERROR)
           {
                if(I2C_1_I2CMasterWriteByte(12) == I2C_1_I2C_MSTR_NO_ERROR)
                {
                    isMaster = 0;
                }
            }
            
            I2C_1_I2CMasterSendStop();
            I2C_1_I2CMasterClearStatus();
            
            CyDelay(500);
            
        }
        else if(isMaster == 0)
        {
           
            if (I2C_1_I2CSlaveStatus() == I2C_1_I2C_SSTAT_WR_CMPLT)
            {
                 if ((int)slaveWritebuffer[0] == 12)
                 {
                    I2C_1_I2CSlaveClearWriteBuf();
                    isMaster = 1;
                    DebugLedGreen_Write(!DebugLedGreen_Read());
                    CyDelay(500);
                    
                 }
                I2C_1_I2CSlaveClearReadStatus();
            }
        }
    }
}

/* [] END OF FILE */
