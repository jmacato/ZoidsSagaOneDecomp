#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08015400(void)
{
    func_0805EE78(0x20);
    func_08008B58(0xC0);
    func_08001A08(9);
    D_02000B54.f_0 = 0;
    func_080019B4(9);
    func_08011F18(1, 0x140, 0xA0, 0x20, 2, 1);
    func_08008B58(0xC1);
    func_08011F18(1, 0x140, 0x100, 0x20, 2, 1);
    func_08008B58(0xC2);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0x32, 0xA, 4, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
