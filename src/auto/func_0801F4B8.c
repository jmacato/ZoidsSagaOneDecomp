#include "m2c.h"

extern u8 D_02000000[];
extern u8 D_02000B54[];

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_0801F4B8(void)
{
    func_08011E24();
    func_08011F18(1, 0x100, 0xC0, 0x20, 4, 1);
    func_08008B70(1, 0xFF, 0xFF);
    func_08001A08(8);
    *(s16 *)D_02000B54 = 0;
    func_080019B4(8);
    func_08008B58(0x1EE);
    func_08011F18(2, 0x100, 0x40, 0x20, 1, 0);
    func_08011F18(0, 0xE0, 0x40, 0x20, 1, 0);
    func_08000BD8(1, 3);
    func_08008B58(0x1EF);
    func_08011F18(2, 0xE0, 0x40, 0x20, 1, 0);
    func_08008B70(2, 0xFF, 0xFF);
    func_0805EE78(0x1E);
    func_08011F18(0, 0x100, 0x40, 0x20, 1, 1);
    func_08011F18(0, 0x100, 0x160, 0x20, 1, 1);
    func_08011E08();
    *(s32 *)D_02000000 = 0x08008025;
    func_08003DD8(3);
    *(s32 *)D_02000000 = 0x0801F5A1;
loop_1:
    func_0805EE78(1);
    goto loop_1;
}
