@echo "inserting cmpc module"
insmod cmpc.ko
mknod /dev/cmpc c 69 0
@echo "Setting pins 171-177 to mode 0 (SPI)"
echo 171:0 > /dev/cmpc
echo 172:0 > /dev/cmpc
echo 173:0 > /dev/cmpc
echo 174:0 > /dev/cmpc
echo 177:0 > /dev/cmpc
