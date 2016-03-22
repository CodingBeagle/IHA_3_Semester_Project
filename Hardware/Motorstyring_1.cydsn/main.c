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

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_1_Start(); 
    Clock_PWM_Start(); 
     
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_1_WriteCompare(0); 
     int a=1;
    for(;;)
    {
       
        if(a<=3)
        {
        PWM_1_WriteCompare(20); 
        CyDelay(5); 
        PWM_1_WriteCompare(0);
        CyDelay(300);
        a++;
        }
        
        /* Place your application code here. */
        /*if(Pin_2_Read()==1)
        {
            Pin_1_Write(1); 
        }
        else
            Pin_1_Write(0);
        */
    }
}

/* [] END OF FILE */
