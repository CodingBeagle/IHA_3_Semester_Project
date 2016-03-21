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


int x = 127;
int y = 127;
int z = 127;

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
        
        if (x < 100)
        {
            debugLEDRed_Write(0);
        }
        else if(x > 150)
        {
            debugLEDGreen_Write(0);   
        }
        else
        {
            debugLEDRed_Write(1);
            debugLEDGreen_Write(1);
        }
        
        if(y < 100)
        {
           debugLEDBlue_Write(0); 
        }
        else if( y > 150)
        {
            debugLEDGreen_Write(0);
            debugLEDRed_Write(0);
        }
        else
        {
            debugLEDBlue_Write(1);
        }
        
    }
}

/* [] END OF FILE */