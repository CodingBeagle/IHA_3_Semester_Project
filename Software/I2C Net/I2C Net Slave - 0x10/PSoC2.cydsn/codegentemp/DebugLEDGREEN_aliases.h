/*******************************************************************************
* File Name: DebugLEDGREEN.h  
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

#if !defined(CY_PINS_DebugLEDGREEN_ALIASES_H) /* Pins DebugLEDGREEN_ALIASES_H */
#define CY_PINS_DebugLEDGREEN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DebugLEDGREEN_0			(DebugLEDGREEN__0__PC)
#define DebugLEDGREEN_0_PS		(DebugLEDGREEN__0__PS)
#define DebugLEDGREEN_0_PC		(DebugLEDGREEN__0__PC)
#define DebugLEDGREEN_0_DR		(DebugLEDGREEN__0__DR)
#define DebugLEDGREEN_0_SHIFT	(DebugLEDGREEN__0__SHIFT)
#define DebugLEDGREEN_0_INTR	((uint16)((uint16)0x0003u << (DebugLEDGREEN__0__SHIFT*2u)))

#define DebugLEDGREEN_INTR_ALL	 ((uint16)(DebugLEDGREEN_0_INTR))


#endif /* End Pins DebugLEDGREEN_ALIASES_H */


/* [] END OF FILE */
