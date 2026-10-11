#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08018AA8(void)
{
    func_08011E08();
    func_080076C0(0x6F, 0x2A, 0x10, 5, 0x0866824C);
    func_08001A08(4);
    D_02000B54.f_0 = 0;
    func_080019B4(4);
    func_08011E24();
    func_08011F18(0, 0x560, 0x2A0, 0x20, 1, 1);
    func_08008B70(1, 0x2E, 0x17);
    func_0805EE78(0x1E);
    func_08011F18(1, 0x580, 0x2A0, 0x20, 2, 1);
    func_08000BD8(2, 2);
    func_08008B58(0x11D);
    func_08001A08(1);
    D_02000B54.f_0 = 0;
    func_080019B4(1);
    func_08008B58(0x11E);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x08018DB1;
}
