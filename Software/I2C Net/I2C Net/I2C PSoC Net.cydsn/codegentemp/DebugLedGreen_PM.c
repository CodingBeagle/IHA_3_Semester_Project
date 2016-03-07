/*******************************************************************************
* File Name: DebugLedGreen.c  
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
#include "DebugLedGreen.h"

static DebugLedGreen_BACKUP_STRUCT  DebugLedGreen_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: DebugLedGreen_Sleep
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
*  \snippet DebugLedGreen_SUT.c usage_DebugLedGreen_Sleep_Wakeup
*******************************************************************************/
void DebugLedGreen_Sleep(void)
{
    #if defined(DebugLedGreen__PC)
        DebugLedGreen_backup.pcState = DebugLedGreen_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            DebugLedGreen_backup.usbState = DebugLedGreen_CR1_REG;
            DebugLedGreen_USB_POWER_REG |= DebugLedGreen_USBIO_ENTER_SLEEP;
            DebugLedGreen_CR1_REG &= DebugLedGreen_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DebugLedGreen__SIO)
        DebugLedGreen_backup.sioState = DebugLedGreen_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        DebugLedGreen_SIO_REG &= (uint32)(~DebugLedGreen_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: DebugLedGreen_Wakeup
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
*  Refer to DebugLedGreen_Sleep() for an example usage.
*******************************************************************************/
void DebugLedGreen_Wakeup(void)
{
    #if defined(DebugLedGreen__PC)
        DebugLedGreen_PC = DebugLedGreen_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            DebugLedGreen_USB_POWER_REG &= DebugLedGreen_USBIO_EXIT_SLEEP_PH1;
            DebugLedGreen_CR1_REG = DebugLedGreen_backup.usbState;
            DebugLedGreen_USB_POWER_REG &= DebugLedGreen_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DebugLedGreen__SIO)
        DebugLedGreen_SIO_REG = DebugLedGreen_backup.sioState;
    #endif
}


/* [] END OF FILE */
