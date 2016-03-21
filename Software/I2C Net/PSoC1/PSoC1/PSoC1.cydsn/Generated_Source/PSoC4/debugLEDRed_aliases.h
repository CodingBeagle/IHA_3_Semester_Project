/*******************************************************************************
* File Name: debugLEDRed.h  
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

#if !defined(CY_PINS_debugLEDRed_ALIASES_H) /* Pins debugLEDRed_ALIASES_H */
#define CY_PINS_debugLEDRed_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define debugLEDRed_0			(debugLEDRed__0__PC)
#define debugLEDRed_0_PS		(debugLEDRed__0__PS)
#define debugLEDRed_0_PC		(debugLEDRed__0__PC)
#define debugLEDRed_0_DR		(debugLEDRed__0__DR)
#define debugLEDRed_0_SHIFT	(debugLEDRed__0__SHIFT)
#define debugLEDRed_0_INTR	((uint16)((uint16)0x0003u << (debugLEDRed__0__SHIFT*2u)))

#define debugLEDRed_INTR_ALL	 ((uint16)(debugLEDRed_0_INTR))


#endif /* End Pins debugLEDRed_ALIASES_H */


/* [] END OF FILE */
