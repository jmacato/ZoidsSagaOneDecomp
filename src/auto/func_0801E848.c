#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08000F88(s32);
s32 func_08001040(s32);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037424(s32);
M2C_UNK func_0805EE78(s32);

void func_0801E848(void)
{
    func_08008B58(0x1DF);
    func_08008B70(2, 4, 0xE);
    func_08011F18(2, 0xE0, 0x1C0, 0x20, 1, 0);
    func_08000BD8(1, 2);
    func_08008B58(0x1E0);
    if (func_08001040(0x19A) == 0)
    {
        func_08000F88(0x19A);
        func_08008B70(3, 0xE, 0xC);
        func_08011F18(3, 0x140, 0x1C0, 0x20, 1, 0);
        func_08008B70(4, 0xE, 0xD);
        func_08011F18(4, 0x140, 0x1A0, 0x20, 1, 0);
        func_08001A08(9);
        D_02000B54.f_0 = 0;
        func_080019B4(9);
        func_08008B58(0x1E1);
        func_08037424(0x18);
        func_08037424(0x19);
    }
    else
    {
        func_08008B70(4, 9, 0xE);
        func_08011F18(4, 0x140, 0x1A0, 0x20, 1, 0);
        func_08000BD8(5, 2);
        func_08008B70(3, 9, 0xE);
        func_08011F18(3, 0x140, 0x1C0, 0x20, 1, 0);
        func_08000BD8(4, 2);
    }
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x0801E971;
loop_4:
    func_0805EE78(1);
    goto loop_4;
}
