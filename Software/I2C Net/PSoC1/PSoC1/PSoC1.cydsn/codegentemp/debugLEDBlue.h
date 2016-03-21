/*******************************************************************************
* File Name: debugLEDBlue.h  
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

#if !defined(CY_PINS_debugLEDBlue_H) /* Pins debugLEDBlue_H */
#define CY_PINS_debugLEDBlue_H

#include "cytypes.h"
#include "cyfitter.h"
#include "debugLEDBlue_aliases.h"


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
} debugLEDBlue_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   debugLEDBlue_Read(void);
void    debugLEDBlue_Write(uint8 value);
uint8   debugLEDBlue_ReadDataReg(void);
#if defined(debugLEDBlue__PC) || (CY_PSOC4_4200L) 
    void    debugLEDBlue_SetDriveMode(uint8 mode);
#endif
void    debugLEDBlue_SetInterruptMode(uint16 position, uint16 mode);
uint8   debugLEDBlue_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void debugLEDBlue_Sleep(void); 
void debugLEDBlue_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(debugLEDBlue__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define debugLEDBlue_DRIVE_MODE_BITS        (3)
    #define debugLEDBlue_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - debugLEDBlue_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the debugLEDBlue_SetDriveMode() function.
         *  @{
         */
        #define debugLEDBlue_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define debugLEDBlue_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define debugLEDBlue_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define debugLEDBlue_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define debugLEDBlue_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define debugLEDBlue_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define debugLEDBlue_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define debugLEDBlue_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define debugLEDBlue_MASK               debugLEDBlue__MASK
#define debugLEDBlue_SHIFT              debugLEDBlue__SHIFT
#define debugLEDBlue_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in debugLEDBlue_SetInterruptMode() function.
     *  @{
     */
        #define debugLEDBlue_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define debugLEDBlue_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define debugLEDBlue_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define debugLEDBlue_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(debugLEDBlue__SIO)
    #define debugLEDBlue_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(debugLEDBlue__PC) && (CY_PSOC4_4200L)
    #define debugLEDBlue_USBIO_ENABLE               ((uint32)0x80000000u)
    #define debugLEDBlue_USBIO_DISABLE              ((uint32)(~debugLEDBlue_USBIO_ENABLE))
    #define debugLEDBlue_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define debugLEDBlue_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define debugLEDBlue_USBIO_ENTER_SLEEP          ((uint32)((1u << debugLEDBlue_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << debugLEDBlue_USBIO_SUSPEND_DEL_SHIFT)))
    #define debugLEDBlue_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << debugLEDBlue_USBIO_SUSPEND_SHIFT)))
    #define debugLEDBlue_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << debugLEDBlue_USBIO_SUSPEND_DEL_SHIFT)))
    #define debugLEDBlue_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(debugLEDBlue__PC)
    /* Port Configuration */
    #define debugLEDBlue_PC                 (* (reg32 *) debugLEDBlue__PC)
#endif
/* Pin State */
#define debugLEDBlue_PS                     (* (reg32 *) debugLEDBlue__PS)
/* Data Register */
#define debugLEDBlue_DR                     (* (reg32 *) debugLEDBlue__DR)
/* Input Buffer Disable Override */
#define debugLEDBlue_INP_DIS                (* (reg32 *) debugLEDBlue__PC2)

/* Interrupt configuration Registers */
#define debugLEDBlue_INTCFG                 (* (reg32 *) debugLEDBlue__INTCFG)
#define debugLEDBlue_INTSTAT                (* (reg32 *) debugLEDBlue__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define debugLEDBlue_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(debugLEDBlue__SIO)
    #define debugLEDBlue_SIO_REG            (* (reg32 *) debugLEDBlue__SIO)
#endif /* (debugLEDBlue__SIO_CFG) */

/* USBIO registers */
#if !defined(debugLEDBlue__PC) && (CY_PSOC4_4200L)
    #define debugLEDBlue_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define debugLEDBlue_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define debugLEDBlue_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define debugLEDBlue_DRIVE_MODE_SHIFT       (0x00u)
#define debugLEDBlue_DRIVE_MODE_MASK        (0x07u << debugLEDBlue_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins debugLEDBlue_H */


/* [] END OF FILE */
