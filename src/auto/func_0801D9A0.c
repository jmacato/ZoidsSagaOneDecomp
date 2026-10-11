#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080019B4(s32);
M2C_UNK func_080019EC(s32);
M2C_UNK func_08001A08(s32);
s32 func_08001A28(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008324(s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0801D9A0(void)
{
    u32 var_r4;

    func_08011E08();
    func_080076C0(0xB0, 0x16, 7, 8, 0x08669BA8);
    func_08001A08(4);
    D_02000B54.f_0 = 0;
    func_080019B4(4);
    func_08011E24();
    func_0805EE78(6);
    func_080019EC(0x5B);
    do
    {
        func_0805EE78(1);
    } while (func_08001A28(0x5B) == 0);
    func_0805EE78(0xC);
    func_080019EC(0x5B);
    func_0805EE78(0x1E);
    func_080019EC(0x5B);
    do
    {
        func_0805EE78(1);
    } while (func_08001A28(0x5B) == 0);
    func_0805EE78(6);
    func_08008B58(0x1BC);
    func_080019EC(0x81);
    do
    {
        func_0805EE78(1);
    } while (func_08001A28(0x81) == 0);
    func_0805EE78(6);
    func_080019EC(0x5B);
    do
    {
        func_0805EE78(1);
    } while (func_08001A28(0x5B) == 0);
    func_0805EE78(6);
    func_080019EC(0x5B);
    do
    {
        func_0805EE78(1);
    } while (func_08001A28(0x5B) == 0);
    func_08011F18(0, 0x2E0, 0xE0, 0x20, 1, 1);
    func_08011F18(0, 0x2E0, 0x100, 0x20, 1, 1);
    func_08011F18(0, 0x320, 0x100, 0x20, 1, 1);
    func_08011F18(0, 0x320, 0x120, 0x20, 1, 1);
    func_08000BD8(1, 1);
    var_r4 = 0;
    do
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
        var_r4 += 1;
    } while (var_r4 <= 0x1FU);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x0801DB09;
loop_13:
    func_0805EE78(1);
    goto loop_13;
}
