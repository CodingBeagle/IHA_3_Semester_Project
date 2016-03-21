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
#define PSoC0 0x08

#define NunchuckDataCommand 0b00101010
#define WakeupBitchDataCommand 41

// Create buffer for decoded data
uint8 dataBuffer[3];

uint8 slaveDataReadBuffer[1];
uint8 slaveDataBuffer[1];
int isMaster = 1;

void workingNunchuckRead();

int sendHandshake = 0;
int sendNunchuckData = 0;

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Starts the I2C component on the PSoC.
    I2C_1_Start();
    
    // Set slave buffers for write and read
    //I2C_1_I2CSlaveInitReadBuf(slaveDataReadBuffer,1);
    //I2C_1_I2CSlaveInitWriteBuf(slaveDataBuffer, 1);
    
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
            readError = I2C_1_I2CMasterSendStart(PSoC0, I2C_1_I2C_WRITE_XFER_MODE);
            
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
            //sendHandshake = 0;
        }
    
    }
    
    return 0;
}

void workingNunchuckRead()
{

}


/*
       else
       {
            int errorStatus = I2C_1_I2CSlaveStatus();
            if (errorStatus == I2C_1_I2C_SSTAT_WR_CMPLT)
            {
                 if ((int)slaveDataBuffer[0] == WakeupBitchDataCommand)
                 {
                    I2C_1_I2CSlaveClearWriteBuf();
                    isMaster = 1;
                    //CyDelay(500);
                    
                 }
                I2C_1_I2CSlaveClearReadStatus();
            }
       }
*/
/* [] END OF FILE */
