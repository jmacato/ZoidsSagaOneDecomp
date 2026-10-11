#include "m2c.h"

M2C_UNK func_08032800(u8);
s32 func_08037004(u8);
M2C_UNK func_0803E488(s32, s32);

void func_08037990(u8 arg0)
{
    u8 temp_r4;

    temp_r4 = arg0;
    func_0803E488(0x0874FA90, 0x1F);
    func_0803E488(0x08675BEC, 6);
    func_0803E488(0x08675BEC, 7);
    func_0803E488(0x08675C5C, 0x2A);
    func_08032800(temp_r4);
    func_0803E488(0x08675C5C, 0x2B);
    func_0803E488(0x08675BEC, 5);
    if (func_08037004(temp_r4) != 0)
    {
        func_0803E488(0x08675BEC, 0x14);
        func_0803E488(0x08675BEC, 6);
        func_0803E488(0x08675BEC, 7);
        func_0803E488(0x08675C5C, 0x2C);
        func_0803E488(0x08675BEC, 5);
    }
    func_0803E488(0x0874FA90, 0x22);
}
