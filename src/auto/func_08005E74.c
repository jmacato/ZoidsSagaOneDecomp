#include "m2c.h"

extern struct { u8 pad_0[0xC]; s32 f_C; s32 f_10; s32 f_14; s8 f_18; } D_03001F8C;

M2C_UNK func_0805D194();

void func_08005E74(void)
{
    func_0805D194();
    D_03001F8C.f_14 = 0;
    D_03001F8C.f_10 = 0;
    D_03001F8C.f_C = 0;
    D_03001F8C.f_18 = 0;
}
