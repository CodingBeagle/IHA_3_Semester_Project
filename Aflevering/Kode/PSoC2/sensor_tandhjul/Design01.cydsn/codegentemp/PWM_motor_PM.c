/*******************************************************************************
* File Name: PWM_motor_PM.c
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

#include "PWM_motor.h"

static PWM_motor_backupStruct PWM_motor_backup;


/*******************************************************************************
* Function Name: PWM_motor_SaveConfig
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
*  PWM_motor_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_motor_SaveConfig(void) 
{

    #if(!PWM_motor_UsingFixedFunction)
        #if(!PWM_motor_PWMModeIsCenterAligned)
            PWM_motor_backup.PWMPeriod = PWM_motor_ReadPeriod();
        #endif /* (!PWM_motor_PWMModeIsCenterAligned) */
        PWM_motor_backup.PWMUdb = PWM_motor_ReadCounter();
        #if (PWM_motor_UseStatus)
            PWM_motor_backup.InterruptMaskValue = PWM_motor_STATUS_MASK;
        #endif /* (PWM_motor_UseStatus) */

        #if(PWM_motor_DeadBandMode == PWM_motor__B_PWM__DBM_256_CLOCKS || \
            PWM_motor_DeadBandMode == PWM_motor__B_PWM__DBM_2_4_CLOCKS)
            PWM_motor_backup.PWMdeadBandValue = PWM_motor_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_motor_KillModeMinTime)
             PWM_motor_backup.PWMKillCounterPeriod = PWM_motor_ReadKillTime();
        #endif /* (PWM_motor_KillModeMinTime) */

        #if(PWM_motor_UseControl)
            PWM_motor_backup.PWMControlRegister = PWM_motor_ReadControlRegister();
        #endif /* (PWM_motor_UseControl) */
    #endif  /* (!PWM_motor_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_motor_RestoreConfig
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
*  PWM_motor_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_motor_RestoreConfig(void) 
{
        #if(!PWM_motor_UsingFixedFunction)
            #if(!PWM_motor_PWMModeIsCenterAligned)
                PWM_motor_WritePeriod(PWM_motor_backup.PWMPeriod);
            #endif /* (!PWM_motor_PWMModeIsCenterAligned) */

            PWM_motor_WriteCounter(PWM_motor_backup.PWMUdb);

            #if (PWM_motor_UseStatus)
                PWM_motor_STATUS_MASK = PWM_motor_backup.InterruptMaskValue;
            #endif /* (PWM_motor_UseStatus) */

            #if(PWM_motor_DeadBandMode == PWM_motor__B_PWM__DBM_256_CLOCKS || \
                PWM_motor_DeadBandMode == PWM_motor__B_PWM__DBM_2_4_CLOCKS)
                PWM_motor_WriteDeadTime(PWM_motor_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_motor_KillModeMinTime)
                PWM_motor_WriteKillTime(PWM_motor_backup.PWMKillCounterPeriod);
            #endif /* (PWM_motor_KillModeMinTime) */

            #if(PWM_motor_UseControl)
                PWM_motor_WriteControlRegister(PWM_motor_backup.PWMControlRegister);
            #endif /* (PWM_motor_UseControl) */
        #endif  /* (!PWM_motor_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_motor_Sleep
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
*  PWM_motor_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_motor_Sleep(void) 
{
    #if(PWM_motor_UseControl)
        if(PWM_motor_CTRL_ENABLE == (PWM_motor_CONTROL & PWM_motor_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_motor_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_motor_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_motor_UseControl) */

    /* Stop component */
    PWM_motor_Stop();

    /* Save registers configuration */
    PWM_motor_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_motor_Wakeup
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
*  PWM_motor_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_motor_Wakeup(void) 
{
     /* Restore registers values */
    PWM_motor_RestoreConfig();

    if(PWM_motor_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_motor_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
