#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice_trm.h"

/* I2C_1_SCB */
#define I2C_1_SCB__BIST_CONTROL CYREG_SCB0_BIST_CONTROL
#define I2C_1_SCB__BIST_DATA CYREG_SCB0_BIST_DATA
#define I2C_1_SCB__CTRL CYREG_SCB0_CTRL
#define I2C_1_SCB__EZ_DATA00 CYREG_SCB0_EZ_DATA00
#define I2C_1_SCB__EZ_DATA01 CYREG_SCB0_EZ_DATA01
#define I2C_1_SCB__EZ_DATA02 CYREG_SCB0_EZ_DATA02
#define I2C_1_SCB__EZ_DATA03 CYREG_SCB0_EZ_DATA03
#define I2C_1_SCB__EZ_DATA04 CYREG_SCB0_EZ_DATA04
#define I2C_1_SCB__EZ_DATA05 CYREG_SCB0_EZ_DATA05
#define I2C_1_SCB__EZ_DATA06 CYREG_SCB0_EZ_DATA06
#define I2C_1_SCB__EZ_DATA07 CYREG_SCB0_EZ_DATA07
#define I2C_1_SCB__EZ_DATA08 CYREG_SCB0_EZ_DATA08
#define I2C_1_SCB__EZ_DATA09 CYREG_SCB0_EZ_DATA09
#define I2C_1_SCB__EZ_DATA10 CYREG_SCB0_EZ_DATA10
#define I2C_1_SCB__EZ_DATA11 CYREG_SCB0_EZ_DATA11
#define I2C_1_SCB__EZ_DATA12 CYREG_SCB0_EZ_DATA12
#define I2C_1_SCB__EZ_DATA13 CYREG_SCB0_EZ_DATA13
#define I2C_1_SCB__EZ_DATA14 CYREG_SCB0_EZ_DATA14
#define I2C_1_SCB__EZ_DATA15 CYREG_SCB0_EZ_DATA15
#define I2C_1_SCB__EZ_DATA16 CYREG_SCB0_EZ_DATA16
#define I2C_1_SCB__EZ_DATA17 CYREG_SCB0_EZ_DATA17
#define I2C_1_SCB__EZ_DATA18 CYREG_SCB0_EZ_DATA18
#define I2C_1_SCB__EZ_DATA19 CYREG_SCB0_EZ_DATA19
#define I2C_1_SCB__EZ_DATA20 CYREG_SCB0_EZ_DATA20
#define I2C_1_SCB__EZ_DATA21 CYREG_SCB0_EZ_DATA21
#define I2C_1_SCB__EZ_DATA22 CYREG_SCB0_EZ_DATA22
#define I2C_1_SCB__EZ_DATA23 CYREG_SCB0_EZ_DATA23
#define I2C_1_SCB__EZ_DATA24 CYREG_SCB0_EZ_DATA24
#define I2C_1_SCB__EZ_DATA25 CYREG_SCB0_EZ_DATA25
#define I2C_1_SCB__EZ_DATA26 CYREG_SCB0_EZ_DATA26
#define I2C_1_SCB__EZ_DATA27 CYREG_SCB0_EZ_DATA27
#define I2C_1_SCB__EZ_DATA28 CYREG_SCB0_EZ_DATA28
#define I2C_1_SCB__EZ_DATA29 CYREG_SCB0_EZ_DATA29
#define I2C_1_SCB__EZ_DATA30 CYREG_SCB0_EZ_DATA30
#define I2C_1_SCB__EZ_DATA31 CYREG_SCB0_EZ_DATA31
#define I2C_1_SCB__I2C_CFG CYREG_SCB0_I2C_CFG
#define I2C_1_SCB__I2C_CTRL CYREG_SCB0_I2C_CTRL
#define I2C_1_SCB__I2C_M_CMD CYREG_SCB0_I2C_M_CMD
#define I2C_1_SCB__I2C_S_CMD CYREG_SCB0_I2C_S_CMD
#define I2C_1_SCB__I2C_STATUS CYREG_SCB0_I2C_STATUS
#define I2C_1_SCB__INTR_CAUSE CYREG_SCB0_INTR_CAUSE
#define I2C_1_SCB__INTR_I2C_EC CYREG_SCB0_INTR_I2C_EC
#define I2C_1_SCB__INTR_I2C_EC_MASK CYREG_SCB0_INTR_I2C_EC_MASK
#define I2C_1_SCB__INTR_I2C_EC_MASKED CYREG_SCB0_INTR_I2C_EC_MASKED
#define I2C_1_SCB__INTR_M CYREG_SCB0_INTR_M
#define I2C_1_SCB__INTR_M_MASK CYREG_SCB0_INTR_M_MASK
#define I2C_1_SCB__INTR_M_MASKED CYREG_SCB0_INTR_M_MASKED
#define I2C_1_SCB__INTR_M_SET CYREG_SCB0_INTR_M_SET
#define I2C_1_SCB__INTR_RX CYREG_SCB0_INTR_RX
#define I2C_1_SCB__INTR_RX_MASK CYREG_SCB0_INTR_RX_MASK
#define I2C_1_SCB__INTR_RX_MASKED CYREG_SCB0_INTR_RX_MASKED
#define I2C_1_SCB__INTR_RX_SET CYREG_SCB0_INTR_RX_SET
#define I2C_1_SCB__INTR_S CYREG_SCB0_INTR_S
#define I2C_1_SCB__INTR_S_MASK CYREG_SCB0_INTR_S_MASK
#define I2C_1_SCB__INTR_S_MASKED CYREG_SCB0_INTR_S_MASKED
#define I2C_1_SCB__INTR_S_SET CYREG_SCB0_INTR_S_SET
#define I2C_1_SCB__INTR_SPI_EC CYREG_SCB0_INTR_SPI_EC
#define I2C_1_SCB__INTR_SPI_EC_MASK CYREG_SCB0_INTR_SPI_EC_MASK
#define I2C_1_SCB__INTR_SPI_EC_MASKED CYREG_SCB0_INTR_SPI_EC_MASKED
#define I2C_1_SCB__INTR_TX CYREG_SCB0_INTR_TX
#define I2C_1_SCB__INTR_TX_MASK CYREG_SCB0_INTR_TX_MASK
#define I2C_1_SCB__INTR_TX_MASKED CYREG_SCB0_INTR_TX_MASKED
#define I2C_1_SCB__INTR_TX_SET CYREG_SCB0_INTR_TX_SET
#define I2C_1_SCB__RX_CTRL CYREG_SCB0_RX_CTRL
#define I2C_1_SCB__RX_FIFO_CTRL CYREG_SCB0_RX_FIFO_CTRL
#define I2C_1_SCB__RX_FIFO_RD CYREG_SCB0_RX_FIFO_RD
#define I2C_1_SCB__RX_FIFO_RD_SILENT CYREG_SCB0_RX_FIFO_RD_SILENT
#define I2C_1_SCB__RX_FIFO_STATUS CYREG_SCB0_RX_FIFO_STATUS
#define I2C_1_SCB__RX_MATCH CYREG_SCB0_RX_MATCH
#define I2C_1_SCB__SPI_CTRL CYREG_SCB0_SPI_CTRL
#define I2C_1_SCB__SPI_STATUS CYREG_SCB0_SPI_STATUS
#define I2C_1_SCB__SS0_POSISTION 0u
#define I2C_1_SCB__SS1_POSISTION 1u
#define I2C_1_SCB__SS2_POSISTION 2u
#define I2C_1_SCB__SS3_POSISTION 3u
#define I2C_1_SCB__STATUS CYREG_SCB0_STATUS
#define I2C_1_SCB__TX_CTRL CYREG_SCB0_TX_CTRL
#define I2C_1_SCB__TX_FIFO_CTRL CYREG_SCB0_TX_FIFO_CTRL
#define I2C_1_SCB__TX_FIFO_STATUS CYREG_SCB0_TX_FIFO_STATUS
#define I2C_1_SCB__TX_FIFO_WR CYREG_SCB0_TX_FIFO_WR
#define I2C_1_SCB__UART_CTRL CYREG_SCB0_UART_CTRL
#define I2C_1_SCB__UART_RX_CTRL CYREG_SCB0_UART_RX_CTRL
#define I2C_1_SCB__UART_RX_STATUS CYREG_SCB0_UART_RX_STATUS
#define I2C_1_SCB__UART_TX_CTRL CYREG_SCB0_UART_TX_CTRL

/* I2C_1_SCB_IRQ */
#define I2C_1_SCB_IRQ__INTC_CLR_EN_REG CYREG_CM0_ICER
#define I2C_1_SCB_IRQ__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define I2C_1_SCB_IRQ__INTC_MASK 0x400u
#define I2C_1_SCB_IRQ__INTC_NUMBER 10u
#define I2C_1_SCB_IRQ__INTC_PRIOR_MASK 0xC00000u
#define I2C_1_SCB_IRQ__INTC_PRIOR_NUM 3u
#define I2C_1_SCB_IRQ__INTC_PRIOR_REG CYREG_CM0_IPR2
#define I2C_1_SCB_IRQ__INTC_SET_EN_REG CYREG_CM0_ISER
#define I2C_1_SCB_IRQ__INTC_SET_PD_REG CYREG_CM0_ISPR

/* I2C_1_SCBCLK */
#define I2C_1_SCBCLK__DIVIDER_MASK 0x0000FFFFu
#define I2C_1_SCBCLK__ENABLE CYREG_CLK_DIVIDER_B00
#define I2C_1_SCBCLK__ENABLE_MASK 0x80000000u
#define I2C_1_SCBCLK__MASK 0x80000000u
#define I2C_1_SCBCLK__REGISTER CYREG_CLK_DIVIDER_B00

/* I2C_1_scl */
#define I2C_1_scl__0__DM__MASK 0x07u
#define I2C_1_scl__0__DM__SHIFT 0
#define I2C_1_scl__0__DR CYREG_PRT4_DR
#define I2C_1_scl__0__HSIOM CYREG_HSIOM_PORT_SEL4
#define I2C_1_scl__0__HSIOM_MASK 0x0000000Fu
#define I2C_1_scl__0__HSIOM_SHIFT 0u
#define I2C_1_scl__0__INTCFG CYREG_PRT4_INTCFG
#define I2C_1_scl__0__INTSTAT CYREG_PRT4_INTSTAT
#define I2C_1_scl__0__MASK 0x01u
#define I2C_1_scl__0__PC CYREG_PRT4_PC
#define I2C_1_scl__0__PC2 CYREG_PRT4_PC2
#define I2C_1_scl__0__PORT 4u
#define I2C_1_scl__0__PS CYREG_PRT4_PS
#define I2C_1_scl__0__SHIFT 0
#define I2C_1_scl__DR CYREG_PRT4_DR
#define I2C_1_scl__INTCFG CYREG_PRT4_INTCFG
#define I2C_1_scl__INTSTAT CYREG_PRT4_INTSTAT
#define I2C_1_scl__MASK 0x01u
#define I2C_1_scl__PC CYREG_PRT4_PC
#define I2C_1_scl__PC2 CYREG_PRT4_PC2
#define I2C_1_scl__PORT 4u
#define I2C_1_scl__PS CYREG_PRT4_PS
#define I2C_1_scl__SHIFT 0

/* I2C_1_sda */
#define I2C_1_sda__0__DM__MASK 0x38u
#define I2C_1_sda__0__DM__SHIFT 3
#define I2C_1_sda__0__DR CYREG_PRT4_DR
#define I2C_1_sda__0__HSIOM CYREG_HSIOM_PORT_SEL4
#define I2C_1_sda__0__HSIOM_MASK 0x000000F0u
#define I2C_1_sda__0__HSIOM_SHIFT 4u
#define I2C_1_sda__0__INTCFG CYREG_PRT4_INTCFG
#define I2C_1_sda__0__INTSTAT CYREG_PRT4_INTSTAT
#define I2C_1_sda__0__MASK 0x02u
#define I2C_1_sda__0__PC CYREG_PRT4_PC
#define I2C_1_sda__0__PC2 CYREG_PRT4_PC2
#define I2C_1_sda__0__PORT 4u
#define I2C_1_sda__0__PS CYREG_PRT4_PS
#define I2C_1_sda__0__SHIFT 1
#define I2C_1_sda__DR CYREG_PRT4_DR
#define I2C_1_sda__INTCFG CYREG_PRT4_INTCFG
#define I2C_1_sda__INTSTAT CYREG_PRT4_INTSTAT
#define I2C_1_sda__MASK 0x02u
#define I2C_1_sda__PC CYREG_PRT4_PC
#define I2C_1_sda__PC2 CYREG_PRT4_PC2
#define I2C_1_sda__PORT 4u
#define I2C_1_sda__PS CYREG_PRT4_PS
#define I2C_1_sda__SHIFT 1

/* SPI_1_miso_s */
#define SPI_1_miso_s__0__DM__MASK 0x38u
#define SPI_1_miso_s__0__DM__SHIFT 3
#define SPI_1_miso_s__0__DR CYREG_PRT3_DR
#define SPI_1_miso_s__0__HSIOM CYREG_HSIOM_PORT_SEL3
#define SPI_1_miso_s__0__HSIOM_MASK 0x000000F0u
#define SPI_1_miso_s__0__HSIOM_SHIFT 4u
#define SPI_1_miso_s__0__INTCFG CYREG_PRT3_INTCFG
#define SPI_1_miso_s__0__INTSTAT CYREG_PRT3_INTSTAT
#define SPI_1_miso_s__0__MASK 0x02u
#define SPI_1_miso_s__0__OUT_SEL CYREG_UDB_PA3_CFG10
#define SPI_1_miso_s__0__OUT_SEL_SHIFT 2u
#define SPI_1_miso_s__0__OUT_SEL_VAL -1u
#define SPI_1_miso_s__0__PA__CFG0 CYREG_UDB_PA3_CFG0
#define SPI_1_miso_s__0__PA__CFG1 CYREG_UDB_PA3_CFG1
#define SPI_1_miso_s__0__PA__CFG10 CYREG_UDB_PA3_CFG10
#define SPI_1_miso_s__0__PA__CFG11 CYREG_UDB_PA3_CFG11
#define SPI_1_miso_s__0__PA__CFG12 CYREG_UDB_PA3_CFG12
#define SPI_1_miso_s__0__PA__CFG13 CYREG_UDB_PA3_CFG13
#define SPI_1_miso_s__0__PA__CFG14 CYREG_UDB_PA3_CFG14
#define SPI_1_miso_s__0__PA__CFG2 CYREG_UDB_PA3_CFG2
#define SPI_1_miso_s__0__PA__CFG3 CYREG_UDB_PA3_CFG3
#define SPI_1_miso_s__0__PA__CFG4 CYREG_UDB_PA3_CFG4
#define SPI_1_miso_s__0__PA__CFG5 CYREG_UDB_PA3_CFG5
#define SPI_1_miso_s__0__PA__CFG6 CYREG_UDB_PA3_CFG6
#define SPI_1_miso_s__0__PA__CFG7 CYREG_UDB_PA3_CFG7
#define SPI_1_miso_s__0__PA__CFG8 CYREG_UDB_PA3_CFG8
#define SPI_1_miso_s__0__PA__CFG9 CYREG_UDB_PA3_CFG9
#define SPI_1_miso_s__0__PC CYREG_PRT3_PC
#define SPI_1_miso_s__0__PC2 CYREG_PRT3_PC2
#define SPI_1_miso_s__0__PORT 3u
#define SPI_1_miso_s__0__PS CYREG_PRT3_PS
#define SPI_1_miso_s__0__SHIFT 1
#define SPI_1_miso_s__DR CYREG_PRT3_DR
#define SPI_1_miso_s__INTCFG CYREG_PRT3_INTCFG
#define SPI_1_miso_s__INTSTAT CYREG_PRT3_INTSTAT
#define SPI_1_miso_s__MASK 0x02u
#define SPI_1_miso_s__PA__CFG0 CYREG_UDB_PA3_CFG0
#define SPI_1_miso_s__PA__CFG1 CYREG_UDB_PA3_CFG1
#define SPI_1_miso_s__PA__CFG10 CYREG_UDB_PA3_CFG10
#define SPI_1_miso_s__PA__CFG11 CYREG_UDB_PA3_CFG11
#define SPI_1_miso_s__PA__CFG12 CYREG_UDB_PA3_CFG12
#define SPI_1_miso_s__PA__CFG13 CYREG_UDB_PA3_CFG13
#define SPI_1_miso_s__PA__CFG14 CYREG_UDB_PA3_CFG14
#define SPI_1_miso_s__PA__CFG2 CYREG_UDB_PA3_CFG2
#define SPI_1_miso_s__PA__CFG3 CYREG_UDB_PA3_CFG3
#define SPI_1_miso_s__PA__CFG4 CYREG_UDB_PA3_CFG4
#define SPI_1_miso_s__PA__CFG5 CYREG_UDB_PA3_CFG5
#define SPI_1_miso_s__PA__CFG6 CYREG_UDB_PA3_CFG6
#define SPI_1_miso_s__PA__CFG7 CYREG_UDB_PA3_CFG7
#define SPI_1_miso_s__PA__CFG8 CYREG_UDB_PA3_CFG8
#define SPI_1_miso_s__PA__CFG9 CYREG_UDB_PA3_CFG9
#define SPI_1_miso_s__PC CYREG_PRT3_PC
#define SPI_1_miso_s__PC2 CYREG_PRT3_PC2
#define SPI_1_miso_s__PORT 3u
#define SPI_1_miso_s__PS CYREG_PRT3_PS
#define SPI_1_miso_s__SHIFT 1

/* SPI_1_mosi_s */
#define SPI_1_mosi_s__0__DM__MASK 0x07u
#define SPI_1_mosi_s__0__DM__SHIFT 0
#define SPI_1_mosi_s__0__DR CYREG_PRT3_DR
#define SPI_1_mosi_s__0__HSIOM CYREG_HSIOM_PORT_SEL3
#define SPI_1_mosi_s__0__HSIOM_MASK 0x0000000Fu
#define SPI_1_mosi_s__0__HSIOM_SHIFT 0u
#define SPI_1_mosi_s__0__INTCFG CYREG_PRT3_INTCFG
#define SPI_1_mosi_s__0__INTSTAT CYREG_PRT3_INTSTAT
#define SPI_1_mosi_s__0__MASK 0x01u
#define SPI_1_mosi_s__0__PA__CFG0 CYREG_UDB_PA3_CFG0
#define SPI_1_mosi_s__0__PA__CFG1 CYREG_UDB_PA3_CFG1
#define SPI_1_mosi_s__0__PA__CFG10 CYREG_UDB_PA3_CFG10
#define SPI_1_mosi_s__0__PA__CFG11 CYREG_UDB_PA3_CFG11
#define SPI_1_mosi_s__0__PA__CFG12 CYREG_UDB_PA3_CFG12
#define SPI_1_mosi_s__0__PA__CFG13 CYREG_UDB_PA3_CFG13
#define SPI_1_mosi_s__0__PA__CFG14 CYREG_UDB_PA3_CFG14
#define SPI_1_mosi_s__0__PA__CFG2 CYREG_UDB_PA3_CFG2
#define SPI_1_mosi_s__0__PA__CFG3 CYREG_UDB_PA3_CFG3
#define SPI_1_mosi_s__0__PA__CFG4 CYREG_UDB_PA3_CFG4
#define SPI_1_mosi_s__0__PA__CFG5 CYREG_UDB_PA3_CFG5
#define SPI_1_mosi_s__0__PA__CFG6 CYREG_UDB_PA3_CFG6
#define SPI_1_mosi_s__0__PA__CFG7 CYREG_UDB_PA3_CFG7
#define SPI_1_mosi_s__0__PA__CFG8 CYREG_UDB_PA3_CFG8
#define SPI_1_mosi_s__0__PA__CFG9 CYREG_UDB_PA3_CFG9
#define SPI_1_mosi_s__0__PC CYREG_PRT3_PC
#define SPI_1_mosi_s__0__PC2 CYREG_PRT3_PC2
#define SPI_1_mosi_s__0__PORT 3u
#define SPI_1_mosi_s__0__PS CYREG_PRT3_PS
#define SPI_1_mosi_s__0__SHIFT 0
#define SPI_1_mosi_s__DR CYREG_PRT3_DR
#define SPI_1_mosi_s__INTCFG CYREG_PRT3_INTCFG
#define SPI_1_mosi_s__INTSTAT CYREG_PRT3_INTSTAT
#define SPI_1_mosi_s__MASK 0x01u
#define SPI_1_mosi_s__PA__CFG0 CYREG_UDB_PA3_CFG0
#define SPI_1_mosi_s__PA__CFG1 CYREG_UDB_PA3_CFG1
#define SPI_1_mosi_s__PA__CFG10 CYREG_UDB_PA3_CFG10
#define SPI_1_mosi_s__PA__CFG11 CYREG_UDB_PA3_CFG11
#define SPI_1_mosi_s__PA__CFG12 CYREG_UDB_PA3_CFG12
#define SPI_1_mosi_s__PA__CFG13 CYREG_UDB_PA3_CFG13
#define SPI_1_mosi_s__PA__CFG14 CYREG_UDB_PA3_CFG14
#define SPI_1_mosi_s__PA__CFG2 CYREG_UDB_PA3_CFG2
#define SPI_1_mosi_s__PA__CFG3 CYREG_UDB_PA3_CFG3
#define SPI_1_mosi_s__PA__CFG4 CYREG_UDB_PA3_CFG4
#define SPI_1_mosi_s__PA__CFG5 CYREG_UDB_PA3_CFG5
#define SPI_1_mosi_s__PA__CFG6 CYREG_UDB_PA3_CFG6
#define SPI_1_mosi_s__PA__CFG7 CYREG_UDB_PA3_CFG7
#define SPI_1_mosi_s__PA__CFG8 CYREG_UDB_PA3_CFG8
#define SPI_1_mosi_s__PA__CFG9 CYREG_UDB_PA3_CFG9
#define SPI_1_mosi_s__PC CYREG_PRT3_PC
#define SPI_1_mosi_s__PC2 CYREG_PRT3_PC2
#define SPI_1_mosi_s__PORT 3u
#define SPI_1_mosi_s__PS CYREG_PRT3_PS
#define SPI_1_mosi_s__SHIFT 0

/* SPI_1_SCB */
#define SPI_1_SCB__BIST_CONTROL CYREG_SCB1_BIST_CONTROL
#define SPI_1_SCB__BIST_DATA CYREG_SCB1_BIST_DATA
#define SPI_1_SCB__CTRL CYREG_SCB1_CTRL
#define SPI_1_SCB__EZ_DATA00 CYREG_SCB1_EZ_DATA00
#define SPI_1_SCB__EZ_DATA01 CYREG_SCB1_EZ_DATA01
#define SPI_1_SCB__EZ_DATA02 CYREG_SCB1_EZ_DATA02
#define SPI_1_SCB__EZ_DATA03 CYREG_SCB1_EZ_DATA03
#define SPI_1_SCB__EZ_DATA04 CYREG_SCB1_EZ_DATA04
#define SPI_1_SCB__EZ_DATA05 CYREG_SCB1_EZ_DATA05
#define SPI_1_SCB__EZ_DATA06 CYREG_SCB1_EZ_DATA06
#define SPI_1_SCB__EZ_DATA07 CYREG_SCB1_EZ_DATA07
#define SPI_1_SCB__EZ_DATA08 CYREG_SCB1_EZ_DATA08
#define SPI_1_SCB__EZ_DATA09 CYREG_SCB1_EZ_DATA09
#define SPI_1_SCB__EZ_DATA10 CYREG_SCB1_EZ_DATA10
#define SPI_1_SCB__EZ_DATA11 CYREG_SCB1_EZ_DATA11
#define SPI_1_SCB__EZ_DATA12 CYREG_SCB1_EZ_DATA12
#define SPI_1_SCB__EZ_DATA13 CYREG_SCB1_EZ_DATA13
#define SPI_1_SCB__EZ_DATA14 CYREG_SCB1_EZ_DATA14
#define SPI_1_SCB__EZ_DATA15 CYREG_SCB1_EZ_DATA15
#define SPI_1_SCB__EZ_DATA16 CYREG_SCB1_EZ_DATA16
#define SPI_1_SCB__EZ_DATA17 CYREG_SCB1_EZ_DATA17
#define SPI_1_SCB__EZ_DATA18 CYREG_SCB1_EZ_DATA18
#define SPI_1_SCB__EZ_DATA19 CYREG_SCB1_EZ_DATA19
#define SPI_1_SCB__EZ_DATA20 CYREG_SCB1_EZ_DATA20
#define SPI_1_SCB__EZ_DATA21 CYREG_SCB1_EZ_DATA21
#define SPI_1_SCB__EZ_DATA22 CYREG_SCB1_EZ_DATA22
#define SPI_1_SCB__EZ_DATA23 CYREG_SCB1_EZ_DATA23
#define SPI_1_SCB__EZ_DATA24 CYREG_SCB1_EZ_DATA24
#define SPI_1_SCB__EZ_DATA25 CYREG_SCB1_EZ_DATA25
#define SPI_1_SCB__EZ_DATA26 CYREG_SCB1_EZ_DATA26
#define SPI_1_SCB__EZ_DATA27 CYREG_SCB1_EZ_DATA27
#define SPI_1_SCB__EZ_DATA28 CYREG_SCB1_EZ_DATA28
#define SPI_1_SCB__EZ_DATA29 CYREG_SCB1_EZ_DATA29
#define SPI_1_SCB__EZ_DATA30 CYREG_SCB1_EZ_DATA30
#define SPI_1_SCB__EZ_DATA31 CYREG_SCB1_EZ_DATA31
#define SPI_1_SCB__I2C_CFG CYREG_SCB1_I2C_CFG
#define SPI_1_SCB__I2C_CTRL CYREG_SCB1_I2C_CTRL
#define SPI_1_SCB__I2C_M_CMD CYREG_SCB1_I2C_M_CMD
#define SPI_1_SCB__I2C_S_CMD CYREG_SCB1_I2C_S_CMD
#define SPI_1_SCB__I2C_STATUS CYREG_SCB1_I2C_STATUS
#define SPI_1_SCB__INTR_CAUSE CYREG_SCB1_INTR_CAUSE
#define SPI_1_SCB__INTR_I2C_EC CYREG_SCB1_INTR_I2C_EC
#define SPI_1_SCB__INTR_I2C_EC_MASK CYREG_SCB1_INTR_I2C_EC_MASK
#define SPI_1_SCB__INTR_I2C_EC_MASKED CYREG_SCB1_INTR_I2C_EC_MASKED
#define SPI_1_SCB__INTR_M CYREG_SCB1_INTR_M
#define SPI_1_SCB__INTR_M_MASK CYREG_SCB1_INTR_M_MASK
#define SPI_1_SCB__INTR_M_MASKED CYREG_SCB1_INTR_M_MASKED
#define SPI_1_SCB__INTR_M_SET CYREG_SCB1_INTR_M_SET
#define SPI_1_SCB__INTR_RX CYREG_SCB1_INTR_RX
#define SPI_1_SCB__INTR_RX_MASK CYREG_SCB1_INTR_RX_MASK
#define SPI_1_SCB__INTR_RX_MASKED CYREG_SCB1_INTR_RX_MASKED
#define SPI_1_SCB__INTR_RX_SET CYREG_SCB1_INTR_RX_SET
#define SPI_1_SCB__INTR_S CYREG_SCB1_INTR_S
#define SPI_1_SCB__INTR_S_MASK CYREG_SCB1_INTR_S_MASK
#define SPI_1_SCB__INTR_S_MASKED CYREG_SCB1_INTR_S_MASKED
#define SPI_1_SCB__INTR_S_SET CYREG_SCB1_INTR_S_SET
#define SPI_1_SCB__INTR_SPI_EC CYREG_SCB1_INTR_SPI_EC
#define SPI_1_SCB__INTR_SPI_EC_MASK CYREG_SCB1_INTR_SPI_EC_MASK
#define SPI_1_SCB__INTR_SPI_EC_MASKED CYREG_SCB1_INTR_SPI_EC_MASKED
#define SPI_1_SCB__INTR_TX CYREG_SCB1_INTR_TX
#define SPI_1_SCB__INTR_TX_MASK CYREG_SCB1_INTR_TX_MASK
#define SPI_1_SCB__INTR_TX_MASKED CYREG_SCB1_INTR_TX_MASKED
#define SPI_1_SCB__INTR_TX_SET CYREG_SCB1_INTR_TX_SET
#define SPI_1_SCB__RX_CTRL CYREG_SCB1_RX_CTRL
#define SPI_1_SCB__RX_FIFO_CTRL CYREG_SCB1_RX_FIFO_CTRL
#define SPI_1_SCB__RX_FIFO_RD CYREG_SCB1_RX_FIFO_RD
#define SPI_1_SCB__RX_FIFO_RD_SILENT CYREG_SCB1_RX_FIFO_RD_SILENT
#define SPI_1_SCB__RX_FIFO_STATUS CYREG_SCB1_RX_FIFO_STATUS
#define SPI_1_SCB__RX_MATCH CYREG_SCB1_RX_MATCH
#define SPI_1_SCB__SPI_CTRL CYREG_SCB1_SPI_CTRL
#define SPI_1_SCB__SPI_STATUS CYREG_SCB1_SPI_STATUS
#define SPI_1_SCB__SS0_POSISTION 0u
#define SPI_1_SCB__SS1_POSISTION 1u
#define SPI_1_SCB__SS2_POSISTION 2u
#define SPI_1_SCB__SS3_POSISTION 3u
#define SPI_1_SCB__STATUS CYREG_SCB1_STATUS
#define SPI_1_SCB__TX_CTRL CYREG_SCB1_TX_CTRL
#define SPI_1_SCB__TX_FIFO_CTRL CYREG_SCB1_TX_FIFO_CTRL
#define SPI_1_SCB__TX_FIFO_STATUS CYREG_SCB1_TX_FIFO_STATUS
#define SPI_1_SCB__TX_FIFO_WR CYREG_SCB1_TX_FIFO_WR
#define SPI_1_SCB__UART_CTRL CYREG_SCB1_UART_CTRL
#define SPI_1_SCB__UART_RX_CTRL CYREG_SCB1_UART_RX_CTRL
#define SPI_1_SCB__UART_RX_STATUS CYREG_SCB1_UART_RX_STATUS
#define SPI_1_SCB__UART_TX_CTRL CYREG_SCB1_UART_TX_CTRL

/* SPI_1_SCBCLK */
#define SPI_1_SCBCLK__DIVIDER_MASK 0x0000FFFFu
#define SPI_1_SCBCLK__ENABLE CYREG_CLK_DIVIDER_A00
#define SPI_1_SCBCLK__ENABLE_MASK 0x80000000u
#define SPI_1_SCBCLK__MASK 0x80000000u
#define SPI_1_SCBCLK__REGISTER CYREG_CLK_DIVIDER_A00

/* SPI_1_sclk_s */
#define SPI_1_sclk_s__0__DM__MASK 0x1C0000u
#define SPI_1_sclk_s__0__DM__SHIFT 18
#define SPI_1_sclk_s__0__DR CYREG_PRT0_DR
#define SPI_1_sclk_s__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define SPI_1_sclk_s__0__HSIOM_MASK 0x0F000000u
#define SPI_1_sclk_s__0__HSIOM_SHIFT 24u
#define SPI_1_sclk_s__0__INTCFG CYREG_PRT0_INTCFG
#define SPI_1_sclk_s__0__INTSTAT CYREG_PRT0_INTSTAT
#define SPI_1_sclk_s__0__MASK 0x40u
#define SPI_1_sclk_s__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SPI_1_sclk_s__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SPI_1_sclk_s__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SPI_1_sclk_s__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SPI_1_sclk_s__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SPI_1_sclk_s__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SPI_1_sclk_s__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SPI_1_sclk_s__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SPI_1_sclk_s__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SPI_1_sclk_s__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SPI_1_sclk_s__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SPI_1_sclk_s__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SPI_1_sclk_s__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SPI_1_sclk_s__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SPI_1_sclk_s__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SPI_1_sclk_s__0__PC CYREG_PRT0_PC
#define SPI_1_sclk_s__0__PC2 CYREG_PRT0_PC2
#define SPI_1_sclk_s__0__PORT 0u
#define SPI_1_sclk_s__0__PS CYREG_PRT0_PS
#define SPI_1_sclk_s__0__SHIFT 6
#define SPI_1_sclk_s__DR CYREG_PRT0_DR
#define SPI_1_sclk_s__INTCFG CYREG_PRT0_INTCFG
#define SPI_1_sclk_s__INTSTAT CYREG_PRT0_INTSTAT
#define SPI_1_sclk_s__MASK 0x40u
#define SPI_1_sclk_s__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SPI_1_sclk_s__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SPI_1_sclk_s__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SPI_1_sclk_s__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SPI_1_sclk_s__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SPI_1_sclk_s__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SPI_1_sclk_s__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SPI_1_sclk_s__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SPI_1_sclk_s__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SPI_1_sclk_s__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SPI_1_sclk_s__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SPI_1_sclk_s__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SPI_1_sclk_s__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SPI_1_sclk_s__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SPI_1_sclk_s__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SPI_1_sclk_s__PC CYREG_PRT0_PC
#define SPI_1_sclk_s__PC2 CYREG_PRT0_PC2
#define SPI_1_sclk_s__PORT 0u
#define SPI_1_sclk_s__PS CYREG_PRT0_PS
#define SPI_1_sclk_s__SHIFT 6

/* SPI_1_ss_s */
#define SPI_1_ss_s__0__DM__MASK 0xE00000u
#define SPI_1_ss_s__0__DM__SHIFT 21
#define SPI_1_ss_s__0__DR CYREG_PRT0_DR
#define SPI_1_ss_s__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define SPI_1_ss_s__0__HSIOM_MASK 0xF0000000u
#define SPI_1_ss_s__0__HSIOM_SHIFT 28u
#define SPI_1_ss_s__0__INTCFG CYREG_PRT0_INTCFG
#define SPI_1_ss_s__0__INTSTAT CYREG_PRT0_INTSTAT
#define SPI_1_ss_s__0__MASK 0x80u
#define SPI_1_ss_s__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SPI_1_ss_s__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SPI_1_ss_s__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SPI_1_ss_s__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SPI_1_ss_s__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SPI_1_ss_s__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SPI_1_ss_s__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SPI_1_ss_s__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SPI_1_ss_s__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SPI_1_ss_s__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SPI_1_ss_s__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SPI_1_ss_s__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SPI_1_ss_s__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SPI_1_ss_s__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SPI_1_ss_s__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SPI_1_ss_s__0__PC CYREG_PRT0_PC
#define SPI_1_ss_s__0__PC2 CYREG_PRT0_PC2
#define SPI_1_ss_s__0__PORT 0u
#define SPI_1_ss_s__0__PS CYREG_PRT0_PS
#define SPI_1_ss_s__0__SHIFT 7
#define SPI_1_ss_s__DR CYREG_PRT0_DR
#define SPI_1_ss_s__INTCFG CYREG_PRT0_INTCFG
#define SPI_1_ss_s__INTSTAT CYREG_PRT0_INTSTAT
#define SPI_1_ss_s__MASK 0x80u
#define SPI_1_ss_s__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SPI_1_ss_s__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SPI_1_ss_s__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SPI_1_ss_s__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SPI_1_ss_s__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SPI_1_ss_s__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SPI_1_ss_s__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SPI_1_ss_s__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SPI_1_ss_s__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SPI_1_ss_s__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SPI_1_ss_s__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SPI_1_ss_s__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SPI_1_ss_s__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SPI_1_ss_s__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SPI_1_ss_s__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SPI_1_ss_s__PC CYREG_PRT0_PC
#define SPI_1_ss_s__PC2 CYREG_PRT0_PC2
#define SPI_1_ss_s__PORT 0u
#define SPI_1_ss_s__PS CYREG_PRT0_PS
#define SPI_1_ss_s__SHIFT 7

/* INT_PIN */
#define INT_PIN__0__DM__MASK 0x1C0000u
#define INT_PIN__0__DM__SHIFT 18
#define INT_PIN__0__DR CYREG_PRT2_DR
#define INT_PIN__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define INT_PIN__0__HSIOM_MASK 0x0F000000u
#define INT_PIN__0__HSIOM_SHIFT 24u
#define INT_PIN__0__INTCFG CYREG_PRT2_INTCFG
#define INT_PIN__0__INTSTAT CYREG_PRT2_INTSTAT
#define INT_PIN__0__MASK 0x40u
#define INT_PIN__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define INT_PIN__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define INT_PIN__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define INT_PIN__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define INT_PIN__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define INT_PIN__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define INT_PIN__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define INT_PIN__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define INT_PIN__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define INT_PIN__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define INT_PIN__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define INT_PIN__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define INT_PIN__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define INT_PIN__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define INT_PIN__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define INT_PIN__0__PC CYREG_PRT2_PC
#define INT_PIN__0__PC2 CYREG_PRT2_PC2
#define INT_PIN__0__PORT 2u
#define INT_PIN__0__PS CYREG_PRT2_PS
#define INT_PIN__0__SHIFT 6
#define INT_PIN__DR CYREG_PRT2_DR
#define INT_PIN__INTCFG CYREG_PRT2_INTCFG
#define INT_PIN__INTSTAT CYREG_PRT2_INTSTAT
#define INT_PIN__MASK 0x40u
#define INT_PIN__PA__CFG0 CYREG_UDB_PA2_CFG0
#define INT_PIN__PA__CFG1 CYREG_UDB_PA2_CFG1
#define INT_PIN__PA__CFG10 CYREG_UDB_PA2_CFG10
#define INT_PIN__PA__CFG11 CYREG_UDB_PA2_CFG11
#define INT_PIN__PA__CFG12 CYREG_UDB_PA2_CFG12
#define INT_PIN__PA__CFG13 CYREG_UDB_PA2_CFG13
#define INT_PIN__PA__CFG14 CYREG_UDB_PA2_CFG14
#define INT_PIN__PA__CFG2 CYREG_UDB_PA2_CFG2
#define INT_PIN__PA__CFG3 CYREG_UDB_PA2_CFG3
#define INT_PIN__PA__CFG4 CYREG_UDB_PA2_CFG4
#define INT_PIN__PA__CFG5 CYREG_UDB_PA2_CFG5
#define INT_PIN__PA__CFG6 CYREG_UDB_PA2_CFG6
#define INT_PIN__PA__CFG7 CYREG_UDB_PA2_CFG7
#define INT_PIN__PA__CFG8 CYREG_UDB_PA2_CFG8
#define INT_PIN__PA__CFG9 CYREG_UDB_PA2_CFG9
#define INT_PIN__PC CYREG_PRT2_PC
#define INT_PIN__PC2 CYREG_PRT2_PC2
#define INT_PIN__PORT 2u
#define INT_PIN__PS CYREG_PRT2_PS
#define INT_PIN__SHIFT 6

/* isr_spi */
#define isr_spi__INTC_CLR_EN_REG CYREG_CM0_ICER
#define isr_spi__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define isr_spi__INTC_MASK 0x800u
#define isr_spi__INTC_NUMBER 11u
#define isr_spi__INTC_PRIOR_MASK 0xC0000000u
#define isr_spi__INTC_PRIOR_NUM 3u
#define isr_spi__INTC_PRIOR_REG CYREG_CM0_IPR2
#define isr_spi__INTC_SET_EN_REG CYREG_CM0_ISER
#define isr_spi__INTC_SET_PD_REG CYREG_CM0_ISPR

/* DebugLEDRed */
#define DebugLEDRed__0__DM__MASK 0x1C0000u
#define DebugLEDRed__0__DM__SHIFT 18
#define DebugLEDRed__0__DR CYREG_PRT1_DR
#define DebugLEDRed__0__HSIOM CYREG_HSIOM_PORT_SEL1
#define DebugLEDRed__0__HSIOM_MASK 0x0F000000u
#define DebugLEDRed__0__HSIOM_SHIFT 24u
#define DebugLEDRed__0__INTCFG CYREG_PRT1_INTCFG
#define DebugLEDRed__0__INTSTAT CYREG_PRT1_INTSTAT
#define DebugLEDRed__0__MASK 0x40u
#define DebugLEDRed__0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define DebugLEDRed__0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define DebugLEDRed__0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define DebugLEDRed__0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define DebugLEDRed__0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define DebugLEDRed__0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define DebugLEDRed__0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define DebugLEDRed__0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define DebugLEDRed__0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define DebugLEDRed__0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define DebugLEDRed__0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define DebugLEDRed__0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define DebugLEDRed__0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define DebugLEDRed__0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define DebugLEDRed__0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define DebugLEDRed__0__PC CYREG_PRT1_PC
#define DebugLEDRed__0__PC2 CYREG_PRT1_PC2
#define DebugLEDRed__0__PORT 1u
#define DebugLEDRed__0__PS CYREG_PRT1_PS
#define DebugLEDRed__0__SHIFT 6
#define DebugLEDRed__DR CYREG_PRT1_DR
#define DebugLEDRed__INTCFG CYREG_PRT1_INTCFG
#define DebugLEDRed__INTSTAT CYREG_PRT1_INTSTAT
#define DebugLEDRed__MASK 0x40u
#define DebugLEDRed__PA__CFG0 CYREG_UDB_PA1_CFG0
#define DebugLEDRed__PA__CFG1 CYREG_UDB_PA1_CFG1
#define DebugLEDRed__PA__CFG10 CYREG_UDB_PA1_CFG10
#define DebugLEDRed__PA__CFG11 CYREG_UDB_PA1_CFG11
#define DebugLEDRed__PA__CFG12 CYREG_UDB_PA1_CFG12
#define DebugLEDRed__PA__CFG13 CYREG_UDB_PA1_CFG13
#define DebugLEDRed__PA__CFG14 CYREG_UDB_PA1_CFG14
#define DebugLEDRed__PA__CFG2 CYREG_UDB_PA1_CFG2
#define DebugLEDRed__PA__CFG3 CYREG_UDB_PA1_CFG3
#define DebugLEDRed__PA__CFG4 CYREG_UDB_PA1_CFG4
#define DebugLEDRed__PA__CFG5 CYREG_UDB_PA1_CFG5
#define DebugLEDRed__PA__CFG6 CYREG_UDB_PA1_CFG6
#define DebugLEDRed__PA__CFG7 CYREG_UDB_PA1_CFG7
#define DebugLEDRed__PA__CFG8 CYREG_UDB_PA1_CFG8
#define DebugLEDRed__PA__CFG9 CYREG_UDB_PA1_CFG9
#define DebugLEDRed__PC CYREG_PRT1_PC
#define DebugLEDRed__PC2 CYREG_PRT1_PC2
#define DebugLEDRed__PORT 1u
#define DebugLEDRed__PS CYREG_PRT1_PS
#define DebugLEDRed__SHIFT 6

/* DebugLEDBlue */
#define DebugLEDBlue__0__DM__MASK 0xE00u
#define DebugLEDBlue__0__DM__SHIFT 9
#define DebugLEDBlue__0__DR CYREG_PRT0_DR
#define DebugLEDBlue__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define DebugLEDBlue__0__HSIOM_MASK 0x0000F000u
#define DebugLEDBlue__0__HSIOM_SHIFT 12u
#define DebugLEDBlue__0__INTCFG CYREG_PRT0_INTCFG
#define DebugLEDBlue__0__INTSTAT CYREG_PRT0_INTSTAT
#define DebugLEDBlue__0__MASK 0x08u
#define DebugLEDBlue__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define DebugLEDBlue__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define DebugLEDBlue__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define DebugLEDBlue__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define DebugLEDBlue__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define DebugLEDBlue__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define DebugLEDBlue__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define DebugLEDBlue__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define DebugLEDBlue__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define DebugLEDBlue__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define DebugLEDBlue__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define DebugLEDBlue__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define DebugLEDBlue__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define DebugLEDBlue__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define DebugLEDBlue__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define DebugLEDBlue__0__PC CYREG_PRT0_PC
#define DebugLEDBlue__0__PC2 CYREG_PRT0_PC2
#define DebugLEDBlue__0__PORT 0u
#define DebugLEDBlue__0__PS CYREG_PRT0_PS
#define DebugLEDBlue__0__SHIFT 3
#define DebugLEDBlue__DR CYREG_PRT0_DR
#define DebugLEDBlue__INTCFG CYREG_PRT0_INTCFG
#define DebugLEDBlue__INTSTAT CYREG_PRT0_INTSTAT
#define DebugLEDBlue__MASK 0x08u
#define DebugLEDBlue__PA__CFG0 CYREG_UDB_PA0_CFG0
#define DebugLEDBlue__PA__CFG1 CYREG_UDB_PA0_CFG1
#define DebugLEDBlue__PA__CFG10 CYREG_UDB_PA0_CFG10
#define DebugLEDBlue__PA__CFG11 CYREG_UDB_PA0_CFG11
#define DebugLEDBlue__PA__CFG12 CYREG_UDB_PA0_CFG12
#define DebugLEDBlue__PA__CFG13 CYREG_UDB_PA0_CFG13
#define DebugLEDBlue__PA__CFG14 CYREG_UDB_PA0_CFG14
#define DebugLEDBlue__PA__CFG2 CYREG_UDB_PA0_CFG2
#define DebugLEDBlue__PA__CFG3 CYREG_UDB_PA0_CFG3
#define DebugLEDBlue__PA__CFG4 CYREG_UDB_PA0_CFG4
#define DebugLEDBlue__PA__CFG5 CYREG_UDB_PA0_CFG5
#define DebugLEDBlue__PA__CFG6 CYREG_UDB_PA0_CFG6
#define DebugLEDBlue__PA__CFG7 CYREG_UDB_PA0_CFG7
#define DebugLEDBlue__PA__CFG8 CYREG_UDB_PA0_CFG8
#define DebugLEDBlue__PA__CFG9 CYREG_UDB_PA0_CFG9
#define DebugLEDBlue__PC CYREG_PRT0_PC
#define DebugLEDBlue__PC2 CYREG_PRT0_PC2
#define DebugLEDBlue__PORT 0u
#define DebugLEDBlue__PS CYREG_PRT0_PS
#define DebugLEDBlue__SHIFT 3

/* DebugLEDGreen */
#define DebugLEDGreen__0__DM__MASK 0x1C0u
#define DebugLEDGreen__0__DM__SHIFT 6
#define DebugLEDGreen__0__DR CYREG_PRT0_DR
#define DebugLEDGreen__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define DebugLEDGreen__0__HSIOM_MASK 0x00000F00u
#define DebugLEDGreen__0__HSIOM_SHIFT 8u
#define DebugLEDGreen__0__INTCFG CYREG_PRT0_INTCFG
#define DebugLEDGreen__0__INTSTAT CYREG_PRT0_INTSTAT
#define DebugLEDGreen__0__MASK 0x04u
#define DebugLEDGreen__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define DebugLEDGreen__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define DebugLEDGreen__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define DebugLEDGreen__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define DebugLEDGreen__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define DebugLEDGreen__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define DebugLEDGreen__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define DebugLEDGreen__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define DebugLEDGreen__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define DebugLEDGreen__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define DebugLEDGreen__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define DebugLEDGreen__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define DebugLEDGreen__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define DebugLEDGreen__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define DebugLEDGreen__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define DebugLEDGreen__0__PC CYREG_PRT0_PC
#define DebugLEDGreen__0__PC2 CYREG_PRT0_PC2
#define DebugLEDGreen__0__PORT 0u
#define DebugLEDGreen__0__PS CYREG_PRT0_PS
#define DebugLEDGreen__0__SHIFT 2
#define DebugLEDGreen__DR CYREG_PRT0_DR
#define DebugLEDGreen__INTCFG CYREG_PRT0_INTCFG
#define DebugLEDGreen__INTSTAT CYREG_PRT0_INTSTAT
#define DebugLEDGreen__MASK 0x04u
#define DebugLEDGreen__PA__CFG0 CYREG_UDB_PA0_CFG0
#define DebugLEDGreen__PA__CFG1 CYREG_UDB_PA0_CFG1
#define DebugLEDGreen__PA__CFG10 CYREG_UDB_PA0_CFG10
#define DebugLEDGreen__PA__CFG11 CYREG_UDB_PA0_CFG11
#define DebugLEDGreen__PA__CFG12 CYREG_UDB_PA0_CFG12
#define DebugLEDGreen__PA__CFG13 CYREG_UDB_PA0_CFG13
#define DebugLEDGreen__PA__CFG14 CYREG_UDB_PA0_CFG14
#define DebugLEDGreen__PA__CFG2 CYREG_UDB_PA0_CFG2
#define DebugLEDGreen__PA__CFG3 CYREG_UDB_PA0_CFG3
#define DebugLEDGreen__PA__CFG4 CYREG_UDB_PA0_CFG4
#define DebugLEDGreen__PA__CFG5 CYREG_UDB_PA0_CFG5
#define DebugLEDGreen__PA__CFG6 CYREG_UDB_PA0_CFG6
#define DebugLEDGreen__PA__CFG7 CYREG_UDB_PA0_CFG7
#define DebugLEDGreen__PA__CFG8 CYREG_UDB_PA0_CFG8
#define DebugLEDGreen__PA__CFG9 CYREG_UDB_PA0_CFG9
#define DebugLEDGreen__PC CYREG_PRT0_PC
#define DebugLEDGreen__PC2 CYREG_PRT0_PC2
#define DebugLEDGreen__PORT 0u
#define DebugLEDGreen__PS CYREG_PRT0_PS
#define DebugLEDGreen__SHIFT 2

/* Miscellaneous */
#define CY_PROJECT_NAME "PSoC0"
#define CY_VERSION "PSoC Creator  3.3 SP1"
#define CYDEV_BCLK__HFCLK__HZ 24000000U
#define CYDEV_BCLK__HFCLK__KHZ 24000U
#define CYDEV_BCLK__HFCLK__MHZ 24U
#define CYDEV_BCLK__SYSCLK__HZ 24000000U
#define CYDEV_BCLK__SYSCLK__KHZ 24000U
#define CYDEV_BCLK__SYSCLK__MHZ 24U
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PANTHER 18u
#define CYDEV_CHIP_DIE_PSOC4A 10u
#define CYDEV_CHIP_DIE_PSOC5LP 17u
#define CYDEV_CHIP_DIE_TMA4 2u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC4
#define CYDEV_CHIP_JTAG_ID 0x04C81193u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 10u
#define CYDEV_CHIP_MEMBER_4C 15u
#define CYDEV_CHIP_MEMBER_4D 6u
#define CYDEV_CHIP_MEMBER_4E 4u
#define CYDEV_CHIP_MEMBER_4F 11u
#define CYDEV_CHIP_MEMBER_4G 2u
#define CYDEV_CHIP_MEMBER_4H 9u
#define CYDEV_CHIP_MEMBER_4I 14u
#define CYDEV_CHIP_MEMBER_4J 7u
#define CYDEV_CHIP_MEMBER_4K 8u
#define CYDEV_CHIP_MEMBER_4L 13u
#define CYDEV_CHIP_MEMBER_4M 12u
#define CYDEV_CHIP_MEMBER_4N 5u
#define CYDEV_CHIP_MEMBER_4U 3u
#define CYDEV_CHIP_MEMBER_5A 17u
#define CYDEV_CHIP_MEMBER_5B 16u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_4A
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PANTHER_ES0 0u
#define CYDEV_CHIP_REV_PANTHER_ES1 1u
#define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4C_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_4A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_PROTECT_KILL 4
#define CYDEV_DEBUG_PROTECT_OPEN 1
#define CYDEV_DEBUG_PROTECT CYDEV_DEBUG_PROTECT_OPEN
#define CYDEV_DEBUG_PROTECT_PROTECTED 2
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DFT_SELECT_CLK0 1u
#define CYDEV_DFT_SELECT_CLK1 2u
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_IMO_TRIMMED_BY_USB 0u
#define CYDEV_IMO_TRIMMED_BY_WCO 0u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_STACK_SIZE 0x0400
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 1
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYDEV_WDT_GENERATE_ISR 1u
#define CYIPBLOCK_M0S8_CTBM_VERSION 0
#define CYIPBLOCK_m0s8cpuss_VERSION 0
#define CYIPBLOCK_m0s8csd_VERSION 0
#define CYIPBLOCK_m0s8gpio2_VERSION 0
#define CYIPBLOCK_m0s8hsiom4a_VERSION 0
#define CYIPBLOCK_m0s8lcd_VERSION 0
#define CYIPBLOCK_m0s8lpcomp_VERSION 0
#define CYIPBLOCK_m0s8pclk_VERSION 0
#define CYIPBLOCK_m0s8sar_VERSION 0
#define CYIPBLOCK_m0s8scb_VERSION 0
#define CYIPBLOCK_m0s8srssv2_VERSION 1
#define CYIPBLOCK_m0s8tcpwm_VERSION 0
#define CYIPBLOCK_m0s8udbif_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 2
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
