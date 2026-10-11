#include "m2c.h"

M2C_UNK func_08032888();
M2C_UNK func_0803E488(M2C_UNK, s32);

void func_0803C084(u8 arg0)
{
    if (arg0 != 0xFF)
    {
        func_08032888();
        return;
    }
    func_0803E488(0x08675C5C, 0x23);
}
