/*******************************************************************************
* File Name: DebugLEDGreen.h  
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

#if !defined(CY_PINS_DebugLEDGreen_ALIASES_H) /* Pins DebugLEDGreen_ALIASES_H */
#define CY_PINS_DebugLEDGreen_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DebugLEDGreen_0			(DebugLEDGreen__0__PC)
#define DebugLEDGreen_0_PS		(DebugLEDGreen__0__PS)
#define DebugLEDGreen_0_PC		(DebugLEDGreen__0__PC)
#define DebugLEDGreen_0_DR		(DebugLEDGreen__0__DR)
#define DebugLEDGreen_0_SHIFT	(DebugLEDGreen__0__SHIFT)
#define DebugLEDGreen_0_INTR	((uint16)((uint16)0x0003u << (DebugLEDGreen__0__SHIFT*2u)))

#define DebugLEDGreen_INTR_ALL	 ((uint16)(DebugLEDGreen_0_INTR))


#endif /* End Pins DebugLEDGreen_ALIASES_H */


/* [] END OF FILE */
