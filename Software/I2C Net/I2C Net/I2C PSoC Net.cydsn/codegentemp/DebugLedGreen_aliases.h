/*******************************************************************************
* File Name: DebugLedGreen.h  
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

#if !defined(CY_PINS_DebugLedGreen_ALIASES_H) /* Pins DebugLedGreen_ALIASES_H */
#define CY_PINS_DebugLedGreen_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DebugLedGreen_0			(DebugLedGreen__0__PC)
#define DebugLedGreen_0_PS		(DebugLedGreen__0__PS)
#define DebugLedGreen_0_PC		(DebugLedGreen__0__PC)
#define DebugLedGreen_0_DR		(DebugLedGreen__0__DR)
#define DebugLedGreen_0_SHIFT	(DebugLedGreen__0__SHIFT)
#define DebugLedGreen_0_INTR	((uint16)((uint16)0x0003u << (DebugLedGreen__0__SHIFT*2u)))

#define DebugLedGreen_INTR_ALL	 ((uint16)(DebugLedGreen_0_INTR))


#endif /* End Pins DebugLedGreen_ALIASES_H */


/* [] END OF FILE */
