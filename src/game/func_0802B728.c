#include "types.h"

struct Stats
{
    u32 data[4];
};

struct Sub
{
    u16 flags;
    u8 pad_2[4];
    u16 zoid;
};

struct Unit
{
    u8 pad_0[4];
    u32 field_4;
    struct Sub sub;
    u32 field_10;
    u8 pad_14[0x1C];
    u32 field_30;
    u8 pad_34[6];
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
    u8 pad_D2[2];
    u32 field_D4;
    u32 field_D8;
    u8 pad_DC[0x18];
    u8 enemy;
    u8 slot;
    u8 pad_F6[0x1D6];
};

struct Units
{
    u8 pad_0[4];
    struct Unit units[6];
};

struct Data
{
    u8 pad_0[0x10];
    u8 pilot;
    u8 field_11;
    u8 pad_12[2];
    u32 field_14;
    u32 field_18;
};

struct Pair
{
    u8 table;
    u8 index;
    u8 pad_2[2];
};

struct Entry
{
    struct Pair head;
    struct Pair pairs[8];
};

extern struct
{
    struct Entry entries[127];
    u8 pad_11DC[4];
    struct Pair extra[6];
} D_02004A70;

extern struct
{
    u16 flags;
    u8 entry;
} D_02005C70;

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
extern struct Data D_086787A4[][32];
extern struct Data D_086764A4[][32];
extern struct Data D_0867C534[][6];

void func_0802B978(struct Sub *, struct Data *);
void func_0802BA24(struct Sub *, struct Unit *);
struct Stats *func_080334F8(u8);
void func_08036E60(u8, struct Sub *, u32 *);

void func_0802B728(struct Units *side)
{
    u16 i;
    register u32 one asm("r0");

    for (i = 0; i < 6; i++)
    {
        u8 id;
        struct Data *data;

        if (!(D_02005C70.flags & 1))
        {
            if (i == 4)
                id = D_02004A70.entries[D_02005C70.entry].head.index;
            else
                id = D_02004A70.entries[D_02005C70.entry].pairs[i].index;
        }
        else
            id = D_02004A70.extra[i].index;
        if (id != 0xFF)
        {
            if (!(D_02005C70.flags & 1))
            {
                if (i == 4)
                    data = &D_086787A4[D_02004A70.entries[D_02005C70.entry].head.table][id];
                else
                    data = &D_086764A4[D_02004A70.entries[D_02005C70.entry].pairs[i].table][id];
            }
            else
                data = &D_0867C534[D_02005C70.entry][id];
            side->units[i].field_4 = 0;
            func_0802B978(&side->units[i].sub, data);
            if ((D_02005C70.flags & 1) && D_02004A70.extra[i].table == 1)
                side->units[i].sub.flags |= 0x200;
            side->units[i].field_CD = data->field_11;
            func_0802BA24(&side->units[i].sub, &side->units[i]);
            side->units[i].stats = *func_080334F8(data->pilot);
            func_08036E60(data->pilot, &side->units[i].sub, &side->units[i].field_30);
            side->units[i].field_10 = side->units[i].field_30;
            side->units[i].field_D0 = side->units[i].field_3A >> 1;
            side->units[i].sprite = D_03004BBC[D_0866B2E0.enemies[i].sprite];
            asm("" : "=r"(one) : "0"(1), "m"(side->units[i].enemy));
            side->units[i].enemy = one;
            side->units[i].slot = i;
            side->units[i].field_D8 = data->field_18;
            side->units[i].field_D4 = data->field_14;
            side->units[i].portrait = D_0866B3A0[i];
            side->units[i].target = 0xFF;
        }
        else
            side->units[i].sub.zoid = id;
    }
}
