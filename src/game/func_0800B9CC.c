#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[6];
    s32 x;
    s32 y;
    u8 pad_10[0x20];
    u16 dir;
    u8 pad_32[6];
    u16 field_38;
    u8 pad_3A[0x10];
    u16 state;
    u16 timer;
    u16 tile_x;
    u16 tile_y;
    u16 dest_x;
    u16 dest_y;
    u8 pad_56[2];
    u16 target;
    u8 pad_5A[0xA];
    u16 object;
    u8 pad_66[0xA];
    u16 script;
    u8 pad_72[0x16];
};

struct Object
{
    u16 id;
    u8 pad_2[0xE];
};

extern struct Sprite D_03004BBC[];
extern u8 D_0200616C[];
extern u8 D_0200715C[];

extern struct
{
    u8 pad_0[0x18];
    u16 scale;
    u8 pad_1A[4];
    u16 field_1E;
    u16 field_20;
} D_0200000C;

extern struct
{
    u8 pad_0[0xA];
    u16 battles;
    u8 pad_C[0x44];
    struct Object objects[1];
} D_02000B5C;

void func_080019EC(s32);
void func_08001524(s32, void *);
void func_0800BEC8(void);
void func_0805D270(const void *, void *, u32);
void func_080329E4(s32, u16, u16, u16);
u8 func_0800C3AC(void);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_0803E024(u8, u16, u8);
void func_08007E4C(u16, u16);
void func_08001D04(s32);
void func_08000BD8(u16, s32);
void func_08008ABC(void);
void func_080019D8(void);
void func_080014A8(s32, void *);

void func_0800B9CC(u16 sprite)
{
    u16 other;
    u16 ax;
    u16 ay;
    u16 bx;
    u16 by;
    u8 result;

    func_080019EC(0x52);
    func_08001524(0, func_0800BEC8);
    func_0805D270(D_03004BBC, D_0200616C, 0x7F8);
    func_0805D270((void *)0x05000200, D_0200715C, 0x100);
    other = D_03004BBC[sprite].target;
    ax = D_03004BBC[sprite].tile_x;
    ay = D_03004BBC[sprite].tile_y;
    bx = D_03004BBC[other].tile_x;
    by = D_03004BBC[other].tile_y;
    D_03004BBC[sprite].dest_x = ax;
    D_03004BBC[sprite].dest_y = ay;
    D_03004BBC[other].dest_x = bx;
    D_03004BBC[other].dest_y = by;
    if (D_0200000C.field_1E & ~0xFF)
        D_0200000C.field_1E = D_0200000C.field_20;
    func_080329E4(0, D_03004BBC[other].script, D_0200000C.field_1E & 0xFF, D_0200000C.field_20 & 0xFF);
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
    func_08007E4C(ax, ay);
    func_08001D04(1);
    func_0805D270(D_0200616C, D_03004BBC, 0x7F8);
    func_0805D270(D_0200715C, (void *)0x05000200, 0x100);
    D_03004BBC[sprite].x = D_0200000C.scale * ax << 19;
    D_03004BBC[sprite].y = ay * D_0200000C.scale << 19;
    D_03004BBC[other].x = D_0200000C.scale * bx << 19;
    D_03004BBC[other].y = D_0200000C.scale * by << 19;
    D_03004BBC[sprite].dest_x = D_03004BBC[sprite].tile_x;
    D_03004BBC[sprite].dest_y = D_03004BBC[sprite].tile_y;
    D_03004BBC[other].dest_x = D_03004BBC[other].tile_x;
    D_03004BBC[other].dest_y = D_03004BBC[other].tile_y;
    func_08000BD8(sprite, D_03004BBC[1].dir & 3);
    func_08000BD8(other, D_03004BBC[other].dir & 3);
    func_08008ABC();
    func_080019D8();
    func_080014A8(0, func_0800BEC8);
    if (result == 0)
    {
        D_02000B5C.battles++;
        D_03004BBC[sprite].state = 0;
        D_03004BBC[other].state = 5;
        func_08000BD8(other, D_03004BBC[other].dir & 3);
        D_03004BBC[other].flags |= 0x400;
        if (D_03004BBC[other].object != 0xFFFF)
            D_02000B5C.objects[D_03004BBC[other].object].id &= 0x7FFF;
    }
    else if (result == 1)
    {
        D_03004BBC[sprite].field_38 = result;
        D_03004BBC[sprite].state = 5;
        func_08000BD8(sprite, D_03004BBC[sprite].dir & 3);
        D_03004BBC[sprite].flags |= 0x400;
    }
    else
    {
        D_03004BBC[sprite].field_38 = 1;
        D_03004BBC[sprite].state = 0;
        D_03004BBC[other].state = 8;
        D_03004BBC[other].timer = 0xB4;
    }
}
