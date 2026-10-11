#include "types.h"

struct Sprite
{
    u8 pad_0[0x4E];
    u16 tile_x;
    u16 tile_y;
    u8 pad_52[0x36];
};

struct Obj
{
    u8 pad_0[0xB8];
    u16 sprite1_dir;
    u8 pad_BA[0x30];
    u16 sprite1_field_62;
};

extern u8 D_03004BBC[];
extern u8 D_0200616C[];
extern u8 D_0200715C[];
extern u16 D_0200756A;
extern u16 D_02000B54;
extern u16 D_02007560[];

extern struct
{
    u8 pad_0[2];
    u16 area;
} D_0200000C;

extern struct
{
    u8 pad_0[4];
    u16 area;
    u16 x;
    u16 y;
    u8 pad_A[0x3F0E - 0xA];
    u16 music;
} D_02000B5C;

void func_08001524(s32, void *);
void func_0800BEC8(void);
void func_0805D270(const void *, void *, u32);
u8 func_0804E4A8(void);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_0803E024(u8, u16, u8);
void func_08006E08(void);
void func_08007188(s32, s32, s32, s32);
void func_08007D04(void);
void func_08008ABC(void);
void func_08001D04(s32);
void func_08000BD8(s32, s32);
void func_080014A8(s32, void *);

void func_0800B4C8(u16 sprite)
{
    u8 result;
    u16 x;
    u16 y;

    func_08001524(0, func_0800BEC8);
    func_0805D270(D_03004BBC, D_0200616C, 0x7F8);
    func_0805D270((void *)0x05000200, D_0200715C, 0x100);
    D_0200756A = ((struct Obj *)D_03004BBC)->sprite1_field_62;
    x = ((struct Sprite *)D_03004BBC)[sprite].tile_x;
    y = ((struct Sprite *)D_03004BBC)[sprite].tile_y;
    D_02000B5C.area = D_0200000C.area;
    D_02000B5C.x = x;
    D_02000B5C.y = y;
    D_02000B5C.music = D_02000B54;
    result = func_0804E4A8();
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
    if (result == 1)
    {
        func_08006E08();
        D_0200000C.area = D_02007560[0];
        x = D_02007560[1];
        y = D_02007560[2];
        func_08007188(D_0200000C.area, x, y, 0);
    }
    else
    {
        func_08007D04();
        func_0805D270(D_0200616C, D_03004BBC, 0x7F8);
        func_0805D270(D_0200715C, (void *)0x05000200, 0x100);
        func_08008ABC();
    }
    func_08001D04(1);
    func_08000BD8(sprite, ((struct Obj *)D_03004BBC)->sprite1_dir & 3);
    func_08001D04(1);
    func_080014A8(0, func_0800BEC8);
}
