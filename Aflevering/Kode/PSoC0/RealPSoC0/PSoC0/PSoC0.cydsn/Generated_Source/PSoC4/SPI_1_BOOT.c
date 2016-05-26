/*******************************************************************************
* File Name: SPI_1_BOOT.c
* Version 3.10
*
* Description:
*  This file provides the source code of the bootloader communication APIs
*  for the SCB Component Unconfigured mode.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPI_1_BOOT.h"

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_BTLDR_COMM_ENABLED) && \
                                (SPI_1_SCB_MODE_UNCONFIG_CONST_CFG)

/*******************************************************************************
* Function Name: SPI_1_CyBtldrCommStart
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommStart function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_CyBtldrCommStart(void)
{
    if (SPI_1_SCB_MODE_I2C_RUNTM_CFG)
    {
        SPI_1_I2CCyBtldrCommStart();
    }
    else if (SPI_1_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        SPI_1_EzI2CCyBtldrCommStart();
    }
#if (!SPI_1_CY_SCBIP_V1)
    else if (SPI_1_SCB_MODE_SPI_RUNTM_CFG)
    {
        SPI_1_SpiCyBtldrCommStart();
    }
    else if (SPI_1_SCB_MODE_UART_RUNTM_CFG)
    {
        SPI_1_UartCyBtldrCommStart();
    }
#endif /* (!SPI_1_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
}


/*******************************************************************************
* Function Name: SPI_1_CyBtldrCommStop
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommStop function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_CyBtldrCommStop(void)
{
    if (SPI_1_SCB_MODE_I2C_RUNTM_CFG)
    {
        SPI_1_I2CCyBtldrCommStop();
    }
    else if (SPI_1_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        SPI_1_EzI2CCyBtldrCommStop();
    }
#if (!SPI_1_CY_SCBIP_V1)
    else if (SPI_1_SCB_MODE_SPI_RUNTM_CFG)
    {
        SPI_1_SpiCyBtldrCommStop();
    }
    else if (SPI_1_SCB_MODE_UART_RUNTM_CFG)
    {
        SPI_1_UartCyBtldrCommStop();
    }
#endif /* (!SPI_1_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
}


/*******************************************************************************
* Function Name: SPI_1_CyBtldrCommReset
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommReset function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPI_1_CyBtldrCommReset(void)
{
    if(SPI_1_SCB_MODE_I2C_RUNTM_CFG)
    {
        SPI_1_I2CCyBtldrCommReset();
    }
    else if(SPI_1_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        SPI_1_EzI2CCyBtldrCommReset();
    }
#if (!SPI_1_CY_SCBIP_V1)
    else if(SPI_1_SCB_MODE_SPI_RUNTM_CFG)
    {
        SPI_1_SpiCyBtldrCommReset();
    }
    else if(SPI_1_SCB_MODE_UART_RUNTM_CFG)
    {
        SPI_1_UartCyBtldrCommReset();
    }
#endif /* (!SPI_1_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
}


/*******************************************************************************
* Function Name: SPI_1_CyBtldrCommRead
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommRead function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  pData:    Pointer to storage for the block of data to be read from the
*            bootloader host
*  size:     Number of bytes to be read.
*  count:    Pointer to the variable to write the number of bytes actually
*            read.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus SPI_1_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    if(SPI_1_SCB_MODE_I2C_RUNTM_CFG)
    {
        status = SPI_1_I2CCyBtldrCommRead(pData, size, count, timeOut);
    }
    else if(SPI_1_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        status = SPI_1_EzI2CCyBtldrCommRead(pData, size, count, timeOut);
    }
#if (!SPI_1_CY_SCBIP_V1)
    else if(SPI_1_SCB_MODE_SPI_RUNTM_CFG)
    {
        status = SPI_1_SpiCyBtldrCommRead(pData, size, count, timeOut);
    }
    else if(SPI_1_SCB_MODE_UART_RUNTM_CFG)
    {
        status = SPI_1_UartCyBtldrCommRead(pData, size, count, timeOut);
    }
#endif /* (!SPI_1_CY_SCBIP_V1) */
    else
    {
        status = CYRET_INVALID_STATE; /* Unknown mode: return invalid status */
    }

    return(status);
}


/*******************************************************************************
* Function Name: SPI_1_CyBtldrCommWrite
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommWrite  function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  pData:    Pointer to the block of data to be written to the bootloader host.
*  size:     Number of bytes to be written.
*  count:    Pointer to the variable to write the number of bytes actually
*            written.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus SPI_1_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    if(SPI_1_SCB_MODE_I2C_RUNTM_CFG)
    {
        status = SPI_1_I2CCyBtldrCommWrite(pData, size, count, timeOut);
    }
    else if(SPI_1_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        status = SPI_1_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);
    }
#if (!SPI_1_CY_SCBIP_V1)
    else if(SPI_1_SCB_MODE_SPI_RUNTM_CFG)
    {
        status = SPI_1_SpiCyBtldrCommWrite(pData, size, count, timeOut);
    }
    else if(SPI_1_SCB_MODE_UART_RUNTM_CFG)
    {
        status = SPI_1_UartCyBtldrCommWrite(pData, size, count, timeOut);
    }
#endif /* (!SPI_1_CY_SCBIP_V1) */
    else
    {
        status = CYRET_INVALID_STATE; /* Unknown mode: return invalid status */
    }

    return(status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_1_BTLDR_COMM_MODE_ENABLED) */


/* [] END OF FILE */
