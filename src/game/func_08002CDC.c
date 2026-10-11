#include "types.h"

void func_08002CDC(void)
{
    *(vu16 *)0x04000050 = *(vu16 *)0x04000052 = 0;
}

void func_08002CF4(void)
{
    *(vu16 *)0x04000000 |= 0x2000;
}

void func_08002D08(void)
{
    *(vu16 *)0x04000000 &= 0xDFFF;
    *(vu16 *)0x04000000 &= 0xF4FF;
}
