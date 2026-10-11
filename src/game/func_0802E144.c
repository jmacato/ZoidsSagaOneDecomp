#include "types.h"

struct Child
{
    u8 pad_0[8];
    void *sprite;
    u32 x;
    u32 y;
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
    u8 side;
    u8 pad_29;
    s16 count;
    u8 pad_2C[0x1C];
    struct Child *children[16];
};

struct Unit
{
    u8 pad_0[0xE];
    u16 zoid;
    u8 pad_10[0xB8];
    void *sprite;
    u8 portrait;
    u8 pad_CD[0x28];
    u8 slot;
    u8 pad_F6[0x1D6];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Place
{
    u8 pad_0[4];
    u16 sprite;
    u8 pad_6[2];
    u32 x;
    u32 y;
};

struct Sprite
{
    u8 data[0x88];
};

extern struct
{
    u16 flags;
    u8 pad_2[6];
    struct Side sides[2];
} D_0200EB84;
extern u8 D_02000030;
extern struct Task D_02000034[];
extern const struct Place D_0866B2E0[2][6];
extern const u8 D_0866B3A0[];
extern struct Sprite D_03004BBC[];

s32 func_08032A88(u8, u8);
void func_08003ED8(struct Task *, s32, void *);
void func_0802F408(void);
void func_0805D270(const void *, void *, u32);
void func_08003EA4(struct Task *);
void func_08003F40(struct Task *, u8);
void func_080317E4(u8);
void func_0805EE78(s32);

void func_0802E144(void)
{
    struct Task *task = &D_02000034[D_02000030];
    struct Side *group;
    u8 i;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            task->side = task->message;
            task->state = 1000;
        case 1000:
            task->count = 0;
            for (i = 0; i <= 2; i++)
            {
                if (func_08032A88(task->side, i))
                {
                    vu16 zero;

                    func_08003ED8(task, task->count, func_0802F408);
                    task->children[task->count]->sprite = D_0200EB84.sides[task->side].units[i].sprite;
                    task->children[task->count]->x = D_0866B2E0[task->side][i + 3].x;
                    task->children[task->count]->y = D_0866B2E0[task->side][i + 3].y;
                    task->count++;
                    D_0200EB84.sides[task->side].units[i + 3] = D_0200EB84.sides[task->side].units[i];
                    D_0200EB84.sides[task->side].units[i + 3].sprite = &D_03004BBC[D_0866B2E0[task->side][i + 3].sprite];
                    D_0200EB84.sides[task->side].units[i + 3].portrait = D_0866B3A0[i + 3];
                    zero = 0;
                    func_0805D270((void *)&zero, (group = &D_0200EB84.sides[task->side], &group->units[i]), 0x01000166);
                    D_0200EB84.sides[task->side].units[i].zoid = 0xFF;
                    D_0200EB84.sides[task->side].units[i + 3].slot = i + 3;
                }
            }
            if (task->count)
                task->state = 2100;
            else
                task->state = 3000;
            break;
        case 2100:
            i = 0;
            if (i < task->count && task->children[i]->busy == 1)
            {
                do
                {
                    task->state = 2200;
                    i++;
                } while (i < task->count && task->children[i]->busy == 1);
            }
            func_08003EA4(task);
            break;
        case 2200:
            for (i = 0; i < task->count; i++)
                func_08003F40(task, i);
            func_080317E4(task->side);
            if (task->side == 0)
                D_0200EB84.flags &= 0xFF7F;
            else if (task->side == 1)
                D_0200EB84.flags &= 0xFEFF;
            task->busy = 1;
            task->state = 9000;
            break;
        case 3000:
            break;
        }
        func_0805EE78(1);
    }
}
