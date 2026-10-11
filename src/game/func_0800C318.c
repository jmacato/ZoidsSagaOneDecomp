#include "types.h"

extern u16 D_03002338;
extern u16 D_0300233A;
extern const u8 D_0832A03C[];
extern const u8 D_0832A034[];

void func_0800C200(void);

s32 func_0800C318(void)
{
    vu32 *dma = (vu32 *)0x040000D4;

    dma[0] = (u32)D_0832A03C;
    dma[1] = 0x0600FB60;
    dma[2] = 0x84000128;
    dma[2];
    dma[0] = (u32)D_0832A034;
    dma[1] = 0x050001C0;
    dma[2] = 0x80000003;
    dma[2];
    func_0800C200();
}

s32 func_0800C35C(void)
{
    u16 v = *(vu16 *)0x04000000;

    *(vu16 *)0x04000000 = v ^ 0x200;
    if (*(vu16 *)0x04000000 & 0x200)
        func_0800C318();
}

void func_0800C380(void)
{
    *(vu16 *)0x0400001C += D_03002338 + D_0300233A;
    D_0300233A++;
}
