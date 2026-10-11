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
    u8 pad_6[2];
    u32 message;
    u8 pad_C[0xC];
    s32 busy;
    u8 pad_1C[0xC];
    s16 count;
    u8 pad_2A[0x1E];
    struct Child *children[16];
};

struct Unit
{
    u8 pad_0[0x10];
    u32 hp;
    u32 en;
    u8 pad_18[0x18];
    u32 max_hp;
    u32 max_en;
    u8 pad_38[0xA];
    u8 id;
    u8 pad_43[3];
    u16 stats[4];
    u8 pad_4E[0x7E];
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
} D_0200EB84;
extern u8 D_02000030;
extern struct Task D_02000034[];
extern const u8 D_0866B3A0[];

void func_08032134(s32);
void func_08003ED8(struct Task *, s32, void *);
void func_0802E618(void);
void func_0802B5D0(void *, u8);
void func_0803376C(struct Unit *);
void func_08031618(struct Unit *, s32);
void func_08031598(u8);
void func_080019EC(s32);
void func_08003EA4(struct Task *);
void func_0805EE78(s32);

void func_0802E40C(void)
{
    struct Task *task = &D_02000034[D_02000030];
    struct Side *group;
    struct Turn *turn;
    struct Unit *unit;
    u32 flags;
    u16 i;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            flags = task->message;
            func_08032134(7);
            task->count = 0;
            for (i = 0; i < D_0200EB84.count; i++)
            {
                turn = &D_0200EB84.turns[i];
                func_08003ED8(task, task->count, func_0802E618);
                task->children[task->count]->unit = (group = &D_0200EB84.sides[turn->side], &group->units[turn->slot]);
                task->children[task->count]->side = turn->side;
                task->children[task->count]->slot = turn->slot;
                task->count++;
                func_0802B5D0((u8 *)&D_0200EB84 + 4, turn->slot);
                unit = &D_0200EB84.sides[0].units[turn->slot];
                unit->portrait = D_0866B3A0[turn->slot];
                if ((flags & 0x20) && unit->id == 0)
                {
                    unit->stats[0] <<= 1;
                    unit->stats[1] <<= 1;
                    unit->stats[2] <<= 1;
                    unit->stats[3] <<= 1;
                }
                func_0803376C(unit);
                unit->hp = unit->max_hp;
                unit->en = unit->max_en;
                if (D_0200EB84.sides[0].units[turn->slot].field_F4 == 0)
                {
                    func_08031618(unit, 0x11);
                    func_08031598(D_0200EB84.sides[0].units[turn->slot].id);
                }
            }
            if (task->count)
            {
                func_080019EC(0x56);
                task->state = 1000;
            }
            else
            {
                task->state = 9000;
            }
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
            task->busy = 1;
            task->state = 0x238C;
            break;
        }
        func_0805EE78(1);
    }
}
