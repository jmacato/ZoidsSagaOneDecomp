#include "m2c.h"

void func_080032D0(void)
{
    *(u8 *)0x0200E8A9 ^= 1;
    *(s32 *)0x0200E8AC = (*(u8 *)0x0200E8A9 * 0x140) + 0x0200E8B0;
}
