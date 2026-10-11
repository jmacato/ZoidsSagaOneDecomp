#include "types.h"

extern struct
{
    void *first;
} D_02000000;

void func_08003D78(s32, void *);
void func_08008B58(s32);
void func_08000F88(s32);

struct Obj
{
    u8 pad_0[0xE8];
    u16 field_E8;
};

extern struct Obj D_03004BBC;

extern u16 D_02007574[];

s32 func_08001040(s32);
u8 func_080385C0(s32);
void func_08006DFC(s32);
void func_08011E04(void);
void func_080193E8(void);
void func_0801A364(void);
void func_0801A370(void);
void func_0801A37C(void);
void func_0801A388(void);
void func_0801A394(void);

void func_08019518(void)
{
    register u32 event asm("r4");
    u16 idx = 0;
    struct Obj *obj = &D_03004BBC;
    u16 *flag = &obj->field_E8;

    *flag = 1;
    event = 0x183;
    asm("" : "+r"(event));
    if (!func_08001040(event))
    {
        func_08008B58(0x14D);
        if (D_02007574[0] != 0 && D_02007574[1] != 1)
        {
            func_08000F88(event);
            D_02000000.first = func_080193E8;
            func_08006DFC(0xE);
        }
    }
    else
    {
        if (!func_08001040(0x184))
        {
            if (func_080385C0(5))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A364);
                return;
            }
        }
        else if (!func_08001040(0x185))
        {
            idx = 1;
            if (func_080385C0(6))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A370);
                return;
            }
        }
        else if (!func_08001040(0x186))
        {
            idx = 2;
            if (func_080385C0(7))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A37C);
                return;
            }
        }
        else if (!func_08001040(0x187))
        {
            idx = 3;
            if (func_080385C0(8))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A388);
                return;
            }
        }
        else if (!func_08001040(0x188))
        {
            idx = 4;
            if (func_080385C0(9))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A394);
                return;
            }
        }
        else
        {
            func_08008B58(0x14E);
            *flag = idx;
            return;
        }
        switch (idx)
        {
        case 0:
            break;
        case 1:
            break;
        case 2:
            func_08008B58(0x157);
            break;
        case 3:
            func_08008B58(0x15B);
            break;
        case 4:
            func_08008B58(0x15F);
            break;
        }
    }
    D_03004BBC.field_E8 = 0;
}
