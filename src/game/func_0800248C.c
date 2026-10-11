#include "types.h"

struct Task
{
    u8 pad_0[0x18];
    s32 busy;
    u8 pad_1C[0x6C];
};

extern struct
{
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1C;
} D_03004B9C;

extern u16 D_0300239C[];
extern const u32 D_08061638[];
extern const u8 D_08062FF4[];
extern const u8 D_0806327C[];
extern const u8 D_0806329C[];
extern const u8 D_080632BC[];
extern const u8 D_080632DC[];
extern const u8 D_080632FC[];
extern const u8 D_080677A8[];
extern struct Task D_02000034[];
extern u8 D_0200E8A8;
extern u16 D_0300235A;

void func_0805D288(const void *, void *);
void func_0805D270(const void *, void *, u32);
void func_08002450(s32);
void func_08002404(s32, s32);
void func_0805EE78(s32);
void func_08003D78(s32, void *);
void func_08002E48(void);
void func_08002A30(void);
void func_080027AC(void);
void func_0800338C(void);
void func_0800331C(void);

void func_0800248C(void)
{
    u32 base;
    register u32 tiles asm("r8");
    u32 tile;
    u32 y;
    u32 x;
    vu16 fill;
    vu32 *dma;
    register const u32 *data asm("r9");

    base = (*(vu16 *)0x0400000A & 0xC) << 12;
    {
        u32 address = base + 0x06000000;
        asm("" : "+l"(address));
        tiles = address;
        asm("" : : "r"(tiles));
    }
    *(vu16 *)0x0400000A;
    *(vu16 *)0x0400000C;
    *(vu16 *)0x0400000E;
    fill = 0x100;
    dma = (vu32 *)0x040000D4;
    dma[0] = (u32)&fill;
    dma[1] = 0x06000000;
    dma[2] = 0x81001000;
    dma[2];
    fill = 0x100;
    dma[0] = (u32)&fill;
    dma[1] = (u32)D_0300239C;
    dma[2] = 0x81001000;
    dma[2];
    fill = 0;
    dma[0] = (u32)&fill;
    {
        register u32 screen asm("r2") = 0x06002000;
        asm("" : : "r"(screen));
        dma[1] = base + screen;
        dma[2] = 0x81000020;
        dma[2];
        data = D_08061638;
        asm("" : : "r"(data));
        screen += 0x40;
        asm("" : : "r"(screen));
        func_0805D288(data, (void *)(base + screen));
    }
    dma[0] = base + 0x06003620;
    dma[1] = 0x06010000;
    dma[2] = 0x80000700;
    dma[2];
    func_0805D288(D_08062FF4, (void *)0x06010E00);
    dma[0] = 0x06002000;
    dma[1] = (u32)&D_0300239C[0x1000];
    dma[2] = 0x80000400;
    dma[2];
    dma[0] = (u32)D_0806327C;
    dma[1] = 0x05000160;
    dma[2] = 0x80000010;
    dma[2];
    dma[0] = (u32)D_0806329C;
    dma[1] = 0x05000180;
    dma[2] = 0x80000010;
    dma[2];
    dma[0] = (u32)D_080632BC;
    dma[1] = 0x050001A0;
    dma[2] = 0x80000010;
    dma[2];
    dma[0] = (u32)D_080632DC;
    dma[1] = 0x050001C0;
    dma[2] = 0x80000010;
    dma[2];
    dma[0] = (u32)D_080632BC;
    dma[1] = 0x05000200;
    dma[2] = 0x80000010;
    dma[2];
    dma[0] = (u32)D_080632DC;
    dma[1] = 0x05000220;
    dma[2] = 0x80000010;
    dma[2];
    {
        register const u8 *compressed asm("r0") = D_080632FC;
        u32 offset;
        register const u32 *header asm("r2");
        asm("" : : "r"(compressed));
        header = data;
        asm("" : : "r"(header), "r"(compressed));
        offset = (*header >> 8) + 0x2040;
        asm("" : "+l"(offset) : "r"(compressed), "r"(tiles));
        tiles += offset;
        asm("" : : "r"(tiles), "r"(compressed));
        func_0805D288(compressed, (void *)tiles);
    }
    dma[0] = (u32)D_080677A8;
    dma[1] = 0x05000000;
    dma[2] = 0x800000B0;
    dma[2];
    tile = 0;
    for (y = 0; y <= 5; y++)
        for (x = 0; x <= 9; x++)
            D_0300239C[0x400 + y * 32 + x] = tile++ + 0xC139;
    func_08002450(0x805);
    D_0300239C[0x804] = 0xB502;
    D_0300239C[0x8A4] = 0xB507;
    func_08002404(4, 7);
    D_03004B9C.field_0 = D_03004B9C.field_8 = 0xFFD80000;
    D_03004B9C.field_4 = D_03004B9C.field_C = 0xFFC80000;
    D_03004B9C.field_10 = 0xFFB00000;
    D_03004B9C.field_14 = 0xFFC80000;
    D_03004B9C.field_18 = 0xFFB40000;
    D_03004B9C.field_1C = 0xFFC00000;
    while (D_02000034[10].busy != 1)
        func_0805EE78(1);
    func_0805EE78(30);
    func_08003D78(4, func_08002E48);
    func_08003D78(5, func_08002A30);
    func_08003D78(7, func_080027AC);
    while (!(D_0200E8A8 & 8))
        func_0805EE78(1);
    func_08003D78(4, func_0800338C);
    func_08003D78(5, func_0800331C);
    for (;;)
    {
        func_0805EE78(1);
        if (D_0200E8A8 & 4)
        {
            for (;;)
                func_0805EE78(1);
        }
        if (D_0300235A & 8)
            break;
    }
    D_0200E8A8 |= 2;
    fill = 0x100;
    func_0805D270((void *)&fill, D_0300239C, 0x01000400);
    func_0805EE78(1);
    *(vu16 *)0x04000008 = 0;
    D_03004B9C.field_0 = 0;
    D_03004B9C.field_4 = 0;
    *(vu16 *)0x04000000 |= 0x100;
    D_0200E8A8 |= 1;
}
