#include "types.h"

extern u16 D_0300234A;
extern u16 D_03002350;
extern u16 D_03002342;
extern u16 D_03002346;
extern u16 D_03002356;
extern void *D_02000B58;

void func_08001F80(void);

void func_0800292C(void)
{
    *(vu16 *)0x04000000 &= 0xDFFF;
    D_0300234A = D_03002350 = D_03002342 = D_03002346 = 0;
    *(vu16 *)0x04000050 = 0;
    D_03002356 = *(vu16 *)0x04000054 = 0;
    *(vu16 *)0x04000052 = 0;
    D_02000B58 = func_08001F80;
    *(vu16 *)0x04000000 &= 0xE0FF;
}
