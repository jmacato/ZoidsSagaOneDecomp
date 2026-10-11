#include "m2c.h"

extern struct { u8 pad_0[0x3C0]; s32 f_3C0; u8 pad_3C4[0xC]; s32 f_3D0; } D_02000034;
extern struct { u16 f_0; u8 pad_2[0x21EA]; u8 f_21EC; } D_0200EB84;

M2C_UNK func_08003DF8(s32, M2C_UNK);
M2C_UNK func_08003E3C(s32);
M2C_UNK func_0805EE78(s32);

void func_0803519C(void)
{
    s32 *var_r4;

    if ((0x20 & D_0200EB84.f_0) && (D_0200EB84.f_21EC == 1))
    {
        func_08003DF8(7, 0x08034AA1);
        var_r4 = (s32 *)((u8 *)&D_02000034);
        D_02000034.f_3C0 = 0xFD0C;
        func_0805EE78(1);
        var_r4 = (s32 *)((u8 *)&D_02000034 + 0x3D0);
        while (D_02000034.f_3D0 != 1)
        {
            func_0805EE78(1);
        }
        func_08003E3C(7);
        func_0805EE78(1);
    }
}
