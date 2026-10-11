#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008324(s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_080252E0(void)
{
    u32 var_r4;

    func_08011E08();
    func_080076C0(0xEE, 0x19, 0xF, 5, 0x0866B27C);
    func_08001A08(9);
    D_02000B54.f_0 = 0;
    func_080019B4(9);
    func_08011E24();
    func_08008B58(0x22B);
    func_08003D78(4, 0x08025405);
    func_08003D78(5, 0x08025425);
    var_r4 = 0;
    do
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
        var_r4 += 1;
    } while (var_r4 <= 0x2FU);
    func_08008B58(0x22C);
    func_08003D78(4, 0x08025445);
    func_08011F18(3, 0x1A0, 0x100, 0x10, 2, 1);
    func_08000BD8(5, 0);
    func_08008B58(0x22D);
    func_08008B58(0x22E);
    func_08011F18(4, 0x190, 0x1A0, 0x10, 2, 1);
    func_08008B70(4, 0xFF, 0xFF);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x080253E1;
loop_3:
    func_0805EE78(1);
    goto loop_3;
}
