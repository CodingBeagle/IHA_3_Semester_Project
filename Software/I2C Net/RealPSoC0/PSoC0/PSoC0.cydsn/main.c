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
#include "nunchuck.h"
#include "CommunicationProtocol.h"

// Define unit address for nunchuck
#define nunchuckUnitAddress 0x52
#define PSoC1 0x09

#define NunchuckDataCommand 0b00101010


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
            
            // Delay between requesting and reading
            CyDelay(1);
            
            //Request Data from Nunchuck
            //If nunchuckreadData returns 0 it means an error occured.
            if (NunchuckReadData(dataBuffer) == 0)
            {
                sendHandshake = 0;
            }
            //If the return data is different from 0, we want to send it to the next PSoC.
            else
            {                
                sendNunchuckData = 1;
            }
        }
        
        CyDelay(1);
        
        // Send nunchuck data
        if (sendNunchuckData)
        {
            // Sends the databuffer data to PSoC1.
            sendData(PSoC1, NunchuckDataCommand, dataBuffer, 3);
            
            // Tells the program that the data has been sent 
            // and we need new data from the Nunchuck
            sendNunchuckData = 0;
            
            // Adds a minor delay between sending data, and reading from Nunchuck.
            CyDelay(1);
        }    
    }    
    return 0;
}
