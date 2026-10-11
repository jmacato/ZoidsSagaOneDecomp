#include "types.h"

extern struct
{
    u8 pad_0[6];
    u8 field_6;
} D_030021A8;

void func_08006298(void)
{
    *(vu16 *)0x04000208 = 0;
    *(vu16 *)0x04000200 &= 0xFF3F;
    *(vu16 *)0x04000208 = 1;
    *(vu16 *)0x04000128 = 0x2003;
    *(vu32 *)0x0400010C = 0xBFC0;
    *(vu16 *)0x04000202 = 0xC0;
    D_030021A8.field_6 = 0;
}
