#include "types.h"

extern struct
{
    void *first;
} D_02000000;

extern struct
{
    u8 pad_0[0xC0];
    u16 field_C0;
    u8 pad_C2[0x14];
    u16 x;
    u16 y;
    u8 pad_DA[0xE];
    u16 field_E8;
    u8 pad_EA[8];
    u16 target_x;
    u16 target_y;
    u16 delay;
    u8 pad_F8[0xC];
    u32 speed;
    u8 pad_108[8];
    u16 flags;
    u8 pad_112[0x36];
    u16 field_148;
} D_03004BBC;

extern struct
{
    u8 pad_0[0x18];
    u16 delay;
} D_0200000C;

void func_0805EE78(s32);
void func_08000F88(s32);
void func_08008B58(s32);
void func_08000BD8(s32, s32);
void func_080019EC(s32);
void func_08008024(void);
void func_08003DD8(s32);

void func_080103B4(void)
{
    func_0805EE78(0x3C);
    func_08008B58(0x44);
    D_03004BBC.field_E8 = 10;
    D_03004BBC.target_x = 0xB;
    D_03004BBC.target_y = 6;
    D_03004BBC.speed = 0x10000;
    D_03004BBC.delay = D_0200000C.delay << 3;
    D_03004BBC.field_C0 = 1;
    while (D_03004BBC.field_E8 != 1)
        func_0805EE78(1);
    D_03004BBC.field_E8 = 10;
    D_03004BBC.target_x = 0xB;
    D_03004BBC.target_y = 7;
    D_03004BBC.speed = 0x10000;
    D_03004BBC.delay = D_0200000C.delay << 3;
    D_03004BBC.field_C0 = 1;
    while (D_03004BBC.field_E8 != 1)
        func_0805EE78(1);
    D_03004BBC.field_E8 = 10;
    D_03004BBC.target_x = 0xE;
    D_03004BBC.target_y = 7;
    D_03004BBC.speed = 0x10000;
    D_03004BBC.delay = D_0200000C.delay << 3;
    D_03004BBC.field_C0 = 1;
    func_0805EE78(0x3C);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
}
