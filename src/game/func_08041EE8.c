#include "types.h"

extern u8 D_03005BB0[];
extern u32 D_02000B58;
extern u8 D_0200DA99;

void func_08041EAC(void);
void func_0805D270(void *, void *, u32);

void func_08041EE8(u8 mode)
{
    switch (mode)
    {
    case 0:
        *(vu16 *)0x04000200 |= 1;
        *(vu16 *)0x04000004 |= 8;
        break;
    case 1:
        func_0805D270(func_08041EAC, D_03005BB0, 0x04000010);
        D_02000B58 = (u32)D_03005BB0 + 1;
        D_0200DA99 = 0;
        *(vu16 *)0x04000200 |= 3;
        *(vu16 *)0x04000004 |= 0x18;
        break;
    }
}
