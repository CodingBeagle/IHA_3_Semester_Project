/*******************************************************************************
* File Name: DebugLEDGreen.c  
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
#include "DebugLEDGreen.h"

static DebugLEDGreen_BACKUP_STRUCT  DebugLEDGreen_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: DebugLEDGreen_Sleep
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
*  \snippet DebugLEDGreen_SUT.c usage_DebugLEDGreen_Sleep_Wakeup
*******************************************************************************/
void DebugLEDGreen_Sleep(void)
{
    #if defined(DebugLEDGreen__PC)
        DebugLEDGreen_backup.pcState = DebugLEDGreen_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            DebugLEDGreen_backup.usbState = DebugLEDGreen_CR1_REG;
            DebugLEDGreen_USB_POWER_REG |= DebugLEDGreen_USBIO_ENTER_SLEEP;
            DebugLEDGreen_CR1_REG &= DebugLEDGreen_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DebugLEDGreen__SIO)
        DebugLEDGreen_backup.sioState = DebugLEDGreen_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        DebugLEDGreen_SIO_REG &= (uint32)(~DebugLEDGreen_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: DebugLEDGreen_Wakeup
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
*  Refer to DebugLEDGreen_Sleep() for an example usage.
*******************************************************************************/
void DebugLEDGreen_Wakeup(void)
{
    #if defined(DebugLEDGreen__PC)
        DebugLEDGreen_PC = DebugLEDGreen_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            DebugLEDGreen_USB_POWER_REG &= DebugLEDGreen_USBIO_EXIT_SLEEP_PH1;
            DebugLEDGreen_CR1_REG = DebugLEDGreen_backup.usbState;
            DebugLEDGreen_USB_POWER_REG &= DebugLEDGreen_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DebugLEDGreen__SIO)
        DebugLEDGreen_SIO_REG = DebugLEDGreen_backup.sioState;
    #endif
}


/* [] END OF FILE */
