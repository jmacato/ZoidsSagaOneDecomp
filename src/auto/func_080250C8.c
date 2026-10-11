#include "m2c.h"

M2C_UNK func_08016CA8(s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_080250C8(void)
{
loop_1:
    func_08016CA8(6, 5, 4);
    func_0805EE78(0xA);
    func_08016CA8(6, 5, 4);
    func_0805EE78(4);
    func_08016CA8(6, 5, 4);
    func_0805EE78(4);
    goto loop_1;
}
