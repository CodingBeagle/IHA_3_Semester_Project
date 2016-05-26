#include "SPICommunication.h"
#include "I2CCommunication.h"
#include "Nunchuck.h"
#include "Project.h"


//Completes the SPI test by writing SPI_OK to the outgoing spi register 
void completeSPITest()
{
    testNunchuck = 0;
    testI2C = 0;
    SPI_1_SpiUartClearTxBuffer();
    SPI_1_SpiUartWriteTxData(SPI_OK);
    
    //Debug LEDS
    DebugLEDRed_Write(!DebugLEDRed_Read());
    DebugLEDBlue_Write(1);
    DebugLEDGreen_Write(1);   
}

//Enables the I2C test by setting testI2C to 1 
void startI2CTest()
{
    testNunchuck = 0;
    testI2C = 1;
    SPI_1_SpiUartClearTxBuffer();
    
    //Debug LEDS
    DebugLEDRed_Write(1);
    DebugLEDBlue_Write(!DebugLEDBlue_Read());
    DebugLEDGreen_Write(1); 
}

//Runs through the I2C test if testI2C is set to 1.
void completeI2CTest()
{
      if (testI2C == 1)
        {
            int PSoC1Reached = 0;
            int NunchuckReached = 0;
            int readError = 0;
            testI2C = 0;
            
            I2C_1_I2CMasterClearStatus();
            readError = I2C_1_I2CMasterSendStart(PSoC1UnitAddress, I2C_1_I2C_WRITE_XFER_MODE);
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

//Enables the Nunchuck test by setting testNunchuck to 1
void startNunchuckTest()
{
    SPI_1_SpiUartClearTxBuffer();
    testNunchuck = 1;
    testI2C = 0;
    testNunchuckTimer = clock();
    SPI_1_SpiUartWriteTxData(NUNCHUCK_FAIL);
    
    //Debug LEDS
    DebugLEDRed_Write(1);
    DebugLEDBlue_Write(1);
    DebugLEDGreen_Write(!DebugLEDGreen_Read());  
}

//Runs through the Nunchuck test if testNunchuck is set to 1
void completeNunchuckTest(uint8* dataBuffer)
{
    if (testNunchuck)
    {
        double cpuTime = (double) (clock() - testNunchuckTimer) / CLOCKS_PER_SEC;
        
        // Z button pressed
        if ((dataBuffer[2] & 0b00000011) == 2)
        {
            SPI_1_SpiUartClearTxBuffer();
            SPI_1_SpiUartClearTxBuffer();
            SPI_1_SpiUartWriteTxData(NUNCHUCK_OK);
            testNunchuck = 0;
        }
    }
}

CY_ISR(isr_spi_Interrupt)
{
    INT_PIN_Write(0);
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
            completeSPITest();
            break;
            
            case START_I2C_TEST:
            startI2CTest();        
            break;
            
            case START_NUNCHUCK_TEST:
             startNunchuckTest();
            break;
        }
        
        INT_PIN_Write(1);
    }

    // Clear Rx Interrupt Source
    source = SPI_1_GetRxInterruptSourceMasked();
    SPI_1_ClearRxInterruptSource(source);
} 