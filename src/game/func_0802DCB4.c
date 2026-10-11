#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    void *data;
    u8 pad_C[0xC];
    s32 busy;
    u8 pad_1C[0xC];
    s16 count;
    u8 pad_2A[0x1E];
    struct Task *children[16];
};

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[6];
    u32 field_10;
    u8 pad_14[0x2E];
    u8 field_42;
    u8 pad_43[0x289];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Status
{
    u16 flags;
    u8 pad_2[10];
};

struct Turn
{
    u8 side;
    u8 slot;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[8];
    struct Side sides[2];
    u8 pad_21B8[0x39];
    u8 count;
    u8 pad_21F2[2];
    struct Turn turns[6];
    struct Status status[2][6];
} D_0200EB84;

extern u8 D_02000030;
extern struct Task D_02000034[];

void func_08032134(s32);
void func_08003ED8(struct Task *, s32, void *);
void func_0802DBE4(void);
void func_08031618(struct Unit *, s32);
void func_08031598(u8);
void func_08003EA4(struct Task *);
void func_0802C014(void);
void func_0805EE78(s32);

void func_0802DCB4(void)
{
    struct Task *task = &D_02000034[D_02000030];
    register u8 *units_base asm("r12");
    u16 i;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            func_08032134(1);
            task->count = 0;
            for (i = 0; i < D_0200EB84.count; i++)
            {
                struct Turn *turn = &D_0200EB84.turns[i];

                if (D_0200EB84.status[turn->side][turn->slot].flags & 1)
                {
                    func_08003ED8(task, task->count, func_0802DBE4);
                    {
                        register struct Task *child asm("r2") = task->children[task->count];
                        register u32 index asm("r0") = turn->side;
                        register u32 side_bytes asm("r1");
                        u32 stride = sizeof(struct Side);
                        register struct Unit *unit asm("r1");
                        register u32 base asm("r0");

                        asm("" : : "r"(child), "r"(index), "r"(stride));
                        side_bytes = index;
                        asm("" : "+r"(side_bytes));
                        side_bytes *= stride;
                        base = 8;
                        asm("" : : "r"(base), "r"(side_bytes));
                        base += (u32)&D_0200EB84;
                        units_base = (u8 *)base;
                        asm("" : : "r"(units_base));
                        side_bytes += (u32)units_base;
                        asm("" : "+r"(side_bytes));
                        unit = (struct Unit *)(side_bytes + turn->slot * sizeof(struct Unit));
                        asm("" : : "r"(unit));
                        child->data = unit;
                    }
                    task->count++;
                    D_0200EB84.sides[turn->side].units[turn->slot].flags |= 0x400;
                    D_0200EB84.sides[turn->side].units[turn->slot].field_10 = 0;
                    if (turn->side == 0)
                    {
                        func_08031618((struct Unit *)(units_base + turn->side * sizeof(struct Side) + turn->slot * sizeof(struct Unit)), 0x11);
                        func_08031598(D_0200EB84.sides[turn->side].units[turn->slot].field_42);
                    }
                }
            }
            if (task->count)
                task->state = 1000;
            else
                task->state = 9000;
            break;
        case 1000:
            func_08003EA4(task);
            i = 0;
            if (i < task->count && task->children[i]->busy)
            {
                do
                {
                    task->state = 9000;
                    i++;
                } while (i < task->count && task->children[i]->busy);
            }
            break;
        case 9000:
            func_0802C014();
            task->busy = 1;
            task->state = 0x238C;
            break;
        }
        func_0805EE78(1);
    }
}
