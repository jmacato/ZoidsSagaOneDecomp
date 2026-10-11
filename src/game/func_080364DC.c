#include "types.h"

struct Zoid
{
    u16 flags;
    u8 pad_2[6];
    s32 x;
    s32 y;
    u8 pad_10[0x18];
    u8 field_28[0xC];
    u8 level;
    u8 pad_35[3];
};

struct Entry
{
    u8 zoid;
    u8 unit;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[180];
    u8 pad_348C[0x174];
    struct Entry entries[6];
} D_02000B5C;

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[6];
    s32 x;
    s32 y;
    u8 pad_18[0x2B4];
};

extern struct
{
    struct Unit units[12];
    u8 pad_2190[0x50];
    u8 mode;
} D_0200EB8C;

u8 func_080365C8(s32, u8);
void func_08037A88(u8);
void func_08036C1C(u8, u8, u8 *);

void func_080364DC(void)
{
    u8 i;

    for (i = 0; i <= 5; i++)
    {
        if (D_02000B5C.entries[i].zoid != 0xFF)
        {
            struct Zoid *zoid = &D_02000B5C.zoids[D_02000B5C.entries[i].zoid];
            u8 slot = func_080365C8(0, D_02000B5C.entries[i].unit);
            struct Unit *unit;

            if (slot == 0xFF || ((unit = &D_0200EB8C.units[slot])->flags & 0x800))
            {
                zoid->x = 0;
                zoid->y = 0;
                zoid->flags |= 0x800;
                func_08037A88(i);
            }
            else
            {
                zoid->x = unit->x;
                zoid->y = unit->y;
                if (D_0200EB8C.mode == 1)
                {
                    if (++zoid->level > 99)
                        zoid->level = 100;
                    func_08036C1C(D_02000B5C.entries[i].unit, D_02000B5C.entries[i].zoid, D_02000B5C.zoids[D_02000B5C.entries[i].zoid].field_28);
                }
            }
        }
    }
}
