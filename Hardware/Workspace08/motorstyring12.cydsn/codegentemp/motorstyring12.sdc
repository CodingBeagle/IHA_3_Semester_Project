# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\mikkel\Documents\PSoC Creator\Workspace08\motorstyring12.cydsn\motorstyring12.cyprj
# Date: Mon, 18 Apr 2016 15:36:56 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_PWM_3} -source [get_pins {ClockBlock/hfclk}] -edges {1 48001 96001} [list [get_pins {ClockBlock/udb_div_0}]]
create_generated_clock -name {Clock_PWM_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 48001 96001} [list [get_pins {ClockBlock/udb_div_1}]]
create_generated_clock -name {Clock_PWM} -source [get_pins {ClockBlock/hfclk}] -edges {1 48001 96001} [list [get_pins {ClockBlock/udb_div_2}]]
create_generated_clock -name {Clock_PWM_2} -source [get_pins {ClockBlock/hfclk}] -edges {1 48001 96001} [list [get_pins {ClockBlock/udb_div_3}]]


# Component constraints for C:\Users\mikkel\Documents\PSoC Creator\Workspace08\motorstyring12.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\mikkel\Documents\PSoC Creator\Workspace08\motorstyring12.cydsn\motorstyring12.cyprj
# Date: Mon, 18 Apr 2016 15:36:47 GMT
