#include "types.h"

struct Zoid
{
    u8 pad_0[6];
    u16 id;
    s32 x;
    s32 y;
    u8 pad_10[0x18];
    s32 home_x;
    s32 home_y;
    u8 pad_30[8];
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[0xAD];
} D_02000B5C;

void func_08030FFC(void)
{
    u8 i;

    for (i = 0; i <= 0xAC; i++)
    {
        if (D_02000B5C.zoids[i].id != 0)
        {
            D_02000B5C.zoids[i].x = D_02000B5C.zoids[i].home_x;
            D_02000B5C.zoids[i].y = D_02000B5C.zoids[i].home_y;
        }
    }
}
