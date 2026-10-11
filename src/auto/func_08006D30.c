#include "m2c.h"

M2C_UNK func_08000F88(s32);
s32 func_08001040(s32);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_08037990(s32);

void func_08006D30(void)
{
    if (func_08001040(0x13A) != 0)
    {
        func_08008B58(0x2D5);
        return;
    }
    func_08000F88(0x13A);
    func_08008B58(0x2D3);
    func_08037990(0x95);
    func_08037990(0x7C);
    func_08037990(0x80);
    func_08037990(0x7E);
    func_08037990(0x7F);
    func_08037990(0x7D);
    func_08037990(0x81);
    func_08037990(0x92);
}
