#include "types.h"

extern u16 D_03002356;
extern u8 D_0200EB30[];
extern u32 D_02000B58;

void func_080032AC(void);


void func_08003244(void)
{
    vu32 *dma;

    *(vu16 *)0x0400000C &= 0xFF70;
    *(vu16 *)0x0400000C |= 0x82;
    *(vu16 *)0x04000000 |= 0x400;
    *(vu16 *)0x04000050 = 0xC4;
    D_03002356 = 15;
    dma = (vu32 *)0x040000D4;
    dma[0] = (u32)func_080032AC;
    dma[1] = (u32)D_0200EB30;
    dma[2] = 0x84000040;
    dma[2];
    D_02000B58 = (u32)D_0200EB30 + 1;
}
