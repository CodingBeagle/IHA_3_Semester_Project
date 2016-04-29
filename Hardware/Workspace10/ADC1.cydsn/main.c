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
{char publicar[6];
    uint16 con;
    float32 adc;
    CyGlobalIntEnable; /* Enable global interrupts. */

    ADC_1_Start();
    ADC_1_StartConvert();
   ADC_1_IsEndConversion(ADC_1_WAIT_FOR_RESULT);
   // ADC_1_IsEndConversion(ADC_1_WAIT_FOR_RESULT);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
//UART_1_Start();


    // Initialize PWM signal
    PWM_X_RIGHT_Start();
    Clock_PWM_2_Start();
    
    PWM_X_RIGHT_WriteCompare(0);
UART_1_Start();
    for(;;)
    {
    ADC_1_StartConvert();
    con= ADC_1_GetResult16(0);
   
    if ( 1300 < con && con < 1500)
    {
        PWM_X_RIGHT_WriteCompare(30);
    }
    else 
    {
        PWM_X_RIGHT_WriteCompare(0);
    }
        

   ADC_1_StopConvert();
    
   /* adc= ADC_1_CountsTo_Volts(0,con);
    sprintf(publicar,"%.4f",adc);
    
   UART_1_UartPutString(publicar);*/

    }
}

/* [] END OF FILE */
