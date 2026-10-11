#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
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
M2C_UNK func_08037450(s32);
M2C_UNK func_0805EE78(s32);

void func_08018650(void)
{
    func_08011E08();
    func_080076C0(0x84, 0x55, 0x2A, 0xC, 0x0866815C);
    func_08001A08(9);
    D_02000B54.f_0 = 0;
    func_080019B4(9);
    func_08008B70(0, 0x55, 0x23);
    func_08011E24();
    func_08003D78(4, 0x080188C1);
    func_08003D78(5, 0x080188E1);
    func_08003D78(6, 0x08018901);
    func_08011F18(1, 0x540, 0x280, 0x10, 1, 1);
    func_0805EE78(8);
    func_08003D78(4, 0x08018921);
    func_08003D78(5, 0x08018941);
    func_08003D78(6, 0x08018961);
    func_08011F18(7, 0x570, 0x270, 0x10, 1, 1);
    func_0805EE78(8);
    func_08008B58(0x119);
    func_08003D78(4, 0x08018985);
    func_08011F18(0xB, 0x570, 0x2A0, 0x10, 1, 1);
    func_08000BD8(0xC, 0);
    func_08003D78(4, 0x080189B1);
    func_0805EE78(0x1E);
    func_08011F18(9, 0x560, 0x2C0, 0x10, 2, 1);
    func_08011F18(9, 0x5C0, 0x2D0, 0x10, 2, 1);
    func_08008B70(9, 0xFF, 0xFF);
    func_0805EE78(0xF);
    func_08003D78(4, 0x080189F5);
    func_08011F18(0xA, 0x5C0, 0x2D0, 0x10, 2, 1);
    func_08008B70(0xA, 0xFF, 0xFF);
    func_08008B58(0x11A);
    func_08011F18(7, 0x580, 0x270, 0x10, 1, 1);
    func_08011F18(7, 0x5C0, 0x2D0, 0x10, 2, 1);
    func_08008B70(7, 0xFF, 0xFF);
    func_08008B58(0x11B);
    func_08003D78(4, 0x08018A21);
    func_08003D78(5, 0x08018A65);
    func_08011F18(6, 0x560, 0x2C0, 0x10, 2, 1);
    func_08011F18(6, 0x5C0, 0x2D0, 0x10, 2, 1);
    func_08008B70(6, 0xFF, 0xFF);
    func_08037450(9);
    func_08037450(0xA);
    func_08037450(0xB);
    func_08037450(0xC);
    func_08008B58(0x11C);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x0801889D;
}
