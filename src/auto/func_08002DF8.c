#include "m2c.h"

void func_08002DF8(void)
{
    *(u16 *)0x04000000 |= 0x800;
    *(s16 *)0x04000050 = 0xC8;
    *(s16 *)0x03002356 = 0xF;
}
