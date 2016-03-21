#ifndef ADS7870_H
#define ADS7870_H

/*
 * ADS7870 Definitions and Macros
 */
#define ADS7870_CS_PORT			PORTB
#define ADS7870_CS_DDR			DDRB
#define ADS7870_CS_PIN			PB0

// instruction bit defines
#define ADS7870_CONVERT			0x80

#define ADS7870_REG_READ		0x40
#define ADS7870_REG_WRITE		0x00
#define ADS7870_REG_16BIT		0x20

// register addresses
#define ADS7870_RESULTLO		0x00
#define ADS7870_RESULTHI		0x01
#define ADS7870_PGAVALID		0x02
#define ADS7870_ADCTRL			0x03
#define ADS7870_GAINMUX			0x04
#define ADS7870_DIGIOSTATE		0x05
#define ADS7870_DIGIOCTRL		0x06
#define ADS7870_REFOSC			0x07
#define ADS7870_SERIFCTRL		0x18
#define ADS7870_ID			0x1F

// register bit defines
#define ADS7870_RESULTLO_OVR	0x01

#define ADS7870_ADCTRL_BIN		0x20
#define ADS7870_ADCTRL_RMB1		0x08
#define ADS7870_ADCTRL_RMB0		0x04
#define ADS7870_ADCTRL_CFD1		0x02
#define ADS7870_ADCTRL_CFD0		0x01

#define ADS7870_GAINMUX_CNVBSY	0x80

#define ADS7870_REFOSC_OSCR		0x20
#define ADS7870_REFOSC_OSCE		0x10
#define ADS7870_REFOSC_REFE		0x08
#define ADS7870_REFOSC_BUFE		0x04
#define ADS7870_REFOSC_R2V		0x02
#define ADS7870_REFOSC_RBG		0x01

#define ADS7870_SERIFCTRL_LSB	0x01
#define ADS7870_SERIFCTRL_2W3W	0x02
#define ADS7870_SERIFCTRL_8051	0x04

#define ADS7870_ID_VALUE		0x01

// gain defines
#define ADS7870_GAIN_1X			0x00
#define ADS7870_GAIN_2X			0x10
#define ADS7870_GAIN_4X			0x20
#define ADS7870_GAIN_5X			0x30
#define ADS7870_GAIN_8X			0x40
#define ADS7870_GAIN_10X		0x50
#define ADS7870_GAIN_16X		0x60
#define ADS7870_GAIN_20X		0x70

// channel defines
#define ADS7870_CH_0_1_DIFF		0x00
#define ADS7870_CH_2_3_DIFF		0x01
#define ADS7870_CH_4_5_DIFF		0x02
#define ADS7870_CH_6_7_DIFF		0x03
#define ADS7870_CH_1_0_DIFF		0x04
#define ADS7870_CH_3_2_DIFF		0x05
#define ADS7870_CH_5_4_DIFF		0x06
#define ADS7870_CH_7_6_DIFF		0x07
#define ADS7870_CH_SINGLE_ENDED	0x08
#define ADS7870_CH_0			0x08
#define ADS7870_CH_1			0x09
#define ADS7870_CH_2			0x0A
#define ADS7870_CH_3			0x0B
#define ADS7870_CH_4			0x0C
#define ADS7870_CH_5			0x0D
#define ADS7870_CH_6			0x0E
#define ADS7870_CH_7			0x0F

#endif
