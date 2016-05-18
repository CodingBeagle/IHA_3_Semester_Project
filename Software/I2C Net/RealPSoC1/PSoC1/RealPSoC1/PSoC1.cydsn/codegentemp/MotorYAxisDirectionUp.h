/*******************************************************************************
* File Name: MotorYAxisDirectionUp.h  
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

#if !defined(CY_PINS_MotorYAxisDirectionUp_H) /* Pins MotorYAxisDirectionUp_H */
#define CY_PINS_MotorYAxisDirectionUp_H

#include "cytypes.h"
#include "cyfitter.h"
#include "MotorYAxisDirectionUp_aliases.h"


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
} MotorYAxisDirectionUp_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   MotorYAxisDirectionUp_Read(void);
void    MotorYAxisDirectionUp_Write(uint8 value);
uint8   MotorYAxisDirectionUp_ReadDataReg(void);
#if defined(MotorYAxisDirectionUp__PC) || (CY_PSOC4_4200L) 
    void    MotorYAxisDirectionUp_SetDriveMode(uint8 mode);
#endif
void    MotorYAxisDirectionUp_SetInterruptMode(uint16 position, uint16 mode);
uint8   MotorYAxisDirectionUp_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void MotorYAxisDirectionUp_Sleep(void); 
void MotorYAxisDirectionUp_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(MotorYAxisDirectionUp__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define MotorYAxisDirectionUp_DRIVE_MODE_BITS        (3)
    #define MotorYAxisDirectionUp_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - MotorYAxisDirectionUp_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the MotorYAxisDirectionUp_SetDriveMode() function.
         *  @{
         */
        #define MotorYAxisDirectionUp_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define MotorYAxisDirectionUp_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define MotorYAxisDirectionUp_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define MotorYAxisDirectionUp_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define MotorYAxisDirectionUp_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define MotorYAxisDirectionUp_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define MotorYAxisDirectionUp_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define MotorYAxisDirectionUp_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define MotorYAxisDirectionUp_MASK               MotorYAxisDirectionUp__MASK
#define MotorYAxisDirectionUp_SHIFT              MotorYAxisDirectionUp__SHIFT
#define MotorYAxisDirectionUp_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MotorYAxisDirectionUp_SetInterruptMode() function.
     *  @{
     */
        #define MotorYAxisDirectionUp_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define MotorYAxisDirectionUp_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define MotorYAxisDirectionUp_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define MotorYAxisDirectionUp_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(MotorYAxisDirectionUp__SIO)
    #define MotorYAxisDirectionUp_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(MotorYAxisDirectionUp__PC) && (CY_PSOC4_4200L)
    #define MotorYAxisDirectionUp_USBIO_ENABLE               ((uint32)0x80000000u)
    #define MotorYAxisDirectionUp_USBIO_DISABLE              ((uint32)(~MotorYAxisDirectionUp_USBIO_ENABLE))
    #define MotorYAxisDirectionUp_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define MotorYAxisDirectionUp_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define MotorYAxisDirectionUp_USBIO_ENTER_SLEEP          ((uint32)((1u << MotorYAxisDirectionUp_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << MotorYAxisDirectionUp_USBIO_SUSPEND_DEL_SHIFT)))
    #define MotorYAxisDirectionUp_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << MotorYAxisDirectionUp_USBIO_SUSPEND_SHIFT)))
    #define MotorYAxisDirectionUp_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << MotorYAxisDirectionUp_USBIO_SUSPEND_DEL_SHIFT)))
    #define MotorYAxisDirectionUp_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(MotorYAxisDirectionUp__PC)
    /* Port Configuration */
    #define MotorYAxisDirectionUp_PC                 (* (reg32 *) MotorYAxisDirectionUp__PC)
#endif
/* Pin State */
#define MotorYAxisDirectionUp_PS                     (* (reg32 *) MotorYAxisDirectionUp__PS)
/* Data Register */
#define MotorYAxisDirectionUp_DR                     (* (reg32 *) MotorYAxisDirectionUp__DR)
/* Input Buffer Disable Override */
#define MotorYAxisDirectionUp_INP_DIS                (* (reg32 *) MotorYAxisDirectionUp__PC2)

/* Interrupt configuration Registers */
#define MotorYAxisDirectionUp_INTCFG                 (* (reg32 *) MotorYAxisDirectionUp__INTCFG)
#define MotorYAxisDirectionUp_INTSTAT                (* (reg32 *) MotorYAxisDirectionUp__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define MotorYAxisDirectionUp_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(MotorYAxisDirectionUp__SIO)
    #define MotorYAxisDirectionUp_SIO_REG            (* (reg32 *) MotorYAxisDirectionUp__SIO)
#endif /* (MotorYAxisDirectionUp__SIO_CFG) */

/* USBIO registers */
#if !defined(MotorYAxisDirectionUp__PC) && (CY_PSOC4_4200L)
    #define MotorYAxisDirectionUp_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define MotorYAxisDirectionUp_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define MotorYAxisDirectionUp_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define MotorYAxisDirectionUp_DRIVE_MODE_SHIFT       (0x00u)
#define MotorYAxisDirectionUp_DRIVE_MODE_MASK        (0x07u << MotorYAxisDirectionUp_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins MotorYAxisDirectionUp_H */


/* [] END OF FILE */
