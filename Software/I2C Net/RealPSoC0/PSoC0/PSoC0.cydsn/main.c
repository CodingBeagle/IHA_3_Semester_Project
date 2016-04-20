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
#include <time.h>

// Define unit address for PSoC1
#define PSoC1 0x09

#define START_SPI_TEST 0xF1
#define START_I2C_TEST 0xF2
#define START_NUNCHUCK_TEST 0xF3
#define SPI_OK 0xD1
#define I2C_OK 0xD2
#define I2C_FAIL 0xC2
#define NUNCHUCK_OK 0xD3
#define NUNCHUCK_FAIL 0xC3

// Create buffer for read data
uint8 dataBuffer[3];

int sendHandshake = 0;
int sendNunchuckData = 0;

int testI2C = 0;
int testNunchuck = 0;
clock_t testNunchuckTimer, diff;


CY_ISR(isr_spi_Interrupt)
{
    uint8 i, j, buf[8];
    uint32 source = 0u;

    // Check if any data available.
    // Returns the number of received data elements in the receive buffer
    j = SPI_1_SpiUartGetRxBufferSize();

    // SPI Read data from SPIS RX software buffer to buf
    for(i=0u; i<j; i++)
    {
        // Retrieves the next data element from the receive buffer
        buf[i] = SPI_1_SpiUartReadRxData();
    }

    if (j>0) // Process data received....
    {
        int commandType = buf[0];
        int readError = 0;
        
        switch (commandType)
        {
            case START_SPI_TEST:
            SPI_1_SpiUartClearTxBuffer();
            SPI_1_SpiUartWriteTxData(SPI_OK);
            
            DebugLEDRed_Write(!DebugLEDRed_Read());
            DebugLEDBlue_Write(1);
            DebugLEDGreen_Write(1);
            break;
            
            case START_I2C_TEST:
       
            testI2C = 1;
            SPI_1_SpiUartClearTxBuffer();
            
            DebugLEDRed_Write(1);
            DebugLEDBlue_Write(!DebugLEDBlue_Read());
            DebugLEDGreen_Write(1);         
            break;
            
            case START_NUNCHUCK_TEST:
            SPI_1_SpiUartClearTxBuffer();
            testNunchuck = 1;
            testNunchuckTimer = clock();
            SPI_1_SpiUartWriteTxData(NUNCHUCK_FAIL);
            
            DebugLEDRed_Write(1);
            DebugLEDBlue_Write(1);
            DebugLEDGreen_Write(!DebugLEDGreen_Read());               
            break;
        }
        
        // Send last command back to master at next transaction!
        // Places a data entry into the transmit buffer to be sent
        //SPI_1_SpiUartWriteTxData(buf[j-1]);
        
    }

    //Pin_LED_Write(!Pin_LED_Read()); // Debug -> Toggle LED!
    //CyDelay(100);

    // Clear Rx Interrupt Source
    source = SPI_1_GetRxInterruptSourceMasked();
    SPI_1_ClearRxInterruptSource(source);
} 


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

            if (testNunchuck)
            {
                diff = clock() - testNunchuckTimer;
                
                // Z button pressed
                if ((dataBuffer[2] & 0b00000011) == 2)
                {
                    SPI_1_SpiUartClearTxBuffer();
                    SPI_1_SpiUartClearTxBuffer();
                    SPI_1_SpiUartWriteTxData(NUNCHUCK_OK);
                    testNunchuck = 0;
                }
                
                if (diff >= 5000)
                {
                    SPI_1_SpiUartClearTxBuffer();
                    testNunchuck = 0;
                }
            }

            // Sends the data in dataBuffer to PSoC1
            sendData(PSoC1, NunchuckData, dataBuffer, 3);
            
            // Tells the program that the data has been sent 
            // and to start new data request from the Nunchuck
            sendNunchuckData = 0;
        }
        
        if (testI2C == 1)
        {
            int PSoC1Reached = 0;
            int NunchuckReached = 0;
            int readError = 0;
            testI2C = 0;
            
            I2C_1_I2CMasterClearStatus();
            readError = I2C_1_I2CMasterSendStart(PSoC1, I2C_1_I2C_WRITE_XFER_MODE);
            if (readError == I2C_1_I2C_MSTR_NO_ERROR)
            {
                PSoC1Reached = 1;
            }
            I2C_1_I2CMasterSendStop();
            
            CyDelay(5);
            
            I2C_1_I2CMasterClearStatus();
            readError = I2C_1_I2CMasterSendStart(nunchuckUnitAddress, I2C_1_I2C_WRITE_XFER_MODE);
            if (readError == I2C_1_I2C_MSTR_NO_ERROR)
            {
                NunchuckReached = 1;
            }
            I2C_1_I2CMasterSendStop();
            
            if (PSoC1Reached && NunchuckReached)
            {
                SPI_1_SpiUartWriteTxData(I2C_OK);
            }
            else
            {
                SPI_1_SpiUartWriteTxData(I2C_FAIL);
            }
        }
        
    }    
    return 0;
}
