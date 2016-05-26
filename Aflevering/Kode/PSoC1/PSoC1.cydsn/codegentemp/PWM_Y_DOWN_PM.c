/*******************************************************************************
* File Name: PWM_Y_DOWN_PM.c
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

#include "PWM_Y_DOWN.h"

static PWM_Y_DOWN_backupStruct PWM_Y_DOWN_backup;


/*******************************************************************************
* Function Name: PWM_Y_DOWN_SaveConfig
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
*  PWM_Y_DOWN_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Y_DOWN_SaveConfig(void) 
{

    #if(!PWM_Y_DOWN_UsingFixedFunction)
        #if(!PWM_Y_DOWN_PWMModeIsCenterAligned)
            PWM_Y_DOWN_backup.PWMPeriod = PWM_Y_DOWN_ReadPeriod();
        #endif /* (!PWM_Y_DOWN_PWMModeIsCenterAligned) */
        PWM_Y_DOWN_backup.PWMUdb = PWM_Y_DOWN_ReadCounter();
        #if (PWM_Y_DOWN_UseStatus)
            PWM_Y_DOWN_backup.InterruptMaskValue = PWM_Y_DOWN_STATUS_MASK;
        #endif /* (PWM_Y_DOWN_UseStatus) */

        #if(PWM_Y_DOWN_DeadBandMode == PWM_Y_DOWN__B_PWM__DBM_256_CLOCKS || \
            PWM_Y_DOWN_DeadBandMode == PWM_Y_DOWN__B_PWM__DBM_2_4_CLOCKS)
            PWM_Y_DOWN_backup.PWMdeadBandValue = PWM_Y_DOWN_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Y_DOWN_KillModeMinTime)
             PWM_Y_DOWN_backup.PWMKillCounterPeriod = PWM_Y_DOWN_ReadKillTime();
        #endif /* (PWM_Y_DOWN_KillModeMinTime) */

        #if(PWM_Y_DOWN_UseControl)
            PWM_Y_DOWN_backup.PWMControlRegister = PWM_Y_DOWN_ReadControlRegister();
        #endif /* (PWM_Y_DOWN_UseControl) */
    #endif  /* (!PWM_Y_DOWN_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Y_DOWN_RestoreConfig
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
*  PWM_Y_DOWN_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Y_DOWN_RestoreConfig(void) 
{
        #if(!PWM_Y_DOWN_UsingFixedFunction)
            #if(!PWM_Y_DOWN_PWMModeIsCenterAligned)
                PWM_Y_DOWN_WritePeriod(PWM_Y_DOWN_backup.PWMPeriod);
            #endif /* (!PWM_Y_DOWN_PWMModeIsCenterAligned) */

            PWM_Y_DOWN_WriteCounter(PWM_Y_DOWN_backup.PWMUdb);

            #if (PWM_Y_DOWN_UseStatus)
                PWM_Y_DOWN_STATUS_MASK = PWM_Y_DOWN_backup.InterruptMaskValue;
            #endif /* (PWM_Y_DOWN_UseStatus) */

            #if(PWM_Y_DOWN_DeadBandMode == PWM_Y_DOWN__B_PWM__DBM_256_CLOCKS || \
                PWM_Y_DOWN_DeadBandMode == PWM_Y_DOWN__B_PWM__DBM_2_4_CLOCKS)
                PWM_Y_DOWN_WriteDeadTime(PWM_Y_DOWN_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Y_DOWN_KillModeMinTime)
                PWM_Y_DOWN_WriteKillTime(PWM_Y_DOWN_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Y_DOWN_KillModeMinTime) */

            #if(PWM_Y_DOWN_UseControl)
                PWM_Y_DOWN_WriteControlRegister(PWM_Y_DOWN_backup.PWMControlRegister);
            #endif /* (PWM_Y_DOWN_UseControl) */
        #endif  /* (!PWM_Y_DOWN_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Y_DOWN_Sleep
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
*  PWM_Y_DOWN_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Y_DOWN_Sleep(void) 
{
    #if(PWM_Y_DOWN_UseControl)
        if(PWM_Y_DOWN_CTRL_ENABLE == (PWM_Y_DOWN_CONTROL & PWM_Y_DOWN_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Y_DOWN_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Y_DOWN_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Y_DOWN_UseControl) */

    /* Stop component */
    PWM_Y_DOWN_Stop();

    /* Save registers configuration */
    PWM_Y_DOWN_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Y_DOWN_Wakeup
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
*  PWM_Y_DOWN_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Y_DOWN_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Y_DOWN_RestoreConfig();

    if(PWM_Y_DOWN_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Y_DOWN_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
