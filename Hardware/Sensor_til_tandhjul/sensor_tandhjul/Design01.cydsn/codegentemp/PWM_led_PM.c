/*******************************************************************************
* File Name: PWM_led_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_led.h"

static PWM_led_backupStruct PWM_led_backup;


/*******************************************************************************
* Function Name: PWM_led_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_led_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_led_SaveConfig(void) 
{

    #if(!PWM_led_UsingFixedFunction)
        #if(!PWM_led_PWMModeIsCenterAligned)
            PWM_led_backup.PWMPeriod = PWM_led_ReadPeriod();
        #endif /* (!PWM_led_PWMModeIsCenterAligned) */
        PWM_led_backup.PWMUdb = PWM_led_ReadCounter();
        #if (PWM_led_UseStatus)
            PWM_led_backup.InterruptMaskValue = PWM_led_STATUS_MASK;
        #endif /* (PWM_led_UseStatus) */

        #if(PWM_led_DeadBandMode == PWM_led__B_PWM__DBM_256_CLOCKS || \
            PWM_led_DeadBandMode == PWM_led__B_PWM__DBM_2_4_CLOCKS)
            PWM_led_backup.PWMdeadBandValue = PWM_led_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_led_KillModeMinTime)
             PWM_led_backup.PWMKillCounterPeriod = PWM_led_ReadKillTime();
        #endif /* (PWM_led_KillModeMinTime) */

        #if(PWM_led_UseControl)
            PWM_led_backup.PWMControlRegister = PWM_led_ReadControlRegister();
        #endif /* (PWM_led_UseControl) */
    #endif  /* (!PWM_led_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_led_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_led_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_led_RestoreConfig(void) 
{
        #if(!PWM_led_UsingFixedFunction)
            #if(!PWM_led_PWMModeIsCenterAligned)
                PWM_led_WritePeriod(PWM_led_backup.PWMPeriod);
            #endif /* (!PWM_led_PWMModeIsCenterAligned) */

            PWM_led_WriteCounter(PWM_led_backup.PWMUdb);

            #if (PWM_led_UseStatus)
                PWM_led_STATUS_MASK = PWM_led_backup.InterruptMaskValue;
            #endif /* (PWM_led_UseStatus) */

            #if(PWM_led_DeadBandMode == PWM_led__B_PWM__DBM_256_CLOCKS || \
                PWM_led_DeadBandMode == PWM_led__B_PWM__DBM_2_4_CLOCKS)
                PWM_led_WriteDeadTime(PWM_led_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_led_KillModeMinTime)
                PWM_led_WriteKillTime(PWM_led_backup.PWMKillCounterPeriod);
            #endif /* (PWM_led_KillModeMinTime) */

            #if(PWM_led_UseControl)
                PWM_led_WriteControlRegister(PWM_led_backup.PWMControlRegister);
            #endif /* (PWM_led_UseControl) */
        #endif  /* (!PWM_led_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_led_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_led_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_led_Sleep(void) 
{
    #if(PWM_led_UseControl)
        if(PWM_led_CTRL_ENABLE == (PWM_led_CONTROL & PWM_led_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_led_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_led_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_led_UseControl) */

    /* Stop component */
    PWM_led_Stop();

    /* Save registers configuration */
    PWM_led_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_led_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_led_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_led_Wakeup(void) 
{
     /* Restore registers values */
    PWM_led_RestoreConfig();

    if(PWM_led_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_led_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
