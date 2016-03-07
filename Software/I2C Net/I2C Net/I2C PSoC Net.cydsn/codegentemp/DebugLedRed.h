/*******************************************************************************
* File Name: DebugLedRed.h  
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

#if !defined(CY_PINS_DebugLedRed_H) /* Pins DebugLedRed_H */
#define CY_PINS_DebugLedRed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "DebugLedRed_aliases.h"


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
} DebugLedRed_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   DebugLedRed_Read(void);
void    DebugLedRed_Write(uint8 value);
uint8   DebugLedRed_ReadDataReg(void);
#if defined(DebugLedRed__PC) || (CY_PSOC4_4200L) 
    void    DebugLedRed_SetDriveMode(uint8 mode);
#endif
void    DebugLedRed_SetInterruptMode(uint16 position, uint16 mode);
uint8   DebugLedRed_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void DebugLedRed_Sleep(void); 
void DebugLedRed_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(DebugLedRed__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define DebugLedRed_DRIVE_MODE_BITS        (3)
    #define DebugLedRed_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - DebugLedRed_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the DebugLedRed_SetDriveMode() function.
         *  @{
         */
        #define DebugLedRed_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define DebugLedRed_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define DebugLedRed_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define DebugLedRed_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define DebugLedRed_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define DebugLedRed_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define DebugLedRed_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define DebugLedRed_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define DebugLedRed_MASK               DebugLedRed__MASK
#define DebugLedRed_SHIFT              DebugLedRed__SHIFT
#define DebugLedRed_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DebugLedRed_SetInterruptMode() function.
     *  @{
     */
        #define DebugLedRed_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define DebugLedRed_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define DebugLedRed_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define DebugLedRed_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(DebugLedRed__SIO)
    #define DebugLedRed_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(DebugLedRed__PC) && (CY_PSOC4_4200L)
    #define DebugLedRed_USBIO_ENABLE               ((uint32)0x80000000u)
    #define DebugLedRed_USBIO_DISABLE              ((uint32)(~DebugLedRed_USBIO_ENABLE))
    #define DebugLedRed_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define DebugLedRed_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define DebugLedRed_USBIO_ENTER_SLEEP          ((uint32)((1u << DebugLedRed_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << DebugLedRed_USBIO_SUSPEND_DEL_SHIFT)))
    #define DebugLedRed_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << DebugLedRed_USBIO_SUSPEND_SHIFT)))
    #define DebugLedRed_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << DebugLedRed_USBIO_SUSPEND_DEL_SHIFT)))
    #define DebugLedRed_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(DebugLedRed__PC)
    /* Port Configuration */
    #define DebugLedRed_PC                 (* (reg32 *) DebugLedRed__PC)
#endif
/* Pin State */
#define DebugLedRed_PS                     (* (reg32 *) DebugLedRed__PS)
/* Data Register */
#define DebugLedRed_DR                     (* (reg32 *) DebugLedRed__DR)
/* Input Buffer Disable Override */
#define DebugLedRed_INP_DIS                (* (reg32 *) DebugLedRed__PC2)

/* Interrupt configuration Registers */
#define DebugLedRed_INTCFG                 (* (reg32 *) DebugLedRed__INTCFG)
#define DebugLedRed_INTSTAT                (* (reg32 *) DebugLedRed__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define DebugLedRed_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(DebugLedRed__SIO)
    #define DebugLedRed_SIO_REG            (* (reg32 *) DebugLedRed__SIO)
#endif /* (DebugLedRed__SIO_CFG) */

/* USBIO registers */
#if !defined(DebugLedRed__PC) && (CY_PSOC4_4200L)
    #define DebugLedRed_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define DebugLedRed_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define DebugLedRed_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define DebugLedRed_DRIVE_MODE_SHIFT       (0x00u)
#define DebugLedRed_DRIVE_MODE_MASK        (0x07u << DebugLedRed_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins DebugLedRed_H */


/* [] END OF FILE */
