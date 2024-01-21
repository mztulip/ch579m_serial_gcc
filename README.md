# ch579m_ledBlink_gcc

Led blink example with YLCH579M eval board.

Compile:
```
chmod +x make.sh(if necessary)
make.sh
```

Compiled using:
arm-none-eabi-gcc (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)[Link](https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2?rev=78196d3461ba4c9089a67b5f33edf82a&hash=5631ACEF1F8F237389F14B41566964EC)
GNU bash, version 5.2.21(1)-release (x86_64-pc-linux-gnu)

![alt text](https://github.com/mztulip/ch579m_ledBlink_gcc/blob/main/eval.png?raw=true)

Board can be programmed over USB cable using https://github.com/ch32-rs/wchisp.
```
wchisp flash output.elf
```