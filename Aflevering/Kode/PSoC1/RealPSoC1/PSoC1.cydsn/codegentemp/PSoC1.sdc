# THIS FILE IS AUTOMATICALLY GENERATED
# Project: \\BADBOY93\Users\Daniel\Documents\IHA_3_Semester_Project\Software\I2C Net\RealPSoC1\PSoC1\RealPSoC1\PSoC1.cydsn\PSoC1.cyprj
# Date: Wed, 18 May 2016 12:40:12 GMT
#set_units -time ns
create_clock -name {ADC_1_intClock(FFB)} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {I2C_1_SCBCLK(FFB)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_PWM_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 9 17} [list [get_pins {ClockBlock/udb_div_0}]]
create_generated_clock -name {ADC_1_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 9 17} [list]
create_generated_clock -name {I2C_1_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 15 31} [list]


# Component constraints for \\BADBOY93\Users\Daniel\Documents\IHA_3_Semester_Project\Software\I2C Net\RealPSoC1\PSoC1\RealPSoC1\PSoC1.cydsn\TopDesign\TopDesign.cysch
# Project: \\BADBOY93\Users\Daniel\Documents\IHA_3_Semester_Project\Software\I2C Net\RealPSoC1\PSoC1\RealPSoC1\PSoC1.cydsn\PSoC1.cyprj
# Date: Wed, 18 May 2016 12:39:58 GMT