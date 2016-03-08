/*******************************************************************************
* File Name: DebugLEDGREEN.h  
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

#if !defined(CY_PINS_DebugLEDGREEN_H) /* Pins DebugLEDGREEN_H */
#define CY_PINS_DebugLEDGREEN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "DebugLEDGREEN_aliases.h"


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
} DebugLEDGREEN_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   DebugLEDGREEN_Read(void);
void    DebugLEDGREEN_Write(uint8 value);
uint8   DebugLEDGREEN_ReadDataReg(void);
#if defined(DebugLEDGREEN__PC) || (CY_PSOC4_4200L) 
    void    DebugLEDGREEN_SetDriveMode(uint8 mode);
#endif
void    DebugLEDGREEN_SetInterruptMode(uint16 position, uint16 mode);
uint8   DebugLEDGREEN_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void DebugLEDGREEN_Sleep(void); 
void DebugLEDGREEN_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(DebugLEDGREEN__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define DebugLEDGREEN_DRIVE_MODE_BITS        (3)
    #define DebugLEDGREEN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - DebugLEDGREEN_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the DebugLEDGREEN_SetDriveMode() function.
         *  @{
         */
        #define DebugLEDGREEN_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define DebugLEDGREEN_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define DebugLEDGREEN_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define DebugLEDGREEN_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define DebugLEDGREEN_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define DebugLEDGREEN_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define DebugLEDGREEN_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define DebugLEDGREEN_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define DebugLEDGREEN_MASK               DebugLEDGREEN__MASK
#define DebugLEDGREEN_SHIFT              DebugLEDGREEN__SHIFT
#define DebugLEDGREEN_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DebugLEDGREEN_SetInterruptMode() function.
     *  @{
     */
        #define DebugLEDGREEN_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define DebugLEDGREEN_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define DebugLEDGREEN_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define DebugLEDGREEN_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(DebugLEDGREEN__SIO)
    #define DebugLEDGREEN_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(DebugLEDGREEN__PC) && (CY_PSOC4_4200L)
    #define DebugLEDGREEN_USBIO_ENABLE               ((uint32)0x80000000u)
    #define DebugLEDGREEN_USBIO_DISABLE              ((uint32)(~DebugLEDGREEN_USBIO_ENABLE))
    #define DebugLEDGREEN_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define DebugLEDGREEN_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define DebugLEDGREEN_USBIO_ENTER_SLEEP          ((uint32)((1u << DebugLEDGREEN_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << DebugLEDGREEN_USBIO_SUSPEND_DEL_SHIFT)))
    #define DebugLEDGREEN_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << DebugLEDGREEN_USBIO_SUSPEND_SHIFT)))
    #define DebugLEDGREEN_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << DebugLEDGREEN_USBIO_SUSPEND_DEL_SHIFT)))
    #define DebugLEDGREEN_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(DebugLEDGREEN__PC)
    /* Port Configuration */
    #define DebugLEDGREEN_PC                 (* (reg32 *) DebugLEDGREEN__PC)
#endif
/* Pin State */
#define DebugLEDGREEN_PS                     (* (reg32 *) DebugLEDGREEN__PS)
/* Data Register */
#define DebugLEDGREEN_DR                     (* (reg32 *) DebugLEDGREEN__DR)
/* Input Buffer Disable Override */
#define DebugLEDGREEN_INP_DIS                (* (reg32 *) DebugLEDGREEN__PC2)

/* Interrupt configuration Registers */
#define DebugLEDGREEN_INTCFG                 (* (reg32 *) DebugLEDGREEN__INTCFG)
#define DebugLEDGREEN_INTSTAT                (* (reg32 *) DebugLEDGREEN__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define DebugLEDGREEN_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(DebugLEDGREEN__SIO)
    #define DebugLEDGREEN_SIO_REG            (* (reg32 *) DebugLEDGREEN__SIO)
#endif /* (DebugLEDGREEN__SIO_CFG) */

/* USBIO registers */
#if !defined(DebugLEDGREEN__PC) && (CY_PSOC4_4200L)
    #define DebugLEDGREEN_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define DebugLEDGREEN_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define DebugLEDGREEN_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define DebugLEDGREEN_DRIVE_MODE_SHIFT       (0x00u)
#define DebugLEDGREEN_DRIVE_MODE_MASK        (0x07u << DebugLEDGREEN_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins DebugLEDGREEN_H */


/* [] END OF FILE */
