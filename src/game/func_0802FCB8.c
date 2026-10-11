#include "types.h"

struct Item
{
    u8 pad_0;
    u8 used;
    u16 id;
    u8 pad_4[4];
};

struct Unit
{
    u8 pad_0[0xE];
    u16 zoid;
    u8 pad_10[0x138];
    struct Item items[48];
    u8 pad_2C8[4];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    struct Unit *unit;
    u32 side;
    u32 slot;
    u8 pad_14[4];
    s32 busy;
    u8 pad_1C[0xC];
    u8 index;
    u8 pad_29[3];
    u8 fade;
    u8 pad_2D[0x5B];
};

struct ZoidDef
{
    u8 pad_0[0x34];
    const u16 *palette;
    u8 pad_38[0x14];
};

struct SlotDef
{
    u8 palette;
    u8 pad_1[0xF];
};

extern struct Side D_0200EB8C[2];
extern struct ZoidDef D_0867006C[];
extern struct SlotDef D_0866B2E0[2][6];
extern u8 D_02000030;
extern struct Task D_02000034[];
extern const u8 D_08675BEC[];
extern const u8 D_08675D58[];
extern const u8 D_0866634C[];

extern struct
{
    u8 pad_0[0xC];
    u16 item;
} D_02007574;

void func_0805D270(const void *, void *, u32);
void func_08031E90(u16 *, u8, s32);
s32 func_08032A88(u8, u8);
void func_0803E488(const u8 *, s32);
void func_08004018(void);
void func_0805EE78(s32);

void func_0802FCB8(s32 unused, struct Task *task)
{
    struct Unit *unit = task->unit;
    u16 buffer[16];

    switch (task->state)
    {
    case 0:
        task->fade = 0x18;
        task->state = 100;
    case 100:
        func_0805D270(D_0867006C[unit->zoid].palette, buffer, 0x10);
        func_08031E90(buffer, task->fade, 0x1D);
        func_0805D270(buffer, (void *)(0x05000200 + D_0866B2E0[task->side][task->slot].palette * 32), 0x10);
        task->fade -= 2;
        if (task->fade == 0)
        {
            task->busy = 1;
            task->state = 900;
        }
        break;
    case 900:
        break;
    }
}

void func_0802FD4C(void)
{
    struct Task *task = &D_02000034[D_02000030];
    u16 list[36];
    u8 count;
    u8 side;
    u8 slot;
    u8 k;
    u8 j;
    struct Unit *unit;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            count = 0;
            for (side = 0; side <= 1; side++)
            {
                for (slot = 0; slot <= 5; slot++)
                {
                    if (func_08032A88(side, slot))
                    {
                        struct Side *group = &D_0200EB8C[side];

                        unit = &group->units[slot];
                        for (k = 0; k <= 0x2F; k++)
                        {
                            if (unit->items[k].used == 0 && unit->items[k].id != 0)
                            {
                                for (j = 0; j < count; j++)
                                {
                                    if (list[j] == unit->items[k].id)
                                    {
                                        j = 0xFF;
                                        break;
                                    }
                                }
                                if (j != 0xFF)
                                {
                                    list[count] = unit->items[k].id;
                                    count++;
                                    if (count > 0x23)
                                        count = 0x23;
                                }
                                unit->items[k].id = 0;
                            }
                        }
                    }
                }
            }
            if (count == 0)
                task->state = 9000;
            else
                task->state = 1000;
            break;
        case 1000:
            task->index = 0;
            task->state = 1100;
        case 1100:
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            D_02007574.item = list[task->index];
            func_0803E488(D_0866634C, D_02007574.item);
            func_0803E488(D_08675D58, 0x18);
            func_0803E488(D_08675BEC, 5);
            func_08004018();
            task->state = 1200;
            break;
        case 1200:
            if (D_02000034[9].busy == 1)
                task->state = 1300;
            break;
        case 1300:
            task->index++;
            if (task->index >= count)
                task->state = 9000;
            else
                task->state = 1100;
            break;
        case 9000:
            task->busy = 1;
            task->state = 0x238C;
            break;
        case 0x238C:
            break;
        }
        func_0805EE78(1);
    }
}
