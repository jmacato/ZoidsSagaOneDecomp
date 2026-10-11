#include "m2c.h"

extern u8 D_03001F8C[];
extern u8 D_08666CB0[];

M2C_UNK func_08005EC0(M2C_UNK, u8, s32, M2C_UNK);

s32 func_08005E90(u8 arg0, s32 arg1, u8 arg2, s32 arg3, s32 arg4)
{
    M2C_FIELD((u8 *)D_03001F8C, s32 *, 0) = arg3;
    M2C_FIELD((u8 *)D_03001F8C, s32 *, 8) = arg4;
    M2C_FIELD((u8 *)D_03001F8C, s32 *, 4) = (s32) arg2;
    return func_08005EC0(D_03001F8C, arg0, arg1, D_08666CB0);
}
