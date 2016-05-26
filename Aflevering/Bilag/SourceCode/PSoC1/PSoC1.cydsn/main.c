#include <project.h>
#include "CommunicationProtocol.h"


//Creates the buffer for the recieved data.
uint8 recievedDataBuffer[4];
uint8 transferErrorStatus;

int x = 127;
int y = 127;
int z = 127;

void controlMotor(uint8* nunchuckDataBuffer);

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
    Shoot_Write(0);
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    // Turn off motor x axis left direction
    //MotorXAxisDirectionLeft_Write(0);
    
    ADC_1_Start();
    
    // Initialize PWM signals
    PWM_X_RIGHT_Start();
    //Clock_PWM_2_Start();
    
    PWM_X_LEFT_Start();
    PWM_Y_UP_Start();
    PWM_Y_DOWN_Start();
    Clock_PWM_1_Start();
    
    PWM_X_RIGHT_WriteCompare(0);
    PWM_X_LEFT_WriteCompare(0);
    PWM_Y_UP_WriteCompare(0);
    PWM_Y_DOWN_WriteCompare(0);
    
    for(;;)
    {
        //Receive data from PSoC1
        receiveData(recievedDataBuffer);

        // Uses the received data to control direction and speed of the Motor.
        controlMotor(recievedDataBuffer);
        
    }
}

void controlMotor(uint8* receivedDataBuffer)
{
    // Initialize ADC
    uint16 convertedValue;
    float32 adc;
    ADC_1_StartConvert();
    ADC_1_IsEndConversion(ADC_1_WAIT_FOR_RESULT);
    convertedValue= ADC_1_GetResult16(0);
    
    // Receive value from ADC
    adc=ADC_1_CountsTo_mVolts(0,convertedValue);
    
    if(receivedDataBuffer[0] == NunchuckData)
    {
        
        //Handle debug LEDs for the X-Axis.
        if(receivedDataBuffer[1] < 100 && adc > 915)
        {
            DebugLEDRed_Write(0);
            PWM_X_LEFT_WriteCompare(70);
        }
        else if(receivedDataBuffer[1] > 150 && adc < 2000)
        {
            DebugLEDGreen_Write(0);
            PWM_X_RIGHT_WriteCompare(70);
        }
        else
        {
            PWM_X_LEFT_WriteCompare(0);
            PWM_X_RIGHT_WriteCompare(0);
            DebugLEDGreen_Write(1);
            DebugLEDRed_Write(1);
        }
        
        /*
        if (receivedDataBuffer[1] < 150)
        {
           PWM_X_RIGHT_WriteCompare(0);
        }

        if (receivedDataBuffer[1] > 100)
        {
           PWM_X_LEFT_WriteCompare(0);
        }
        */
        //Handle debug LEDs for the Y-Axis (No motor handling yet).
        if(receivedDataBuffer[2] < 100)
        {
            DebugLEDBlue_Write(0);
            PWM_Y_DOWN_WriteCompare(80);
        }
        else if(receivedDataBuffer[2] > 150)
        {
            PWM_Y_UP_WriteCompare(100);
            DebugLEDGreen_Write(0);
            DebugLEDRed_Write(0);
            DebugLEDBlue_Write(0);
        }
        else
        {
            PWM_Y_UP_WriteCompare(0);
            PWM_Y_DOWN_WriteCompare(0);
            DebugLEDBlue_Write(1);
        }
        
        if((receivedDataBuffer[3] & 0b00000011) == 2)
        {
            Shoot_Write(1);
        }
        else
        {
           Shoot_Write(0);
        }
            
        ADC_1_StopConvert();
    }
}