#include "text.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 message;
    u32 data;
    u8 pad_10[8];
    s32 busy;
    u8 pad_1C[0xC];
    u8 row;
    u8 pad_29;
    u8 unit;
    u8 target;
    u8 pad_2C[0x5C];
};

struct Grid
{
    u8 count;
    u8 row;
    u8 col;
    u8 pad_3;
    u16 cursor;
    u8 cells[20][9];
    u8 used[20][9];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern struct Grid D_0200E8A4;
extern struct Grid D_0200EA14;
extern u16 D_0200EB84;
extern u8 D_0200EB88[];
extern struct
{
    u16 field_0;
    u16 index;
} D_02007574;
extern u16 D_03002358;
extern u16 D_0300235A;
extern const u8 *D_08663D44[];
extern u8 D_08675BEC[];

void func_08003DF8(s32, void *);
void func_08004034(void);
void func_08003E3C(s32);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_08001DE4(const u8 *);
void func_0802F07C(void);
void func_0803E488(u8 *, s32);
void func_0803B410(void);
void func_0803BFC8(u8);
void func_0803B4DC(void);
void func_0803B600(u8, u8);
void func_0803B650(u8);
void func_080382F0(u8 *, u8);
s32 func_080355AC(u8);
void func_0803BF54(u8, u8);
void func_0803B724(u8, u8);
void func_0802BC6C(void *);
void func_0805EE78(s32);

void func_0803AF70(void)
{
    struct Task *task = &D_02000034[D_02000030];

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 1;
            D_02000034[10].data = 0;
            task->state = 100;
        case 100:
            if (D_02000034[10].busy == 1)
            {
                func_08003E3C(10);
                task->state = 200;
            }
            break;
        case 200:
            func_08000DB8();
            func_08000D1C(0);
            func_08001DE4(D_08663D44[24]);
            func_0802F07C();
            func_0803E488(D_08675BEC, 2);
            func_0803E488(D_08675BEC, 5);
            func_0803E488(D_08675BEC, 0x10);
            func_0803E488(D_08675BEC, 9);
            func_0803E488(D_08675BEC, 0x11);
            func_0803E488(D_08675BEC, 0xA);
            func_0803B410();
            func_0803BFC8(D_0200E8A4.row);
            func_0803B4DC();
            func_0803B600(D_0200EA14.row, D_0200EA14.col);
            func_0803B650(D_0200EA14.row);
            task->state = 300;
            break;
        case 300:
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 0;
            D_02000034[10].data = 0;
            task->state = 400;
            break;
        case 400:
            if (D_02000034[10].busy == 1)
            {
                func_08003E3C(10);
                task->state = 1000;
            }
            break;
        case 1000:
            func_0803B600(D_0200EA14.row, D_0200EA14.col);
            task->state = 1100;
        case 1100:
            func_0803E488(D_08675BEC, 0x12);
            if (D_03002358 & 0xC0)
            {
                func_0803E488(D_08675BEC, 6);
                D_0200EA14.col = D_02007574.index;
                func_0803B600(D_0200EA14.row, D_0200EA14.col);
            }
            else if (D_0300235A & 0x300)
            {
                task->row = D_0200EA14.row;
                func_080382F0(&D_0200EA14.row, D_0200EA14.count);
                if (task->row != D_0200EA14.row)
                {
                    func_0803B650(D_0200EA14.row);
                    text_windows[3].unknown0d = 0;
                    D_02007574.index = 0;
                    func_0803E488(D_08675BEC, 6);
                    D_0200EA14.col = 0;
                    func_0803B600(D_0200EA14.row, D_0200EA14.col);
                }
            }
            else if (D_0300235A & 1)
            {
                if (!(D_0200EB84 & 0x20) || !func_080355AC(D_0200EA14.cells[D_0200EA14.row][D_0200EA14.col]))
                {
                    if (D_0200EA14.used[D_0200EA14.row][D_0200EA14.col] == 0xFF)
                    {
                        task->unit = D_0200EA14.cells[D_0200EA14.row][D_0200EA14.col];
                        task->state = 2000;
                    }
                }
            }
            else if (D_0300235A & 0xA)
            {
                task->state = 9000;
            }
            break;
        case 2000:
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675BEC, 5);
            text_windows[2].unknown0d = D_0200E8A4.col;
            D_0200E8A4.cursor = 0xFF;
            func_0803BF54(D_0200E8A4.row, D_0200E8A4.col);
            task->state = 2100;
        case 2100:
            func_0803E488(D_08675BEC, 0xF);
            if (D_03002358 & 0xC0)
            {
                func_0803E488(D_08675BEC, 6);
                D_0200E8A4.col = D_02007574.index;
                func_0803BF54(D_0200E8A4.row, D_0200E8A4.col);
            }
            else if (D_0300235A & 1)
            {
                task->target = D_0200E8A4.cells[D_0200E8A4.row][D_0200E8A4.col];
                task->state = 2200;
            }
            else if (D_0300235A & 2)
            {
                task->state = 2900;
            }
            break;
        case 2200:
            D_0200E8A4.cells[D_0200E8A4.row][D_0200E8A4.col] = task->unit;
            func_0803B724(task->unit, D_0200E8A4.col);
            func_0803B4DC();
            task->state = 2900;
            break;
        case 2900:
            text_windows[3].unknown0d = D_0200EA14.col;
            func_0803E488(D_08675BEC, 0xD);
            func_0803BFC8(D_0200E8A4.row);
            func_0803E488(D_08675BEC, 0xE);
            func_0803B650(D_0200EA14.row);
            D_0200EA14.cursor = 0xFF;
            task->state = 1000;
            break;
        case 9000:
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 1;
            D_02000034[10].data = 0;
            task->state = 9100;
        case 9100:
            if (D_02000034[10].busy == 1)
            {
                func_08003E3C(10);
                task->state = 9200;
            }
            break;
        case 9200:
            func_0802BC6C(D_0200EB88);
            task->busy = 1;
            task->state = 9300;
            break;
        }
        func_0805EE78(1);
    }
}
