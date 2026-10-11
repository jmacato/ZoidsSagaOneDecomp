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

void func_08000BD8(s32, s32);
void func_08008B58(s32);
void func_08021D1C(u8);
s32 func_08001040(s32);
void func_08008024(void);
void func_08003DD8(s32);

void func_08021DA0(u8 area)
{
    func_08000BD8(2, 1);
    func_08008B58(0x245);
    func_08021D1C(area);
    if (func_08001040(0x1BC) != 0 && func_08001040(0x1BD) != 0 && func_08001040(0x1BE) != 0 &&
        func_08001040(0x1BF) != 0 && func_08001040(0x1C0) != 0 && func_08001040(0x1C1) != 0)
        func_08008B58(0x24A);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_03004BBC.field_E8 = 0;
    D_02000000.counter &= 0xFFFD;
}
