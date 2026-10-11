#include "m2c.h"

M2C_UNK func_080328E4(u8);
M2C_UNK func_08036FAC(u8, s32);
M2C_UNK func_0803E488(s32, s32);

void func_08037920(u8 arg0)
{
    u8 temp_r4;

    temp_r4 = arg0;
    func_0803E488(0x0874FA90, 0x1F);
    func_08036FAC(temp_r4, 1);
    func_0803E488(0x08675BEC, 6);
    func_0803E488(0x08675BEC, 7);
    func_0803E488(0x08675C5C, 0x28);
    func_080328E4(temp_r4);
    func_0803E488(0x08675C5C, 9);
    func_0803E488(0x08675BEC, 5);
    func_0803E488(0x0874FA90, 0x22);
}
