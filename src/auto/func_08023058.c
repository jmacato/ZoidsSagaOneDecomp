#include "m2c.h"

M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08023058(void)
{
loop_1:
    func_08008B70(0xE, 9, 9);
    func_0805EE78(2);
    func_08008B70(0xE, 0xFF, 0xFF);
    func_0805EE78(2);
    goto loop_1;
}
