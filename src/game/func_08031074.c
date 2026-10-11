#include "types.h"

struct Side
{
    u8 pad_0[0x10C9];
    u8 zoid;
    u8 pad_10CA[0xE];
};

struct Art
{
    const void *palette;
    const void *tiles;
    const u8 *map;
    const void *palette2;
    const void *tiles2;
    const u8 *map2;
};

struct Entry
{
    u8 zoid;
    u8 pilot;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[8];
    struct Side sides[2];
} D_0200EB84;

extern struct
{
    u8 pad_0[0x3600];
    struct Entry entries[6];
} D_02000B5C;

extern struct
{
    u8 pad_0[8];
    s32 field_8;
} D_03004B9C;

extern const u8 D_0832D3D0[];
extern const u8 D_0832B3D0[];
extern const u8 D_0832D5D0[];
extern const u8 D_08675BEC[];
extern const u8 D_0866B7E0[];
extern const u8 D_0836BA28[];
extern const u8 D_0836BB44[];
extern struct Art D_0866B588[];
extern u16 D_0300239C[];

void func_0805D270(const void *, void *, u32);
void func_0805D288(const void *, void *);
void func_080011F0(const u8 *, s32, s32, s32, s32, s32, s32, s32);
void func_0803E488(const u8 *, s32);
void func_0803E134(s32, s32, s32, s32);
void func_08032818(u32);
void func_0805EE78(s32);
void func_080312F8(u8, u8, u8);
void func_0802F07C(void);

void func_08031074(void)
{
    u8 zoid0 = D_0200EB84.sides[0].zoid;
    u8 zoid1 = D_0200EB84.sides[1].zoid;
    u8 count;
    u8 i;
    u8 j;
    vu16 fill;

    func_0805D270(D_0832D3D0, (void *)0x05000000, 0x10);
    func_0805D270(D_0832B3D0, (void *)0x0600C000, 0x1000);
    func_080011F0(D_0832D5D0, 0x1E, 0x14, 0, 0, 0, 0, 0x1000);
    func_0805D270(D_0866B588[zoid0].palette, (void *)0x05000020, 0x10);
    func_0805D270(D_0866B588[zoid0].tiles, (void *)0x06008000, 0x1000);
    func_080011F0(D_0866B588[zoid0].map + 0x3C, 0xF, 0x12, 0xF, 2, 0, 1, 0x800);
    func_0805D270(D_0866B588[zoid1].palette2, (void *)0x05000040, 0x10);
    func_0805D270(D_0866B588[zoid1].tiles2, (void *)0x0600A000, 0x1000);
    func_080011F0(D_0866B588[zoid1].map2 + 0x3C, 0xF, 0x12, 0, 2, 0x100, 2, 0x800);
    *(vu16 *)0x0400000A = 4;
    count = 0;
    for (i = 0; i <= 5; i++)
    {
        if (D_02000B5C.entries[i].zoid != 0xFF)
        {
            func_0803E488(D_08675BEC, 1);
            func_0803E134(1, 0x56, 0, 4);
            fill = 0x1111;
            func_0805D270((void *)&fill, (void *)0x060052C0, 0x01000080);
            func_0803E488(D_0866B7E0, 0);
            func_08032818(D_02000B5C.entries[i].pilot);
            func_0805EE78(1);
            func_0805D270((void *)0x060052C0, (void *)(0x06004000 + (count << 8)), 0x80);
            func_0803E488(D_08675BEC, 1);
            count++;
        }
    }
    fill = 0x56;
    func_0805D270((void *)&fill, D_0300239C, 0x01000400);
    func_0805D288(D_0836BA28, (void *)0x06004600);
    j = count - 1;
    for (i = 5; i <= 5; i--)
    {
        if (D_02000B5C.entries[i].zoid != 0xFF)
        {
            func_080312F8(j, i, count);
            j--;
        }
    }
    func_0802F07C();
    if (count == 6)
        D_03004B9C.field_8 = 0x40000;
    else
        D_03004B9C.field_8 = 0;
    func_0805EE78(4);
    {
        vu32 *dma = (vu32 *)0x040000D4;

        dma[0] = (u32)D_0836BB44;
        dma[1] = 0x050001C0;
        dma[2] = 0x80000010;
        dma[2];
    }
}
