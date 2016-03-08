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
#define SCB_I2C_WRITE_XFER_MODE 0
#define SCB_I2C_READ_XFER_MODE 1

//Defines the adresses of the I2C components on the network.
#define PSoC0UnitAdress 0x08
#define PSoC1UnitAdress 0x09
#define PSoc2UnitAdress 0x10

//Defines the adresses of the I2C components on the network.
#define PSoC0UnitAdress 0x08
#define PSoC1UnitAdress 0x09
#define PSoC2UnitAdress 0x10

//Creates the buffer for the recieved data.
uint8 recievedDataBuffer[2];
uint8 transferErrorStatus;

uint8 buffer[1];

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    // Set slave write buffer
    // This is data written to this slave by a master
    I2C_1_I2CSlaveInitWriteBuf(buffer, 1);
    
    //Starts the I2C component on the PSoC.
    I2C_1_Start();
    
    // Initialize Debug LED
    DebugLEDGREEN_Write(1);
    DebugLEDRED_Write(1);
    
    int isMaster = 0;
    
    // Main Loop
    for(;;)
    {
        if (isMaster == 0)
        {
            if (I2C_1_I2CSlaveStatus() == I2C_1_I2C_SSTAT_WR_CMPLT)
            {
                if ((int)buffer[0] == 12)
                {
                    DebugLEDGREEN_Write(1);
                    DebugLEDRED_Write(0);
                    I2C_1_I2CSlaveClearReadStatus();
                    isMaster = 1;
                    I2C_1_I2CSlaveClearWriteBuf();
                    CyDelay(1000);
                }
            }
        }
        else
        {
           //I2C_1_I2CMasterClearStatus();
           transferErrorStatus = I2C_1_I2CMasterSendStart(PSoC0UnitAdress, I2C_1_I2C_WRITE_XFER_MODE);
            if(transferErrorStatus == I2C_1_I2C_MSTR_NO_ERROR)
            {                
                if (I2C_1_I2CMasterWriteByte(12) == I2C_1_I2C_MSTR_NO_ERROR)
                {
                    //Turn on Green LED while sending
                    DebugLEDGREEN_Write(0);
                    DebugLEDRED_Write(1);
                    isMaster = 0;
                }
            }
            I2C_1_I2CMasterSendStop();
            I2C_1_I2CMasterClearStatus();
            CyDelay(1000);
        }
    }
}

/* [] END OF FILE */