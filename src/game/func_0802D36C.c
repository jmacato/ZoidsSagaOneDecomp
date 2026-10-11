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
    s16 level;
    u8 pad_2C[0x1C];
    struct Child *children[16];
};

struct Unit
{
    u8 pad_0[0x3D];
    u8 level;
    u8 pad_3E[0x28E];
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

struct Battle
{
    u8 pad_0[8];
    struct Side sides[2];
    u8 pad_21B8[0x39];
    u8 count;
    u8 pad_21F2[2];
    struct Turn turns[6];
    u8 pad_220C[0x0];
    struct Status status[2][6];
};
extern struct Battle D_0200EB84;
extern struct Side D_0200EB8C[];
extern u8 D_02010D75;
extern struct Turn D_02010D78[];
extern u8 D_02000030;
extern struct Task D_02000034[];

void func_08032134(s32);
void func_08003ED8(struct Task *, s32, void (*)(void));
void func_0802D9A4(void);
void func_0802CD38(void);
void func_0802DAF4(void);
void func_0802DBE4(void);
void func_08003F40(struct Task *, u16);
void func_080019EC(s32);
void func_08003EA4(struct Task *);
void func_0805EE78(s32);

void func_0802D36C(void)
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
            func_08032134(0);
            task->count = 0;
            i = 0;
            if (i < ({
                register u8 *initial_pointer asm("r1") = &D_02010D75;
                register u32 initial_count asm("r1");
                asm("" : "+r"(initial_pointer));
                initial_count = *initial_pointer;
                asm("" : "+r"(initial_count));
                initial_count;
            }))
            {
                struct Turn *turns = D_02010D78;
                u8 *count;
                struct Battle *battle;
                u8 *units;
                {
                    register u32 held_count asm("r8");
                    register u32 held_units asm("r9");
                    register u32 held_low asm("r1");
                    asm("" : "=r"(held_count), "=r"(held_units), "=r"(held_low));
                    battle = (struct Battle *)((u8 *)turns - 0x21F4);
                    asm("" : "+r"(battle) : "r"(held_count), "r"(held_units), "r"(held_low));
                }
                {
                    register u32 held_count asm("r8");
                    register u32 held0 asm("r0");
                    register u32 held1 asm("r1");
                    register u32 held2 asm("r2");
                    register u32 held3 asm("r3");
                    asm("" : "=r"(held_count), "=r"(held0), "=r"(held1), "=r"(held2), "=r"(held3));
                    units = (u8 *)turns - 0x21EC;
                    asm("" : "+r"(units) : "r"(held_count), "r"(held0), "r"(held1), "r"(held2), "r"(held3));
                }
                {
                    register u8 *initial_count asm("r0") = (u8 *)turns - 3;
                    asm("" : "+r"(initial_count));
                    count = initial_count;
                }
                do
                {
                {
                    register u32 turn_offset asm("r0") = i * sizeof(struct Turn);
                    asm("" : "+r"(turn_offset));
                    turn = (struct Turn *)(turn_offset + (u32)turns);
                }
                if (({
                    register u32 slot asm("r0") = turn->slot;
                    register u32 offset asm("r1");
                    register u32 side asm("r2");
                    register u32 side_offset asm("r0");
                    register u32 status_offset asm("r2");
                    register u16 flags asm("r1");
                    asm("" : "+r"(slot));
                    offset = slot * sizeof(struct Status);
                    asm("" : "+r"(offset));
                    side = turn->side;
                    asm("" : "+r"(side));
                    side_offset = side * sizeof(D_0200EB84.status[0]);
                    asm("" : "+r"(side_offset));
                    offset += side_offset;
                    asm("" : "+r"(offset));
                    offset += (u32)battle;
                    asm("" : "+r"(offset));
                    status_offset = 0x220C;
                    asm("" : "+r"(status_offset));
                    offset += status_offset;
                    asm("" : "+r"(offset));
                    flags = *(u16 *)offset;
                    asm("" : "+r"(flags));
                    flags;
                }) & 1)
                {
                    func_08003ED8(task, ({
                        register u32 held2 asm("r2");
                        register u32 held3 asm("r3");
                        register s32 value asm("r1");
                        asm("" : "=r"(held2), "=r"(held3));
                        value = task->count;
                        asm("" : "+r"(value) : "r"(held2), "r"(held3));
                        value;
                    }), func_0802D9A4);
                    {
                        struct Child *child = task->children[({
                        register u32 held0 asm("r0");
                        register u32 held3 asm("r3");
                        register s32 value asm("r1");
                        asm("" : "=r"(held0), "=r"(held3));
                        value = task->count;
                        asm("" : "+r"(value) : "r"(held0), "r"(held3));
                        value;
                    })];
                        u32 address = turn->side * sizeof(struct Side) + (u32)units;
                        asm("" : "+r"(address) : : "r2");
                        child->unit = (struct Unit *)(address + turn->slot * sizeof(struct Unit));
                    }
                    task->count++;
                }
                i++;
                } while (i < ({
                    register u8 *query asm("r4") = count;
                    register u32 value asm("r4");
                    asm("" : "+r"(query));
                    value = *query;
                    asm("" : "+r"(value));
                    value;
                }));
            }
            if (({
                        register u32 held2 asm("r2");
                        register u32 held3 asm("r3");
                        register u32 held4 asm("r4");
                        register s32 value asm("r0");
                        asm("" : "=r"(held2), "=r"(held3), "=r"(held4));
                        value = task->count;
                        asm("" : "+r"(value) : "r"(held2), "r"(held3), "r"(held4));
                        value;
                    }))
            {
                func_080019EC(0x5A);
                task->state = 100;
            }
            else
            {
                task->state = 1000;
            }
            break;
        case 100:
        {
            s32 count;
            func_08003EA4(task);
            i = 0;
            {
                register u32 held0 asm("r0");
                register u32 held3 asm("r3");
                register s32 loaded_count asm("r1");
                asm("" : "=r"(held0), "=r"(held3));
                loaded_count = task->count;
                asm("" : "+r"(loaded_count) : "r"(held0), "r"(held3));
                count = loaded_count;
            }
            if (i < count && task->children[i]->busy)
            {
                register u32 state asm("r3") = 900;
                register s32 loop_count asm("r2");
                struct Child **children;
                asm volatile("" : "+r"(state));
                loop_count = count;
                asm("" : "+r"(loop_count) : "r"(state));
                {
                    register struct Child **initial_children asm("r1");
                    asm volatile("" : "=r"(initial_children) : "0"(task));
                    initial_children = (struct Child **)((u8 *)initial_children + 0x48);
                    asm("" : "+r"(initial_children));
                    children = initial_children;
                }
                asm("" : "+r"(children));
                do
                {
                    task->state = state;
                    i++;
                } while (i < loop_count && ((struct Child *)*(u32 *)((u32)children + ({
                    register u32 offset asm("r0") = i * 4;
                    asm("" : "+r"(offset));
                    offset;
                })))->busy);
            }
            break;
        }
        case 900:
            for (i = 0; i < task->count; i++)
                func_08003F40(task, i);
            task->state = 1000;
        case 1000:
        {
            func_08032134(5);
            task->count = 0;
            i = 0;
            if (i < ({
                register u8 *pointer asm("r4") = &D_02010D75;
                register u32 value asm("r4");
                asm("" : "+r"(pointer));
                value = *pointer;
                asm("" : "+r"(value));
                value;
            }))
            {
                struct Turn *turns;
                register struct Battle *battle asm("r9");
                struct Child **children;
                u8 *count;
                {
                    register u32 address asm("r0") = (u32)D_02010D78;
                    asm("" : "+r"(address));
                    turns = (struct Turn *)address;
                    asm("" : "+r"(turns) : "r"(address));
                }
                {
                    register u32 offset asm("r1") = (u32)-0x21F4;
                    register u32 address asm("r1");

                    asm("" : "+r"(offset));
                    address = (u32)turns + offset;
                    asm("" : "+r"(address) : "r"(offset));
                    battle = (struct Battle *)address;
                    asm("" : "+r"(battle) : "r"(address));
                }
                children = task->children;
                {
                    register u32 offset asm("r2") = (u32)-3;
                    register u32 address asm("r2");
                    asm("" : "+r"(offset));
                    address = (u32)turns + offset;
                    asm("" : "+r"(address) : "r"(offset));
                    count = (u8 *)address;
                    asm("" : "+r"(count) : "r"(address));
                }
                do
                {
                {
                    register u32 turn_offset asm("r0") = i * sizeof(struct Turn);
                    asm("" : "+r"(turn_offset));
                    turn = (struct Turn *)(turn_offset + (u32)turns);
                }
                if (({
                    register u32 slot asm("r0") = turn->slot;
                    register u32 offset asm("r1");
                    register u32 side asm("r2");
                    register u32 side_offset asm("r0");
                    register u32 status_offset asm("r2");
                    register u16 flags asm("r1");
                    asm("" : "+r"(slot));
                    offset = slot * sizeof(struct Status);
                    asm("" : "+r"(offset));
                    side = turn->side;
                    asm("" : "+r"(side));
                    side_offset = side * sizeof(D_0200EB84.status[0]);
                    asm("" : "+r"(side_offset));
                    offset += side_offset;
                    asm("" : "+r"(offset));
                    offset += (u32)battle;
                    asm("" : "+r"(offset));
                    status_offset = 0x220C;
                    asm("" : "+r"(status_offset));
                    offset += status_offset;
                    asm("" : "+r"(offset));
                    flags = *(u16 *)offset;
                    asm("" : "+r"(flags));
                    flags;
                }) & 8)
                {
                    func_08003ED8(task, ({
                        register u32 held2 asm("r2");
                        register u32 held3 asm("r3");
                        register s32 value asm("r1");
                        asm("" : "=r"(held2), "=r"(held3));
                        value = task->count;
                        asm("" : "+r"(value) : "r"(held2), "r"(held3));
                        value;
                    }), func_0802CD38);
                    {
                        register struct Child *child asm("r3") = *(struct Child **)((u32)children + ({
                            register u32 offset asm("r0") = task->count * 4;
                            asm("" : "+r"(offset));
                            offset;
                        }));
                        register u32 address asm("r0") = turn->side * sizeof(struct Side);
                        register u32 base asm("r2");
                        register u32 slot asm("r2");
                        register u32 unit_stride asm("r1");
                        asm("" : "+r"(child), "+r"(address));
                        base = (u32)D_0200EB8C;
                        asm("" : "+r"(base));
                        address += base;
                        asm("" : "+r"(address));
                        slot = turn->slot;
                        asm("" : "+r"(slot));
                        unit_stride = sizeof(struct Unit);
                        asm("" : "+r"(unit_stride));
                        child->unit = (struct Unit *)(address + slot * unit_stride);
                    }
                    (*(struct Child **)((u32)children + ({
                        register u32 held asm("r2");
                        register s32 value asm("r0");
                        asm("" : "=r"(held));
                        value = task->count;
                        value *= 4;
                        asm("" : "+r"(value) : "r"(held));
                        value;
                    })))->side = turn->side;
                    (*(struct Child **)((u32)children + ({
                        register u32 held asm("r1");
                        register s32 value asm("r0");
                        asm("" : "=r"(held));
                        value = task->count;
                        value *= 4;
                        asm("" : "+r"(value) : "r"(held));
                        value;
                    })))->slot = turn->slot;
                    task->count++;
                }
                i++;
                } while (i < *count);
            }
            if (task->count)
                task->state = 1100;
            else
                task->state = 2000;
            break;
        }
        case 1100:
            func_08003EA4(task);
            i = 0;
            if (i < task->count && task->children[i]->busy)
            {
                do
                {
                    task->state = 1900;
                    i++;
                } while (i < task->count && task->children[i]->busy);
            }
            break;
        case 1900:
            for (i = 0; i < task->count; i++)
                func_08003F40(task, i);
            task->state = 2000;
        case 2000:
        {
            func_08032134(6);
            task->count = 0;
            i = 0;
            if (i < ({
                register u8 *pointer asm("r4") = &D_02010D75;
                register u32 value asm("r4");
                asm("" : "+r"(pointer));
                value = *pointer;
                asm("" : "+r"(value));
                value;
            }))
            {
                struct Turn *turns;
                register struct Battle *battle asm("r9");
                struct Child **children;
                u8 *count;
                {
                    register u32 address asm("r0") = (u32)D_02010D78;
                    asm("" : "+r"(address));
                    turns = (struct Turn *)address;
                    asm("" : "+r"(turns) : "r"(address));
                }
                {
                    register u32 offset asm("r1") = (u32)-0x21F4;
                    register u32 address asm("r1");

                    asm("" : "+r"(offset));
                    address = (u32)turns + offset;
                    asm("" : "+r"(address) : "r"(offset));
                    battle = (struct Battle *)address;
                    asm("" : "+r"(battle) : "r"(address));
                }
                children = task->children;
                {
                    register u32 offset asm("r2") = (u32)-3;
                    register u32 address asm("r2");
                    asm("" : "+r"(offset));
                    address = (u32)turns + offset;
                    asm("" : "+r"(address) : "r"(offset));
                    count = (u8 *)address;
                    asm("" : "+r"(count) : "r"(address));
                }
                do
                {
                {
                    register u32 turn_offset asm("r0") = i * sizeof(struct Turn);
                    asm("" : "+r"(turn_offset));
                    turn = (struct Turn *)(turn_offset + (u32)turns);
                }
                if (({
                    register u32 slot asm("r0") = turn->slot;
                    register u32 offset asm("r1");
                    register u32 side asm("r2");
                    register u32 side_offset asm("r0");
                    register u32 status_offset asm("r2");
                    register u16 flags asm("r1");
                    asm("" : "+r"(slot));
                    offset = slot * sizeof(struct Status);
                    asm("" : "+r"(offset));
                    side = turn->side;
                    asm("" : "+r"(side));
                    side_offset = side * sizeof(D_0200EB84.status[0]);
                    asm("" : "+r"(side_offset));
                    offset += side_offset;
                    asm("" : "+r"(offset));
                    offset += (u32)battle;
                    asm("" : "+r"(offset));
                    status_offset = 0x220C;
                    asm("" : "+r"(status_offset));
                    offset += status_offset;
                    asm("" : "+r"(offset));
                    flags = *(u16 *)offset;
                    asm("" : "+r"(flags));
                    flags;
                }) & 4)
                {
                    func_08003ED8(task, ({
                        register u32 held2 asm("r2");
                        register u32 held3 asm("r3");
                        register s32 value asm("r1");
                        asm("" : "=r"(held2), "=r"(held3));
                        value = task->count;
                        asm("" : "+r"(value) : "r"(held2), "r"(held3));
                        value;
                    }), func_0802DAF4);
                    {
                        register struct Child *child asm("r3") = *(struct Child **)((u32)children + ({
                            register u32 offset asm("r0") = task->count * 4;
                            asm("" : "+r"(offset));
                            offset;
                        }));
                        register u32 address asm("r0") = turn->side * sizeof(struct Side);
                        register u32 base asm("r2");
                        register u32 slot asm("r2");
                        register u32 unit_stride asm("r1");
                        asm("" : "+r"(child), "+r"(address));
                        base = (u32)D_0200EB8C;
                        asm("" : "+r"(base));
                        address += base;
                        asm("" : "+r"(address));
                        slot = turn->slot;
                        asm("" : "+r"(slot));
                        unit_stride = sizeof(struct Unit);
                        asm("" : "+r"(unit_stride));
                        child->unit = (struct Unit *)(address + slot * unit_stride);
                    }
                    (*(struct Child **)((u32)children + ({
                        register u32 held asm("r2");
                        register s32 value asm("r0");
                        asm("" : "=r"(held));
                        value = task->count;
                        value *= 4;
                        asm("" : "+r"(value) : "r"(held));
                        value;
                    })))->side = turn->side;
                    (*(struct Child **)((u32)children + ({
                        register u32 held asm("r1");
                        register s32 value asm("r0");
                        asm("" : "=r"(held));
                        value = task->count;
                        value *= 4;
                        asm("" : "+r"(value) : "r"(held));
                        value;
                    })))->slot = turn->slot;
                    task->count++;
                }
                i++;
                } while (i < *count);
            }
            if (task->count)
                task->state = 2100;
            else
                task->state = 4000;
            break;
        }
        case 2100:
            func_08003EA4(task);
            i = 0;
            if (i < task->count && task->children[i]->busy)
            {
                do
                {
                    task->state = 2900;
                    i++;
                } while (i < task->count && task->children[i]->busy);
            }
            break;
        case 2900:
            for (i = 0; i < task->count; i++)
                func_08003F40(task, i);
            task->state = 4000;
        case 4000:
        {
            u32 unit_size;
            task->level = 0;
            func_08032134(1);
            task->count = 0;
            i = 0;
            if (i < D_02010D75)
            {
                register struct Turn *turns asm("r9") = ({
                    register u32 address asm("r1") = (u32)D_02010D78;
                    asm("" : "+r"(address));
                    (struct Turn *)address;
                });
                u8 *battle = (u8 *)turns - 0x21F4;
                register u32 side_size asm("r8");
                u8 *count;
                asm("" : "+r"(battle) : "r"(turns));
                side_size = ({
                    register u32 value asm("r2") = sizeof(struct Side);
                    asm("" : "+r"(value));
                    value;
                });
                count = ({
                    register u32 address asm("r4") = 0x21F1;
                    asm("" : "+r"(address));
                    address += (u32)battle;
                    asm("" : "+r"(address));
                    (u8 *)address;
                });
                asm("" : : "r"(side_size), "r"(count));
                {
                    register u32 entry asm("r3") = sizeof(struct Unit);
                    asm("" : "+r"(entry));
                    unit_size = entry;
                }
                do
                {
                turn = (struct Turn *)(({
                    register u32 offset asm("r0") = i * sizeof(struct Turn);
                    asm("" : "+r"(offset));
                    offset;
                }) + (u32)turns);
                if (({
                    register u32 slot asm("r0") = turn->slot;
                    register u32 offset asm("r1");
                    register u32 side asm("r2");
                    register u32 side_offset asm("r0");
                    register u32 status_offset asm("r2");
                    register u16 flags asm("r0");
                    asm("" : "+r"(slot));
                    offset = slot * sizeof(struct Status);
                    asm("" : "+r"(offset));
                    side = turn->side;
                    asm("" : "+r"(side));
                    side_offset = side * sizeof(D_0200EB84.status[0]);
                    asm("" : "+r"(side_offset));
                    offset += side_offset;
                    asm("" : "+r"(offset));
                    offset += (u32)battle;
                    asm("" : "+r"(offset));
                    status_offset = 0x220C;
                    asm("" : "+r"(status_offset));
                    offset += status_offset;
                    asm("" : "+r"(offset));
                    flags = *(u16 *)offset;
                    asm("" : "+r"(flags));
                    flags;
                }) & 0x8000)
                {
                    func_08003ED8(task, task->count, func_0802DBE4);
                    {
                        struct Child *child = task->children[task->count];
                        register u32 side_bytes asm("r0") = turn->side * side_size;
                        register u8 *unit_base asm("r1");
                        register u32 slot asm("r1");
                        asm("" : "+r"(side_bytes));
                        unit_base = battle + 8;
                        asm("" : "+r"(unit_base));
                        side_bytes += (u32)unit_base;
                        asm("" : "+r"(side_bytes));
                        slot = turn->slot;
                        asm("" : "+r"(slot));
                        child->unit = (struct Unit *)(side_bytes + slot * unit_size);
                    }
                    task->count++;
                    {
                        s32 previous = task->level;
                        u8 level = ({
                            u32 offset = turn->slot * unit_size + turn->side * side_size;
                            asm("" : "+r"(offset));
                            *(u8 *)(offset + (u32)battle + 0x45);
                        });
                        if (previous < level)
                            task->level = level;
                    }
                }
                    i++;
                } while (i < *count);
            }
            if (task->count)
            {
                task->state = 4100;
                switch (task->level)
                {
                case 0:
                    func_080019EC(0x5B);
                    break;
                case 1:
                    func_080019EC(0x5C);
                    break;
                case 2:
                    func_080019EC(0x5D);
                    break;
                }
            }
            else
            {
                task->state = 9000;
            }
            break;
        }
        case 4100:
            func_08003EA4(task);
            i = 0;
            if (i < task->count && task->children[i]->busy)
            {
                do
                {
                    task->state = 4900;
                    i++;
                } while (i < task->count && task->children[i]->busy);
            }
            break;
        case 4900:
            for (i = 0; i < task->count; i++)
                func_08003F40(task, i);
            task->state = 9000;
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
