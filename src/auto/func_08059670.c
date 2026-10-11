#include "m2c.h"

M2C_UNK func_08038A6C();
M2C_UNK func_08059980();
s32 func_08059A78();
M2C_UNK func_08059B68();
M2C_UNK func_08059BF8();
M2C_UNK func_08059C48();
M2C_UNK func_0805A924();
M2C_UNK func_0805AD14(s32);
M2C_UNK func_0805AE50(s32);

void func_08059670(s32 arg0)
{
    func_08038A6C();
    func_08059980();
    func_08059C48();
    if ((func_08059A78() << 0x18) == 0)
    {
        func_08059980();
        func_08059BF8();
    }
    else
    {
        func_0805AE50(0x12);
        func_0805A924();
        if ((func_08059A78() << 0x18) == 0)
        {
            func_08059980();
            func_08059C48();
            func_0805AE50(0x12);
            func_0805AD14(arg0);
            if ((func_08059A78() << 0x18) == 0)
            {
                func_08059980();
                func_08059BF8();
            }
        }
    }
    func_08059B68();
}
