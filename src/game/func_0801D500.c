#include "types.h"

extern struct
{
    u8 pad_0[0x90];
    u32 x;
    u32 y;
} D_03004BBC;

void func_0805EE78(s32);
void func_08016CA8(s32, s32, s32);

void func_0801D500(void)
{
    while (1)
    {
        func_0805EE78(12);
        func_08016CA8(2, (D_03004BBC.x >> 21) - 1, (D_03004BBC.y >> 21) + 1);
    }
}
