#include "types.h"

extern u32 D_0200E284;
extern u32 D_0200E288;
extern u8 D_0200DA71;

void func_08000DB8(void);
void func_08043F64(void);
void func_08003DF8(s32, void *);

void func_08042FB4(void)
{
    func_08000DB8();
    *(vu16 *)0x04000000 = 0x1740;
    *(vu16 *)0x04000008 = 1;
    *(vu16 *)0x0400000E = 0x81;
    *(vu16 *)0x0400000A = 0x4082;
    *(vu16 *)0x0400000C = 0x83;
    *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0xFFF3) | 8;
    *(vu16 *)0x0400000A = (*(vu16 *)0x0400000A & 0xFFF3) | 4;
    *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0xE0FF) | 0x300;
    *(vu16 *)0x0400000A = (*(vu16 *)0x0400000A & 0xE0FF) | 0x100;
    D_0200E284 = 0;
    D_0200E288 = 0;
    D_0200DA71 = 0;
    func_08003DF8(6, func_08043F64);
}
