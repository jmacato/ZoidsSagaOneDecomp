#include "types.h"

extern u16 D_0300235A;
extern const u8 D_0832A014[];

void func_08000D1C(s32);
void func_08000DB8(void);
void func_0800A35C(s32, s32, s32, s32, s32, s32, s32);
void func_080014A8(s32, void *);
void func_08001524(s32, void *);
void func_08009A54(void);
void func_0800100C(s32);
u16 func_08001080(void);

s32 func_0800A3F8(u16 x, u16 y, u16 color)
{
    u16 mask;
    u16 *pixel;
    u16 old;

    if ((x & 3) == 0)
        mask = 0xFFF0;
    else if ((x & 3) == 1)
    {
        color <<= 4;
        mask = 0xFF0F;
    }
    else if ((x & 3) == 2)
    {
        color <<= 8;
        mask = 0xF0FF;
    }
    else
    {
        color <<= 12;
        mask = 0x0FFF;
    }
    pixel = (u16 *)(((u16)((y >> 3) * 30 + (x >> 3)) << 5) + ((y & 7) << 2) + ((u16)(x & 4) >> 1) + 0x06004000);
    old = *pixel;
    color = (color + (old & ~mask)) & ~mask;
    *pixel = color + (old & mask);
}

s32 func_0800A48C(void)
{
    vu32 zero;

    *(vu16 *)0x04000000 = 0x100;
    *(vu16 *)0x04000008 = 4;
    {
        vu32 *dma;

        zero = 0;
        dma = (vu32 *)0x040000D4;
        dma[0] = (vu32)&zero;
        dma[1] = 0x06000000;
        dma[2] = 0x85003000;
        dma[2];
    }
    func_08000D1C(0);
    func_08000DB8();
    {
        vu32 *dma = (vu32 *)0x040000D4;

        dma[0] = (vu32)D_0832A014;
        dma[1] = 0x05000000;
        dma[2] = 0x80000100;
        dma[2];
    }
    func_0800A35C(0, 0x1E, 0x14, 0x20, 0, 0, 0);
    func_080014A8(0xFFFF, func_08009A54);
    func_0800100C(0);
    while (!(D_0300235A & 8))
    {
        u16 a = func_08001080();
        u16 b = func_08001080();

        func_0800A3F8(a, b, 1);
    }
    func_08001524(0, func_08009A54);
}
