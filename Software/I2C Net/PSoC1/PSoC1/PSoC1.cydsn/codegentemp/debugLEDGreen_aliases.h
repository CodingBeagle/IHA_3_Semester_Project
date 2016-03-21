/*******************************************************************************
* File Name: debugLEDGreen.h  
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

#if !defined(CY_PINS_debugLEDGreen_ALIASES_H) /* Pins debugLEDGreen_ALIASES_H */
#define CY_PINS_debugLEDGreen_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define debugLEDGreen_0			(debugLEDGreen__0__PC)
#define debugLEDGreen_0_PS		(debugLEDGreen__0__PS)
#define debugLEDGreen_0_PC		(debugLEDGreen__0__PC)
#define debugLEDGreen_0_DR		(debugLEDGreen__0__DR)
#define debugLEDGreen_0_SHIFT	(debugLEDGreen__0__SHIFT)
#define debugLEDGreen_0_INTR	((uint16)((uint16)0x0003u << (debugLEDGreen__0__SHIFT*2u)))

#define debugLEDGreen_INTR_ALL	 ((uint16)(debugLEDGreen_0_INTR))


#endif /* End Pins debugLEDGreen_ALIASES_H */


/* [] END OF FILE */
