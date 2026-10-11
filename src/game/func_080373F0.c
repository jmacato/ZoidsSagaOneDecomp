#include "types.h"

struct Zoid
{
    u8 pad_0[2];
    u8 kind;
    u8 pad_3[0x35];
};

struct Pilot
{
    u8 pad_0[2];
    u8 zoid;
    u8 pad_3;
};

extern struct
{
    u8 pad_0[0xD30];
    struct Zoid zoids[1];
    u8 pad_D68[0x34A4 - 0xD68];
    struct Pilot pilots[1];
} D_02000B5C;

u8 func_080373F0(u8 index)
{
    u8 zoid = D_02000B5C.pilots[index].zoid;

    if (zoid == 0xFF)
        return 0xFF;
    return D_02000B5C.zoids[zoid].kind;
}
