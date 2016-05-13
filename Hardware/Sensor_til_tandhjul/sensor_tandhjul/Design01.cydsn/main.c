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

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
        
    volatile uint16 ADCresult; 
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    
    Opamp_1_Start();
    PWM_1_Start(); //initialisering af PWM
    
    //Initialisering af ADC
    ADC_2_Start(); 
    ADC_2_StartConvert(); 
    ADC_2_IsEndConversion(ADC_2_WAIT_FOR_RESULT); 
    
    
    
    for(;;)
    {
        ADCresult = ADC_2_GetResult16(0);
        
        // if(ADCresult>=)
        //{
            
        //}
    }
}

/* [] END OF FILE */
