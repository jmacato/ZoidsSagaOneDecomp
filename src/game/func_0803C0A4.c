#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 flags;
    u8 pad_C[12];
    u32 busy;
    u8 pad_1C[12];
    u8 excluded_side;
    u8 excluded_slot;
    u8 pad_2A[0x5E];
};

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[0x33];
    u8 level;
    u8 pad_3E[0x28E];
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

struct Status
{
    u16 flags;
    u8 pad_2[10];
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
extern u8 D_02010D74;
extern u8 D_02010D75;
extern u8 D_02000030;
extern struct Task D_02000034[];

s32 func_08032A88(u8, u8);
u8 func_08032AC4(u8, u8);
void func_08003DF8(u32, void (*)(void));
void func_08003E3C(u32);
void func_0803C838(u32);
void func_0805EE78(u32);
void func_0802DE74(void);
void func_0802C420(void);
void func_0802CA54(void);
void func_0802C8EC(void);
void func_0802DCB4(void);
void func_0802E144(void);
void func_0802E40C(void);

void func_0803C0A4(void)
{
    struct Task *task = &D_02000034[D_02000030];
    u32 flags;
    u32 passes;
    u8 side;
    u8 index;
    u8 slot;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            {
                register struct Task *source asm("r4") = task;
                register u32 captured asm("r4");
                register u32 value asm("r0");
                register u8 *field asm("r5");
                asm("" : "+r"(source));
                captured = source->flags;
                asm("" : "+r"(captured));
                flags = captured;
                asm("" : : "r"(flags));
                value = 0xFF;
                asm("" : "+r"(value));
                field = &D_02010D74;
                asm("" : "+r"(field) : "r"(value));
                *field = value;
                asm("" : : "r"(captured));
            if (captured & 4)
            {
                register u32 count asm("r7") = 2;
                asm("" : "+r"(count));
                passes = count;
                side = 0;
            }
            else
            {
                passes = 1;
                asm("" : "+m"(passes));
                {
                    register u32 mask asm("r0") = flags;
                    register u32 count asm("r1");
                    asm("" : "+r"(mask));
                    count = passes;
                    asm("" : "+r"(count) : "r"(mask));
                    mask &= count;
                    asm("" : "+r"(mask));
                    side = 1;
                    asm("" : : "r"(side), "r"(mask));
                    if (mask)
                        side = 0;
                }
            }
            }
        case 100:
            {
            register u32 rejected_leader asm("r0");
            if (({
                register u32 mask asm("r1") = 0x10;
                register u32 selection asm("r2");
                asm("" : : "r"(mask));
                selection = flags;
                asm("" : "+r"(selection) : "r"(mask));
                mask & selection;
            }))
            {
                {
                    register u32 zero asm("r4") = 0;
                    register u8 *field asm("r3");
                    asm("" : "+r"(zero));
                    field = &D_02010D75;
                    asm("" : "+r"(field) : "r"(zero));
                    *field = zero;
                }
                index = 0;
                for (slot = 0; slot <= 5; slot++)
                {
                    if (func_08032A88(side, slot))
                    {
                        D_0200EB84.count++;
                        D_0200EB84.turns[index].side = side;
                        D_0200EB84.turns[index].slot = slot;
                        index++;
                    }
                }
            }
            else if (({
                register u32 mask asm("r0") = 0x20;
                register u32 value asm("r2");
                asm("" : : "r"(mask));
                value = flags;
                asm("" : "+r"(value) : "r"(mask));
                mask &= value;
                asm("" : : "r"(mask));
                rejected_leader = mask;
                mask;
            }))
            {
                {
                    register u32 held2 asm("r2");
                    asm("" : "=r"(held2));
                    D_0200EB84.count = 0;
                    asm("" : : "r"(held2));
                }
                slot = func_08032AC4(side, 0);
                if (func_08032A88(side, slot))
                {
                    D_0200EB84.count = 1;
                    D_0200EB84.turns[0].side = side;
                    D_0200EB84.turns[0].slot = slot;
                }
            }
            else if (flags & 0x40)
            {
                { register u8 *counter asm("r5") = &D_02010D75; *counter = rejected_leader; }
                index = 0;
                for (slot = 0; slot <= 2; slot++)
                {
                    if (func_08032A88(side, slot))
                    {
                        D_0200EB84.count++;
                        D_0200EB84.turns[index].side = side;
                        D_0200EB84.turns[index].slot = slot;
                        index++;
                    }
                }
            }
            else if (flags & 0x80)
            {
                { register u8 *counter asm("r3") = &D_02010D75; *counter = 0; }
                index = 0;
                {
                    register u32 scale asm("r7");
                    register u32 cached asm("sl");

                    slot = 3;
                    asm("" : : "r"(slot));
                    scale = side << 3;
                    asm("" : : "r"(scale));
                    cached = scale;
                    asm("" : : "r"(cached));
                    asm volatile("" : "=r"(scale));
                }
                for (; slot <= 5; slot++)
                {
                    if (func_08032A88(side, slot))
                    {
                        D_0200EB84.count++;
                        D_0200EB84.turns[index].side = side;
                        D_0200EB84.turns[index].slot = slot;
                        index++;
                    }
                }
            }
            else if (flags & 0x200)
            {
                D_0200EB84.count = 0;
                index = 0;
                for (slot = 0; slot <= 5; slot++)
                {
                    if (func_08032A88(side, slot) && (D_0200EB84.sides[side].units[slot].flags & 2))
                    {
                        D_0200EB84.count++;
                        D_0200EB84.turns[index].side = side;
                        D_0200EB84.turns[index].slot = slot;
                        index++;
                    }
                }
            }
            else if (flags & 0x100)
            {
                D_0200EB84.count = 0;
                index = 0;
                for (slot = 0; slot <= 5; slot++)
                {
                    if (func_08032A88(side, slot) && (D_0200EB84.sides[side].units[slot].flags & 4))
                    {
                        D_0200EB84.count++;
                        D_0200EB84.turns[index].side = side;
                        D_0200EB84.turns[index].slot = slot;
                        index++;
                    }
                }
            }
            else if (flags & 0x400)
            {
                D_0200EB84.count = 0;
                index = 0;
                for (slot = 0; slot <= 5; slot++)
                {
                    if (func_08032A88(side, slot) && D_0200EB84.sides[side].units[slot].level != 2)
                    {
                        D_0200EB84.count++;
                        D_0200EB84.turns[index].side = side;
                        D_0200EB84.turns[index].slot = slot;
                        index++;
                    }
                }
            }
            else if (flags & 0x800)
            {
                D_0200EB84.count = 0;
                index = 0;
                for (slot = 0; slot <= 5; slot++)
                {
                    if (func_08032A88(side, slot) && D_0200EB84.sides[side].units[slot].level != 0)
                    {
                        D_0200EB84.count++;
                        D_0200EB84.turns[index].side = side;
                        D_0200EB84.turns[index].slot = slot;
                        index++;
                    }
                }
            }
            else if (flags & 0x1000)
            {
                task->excluded_side = D_0200EB84.turns[0].side;
                task->excluded_slot = D_0200EB84.turns[0].slot;
                D_0200EB84.count = 0;
                index = 0;
                for (slot = 0; slot <= 5; slot++)
                {
                    if (func_08032A88(side, slot) && (task->excluded_side != side || task->excluded_slot != slot))
                    {
                        D_0200EB84.count++;
                        D_0200EB84.turns[index].side = side;
                        D_0200EB84.turns[index].slot = slot;
                        index++;
                    }
                }
            }
            else if (flags & 0x2000)
            {
                slot = func_08032AC4(0, 0);
                if (func_08032A88(side, slot))
                {
                    task->excluded_side = 0;
                    task->excluded_slot = slot;
                }
                D_0200EB84.count = 0;
                index = 0;
                for (slot = 0; slot <= 5; slot++)
                {
                    if (func_08032A88(side, slot) && (task->excluded_side != side || task->excluded_slot != slot))
                    {
                        D_0200EB84.count++;
                        D_0200EB84.turns[index].side = side;
                        D_0200EB84.turns[index].slot = slot;
                        index++;
                    }
                }
            }
            for (slot = 0; slot <= 5; slot++)
                D_0200EB84.status[side][slot].flags = 0;
            for (slot = 0; slot < D_0200EB84.count; slot++)
                D_0200EB84.status[D_0200EB84.turns[slot].side][D_0200EB84.turns[slot].slot].flags |= 1;
            task->state = 7000;
            if (flags & 0x20000000)
                func_08003DF8(7, func_0802DE74);
            else if (flags & 0x02000000)
                func_08003DF8(7, func_0802C420);
            else if (({ u32 action = flags & 0x04000000;
                        asm("" : "+r"(action));
                        action; }) || ({
                    register u32 mask asm("r0") = 0x40000000;
                    register u32 value asm("r1");
                    asm("" : : "r"(mask));
                    value = flags;
                    asm("" : "+r"(value) : "r"(mask));
                    mask & value;
                }))
                func_08003DF8(7, func_0802CA54);
            else if (({ register s32 value asm("r2") = flags; asm("" : : "r"(value)); value < 0; }))
                func_08003DF8(7, func_0802C8EC);
            else if (({ register u32 mask asm("r0") = 0x10000000; register u32 value asm("r3"); asm("" : : "r"(mask)); value = flags; asm("" : : "r"(value), "r"(mask)); mask & value; }))
                func_08003DF8(7, func_0802DCB4);
            else if (({ register u32 mask asm("r0") = 0x08000000; register u32 value asm("r5"); asm("" : : "r"(mask)); value = flags; asm("" : : "r"(value), "r"(mask)); mask & value; }))
            {
                if (side == 0 && ({
                    register u32 held0 asm("r0");
                    register u32 held2 asm("r2");
                    register u32 held3 asm("r3");
                    register u32 held5 asm("r5");
                    register u16 value asm("r1");

                    asm("" : "=r"(held0), "=r"(held2), "=r"(held3), "=r"(held5));
                    value = D_0200EB84.flags;
                    asm("" : : "r"(held0), "r"(held2), "r"(held3), "r"(held5), "r"(value));
                    value & 0x80;
                }))
                {
                    func_08003DF8(7, func_0802E144);
                    D_02000034[7].flags = side;
                    task->state = 3000;
                }
                else if (side == 1 && (D_0200EB84.flags & 0x100))
                {
                    func_08003DF8(7, func_0802E144);
                    D_02000034[7].flags = side;
                    task->state = 3000;
                }
                else
                    task->state = 3100;
            }
            break;
            }
        case 3000:
            if (D_02000034[7].busy == 1)
            {
                func_08003E3C(7);
                task->state = 3100;
            }
            break;
        case 3100:
            func_0803C838(flags);
            func_08003DF8(7, func_0802E40C);
            D_02000034[7].flags = flags;
            task->state = 7000;
            break;
        case 7000:
            if (D_02000034[7].busy == 1)
            {
                func_08003E3C(7);
                task->state = 9000;
                passes = (u8)(passes - 1);
                if (passes)
                {
                    side = 1;
                    task->state = 100;
                }
            }
            break;
        case 9000:
            task->busy = 1;
            task->state = 9100;
            break;
        case 9100:
            break;
        }
        func_0805EE78(1);
    }
}
