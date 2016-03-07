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

//Creates the buffer for the recieved data.
uint8 recievedDataBuffer[2];
uint8 transferErrorStatus;

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    //Starts the I2C component on the PSoC.
    I2C_1_Start();
    I2C_1_I2CMasterClearStatus();
    
    for(;;)
    {
        transferErrorStatus = I2C_1_I2CMasterSendStart(PSoC1UnitAdress, SCB_I2C_WRITE_XFER_MODE);
    }
}

/* [] END OF FILE */
