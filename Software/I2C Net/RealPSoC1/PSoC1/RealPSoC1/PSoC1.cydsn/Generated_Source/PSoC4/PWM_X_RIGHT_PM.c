/*******************************************************************************
* File Name: PWM_X_RIGHT_PM.c
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

#include "PWM_X_RIGHT.h"

static PWM_X_RIGHT_backupStruct PWM_X_RIGHT_backup;


/*******************************************************************************
* Function Name: PWM_X_RIGHT_SaveConfig
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
*  PWM_X_RIGHT_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_X_RIGHT_SaveConfig(void) 
{

    #if(!PWM_X_RIGHT_UsingFixedFunction)
        #if(!PWM_X_RIGHT_PWMModeIsCenterAligned)
            PWM_X_RIGHT_backup.PWMPeriod = PWM_X_RIGHT_ReadPeriod();
        #endif /* (!PWM_X_RIGHT_PWMModeIsCenterAligned) */
        PWM_X_RIGHT_backup.PWMUdb = PWM_X_RIGHT_ReadCounter();
        #if (PWM_X_RIGHT_UseStatus)
            PWM_X_RIGHT_backup.InterruptMaskValue = PWM_X_RIGHT_STATUS_MASK;
        #endif /* (PWM_X_RIGHT_UseStatus) */

        #if(PWM_X_RIGHT_DeadBandMode == PWM_X_RIGHT__B_PWM__DBM_256_CLOCKS || \
            PWM_X_RIGHT_DeadBandMode == PWM_X_RIGHT__B_PWM__DBM_2_4_CLOCKS)
            PWM_X_RIGHT_backup.PWMdeadBandValue = PWM_X_RIGHT_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_X_RIGHT_KillModeMinTime)
             PWM_X_RIGHT_backup.PWMKillCounterPeriod = PWM_X_RIGHT_ReadKillTime();
        #endif /* (PWM_X_RIGHT_KillModeMinTime) */

        #if(PWM_X_RIGHT_UseControl)
            PWM_X_RIGHT_backup.PWMControlRegister = PWM_X_RIGHT_ReadControlRegister();
        #endif /* (PWM_X_RIGHT_UseControl) */
    #endif  /* (!PWM_X_RIGHT_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_X_RIGHT_RestoreConfig
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
*  PWM_X_RIGHT_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_X_RIGHT_RestoreConfig(void) 
{
        #if(!PWM_X_RIGHT_UsingFixedFunction)
            #if(!PWM_X_RIGHT_PWMModeIsCenterAligned)
                PWM_X_RIGHT_WritePeriod(PWM_X_RIGHT_backup.PWMPeriod);
            #endif /* (!PWM_X_RIGHT_PWMModeIsCenterAligned) */

            PWM_X_RIGHT_WriteCounter(PWM_X_RIGHT_backup.PWMUdb);

            #if (PWM_X_RIGHT_UseStatus)
                PWM_X_RIGHT_STATUS_MASK = PWM_X_RIGHT_backup.InterruptMaskValue;
            #endif /* (PWM_X_RIGHT_UseStatus) */

            #if(PWM_X_RIGHT_DeadBandMode == PWM_X_RIGHT__B_PWM__DBM_256_CLOCKS || \
                PWM_X_RIGHT_DeadBandMode == PWM_X_RIGHT__B_PWM__DBM_2_4_CLOCKS)
                PWM_X_RIGHT_WriteDeadTime(PWM_X_RIGHT_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_X_RIGHT_KillModeMinTime)
                PWM_X_RIGHT_WriteKillTime(PWM_X_RIGHT_backup.PWMKillCounterPeriod);
            #endif /* (PWM_X_RIGHT_KillModeMinTime) */

            #if(PWM_X_RIGHT_UseControl)
                PWM_X_RIGHT_WriteControlRegister(PWM_X_RIGHT_backup.PWMControlRegister);
            #endif /* (PWM_X_RIGHT_UseControl) */
        #endif  /* (!PWM_X_RIGHT_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_X_RIGHT_Sleep
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
*  PWM_X_RIGHT_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_X_RIGHT_Sleep(void) 
{
    #if(PWM_X_RIGHT_UseControl)
        if(PWM_X_RIGHT_CTRL_ENABLE == (PWM_X_RIGHT_CONTROL & PWM_X_RIGHT_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_X_RIGHT_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_X_RIGHT_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_X_RIGHT_UseControl) */

    /* Stop component */
    PWM_X_RIGHT_Stop();

    /* Save registers configuration */
    PWM_X_RIGHT_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_X_RIGHT_Wakeup
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
*  PWM_X_RIGHT_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_X_RIGHT_Wakeup(void) 
{
     /* Restore registers values */
    PWM_X_RIGHT_RestoreConfig();

    if(PWM_X_RIGHT_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_X_RIGHT_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
