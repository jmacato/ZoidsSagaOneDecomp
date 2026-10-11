#include "m2c.h"

M2C_UNK func_0800BFE4(s32, M2C_UNK);

void func_0800BFB4(void)
{
    void *temp_r4;

    temp_r4 = (*(u8 *)0x02000030 * 0x88) + 0x02000034;
    func_0800BFE4(1, 0xFFFF);
    M2C_FIELD(temp_r4, s32 *, 0x18) = 1;
}
