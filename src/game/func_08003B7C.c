#include "types.h"

extern u8 D_0874FA90[];

void func_080019EC(s32);
void func_08001D04(s32);
void func_08003B78(void);
void func_080014A8(s32, void *);
s32 func_08001524(s32, void *);
void func_0803E488(u8 *, s32);

s32 func_08003B7C(u8 mode)
{
    func_080019EC(0);
    *(vu16 *)0x04000000 = 0x140;
    func_08001D04(1);
    func_080014A8(0xFFFF, func_08003B78);
    if (mode == 0)
        func_0803E488(D_0874FA90, 0xB);
    else if (mode == 1)
        func_0803E488(D_0874FA90, 0xA);
    else if (mode == 2)
        func_0803E488(D_0874FA90, 0xB);
    return func_08001524(0xFFFF, func_08003B78);
}
