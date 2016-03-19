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
#include <nunchuck.h>

// Define unit address for nunchuck
#define nunchuckUnitAddress 0x52

// Create buffer for decoded data
uint8 dataBuffer[3];

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
            if (NunchuckSendHandshake() == 0)
            {
                DebugLEDGreen_Write(1);
                DebugLEDRed_Write(0);
            }
            else
            {
                sendHandshake = 1;
            }
        }
        else
        {   
            DebugLEDGreen_Write(0);
         
            if (NunchuckRequestData() == 0)
            {
                DebugLEDGreen_Write(1);
                DebugLEDRed_Write(0);
            }
            else 
            {
                DebugLEDGreen_Write(0);
            }
            
            // Delay between requesting and reading
            CyDelay(200);
            
            if (NunchuckReadData(dataBuffer) == 0)
            {
                DebugLEDGreen_Write(1);
                DebugLEDRed_Write(0);
            }
            else
            {
             DebugLEDGreen_Write(0);   
            }
        }
        I2C_1_I2CMasterSendStop();
        CyDelay(200);
    }
    
    return 0;
}

/* [] END OF FILE */
