#include <project.h>
#include "nunchuck.h"
#include "CommunicationProtocol.h"
#include "SPICommunication.h"


// Create buffer for read data
uint8 dataBuffer[3];

int sendHandshake = 0;
int sendNunchuckData = 0;


int main()
{    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Starts the I2C component on the PSoC
    I2C_1_Start();
    SPI_1_Start();
    isr_spi_Start();
    
    // Initialize debug 
    DebugLEDGreen_Write(1);
    DebugLEDRed_Write(1);
    DebugLEDBlue_Write(1);

    for(;;)
    {
        // If we havn't done a handshake with the Nunchuck yet:
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
            //Completes the Nunchuck test if testNunchuck is 1
            //Sets SPITX to NUNCHUCK_OK on success and NUNCHUCK_FAIL on fail.
            completeNunchuckTest(dataBuffer);

            // Sends the data in dataBuffer to PSoC1
            sendData(PSoC1UnitAddress, NunchuckData, dataBuffer, 3);
            
            // Tells the program that the data has been sent 
            // and to start new data request from the Nunchuck
            sendNunchuckData = 0;
        }
        
        //Runs through I2C test, if testI2C is set to 1.
        //Sets SPITX to I2C_OK on success or I2C_FAIL on failure.
        completeI2CTest();
        
    }    
    return 0;
}
