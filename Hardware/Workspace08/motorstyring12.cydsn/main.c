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
#define size 8
int main()
{
    
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
      int akse[size];
    receiveData(akse[]);
    
    PWM_1_Start(); 
    Clock_PWM_Start(); 
     
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_1_WriteCompare(0); 
    PWM_2_Start(); 
    Clock_PWM_2_Start(); 
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_2_WriteCompare(0); 
     PWM_3_Start(); 
    Clock_PWM_3_Start(); 
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_3_WriteCompare(0); 
     PWM_4_Start(); 
    Clock_PWM_Start(); 
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_4_WriteCompare(0); 
    
   
    
   
    for(;;)
    {
        if(akse[1]==0x7E|akse[1]==0x7B)
        {
            CyDelay(5);
        }
       
        if(akse[1]==0x1E|akse[1]==0xE1)
        {
        if(akse[2]>=75)
 {
        PWM_1_WriteCompare(20); 
        CyDelay(5); 
        PWM_1_WriteCompare(0);
        CyDelay(300);
        
        }
else
{
        PWM_2_WriteCompare(20); 
        CyDelay(5); 
        PWM_2_WriteCompare(0);
        CyDelay(300);
                }
        }
 else//(yakse==2)
        {if(akse[2]>75)
 {
        PWM_3_WriteCompare(20); 
        CyDelay(5); 
        PWM_3_WriteCompare(0);
        CyDelay(300);
        }
else//(tallet>117)
{PWM_4_WriteCompare(20); 
        CyDelay(5); 
        PWM_4_WriteCompare(0);
        CyDelay(300);
        }}
       
    }
}

/* [] END OF FILE */

