#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[0x12];
    s32 busy;
    u8 pad_1C[0xC];
    s16 index;
    u8 pad_2A[0x5E];
};

struct Sprite
{
    u16 flags;
    u8 pad_2[6];
    u32 x;
    u32 y;
    u8 pad_10[0x78];
};

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[4];
    u16 field_E;
    u8 pad_10[0x32];
    u8 id;
    u8 pad_43[0x85];
    struct Sprite *sprite;
    u8 portrait;
    u8 pad_CD[0x27];
    u8 field_F4;
    u8 pad_F5[0x1D7];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Status
{
    u16 flags;
    u16 effects;
    u32 value;
    u8 pad_8[4];
};

struct Turn
{
    u8 side;
    u8 slot;
    u8 pad_2[2];
};

extern struct
{
    u16 flags;
    u8 pad_2[6];
    struct Side sides[2];
    u8 pad_21B8[0x39];
    u8 count;
    u8 pad_21F2[2];
    struct Turn turns[6];
    struct Status status[2][6];
} D_0200EB84;
extern struct Side D_0200EB8C[];
extern u8 D_02000030;
extern struct Task D_02000034[];
extern u8 D_02010D75;
extern s32 D_02000514;
extern const u8 D_08675B68[];
extern const u8 D_08675BEC[];
extern const u8 D_08675C5C[];
extern const u8 D_08675D58[];

void func_0803E488(const u8 *, s32);
void func_080339C4(struct Unit *);
void func_08001848(u32, s32, s32);
void func_08004018(void);
void func_08031618(struct Unit *, s32);
void func_08031598(u8);
void func_08032818(u32);
void func_0805EE78(s32);

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
    u8 pad_1[0xF];
};

extern struct Sprite D_03004BBC[];
extern const struct Kind D_0867006C[];
extern const struct Place D_0866B2E0[2][6];

void func_08032164(s32, u8, u32, u32);
void func_0805D270(const void *, void *, u32);
void func_08031E90(u16 *, u8, u8);

void func_0802C588(void *unused, struct Child *task)
{
    u16 palette[16];
    struct Unit *unit = task->unit;
    struct Sprite *sprite = unit->sprite;

    switch (task->state)
    {
    case 0:
        func_08032164(2, unit->portrait, sprite->x, sprite->y);
        task->level = 8;
        task->state = 100;
        break;
    case 100:
        func_0805D270(D_0867006C[unit->field_E].palette, palette, 0x10);
        func_08031E90(palette, task->level, 0x12);
        func_08031E90(palette, task->level, 0xD);
        func_0805D270(palette, (void *)(0x05000200 + D_0866B2E0[task->side][task->slot].palette * 32), 0x10);
        task->level += 2;
        if (task->level > 0x1F)
            task->state = 200;
        break;
    case 200:
        task->level -= 2;
        func_0805D270(D_0867006C[unit->field_E].palette, palette, 0x10);
        func_08031E90(palette, task->level, 0x12);
        func_08031E90(palette, task->level, 0xD);
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

void func_0802C708(void)
{
    struct Task *task = &D_02000034[D_02000030];
    struct Status *status;
    struct Unit *unit;
    struct Side *group;
    register u32 finished asm("r10") = 1300;
    {
        register struct Status *incoming_status asm("r7");
        register struct Unit *incoming_unit asm("r6");
        asm("" : "=r"(incoming_status), "=r"(incoming_unit));
        status = incoming_status;
        unit = incoming_unit;
    }

    asm("" : "+r"(finished));
    {
        register typeof(D_0200EB84) *entry asm("r2") = &D_0200EB84;
        register typeof(D_0200EB84) *cache asm("r9");
        asm("" : : "r"(entry));
        cache = entry;
        asm("" : : "r"(cache));
    }
    {
        register const u8 *entry asm("r3") = D_08675BEC;
        register const u8 *cache asm("r8");
        asm("" : : "r"(entry));
        cache = entry;
        asm("" : : "r"(cache));
    }

    for (;;)
    {
        {
        register s32 state asm("r0");
        {
            register u32 saved2 asm("r2");
            register u32 saved3 asm("r3");
            asm("" : "=r"(saved2), "=r"(saved3));
            state = task->state;
            asm("" : : "r"(saved2), "r"(saved3), "r"(state));
        }
        asm("" : "+r"(state));
        if (state == 1200)
            goto state_1200;
        if (state > 1200)
            goto higher_state;
        {
            if (state == 1000)
                goto state_1000;
            if (state > 1000)
                goto above_1000;
            if (state == 0)
                goto state_0;
            goto yield;
        }
        above_1000:
        {
            register u32 target asm("r2") = 1100;
            asm("" : "+r"(target));
            if (state == target)
                goto state_1100;
            goto yield;
        }
        higher_state:
        if (state == 9000)
            goto state_9000;
        asm("" : : "r"(finished));
        if (state <= 9000 && state == finished)
            goto state_1300;
        goto yield;

        state_0:
            task->index = state;
            task->state = 1000;
        }
        state_1000:
            status = &D_0200EB84.status[D_0200EB84.turns[({ s32 value; register u32 saved1 asm("r1"); register u32 saved2 asm("r2"); asm("" : "=r"(saved1), "=r"(saved2)); value = task->index; asm("" : : "r"(saved1), "r"(saved2), "r"(value)); value; })].side][({ u8 slot = D_0200EB84.turns[task->index].slot; asm("" : : : "r1"); slot; })];
            group = &D_0200EB84.sides[D_0200EB84.turns[task->index].side];
            unit = &group->units[D_0200EB84.turns[task->index].slot];
            if (status->flags & 1)
            {
                func_0803E488(D_08675BEC, 6);
                func_0803E488(D_08675BEC, 7);
                func_080339C4(unit);
                func_0803E488(D_08675D58, 0);
                func_0803E488(D_08675D58, 6);
                func_08001848(status->value, 7, 1);
                func_0803E488(D_08675D58, 0xB);
                func_0803E488(D_08675BEC, 5);
            }
            if (unit->field_F4 == 0)
            {
                func_08031618(unit, 0x11);
                func_08031598(unit->id);
            }
            func_08004018();
            { register u32 next asm("r1") = 1100; asm("" : "+r"(next) : "m"(task->state)); task->state = next; }
        state_1100:
            if (({ register s32 *busy asm("r2") = &D_02000514; asm("" : "+r"(busy)); *busy; }) == 1)
            {
                if (status->flags & 0x10)
                {
                    func_0803E488(D_08675BEC, 6);
                    func_0803E488(D_08675BEC, 7);
                    func_080339C4(unit);
                    func_0803E488(D_08675D58, 0x14);
                    func_0803E488(D_08675BEC, 5);
                    func_08004018();
                    task->state = 1200;
                }
                else
                {
                    { register u32 next asm("r3") = finished; asm("" : "+r"(next) : "r"(finished)); task->state = next; }
                    asm("" : : : "memory");
                }
            }
            goto yield;
        state_1200:
            if (({ register s32 *busy asm("r1") = &D_02000514; asm("" : "+r"(busy)); *busy; }) == 1)
                { register u32 next asm("r2") = finished; asm("" : "+r"(next) : "r"(finished)); task->state = next; }
            goto yield;
        state_1300:
            task->index++;
            if (({ s32 value; register u32 saved asm("r2"); asm("" : "=r"(saved)); value = task->index; asm("" : : "r"(saved), "r"(value)); value; }) >= D_0200EB84.count)
                task->state = 9000;
            else
                task->state = 1000;
            goto yield;
        state_9000:
            task->busy = 1;
            task->state = 0x238C;
            goto yield;
        yield:
        func_0805EE78(1);
    }
}
