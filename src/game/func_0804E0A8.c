#include "types.h"

struct Part
{
    u16 flags;
    u16 id;
};

struct Zoid
{
    u8 pad_0[6];
    u16 kind;
    u8 pad_8[8];
    struct Part slots[9];
    u8 pad_34[4];
};

struct Kind
{
    u8 pad_0[8];
    struct Part parts[0x11];
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[1];
} D_02000B5C;

extern const struct Kind D_0867006C[];
extern const u8 D_0875B304[];
extern const u8 D_0875AFB8[];
extern const u8 D_0866634C[];

void func_0803E488(const u8 *, s32);

void func_0804E0A8(u8 zoid, s16 part)
{
    const struct Kind *kind = &D_0867006C[D_02000B5C.zoids[zoid].kind];

    if ((kind->parts[part].flags & 3) != 0 || kind->parts[part].id != 0xFFFF)
    {
        switch (kind->parts[part].flags & 3)
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
        if (D_02000B5C.zoids[zoid].slots[part].id != 0xFFFF)
            func_0803E488(D_0866634C, D_02000B5C.zoids[zoid].slots[part].id);
        else
            func_0803E488(D_0875B304, 1);
    }
    else
    {
        func_0803E488(D_0875B304, 5);
        func_0803E488(D_0875AFB8, 0x29);
        func_0803E488(D_0875B304, 0);
    }
}
