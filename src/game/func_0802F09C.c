#include "types.h"

struct Child
{
    u8 pad_0[8];
    void *sprite;
    void *first;
    void *second;
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
    u8 side;
    u8 lost;
    s16 count;
    u8 pad_2C[0x1C];
    struct Child *children[16];
};

struct Unit
{
    u8 pad_0[0x16];
    u16 zoid;
    u8 pad_10[0xB8];
    void *sprite;
    u8 portrait;
    u8 pad_CD[0x28];
    u8 slot;
    u8 pad_FE[0x1CE];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Def
{
    u8 pad_0[4];
    u16 sprite;
    u8 pad_6[2];
    void *first;
    void *second;
};

extern union
{
    struct { u16 flags; } head;
    struct Side sides[2];
} D_0200EB84;
extern u8 D_02000030;
extern struct Task D_02000034[];
extern u8 D_03004BBC[][0x88];
extern const struct Def D_0866B2E0[2][6];
extern const u8 D_0866B3A0[];

s32 func_08032A88(u32, u32);
void func_08003ED8(struct Task *, s32, void (*)(void));
void func_0802F408(void);
void func_08003EA4(struct Task *);
void func_08003F40(struct Task *, u32);
void func_0802FA58(void);
void func_0802FA6C(void);
void func_080317E4(u8);
void *func_0805ED60(void *, const void *, u32);
void func_0805D270(const void *, void *, u32);
void func_0805EE78(s32);

void func_0802F09C(void)
{
    struct Task *task = &D_02000034[D_02000030];
    struct { vu16 zero; u16 pad; vu32 children; vu32 defs; vu32 side; } storage;
    register u32 i asm("r8");
    register u32 threshold asm("r2");

    asm volatile("" : "+r"(task) : : "r4", "r5", "r6");
    for (;;)
    {
        {
            register s32 state asm("r1") = task->state;
            register u32 value asm("r0");
            asm("" : "+r"(state));
            threshold = 2010;
            asm("" : "+r"(threshold));
            if (state == (s32)threshold)
                goto restore_units;
            if (state > (s32)threshold)
                goto upper_state;
            threshold = 1000;
            asm("" : "+r"(threshold));
            if (state == (s32)threshold)
                goto scan_front;
            if (state > (s32)threshold)
                goto hide_state;
            if (state == 0)
                goto initialize_side;
            goto yield_task;
        hide_state:
            value = 2000;
            asm("" : "+r"(value));
            if (state == (s32)value)
                goto hide_front;
            goto yield_task;
        upper_state:
            threshold = 2200;
            asm("" : : "r"(threshold));
            if (state == (s32)threshold)
                goto release_children;
            if (state > (s32)threshold)
                goto later_state;
            value = 2100;
            asm("" : "+r"(value));
            if (state == (s32)value)
                goto wait_children;
            goto yield_task;
        later_state:
            {
                register u32 later_threshold asm("r3") = 3000;
                asm("" : "+r"(later_threshold));
                if (state == (s32)later_threshold)
                    goto next_side;
                value = 9000;
                asm("" : "+r"(value));
                if (state == (s32)value)
                    goto finish_restore;
                goto yield_task;
            }
        initialize_side:
            value = (u32)&task->side;
            asm("" : "+r"(value));
            *(u8 *)value = state;
            task->state = threshold;
        }
        scan_front:
        {
            register u32 side_address asm("r3");
            u32 active;
            u8 *lost;
            u8 *increment;
            {
            register u32 initial_lost asm("r0") = (u32)&task->lost;
            asm("" : "+r"(initial_lost));
            {
                register u32 zero asm("r4") = 0;
                register u32 initial asm("r1");
                asm("" : : "r"(zero));
                *(u8 *)initial_lost = zero;
                initial = 0;
                asm("" : : "r"(initial));
                i = initial;
                asm("" : "+r"(i) : "r"(initial));
            }
            side_address = (u32)&task->side;
            asm("" : : "r"(side_address));
            lost = (u8 *)initial_lost;
            asm("" : "+r"(lost) : "r"(initial_lost) : "r4");
            }
            increment = lost;
            asm("" : "+r"(increment));
            do
            {
                u32 side = *(u8 *)side_address;
                register u32 slot asm("r1") = i;
                asm("" : : "r"(side), "r"(slot));
                storage.side = side_address;
                active = func_08032A88(side, slot);
                asm("" : "+r"(active));
                side_address = storage.side;
                asm("" : : "r"(side_address));
                if (!active)
                    (*increment)++;
                i = (u8)(i + 1);
            } while (i <= 2);
            if (*lost == 3)
                task->state = 2000;
            else
                goto no_children;
            goto yield_task;
        }
        hide_front:
            func_0802FA58();
            {
                register u32 next_state asm("r3") = 2010;
                asm("" : "+r"(next_state));
                task->state = next_state;
            }
        restore_units:
        {
            register u32 side_address asm("r3");
            register u32 side_stride asm("r10");
            register u32 front_slot asm("r9");
            register u32 def_bytes asm("r5");
            register u32 unit_bytes asm("r6");
            register u32 front_bytes asm("r4");
            u32 active;
            {
                register u32 zero asm("r4") = 0;
                register u32 initial asm("r0");
                asm("" : : "r"(zero));
                task->count = zero;
                initial = 3;
                asm("" : : "r"(initial));
                i = initial;
                asm("" : "+r"(i) : "r"(initial));
            }
            side_address = (u32)&task->side;
            asm("" : : "r"(side_address));
            {
                register u32 children asm("r1") = (u32)task->children;
                register u32 stride asm("r2");
                register u32 defs asm("r4");
                asm("" : : "r"(children));
                storage.children = children;
                stride = sizeof(struct Side);
                asm("" : : "r"(stride));
                side_stride = stride;
                asm("" : "+r"(side_stride) : "r"(stride));
                defs = (u32)D_0866B2E0;
                asm("" : : "r"(defs));
                storage.defs = defs;
            }
            do
            {
                u32 side = *(u8 *)side_address;
                register u32 slot asm("r1") = i;
                asm("" : : "r"(side), "r"(slot));
                storage.side = side_address;
                active = func_08032A88(side, slot);
                asm("" : "+r"(active));
                side_address = storage.side;
                asm("" : : "r"(side_address));
                if (active)
                {
                    {
                        register u32 held2 asm("r2");
                        register u32 held4 asm("r4");
                        register u32 held5 asm("r5");
                        register s32 count asm("r1");
                        asm("" : "=r"(held2), "=r"(held4), "=r"(held5));
                        count = task->count;
                        asm("" : "+r"(count) : "r"(held2), "r"(held4), "r"(held5));
                        func_08003ED8(task, count, func_0802F408);
                    }
                    {
                        register u32 count asm("r0");
                        register u32 held2 asm("r2");
                        register u32 held4 asm("r4");
                        register u32 children asm("r2");
                        register u32 child asm("r1");
                        register u32 unit_stride asm("r4");
                        register u32 side_bytes asm("r2");
                        register u32 address asm("r0");
                        register u32 sprite_base asm("r4");
                        asm("" : "=r"(held2), "=r"(held4));
                        count = task->count;
                        asm("" : "+r"(count) : "r"(held2), "r"(held4));
                        count *= 4;
                        asm("" : : "r"(count));
                        children = storage.children;
                        asm("" : "+r"(children));
                        count = children + count;
                        asm("" : "+r"(count));
                        child = *(u32 *)count;
                        asm("" : "+r"(child));
                        unit_stride = sizeof(struct Unit);
                        asm("" : "+r"(unit_stride));
                        unit_bytes = i;
                        asm("" : "+r"(unit_bytes));
                        unit_bytes *= unit_stride;
                        asm("" : : "r"(unit_bytes));
                        side_address = storage.side;
                        asm("" : : "r"(side_address));
                        address = *(u8 *)side_address;
                        asm("" : : "r"(address));
                        side_bytes = side_stride;
                        asm("" : "+r"(side_bytes));
                        side_bytes *= address;
                        asm("" : : "r"(side_bytes));
                        address = side_bytes;
                        asm("" : "+r"(address));
                        address = unit_bytes - (0u - address);
                        asm("" : "+r"(address));
                        sprite_base = (u32)&D_0200EB84.sides[0].units[0].sprite;
                        asm("" : : "r"(sprite_base));
                        address += sprite_base;
                        asm("" : "+r"(address));
                        address = *(u32 *)address;
                        asm("" : : "r"(address));
                        *(u32 *)(child + 8) = address;
                    }
                    {
                        register u32 count asm("r0");
                        register u32 held2 asm("r2");
                        register u32 held4 asm("r4");
                        register u32 held5 asm("r5");
                        register u32 children asm("r2");
                        register u32 child asm("r2");
                        register u32 slot asm("r4");
                        register u32 side asm("r1");
                        register u32 address asm("r0");
                        register u32 defs asm("r1");
                        asm("" : "=r"(held2), "=r"(held4), "=r"(held5));
                        count = task->count;
                        asm("" : "+r"(count) : "r"(held2), "r"(held4), "r"(held5), "r"(side_address), "r"(unit_bytes));
                        count *= 4;
                        asm("" : : "r"(count));
                        children = storage.children;
                        asm("" : "+r"(children));
                        count = children + count;
                        asm("" : "+r"(count));
                        child = *(u32 *)count;
                        asm("" : "+r"(child));
                        slot = 0u - 3;
                        asm("" : "+r"(slot));
                        slot += i;
                        asm("" : : "r"(slot));
                        front_slot = slot;
                        asm("" : "+r"(front_slot) : "r"(slot));
                        def_bytes = slot * 16;
                        asm("" : "+r"(def_bytes));
                        side = *(u8 *)side_address;
                        asm("" : : "r"(side));
                        address = side * 96;
                        asm("" : "+r"(address));
                        address = def_bytes - (0u - address);
                        asm("" : "+r"(address));
                        defs = storage.defs;
                        asm("" : "+r"(defs));
                        defs += 8;
                        asm("" : "+r"(defs));
                        address += defs;
                        asm("" : "+r"(address));
                        address = *(u32 *)address;
                        asm("" : : "r"(address));
                        *(u32 *)(child + 12) = address;
                    }
                    {
                        register u32 count asm("r0");
                        register u32 held2 asm("r2");
                        register u32 held4 asm("r4");
                        register u32 held5 asm("r5");
                        register u32 children asm("r2");
                        register u32 child asm("r2");
                        register u32 side asm("r1");
                        register u32 address asm("r0");
                        register u32 defs asm("r1");
                        asm("" : "=r"(held2), "=r"(held4), "=r"(held5));
                        count = task->count;
                        asm("" : "+r"(count) : "r"(held2), "r"(held4), "r"(held5));
                        count *= 4;
                        asm("" : : "r"(count));
                        children = storage.children;
                        asm("" : "+r"(children));
                        count = children + count;
                        asm("" : "+r"(count));
                        child = *(u32 *)count;
                        asm("" : "+r"(child));
                        side = *(u8 *)side_address;
                        asm("" : : "r"(side));
                        address = side * 96;
                        asm("" : "+r"(address));
                        address = def_bytes - (0u - address);
                        asm("" : "+r"(address));
                        defs = storage.defs;
                        asm("" : "+r"(defs));
                        defs += 12;
                        asm("" : "+r"(defs));
                        address += defs;
                        asm("" : "+r"(address));
                        address = *(u32 *)address;
                        asm("" : : "r"(address));
                        *(u32 *)(child + 16) = address;
                    }
                    task->count++;
                    {
                        register u32 arg0 asm("r0") = sizeof(struct Unit);
                        register u32 arg1 asm("r1");
                        register u32 arg2 asm("r2");
                        asm("" : "+r"(arg0));
                        front_bytes = front_slot;
                        asm("" : "+r"(front_bytes));
                        front_bytes *= arg0;
                        asm("" : : "r"(front_bytes));
                        arg0 = *(u8 *)side_address;
                        asm("" : : "r"(arg0));
                        arg1 = side_stride;
                        asm("" : "+r"(arg1));
                        arg1 *= arg0;
                        asm("" : : "r"(arg1));
                        arg0 = front_bytes + arg1;
                        asm("" : "+r"(arg0));
                        arg2 = (u32)&D_0200EB84;
                        asm("" : "+r"(arg2));
                        arg0 += arg2;
                        asm("" : "+r"(arg0));
                        arg1 = unit_bytes + arg1;
                        asm("" : "+r"(arg1));
                        arg1 += arg2;
                        asm("" : "+r"(arg1));
                        arg0 += 8;
                        arg1 += 8;
                        asm("" : : "r"(arg0), "r"(arg1));
                        arg2 = sizeof(struct Unit);
                        asm("" : : "r"(arg2));
                        storage.side = side_address;
                        func_0805ED60((void *)arg0, (void *)arg1, arg2);
                    }
                    side_address = storage.side;
                    asm("" : : "r"(side_address));
                    {
                        register u32 arg1 asm("r1") = *(u8 *)side_address;
                        register u32 arg2 asm("r2");
                        register u32 arg0 asm("r0");
                        asm("" : : "r"(arg1));
                        arg2 = side_stride;
                        asm("" : "+r"(arg2));
                        arg2 *= arg1;
                        asm("" : "+r"(arg2));
                        arg2 = front_bytes + arg2;
                        asm("" : "+r"(arg2));
                        arg0 = (u32)&D_0200EB84.sides[0].units[0].sprite;
                        asm("" : : "r"(arg0));
                        arg2 += arg0;
                        asm("" : "+r"(arg2));
                        arg0 = arg1 * 96;
                        asm("" : "+r"(arg0));
                        def_bytes += arg0;
                        asm("" : "+r"(def_bytes));
                        arg1 = storage.defs;
                        asm("" : : "r"(arg1));
                        def_bytes += arg1;
                        asm("" : "+r"(def_bytes));
                        arg1 = *(u16 *)(def_bytes + 4);
                        asm("" : : "r"(arg1));
                        arg0 = arg1 * 136;
                        asm("" : "+r"(arg0));
                        arg1 = (u32)D_03004BBC;
                        asm("" : : "r"(arg1));
                        arg0 += arg1;
                        asm("" : : "r"(arg0));
                        *(u32 *)arg2 = arg0;
                    }
                    {
                        register u32 arg0 asm("r0") = *(u8 *)side_address;
                        register u32 arg1 asm("r1");
                        register u32 arg2 asm("r2");
                        asm("" : : "r"(arg0));
                        arg1 = side_stride;
                        asm("" : "+r"(arg1));
                        arg1 *= arg0;
                        asm("" : "+r"(arg1));
                        arg1 = front_bytes + arg1;
                        asm("" : "+r"(arg1));
                        arg2 = (u32)&D_0200EB84;
                        asm("" : "+r"(arg2));
                        arg1 += arg2;
                        asm("" : "+r"(arg1));
                        arg0 = (u32)D_0866B3A0;
                        asm("" : "+r"(arg0));
                        arg0 += front_slot;
                        asm("" : "+r"(arg0));
                        arg0 = *(u8 *)arg0;
                        asm("" : : "r"(arg0));
                        arg1 += 212;
                        asm("" : : "r"(arg1));
                        *(u8 *)arg1 = arg0;
                        arg0 = (u32)&storage;
                        asm("" : "+r"(arg0));
                        arg1 = 0;
                        asm("" : : "r"(arg1));
                        *(vu16 *)arg0 = arg1;
                        arg0 = *(u8 *)side_address;
                        asm("" : : "r"(arg0));
                        arg1 = side_stride;
                        asm("" : "+r"(arg1));
                        arg1 *= arg0;
                        asm("" : "+r"(arg1));
                        arg0 = arg2;
                        asm("" : "+r"(arg0));
                        arg0 += 8;
                        asm("" : : "r"(arg0));
                        arg1 += arg0;
                        asm("" : "+r"(arg1));
                        arg1 += unit_bytes;
                        asm("" : : "r"(arg1));
                        arg0 = (u32)&storage;
                        asm("" : : "r"(arg0));
                        arg2 = 0x01000166;
                        asm("" : : "r"(arg2));
                        storage.side = side_address;
                        func_0805D270((void *)arg0, (void *)arg1, arg2);
                    }
                    side_address = storage.side;
                    asm("" : : "r"(side_address));
                    {
                        register u32 arg0 asm("r0") = *(u8 *)side_address;
                        register u32 arg2 asm("r2");
                        asm("" : : "r"(arg0));
                        arg2 = side_stride;
                        asm("" : "+r"(arg2));
                        arg2 *= arg0;
                        asm("" : : "r"(arg2));
                        arg0 = arg2;
                        asm("" : "+r"(arg0));
                        unit_bytes += arg0;
                        asm("" : "+r"(unit_bytes));
                        arg0 = (u32)&D_0200EB84;
                        asm("" : : "r"(arg0));
                        unit_bytes += arg0;
                        asm("" : "+r"(unit_bytes));
                        arg0 = 255;
                        asm("" : : "r"(arg0));
                        *(u16 *)(unit_bytes + 22) = arg0;
                    }
                    {
                        register u32 arg0 asm("r0") = *(u8 *)side_address;
                        register u32 arg1 asm("r1");
                        register u32 arg2 asm("r2");
                        asm("" : : "r"(arg0));
                        arg1 = side_stride;
                        asm("" : "+r"(arg1));
                        arg1 *= arg0;
                        asm("" : : "r"(arg1));
                        arg0 = arg1;
                        asm("" : "+r"(arg0));
                        front_bytes += arg0;
                        asm("" : "+r"(front_bytes));
                        arg2 = (u32)&D_0200EB84;
                        asm("" : : "r"(arg2));
                        front_bytes += arg2;
                        asm("" : "+r"(front_bytes));
                        front_bytes += 253;
                        asm("" : "+r"(front_bytes));
                        arg0 = front_slot;
                        asm("" : : "r"(arg0));
                        *(u8 *)front_bytes = arg0;
                    }
                }
                i = (u8)(i + 1);
            } while (i <= 5);
            {
            register u32 held2 asm("r2");
            register u32 held3 asm("r3");
            register u32 held4 asm("r4");
            register u32 held5 asm("r5");
            register u32 held6 asm("r6");
            register s32 count asm("r0");
            asm("" : "=r"(held2), "=r"(held3), "=r"(held4), "=r"(held5), "=r"(held6));
            count = task->count;
            asm("" : "+r"(count) : "r"(held2), "r"(held3), "r"(held4), "r"(held5), "r"(held6));
            if (count)
                task->state = 2100;
            else
            {
            no_children:
                {
                    register u32 next_state asm("r2") = 3000;
                    asm("" : "+r"(next_state));
                    task->state = next_state;
                }
            }
            }
            goto yield_task;
        }
        wait_children:
        {
            register u32 initial asm("r3") = 0;
            register s32 count asm("r1");
            register u32 held0 asm("r0");
            register u32 held3 asm("r3");
            register u32 held5 asm("r5");
            register u32 held6 asm("r6");
            asm("" : : "r"(initial), "r"(threshold));
            i = initial;
            asm("" : "+r"(i) : "r"(initial));
            asm("" : "=r"(held0), "=r"(held3), "=r"(held5), "=r"(held6));
            count = task->count;
            asm("" : "+r"(count) : "r"(held0), "r"(threshold), "r"(held3), "r"(held5), "r"(held6));
            if ((s32)i < count)
            {
                u32 busy = task->children[0]->busy;
                asm("" : "+r"(busy));
                if (busy == 1)
                {
                    register u32 state asm("r3") = threshold;
                    register s32 saved_count asm("r2") = count;
                    register u32 children asm("r1") = (u32)task->children;
                    asm("" : "+r"(state), "+r"(saved_count), "+r"(children));
                    do
                    {
                        task->state = state;
                        i = (u8)(i + 1);
                    } while ((s32)i < saved_count && (*(struct Child **)(children - (0u - i * 4)))->busy == 1);
                }
            }
            func_08003EA4(task);
            goto yield_task;
        }
        release_children:
        {
            register u32 initial asm("r0") = 0;
            register s32 count asm("r0");
            register u32 side_address asm("r3");
            asm("" : : "r"(initial));
            i = initial;
            asm("" : "+r"(i) : "r"(initial));
            count = task->count;
            asm("" : "+r"(count));
            side_address = (u32)&task->side;
            asm("" : : "r"(side_address));
            if ((s32)i < count)
            {
                do
                {
                    {
                        register u32 task_arg asm("r0") = (u32)task;
                        register u32 slot_arg asm("r1") = i;
                        asm("" : : "r"(task_arg), "r"(slot_arg));
                        storage.side = side_address;
                        func_08003F40((struct Task *)task_arg, slot_arg);
                    }
                    i = (u8)(i + 1);
                    {
                        register u32 held1 asm("r1");
                        register u32 held3 asm("r3");
                        register u32 held4 asm("r4");
                        register u32 held5 asm("r5");
                        register u32 held6 asm("r6");
                        asm("" : "=r"(held1), "=r"(held3), "=r"(held4), "=r"(held5), "=r"(held6));
                        count = task->count;
                        asm("" : "+r"(count) : "r"(held1), "r"(held3), "r"(held4), "r"(held5), "r"(held6));
                    }
                    side_address = storage.side;
                    asm("" : : "r"(side_address));
                } while ((s32)i < count);
            }
            {
                register u32 side asm("r0") = *(u8 *)side_address;
                asm("" : : "r"(side));
                storage.side = side_address;
                func_080317E4(side);
            }
            side_address = storage.side;
            asm("" : : "r"(side_address));
            {
                u32 side = *(u8 *)side_address;
                if (side == 0)
                    D_0200EB84.head.flags |= 0x80;
                else if (side == 1)
                {
                    register u32 base asm("r0") = (u32)&D_0200EB84;
                    register u32 flags asm("r1");
                    register u32 mask asm("r3");
                    register u32 stored_mask asm("r2");
                    asm("" : "+r"(base));
                    flags = *(u16 *)base;
                    asm("" : "+r"(flags));
                    mask = 128;
                    asm("" : "+r"(mask));
                    mask *= 2;
                    asm("" : : "r"(mask));
                    stored_mask = mask;
                    asm("" : "+r"(stored_mask) : "r"(mask));
                    flags |= stored_mask;
                    *(u16 *)base = flags;
                }
            }
            {
                register u32 next_state asm("r4") = 3000;
                asm("" : "+r"(next_state));
                task->state = next_state;
            }
            goto yield_task;
        }
        next_side:
            if (task->side == 0)
            {
                task->side = 1;
                task->state = 1000;
            }
            else
                task->state = 9000;
            goto yield_task;
        finish_restore:
            func_0802FA6C();
            task->busy = 1;
            task->state = 9100;
            goto yield_task;
        yield_task:
        func_0805EE78(1);
    }
}
