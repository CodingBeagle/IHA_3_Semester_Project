/*******************************************************************************
* File Name: MotorYAxisDirectionDown.h  
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

#if !defined(CY_PINS_MotorYAxisDirectionDown_H) /* Pins MotorYAxisDirectionDown_H */
#define CY_PINS_MotorYAxisDirectionDown_H

#include "cytypes.h"
#include "cyfitter.h"
#include "MotorYAxisDirectionDown_aliases.h"


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
} MotorYAxisDirectionDown_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   MotorYAxisDirectionDown_Read(void);
void    MotorYAxisDirectionDown_Write(uint8 value);
uint8   MotorYAxisDirectionDown_ReadDataReg(void);
#if defined(MotorYAxisDirectionDown__PC) || (CY_PSOC4_4200L) 
    void    MotorYAxisDirectionDown_SetDriveMode(uint8 mode);
#endif
void    MotorYAxisDirectionDown_SetInterruptMode(uint16 position, uint16 mode);
uint8   MotorYAxisDirectionDown_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void MotorYAxisDirectionDown_Sleep(void); 
void MotorYAxisDirectionDown_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(MotorYAxisDirectionDown__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define MotorYAxisDirectionDown_DRIVE_MODE_BITS        (3)
    #define MotorYAxisDirectionDown_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - MotorYAxisDirectionDown_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the MotorYAxisDirectionDown_SetDriveMode() function.
         *  @{
         */
        #define MotorYAxisDirectionDown_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define MotorYAxisDirectionDown_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define MotorYAxisDirectionDown_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define MotorYAxisDirectionDown_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define MotorYAxisDirectionDown_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define MotorYAxisDirectionDown_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define MotorYAxisDirectionDown_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define MotorYAxisDirectionDown_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define MotorYAxisDirectionDown_MASK               MotorYAxisDirectionDown__MASK
#define MotorYAxisDirectionDown_SHIFT              MotorYAxisDirectionDown__SHIFT
#define MotorYAxisDirectionDown_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MotorYAxisDirectionDown_SetInterruptMode() function.
     *  @{
     */
        #define MotorYAxisDirectionDown_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define MotorYAxisDirectionDown_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define MotorYAxisDirectionDown_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define MotorYAxisDirectionDown_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(MotorYAxisDirectionDown__SIO)
    #define MotorYAxisDirectionDown_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(MotorYAxisDirectionDown__PC) && (CY_PSOC4_4200L)
    #define MotorYAxisDirectionDown_USBIO_ENABLE               ((uint32)0x80000000u)
    #define MotorYAxisDirectionDown_USBIO_DISABLE              ((uint32)(~MotorYAxisDirectionDown_USBIO_ENABLE))
    #define MotorYAxisDirectionDown_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define MotorYAxisDirectionDown_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define MotorYAxisDirectionDown_USBIO_ENTER_SLEEP          ((uint32)((1u << MotorYAxisDirectionDown_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << MotorYAxisDirectionDown_USBIO_SUSPEND_DEL_SHIFT)))
    #define MotorYAxisDirectionDown_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << MotorYAxisDirectionDown_USBIO_SUSPEND_SHIFT)))
    #define MotorYAxisDirectionDown_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << MotorYAxisDirectionDown_USBIO_SUSPEND_DEL_SHIFT)))
    #define MotorYAxisDirectionDown_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(MotorYAxisDirectionDown__PC)
    /* Port Configuration */
    #define MotorYAxisDirectionDown_PC                 (* (reg32 *) MotorYAxisDirectionDown__PC)
#endif
/* Pin State */
#define MotorYAxisDirectionDown_PS                     (* (reg32 *) MotorYAxisDirectionDown__PS)
/* Data Register */
#define MotorYAxisDirectionDown_DR                     (* (reg32 *) MotorYAxisDirectionDown__DR)
/* Input Buffer Disable Override */
#define MotorYAxisDirectionDown_INP_DIS                (* (reg32 *) MotorYAxisDirectionDown__PC2)

/* Interrupt configuration Registers */
#define MotorYAxisDirectionDown_INTCFG                 (* (reg32 *) MotorYAxisDirectionDown__INTCFG)
#define MotorYAxisDirectionDown_INTSTAT                (* (reg32 *) MotorYAxisDirectionDown__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define MotorYAxisDirectionDown_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(MotorYAxisDirectionDown__SIO)
    #define MotorYAxisDirectionDown_SIO_REG            (* (reg32 *) MotorYAxisDirectionDown__SIO)
#endif /* (MotorYAxisDirectionDown__SIO_CFG) */

/* USBIO registers */
#if !defined(MotorYAxisDirectionDown__PC) && (CY_PSOC4_4200L)
    #define MotorYAxisDirectionDown_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define MotorYAxisDirectionDown_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define MotorYAxisDirectionDown_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define MotorYAxisDirectionDown_DRIVE_MODE_SHIFT       (0x00u)
#define MotorYAxisDirectionDown_DRIVE_MODE_MASK        (0x07u << MotorYAxisDirectionDown_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins MotorYAxisDirectionDown_H */


/* [] END OF FILE */
