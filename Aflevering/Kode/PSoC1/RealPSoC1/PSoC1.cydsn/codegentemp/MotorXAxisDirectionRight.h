/*******************************************************************************
* File Name: MotorXAxisDirectionRight.h  
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

#if !defined(CY_PINS_MotorXAxisDirectionRight_H) /* Pins MotorXAxisDirectionRight_H */
#define CY_PINS_MotorXAxisDirectionRight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "MotorXAxisDirectionRight_aliases.h"


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
} MotorXAxisDirectionRight_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   MotorXAxisDirectionRight_Read(void);
void    MotorXAxisDirectionRight_Write(uint8 value);
uint8   MotorXAxisDirectionRight_ReadDataReg(void);
#if defined(MotorXAxisDirectionRight__PC) || (CY_PSOC4_4200L) 
    void    MotorXAxisDirectionRight_SetDriveMode(uint8 mode);
#endif
void    MotorXAxisDirectionRight_SetInterruptMode(uint16 position, uint16 mode);
uint8   MotorXAxisDirectionRight_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void MotorXAxisDirectionRight_Sleep(void); 
void MotorXAxisDirectionRight_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(MotorXAxisDirectionRight__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define MotorXAxisDirectionRight_DRIVE_MODE_BITS        (3)
    #define MotorXAxisDirectionRight_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - MotorXAxisDirectionRight_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the MotorXAxisDirectionRight_SetDriveMode() function.
         *  @{
         */
        #define MotorXAxisDirectionRight_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define MotorXAxisDirectionRight_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define MotorXAxisDirectionRight_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define MotorXAxisDirectionRight_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define MotorXAxisDirectionRight_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define MotorXAxisDirectionRight_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define MotorXAxisDirectionRight_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define MotorXAxisDirectionRight_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define MotorXAxisDirectionRight_MASK               MotorXAxisDirectionRight__MASK
#define MotorXAxisDirectionRight_SHIFT              MotorXAxisDirectionRight__SHIFT
#define MotorXAxisDirectionRight_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MotorXAxisDirectionRight_SetInterruptMode() function.
     *  @{
     */
        #define MotorXAxisDirectionRight_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define MotorXAxisDirectionRight_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define MotorXAxisDirectionRight_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define MotorXAxisDirectionRight_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(MotorXAxisDirectionRight__SIO)
    #define MotorXAxisDirectionRight_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(MotorXAxisDirectionRight__PC) && (CY_PSOC4_4200L)
    #define MotorXAxisDirectionRight_USBIO_ENABLE               ((uint32)0x80000000u)
    #define MotorXAxisDirectionRight_USBIO_DISABLE              ((uint32)(~MotorXAxisDirectionRight_USBIO_ENABLE))
    #define MotorXAxisDirectionRight_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define MotorXAxisDirectionRight_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define MotorXAxisDirectionRight_USBIO_ENTER_SLEEP          ((uint32)((1u << MotorXAxisDirectionRight_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << MotorXAxisDirectionRight_USBIO_SUSPEND_DEL_SHIFT)))
    #define MotorXAxisDirectionRight_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << MotorXAxisDirectionRight_USBIO_SUSPEND_SHIFT)))
    #define MotorXAxisDirectionRight_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << MotorXAxisDirectionRight_USBIO_SUSPEND_DEL_SHIFT)))
    #define MotorXAxisDirectionRight_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(MotorXAxisDirectionRight__PC)
    /* Port Configuration */
    #define MotorXAxisDirectionRight_PC                 (* (reg32 *) MotorXAxisDirectionRight__PC)
#endif
/* Pin State */
#define MotorXAxisDirectionRight_PS                     (* (reg32 *) MotorXAxisDirectionRight__PS)
/* Data Register */
#define MotorXAxisDirectionRight_DR                     (* (reg32 *) MotorXAxisDirectionRight__DR)
/* Input Buffer Disable Override */
#define MotorXAxisDirectionRight_INP_DIS                (* (reg32 *) MotorXAxisDirectionRight__PC2)

/* Interrupt configuration Registers */
#define MotorXAxisDirectionRight_INTCFG                 (* (reg32 *) MotorXAxisDirectionRight__INTCFG)
#define MotorXAxisDirectionRight_INTSTAT                (* (reg32 *) MotorXAxisDirectionRight__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define MotorXAxisDirectionRight_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(MotorXAxisDirectionRight__SIO)
    #define MotorXAxisDirectionRight_SIO_REG            (* (reg32 *) MotorXAxisDirectionRight__SIO)
#endif /* (MotorXAxisDirectionRight__SIO_CFG) */

/* USBIO registers */
#if !defined(MotorXAxisDirectionRight__PC) && (CY_PSOC4_4200L)
    #define MotorXAxisDirectionRight_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define MotorXAxisDirectionRight_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define MotorXAxisDirectionRight_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define MotorXAxisDirectionRight_DRIVE_MODE_SHIFT       (0x00u)
#define MotorXAxisDirectionRight_DRIVE_MODE_MASK        (0x07u << MotorXAxisDirectionRight_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins MotorXAxisDirectionRight_H */


/* [] END OF FILE */
