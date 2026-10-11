#include "types.h"

extern struct
{
    u8 pad_0[0xE4];
    u16 field_E4;
    u8 pad_E6[4];
    u16 field_EA;
} D_03004BBC;

s32 func_080089A0(s32, s32);

s32 func_08008A94(void)
{
    if (D_03004BBC.field_EA == 1 && D_03004BBC.field_E4 == 6)
        return func_080089A0(1, 150);
}
