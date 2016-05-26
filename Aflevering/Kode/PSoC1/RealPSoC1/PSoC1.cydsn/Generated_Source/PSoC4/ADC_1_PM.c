/*******************************************************************************
* File Name: ADC_1_PM.c
* Version 2.30
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_1.h"


/***************************************
* Local data allocation
***************************************/

static ADC_1_BACKUP_STRUCT  ADC_1_backup =
{
    ADC_1_DISABLED
};


/*******************************************************************************
* Function Name: ADC_1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_1_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_1_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_1_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_1_backup - modified.
*
*******************************************************************************/
void ADC_1_Sleep(void)
{
    /* During deepsleep/ hibernate mode keep SARMUX active, i.e. do not open
    *   all switches (disconnect), to be used for ADFT
    */
    ADC_1_SAR_DFT_CTRL_REG |= ADC_1_ADFT_OVERRIDE;
    if((ADC_1_SAR_CTRL_REG  & ADC_1_ENABLE) != 0u)
    {
        if((ADC_1_SAR_SAMPLE_CTRL_REG & ADC_1_CONTINUOUS_EN) != 0u)
        {
            ADC_1_backup.enableState = ADC_1_ENABLED | ADC_1_STARTED;
        }
        else
        {
            ADC_1_backup.enableState = ADC_1_ENABLED;
        }
        ADC_1_StopConvert();
        ADC_1_Stop();
        
        /* Disable the SAR internal pump before entering the chip low power mode */
        if((ADC_1_SAR_CTRL_REG & ADC_1_BOOSTPUMP_EN) != 0u)
        {
            ADC_1_SAR_CTRL_REG &= (uint32)~ADC_1_BOOSTPUMP_EN;
            ADC_1_backup.enableState |= ADC_1_BOOSTPUMP_ENABLED;
        }
    }
    else
    {
        ADC_1_backup.enableState = ADC_1_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_1_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers.
*  This should be called just after awaking from sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_1_backup - used.
*
*******************************************************************************/
void ADC_1_Wakeup(void)
{
    ADC_1_SAR_DFT_CTRL_REG &= (uint32)~ADC_1_ADFT_OVERRIDE;
    if(ADC_1_backup.enableState != ADC_1_DISABLED)
    {
        /* Enable the SAR internal pump  */
        if((ADC_1_backup.enableState & ADC_1_BOOSTPUMP_ENABLED) != 0u)
        {
            ADC_1_SAR_CTRL_REG |= ADC_1_BOOSTPUMP_EN;
        }
        ADC_1_Enable();
        if((ADC_1_backup.enableState & ADC_1_STARTED) != 0u)
        {
            ADC_1_StartConvert();
        }
    }
}
/* [] END OF FILE */
