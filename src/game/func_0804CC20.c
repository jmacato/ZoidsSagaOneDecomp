#include "types.h"

extern struct
{
    u8 pad_0[0x34A4];
    u16 flags;
} D_02000B5C;

void func_08000DB8(void);
void func_0803E024(s32, s32, s32);

void func_0804CC20(void)
{
    u16 i;

    func_08000DB8();
    *(vu16 *)0x04000000 = 0x1140;
    *(vu16 *)0x04000008 = 1;
    *(vu16 *)0x0400000E = 0x81;
    *(vu16 *)0x0400000A = 0x4082;
    *(vu16 *)0x0400000C = 0x83;
    *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0xFFF3) | 8;
    *(vu16 *)0x0400000A = (*(vu16 *)0x0400000A & 0xFFF3) | 4;
    *(vu16 *)0x0400000E = (*(vu16 *)0x0400000E & 0xFFF3) | 8;
    *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0xE0FF) | 0x300;
    *(vu16 *)0x0400000A = (*(vu16 *)0x0400000A & 0xE0FF) | 0x100;
    *(vu16 *)0x0400000E = (*(vu16 *)0x0400000E & 0xE0FF) | 0x300;
    for (i = 0; i <= 15; i++)
        ((u16 *)0x050001C0)[i] = 0;
    func_0803E024(3, 0, 0x32);
    D_02000B5C.flags |= 0x20;
}
