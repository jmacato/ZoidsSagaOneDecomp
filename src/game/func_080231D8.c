#include "types.h"

extern struct
{
    void *first;
} D_02000000;

extern struct
{
    u8 pad_0[0x90];
    u32 x;
    u32 y;
} D_03004BBC;

void func_08008B58(s32);
void func_08011F18(s32, s32, s32, s32, s32, s32);
void func_08008B70(s32, s32, s32);
void func_08011E08(void);
void func_08008024(void);
void func_08003DD8(s32);
void func_08007188(s32, u32, u32, s32);
void func_0800BEA4(void);
void func_080014A8(s32, void *);

void func_080231D8(void)
{
    func_08008B58(0x23F);
    if (D_03004BBC.x == 0x1A00000 && D_03004BBC.y == 0x1400000)
        func_08011F18(0, 0x1A0, 0x160, 0x20, 1, 0);
    func_08011F18(4, 0x1A0, 0x140, 0x20, 2, 0);
    func_08011F18(4, 0x1A0, 0xE0, 0x20, 2, 0);
    func_08008B70(4, 0xFF, 0xFF);
    func_08008B58(0x240);
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    func_08007188(0xED, D_03004BBC.x >> 21, D_03004BBC.y >> 21, 0xFFFF);
    func_080014A8(1, func_0800BEA4);
}
