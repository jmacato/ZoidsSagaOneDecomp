#include "types.h"

struct Zoid
{
    u8 pad_0[6];
    u16 kind;
    u8 pad_8[0x30];
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
    struct Zoid zoids[180];
    u8 pad_348C[0x18];
    struct Pilot pilots[16];
} D_02000B5C;

struct Part
{
    u16 flags;
    u16 id;
};

struct Info
{
    u8 pad_0[8];
    struct Part parts[17];
};

extern struct Info D_0867006C[];
extern u8 D_0875B304[];
extern u8 D_0875AFB8[];

void func_0803E488(u8 *, s32);
void func_0804DF38(u8, s16);

void func_0804DFB8(u8 slot, s16 index)
{
    struct Info *info = &D_0867006C[D_02000B5C.zoids[D_02000B5C.pilots[slot].zoid].kind];
    s32 mode = info->parts[index].flags & 3;

    if (mode != 0 || info->parts[index].id != 0xFFFF)
    {
        switch (mode)
        {
        case 1:
            func_0803E488(D_0875B304, 2);
            break;
        case 2:
            func_0803E488(D_0875B304, 3);
            break;
        case 3:
            func_0803E488(D_0875B304, 4);
            break;
        default:
            func_0803E488(D_0875B304, 6);
            break;
        }
        func_0803E488(D_0875AFB8, 0x29);
        func_0804DF38(slot, index);
    }
    else
    {
        func_0803E488(D_0875AFB8, 0x29);
        func_0803E488(D_0875B304, 0);
    }
}
