#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 message;
    u8 pad_C[0xC];
    s32 busy;
    u32 result;
    u8 pad_20[0x68];
};

extern u8 D_02000030;
extern struct Task D_02000034[];

extern struct
{
    u16 field_0;
    u16 field_2;
} D_02004A6C;

void func_08003DF8(s32, void *);
void func_08003E3C(s32);
u8 func_08003C14(s32);
void func_08059338(void);
void func_08003948(void);
void func_08003B3C(void);
void func_08033A78(u8);
void func_08003F70(void);
void func_08001F8C(void);
void func_080020E0(void);
void func_0800BF80(void);
void func_0800BFB4(void);
void func_08009A58(void);
void func_0802AC0C(void);
void func_08039608(void);
void func_080034AC(void);
void func_0804313C(void);
void func_0804D03C(void);
void func_0804C984(void);
void func_08043B10(void);
void func_080056C4(void);
void func_080041B4(void);
void func_0805EE78(s32);

void func_080035F0(void)
{
    struct Task *task = &D_02000034[D_02000030];

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            func_08003DF8(9, func_08003F70);
            task->state = 100;
            break;
        case 100:
            func_08003DF8(2, func_08001F8C);
            task->state = 110;
            break;
        case 200:
            func_08003DF8(2, func_080020E0);
            task->state = 210;
            break;
        case 210:
            if (D_02000034[2].busy == 1)
            {
                func_08003C14(0);
                switch (D_02000034[2].result)
                {
                case 0:
                    D_02004A6C.field_2 = 0;
                    D_02004A6C.field_0 = 0;
                    func_08059338();
                    func_08003948();
                    func_08003B3C();
                    task->state = 300;
                    break;
                case 1:
                    func_08003948();
                    if (func_08003C14(1))
                        task->state = 200;
                    else
                        task->state = 301;
                    break;
                case 2:
                    task->state = 700;
                    break;
                case 3:
                    task->state = 400;
                    break;
                case 5:
                    task->state = 501;
                    break;
                case 7:
                    task->state = 302;
                    break;
                case 4:
                    task->state = 500;
                    break;
                case 6:
                    task->state = 200;
                    break;
                case 8:
                    task->state = 2000;
                    break;
                case 9:
                    task->state = 600;
                    break;
                case 10:
                    task->state = 650;
                    break;
                case 11:
                    task->state = 2200;
                    break;
                }
                func_08003E3C(2);
            }
            break;
        case 300:
            func_08003DF8(2, func_0800BF80);
            task->state = 310;
            break;
        case 301:
            func_08003DF8(2, func_0800BFB4);
            task->state = 310;
            break;
        case 302:
            func_08003DF8(2, func_08009A58);
            task->state = 310;
            break;
        case 400:
            func_08033A78(0);
            func_08003DF8(4, func_0802AC0C);
            task->state = 410;
            break;
        case 700:
            func_08003DF8(2, func_08039608);
            task->state = 710;
            break;
        case 800:
            func_08003DF8(3, func_080034AC);
            D_02000034[3].message = 0;
            task->state = 810;
            break;
        case 810:
            if (D_02000034[3].busy == 1)
            {
                func_08003E3C(3);
                task->state = 200;
            }
            break;
        case 500:
            func_08003DF8(4, func_0804313C);
            task->state = 410;
            break;
        case 501:
            func_08003DF8(4, func_0804D03C);
            task->state = 410;
            break;
        case 600:
            func_08003DF8(4, func_0804C984);
            task->state = 410;
            break;
        case 650:
            func_08003DF8(4, func_08043B10);
            task->state = 410;
            break;
        case 410:
            if (D_02000034[4].busy == 1)
            {
                func_08003E3C(4);
                task->state = 200;
            }
            break;
        case 2000:
            func_08003DF8(2, func_080056C4);
            task->state = 2010;
            break;
        case 2200:
            func_08003DF8(2, func_080041B4);
            task->state = 2210;
            break;
        case 110:
        case 310:
        case 710:
        case 2010:
        case 2210:
            if (D_02000034[2].busy == 1)
            {
                func_08003E3C(2);
                task->state = 200;
            }
            break;
        }
        func_0805EE78(1);
    }
}
