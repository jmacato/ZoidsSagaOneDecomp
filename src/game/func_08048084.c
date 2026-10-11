#include "types.h"

extern u16 D_03002356;

void func_08048084(u16 first, u16 second, u16 alpha, u8 reset)
{
    if (reset & 1)
    {
        D_03002356 = 0;
        *(vu16 *)0x04000052 = 0;
    }
    first &= 0xC0;
    second &= 0x3F;
    alpha = (alpha << 8) & 0x3F00;
    *(vu16 *)0x04000050 = first | second | alpha;
}
