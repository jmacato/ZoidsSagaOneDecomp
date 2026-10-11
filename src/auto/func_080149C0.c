#include "m2c.h"

s32 func_08001040(s32);
M2C_UNK func_08008B58(s32);

void func_080149C0(void)
{
    if (func_08001040(0x164) == 0)
    {
        func_08008B58(0x2D7);
        return;
    }
    if (func_08001040(0x169) == 0)
    {
        func_08008B58(0x2D8);
        return;
    }
    if (func_08001040(0x16A) == 0)
    {
        func_08008B58(0x2D9);
        return;
    }
    if (func_08001040(0x16B) == 0)
    {
        func_08008B58(0x2DA);
        return;
    }
    func_08008B58(0x2DB);
}
