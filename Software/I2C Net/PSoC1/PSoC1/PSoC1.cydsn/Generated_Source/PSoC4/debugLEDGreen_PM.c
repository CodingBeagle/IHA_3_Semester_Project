/*******************************************************************************
* File Name: debugLEDGreen.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "debugLEDGreen.h"

static debugLEDGreen_BACKUP_STRUCT  debugLEDGreen_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: debugLEDGreen_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet debugLEDGreen_SUT.c usage_debugLEDGreen_Sleep_Wakeup
*******************************************************************************/
void debugLEDGreen_Sleep(void)
{
    #if defined(debugLEDGreen__PC)
        debugLEDGreen_backup.pcState = debugLEDGreen_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            debugLEDGreen_backup.usbState = debugLEDGreen_CR1_REG;
            debugLEDGreen_USB_POWER_REG |= debugLEDGreen_USBIO_ENTER_SLEEP;
            debugLEDGreen_CR1_REG &= debugLEDGreen_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(debugLEDGreen__SIO)
        debugLEDGreen_backup.sioState = debugLEDGreen_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        debugLEDGreen_SIO_REG &= (uint32)(~debugLEDGreen_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: debugLEDGreen_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to debugLEDGreen_Sleep() for an example usage.
*******************************************************************************/
void debugLEDGreen_Wakeup(void)
{
    #if defined(debugLEDGreen__PC)
        debugLEDGreen_PC = debugLEDGreen_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            debugLEDGreen_USB_POWER_REG &= debugLEDGreen_USBIO_EXIT_SLEEP_PH1;
            debugLEDGreen_CR1_REG = debugLEDGreen_backup.usbState;
            debugLEDGreen_USB_POWER_REG &= debugLEDGreen_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(debugLEDGreen__SIO)
        debugLEDGreen_SIO_REG = debugLEDGreen_backup.sioState;
    #endif
}


/* [] END OF FILE */
