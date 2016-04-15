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

// Define unit address for PSoC1
#define PSoC1 0x09

// Create buffer for read data
uint8 dataBuffer[3];


int sendHandshake = 0;
int sendNunchuckData = 0;

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Starts the I2C component on the PSoC
    I2C_1_Start();
    
    
    // Initialize debug 
    DebugLEDGreen_Write(1);
    DebugLEDRed_Write(1);
    DebugLEDBlue_Write(1);

    for(;;)
    {
       if (!sendHandshake)
        {
            if(NunchuckSendHandshake() != 0)
            {
                sendHandshake = 1;
            }
        }
        else
        {   
            if (NunchuckRequestData() == 0)
            {
                sendHandshake = 0;
            }
            
            // Delay between requesting and reading
            CyDelay(1);
            
            //Request Data from Nunchuck
            //If NunchuckReadData returns 0, an error occured
            if (NunchuckReadData(dataBuffer) == 0)
            {
                sendHandshake = 0;
            }
            //If return is different from 0, the read data will be sent to PSoC1
            else
            {                
                sendNunchuckData = 1;
            }
        }
        
        CyDelay(1);
        
        // Send nunchuck data
        if (sendNunchuckData)
        {
            // Sends the data in dataBuffer to PSoC1
            sendData(PSoC1, NunchuckDataCommand, dataBuffer, 3);
            
            // Tells the program that the data has been sent 
            // and to start new data request from the Nunchuck
            sendNunchuckData = 0;
        }    
    }    
    return 0;
}
