#include <project.h>
#include "CommunicationProtocol.h"


//Creates the buffer for the recieved data.
uint8 recievedDataBuffer[4];
uint8 transferErrorStatus;

int x = 127;
int y = 127;
int z = 127;

void debugNunchuckData(uint8* nunchuckDataBuffer);

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    //Starts the I2C component on the PSoC.
    I2C_1_Start();
    
    // Init the slave buffers
    initReceiveData();
    
    
    //Turn off LEDS
    DebugLEDGreen_Write(1);
    DebugLEDRed_Write(1);
    DebugLEDBlue_Write(1);
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    for(;;)
    {
        receiveData(recievedDataBuffer);

        debugNunchuckData(recievedDataBuffer);
    }
}

void debugNunchuckData(uint8* receivedDataBuffer)
{
    if(receivedDataBuffer[0] == NunchuckData)
    {
        //Handle debug LEDs for the X-Axis.
        if(receivedDataBuffer[1] < 100)
            DebugLEDRed_Write(0);
        else if(receivedDataBuffer[1] > 150)
            DebugLEDGreen_Write(0);
        else
        {
            DebugLEDGreen_Write(1);
            DebugLEDRed_Write(1);
        }
        
        //Handle debug LEDs for the Y-Axis.
        if(receivedDataBuffer[2] < 100)
            DebugLEDBlue_Write(0);
        else if(receivedDataBuffer[2] > 150)
        {
            DebugLEDGreen_Write(0);
            DebugLEDRed_Write(0);
            DebugLEDBlue_Write(0);
        }
        else
            DebugLEDBlue_Write(1);     
    }
}