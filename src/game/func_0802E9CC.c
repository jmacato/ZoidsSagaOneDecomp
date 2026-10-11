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
    u32 result;
    u8 pad_20[8];
    s16 index;
    u8 pad_2A[0x5E];
};

struct Unit
{
    u8 data[0x2CC];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern struct
{
    u16 flags;
    u8 pad_2[0x21E6];
    u8 field_21E8;
} D_0200EB84;
extern struct Unit D_0200FC64[];
extern struct
{
    u16 flags;
} D_02005C70;
extern struct
{
    u16 field_0;
    u16 choice;
} D_02007574;
extern struct
{
    u8 pad_0[0xC];
    u32 scroll;
    u8 pad_10[4];
    u32 field_14;
} D_03004B9C;
extern const u8 *D_08663D44[];
extern const u8 D_08675BEC[];
extern const u8 D_08675C5C[];

void func_080019B4(s32);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_08001DE4(const u8 *);
void func_08031074(void);
void func_080317D0(void);
void func_08003DF8(s32, void *);
void func_08004034(void);
void func_08003E3C(s32);
void func_0803E488(const u8 *, s32);
void func_08004018(void);
s32 func_08032A88(s32, s32);
void func_080339C4(struct Unit *);
s32 func_08033E00(void);
void func_0802FA58(void);
void func_08037AF0(void);
void func_0802F07C(void);
void func_0802FA6C(void);
void func_0803AF70(void);
void func_08052198(void);
s32 func_08033DC8(void);
void func_0802F04C(void);
void func_08032684(void);
void func_08003D78(s32, void *);
void func_0802F010(void);
void func_0805EE78(s32);

void func_0802E9CC(void)
{
    struct Task *task = &D_02000034[D_02000030];

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            func_080019B4(0x16);
            task->state = 50;
        case 50:
            func_08000DB8();
            func_08000D1C(0);
            func_08001DE4(D_08663D44[24]);
            func_08031074();
            D_03004B9C.scroll = 0x100000;
            D_03004B9C.field_14 = 0;
            func_080317D0();
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
            }
            break;
        case 1000:
            func_0803E488(D_08675BEC, 2);
            func_0803E488(D_08675C5C, 1);
            func_0803E488(D_08675BEC, 5);
            func_08004018();
            task->state = 1100;
            break;
        case 1100:
            if (D_02000034[9].busy == 1)
            {
                task->state = 1200;
                task->index = 0;
            }
            break;
        case 1200:
            if (func_08032A88(1, task->index))
            {
                func_0803E488(D_08675BEC, 6);
                func_0803E488(D_08675BEC, 7);
                func_080339C4(&D_0200FC64[task->index]);
                func_0803E488(D_08675C5C, 0xF);
                func_0803E488(D_08675BEC, 5);
                func_08004018();
                task->state = 1300;
            }
            else
            {
                task->state = 1400;
            }
            break;
        case 1300:
            if (D_02000034[9].busy == 1)
                task->state = 1400;
            break;
        case 1400:
            if (++task->index > 5)
                task->state = 1500;
            else
                task->state = 1200;
            break;
        case 1500:
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675C5C, 0x10);
            func_0803E488(D_08675BEC, 5);
            func_08004018();
            task->state = 1600;
            break;
        case 1600:
            if (D_02000034[9].busy == 1)
                task->state = 2000;
            break;
        case 2000:
            if ((D_0200EB84.flags & 0x20) || (D_02005C70.flags & 1))
                func_0803E488(D_08675BEC, 0x18);
            else
                func_0803E488(D_08675BEC, 0);
            task->result = D_02007574.choice;
            switch (D_02007574.choice)
            {
            case 0:
                if (func_08033E00())
                    task->state = 9000;
                else
                    task->state = 2500;
                break;
            case 1:
                if (!(D_02005C70.flags & 8))
                {
                    func_0802FA58();
                    task->state = 3000;
                }
                break;
            case 2:
                func_0802FA58();
                task->state = 4000;
                break;
            case 3:
                func_0802FA58();
                task->state = 5000;
                break;
            case 4:
                if (!(D_0200EB84.flags & 0x20))
                    task->state = 8000;
                break;
            default:
                task->state = 9000;
                break;
            }
            break;
        case 2500:
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675C5C, 0x3E);
            func_0803E488(D_08675BEC, 5);
            func_0803E488(D_08675BEC, 0x14);
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675C5C, 0x10);
            func_0803E488(D_08675BEC, 5);
            task->state = 2000;
            break;
        case 3000:
            func_08003DF8(7, func_08037AF0);
            task->state = 3100;
            break;
        case 3100:
            if (D_02000034[7].busy == 1)
            {
                func_08003E3C(7);
                task->state = 3200;
            }
            break;
        case 3200:
            func_08000DB8();
            func_08000D1C(0);
            func_08001DE4(D_08663D44[24]);
            func_08031074();
            func_080317D0();
            D_03004B9C.scroll = 0x100000;
            D_03004B9C.field_14 = 0;
            func_0802F07C();
            func_0803E488(D_08675BEC, 2);
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675C5C, 0x10);
            func_0803E488(D_08675BEC, 5);
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 0;
            D_02000034[10].data = 0;
            task->state = 3300;
            break;
        case 3300:
            if (D_02000034[10].busy == 1)
            {
                func_08003E3C(10);
                func_0802FA6C();
                task->state = 2000;
            }
            break;
        case 4000:
            func_08003DF8(7, func_0803AF70);
            task->state = 4100;
            break;
        case 4100:
            if (D_02000034[7].busy == 1)
            {
                func_08003E3C(7);
                task->state = 3200;
            }
            break;
        case 5000:
            func_08003DF8(10, func_08004034);
            D_02000034[10].message = 1;
            D_02000034[10].data = 0;
            task->state = 5010;
        case 5010:
            if (D_02000034[10].busy == 1)
            {
                func_08003E3C(10);
                task->state = 5100;
            }
            break;
        case 5100:
            func_08052198();
            task->state = 3200;
            break;
        case 8000:
            if (func_08033DC8())
                func_0802F04C();
            func_08032684();
            if (D_0200EB84.field_21E8)
            {
                task->busy = 2;
                task->state = 9010;
            }
            else
            {
                func_0803E488(D_08675BEC, 6);
                func_0803E488(D_08675BEC, 7);
                func_0803E488(D_08675C5C, 0xE);
                func_0803E488(D_08675BEC, 5);
                func_0803E488(D_08675BEC, 0x14);
                task->state = 9000;
            }
            break;
        case 9000:
            func_08003D78(7, func_0802F010);
            while (D_03004B9C.scroll > 0xFFFF)
            {
                D_03004B9C.scroll -= 0x20000;
                func_0805EE78(1);
            }
            D_03004B9C.scroll = 0;
            func_0805EE78(15);
            task->busy = 1;
            task->state = 9010;
            break;
        case 9010:
            break;
        }
        func_0805EE78(1);
    }
}
