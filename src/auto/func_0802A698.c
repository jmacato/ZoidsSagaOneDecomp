#include "m2c.h"

extern struct { u16 f_0; u16 f_2; } D_02007574;

M2C_UNK func_08000F88(s32);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_0803E024(s32, s32, s32);

void func_0802A698(void)
{
    func_0803E024(0, 0x140, 0xB4);
    func_08008B58(0x2CF);
    if ((D_02007574.f_2 == 0) && (D_02007574.f_0 != 0))
    {
        func_08000F88(0x138);
    }
}
