# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\PernilleLouise\Documents\Elektro\3. semester\E3PRJ3\Hardware\Motorstyring_1.cydsn\Motorstyring_1.cyprj
# Date: Mon, 07 Mar 2016 11:59:14 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_PWM} -source [get_pins {ClockBlock/hfclk}] -edges {1 9 17} [list [get_pins {ClockBlock/udb_div_0}]]


# Component constraints for C:\Users\PernilleLouise\Documents\Elektro\3. semester\E3PRJ3\Hardware\Motorstyring_1.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\PernilleLouise\Documents\Elektro\3. semester\E3PRJ3\Hardware\Motorstyring_1.cydsn\Motorstyring_1.cyprj
# Date: Mon, 07 Mar 2016 11:59:11 GMT
