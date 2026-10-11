#include "types.h"

struct Option
{
    u16 cond;
    u16 value;
};

struct Action
{
    u16 id;
    u8 pad_2[2];
    struct Option options[3];
    u8 pad_10[12];
};

struct Slot
{
    u8 group;
    u8 index;
    u8 pad_2[2];
};

struct Enemy
{
    u8 group;
    u8 index;
    u8 pad_2[2];
    struct Slot slots[7];
    u8 field_20;
    u8 field_21;
    u8 pad_22[2];
};

extern struct
{
    u8 pad_0[0x22A8];
    u8 field_22A8;
    s8 field_22A9;
    s8 option;
    s8 action;
} D_0200EB84;

extern struct
{
    u16 flags;
    u8 enemy;
} D_02005C70;

extern struct Enemy D_02004A70[];
extern struct Action D_086787A4[][32];
extern struct Action D_086764A4[][32];

u16 func_08001080(void);

void func_0803666C(void)
{
    u8 list[6];
    u8 count;
    u8 i;
    u8 fallback;
    u16 r;
    struct Action *action;

    D_0200EB84.field_22A8 = 0xFF;
    D_0200EB84.field_22A9 = -1;
    D_0200EB84.option = -1;
    D_0200EB84.action = -1;
    if (D_02005C70.flags & 1)
        return;
    D_0200EB84.field_22A8 = D_02004A70[D_02005C70.enemy].field_20;
    D_0200EB84.field_22A9 = D_02004A70[D_02005C70.enemy].field_21;
    fallback = 0;
    count = 0;
    for (i = 0; i < 6; i++)
    {
        if (D_02004A70[D_02005C70.enemy].slots[i].index != 0xFF)
        {
            list[count] = i;
            count++;
        }
    }
    if (count == 0)
        fallback = 1;
    else
    {
        count++;
        r = func_08001080() % count;
        if (r == 0)
            fallback = 1;
        else
            i = list[r - 1];
    }
    if (fallback == 1)
        action = &D_086787A4[D_02004A70[D_02005C70.enemy].group][D_02004A70[D_02005C70.enemy].index];
    else
        action = &D_086764A4[D_02004A70[D_02005C70.enemy].slots[i].group][D_02004A70[D_02005C70.enemy].slots[i].index];
    D_0200EB84.action = action->id;
    r = func_08001080() % 3U;
    if (r > 2)
        r = 0;
    if (action->options[r].value != 0xFFFF && action->options[r].cond)
        D_0200EB84.option = action->options[r].value;
}
