#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_0805EE78(s32);

void func_0802307C(void)
{
    func_08001A08(4);
    D_02000B54.f_0 = 0;
    func_080019B4(4);
    func_08008B58(0x23D);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x080230C5;
loop_1:
    func_0805EE78(1);
    goto loop_1;
}
