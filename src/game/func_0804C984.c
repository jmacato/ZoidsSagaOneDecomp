#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 message;
    u32 data;
    u8 pad_10[8];
    s32 busy;
    u8 pad_1C[0x6C];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
struct Sprite
{
    u16 flags;
    u8 pad_2[0x86];
};

extern struct Sprite D_03004BBC[];
extern s32 D_0200059C;
extern u16 D_03002356;
extern u16 D_0300235A;
extern u16 D_03002358;

extern struct
{
    u16 result;
    u8 pad_2[0xA];
    u16 field_C;
} D_02007574;

void func_0804BDC8(void);
void func_08043CD8(s32, s32);
void func_08003DF8(s32, void *);
void func_08004034(void);
void func_0803E454(s32);
void func_0804C918(void);
u16 func_0800175C(s32, s32);
u8 func_0804C2D0(u16);
void func_08000BD8(s32, s32);
void func_080019EC(s32);
void func_0804BF78(void);
void func_08003E3C(s32);
void func_0804206C(void);
u8 func_08042094(void);
void func_08041E1C(void);
void func_0805EE78(s32);

void func_0804C984(void)
{
    struct Task *task = &D_02000034[D_02000030];
    s32 next;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            next = 1;
            task->state = 0x1001;
        case 1:
            func_0804BDC8();
            func_08043CD8(0x1B, 0);
            D_02007574.field_C = 0;
            task->state = 2;
            break;
        case 2:
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 0;
            D_02000034[10].data = 0;
            func_0803E454(0x1A);
            func_0803E454(0x1B);
            func_0804C918();
            next = 0x20;
            task->state = 0x1020;
            break;
        case 0x20:
            if (func_0804C2D0(func_0800175C(0x10, 6)) == 0xFF)
            {
                func_08000BD8(1, 3);
                task->state++;
            }
            break;
        case 0x21:
            func_080019EC(0x47);
            D_03004BBC[3].flags &= 0x7FFF;
            func_0804BF78();
            func_0803E454(0x1F);
            D_03004BBC[3].flags |= 0x8000;
            func_08000BD8(1, 0);
            if (D_02007574.result == 0xFF)
            {
                func_080019EC(0x3F);
                task->state = 0x20;
                break;
            }
            task->state++;
            break;
        case 0x22:
            next = 0x2000;
            task->state = 0x1001;
            break;
        case 0x23:
            task->state = 2;
            break;
        case 0x1020:
            if (D_02000034[10].busy == 1)
            {
                func_08003E3C(10);
                task->state = next;
            }
            break;
        case 0x30:
            D_03002356 = 0x10;
            task->state = 0x40;
            break;
        case 0x40:
            if (D_03002356 & 0xF)
                D_03002356--;
            else
                task->state = next;
            break;
        case 0x1000:
            func_0804206C();
            task->state = 0x1002;
            break;
        case 0x1001:
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 1;
            D_02000034[10].data = 0;
            task->state = 0x1020;
            break;
        case 0x1002:
            if (func_08042094())
                task->state = next;
            break;
        case 0x1005:
            if (D_0300235A & 8)
            {
                next = 0x2000;
                task->state = 0x1001;
            }
            if (D_0300235A & 1)
                task->state = 0x1001;
            if (D_03002358 & 2)
                task->state = 0x1001;
            break;
        case 0x50:
        case 0x1003:
            func_08003E3C(10);
            task->state = 0x1001;
            next = 0x2000;
            break;
        case 0x2000:
            func_0803E454(8);
            func_08003E3C(8);
            func_08041E1C();
            task->state = 0x2001;
            task->busy = 1;
            func_08003E3C(6);
            task->busy = 1;
            break;
        }
        func_0805EE78(1);
    }
}
