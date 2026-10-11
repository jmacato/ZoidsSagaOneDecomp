#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[0x86];
};

struct Unit
{
    u8 pad_0[0xE];
    u16 zoid;
    u8 pad_10[0xBC];
    u8 portrait;
    u8 action;
    u8 pad_CE[0x26];
    u8 field_F4;
    u8 pad_F5[0x1D7];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0xD];
    u8 phase;
    u8 pad_10D6[2];
};

union Slot
{
    u8 kind;
    u32 value;
};

struct Child
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    struct Unit *unit;
    u32 side;
    u32 slot;
    u8 pad_14[4];
    s32 busy;
    u8 pad_1C[0x10];
    u8 level;
    u8 pad_2D[3];
    s32 fade;
};

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    struct Unit *unit;
    u8 pad_C[0xC];
    s32 busy;
    u32 result;
    u8 pad_20[0x68];
};

struct Kind
{
    u8 pad_0[0x34];
    const u16 *palette;
    u8 pad_38[0x14];
};

struct Place
{
    u8 palette;
    u8 pad_1;
    u16 field_2;
    u16 sprite;
    u8 pad_6[2];
    u32 x;
    u32 y;
};

extern struct
{
    u16 flags;
    u8 pad_2[6];
    struct Side sides[2];
    union Slot slots[13];
    u8 pad_21EC[0xC4];
    u8 result;
} D_0200EB84;
extern struct
{
    u16 flags;
} D_02005C70;
extern struct
{
    u16 field_0;
    u16 choice;
} D_02007574;
extern struct Sprite D_03004BBC[];
extern const struct Kind D_0867006C[];
extern const struct Place D_0866B2E0[2][6];
extern const u8 D_08675B68[];
extern const u8 D_08675BEC[];
extern const u8 D_08675C5C[];
extern void (*const D_0875BE40[])(struct Unit *);
extern u8 D_02000030;
extern struct Task D_02000034[];

void func_08032164(s32, u8, u32, u32);
void func_0803193C(u16, u8, u16, u16, s32, s32);
void func_0805D270(const void *, void *, u32);
void func_08031E90(u16 *, u8, u8);
void func_08031D50(void);
void func_0803E488(const u8 *, s32);
void func_080339C4(struct Unit *);
s32 func_08033DCC(struct Unit *);
void func_0805EE78(s32);

void func_0802E618(void *unused, struct Child *task)
{
    u16 palette[16];
    struct Unit *unit = task->unit;

    switch (task->state)
    {
    case 0:
        func_08032164(7, unit->portrait, D_0866B2E0[task->side][task->slot].x, D_0866B2E0[task->side][task->slot].y);
        task->level = 0;
        task->state = 100;
        break;
    case 100:
        if (++task->level > 0x1B)
        {
            func_0803193C(D_0200EB84.sides[task->side].units[task->slot].zoid, D_0866B2E0[task->side][task->slot].palette, D_0866B2E0[task->side][task->slot].field_2, D_0866B2E0[task->side][task->slot].sprite, D_0866B2E0[task->side][task->slot].x, D_0866B2E0[task->side][task->slot].y);
            func_0805D270(D_0867006C[unit->zoid].palette, palette, 0x10);
            func_08031E90(palette, 0x20, 0x1E);
            func_0805D270(palette, (void *)(0x05000200 + D_0866B2E0[task->side][task->slot].palette * 32), 0x10);
            task->fade = 0x200000;
            task->state = 200;
        }
        break;
    case 200:
        task->fade = (double)task->fade - 32768.0;
        task->level = task->fade >> 16;
        func_0805D270(D_0867006C[unit->zoid].palette, palette, 0x10);
        func_08031E90(palette, task->level, 0x1E);
        func_0805D270(palette, (void *)(0x05000200 + D_0866B2E0[task->side][task->slot].palette * 32), 0x10);
        if (task->level == 0)
            task->state = 9000;
        break;
    case 9000:
        if (D_03004BBC[unit->portrait].flags & 4)
        {
            D_03004BBC[unit->portrait].flags &= 0x7FFF;
            task->state = 9100;
        }
        break;
    case 9100:
        task->busy = 1;
        break;
    }
}

void func_0802E814(void)
{
    struct Task *task = &D_02000034[D_02000030];
    struct Unit *unit;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            unit = task->unit;
            func_08031D50();
        case 500:
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            if (unit->field_F4 == 1)
                func_0803E488(D_08675B68, 0x10);
            func_080339C4(unit);
            func_0803E488(D_08675C5C, 5);
            func_0803E488(D_08675BEC, 5);
            task->state = 1000;
            if (D_0200EB84.slots[D_0200EB84.sides[1].phase].kind == 1)
            {
                task->state = 2000;
                if (D_0200EB84.flags & 0x20)
                    task->state = 3000;
            }
            break;
        case 1000:
            if ((D_0200EB84.flags & 0x20) || (D_02005C70.flags & 2))
                func_0803E488(D_08675BEC, 0x1A);
            else
                func_0803E488(D_08675BEC, 4);
            if ((task->result = D_02007574.choice) == 0)
            {
                if (func_08033DCC(unit))
                {
                    task->busy = 1;
                }
                else
                {
                    func_0803E488(D_08675BEC, 6);
                    func_0803E488(D_08675BEC, 7);
                    func_0803E488(D_08675C5C, 0x3D);
                    func_0803E488(D_08675BEC, 5);
                    func_0803E488(D_08675BEC, 0x14);
                    task->state = 500;
                }
            }
            else
            {
                task->busy = 1;
            }
            break;
        case 2000:
            D_0875BE40[unit->action](unit);
            task->result = D_0200EB84.result;
            task->busy = 1;
            break;
        case 3000:
            task->busy = 2;
            break;
        }
        func_0805EE78(1);
    }
}
