/*******************************************************************************
* File Name: debugLEDRed.h  
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

#if !defined(CY_PINS_debugLEDRed_H) /* Pins debugLEDRed_H */
#define CY_PINS_debugLEDRed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "debugLEDRed_aliases.h"


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
} debugLEDRed_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   debugLEDRed_Read(void);
void    debugLEDRed_Write(uint8 value);
uint8   debugLEDRed_ReadDataReg(void);
#if defined(debugLEDRed__PC) || (CY_PSOC4_4200L) 
    void    debugLEDRed_SetDriveMode(uint8 mode);
#endif
void    debugLEDRed_SetInterruptMode(uint16 position, uint16 mode);
uint8   debugLEDRed_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void debugLEDRed_Sleep(void); 
void debugLEDRed_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(debugLEDRed__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define debugLEDRed_DRIVE_MODE_BITS        (3)
    #define debugLEDRed_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - debugLEDRed_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the debugLEDRed_SetDriveMode() function.
         *  @{
         */
        #define debugLEDRed_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define debugLEDRed_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define debugLEDRed_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define debugLEDRed_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define debugLEDRed_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define debugLEDRed_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define debugLEDRed_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define debugLEDRed_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define debugLEDRed_MASK               debugLEDRed__MASK
#define debugLEDRed_SHIFT              debugLEDRed__SHIFT
#define debugLEDRed_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in debugLEDRed_SetInterruptMode() function.
     *  @{
     */
        #define debugLEDRed_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define debugLEDRed_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define debugLEDRed_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define debugLEDRed_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(debugLEDRed__SIO)
    #define debugLEDRed_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(debugLEDRed__PC) && (CY_PSOC4_4200L)
    #define debugLEDRed_USBIO_ENABLE               ((uint32)0x80000000u)
    #define debugLEDRed_USBIO_DISABLE              ((uint32)(~debugLEDRed_USBIO_ENABLE))
    #define debugLEDRed_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define debugLEDRed_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define debugLEDRed_USBIO_ENTER_SLEEP          ((uint32)((1u << debugLEDRed_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << debugLEDRed_USBIO_SUSPEND_DEL_SHIFT)))
    #define debugLEDRed_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << debugLEDRed_USBIO_SUSPEND_SHIFT)))
    #define debugLEDRed_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << debugLEDRed_USBIO_SUSPEND_DEL_SHIFT)))
    #define debugLEDRed_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(debugLEDRed__PC)
    /* Port Configuration */
    #define debugLEDRed_PC                 (* (reg32 *) debugLEDRed__PC)
#endif
/* Pin State */
#define debugLEDRed_PS                     (* (reg32 *) debugLEDRed__PS)
/* Data Register */
#define debugLEDRed_DR                     (* (reg32 *) debugLEDRed__DR)
/* Input Buffer Disable Override */
#define debugLEDRed_INP_DIS                (* (reg32 *) debugLEDRed__PC2)

/* Interrupt configuration Registers */
#define debugLEDRed_INTCFG                 (* (reg32 *) debugLEDRed__INTCFG)
#define debugLEDRed_INTSTAT                (* (reg32 *) debugLEDRed__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define debugLEDRed_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(debugLEDRed__SIO)
    #define debugLEDRed_SIO_REG            (* (reg32 *) debugLEDRed__SIO)
#endif /* (debugLEDRed__SIO_CFG) */

/* USBIO registers */
#if !defined(debugLEDRed__PC) && (CY_PSOC4_4200L)
    #define debugLEDRed_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define debugLEDRed_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define debugLEDRed_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define debugLEDRed_DRIVE_MODE_SHIFT       (0x00u)
#define debugLEDRed_DRIVE_MODE_MASK        (0x07u << debugLEDRed_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins debugLEDRed_H */


/* [] END OF FILE */
