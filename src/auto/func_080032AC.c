#include "m2c.h"

void func_080032AC(void)
{
    *(s16 *)0x04000054 = 0xF & *(u16 *)((*(u8 *)0x04000006 * 2) + *(s32 *)0x0200E8AC);
}
