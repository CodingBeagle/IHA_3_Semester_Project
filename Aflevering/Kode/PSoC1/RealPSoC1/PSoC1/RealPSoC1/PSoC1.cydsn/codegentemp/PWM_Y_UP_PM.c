/*******************************************************************************
* File Name: PWM_Y_UP_PM.c
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

#include "PWM_Y_UP.h"

static PWM_Y_UP_backupStruct PWM_Y_UP_backup;


/*******************************************************************************
* Function Name: PWM_Y_UP_SaveConfig
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
*  PWM_Y_UP_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Y_UP_SaveConfig(void) 
{

    #if(!PWM_Y_UP_UsingFixedFunction)
        #if(!PWM_Y_UP_PWMModeIsCenterAligned)
            PWM_Y_UP_backup.PWMPeriod = PWM_Y_UP_ReadPeriod();
        #endif /* (!PWM_Y_UP_PWMModeIsCenterAligned) */
        PWM_Y_UP_backup.PWMUdb = PWM_Y_UP_ReadCounter();
        #if (PWM_Y_UP_UseStatus)
            PWM_Y_UP_backup.InterruptMaskValue = PWM_Y_UP_STATUS_MASK;
        #endif /* (PWM_Y_UP_UseStatus) */

        #if(PWM_Y_UP_DeadBandMode == PWM_Y_UP__B_PWM__DBM_256_CLOCKS || \
            PWM_Y_UP_DeadBandMode == PWM_Y_UP__B_PWM__DBM_2_4_CLOCKS)
            PWM_Y_UP_backup.PWMdeadBandValue = PWM_Y_UP_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Y_UP_KillModeMinTime)
             PWM_Y_UP_backup.PWMKillCounterPeriod = PWM_Y_UP_ReadKillTime();
        #endif /* (PWM_Y_UP_KillModeMinTime) */

        #if(PWM_Y_UP_UseControl)
            PWM_Y_UP_backup.PWMControlRegister = PWM_Y_UP_ReadControlRegister();
        #endif /* (PWM_Y_UP_UseControl) */
    #endif  /* (!PWM_Y_UP_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Y_UP_RestoreConfig
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
*  PWM_Y_UP_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Y_UP_RestoreConfig(void) 
{
        #if(!PWM_Y_UP_UsingFixedFunction)
            #if(!PWM_Y_UP_PWMModeIsCenterAligned)
                PWM_Y_UP_WritePeriod(PWM_Y_UP_backup.PWMPeriod);
            #endif /* (!PWM_Y_UP_PWMModeIsCenterAligned) */

            PWM_Y_UP_WriteCounter(PWM_Y_UP_backup.PWMUdb);

            #if (PWM_Y_UP_UseStatus)
                PWM_Y_UP_STATUS_MASK = PWM_Y_UP_backup.InterruptMaskValue;
            #endif /* (PWM_Y_UP_UseStatus) */

            #if(PWM_Y_UP_DeadBandMode == PWM_Y_UP__B_PWM__DBM_256_CLOCKS || \
                PWM_Y_UP_DeadBandMode == PWM_Y_UP__B_PWM__DBM_2_4_CLOCKS)
                PWM_Y_UP_WriteDeadTime(PWM_Y_UP_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Y_UP_KillModeMinTime)
                PWM_Y_UP_WriteKillTime(PWM_Y_UP_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Y_UP_KillModeMinTime) */

            #if(PWM_Y_UP_UseControl)
                PWM_Y_UP_WriteControlRegister(PWM_Y_UP_backup.PWMControlRegister);
            #endif /* (PWM_Y_UP_UseControl) */
        #endif  /* (!PWM_Y_UP_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Y_UP_Sleep
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
*  PWM_Y_UP_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Y_UP_Sleep(void) 
{
    #if(PWM_Y_UP_UseControl)
        if(PWM_Y_UP_CTRL_ENABLE == (PWM_Y_UP_CONTROL & PWM_Y_UP_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Y_UP_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Y_UP_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Y_UP_UseControl) */

    /* Stop component */
    PWM_Y_UP_Stop();

    /* Save registers configuration */
    PWM_Y_UP_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Y_UP_Wakeup
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
*  PWM_Y_UP_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Y_UP_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Y_UP_RestoreConfig();

    if(PWM_Y_UP_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Y_UP_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
