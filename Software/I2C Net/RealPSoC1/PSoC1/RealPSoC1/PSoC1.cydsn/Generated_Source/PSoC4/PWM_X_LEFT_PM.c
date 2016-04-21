/*******************************************************************************
* File Name: PWM_X_LEFT_PM.c
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

#include "PWM_X_LEFT.h"

static PWM_X_LEFT_backupStruct PWM_X_LEFT_backup;


/*******************************************************************************
* Function Name: PWM_X_LEFT_SaveConfig
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
*  PWM_X_LEFT_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_X_LEFT_SaveConfig(void) 
{

    #if(!PWM_X_LEFT_UsingFixedFunction)
        #if(!PWM_X_LEFT_PWMModeIsCenterAligned)
            PWM_X_LEFT_backup.PWMPeriod = PWM_X_LEFT_ReadPeriod();
        #endif /* (!PWM_X_LEFT_PWMModeIsCenterAligned) */
        PWM_X_LEFT_backup.PWMUdb = PWM_X_LEFT_ReadCounter();
        #if (PWM_X_LEFT_UseStatus)
            PWM_X_LEFT_backup.InterruptMaskValue = PWM_X_LEFT_STATUS_MASK;
        #endif /* (PWM_X_LEFT_UseStatus) */

        #if(PWM_X_LEFT_DeadBandMode == PWM_X_LEFT__B_PWM__DBM_256_CLOCKS || \
            PWM_X_LEFT_DeadBandMode == PWM_X_LEFT__B_PWM__DBM_2_4_CLOCKS)
            PWM_X_LEFT_backup.PWMdeadBandValue = PWM_X_LEFT_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_X_LEFT_KillModeMinTime)
             PWM_X_LEFT_backup.PWMKillCounterPeriod = PWM_X_LEFT_ReadKillTime();
        #endif /* (PWM_X_LEFT_KillModeMinTime) */

        #if(PWM_X_LEFT_UseControl)
            PWM_X_LEFT_backup.PWMControlRegister = PWM_X_LEFT_ReadControlRegister();
        #endif /* (PWM_X_LEFT_UseControl) */
    #endif  /* (!PWM_X_LEFT_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_X_LEFT_RestoreConfig
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
*  PWM_X_LEFT_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_X_LEFT_RestoreConfig(void) 
{
        #if(!PWM_X_LEFT_UsingFixedFunction)
            #if(!PWM_X_LEFT_PWMModeIsCenterAligned)
                PWM_X_LEFT_WritePeriod(PWM_X_LEFT_backup.PWMPeriod);
            #endif /* (!PWM_X_LEFT_PWMModeIsCenterAligned) */

            PWM_X_LEFT_WriteCounter(PWM_X_LEFT_backup.PWMUdb);

            #if (PWM_X_LEFT_UseStatus)
                PWM_X_LEFT_STATUS_MASK = PWM_X_LEFT_backup.InterruptMaskValue;
            #endif /* (PWM_X_LEFT_UseStatus) */

            #if(PWM_X_LEFT_DeadBandMode == PWM_X_LEFT__B_PWM__DBM_256_CLOCKS || \
                PWM_X_LEFT_DeadBandMode == PWM_X_LEFT__B_PWM__DBM_2_4_CLOCKS)
                PWM_X_LEFT_WriteDeadTime(PWM_X_LEFT_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_X_LEFT_KillModeMinTime)
                PWM_X_LEFT_WriteKillTime(PWM_X_LEFT_backup.PWMKillCounterPeriod);
            #endif /* (PWM_X_LEFT_KillModeMinTime) */

            #if(PWM_X_LEFT_UseControl)
                PWM_X_LEFT_WriteControlRegister(PWM_X_LEFT_backup.PWMControlRegister);
            #endif /* (PWM_X_LEFT_UseControl) */
        #endif  /* (!PWM_X_LEFT_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_X_LEFT_Sleep
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
*  PWM_X_LEFT_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_X_LEFT_Sleep(void) 
{
    #if(PWM_X_LEFT_UseControl)
        if(PWM_X_LEFT_CTRL_ENABLE == (PWM_X_LEFT_CONTROL & PWM_X_LEFT_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_X_LEFT_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_X_LEFT_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_X_LEFT_UseControl) */

    /* Stop component */
    PWM_X_LEFT_Stop();

    /* Save registers configuration */
    PWM_X_LEFT_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_X_LEFT_Wakeup
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
*  PWM_X_LEFT_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_X_LEFT_Wakeup(void) 
{
     /* Restore registers values */
    PWM_X_LEFT_RestoreConfig();

    if(PWM_X_LEFT_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_X_LEFT_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
