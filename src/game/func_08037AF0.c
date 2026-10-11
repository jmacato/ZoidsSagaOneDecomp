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
    u8 position;
    u8 pilot;
    u8 pad_2B[0x5D];
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

struct Zoid
{
    u16 flags;
    u8 pad_2[0x33];
    u8 size;
    u8 pad_36[2];
};

struct Pilot
{
    u16 flags;
    u8 zoid;
    u8 pad_3;
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern struct Grid D_0200E8A4;
extern u8 D_0200EB88[];
extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[1];
    u8 pad_D64[0x34A4 - 0xD64];
    struct Pilot pilots[1];
} D_02000B5C;
extern struct
{
    u16 field_0;
    u16 choice;
} D_02007574;
extern u16 D_03002358;
extern u16 D_0300235A;
extern const u8 *D_08663D44[];
extern u8 D_08675BEC[];
extern u8 D_08675C5C[];

void func_08003DF8(s32, void *);
void func_08004034(void);
void func_08003E3C(s32);
void func_0802B5A0(void *);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_08001DE4(const u8 *);
void func_080316FC(void);
void func_0803178C(void);
void func_0802F07C(void);
void func_0803E488(u8 *, s32);
void func_08038054(void);
void func_08038280(u8, u8);
void func_08038100(u8);
void func_080382F0(u8 *, u8);
u8 func_08037810(u8);
void func_08031B44(void);
void func_08031B54(void);
void func_0803847C(u8);
void func_0803832C(u8 *, u8);
void func_080019EC(s32);
void region_08037118(u8, u8, struct Zoid *);
void func_08033844(u8 *, u8);
void func_080371C4(u8);
void func_0805EE78(s32);

void func_08037AF0(void)
{
    struct Task *task = &D_02000034[D_02000030];
    struct Zoid *zoid;

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
                func_0802B5A0(D_0200EB88);
            }
            break;
        case 200:
            func_08000DB8();
            func_08000D1C(0);
            func_08001DE4(D_08663D44[24]);
            func_080316FC();
            func_0803178C();
            func_0802F07C();
            func_0803E488(D_08675BEC, 2);
            func_0803E488(D_08675BEC, 8);
            func_0803E488(D_08675BEC, 5);
            func_0803E488(D_08675BEC, 9);
            func_0803E488(D_08675BEC, 0xA);
            func_08038054();
            func_08038280(D_0200E8A4.row, D_0200E8A4.col);
            func_08038100(D_0200E8A4.row);
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
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675C5C, 0x17);
            func_0803E488(D_08675BEC, 5);
            task->state = 1100;
        case 1100:
            func_0803E488(D_08675BEC, 0xF);
            if (D_03002358 & 0xC0)
            {
                func_0803E488(D_08675BEC, 0xE);
                D_0200E8A4.col = D_02007574.choice;
                func_08038280(D_0200E8A4.row, D_0200E8A4.col);
            }
            else if (D_0300235A & 0x300)
            {
                task->row = D_0200E8A4.row;
                func_080382F0(&D_0200E8A4.row, D_0200E8A4.count);
                if (task->row != D_0200E8A4.row)
                {
                    func_08038100(D_0200E8A4.row);
                    text_windows[2].unknown0d = 0;
                    func_0803E488(D_08675BEC, 0xE);
                    D_0200E8A4.col = 0;
                    func_08038280(D_0200E8A4.row, 0);
                }
            }
            else if (D_0300235A & 1)
            {
                task->pilot = D_0200E8A4.cells[D_0200E8A4.row][D_0200E8A4.col];
                if (D_02000B5C.pilots[task->pilot].zoid != 0xFF)
                {
                    if (D_02000B5C.pilots[task->pilot].flags & 0x10)
                    {
                        task->position = func_08037810(task->pilot);
                        if (task->position == 0xFF)
                            task->position = 1;
                        task->state = 3050;
                    }
                    else if (!(D_02000B5C.zoids[D_02000B5C.pilots[task->pilot].zoid].flags & 0x800))
                    {
                        zoid = &D_02000B5C.zoids[D_02000B5C.pilots[task->pilot].zoid];
                        task->position = 1;
                        task->state = 2000;
                    }
                }
            }
            else if (D_0300235A & 0x20)
            {
                task->position = 1;
                task->state = 3000;
            }
            else if (D_0300235A & 0xA)
            {
                task->state = 9000;
            }
            break;
        case 2000:
            func_08031B44();
            func_0803847C(task->position);
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675C5C, 0x18);
            func_0803E488(D_08675BEC, 5);
            task->state = 2100;
        case 2100:
            func_0803832C(&task->position, zoid->size);
            func_0803847C(task->position);
            if (D_0300235A & 1)
            {
                func_080019EC(0x51);
                region_08037118(task->position, task->pilot, zoid);
                func_0802B5A0(D_0200EB88);
                func_0803178C();
                task->state = 2900;
            }
            else if (D_0300235A & 2)
            {
                func_080019EC(0x3F);
                task->state = 2900;
            }
            break;
        case 2900:
            func_08031B54();
            func_0803E488(D_08675BEC, 0xD);
            func_08038100(D_0200E8A4.row);
            task->state = 1000;
            break;
        case 3000:
            func_08033844(&task->position, 0);
        case 3050:
            func_08031B44();
            func_0803847C(task->position);
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675C5C, 0x19);
            func_0803E488(D_08675BEC, 5);
            task->state = 3100;
        case 3100:
            func_0803832C(&task->position, 1);
            func_0803847C(task->position);
            if (D_0300235A & 1)
            {
                func_080019EC(0x3E);
                func_080371C4(task->position);
                func_0802B5A0(D_0200EB88);
                func_0803178C();
                task->state = 2900;
            }
            else if (D_0300235A & 2)
            {
                func_080019EC(0x3F);
                task->state = 2900;
            }
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
            task->busy = 1;
            task->state = 9300;
            break;
        }
        func_0805EE78(1);
    }
}
