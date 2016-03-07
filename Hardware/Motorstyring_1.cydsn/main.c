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

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        Pin_1_Write(1);
        
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
