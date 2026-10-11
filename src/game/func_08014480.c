#include "types.h"

extern struct
{
    u8 pad_0[0xE8];
    u16 field_E8;
} D_03004BBC;

extern struct
{
    u8 pad_0[8];
    u16 flags;
} D_02000000;

u32 func_08008434(s32, s32, s32);

s32 func_08014480(void)
{
    s32 result;

    if (func_08008434(1, 0, 0) & 0x1000)
    {
        D_03004BBC.field_E8 = 1;
        D_02000000.flags |= 2;
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}
