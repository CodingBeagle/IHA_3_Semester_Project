/*******************************************************************************
* File Name: debugLEDBlue.h  
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

#if !defined(CY_PINS_debugLEDBlue_ALIASES_H) /* Pins debugLEDBlue_ALIASES_H */
#define CY_PINS_debugLEDBlue_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define debugLEDBlue_0			(debugLEDBlue__0__PC)
#define debugLEDBlue_0_PS		(debugLEDBlue__0__PS)
#define debugLEDBlue_0_PC		(debugLEDBlue__0__PC)
#define debugLEDBlue_0_DR		(debugLEDBlue__0__DR)
#define debugLEDBlue_0_SHIFT	(debugLEDBlue__0__SHIFT)
#define debugLEDBlue_0_INTR	((uint16)((uint16)0x0003u << (debugLEDBlue__0__SHIFT*2u)))

#define debugLEDBlue_INTR_ALL	 ((uint16)(debugLEDBlue_0_INTR))


#endif /* End Pins debugLEDBlue_ALIASES_H */


/* [] END OF FILE */
