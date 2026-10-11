#include "m2c.h"

M2C_UNK func_0803702C(u8);
M2C_UNK func_0803E488(s32, s32);

void func_080378C8(void)
{
    u8 var_r4;

    func_0803E488(0x0874FA90, 0x1F);
    func_0803E488(0x08675BEC, 6);
    func_0803E488(0x08675BEC, 7);
    func_0803E488(0x08675C5C, 0x3C);
    func_0803E488(0x08675BEC, 5);
    var_r4 = 0;
    do
    {
        func_0803702C(var_r4);
        var_r4 += 1;
    } while ((u32) var_r4 <= 0x20U);
    func_0803E488(0x0874FA90, 0x22);
}
