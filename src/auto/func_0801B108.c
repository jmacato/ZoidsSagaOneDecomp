#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0x1A]; u16 f_1A; } D_0200000C;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_080019B4(u16);
M2C_UNK func_08001A08(u16);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037450(s32);
M2C_UNK func_08037920(s32);

void func_0801B108(void)
{
    func_080076C0(0x98, 8, 6, 6, 0x0866919C);
    func_08008B70(0, 0xFF, 0xFF);
    func_08001A08(1U);
    D_02000B54.f_0 = 0;
    func_080019B4(1U);
    func_08011E24();
    func_08008B58(0x18B);
    func_08001A08(D_0200000C.f_1A);
    D_02000B54.f_0 = 0;
    func_080019B4(D_0200000C.f_1A);
    func_08011E08();
    func_080076C0(0x86, 0xF, 0x14, 9, 0x08669214);
    func_08011E24();
    func_08008B58(0x18C);
    func_08037920(0x14);
    func_08011E08();
    func_080076C0(0x85, 0x21, 7, 2, 0x086692C8);
    func_08003D78(4, 0x0801B255);
    func_08011F18(0, 0x520, 0xE0, 0x20, 1, 1);
    func_08037450(0xD);
    func_08037450(0xE);
    func_08037450(0xF);
    func_08037450(0x10);
    func_08037450(0x11);
    func_08037450(0x12);
    func_08037450(0x13);
    func_08037450(0x14);
    func_08037450(0x15);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x0801B225;
}
