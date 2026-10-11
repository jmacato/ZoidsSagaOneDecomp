#include "types.h"

struct Obj
{
    u8 pad_0[0xB8];
    u16 sprite1_dir;
    u8 pad_BA[0x1C];
    u16 sprite1_x;
    u16 sprite1_y;
};

extern struct Obj D_03004BBC;
extern u8 D_0200616C[];
extern u8 D_0200715C[];

extern struct
{
    u8 pad_0[2];
    u16 area;
} D_0200000C;

void func_08001524(s32, void *);
void func_0800BEC8(void);
void func_0805D270(const void *, void *, u32);
void func_08053694(u16);
void func_08054424(u16);
void func_080552F4(void);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_0803E024(u8, u16, u8);
void func_08007188(s32, s32, s32, s32);
void func_08001D04(s32);
void func_08008ABC(void);
void func_08000BD8(s32, s32);
void func_080014A8(s32, void *);

void func_08008F58(u16 kind, u16 arg)
{
    u16 x;
    u16 y;

    func_08001524(0, func_0800BEC8);
    func_0805D270(&D_03004BBC, D_0200616C, 0x7F8);
    func_0805D270((void *)0x05000200, D_0200715C, 0x100);
    x = D_03004BBC.sprite1_x;
    y = D_03004BBC.sprite1_y;
    if (kind == 0)
        func_08053694(arg);
    else if (kind == 1)
        func_08054424(arg);
    else
        func_080552F4();
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
    func_08007188(D_0200000C.area, x, y, 0xFFFF);
    func_08001D04(1);
    func_0805D270(D_0200616C, &D_03004BBC, 0x7F8);
    func_0805D270(D_0200715C, (void *)0x05000200, 0x100);
    func_08008ABC();
    func_08000BD8(1, D_03004BBC.sprite1_dir & 3);
    func_08001D04(1);
    func_080014A8(0xFFFF, func_0800BEC8);
}
