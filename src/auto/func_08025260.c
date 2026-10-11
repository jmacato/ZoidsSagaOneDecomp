#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();

void func_08025260(void)
{
    func_08008B58(0x26F);
    func_08011E08();
    func_08008B70(1, 0xFF, 0xFF);
    func_08011E24();
    func_08008B58(0x270);
    func_08011E08();
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x080252AD;
}
