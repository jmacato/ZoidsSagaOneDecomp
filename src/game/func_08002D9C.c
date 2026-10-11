#include "types.h"

extern u16 D_0200E8A4;

void func_08002D9C(void)
{
    *(volatile u16 *)0x04000052 = ((16 - D_0200E8A4) << 8) | D_0200E8A4;
}
