/*******************************************************************************
* File Name: Shoot.c  
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
#include "Shoot.h"

static Shoot_BACKUP_STRUCT  Shoot_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Shoot_Sleep
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
*  \snippet Shoot_SUT.c usage_Shoot_Sleep_Wakeup
*******************************************************************************/
void Shoot_Sleep(void)
{
    #if defined(Shoot__PC)
        Shoot_backup.pcState = Shoot_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Shoot_backup.usbState = Shoot_CR1_REG;
            Shoot_USB_POWER_REG |= Shoot_USBIO_ENTER_SLEEP;
            Shoot_CR1_REG &= Shoot_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Shoot__SIO)
        Shoot_backup.sioState = Shoot_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Shoot_SIO_REG &= (uint32)(~Shoot_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Shoot_Wakeup
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
*  Refer to Shoot_Sleep() for an example usage.
*******************************************************************************/
void Shoot_Wakeup(void)
{
    #if defined(Shoot__PC)
        Shoot_PC = Shoot_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Shoot_USB_POWER_REG &= Shoot_USBIO_EXIT_SLEEP_PH1;
            Shoot_CR1_REG = Shoot_backup.usbState;
            Shoot_USB_POWER_REG &= Shoot_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Shoot__SIO)
        Shoot_SIO_REG = Shoot_backup.sioState;
    #endif
}


/* [] END OF FILE */
