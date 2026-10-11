#include "m2c.h"

M2C_UNK func_08000F88(s32);
s32 func_08001040(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08037990(s32);

void func_08006D94(void)
{
    if (func_08001040(0x13B) != 0)
    {
        func_08008B58(0x2D5);
        return;
    }
    func_08000F88(0x13B);
    func_08008B58(0x2D4);
    func_08037990(0x3D);
    func_08037990(0x3F);
    func_08037990(0x17);
    func_08037990(0x12);
    func_08037990(6);
    func_08037990(0x11);
    func_08037990(0x20);
    func_08037990(0x8C);
}
