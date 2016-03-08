/*******************************************************************************
* File Name: DebugLEDRED.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DebugLEDRED_H) /* Pins DebugLEDRED_H */
#define CY_PINS_DebugLEDRED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "DebugLEDRED_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} DebugLEDRED_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   DebugLEDRED_Read(void);
void    DebugLEDRED_Write(uint8 value);
uint8   DebugLEDRED_ReadDataReg(void);
#if defined(DebugLEDRED__PC) || (CY_PSOC4_4200L) 
    void    DebugLEDRED_SetDriveMode(uint8 mode);
#endif
void    DebugLEDRED_SetInterruptMode(uint16 position, uint16 mode);
uint8   DebugLEDRED_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void DebugLEDRED_Sleep(void); 
void DebugLEDRED_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(DebugLEDRED__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define DebugLEDRED_DRIVE_MODE_BITS        (3)
    #define DebugLEDRED_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - DebugLEDRED_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the DebugLEDRED_SetDriveMode() function.
         *  @{
         */
        #define DebugLEDRED_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define DebugLEDRED_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define DebugLEDRED_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define DebugLEDRED_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define DebugLEDRED_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define DebugLEDRED_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define DebugLEDRED_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define DebugLEDRED_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define DebugLEDRED_MASK               DebugLEDRED__MASK
#define DebugLEDRED_SHIFT              DebugLEDRED__SHIFT
#define DebugLEDRED_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DebugLEDRED_SetInterruptMode() function.
     *  @{
     */
        #define DebugLEDRED_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define DebugLEDRED_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define DebugLEDRED_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define DebugLEDRED_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(DebugLEDRED__SIO)
    #define DebugLEDRED_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(DebugLEDRED__PC) && (CY_PSOC4_4200L)
    #define DebugLEDRED_USBIO_ENABLE               ((uint32)0x80000000u)
    #define DebugLEDRED_USBIO_DISABLE              ((uint32)(~DebugLEDRED_USBIO_ENABLE))
    #define DebugLEDRED_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define DebugLEDRED_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define DebugLEDRED_USBIO_ENTER_SLEEP          ((uint32)((1u << DebugLEDRED_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << DebugLEDRED_USBIO_SUSPEND_DEL_SHIFT)))
    #define DebugLEDRED_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << DebugLEDRED_USBIO_SUSPEND_SHIFT)))
    #define DebugLEDRED_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << DebugLEDRED_USBIO_SUSPEND_DEL_SHIFT)))
    #define DebugLEDRED_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(DebugLEDRED__PC)
    /* Port Configuration */
    #define DebugLEDRED_PC                 (* (reg32 *) DebugLEDRED__PC)
#endif
/* Pin State */
#define DebugLEDRED_PS                     (* (reg32 *) DebugLEDRED__PS)
/* Data Register */
#define DebugLEDRED_DR                     (* (reg32 *) DebugLEDRED__DR)
/* Input Buffer Disable Override */
#define DebugLEDRED_INP_DIS                (* (reg32 *) DebugLEDRED__PC2)

/* Interrupt configuration Registers */
#define DebugLEDRED_INTCFG                 (* (reg32 *) DebugLEDRED__INTCFG)
#define DebugLEDRED_INTSTAT                (* (reg32 *) DebugLEDRED__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define DebugLEDRED_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(DebugLEDRED__SIO)
    #define DebugLEDRED_SIO_REG            (* (reg32 *) DebugLEDRED__SIO)
#endif /* (DebugLEDRED__SIO_CFG) */

/* USBIO registers */
#if !defined(DebugLEDRED__PC) && (CY_PSOC4_4200L)
    #define DebugLEDRED_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define DebugLEDRED_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define DebugLEDRED_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define DebugLEDRED_DRIVE_MODE_SHIFT       (0x00u)
#define DebugLEDRED_DRIVE_MODE_MASK        (0x07u << DebugLEDRED_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins DebugLEDRED_H */


/* [] END OF FILE */
