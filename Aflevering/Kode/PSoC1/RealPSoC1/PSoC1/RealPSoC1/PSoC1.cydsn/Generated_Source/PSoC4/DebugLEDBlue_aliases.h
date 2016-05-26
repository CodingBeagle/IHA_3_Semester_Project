/*******************************************************************************
* File Name: DebugLEDBlue.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DebugLEDBlue_ALIASES_H) /* Pins DebugLEDBlue_ALIASES_H */
#define CY_PINS_DebugLEDBlue_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DebugLEDBlue_0			(DebugLEDBlue__0__PC)
#define DebugLEDBlue_0_PS		(DebugLEDBlue__0__PS)
#define DebugLEDBlue_0_PC		(DebugLEDBlue__0__PC)
#define DebugLEDBlue_0_DR		(DebugLEDBlue__0__DR)
#define DebugLEDBlue_0_SHIFT	(DebugLEDBlue__0__SHIFT)
#define DebugLEDBlue_0_INTR	((uint16)((uint16)0x0003u << (DebugLEDBlue__0__SHIFT*2u)))

#define DebugLEDBlue_INTR_ALL	 ((uint16)(DebugLEDBlue_0_INTR))


#endif /* End Pins DebugLEDBlue_ALIASES_H */


/* [] END OF FILE */
