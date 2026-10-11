#include "types.h"

struct Zoid
{
    u8 pad_0[2];
    u16 flags;
    u8 pad_4[0x34];
};

struct Pilot
{
    u16 flags;
    u8 zoid;
    u8 pad_3;
};

struct Entry
{
    u8 zoid;
    u8 pilot;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[1];
    u8 pad_D64[0x34A4 - 0xD64];
    struct Pilot pilots[1];
    u8 pad_34A8[0x3600 - 0x34A8];
    struct Entry entries[6];
} D_02000B5C;

void func_08037A88(u8 position)
{
    u8 pilot = D_02000B5C.entries[position].pilot;
    u8 zoid;

    D_02000B5C.entries[position].pilot |= 0xFF;
    zoid = D_02000B5C.entries[position].zoid;
    D_02000B5C.entries[position].zoid |= 0xFF;
    D_02000B5C.zoids[zoid].flags &= 0xFFFD;
    D_02000B5C.pilots[pilot].flags &= 0xFFEF;
}
