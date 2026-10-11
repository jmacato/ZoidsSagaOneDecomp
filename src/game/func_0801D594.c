#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern struct
{
    u8 pad_0[0xE8];
    u16 field_E8;
} D_03004BBC;

extern u16 D_02000B54;

void func_08001A08(s32);
void func_080019B4(s32);
void func_08008B58(s32);
void func_08008024(void);
void func_08003DD8(s32);

void func_0801D594(void)
{
    func_08001A08(4);
    D_02000B54 = 0;
    func_080019B4(4);
    func_08008B58(0x1B4);
    D_03004BBC.field_E8 = 0;
    D_02000000.counter &= 0xFFFD;
    D_02000000.first = func_08008024;
    func_08003DD8(3);
}
