#include "types.h"

struct Unit
{
    u8 pad_0[0x10];
    u16 flags;
    u8 pad_12[4];
    u16 kind;
    u8 pad_18[0x2B4];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Turn
{
    u8 side;
    u8 slot;
    u8 pad_2[2];
};

extern struct
{
    struct Side sides[2];
    u8 pad_21B0[5];
    u8 current;
    u8 pad_21B6[2];
    struct Turn turns[1];
} D_0200EB84;

struct Kind
{
    const void *palette;
    u8 pad_4[0x48];
};

struct Def
{
    u8 palette;
    u8 pad_1[0xF];
};

extern const struct Kind D_086700A0[];
extern const struct Def D_0866B2E0[2][6];

s32 func_08032A88(u8, u8);
void func_0805D270(const void *, void *, u32);
void func_08031E90(u8 *, u8, u8);

void func_08031D50(void)
{
    u8 palette[32];
    u8 side;
    u8 i;

    for (side = 0; side < 2; side++)
    {
        for (i = 0; i < 6; i++)
        {
            if (func_08032A88(side, i))
            {
                if (!(D_0200EB84.sides[side].units[i].flags & 0x4000))
                {
                    if (D_0200EB84.turns[D_0200EB84.current].slot != i || D_0200EB84.turns[D_0200EB84.current].side != side)
                    {
                        func_0805D270(D_086700A0[D_0200EB84.sides[side].units[i].kind].palette, palette, 0x10);
                        func_08031E90(palette, 0xC, 0x1D);
                        func_0805D270(palette, (void *)(0x05000200 + D_0866B2E0[side][i].palette * 32), 0x10);
                    }
                    else
                        func_0805D270(D_086700A0[D_0200EB84.sides[side].units[i].kind].palette, (void *)(0x05000200 + D_0866B2E0[side][i].palette * 32), 0x10);
                }
                else
                {
                    func_0805D270(D_086700A0[D_0200EB84.sides[side].units[i].kind].palette, palette, 0x10);
                    func_08031E90(palette, 0x18, 0x1D);
                    func_0805D270(palette, (void *)(0x05000200 + D_0866B2E0[side][i].palette * 32), 0x10);
                }
            }
        }
    }
}
