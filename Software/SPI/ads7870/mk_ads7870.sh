insmod hotplug_ads7870_spi_device.ko
insmod ads7870mod.ko
mknod /dev/adc0 c 64 0
mknod /dev/adc1 c 64 1
mknod /dev/adc2 c 64 2
mknod /dev/adc3 c 64 3
mknod /dev/adc4 c 64 4
mknod /dev/adc5 c 64 5
mknod /dev/adc6 c 64 6
mknod /dev/adc7 c 64 7
