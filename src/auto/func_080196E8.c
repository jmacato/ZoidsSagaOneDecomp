#include "m2c.h"

extern struct { s32 f_0; } D_02000000;

s32 func_08001040(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_0800BEE4();

void func_080196E8(void)
{
    func_0800BEE4();
    if ((func_08001040(0x189) != 0) && (func_08001040(0x18E) == 0))
    {
        D_02000000.f_0 = 0x080197B1;
    }
    if ((func_08001040(0x189) == 0) || (func_08001040(0x190) != 0))
    {
        func_08008B70(1, 0xFF, 0xFF);
    }
}
