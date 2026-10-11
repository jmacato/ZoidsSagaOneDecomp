#include "types.h"

struct Zoid
{
    u16 flags;
    u8 pad_2[0x36];
};

struct Pilot
{
    u16 flags;
    u8 zoid;
    u8 pad_3;
};

struct Slot
{
    u8 pad_0[2];
    u16 id;
};

struct Owner
{
    u8 pad_0[0x10];
    struct Slot slots[3];
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[1];
    u8 pad_D64[0x34A4 - 0xD64];
    struct Pilot pilots[0x57];
} D_02000B5C;

void func_08037578(struct Owner *, u8);

s32 func_080374E4(void)
{
    s32 ok = 1;
    u8 i;

    for (i = 0; i <= 0x56; i++)
    {
        if ((D_02000B5C.pilots[i].flags & 2) && !(D_02000B5C.zoids[D_02000B5C.pilots[i].zoid].flags & 0x800))
        {
            ok = 0;
            break;
        }
    }
    return ok;
}

void func_08037548(struct Owner *owner)
{
    u16 i;

    for (i = 0; i <= 2; i++)
    {
        if (owner->slots[i].id != 0xFFFF)
            func_08037578(owner, i);
    }
}
