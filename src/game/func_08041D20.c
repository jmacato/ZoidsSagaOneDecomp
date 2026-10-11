#include "types.h"

extern u8 D_0200DA71;
extern u8 D_0200DA97;
extern u8 D_0200E22C;
extern u8 D_0200DA96;
extern u8 D_0200DA98;
extern u16 D_03002356;
extern u16 D_02000B56;
extern u16 *D_02009044;

void func_08041A14(void);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_0803E024(u8, u16, u8);
void func_08003DF8(s32, void *);
void func_08043F64(void);
void func_08041F64(void);
void func_08001A08(u16);

void func_08041D20(void)
{
    u16 i;

    func_08041A14();
    func_08000DB8();
    func_08000D1C(0);
    *(vu16 *)0x04000000 = 0x1740;
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
    for (i = 0; i < 16; i++)
        ((u16 *)0x050001C0)[i] = 0;
    func_0803E024(3, 0, 0x32);
    D_0200DA71 = 0;
    D_0200DA97 = 1;
    D_0200E22C = 0;
    D_0200DA96 = 0;
    D_0200DA98 = 0;
    func_08003DF8(6, func_08043F64);
}

void func_08041E1C(void)
{
    *(vu16 *)0x04000000 &= 0xDFFF;
    D_03002356 = 0x10;
    *(vu16 *)0x04000050 = 0x3FFF;
    func_08041F64();
    func_08001A08(D_02000B56);
}

void func_08041E44(u8 mode)
{
    u16 tile;
    u16 *map;
    u16 y;
    u16 x;
    u16 row;

    switch (mode)
    {
    case 0:
        tile = 0xE001;
        break;
    case 1:
        tile = 0xE000;
        break;
    }
    map = D_02009044;
    for (y = 0; y < 20; y++)
    {
        row = y * 32;
        for (x = 0; x < 30; x++)
            map[row + x] = tile;
    }
}
