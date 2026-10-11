#include "types.h"

struct Stats
{
    u32 data[4];
};

struct Sub
{
    u8 pad_0[6];
    u16 zoid;
};

struct Unit
{
    u8 pad_0[4];
    u32 field_4;
    struct Sub sub;
    u8 pad_10[0x2A];
    s16 field_3A;
    u8 pad_3C[4];
    struct Stats stats;
    u8 pad_50[0x78];
    void *sprite;
    u8 portrait;
    u8 field_CD;
    u8 target;
    u8 pad_CF;
    u16 field_D0;
    u8 pad_D2[0x22];
    u8 enemy;
    u8 slot;
    u8 pad_F6[0x1D6];
};

struct Units
{
    u8 pad_0[4];
    struct Unit units[6];
};

struct TeamZoid
{
    u8 pad_0[0x11];
    u8 field_11;
    u8 pad_12[0xA];
};

struct Slot
{
    u8 id;
    u8 pad_1[3];
};

struct Team
{
    u8 pad_0[0x150];
    struct TeamZoid zoids[7];
    struct Slot slots[6];
    u8 pad_22C[0xA];
    u8 pilots[6];
};

extern struct
{
    u8 pad_0[0x361C];
    struct Team teams[3];
    u8 pad_[0x3F0D - 0x361C - 3 * 0x23C];
    u8 team;
} D_02000B5C;

struct Def
{
    u8 pad_0[4];
    u16 sprite;
    u8 pad_6[0xA];
};

extern u8 D_03004BBC[][0x88];
extern const struct
{
    struct Def allies[6];
    struct Def enemies[6];
} D_0866B2E0;
extern const u8 D_0866B3A0[];

void func_0802B978(struct Sub *, struct TeamZoid *);
void func_0802BA24(struct Sub *, struct Unit *);
struct Stats *func_080334F8(u8);

void func_0802F480(struct Units *side)
{
    struct Team *team = &D_02000B5C.teams[D_02000B5C.team];
    struct Slot *slots = team->slots;
    u16 i;

    for (i = 0; i < 6; i++)
    {
        struct Slot *slot = &slots[i];

        if (slot->id != 0xFF)
        {
            struct TeamZoid *zoid;

            side->units[i].field_4 = 0;
            zoid = &team->zoids[slot->id];
            func_0802B978(&side->units[i].sub, zoid);
            side->units[i].field_D0 = side->units[i].field_3A >> 1;
            side->units[i].stats = *func_080334F8(team->pilots[slot->id]);
            side->units[i].field_CD = zoid->field_11;
            func_0802BA24(&side->units[i].sub, &side->units[i]);
            side->units[i].sprite = D_03004BBC[D_0866B2E0.enemies[i].sprite];
            side->units[i].enemy = 1;
            side->units[i].slot = i;
            side->units[i].portrait = D_0866B3A0[i];
            side->units[i].target = 0xFF;
        }
        else
            side->units[i].sub.zoid = 0xFF;
    }
}
