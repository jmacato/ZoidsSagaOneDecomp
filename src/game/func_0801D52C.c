#include "types.h"

extern struct
{
    u8 pad_0[0x90];
    u32 x;
    u32 y;
} D_03004BBC;

void func_0805EE78(s32);
void func_08016CA8(s32, s32, s32);

void func_0801D52C(void)
{
    while (1)
    {
        func_0805EE78(0x1E);
        func_08016CA8(3, (D_03004BBC.x >> 21) + 1, (D_03004BBC.y >> 21) - 1);
    }
}
