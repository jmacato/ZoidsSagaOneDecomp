#include "types.h"

void func_0805C6D4(u8 chan_num)
{
    switch (chan_num)
    {
    case 1:
        *(vu8 *)0x04000063 = 8;
        *(vu8 *)0x04000065 = 0x80;
        break;
    case 2:
        *(vu8 *)0x04000069 = 8;
        *(vu8 *)0x0400006D = 0x80;
        break;
    case 3:
        *(vu8 *)0x04000070 = 0;
        break;
    default:
        *(vu8 *)0x04000079 = 8;
        *(vu8 *)0x0400007D = 0x80;
    }
}
