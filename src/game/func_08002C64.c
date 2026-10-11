#include "types.h"

void func_08002C64(void)
{
    *(volatile u16 *)0x04000050 = 0x3F41;
    *(volatile u16 *)0x04000052 = 0x1000;
    *(volatile u16 *)0x04000008 &= 0xFF70;
    *(volatile u16 *)0x04000008 |= 0;
    *(volatile u16 *)0x04000000 |= 0x100;
}
