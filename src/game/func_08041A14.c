#include "types.h"

struct Sprite
{
    u16 id;
    u8 kind;
    u8 flags;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u16 field_C;
    u16 field_E;
    u8 pad_10[2];
    u16 field_12;
    u8 pad_14;
    u8 field_15;
    u8 side;
    u8 slot;
    void *data;
};

struct Part
{
    u16 level;
    u16 id;
};

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[4];
    u16 zoid;
    u8 pad_10[8];
    struct Part parts[6];
    u8 pad_30[0xD];
    u8 kind;
    u8 pad_3E[4];
    u8 field_42;
    u8 pad_43[0x289];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8;
    u8 code;
    u8 pad_10CA[0xE];
};

extern struct
{
    u8 pad_0[8];
    struct Side sides[2];
    u8 pad_21B8[0x34];
    u8 mode;
    u8 stage;
} D_0200EB84;

extern struct Sprite D_0200D920[];
extern u8 D_0200DA7C;
extern u8 D_0200DA91;
extern u8 D_0200E24B;
extern const u16 D_086E7756[][14];

u8 func_08041938(u8 code);
/* Keep the result wide until the descriptor call truncates it. */
u32 func_080419C0(u8 code, u16 flags);
void region_0804181C(u16 index, u16 id, u8 kind, u8 flags, u16 x, u16 y, u16 width, u16 height, u16 field_C,
                     u16 field_E, u16 field_12, void *data);
void func_0804188C(u16 index, struct Sprite *sprite);
u8 func_08032A88(u8, u8);

void func_08041A14(void)
{
    u16 parts[6];
    u16 i;
    u16 j;
    u16 zoid;
    u8 kind;
    u32 code;
    u16 flags;
    u8 field;
    u32 code2;
    u16 *second_parts;
    u32 next;

    switch (D_0200EB84.mode)
    {
    case 0:
        D_0200DA7C = D_0200EB84.stage;
        D_0200DA91 = 0;
        break;
    case 1:
    {
        register u8 *destination asm("r2") = &D_0200DA7C;
        register u32 side_flag asm("r1");
        asm("" : : "r"(destination));
        side_flag = 0x20;
        asm("" : : "r"(side_flag));
        *destination = (D_0200EB84.stage + 6) | side_flag;
        D_0200DA91 = side_flag;
        break;
    }
    }
    for (i = 0; i < 6; i++)
    {
        asm("" : : : "r9");
        zoid = D_0200EB84.sides[0].units[i].zoid;
        asm("" : : : "r8");
        kind = D_0200EB84.sides[0].units[i].kind;
        code = func_08041938(D_0200EB84.sides[0].code);
        flags = D_0200EB84.sides[0].units[i].flags;
        field = D_0200EB84.sides[0].units[i].field_42;
        if (!func_08032A88(0, i))
        {
            func_0804188C(i, &D_0200D920[i]);
            continue;
        }
        if (kind > 2)
            kind = 0;
        for (j = 0; j < 6; j++)
        {
            parts[j] = 0;
            parts[j] = D_0200EB84.sides[0].units[i].parts[j].id;
            if (D_086E7756[zoid][j] == 0)
                parts[j] = 0;
            if (parts[j] == 0xFFFF)
                parts[j] = 0;
        }
        region_0804181C(i, zoid, kind, func_080419C0(code, flags), parts[0], parts[1], parts[2], parts[3], parts[4],
                        parts[5], i, &D_0200D920[i]);
        D_0200D920[i].field_15 = field;
        D_0200D920[i].side = 0;
        D_0200D920[i].slot = i;
    }
    i = 0;
    second_parts = parts;
    asm("" : : "r"(second_parts));
    for (; i < 6; i = (u16)next)
    {
        zoid = D_0200EB84.sides[1].units[i].zoid;
        kind = D_0200EB84.sides[1].units[i].kind;
        code2 = func_08041938(D_0200EB84.sides[1].code);
        flags = D_0200EB84.sides[1].units[i].flags;
        field = D_0200EB84.sides[1].units[i].field_42;
        if (!func_08032A88(1, i))
        {
            func_0804188C(i + 6, &D_0200D920[6 + i]);
            next = i + 1;
            continue;
        }
        if (kind > 2)
            kind = 0;
        {
            u32 render_flags;
            u32 row;
            u32 zoid_times_eight;
            register u32 shifted_code asm("r12");
            j = 0;
            row = (u32)i << 3;
            asm("" : : "r"(j), "r"(row));
            zoid_times_eight = (u32)zoid << 3;
            asm("" : "+r"(zoid_times_eight));
            shifted_code = code2 << 24;
            asm("" : "+r"(shifted_code));
            next = i + 1;
            for (; j < 6; j++)
            {
                parts[j] = 0;
                parts[j] = D_0200EB84.sides[1].units[i].parts[j].id;
                if (*(const u16 *)((const u8 *)D_086E7756 + ((zoid_times_eight - zoid) << 2) + (j << 1)) == 0)
                    parts[j] = 0;
                if (parts[j] == 0xFFFF)
                    parts[j] = 0;
            }
            render_flags = func_080419C0(shifted_code >> 24, flags);
            asm("" : : "r"((u16)(i + 6)));
            region_0804181C(i + 6, zoid, kind, render_flags, second_parts[0], second_parts[1], second_parts[2], second_parts[3],
                            second_parts[4], second_parts[5], i, (struct Sprite *)((u8 *)&D_0200D920[6] + ((row - i) << 2)));
        }
        D_0200D920[i + 6].field_15 = field;
        D_0200D920[i + 6].side = 1;
        D_0200D920[i + 6].slot = i;
    }
    D_0200E24B = 0;
}
