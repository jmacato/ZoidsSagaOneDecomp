#include "types.h"

struct Block
{
    u32 data[4];
};

struct Pilot
{
    u8 pad_0[2];
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
    u8 pad_0[2];
    u8 field_2;
    u8 pad_3[0xCCF];
    u8 field_CD2;
    u8 pad_CD3[5];
    struct Block blocks[4];
    u8 pad_D18[0x10];
    u32 money;
    u8 pad_D2C[0x33E2 - 0xD2C];
    u8 items[0xC2];
    struct Pilot pilots[0x57];
    u8 pad_3600[0];
    struct Entry entries[6];
    u8 field_3618;
} D_02000B5C;

extern const struct Block D_0867AAA4;
extern const struct Block D_0867AAB4;
extern const struct Block D_0867AAC4;
extern const struct Block D_0867AAD4;
extern u8 D_02003FF8[];
extern u8 D_02003EA8[];
extern u8 D_02003E61[];
extern u8 D_02003E68[];

void func_0805D270(const void *, void *, u32);
void func_0803723C(s32, s32, s32);
void func_080377C4(s32);
void func_0803699C(u16, s32);
void func_0803702C(u16);

void func_08003948(void)
{
    vu16 zero;
    u16 i;

    zero = 0;
    func_0805D270((void *)&zero, &D_02000B5C, 0x01001F88);
    D_02000B5C.money = 0;
    D_02000B5C.field_2 = 0;
    func_0803723C(0, 2, 0);
    D_02000B5C.field_3618 = 2;
    D_02000B5C.field_CD2 = 1;
    D_02000B5C.blocks[0] = D_0867AAA4;
    D_02000B5C.blocks[1] = D_0867AAB4;
    D_02000B5C.blocks[2] = D_0867AAC4;
    D_02000B5C.blocks[3] = D_0867AAD4;
    for (i = 0; i <= 0x56; i++)
        D_02000B5C.pilots[i].zoid |= 0xFF;
    for (i = 0; i <= 5; i++)
    {
        D_02000B5C.entries[i].pilot |= 0xFF;
        D_02000B5C.entries[i].zoid |= 0xFF;
    }
    for (i = 0; i <= 5; i++)
        D_02003FF8[i] |= 0xFF;
    func_080377C4(0);
}

void func_08003A64(void)
{
    u16 i;

    D_02000B5C.money = 9999999;
    for (i = 2; i <= 0x95; i++)
    {
        if (i != 0x53 && i != 0x54 && i != 0x57 && i != 0x75)
            func_0803699C(i, 0);
        D_02000B5C.items[i] = 1;
    }
    func_0803723C(4, 2, 0);
    func_0803723C(5, 2, 0);
    func_0803723C(6, 2, 0);
    func_0803723C(7, 2, 0);
    for (i = 0; i <= 0x20; i++)
        func_0803702C(i);
    for (i = 0; i <= 0x80; i++)
        D_02003EA8[i] = 6;
    for (i = 0; i <= 6; i++)
        D_02003E61[i] = 50;
    for (i = 0; i <= 0x3F; i++)
        D_02003E68[i] = 50;
}
