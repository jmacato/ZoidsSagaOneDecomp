#include "types.h"

struct Zoid
{
    u16 flags;
    u8 pad_2[6];
    s32 x;
    s32 y;
    u8 pad_10[0x18];
    s32 home_x;
    s32 home_y;
    u8 pad_30[8];
};

struct Pilot
{
    u8 pad_0[2];
    u8 zoid;
    u8 pad_3;
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[1];
    u8 pad_D64[0x34A4 - 0xD64];
    struct Pilot pilots[1];
} D_02000B5C;

u8 func_080374E4(void);

void func_0803747C(void)
{
    if (func_080374E4())
    {
        u8 zoid = D_02000B5C.pilots[0].zoid;

        D_02000B5C.zoids[zoid].x = D_02000B5C.zoids[zoid].home_x;
        D_02000B5C.zoids[zoid].y = D_02000B5C.zoids[zoid].home_y;
        D_02000B5C.zoids[zoid].flags &= 0xF7FF;
    }
}
