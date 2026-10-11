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

void func_0805EE78(s32);
void func_08021D1C(s32);
void func_08008024(void);
void func_08003DD8(s32);

void func_08021F48(void)
{
    func_0805EE78(0x20);
    func_08021D1C(3);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_03004BBC.field_E8 = 0;
    D_02000000.counter &= 0xFFFD;
}
