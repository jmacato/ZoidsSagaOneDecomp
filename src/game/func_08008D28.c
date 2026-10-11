#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern u8 D_03004BBC[];
extern u8 D_0200616C[];
extern u8 D_0200715C[];

void func_080019EC(s32);
void func_08001524(s32, void *);
void func_0800C708(void);
void func_0805D270(const void *, void *, u32);
void func_080329E4(s32, u16, s32, s32);
u8 func_0800C3AC(void);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_0803E024(u8, u16, u8);
void func_08007D04(void);
void func_08001D04(s32);
void func_08008ABC(void);
void func_080019D8(void);

u8 func_08008D28(u16 battle)
{
    u8 result;

    D_02000000.counter |= 8;
    func_080019EC(0x52);
    func_08001524(0, func_0800C708);
    func_0805D270(D_03004BBC, D_0200616C, 0x7F8);
    func_0805D270((void *)0x05000200, D_0200715C, 0x100);
    func_080329E4(1, battle, 0, 0);
    result = func_0800C3AC();
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
    func_0803E024(0, 0x140, 0xB4);
    func_08007D04();
    func_08001D04(1);
    func_0805D270(D_0200616C, D_03004BBC, 0x7F8);
    func_0805D270(D_0200715C, (void *)0x05000200, 0x100);
    func_08008ABC();
    func_080019D8();
    D_02000000.counter &= 0xFFF7;
    return result;
}
