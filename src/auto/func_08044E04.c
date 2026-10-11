#include "m2c.h"

M2C_UNK func_08001A54(s32, u16, s32);
s32 func_08044DB8(s32, u16);
M2C_UNK func_08044E50(M2C_UNK, u8);

void func_08044E04(u32 incoming_model, u32 incoming_mode)
{
    u16 arg0 = (u16)incoming_model;
    u16 arg1 = (u16)incoming_mode;
    u16 temp_r4;

    temp_r4 = arg0;
    if ((func_08044DB8(0x086F87D0, temp_r4) << 0x18) != 0)
    {
        func_08001A54(0x086F8F5C, temp_r4, 1);
        func_08001A54(0x086F87D0, temp_r4, 1);
        func_08044E50(0x085643A4, (u8) arg1);
    }
}
