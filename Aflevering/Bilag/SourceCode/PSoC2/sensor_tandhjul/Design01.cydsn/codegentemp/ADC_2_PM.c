/*******************************************************************************
* File Name: ADC_2_PM.c
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

#include "ADC_2.h"


/***************************************
* Local data allocation
***************************************/

static ADC_2_BACKUP_STRUCT  ADC_2_backup =
{
    ADC_2_DISABLED
};


/*******************************************************************************
* Function Name: ADC_2_SaveConfig
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
void ADC_2_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_2_RestoreConfig
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
void ADC_2_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_2_Sleep
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
*  ADC_2_backup - modified.
*
*******************************************************************************/
void ADC_2_Sleep(void)
{
    /* During deepsleep/ hibernate mode keep SARMUX active, i.e. do not open
    *   all switches (disconnect), to be used for ADFT
    */
    ADC_2_SAR_DFT_CTRL_REG |= ADC_2_ADFT_OVERRIDE;
    if((ADC_2_SAR_CTRL_REG  & ADC_2_ENABLE) != 0u)
    {
        if((ADC_2_SAR_SAMPLE_CTRL_REG & ADC_2_CONTINUOUS_EN) != 0u)
        {
            ADC_2_backup.enableState = ADC_2_ENABLED | ADC_2_STARTED;
        }
        else
        {
            ADC_2_backup.enableState = ADC_2_ENABLED;
        }
        ADC_2_StopConvert();
        ADC_2_Stop();
        
        /* Disable the SAR internal pump before entering the chip low power mode */
        if((ADC_2_SAR_CTRL_REG & ADC_2_BOOSTPUMP_EN) != 0u)
        {
            ADC_2_SAR_CTRL_REG &= (uint32)~ADC_2_BOOSTPUMP_EN;
            ADC_2_backup.enableState |= ADC_2_BOOSTPUMP_ENABLED;
        }
    }
    else
    {
        ADC_2_backup.enableState = ADC_2_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_2_Wakeup
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
*  ADC_2_backup - used.
*
*******************************************************************************/
void ADC_2_Wakeup(void)
{
    ADC_2_SAR_DFT_CTRL_REG &= (uint32)~ADC_2_ADFT_OVERRIDE;
    if(ADC_2_backup.enableState != ADC_2_DISABLED)
    {
        /* Enable the SAR internal pump  */
        if((ADC_2_backup.enableState & ADC_2_BOOSTPUMP_ENABLED) != 0u)
        {
            ADC_2_SAR_CTRL_REG |= ADC_2_BOOSTPUMP_EN;
        }
        ADC_2_Enable();
        if((ADC_2_backup.enableState & ADC_2_STARTED) != 0u)
        {
            ADC_2_StartConvert();
        }
    }
}
/* [] END OF FILE */
