#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008324(s32, s32);
M2C_UNK func_08008B58(M2C_UNK);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_080250FC(void)
{
    u32 var_r4;

    func_08011E08();
    func_080076C0(0xED, 0x10, 0xA, 3, 0x0866B240);
    func_08001A08(4);
    D_02000B54.f_0 = 0;
    func_080019B4(4);
    func_08011E24();
    func_08011F18(0, 0x200, 0x120, 0x20, 1, 1);
    func_08011F18(0, 0x220, 0x120, 0x20, 1, 1);
    func_08011F18(0, 0x220, 0x100, 0x20, 1, 1);
    func_08000BD8(1, 0);
    func_08008B70(1, 0x10, 0xA);
    func_08011F18(1, 0x200, 0x120, 0x20, 1, 1);
    func_08011F18(1, 0x220, 0x120, 0x20, 1, 1);
    func_08000BD8(2, 0);
    var_r4 = 0;
    do
    {
        func_08008324(0, 0x10000);
        func_0805EE78(1);
        var_r4 += 1;
    } while (var_r4 <= 0x1FU);
    func_08008B58(0x26E);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x080251F9;
loop_3:
    func_0805EE78(1);
    goto loop_3;
}
