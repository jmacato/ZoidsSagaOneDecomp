#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0x1A]; u16 f_1A; } D_0200000C;
extern struct { s16 f_0; } D_02000B54;
extern struct { u8 pad_0[0xD2]; u16 f_D2; } D_03004BBC;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(u16);
M2C_UNK func_08001A08(u16);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037424(s32);
M2C_UNK func_0805EE78(s32);

void func_080159B4(void)
{
    func_0805EE78(0x20);
    if (D_03004BBC.f_D2 != 0)
    {
        do
        {
            func_0805EE78(1);
        } while (D_03004BBC.f_D2 != 0);
    }
    func_08008B58(0xD5);
    func_08011E08();
    func_080076C0(0x42, 8, 5, 8, 0x08667680);
    func_08008B70(0, 6, 5);
    func_08011E24();
    func_08008B58(0xD6);
    func_08011E08();
    func_080076C0(0x40, 0xD, 1, 0xB, 0x08667720);
    func_08008B70(0, 5, 1);
    func_08011E24();
    func_08011F18(0, 0xC0, 0x10, 0x10, 1, 0);
    func_08003D78(4, 0x08015B99);
    func_08003D78(5, 0x08015BB5);
    func_08003D78(6, 0x08015BD1);
    func_08011F18(4, 0xC0, 0, 0x10, 1, 1);
    func_08001A08(0xEU);
    D_02000B54.f_0 = 0;
    func_080019B4(0xEU);
    func_08008B58(0xD7);
    func_08001A08(D_0200000C.f_1A);
    D_02000B54.f_0 = 0;
    func_080019B4(D_0200000C.f_1A);
    func_08000BD8(6, 2);
    func_08000BD8(7, 2);
    func_08000BD8(8, 2);
    func_08000BD8(9, 1);
    func_08000BD8(0xA, 1);
    func_08000BD8(0xB, 1);
    func_08008B58(0xD8);
    func_08011F18(8, 0xB0, 0x10, 0x10, 1, 1);
    func_08011F18(8, 0xC0, 0x10, 0x10, 1, 1);
    func_08008B70(8, 0xFF, 0xFF);
    func_08011F18(9, 0xC0, 0x10, 0x10, 1, 1);
    func_08008B70(9, 0xFF, 0xFF);
    func_08011F18(0xA, 0xC0, 0x10, 0x10, 1, 1);
    func_08008B70(0xA, 0xFF, 0xFF);
    func_08037424(4);
    func_08037424(3);
    func_08037424(5);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x32, 0x11, 0x15, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
