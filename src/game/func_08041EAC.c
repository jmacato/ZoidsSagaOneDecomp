#include "types.h"

struct Line
{
    u16 x;
    u16 y;
};

extern vu8 D_0200DA99;
extern struct Line D_0200DAAC[];

void func_08041EAC(void)
{
    u16 line;

    D_0200DA99 = line = *(vu16 *)0x04000006;
    *(vu16 *)0x04000018 = D_0200DAAC[D_0200DA99].y;
    if ((u8)line > 0x90)
        *(vu16 *)0x04000018 = D_0200DAAC[1].y;
}
