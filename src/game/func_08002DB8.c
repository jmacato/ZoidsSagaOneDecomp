#include "types.h"

extern u16 D_0300234A;
extern u16 D_03002350;
extern u16 D_03002342;
extern u16 D_03002346;

void func_08002CDC(void);

void func_08002DB8(void)
{
    func_08002CDC();
    *(volatile u16 *)0x04000000 &= 0xDFFF;
    D_0300234A = D_03002350 = D_03002342 = D_03002346 = 0;
}
