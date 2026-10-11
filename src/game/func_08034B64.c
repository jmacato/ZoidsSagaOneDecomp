#include "types.h"

struct Unit
{
    u8 pad_0[4];
    u32 flags;
    u8 pad_8[0xC0];
    void *sprite;
    u8 portrait;
    u8 hidden;
    u8 pad_CE[6];
    u32 field_D4;
    u32 field_D8;
    u8 pad_DC[0x18];
    u8 active;
    u8 slot;
    u8 pad_F6[0x1D6];
};

struct Units
{
    u8 pad_0[4];
    struct Unit units[6];
};

struct Slot
{
    u8 pad_0[4];
    u16 sprite;
    u8 pad_6[0xA];
};

struct Sprite
{
    u8 data[0x88];
};

extern struct Sprite D_03004BBC[];
extern const struct Slot D_0866B2E0[2][6];
extern const u8 D_0866B3A0[];

void func_08034B64(struct Units *side)
{
    u8 i;

    for (i = 0; i < 6; i++)
    {
        side->units[i].flags = 0;
        side->units[i].hidden = 0;
        side->units[i].sprite = &D_03004BBC[D_0866B2E0[1][i].sprite];
        side->units[i].active = 1;
        side->units[i].slot = i;
        side->units[i].field_D8 = 0;
        side->units[i].field_D4 = 0;
        side->units[i].portrait = D_0866B3A0[i];
    }
}
