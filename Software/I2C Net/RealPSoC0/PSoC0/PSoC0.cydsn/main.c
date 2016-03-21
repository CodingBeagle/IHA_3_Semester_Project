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
#define PSoC1 0x09

#define NunchuckDataCommand 0b00101010
#define WakeupBitchDataCommand 41

// Create buffer for decoded data
uint8 dataBuffer[3];


int sendHandshake = 0;
int sendNunchuckData = 0;

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Starts the I2C component on the PSoC.
    I2C_1_Start();
    
    
    // Initialize debug 
    DebugLEDGreen_Write(1);
    DebugLEDRed_Write(1);

    for(;;)
    {
       if (!sendHandshake)
        {
            if (NunchuckSendHandshake() == 0)
            {
                int dummy = 2;
                DebugLEDRed_Write(0);
            }
            else
            {
                DebugLEDRed_Write(1);
                sendHandshake = 1;
            }
        }
        else
        {   
            I2C_1_I2CMasterClearStatus();
         
            if (NunchuckRequestData() == 0)
            {
                sendHandshake = 0;
            }
            else 
            {
                
            }
            
            // Delay between requesting and reading
            CyDelay(1);
            
            if (NunchuckReadData(dataBuffer) == 0)
            {
                
                sendHandshake = 0;
            }
            else
            {                
                sendNunchuckData = 1;
            }
        }
        
        CyDelay(1);
        
        // Send nunchuck data
        if (sendNunchuckData)
        {
            int readError = 0;
            
            I2C_1_I2CMasterClearStatus();
            readError = I2C_1_I2CMasterSendStart(PSoC1, I2C_1_I2C_WRITE_XFER_MODE);
            
            if (readError == I2C_1_I2C_MSTR_NO_ERROR)
            {
                // Send command type
                I2C_1_I2CMasterWriteByte(NunchuckDataCommand);
                
                // Send Nunchuck data
                I2C_1_I2CMasterWriteByte(dataBuffer[0]);
                I2C_1_I2CMasterWriteByte(dataBuffer[1]);
                I2C_1_I2CMasterWriteByte(dataBuffer[2]);

                DebugLEDGreen_Write(0);
                
                sendNunchuckData = 0;
                
            }
            else
            {
                int dummy = 0;
                DebugLEDGreen_Write(1);
            }
            
            I2C_1_I2CMasterSendStop();
            I2C_1_I2CMasterClearStatus();
            CyDelay(1);
        }
    
    }
    
    return 0;
}


/* [] END OF FILE */