/*******************************************************************************
* File Name: DebugLEDRed.h  
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

#if !defined(CY_PINS_DebugLEDRed_ALIASES_H) /* Pins DebugLEDRed_ALIASES_H */
#define CY_PINS_DebugLEDRed_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DebugLEDRed_0			(DebugLEDRed__0__PC)
#define DebugLEDRed_0_PS		(DebugLEDRed__0__PS)
#define DebugLEDRed_0_PC		(DebugLEDRed__0__PC)
#define DebugLEDRed_0_DR		(DebugLEDRed__0__DR)
#define DebugLEDRed_0_SHIFT	(DebugLEDRed__0__SHIFT)
#define DebugLEDRed_0_INTR	((uint16)((uint16)0x0003u << (DebugLEDRed__0__SHIFT*2u)))

#define DebugLEDRed_INTR_ALL	 ((uint16)(DebugLEDRed_0_INTR))


#endif /* End Pins DebugLEDRed_ALIASES_H */


/* [] END OF FILE */
