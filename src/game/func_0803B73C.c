#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 message;
    u32 data;
    u32 size;
    u32 extra;
    u8 pad_18[0];
    s32 busy;
    u8 pad_1C[0xD];
    u8 slot;
    u8 index;
    u8 result;
    u8 position;
    u8 pad_2D[0x5B];
};

struct Unit
{
    u8 data[0x2CC];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[4];
    u8 party[6];
    u8 pad_10D2[6];
};

struct Turn
{
    u8 side;
    u8 slot;
    u8 pad_2[2];
};

struct Grid
{
    u8 count;
    u8 row;
    u8 col;
    u8 pad_3;
    u16 cursor;
    u8 cells[20][9];
};

struct Command
{
    u32 flags;
    u32 first;
    u32 second;
};

extern struct
{
    u16 flags;
    u8 pad_2[6];
    struct Side sides[2];
    u8 pad_21B8[0x38];
    u8 result;
    u8 count;
    u8 pad_21F2[2];
    struct Turn turns[6];
} D_0200EB84;
extern u8 D_02000030;
extern struct Task D_02000034[];
extern s32 D_02000514;
extern struct Grid D_0200E8A4;
extern struct
{
    u16 field_0;
    u16 choice;
} D_02007574;
extern u16 D_03002358;
extern u16 D_0300235A;
extern const struct Command D_08683918[];
extern const u8 D_08675B68[];
extern const u8 D_08675BEC[];
extern const u8 D_08675C5C[];

u8 func_0803C92C(u8, u8);
u8 func_0803C9D0(u8, u8);
void func_0803E488(const u8 *, s32);
void func_0803BE88(void);
void func_0803BF54(u8, u8);
void func_0803BFC8(u8);
void func_080019EC(s32);
void func_08031B44(void);
void func_08031B54(void);
void func_08033844(u8 *, u8);
void func_0803851C(u8, u8);
void func_08032390(s32, u8 *, u16 *);
void func_08003DF8(s32, void *);
void func_08003E3C(s32);
void func_08034AA0(void);
void func_080355FC(void);
void func_0803C0A4(void);
void func_08032818(u32);
void func_08032888(u8);
void func_080328A0(u8);
void func_08004018(void);
void func_0802FA58(void);
void func_0802FA6C(void);
void func_0803C8FC(u32 *);
void func_0803C98C(void);
void func_0805EE78(s32);

void func_0803B73C(void)
{
    struct Task *task = &D_02000034[D_02000030];
    u32 message;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            task->state = 100;
            if ((message = task->message) == 1)
            {
                task->position = func_0803C92C(1, task->index);
                D_0200EB84.sides[1].party[task->position] = 0xFF;
                task->index = task->data;
                task->slot = task->size;
                D_0200EB84.result = -1;
                D_0200EB84.count = message;
                D_0200EB84.turns[0].side = message;
                D_0200EB84.turns[0].slot = task->slot;
                task->result = func_0803C9D0(task->index, 1);
                task->state = 4100;
            }
            break;
        case 100:
            func_0803E488(D_08675BEC, 0x10);
            func_0803E488(D_08675BEC, 9);
            func_0803BE88();
        case 500:
            func_0803BF54(D_0200E8A4.row, D_0200E8A4.col);
            func_0803BFC8(D_0200E8A4.row);
            task->state = 1000;
            break;
        case 1000:
            task->state = 1100;
        case 1100:
            func_0803E488(D_08675BEC, 0xF);
            if (D_03002358 & 0xC0)
            {
                func_0803E488(D_08675BEC, 6);
                D_0200E8A4.col = D_02007574.choice;
                func_0803BF54(D_0200E8A4.row, D_0200E8A4.col);
            }
            else if (D_0300235A & 1)
            {
                func_080019EC(0x3E);
                if (D_0200E8A4.cells[D_0200E8A4.row][D_0200E8A4.col] != 0xFF)
                {
                    task->index = D_0200E8A4.cells[D_0200E8A4.row][D_0200E8A4.col];
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
            if (D_08683918[task->index].flags & 0x100)
            {
                func_08031B44();
                func_08033844(&task->slot, 0);
                func_0803851C(0, task->slot);
                func_0803E488(D_08675BEC, 6);
                func_0803E488(D_08675BEC, 7);
                func_0803E488(D_08675C5C, 0x1E);
                func_0803E488(D_08675BEC, 5);
                task->state = 2100;
            }
            else
            {
                D_0200EB84.result = 0;
                task->state = 3000;
            }
            break;
        case 2100:
            func_08032390(0, &task->slot, &D_0300235A);
            func_0803851C(0, task->slot);
            if (D_0300235A & 1)
            {
                func_080019EC(0x3E);
                D_0200EB84.result = 0xFF;
                D_0200EB84.count = 1;
                D_0200EB84.turns[0].side = 0;
                D_0200EB84.turns[0].slot = task->slot;
                func_08031B54();
                task->state = 3000;
            }
            else if (D_0300235A & 2)
            {
                func_080019EC(0x3F);
                func_08031B54();
                D_0200E8A4.cursor = 0xFF;
                task->state = 500;
            }
            break;
        case 3000:
            task->position = func_0803C92C(0, task->index);
            D_0200EB84.sides[0].party[task->position] = 0xFF;
            task->result = func_0803C9D0(task->index, 0);
            if (task->result == 0)
                task->state = 4000;
            else
                task->state = 7000;
            break;
        case 4000:
            if (D_0200EB84.flags & 0x20)
            {
                func_08003DF8(6, func_08034AA0);
                D_02000034[6].message = 0xFD0A;
                task->state = 4010;
            }
            else
            {
                task->state = 4100;
            }
            break;
        case 4010:
            if (D_02000034[6].busy == 1)
            {
                func_08003E3C(6);
                task->state = 4020;
            }
            break;
        case 4020:
            func_08003DF8(6, func_080355FC);
            D_02000034[6].message = 1;
            D_02000034[6].data = 1;
            D_02000034[6].size = task->index;
            D_02000034[6].extra = task->slot;
            task->state = 4030;
            break;
        case 4030:
            if (D_02000034[6].busy == 1)
            {
                task->state = 4100;
                func_08003E3C(6);
            }
            break;
        case 4100:
            func_080019EC(0x54);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675BEC, 5);
            if (task->message == 1 && (D_0200EB84.flags & 0x20))
                func_0803E488(D_08675B68, 0x17);
            else
                func_08032818(0);
            func_0803E488(D_08675C5C, 0x21);
            func_08032888(task->index);
            func_0803E488(D_08675C5C, 0x22);
            func_0803E488(D_08675BEC, 5);
            func_08004018();
            task->state = 4110;
        case 4110:
            if (D_02000034[9].busy == 1)
                task->state = 4200;
            break;
        case 4200:
            func_0803E488(D_08675BEC, 1);
            func_0803E488(D_08675BEC, 2);
            func_080328A0(task->index);
            func_0803E488(D_08675BEC, 5);
            task->state = 5000;
        case 5000:
            func_0802FA58();
            func_08003DF8(6, func_0803C0A4);
            D_02000034[6].message = D_08683918[task->index].first;
            if (task->message == 1 && (D_0200EB84.flags & 0x20))
                func_0803C8FC(&D_02000034[6].message);
            task->state = 5100;
            break;
        case 5100:
            if (D_02000034[6].busy == 1)
                task->state = 5200;
            break;
        case 5200:
            if (D_08683918[task->index].second)
            {
                func_08003DF8(6, func_0803C0A4);
                D_02000034[6].message = D_08683918[task->index].second;
                if (task->message == 1 && (D_0200EB84.flags & 0x20))
                    func_0803C8FC(&D_02000034[6].message);
                task->state = 5300;
            }
            else
            {
                task->state = 9000;
            }
            break;
        case 5300:
            if (D_02000034[6].busy == 1)
                task->state = 9000;
            break;
        case 7000:
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            switch (task->result)
            {
            case 1:
                func_0803E488(D_08675C5C, 0x35);
                break;
            case 2:
                func_0803E488(D_08675C5C, 0x36);
                break;
            case 3:
                func_0803E488(D_08675C5C, 0x37);
                break;
            case 4:
                func_0803E488(D_08675C5C, 0x38);
                break;
            }
            func_0803E488(D_08675BEC, 5);
            func_0803E488(D_08675BEC, 0x14);
            task->state = 9100;
            break;
        case 9000:
            if (D_0200EB84.turns[0].side == 0)
                func_0803C98C();
            func_0802FA6C();
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
