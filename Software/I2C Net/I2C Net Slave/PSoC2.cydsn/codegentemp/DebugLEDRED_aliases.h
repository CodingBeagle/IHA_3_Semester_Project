/*******************************************************************************
* File Name: DebugLEDRED.h  
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

#if !defined(CY_PINS_DebugLEDRED_ALIASES_H) /* Pins DebugLEDRED_ALIASES_H */
#define CY_PINS_DebugLEDRED_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DebugLEDRED_0			(DebugLEDRED__0__PC)
#define DebugLEDRED_0_PS		(DebugLEDRED__0__PS)
#define DebugLEDRED_0_PC		(DebugLEDRED__0__PC)
#define DebugLEDRED_0_DR		(DebugLEDRED__0__DR)
#define DebugLEDRED_0_SHIFT	(DebugLEDRED__0__SHIFT)
#define DebugLEDRED_0_INTR	((uint16)((uint16)0x0003u << (DebugLEDRED__0__SHIFT*2u)))

#define DebugLEDRED_INTR_ALL	 ((uint16)(DebugLEDRED_0_INTR))


#endif /* End Pins DebugLEDRED_ALIASES_H */


/* [] END OF FILE */
