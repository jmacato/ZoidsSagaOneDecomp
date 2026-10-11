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
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037424(s32);
M2C_UNK func_0805EE78(s32);

void func_080232A4(void)
{
    func_08011F18(0, 0x1C0, 0x2C0, 0x20, 1, 1);
    func_08000BD8(1, 3);
    func_08011E08();
    func_080076C0(0xED, 0xE, 0x16, 2, 0x0866AC00);
    func_08011E24();
    func_08011F18(1, 0x1E0, 0x2C0, 0x20, 2, 0);
    func_08008B58(0x241);
    func_08011F18(0, 0x1E0, 0x2C0, 0x20, 1, 0);
    func_08008B70(0, 0xFF, 0xFF);
    func_08000BD8(2, 3);
    func_0805EE78(0x1E);
    func_08003D78(4, 0x080234ED);
    func_08011E08();
    func_08003DD8(4);
    func_080076C0(0xEC, 0x11, 1, 1, 0x0866AC28);
    func_08008B70(0, 0x11, 5);
    func_08011E24();
    func_08011F18(0, 0x220, 0x20, 0x20, 2, 0);
    func_0805EE78(0xF);
    func_08011E08();
    func_080076C0(0xF5, 0x16, 0x25, 7, 0x0866AC3C);
    func_08008B70(0, 0x16, 0x25);
    func_08003D78(4, 0x08023511);
    func_08003D78(5, 0x08023535);
    func_08003D78(6, 0x08023559);
    func_08003D78(7, 0x0802357D);
    func_08011F18(0, 0x160, 0x220, 0x10, 1, 0);
    func_0805EE78(1);
    func_08003D78(4, 0x08023589);
    func_08003D78(5, 0x080235AD);
    func_08011F18(6, 0x160, 0x200, 0x10, 1, 0);
    func_08008B58(0x242);
    func_08011E08();
    func_080076C0(0xF5, 0x28, 0xA, 7, 0x0866AC3C);
    func_08008B70(0, 0xFF, 0xFF);
    func_08011E24();
    func_08003D78(4, 0x080235D1);
    func_08008B58(0x243);
    func_08037424(0x1D);
    func_08037424(0x1E);
    func_08011E08();
    func_08003DD8(4);
    func_080076C0(0xEC, 0x12, 2, 1, 0x0866ACC8);
    func_08011E24();
    func_08008B58(0x244);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x080234C9;
loop_1:
    func_0805EE78(1);
    goto loop_1;
}
