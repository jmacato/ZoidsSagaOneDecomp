#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0x18]; s16 f_18; } D_0200000C;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08024A98(void)
{
    func_080076C0(0x102, 5, 4, 7, 0x0866B0EC);
    func_08001A08(0x13);
    D_02000B54.f_0 = 0;
    func_080019B4(0x13);
    func_08008B70(0, 6, 4);
    func_08011E24();
    func_08003D78(4, 0x080250C9);
    func_08008B58(0x26C);
    func_08011E08();
    func_08003DD8(4);
    func_080076C0(0x102, 3, 4, 0xA, 0x0866B178);
    D_0200000C.f_18 = 2;
    func_08008B70(0, 0xFF, 0xFF);
    func_08011E24();
    func_08003D78(4, 0x08024EC5);
    func_08003D78(5, 0x08024EF5);
    func_08008B70(6, 0xF, 6);
    func_08011F18(6, 0x70, 0x60, 0x10, 1, 1);
    func_08000BD8(7, 1);
    func_0805EE78(1);
    func_08003D78(4, 0x08024F25);
    func_08003D78(5, 0x08024F55);
    func_08003D78(6, 0x08024F81);
    func_08008B70(3, 0x10, 8);
    func_08011F18(3, 0x80, 0x80, 0x10, 1, 1);
    func_08000BD8(4, 0);
    func_0805EE78(1);
    func_08003D78(4, 0x08024FB1);
    func_08003D78(5, 0x08024FD9);
    func_08008B70(9, 0xF, 7);
    func_08011F18(9, 0xB0, 0x70, 0x10, 1, 1);
    func_0805EE78(1);
    func_08008B58(0x26D);
    func_08003D78(4, 0x08025001);
    func_08003D78(5, 0x08025029);
    func_08003D78(6, 0x08025051);
    func_08003D78(7, 0x08025079);
    func_08003D78(8, 0x080250A1);
    func_08011F18(9, 0xE0, 0x70, 0x10, 2, 1);
    func_08008B70(9, 0xFF, 0xFF);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x08024C71;
loop_1:
    func_0805EE78(1);
    goto loop_1;
}
