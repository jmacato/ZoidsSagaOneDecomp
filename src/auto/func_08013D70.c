#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_080019EC(s32);
s32 func_08001A28(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08013D70(void)
{
    func_0805EE78(0x20);
    func_080019EC(0x68);
    func_0805EE78(0x3C);
    func_0805EE78(0x3C);
    func_08011F18(1, 0xA0, 0x40, 0x20, 4, 1);
    do
    {
        func_0805EE78(1);
    } while (func_08001A28(0x68) == 0);
    func_08008B58(0x9D);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x08013DD9;
}
