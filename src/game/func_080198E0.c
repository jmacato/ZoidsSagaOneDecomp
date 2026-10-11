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
void func_0801AEDC(void);
void func_0801A3A0(void);
void func_0801A3AC(void);
void func_0801A3B8(void);
void func_0801A3C4(void);
void func_0801A3D0(void);

void func_080198E0(void)
{
    u32 idx = 0;
    register struct Obj *obj asm("r0") = &D_03004BBC;
    register u16 *flag asm("r5");

    asm("" : "+r"(obj));
    flag = &obj->field_E8;
    asm("" : : "r"(flag));

    *flag = 1;
    if (!func_08001040(0x189))
    {
        if (func_08001040(0x181) && func_08001040(0x188))
        {
            func_08008B58(0x16D);
            if (D_02007574[0] != 0 && D_02007574[1] != 1)
            {
                if (!func_08001040(0x193))
                {
                    func_08000F88(0x193);
                    *flag = 1;
                    D_02000000.first = func_08011E04;
                    func_08003D78(3, func_0801AEDC);
                }
                else
                    *flag = idx;
                func_08000F88(0x189);
                func_08006DFC(0xF);
                return;
            }
        }
        else
            func_08008B58(0x16E);
    }
    else
    {
        if (!func_08001040(0x18A))
        {
            if (func_080385C0(0xA))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A3A0);
                return;
            }
        }
        else if (!func_08001040(0x18B))
        {
            idx = 1;
            if (func_080385C0(0xB))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A3AC);
                return;
            }
        }
        else if (!func_08001040(0x18C))
        {
            idx = 2;
            if (func_080385C0(0xC))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A3B8);
                return;
            }
        }
        else if (!func_08001040(0x18D))
        {
            idx = 3;
            if (func_080385C0(0xD))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A3C4);
                return;
            }
        }
        else if (!func_08001040(0x18E))
        {
            idx = 4;
            if (func_080385C0(0xE))
            {
                *flag = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_0801A3D0);
                return;
            }
        }
        else
        {
            *flag = idx;
            return;
        }
        switch (idx)
        {
        case 0:
            break;
        case 1:
            func_08008B58(0x176);
            break;
        case 2:
            func_08008B58(0x17A);
            break;
        case 3:
            func_08008B58(0x17E);
            break;
        case 4:
            func_08008B58(0x182);
            break;
        }
    }
    D_03004BBC.field_E8 = 0;
}
