#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019EC(s32);
s32 func_08001A28(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_0801D93C();
M2C_UNK func_0801D968();
M2C_UNK func_0805EE78(s32);

void func_080228E8(void)
{
    u32 var_r4;

    func_080019EC(0x81);
    func_08011E24();
    func_0801D93C();
    var_r4 = 0;
    do
    {
        func_080019EC(0x5B);
        var_r4 += 1;
loop_2:
        func_0805EE78(1);
        if (func_08001A28(0x5B) == 0)
        {
            goto loop_2;
        }
        func_080019EC(0x5B);
        func_0805EE78(0xF);
        func_080019EC(0x5B);
loop_4:
        func_0805EE78(1);
        if (func_08001A28(0x5B) == 0)
        {
            goto loop_4;
        }
    } while (var_r4 <= 1U);
    func_08008B70(1, 0xFF, 0xFF);
    func_08008B70(2, 0xFF, 0xFF);
    func_08008B70(3, 0xFF, 0xFF);
    func_0801D968();
    func_0805EE78(0x3C);
    func_08008B58(0x229);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xED, 0xE, 0xA, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
