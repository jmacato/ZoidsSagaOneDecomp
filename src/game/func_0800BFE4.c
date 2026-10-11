#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern struct
{
    u8 pad_0;
    u8 map;
} D_0200000C;

extern struct
{
    u8 pad_0[2];
    u8 map;
    u8 pad_3;
    u16 x;
    u16 y;
    u16 dir;
    u16 field_A;
    u8 pad_C[0x3F0E - 0xC];
    u16 music;
} D_02000B5C;

extern u16 D_02007568;
extern u16 D_02000B54;
extern u16 D_030022DC;

void func_080019EC(s32);
void func_08001D04(s32);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_0800BEE4(void);
void func_08008024(void);
void func_08008028(void);
void func_0803E024(u8, u16, u8);
void func_08007188(s32, s32, s32, s32);
void func_08007024(u16);
void func_080019B4(s32);
void func_080014A8(s32, void *);
void func_0800BEC8(void);
void func_0800BE7C(void);
void func_0805EE78(s32);

void func_0800BFE4(u16 load, u16 map)
{
    D_02007568 = 0;
    func_080019EC(0);
    func_08001D04(1);
    *(vu16 *)0x04000000 = 0x1F40;
    *(vu16 *)0x0400000A = 0x109;
    *(vu16 *)0x0400000C = 0x20A;
    *(vu16 *)0x0400000E = 0x30B;
    {
        vu32 zero = 0;
        vu32 *dma = (vu32 *)0x040000D4;

        dma[0] = (vu32)&zero;
        dma[1] = 0x06000000;
        dma[2] = 0x85004000;
        dma[2];
    }
    func_08000DB8();
    func_08000D1C(1);
    D_02000B54 = 0;
    func_0800BEE4();
    D_02000000.first = func_08008024;
    D_02000000.second = func_08008028;
    D_02000000.counter = 0;
    func_0803E024(0, 0x140, 0xB4);
    if (map != 0xFFFF)
    {
        D_0200000C.map = 0xFF;
        D_02000B5C.field_A = 0;
        func_08007188(map, 0, 0, 0);
    }
    else if (load)
    {
        func_08007024(D_02000B5C.map);
        D_0200000C.map = D_02000B5C.map;
        func_08007188(D_02000B5C.x, D_02000B5C.y, D_02000B5C.dir, 0);
        func_080019B4(D_02000B5C.music);
    }
    else
    {
        D_0200000C.map = 0xFF;
        D_02000B5C.field_A = 0;
        func_08007188(4, 6, 2, 0);
    }
    D_030022DC = D_02000B5C.field_A;
    func_080014A8(0, func_0800BEC8);
    while (!D_02007568)
    {
        func_0800BE7C();
        func_0805EE78(1);
    }
}
