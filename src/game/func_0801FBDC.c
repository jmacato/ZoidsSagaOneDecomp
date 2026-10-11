#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern struct
{
    u8 pad_0[0xC0];
    u16 field_C0;
    u8 pad_C2[0x10];
    u16 mode;
    u8 pad_D4[2];
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
} D_03004BBC;

extern struct
{
    u8 pad_0[0x18];
    u16 delay;
} D_0200000C;

void func_0805EE78(s32);
void func_08008B58(s32);
void func_08008024(void);
void func_0801EC58(void);
void func_08003DD8(s32);

void func_0801FBDC(void)
{
    while (D_03004BBC.mode != 0)
        func_0805EE78(1);
    func_08008B58(0x200);
    D_03004BBC.field_E8 = 10;
    D_03004BBC.target_x = D_03004BBC.x;
    D_03004BBC.target_y = D_03004BBC.y - 1;
    D_03004BBC.speed = 0x20000;
    D_03004BBC.delay = D_0200000C.delay << 2;
    D_03004BBC.field_C0 = 2;
    while (D_03004BBC.field_E8 != 1)
        func_0805EE78(1);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_02000000.first = func_0801EC58;
    D_03004BBC.field_E8 = 0;
    D_02000000.counter &= 0xFFFD;
}
