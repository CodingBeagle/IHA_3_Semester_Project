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
#include <stdio.h>
#include <math.h>

volatile uint16 ADCresult; 
volatile int16 resVolt; 

CY_ISR(isr_in)
{
    PWM_motor_Start(); //Start motor
    
    do 
    {
        Pin_red_Write(1); //Sluk rød led
        Pin_green_Write(0); //Tænd grøn led
        ADCresult = ADC_2_GetResult16(0);   //output fra ADC
        resVolt = ADC_2_CountsTo_mVolts(0, ADCresult);  //konvertering af ADC-output til mV
    }while (resVolt<=1500);
    
    PWM_motor_Stop(); //Stop motor
    Pin_green_Write(1); //Sluk grøn led
    Pin_red_Write(0); //Tænd rød led
}

int main()
{
    //initialisering af interrupt
     isr_Shoot_StartEx(isr_in); 
    
    CyGlobalIntEnable; /* Enable global interrupts. */
        
    
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    
    Opamp_1_Start(); //initialisering af opamp
    PWM_led_Start(); //initialisering af PWM til led
    //PWM_motor_Start(); //initialisering af PWM til motor
    
    //Initialisering af ADC
    ADC_2_Start(); 
    ADC_2_StartConvert(); 
    ADC_2_IsEndConversion(ADC_2_WAIT_FOR_RESULT); 
    
    
   
    
    Pin_green_Write(1); //Sluk grøn led
    Pin_red_Write(0); //Tænd rød led
    for(;;)
    {
                
    }
}

/* [] END OF FILE */
