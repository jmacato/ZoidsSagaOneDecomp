#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 message;
    u32 data;
    u32 field_10;
    u8 pad_14[4];
    s32 busy;
    u8 pad_1C[0x2C];
    struct Task *children[16];
};

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[0x2C2];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern struct
{
    u16 flags;
} D_0200EB84;

extern struct Side D_0200EB8C[2];

extern u8 D_02000030;
extern struct Task D_02000034[];
extern u16 D_020143BC[];
extern const u8 D_08675BEC[];
extern const u8 D_08675D58[];

void func_0805EE78(s32);
s32 func_08032A88(u32, u8);
void func_08003ED8(struct Task *, s32, void *);
void func_0802FCB8(void);
void func_0803E488(const u8 *, s32);
void func_080339C4(struct Unit *);
void func_08004018(void);
void func_08003EA4(struct Task *);
void func_08003F40(struct Task *, s32);

void func_0802FAA8(void)
{
    struct Task *task = &D_02000034[D_02000030];
    s32 first;
    register u32 count asm("r10");
    u8 slot;
    u32 side;
    u16 limit;
    struct Unit *unit;

    {
        /* The original entry reads the incoming unit pointer from r8. */
        register struct Unit *incoming asm("r8");
        asm("" : "=r"(incoming));
        unit = incoming;
    }

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            first = 0;
            count = 0;
            slot = 0;
            side = 0;
            if (task->message == 1 && task->data == 1)
            {
                side = 1;
                first = 1;
            }
            limit = (D_0200EB84.flags & 0x20) ? 0x19 : 5;
            if (unit->flags & 0x200)
                limit = 0x32;
            task->state = 100;
        case 100:
            task->state = 900;
            if (!func_08032A88(side, slot))
                break;
            {
                u8 *group = (u8 *)D_0200EB8C + side * sizeof(struct Side);
                asm("" : "+r"(group));
                unit = (struct Unit *)(group + slot * sizeof(struct Unit));
            }
            if (!(unit->flags & 0x4000))
                break;
            {
                u16 roll = D_020143BC[count];
                count = (u8)(count + 1);
                if (roll >= limit)
                    break;
            }
            unit->flags &= 0xBFFF;
            task->state = 200;
            break;
        case 200:
            func_08003ED8(task, 0, func_0802FCB8);
            {
                register struct Task *child asm("r2") = task->children[0];
                u32 stride = sizeof(struct Side);
                register u32 group asm("r1");
                asm("" : : "r"(stride));
                group = side;
                asm("" : : "r"(child), "r"(group), "r"(stride));
                group *= stride;
                group += (u32)D_0200EB8C;
                asm("" : "+r"(group));
                child->message = group + slot * sizeof(struct Unit);
                child->data = side;
                child->field_10 = slot;
            }
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_080339C4(unit);
            func_0803E488(D_08675D58, 0x15);
            func_0803E488(D_08675BEC, 5);
            func_08004018();
            task->state = 210;
            break;
        case 210:
            func_08003EA4(task);
            if (task->children[0]->busy == 1)
            {
                func_08003F40(task, 0);
                task->state = 220;
            }
            break;
        case 220:
            if (D_02000034[9].busy == 1)
                task->state = 900;
            break;
        case 900:
            task->state = 100;
            slot++;
            if (slot > 5)
            {
                slot = 0;
                if (!first)
                {
                    if (side == 1)
                        task->state = 9000;
                    else
                        side = 1;
                }
                else
                {
                    if (side == 0)
                        task->state = 9000;
                    else
                        side = 0;
                }
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
