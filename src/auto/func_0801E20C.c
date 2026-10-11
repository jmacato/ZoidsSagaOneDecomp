#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011EAC(s32, s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0801E20C(void)
{
    func_08011E08();
    func_080076C0(0xC8, 0xF, 9, 5, 0x08669C70);
    func_08008B70(0, 0xF, 6);
    func_08011E24();
    func_08011F18(0, 0xF0, 0x70, 0x10, 1, 0);
    func_08008B70(1, 0xF, 7);
    func_08011F18(1, 0xE0, 0x70, 0x10, 1, 1);
    func_08000BD8(2, 1);
    func_08008B70(2, 0xF, 7);
    func_08011F18(2, 0x100, 0x60, 0x10, 1, 1);
    func_08000BD8(3, 1);
    func_08008B70(3, 0xF, 7);
    func_08011F18(3, 0x100, 0x70, 0x10, 1, 1);
    func_08000BD8(4, 1);
    func_08008B58(0x1D0);
    func_08011F18(1, 0xD0, 0x70, 0x10, 1, 1);
    func_08011F18(1, 0xD0, 0x60, 0x10, 1, 1);
    func_08000BD8(2, 3);
    func_08011F18(2, 0x110, 0x60, 0x10, 1, 1);
    func_08000BD8(3, 2);
    func_08011F18(3, 0x110, 0x70, 0x10, 1, 1);
    func_08000BD8(4, 2);
    func_08011F18(0, 0xD0, 0x70, 0x10, 1, 0);
    func_08000BD8(1, 3);
    func_08008B70(4, 0xF, 3);
    func_08011F18(4, 0xF0, 0x70, 0x10, 1, 1);
    func_08011F18(2, 0xF0, 0x60, 0x10, 1, 1);
    func_08000BD8(3, 1);
    func_0805EE78(0xF);
    func_08000BD8(5, 0);
    func_08003D78(4, 0x0801E479);
    func_08011F18(2, 0xF0, 0x70, 0x10, 1, 1);
    func_08011F18(3, 0x100, 0x70, 0x10, 1, 1);
    func_08000BD8(4, 1);
    func_08011F18(0, 0xE0, 0x70, 0x10, 1, 0);
    func_08000BD8(1, 1);
    func_08000BD8(2, 1);
    func_08008B58(0x1D1);
    func_08011EAC(2, 0x10, -1, 0);
    func_08011F18(1, 0xE0, 0x60, 0x10, 1, 1);
    func_08000BD8(2, 3);
    func_08000BD8(1, 3);
    func_08000BD8(4, 2);
    func_0805EE78(0xF);
    func_08008B58(0x1D2);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x0801E449;
}
