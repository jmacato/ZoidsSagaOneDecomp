#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[0x12];
    s32 busy;
    u8 pad_1C[0xD];
    u8 slot;
    u8 item;
    u8 pad_2B[0x5D];
};

struct Unit
{
    u8 head[8];
    u8 body[0x2C4];
};

extern struct
{
    u8 pad_0[8];
    struct Unit units[6];
    u8 pad_10D0[0x1124];
    u8 turn;
} D_0200EB84;

extern struct
{
    u8 pad_0;
    u8 row;
    u8 col;
    u8 pad_3;
    u16 field_4;
    u8 items[4][9];
} D_0200E8A4;

extern struct
{
    u8 pad_0[0x3305];
    u8 items[0x100];
} D_02000B5C;

extern struct
{
    u8 pad_0[2];
    u16 cursor;
} D_02007574;

extern u8 D_02000030;
extern struct Task D_02000034[];
extern const u8 D_08675BEC[];
extern const u8 D_08675C5C[];
extern u16 D_03002358;
extern u16 D_0300235A;

void func_0803E488(const u8 *, s32);
void func_08039318(void);
void func_080393B8(u8, u8);
void func_0803940C(u8);
void func_080019EC(s32);
void func_08031B44(void);
void func_08033844(u8 *, s32);
void func_0803851C(s32, u8);
void func_08032390(s32, u8 *, u16 *);
void func_080394EC(u8, void *, u8, u8);
void func_08031B54(void);
void func_0802FA58(void);
void func_08003DF8(s32, void *);
void func_0802C420(void);
void func_08003E3C(s32);
void func_0802C708(void);
void func_080339C4(void *);
void func_08032870(u8);
void func_08004018(void);
void func_0802FA6C(void);
void func_0803C98C(void);
void func_0805EE78(s32);

void func_08038F30(void)
{
    struct Task *task = &D_02000034[D_02000030];

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675BEC, 5);
            func_0803E488(D_08675BEC, 0x10);
            func_0803E488(D_08675BEC, 9);
            func_08039318();
            task->state = 1000;
            break;
        case 1000:
            func_080393B8(D_0200E8A4.row, D_0200E8A4.col);
            func_0803940C(D_0200E8A4.row);
            task->state = 1100;
        case 1100:
            func_0803E488(D_08675BEC, 0xF);
            if (D_03002358 & 0xC0)
            {
                func_0803E488(D_08675BEC, 6);
                D_0200E8A4.col = D_02007574.cursor;
                func_080393B8(D_0200E8A4.row, D_0200E8A4.col);
            }
            else if (D_0300235A & 1)
            {
                if (D_0200E8A4.items[D_0200E8A4.row][D_0200E8A4.col] != 0xFF)
                {
                    func_080019EC(0x3E);
                    task->item = D_0200E8A4.items[D_0200E8A4.row][D_0200E8A4.col];
                    task->slot = 1;
                    task->state = 2000;
                }
            }
            else if (D_0300235A & 2)
            {
                func_080019EC(0x3F);
                task->state = 9100;
            }
            break;
        case 2000:
            func_08031B44();
            func_08033844(&task->slot, 0);
            func_0803851C(0, task->slot);
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675C5C, 0x1B);
            func_0803E488(D_08675BEC, 5);
            task->state = 2100;
        case 2100:
            func_08032390(0, &task->slot, &D_0300235A);
            func_0803851C(0, task->slot);
            if (D_0300235A & 1)
            {
                func_080394EC(task->item, D_0200EB84.units[task->slot].body, 0, task->slot);
                D_02000B5C.items[task->item]--;
                func_08031B54();
                task->state = 2200;
            }
            else if (D_0300235A & 2)
            {
                func_080019EC(0x3F);
                func_08031B54();
                D_0200E8A4.field_4 = 0xFF;
                task->state = 1000;
            }
            break;
        case 2200:
            func_0802FA58();
            func_08003DF8(6, func_0802C420);
            task->state = 2300;
            break;
        case 2300:
            if (D_02000034[6].busy == 1)
            {
                func_08003E3C(6);
                switch (task->item)
                {
                case 0:
                case 1:
                case 2:
                case 5:
                    func_08003DF8(6, func_0802C708);
                    task->state = 3000;
                    break;
                case 3:
                case 4:
                    task->state = 2400;
                    break;
                }
            }
            break;
        case 2400:
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675BEC, 5);
            func_080339C4(&D_0200EB84.units[task->slot]);
            func_08032870(task->item);
            func_0803E488(D_08675BEC, 5);
            func_08004018();
            task->state = 2500;
        case 2500:
            if (D_02000034[9].busy == 1)
                task->state = 9000;
            break;
        case 3000:
            if (D_02000034[6].busy == 1)
            {
                func_08003E3C(6);
                task->state = 9000;
            }
            break;
        case 9000:
            func_0802FA6C();
            if (D_0200EB84.turn == 0)
                func_0803C98C();
            func_0803E488(D_08675BEC, 1);
            func_0803E488(D_08675BEC, 2);
            task->busy = 1;
            break;
        case 9100:
            func_0803E488(D_08675BEC, 1);
            func_0803E488(D_08675BEC, 2);
            task->busy = 2;
            break;
        }
        func_0805EE78(1);
    }
}
