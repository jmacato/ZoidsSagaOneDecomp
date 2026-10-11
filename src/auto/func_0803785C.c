#include "m2c.h"

M2C_UNK func_08032888(u8);
M2C_UNK func_0803702C(u8);
M2C_UNK func_0803E488(s32, s32);

void func_0803785C(u8 arg0)
{
    u8 temp_r4;

    temp_r4 = arg0;
    func_0803E488(0x0874FA90, 0x1F);
    func_0803E488(0x08675BEC, 6);
    func_0803E488(0x08675BEC, 7);
    func_0803E488(0x08675C5C, 0x39);
    func_08032888(temp_r4);
    func_0803E488(0x08675C5C, 0x3A);
    func_0803E488(0x08675BEC, 5);
    func_0803702C(temp_r4);
    func_0803E488(0x0874FA90, 0x22);
}
