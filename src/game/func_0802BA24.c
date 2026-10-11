#include "types.h"

struct Equip
{
    u16 level;
    u16 id;
};

struct Source
{
    u8 pad_0[0x10];
    struct Equip equips[6];
};

struct Info
{
    u32 flags;
    u8 pad_4[4];
    u16 power;
    u8 pad_A[2];
    u32 effects;
    u16 range;
    u8 hits;
    u8 cost;
    u8 kind;
    u8 pad_15[3];
};

struct Part
{
    u32 flags;
    u16 power;
    u8 pad_6[2];
    u32 effects;
    u16 range;
    u8 hits;
    u8 ammo;
    u8 cost;
    u8 kind;
    u16 id;
};

struct Body
{
    u8 pad_0[0x50];
    struct Part parts[6];
    u8 pad_C8[0x14];
    struct Equip equips[6];
};

extern struct Info D_0866C754[];

void func_0805D270(const void *, void *, u32);
u8 func_0802BAF8(struct Info *);

void func_0802BA24(struct Source *src, struct Body *body)
{
    u16 i;

    for (i = 0; i < 6; i++)
    {
        vu16 zero = 0;
        struct Info *info;

        func_0805D270((void *)&zero, &body->parts[i], 0x0100000A);
        body->equips[i] = src->equips[i];
        body->parts[i].id = src->equips[i].id;
        if (body->parts[i].id != 0xFFFF)
        {
            info = &D_0866C754[src->equips[i].id];
            body->parts[i].flags = info->flags;
            body->parts[i].power = info->power;
            body->parts[i].effects = info->effects;
            body->parts[i].range = info->range;
            body->parts[i].hits = info->hits;
            body->parts[i].cost = info->cost;
            body->parts[i].ammo = func_0802BAF8(info);
            body->parts[i].kind = info->kind;
        }
    }
}
