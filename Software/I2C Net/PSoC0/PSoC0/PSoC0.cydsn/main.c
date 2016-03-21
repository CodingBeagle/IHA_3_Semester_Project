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

#define NunchuckDataCommand 42

//Creates the buffer for the recieved data.
uint8 recievedDataBuffer[5];
uint8 transferErrorStatus;

uint8 slaveWritebuffer[4];
uint8 slaveReadBuffer[1];

uint8 isMaster = 0;

int x, y, z;

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    //Starts the I2C component on the PSoC.
    I2C_1_Start();
    
    //Init slave buffers.
    //Set slave write buffer
    I2C_1_I2CSlaveInitWriteBuf(slaveWritebuffer, 4);
    //Set slave read buffer
    I2C_1_I2CSlaveInitReadBuf(slaveReadBuffer, 1);
    
    
    //Turn off LEDS
    debugLEDGreen_Write(1);
    debugLEDRed_Write(1);
    debugLEDBlue_Write(1);
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    for(;;)
    {
        x = 127;
        y = 127;
        z = 127;
        
        if(isMaster == 0)
        {
            if (I2C_1_I2CSlaveStatus() == I2C_1_I2C_SSTAT_WR_CMPLT)
            {
                 if ((int)slaveWritebuffer[0] == NunchuckDataCommand)
                 {
                    //debugLEDRed_Write(!debugLEDRed_Read());
                    x = (int)slaveWritebuffer[1];
                    y = (int)slaveWritebuffer[2];
                    z = (int)slaveWritebuffer[3];
                    isMaster = 1;
                    
                    I2C_1_I2CSlaveClearWriteBuf();
                 }
                I2C_1_I2CSlaveClearReadStatus();
            }
        }
        else if(isMaster == 1)
        {
            I2C_1_I2CMasterClearStatus();
            transferErrorStatus = I2C_1_I2CMasterSendStart(PSoC1UnitAdress, I2C_1_I2C_WRITE_XFER_MODE);
            if(transferErrorStatus == I2C_1_I2C_MSTR_NO_ERROR)
            {
                //Send command type
                I2C_1_I2CMasterWriteByte(NunchuckDataCommand);
                
                //Send commandtype data
                I2C_1_I2CMasterWriteByte(x);
                I2C_1_I2CMasterWriteByte(y);
                I2C_1_I2CMasterWriteByte(z);
                isMaster = 0;
                
            }
           I2C_1_I2CMasterSendStop();
           
        }
        

    }
}

/* [] END OF FILE */
