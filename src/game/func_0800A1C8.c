#include "types.h"

struct Entry
{
    u16 id;
    u8 pad_2[14];
    u8 name[12];
};

extern const u8 D_08328E38[];
extern const u8 D_08328E30[];
extern const u8 D_08329FCC[];
extern const u8 D_08329FE0[];
extern const u8 D_0832A000[];
extern struct Entry D_0831B164[];
extern u16 D_0300235A;
extern u16 D_03002358;

void func_080019EC(s32);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_080010C0(s32, s32, s32, s32, s32, s32, s32);
void func_080014A8(s32, void *);
void func_08009A54(void);
void func_08009B30(const u8 *, s32);
void func_08009AD4(u16, s32);
void func_08000AF8(s32, s32);
void func_08001D04(s32);
u16 func_0800175C(s32, s32);
void func_0800BF0C(u16);

s32 func_0800A1C8(void)
{
    u16 sel = 0;
    u16 keys;
    vu32 zero;
    vu32 *dma;

    *(vu16 *)0x04000000 = 0x1140;
    *(vu16 *)0x04000008 = 5;
    zero = 0;
    dma = (vu32 *)0x040000D4;
    dma[0] = (u32)&zero;
    dma[1] = 0x06000000;
    dma[2] = 0x85003000;
    dma[2];
    func_080019EC(0);
    func_08000DB8();
    func_08000D1C(0);
    dma[0] = (u32)D_08328E38;
    dma[1] = 0x06004020;
    dma[2] = 0x84000138;
    dma[2];
    dma[0] = (u32)D_08328E30;
    dma[1] = 0x05000000;
    dma[2] = 0x80000004;
    dma[2];
    func_080010C0(0x27, 8, 8, 0x20, 0x14, 6, 0);
    func_080014A8(0xFFFF, func_08009A54);
    func_08009B30(D_08329FCC, 0x240);
    func_08009B30(D_08329FE0, 0x260);
    for (;;)
    {
        keys = func_0800175C(0x10, 6);
        if (D_0300235A & 8)
            break;
        if (D_0300235A & 1)
        {
            func_0800BF0C(sel);
            break;
        }
        if ((keys & 0x20) || (D_03002358 & 0x200))
        {
            if (sel)
                sel--;
        }
        if ((keys & 0x10) || (D_03002358 & 0x100))
        {
            sel++;
            if (D_0831B164[sel].id == 0xFFFF)
                sel--;
        }
        func_08009B30(D_0832A000, 0x140);
        func_08009B30(D_0831B164[sel].name, 0x149);
        func_08009AD4(sel, 0x169);
        func_08000AF8(0, 0);
        func_08001D04(1);
    }
    func_080019EC(0);
}
