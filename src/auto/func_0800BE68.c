#include "m2c.h"

extern u8 D_02000000[];

M2C_UNK func_0805D29C(s32);

void func_0800BE68(void)
{
    func_0805D29C(*(s32 *)D_02000000);
}
