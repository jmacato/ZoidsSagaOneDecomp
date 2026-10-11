#include "types.h"

struct Stats
{
    u32 data[4];
};

struct Unit
{
    u8 pad_0[0xE];
    u16 zoid;
    u8 pad_10[0x20];
    u32 value;
    u8 pad_34[0xC];
    struct Stats stats;
    u8 pad_50[0x78];
    void *sprite;
    u8 portrait;
    u8 pad_CD;
    u8 target;
    u8 pad_CF[0x1FD];
};

struct Units
{
    u8 pad_0[4];
    struct Unit units[6];
};

struct Zoid
{
    u8 pad_0[0x28];
    u8 data[0x10];
};

struct Entry
{
    u8 zoid;
    u8 pilot;
    u8 pad_2[2];
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

struct Save
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[1];
    u8 pad_D64[0x3600 - 0xD64];
    struct Entry entries[6];
};

extern struct Save D_02000B5C;

extern struct Sprite D_03004BBC[];
extern const struct Slot D_0866B2E0[];
extern const u8 D_0866B3A0[];

void func_0805D270(const void *, void *, u32);
void func_08036C1C(u8, u8, void *);
void func_0802B6E0(struct Zoid *, struct Unit *, s32, u8);
struct Stats *func_080334F8(u8);

void func_0802B5D0(struct Units *side, u8 slot)
{
    vu16 zero = 0;
    struct Unit *unit = &side->units[slot];
    u8 id;
    u8 zoid;

    func_0805D270((void *)&zero, unit, 0x01000166);
    id = D_02000B5C.entries[slot].pilot;
    zoid = D_02000B5C.entries[slot].zoid;
    if (zoid != 0xFF)
    {
        u32 value;

        func_08036C1C(id, zoid, D_02000B5C.zoids[zoid].data);
        func_0802B6E0(&D_02000B5C.zoids[zoid], unit, 0, slot);
        value = side->units[slot].value;
        func_08036C1C(0xFF, zoid, &unit->value);
        side->units[slot].value = value;
        side->units[slot].sprite = &D_03004BBC[D_0866B2E0[slot].sprite];
        side->units[slot].stats = *func_080334F8(D_02000B5C.entries[slot].pilot);
        side->units[slot].portrait = D_0866B3A0[slot];
        side->units[slot].target = 0xFF;
    }
    else
        side->units[slot].zoid = zoid;
}
