#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_0805EE78(s32);

void func_080249E4(void)
{
    func_08008B58(0x26A);
    func_08011E08();
    func_080076C0(0xED, 3, 0xD, 1, 0x0866B0D8);
    func_08001A08(1);
    D_02000B54.f_0 = 0;
    func_080019B4(1);
    func_08008B70(0, 5, 0xD);
    func_08011E24();
    func_08008B58(0x26B);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x08024A5D;
loop_1:
    func_0805EE78(1);
    goto loop_1;
}
