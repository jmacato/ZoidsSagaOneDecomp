#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern struct
{
    u8 pad_0[0x18];
    u16 delay;
    u16 music;
} D_0200000C;

extern u16 D_02000B54;

void func_0805EE78(s32);
void func_08000BD8(s32, s32);
void func_080019EC(s32);
void func_08008B70(s32, s32, s32);
void func_08008B58(s32);
void func_08011E08(void);
void func_08011E24(void);
void func_08008024(void);
void func_08003DD8(s32);
void func_08003D78(s32, void *);
void func_08007188(s32, s32, s32, s32);
void func_080076C0(s32, s32, s32, s32, const void *);
void func_0800BEA4(void);
void func_080014A8(s32, void *);
void func_08001A08(s32);
void func_080019B4(s32);
void func_08011F18(s32, s32, s32, s32, s32, s32);
s32 func_08001A28(s32);
void func_08000F88(s32);

struct Spr
{
    u8 pad_0[0x30];
    u16 field_30;
    u8 pad_32[0x18];
    u16 field_4A;
    u8 pad_4C[0x3C];
};

extern struct Spr D_03004BBC[];
extern u8 D_030022E0;

void func_0801BD9C(void)
{
    while (D_03004BBC[D_030022E0 + 1].field_4A)
        func_0805EE78(1);
    while (D_03004BBC[1].field_4A)
        func_0805EE78(1);
    switch (D_03004BBC[D_030022E0 + 1].field_30)
    {
    case 0:
        func_08000BD8(1, 1);
        break;
    case 1:
        func_08000BD8(1, 0);
        break;
    case 2:
        func_08000BD8(1, 3);
        break;
    case 3:
        func_08000BD8(1, 2);
        break;
    }
    func_08008B58(0x1CF);
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    func_08000BD8(1, 0);
    func_08007188(0xC6, 0xE, 4, 0xFFFF);
    func_080014A8(1, func_0800BEA4);
}
