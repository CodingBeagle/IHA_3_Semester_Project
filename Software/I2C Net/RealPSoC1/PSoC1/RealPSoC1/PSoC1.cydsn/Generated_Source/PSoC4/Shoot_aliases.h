/*******************************************************************************
* File Name: Shoot.h  
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

#if !defined(CY_PINS_Shoot_ALIASES_H) /* Pins Shoot_ALIASES_H */
#define CY_PINS_Shoot_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Shoot_0			(Shoot__0__PC)
#define Shoot_0_PS		(Shoot__0__PS)
#define Shoot_0_PC		(Shoot__0__PC)
#define Shoot_0_DR		(Shoot__0__DR)
#define Shoot_0_SHIFT	(Shoot__0__SHIFT)
#define Shoot_0_INTR	((uint16)((uint16)0x0003u << (Shoot__0__SHIFT*2u)))

#define Shoot_INTR_ALL	 ((uint16)(Shoot_0_INTR))


#endif /* End Pins Shoot_ALIASES_H */


/* [] END OF FILE */
