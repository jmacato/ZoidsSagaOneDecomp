#include "types.h"

extern u8 D_08675C5C[];
extern u8 D_08675DD4[];

void func_0803E488(u8 *, u8);
void func_08032888(u8);

void func_0803B6EC(u8 unit, u8 target)
{
    if (unit != 0xFF)
    {
        if (target != 0xFF)
            func_0803E488(D_08675C5C, 0x11);
        else
            func_0803E488(D_08675DD4, 0xC);
        func_08032888(unit);
    }
}
