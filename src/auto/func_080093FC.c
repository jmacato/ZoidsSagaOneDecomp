#include "m2c.h"

M2C_UNK func_080090B4(u8);
u16 func_0805D4FC(u16, s32);

s32 func_080093FC(void)
{
    func_080090B4(M2C_FIELD(func_0805D4FC(*(u16 *)0x030022DC, 0xC), u8 *, 0x08666CD0));
}
