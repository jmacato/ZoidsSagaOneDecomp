#include "types.h"

extern struct
{
    void *first;
} D_02000000;

extern struct
{
    u8 pad_0[0x1A];
    u16 sound;
} D_0200000C;

extern struct
{
    u8 pad_0[0x110];
    u16 flags;
} D_03004BBC;

extern u16 D_02000B54;
extern u8 D_08669C48[];

void func_08008B58(s32);
void func_08001A08(u16);
void func_080019B4(u16);
void func_08011F18(s32, s32, s32, s32, s32, s32);
void func_08008B70(s32, s32, s32);
void func_08011E08(void);
void func_080076C0(s32, s32, s32, s32, u8 *);
void func_08011E24(void);
void func_08008024(void);
void func_08003DD8(s32);
void func_08007188(s32, s32, s32, s32);
void func_0800BEA4(void);
void func_080014A8(s32, void *);

void func_0801DE58(void)
{
    func_08008B58(0x1C6);
    func_08001A08(D_0200000C.sound);
    D_02000B54 = 0;
    func_080019B4(D_0200000C.sound);
    func_08011F18(6, 0x180, 0x140, 0x20, 1, 1);
    func_08008B70(6, 0xFF, 0xFF);
    func_08011E08();
    func_080076C0(0xB0, 0x12, 0xA, 2, D_08669C48);
    func_08008B70(0, 0x13, 0xA);
    D_03004BBC.flags |= 0x400;
    func_08011E24();
    func_08008B58(0x1C7);
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    func_08007188(0xB0, 0x13, 0xA, 0xFFFF);
    func_080014A8(1, func_0800BEA4);
}
