#include "types.h"

extern struct
{
    u8 pad_0[0x10];
    s32 x;
    s32 y;
} D_03004B9C;

void func_0805EE78(s32);

void func_08053524(void)
{
    while (1)
    {
        D_03004B9C.x -= 0x10000;
        D_03004B9C.y += 0x10000;
        func_0805EE78(1);
    }
}
