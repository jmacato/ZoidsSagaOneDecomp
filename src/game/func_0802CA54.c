#include "types.h"

struct Child
{
    u8 pad_0[8];
    void *unit;
    u32 side;
    u32 slot;
    u8 pad_14[4];
    s32 busy;
};

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[0x12];
    s32 busy;
    u8 pad_1C[0xC];
    s16 count;
    u8 pad_2A[0x1E];
    struct Child *children[16];
};

struct Unit
{
    u8 data[0x2CC];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Status
{
    u16 flags;
    u8 pad_2[0xA];
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
    u8 pad_220C[0x0];
    struct Status status[2][6];
} D_0200EB84;
extern u8 D_02000030;
extern struct Task D_02000034[];

void func_08032134(s32);
void func_08003ED8(struct Task *, s32, void (*)(void));
void func_0802CBBC(void);
void func_080019EC(s32);
void func_08003EA4(struct Task *);
void func_0805EE78(s32);

void func_0802CA54(void)
{
    struct Task *task = &D_02000034[D_02000030];
    struct Turn *turn;
    struct Side *group;
    u16 i;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            func_08032134(4);
            task->count = 0;
            for (i = 0; i < D_0200EB84.count; i++)
            {
                turn = &D_0200EB84.turns[i];
                if (D_0200EB84.status[turn->side][turn->slot].flags & 1)
                {
                    func_08003ED8(task, task->count, func_0802CBBC);
                    task->children[task->count]->unit = (group = &D_0200EB84.sides[turn->side], &group->units[turn->slot]);
                    task->children[task->count]->side = turn->side;
                    task->children[task->count]->slot = turn->slot;
                    task->count++;
                }
            }
            if (task->count)
            {
                func_080019EC(0x57);
                task->state = 100;
            }
            else
            {
                task->state = 900;
            }
            break;
        case 100:
            func_08003EA4(task);
            i = 0;
            if (i < task->count && task->children[i]->busy)
            {
                do
                {
                    task->state = 900;
                    i++;
                } while (i < task->count && task->children[i]->busy);
            }
            break;
        case 900:
            task->busy = 1;
            task->state = 910;
            break;
        }
        func_0805EE78(1);
    }
}
