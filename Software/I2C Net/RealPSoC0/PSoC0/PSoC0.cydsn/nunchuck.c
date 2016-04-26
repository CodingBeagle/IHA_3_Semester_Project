#include <project.h>
#include <nunchuck.h>

// Function sends handshake to nunchuck to initiate communication
// Returns 0 if an error occurs
int NunchuckSendHandshake()
{
    // Variable for errorhandling
    uint8 transferErrorStatus;
    
    I2C_1_I2CMasterClearStatus();

    transferErrorStatus = I2C_1_I2CMasterSendStart(nunchuckUnitAddress, I2C_1_I2C_WRITE_XFER_MODE);
    if(transferErrorStatus == I2C_1_I2C_MSTR_NO_ERROR)
    {   
        // Error happened while sending byte
        if(I2C_1_I2CMasterWriteByte(0x40) != I2C_1_I2C_MSTR_NO_ERROR)
        {
            I2C_1_I2CMasterSendStop();
            return 0;
        }
        // No error occurred while sending byte
        else
        {
            // Error happens while sending byte
            if (I2C_1_I2CMasterWriteByte(0x00) != I2C_1_I2C_MSTR_NO_ERROR)
            {
                I2C_1_I2CMasterSendStop();
                return 0;
            }
            // No error occurred while sending byte
            else
            {
                I2C_1_I2CMasterSendStop();
                return 1;
            }
        }
        
        I2C_1_I2CMasterSendStop();
    }
    else
    {
        I2C_1_I2CMasterSendStop();
        return 0;
    }
}

// Function sends 0x00 to request data from nunchuck
// Returns  0 if an error occurs
int NunchuckRequestData()
{
    // Variable for errorhandling
    uint8 writeNunchuckError;
    
    
    I2C_1_I2CMasterClearStatus();         
    writeNunchuckError = I2C_1_I2CMasterSendStart(nunchuckUnitAddress, I2C_1_I2C_WRITE_XFER_MODE);
    if (writeNunchuckError == I2C_1_I2C_MSTR_NO_ERROR)
    {
        // Error happens while sending byte
        if(I2C_1_I2CMasterWriteByte(0x00)!= I2C_1_I2C_MSTR_NO_ERROR)
        {
            I2C_1_I2CMasterSendStop();
            return 0;
        }
        
        I2C_1_I2CMasterSendStop();
    }
    else 
    {
        I2C_1_I2CMasterSendStop();
        return 0;
    }
    
    I2C_1_I2CMasterSendStop();
    // No error occurred while sending byte
    return 1;
}

// Function reads data into buffer
// Returns 0 if an error occurs
int NunchuckReadData(uint8* buffer)
{
    // Variable for errorhandling
    uint8 readNunchuckError;
    
    I2C_1_I2CMasterClearStatus();
    readNunchuckError = I2C_1_I2CMasterSendStart(nunchuckUnitAddress, I2C_1_I2C_READ_XFER_MODE);
    if (readNunchuckError == I2C_1_I2C_MSTR_NO_ERROR)
    {
        // Reading data from Nunchuck
        uint8 XAxisValue = I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA);
        uint8 YAxisValue = I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA);
        uint8 XAxisAccValue = I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA);
        uint8 YAxisAccValue = I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA);
        uint8 ZAxisAccValue = I2C_1_I2CMasterReadByte(I2C_1_I2C_ACK_DATA);
        uint8 ButtonStates = I2C_1_I2CMasterReadByte(I2C_1_I2C_NAK_DATA);
        
        // Decoding Nunchuck values
        uint8 exactData0 = (XAxisValue ^ 0x17) + 0x17 - 15;
        uint8 exactData1 = (YAxisValue ^ 0x17) + 0x17;
        uint8 exactData2 = (ButtonStates ^0x17) + 0x17;
       
        // Inserting exactData into buffer
        // XAxisValue
        buffer[0] = exactData0;
        // YAxisValue
        buffer[1] = exactData1;
        // ButtonStates
        buffer[2] = exactData2;
        
        I2C_1_I2CMasterSendStop();
        return 1;
    }
    // Error has occurred while reading data
    else
    {
        I2C_1_I2CMasterSendStop();
        return 0;
    }
    
    I2C_1_I2CMasterSendStop();
}
