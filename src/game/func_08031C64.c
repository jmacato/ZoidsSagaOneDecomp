#include "types.h"

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[4];
    u16 kind;
    u8 pad_10[0x2BC];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Info
{
    u8 pad_0[0x34];
    void *palette;
    u8 pad_38[0x14];
};

extern struct Side D_0200EB8C[];
extern struct Info D_0867006C[];
extern u8 D_0866B2E0[2][6][16];

s32 func_08032A88(u8, u8);
void func_0805D270(void *, void *, u32);
void func_08031E90(u16 *, s32, s32);

void func_08031C64(void)
{
    u8 side;
    u8 i;
    u16 buffer[16];

    for (side = 0; side <= 1; side++)
    {
        for (i = 0; i <= 5; i++)
        {
            if (func_08032A88(side, i))
            {
                struct Side *group = &D_0200EB8C[side];
                struct Unit *unit = &group->units[i];

                if (!(unit->flags & 0x4000))
                {
                    func_0805D270(D_0867006C[D_0200EB8C[side].units[i].kind].palette, (void *)(0x05000200 + D_0866B2E0[side][i][0] * 32), 0x10);
                }
                else
                {
                    func_0805D270(D_0867006C[unit->kind].palette, buffer, 0x10);
                    func_08031E90(buffer, 0x18, 0x1D);
                    func_0805D270(buffer, (void *)(0x05000200 + D_0866B2E0[side][i][0] * 32), 0x10);
                }
            }
        }
    }
}
