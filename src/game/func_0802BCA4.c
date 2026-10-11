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

struct Status
{
    u8 pad_0[8];
    u8 action;
    u8 pad_9[3];
};

struct StatusRow
{
    struct Status units[6];
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
    u8 pad_2[0x21F2];
    struct Turn turns[6];
    struct StatusRow status[2];
} D_0200EB84;

extern u8 D_02000030;
extern struct Task D_02000034[];
extern const u8 *D_08663D44[];
extern const u8 D_08675BEC[];

extern struct
{
    u8 pad_0[0x14];
    s32 field_14;
} D_03004B9C;

void func_08000DB8(void);
void func_08000D1C(s32);
void func_08001DE4(const u8 *);
void func_08031074(void);
void func_080317D0(void);
void func_0802F07C(void);
void func_0803E488(const u8 *, s32);
void func_08003DF8(s32, void *);
void func_08003E3C(s32);
void func_08004034(void);
void func_08034AA0(void);
void func_0802D36C(void);
void func_0802C084(void);
void func_0802CA54(void);
void func_0802CE98(void);
void func_0802C8EC(void);
void func_0802C420(void);
void func_0802C708(void);
void func_0802D224(void);
void func_0802D0C0(void);
void func_0802C014(void);
void func_0805EE78(s32);

void func_0802BCA4(void)
{
    struct Status *status;
    struct Task *task = &D_02000034[D_02000030];

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            func_08000DB8();
            func_08000D1C(0);
            func_08001DE4(D_08663D44[24]);
            func_08031074();
            func_080317D0();
            D_03004B9C.field_14 = 0xFFF40000;
            func_0802F07C();
            func_0803E488(D_08675BEC, 2);
            task->state = 100;
            break;
        case 100:
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 0;
            D_02000034[10].data = 0;
            task->state = 200;
            break;
        case 200:
            if (D_02000034[10].busy == 1)
            {
                func_08003E3C(10);
                task->state = 1000;
                if (D_0200EB84.flags & 0x20)
                    task->state = 300;
            }
            break;
        case 300:
            func_08003DF8(6, func_08034AA0);
            D_02000034[6].message = 0xFD06;
            task->state = 310;
            break;
        case 310:
            if (D_02000034[6].busy == 1)
            {
                func_08003E3C(6);
                task->state = 1000;
            }
            break;
        case 1000:
            status = &D_0200EB84.status[D_0200EB84.turns[0].side].units[D_0200EB84.turns[0].slot];
            switch (status->action)
            {
            case 0:
                task->state = 2000;
                break;
            case 1:
                task->state = 2100;
                break;
            case 2:
                task->state = 2200;
                break;
            case 3:
                task->state = 2300;
                break;
            case 4:
                task->state = 2400;
                break;
            case 5:
                task->state = 2500;
                break;
            }
            break;
        case 2000:
            func_08003DF8(6, func_0802D36C);
            func_08003DF8(7, func_0802C084);
            task->state = 7000;
            break;
        case 2100:
            func_08003DF8(6, func_0802CA54);
            func_08003DF8(7, func_0802CE98);
            task->state = 7000;
            break;
        case 2200:
            func_08003DF8(6, func_0802C8EC);
            func_08003DF8(7, func_0802CE98);
            task->state = 7000;
            break;
        case 2300:
            func_08003DF8(6, func_0802C420);
            func_08003DF8(7, func_0802C708);
            task->state = 7000;
            break;
        case 2400:
            func_08003DF8(6, func_0802CA54);
            func_08003DF8(7, func_0802D224);
            task->state = 7000;
            break;
        case 2500:
            func_08003DF8(6, func_0802CA54);
            func_08003DF8(7, func_0802D0C0);
            task->state = 7000;
            break;
        case 7000:
            if (D_02000034[7].busy == 1)
            {
                func_08003E3C(7);
                task->state = 7100;
            }
            break;
        case 7100:
            if (D_02000034[6].busy == 1)
            {
                func_08003E3C(6);
                task->state = 8000;
            }
            break;
        case 8000:
            func_0802C014();
            task->state = 9000;
            break;
        case 9000:
            task->busy = 1;
            task->state = 9010;
            break;
        }
        func_0805EE78(1);
    }
}
