#include "m2c.h"

M2C_UNK func_08038A6C();
s32 func_08059410(s32);
M2C_UNK func_08059980();
s32 func_08059A78();
M2C_UNK func_08059B68();
M2C_UNK func_08059BF8();
M2C_UNK func_08059D60();
M2C_UNK func_0805AFA4(s32, s32);

void func_080596D8(s32 arg0)
{
    func_08038A6C();
    if ((func_08059410(arg0) << 0x18) == 0)
    {
        func_08059980();
        func_08059BF8();
        func_0805AFA4(arg0, 0x224);
        if ((func_08059A78() << 0x18) == 0)
        {
            func_08059980();
            func_08059BF8();
            func_08059D60();
        }
    }
    func_08059B68();
}
