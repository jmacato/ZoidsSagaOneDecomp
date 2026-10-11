#include "types.h"

extern u16 D_03002358;

void func_0800A5E4(u16, s32, s32, s32, s32);
void func_0800A594(u16);

void func_0800AA60(u16 id)
{
    if (D_03002358 & 2)
        func_0800A5E4(id, 3, 1, 0xFFFF, 0xFFFF);
    else
        func_0800A594(id);
}
