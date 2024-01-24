#/bin/bash
set -e

if [ $1 = "--ram" ]; then
    LINKER_SCRIPT="ch579_ram.lds"
    
else
    LINKER_SCRIPT="ch579.lds"
fi

TOOLCHAIN="/home/tulip/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-"
TOOLCHAIN_GCC=$TOOLCHAIN"gcc"
TOOLCHAIN_SIZE=$TOOLCHAIN"size"
TOOLCHAIN_OBJDUMP=$TOOLCHAIN"objdump"
TOOLCHAIN_OBJCOPY=$TOOLCHAIN"objcopy"
echo $TOOLCHAIN_GCC

# -c => Compile or assemble the source files, but do not link. 
# -fdata-sections
#-ffunction-sections => Place each function or data item into its own section in the output file if the target supports arbitrary sections. The name of the function or the name of the data item determines the section’s name in the output file. 
# -mthumb => Select between generating code that executes in ARM and Thumb states
GCC_FLAGS="-c -ffunction-sections -fdata-sections -mthumb -mcpu=cortex-m0 -g -mfloat-abi=soft"
INLCUDES="-I StdPeriphDriver/inc/ -I CMSIS/Include/"

file1="$TOOLCHAIN_GCC Main.c $INLCUDES -o build/main.o $GCC_FLAGS"
echo $file1
$file1

file2="$TOOLCHAIN_GCC StdPeriphDriver/CH57x_sys.c $INLCUDES -o build/CH57x_sys.o $GCC_FLAGS"
echo $file2
$file2

file3="$TOOLCHAIN_GCC startup.c $INLCUDES -o build/startup.o $GCC_FLAGS"
echo $file3
$file3

file4="$TOOLCHAIN_GCC StdPeriphDriver/CH57x_clk.c $INLCUDES -o build/CH57x_clk.o $GCC_FLAGS"
echo $file4
$file4

file5="$TOOLCHAIN_GCC StdPeriphDriver/CH57x_gpio.c $INLCUDES -o build/CH57x_gpio.o $GCC_FLAGS"
echo $file5
$file5

file6="$TOOLCHAIN_GCC StdPeriphDriver/CH57x_pwr.c $INLCUDES -o build/CH57x_pwr.o $GCC_FLAGS"
echo $file6
$file6

file7="$TOOLCHAIN_GCC StdPeriphDriver/CH57x_uart1.c $INLCUDES -o build/CH57x_uart1.o $GCC_FLAGS"
echo $file7
$file7

file8="$TOOLCHAIN_GCC StdPeriphDriver/CH57x_int.c $INLCUDES -o build/CH57x_int.o $GCC_FLAGS"
echo $file8
$file8

file9="$TOOLCHAIN_GCC StdPeriphDriver/CH57x_uart0.c $INLCUDES -o build/CH57x_uart0.o $GCC_FLAGS"
echo $file9
$file9

file10="$TOOLCHAIN_GCC StdPeriphDriver/CH57x_uart2.c $INLCUDES -o build/CH57x_uart2.o $GCC_FLAGS"
echo $file10
$file10

file="$TOOLCHAIN_GCC StdPeriphDriver/CH57x_uart3.c $INLCUDES -o build/CH57x_uart3.o $GCC_FLAGS"
echo $file
$file

linker="$TOOLCHAIN_GCC build/*.o -nostartfiles -T$LINKER_SCRIPT -Wl,--gc-sections -mcpu=cortex-m0 -o output.elf  -Xlinker -Map=output.map"
echo $linker
$linker

$TOOLCHAIN_OBJDUMP -S --disassemble -marm output.elf > output.asm
$TOOLCHAIN_OBJCOPY -O ihex output.elf output.hex
$TOOLCHAIN_OBJCOPY -O binary output.elf output.bin

$TOOLCHAIN_SIZE "output.elf"