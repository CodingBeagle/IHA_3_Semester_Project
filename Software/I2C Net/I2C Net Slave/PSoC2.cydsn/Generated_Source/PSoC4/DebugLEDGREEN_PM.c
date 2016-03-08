/*******************************************************************************
* File Name: DebugLEDGREEN.c  
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
#include "DebugLEDGREEN.h"

static DebugLEDGREEN_BACKUP_STRUCT  DebugLEDGREEN_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: DebugLEDGREEN_Sleep
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
*  \snippet DebugLEDGREEN_SUT.c usage_DebugLEDGREEN_Sleep_Wakeup
*******************************************************************************/
void DebugLEDGREEN_Sleep(void)
{
    #if defined(DebugLEDGREEN__PC)
        DebugLEDGREEN_backup.pcState = DebugLEDGREEN_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            DebugLEDGREEN_backup.usbState = DebugLEDGREEN_CR1_REG;
            DebugLEDGREEN_USB_POWER_REG |= DebugLEDGREEN_USBIO_ENTER_SLEEP;
            DebugLEDGREEN_CR1_REG &= DebugLEDGREEN_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DebugLEDGREEN__SIO)
        DebugLEDGREEN_backup.sioState = DebugLEDGREEN_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        DebugLEDGREEN_SIO_REG &= (uint32)(~DebugLEDGREEN_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: DebugLEDGREEN_Wakeup
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
*  Refer to DebugLEDGREEN_Sleep() for an example usage.
*******************************************************************************/
void DebugLEDGREEN_Wakeup(void)
{
    #if defined(DebugLEDGREEN__PC)
        DebugLEDGREEN_PC = DebugLEDGREEN_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            DebugLEDGREEN_USB_POWER_REG &= DebugLEDGREEN_USBIO_EXIT_SLEEP_PH1;
            DebugLEDGREEN_CR1_REG = DebugLEDGREEN_backup.usbState;
            DebugLEDGREEN_USB_POWER_REG &= DebugLEDGREEN_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DebugLEDGREEN__SIO)
        DebugLEDGREEN_SIO_REG = DebugLEDGREEN_backup.sioState;
    #endif
}


/* [] END OF FILE */
