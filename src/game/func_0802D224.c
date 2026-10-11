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

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[4];
    u16 field_E;
    u8 pad_10[0x32];
    u8 id;
    u8 pad_43[0xB1];
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
    u16 field_4;
    s16 value;
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
extern const u8 D_08675B68[];
extern const u8 D_08675BEC[];
extern const u8 D_08675C5C[];
extern const u8 D_08675D58[];

void func_0803E488(const u8 *, s32);
void func_080339C4(struct Unit *);
void func_08001848(s32, s32, s32);
void func_08004018(void);
void func_08031618(struct Unit *, s32);
void func_08031598(u8);
void func_08032818(u32);
void func_0805EE78(s32);

void func_0802D224(void)
{
    struct Task *task = &D_02000034[D_02000030];
    struct Status *status;
    struct Unit *unit;
    struct Side *group;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            task->index = 0;
            task->state = 1000;
        case 1000:
            status = &D_0200EB84.status[D_0200EB84.turns[task->index].side][D_0200EB84.turns[task->index].slot];
            group = &D_0200EB84.sides[D_0200EB84.turns[task->index].side];
            unit = &group->units[D_0200EB84.turns[task->index].slot];
            if (status->flags & 1)
            {
                func_0803E488(D_08675BEC, 6);
                func_0803E488(D_08675BEC, 7);
                func_080339C4(unit);
                func_0803E488(D_08675D58, 0x12);
                func_0803E488(D_08675BEC, 5);
            }
            func_08004018();
            task->state = 1100;
        case 1100:
            if (D_02000034[9].busy == 1)
                task->state = 1300;
            break;
        case 1300:
            task->index++;
            if (task->index >= D_0200EB84.count)
                task->state = 9000;
            else
                task->state = 1000;
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
