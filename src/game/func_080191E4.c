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
void func_080190B0(void);
void func_0801A328(void);
void func_0801A334(void);
void func_0801A340(void);
void func_0801A34C(void);
void func_0801A358(void);

void func_080191E4(void)
{
    register u32 event asm("r4");
    u16 idx = 0;
    struct Obj *obj = &D_03004BBC;
    u16 *flag = &obj->field_E8;

    *flag = 1;
    event = 0x17B;
    asm("" : "+r"(event));
    if (!func_08001040(event))
    {
        func_08008B58(0x130);
        if (D_02007574[0] != 0 && D_02007574[1] != 1)
        {
            func_08000F88(event);
            D_02000000.first = func_080190B0;
            func_08006DFC(0xD);
        }
    }
    else
    {
        if (!func_08001040(0x17D))
        {
            if (func_080385C0(0))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A328);
                return;
            }
        }
        else if (!func_08001040(0x17E))
        {
            idx = 1;
            if (func_080385C0(1))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A334);
                return;
            }
        }
        else if (!func_08001040(0x17F))
        {
            idx = 2;
            if (func_080385C0(2))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A340);
                return;
            }
        }
        else if (!func_08001040(0x180))
        {
            idx = 3;
            if (func_080385C0(3))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A34C);
                return;
            }
        }
        else if (!func_08001040(0x181))
        {
            idx = 4;
            if (func_080385C0(4))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A358);
                return;
            }
        }
        else
        {
            func_08008B58(0x131);
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
            func_08008B58(0x13A);
            break;
        case 3:
            func_08008B58(0x13E);
            break;
        case 4:
            func_08008B58(0x142);
            break;
        }
    }
    D_03004BBC.field_E8 = 0;
}
