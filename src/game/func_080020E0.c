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
    u32 field_1C;
    u8 pad_20[8];
    s16 timer;
    u8 pad_2A[2];
    s16 mode;
    u8 pad_2E[0x5A];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern u8 D_0200E8A8;
extern const u8 *D_08663D44[];
extern const u8 D_0874FA90[];

extern struct
{
    s32 field_0;
    s32 field_4;
} D_03004B9C;

extern struct
{
    u8 pad_0[2];
    u16 cursor;
    u8 pad_4[0xA];
    u16 field_E;
} D_02007574;

void func_080019A4(s32);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_08001DE4(const u8 *);
void func_08003DF8(s32, void *);
void func_08004034(void);
void func_08003D78(s32, void *);
void func_0800248C(void);
void func_0805EE78(s32);
void func_08003E3C(s32);
void func_0803E134(s32, s32, s32, s32);
void func_080013D0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_080019EC(s32);
void func_0803E454(s32);
void func_0803E488(const u8 *, s32);
void func_080034AC(void);

void func_080020E0(void)
{
    struct Task *task = &D_02000034[D_02000030];

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            func_080019A4(1);
            func_08000DB8();
            func_08000D1C(0);
            func_08001DE4(D_08663D44[12]);
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 0;
            D_02000034[10].data = 0;
            task->state = 100;
            D_0200E8A8 = 0;
            func_08003D78(3, func_0800248C);
            func_0805EE78(1);
            break;
        case 100:
            if (D_02000034[10].busy == 1)
            {
                func_08003E3C(10);
                task->state = 200;
            }
            break;
        case 200:
            if (D_0200E8A8 & 1)
            {
                D_03004B9C.field_0 = D_03004B9C.field_4 = 0;
                func_0803E134(3, 4, 0, 0x32);
                func_080013D0(0xB4, 0x20, 0x16, 0, 10, 0, 0, 0);
                func_080019EC(0x3D);
                func_0803E454(9);
                switch (D_02000034[2].field_1C = D_02007574.cursor)
                {
                case 6:
                    func_0803E454(1);
                    if (D_02007574.field_E)
                    {
                        func_0803E134(3, 0, 0, 0x32);
                        func_0803E488(D_0874FA90, D_02007574.cursor);
                    }
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                    task->state = 9000;
                    break;
                }
            }
            else if ((D_0200E8A8 & 0xA) == 8)
            {
                if (++task->timer > 599)
                {
                    D_0200E8A8 |= 4;
                    func_0805EE78(1);
                    task->timer = 0;
                    task->state = 2000;
                }
            }
            break;
        case 2000:
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 1;
            D_02000034[10].data = 0;
            task->state = 2100;
            break;
        case 2100:
            if (D_02000034[10].busy == 1)
            {
                func_08003E3C(10);
                task->state = 2200;
            }
            break;
        case 2200:
            func_08003DF8(3, func_080034AC);
            D_02000034[3].message = task->mode;
            task->state = 2300;
            break;
        case 2300:
            if (D_02000034[3].busy == 1)
            {
                func_08003E3C(3);
                if (++task->mode > 1)
                    task->mode = 0;
                task->state = 0;
            }
            break;
        case 9000:
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 1;
            D_02000034[10].data = 0;
            task->state = 9100;
            break;
        case 9100:
            if (D_02000034[10].busy == 1)
            {
                func_08003E3C(10);
                task->state = 9200;
            }
            break;
        case 9200:
            task->busy = 1;
            task->state = 9300;
            break;
        case 9300:
            break;
        }
        func_0805EE78(1);
    }
}
