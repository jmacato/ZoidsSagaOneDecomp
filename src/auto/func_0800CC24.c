#include "m2c.h"

extern struct { u16 f_0; u16 f_2; } D_02007574;

M2C_UNK func_08000F88(s32);
s32 func_08001040(s32);
M2C_UNK func_08008B58(s32);

s32 func_0800CC24(void)
{
    if (func_08001040(0x124) == 0)
    {
        func_08008B58(0x3F);
        if ((D_02007574.f_2 == 0) && (D_02007574.f_0 != 0))
        {
            return func_08000F88(0x124);
        }
    }
}
