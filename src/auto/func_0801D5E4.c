#include "m2c.h"

extern u8 D_02000000[];
extern u8 D_02000B54[];
extern u8 D_02007574[];
extern u8 D_08669AE0[];
extern u8 D_08669B58[];

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_08000F88(s32);
M2C_UNK func_080014A8(s32, M2C_UNK);
M2C_UNK func_080019B4(s32);
M2C_UNK func_08001A08(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_08007188(s32, s32, s32, M2C_UNK);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_08037424(s32);
M2C_UNK func_0805EE78(s32);

void func_0801D5E4(void)
{
    func_0805EE78(0x20);
    func_08000BD8(1, 0);
    func_0805EE78(0xF);
    func_08001A08(9);
    *(s16 *)D_02000B54 = 0;
    func_080019B4(9);
    func_08008B58(0x1B5);
    func_08011E08();
    func_080076C0(0xD8, 0xC, 0x12, 6, D_08669AE0);
    func_08001A08(9);
    *(s16 *)D_02000B54 = 0;
    func_080019B4(9);
    func_08008B70(0, 0xC, 0x18);
    func_08011E24();
    func_08000BD8(5, 1);
    func_08000BD8(6, 1);
    func_0805EE78(0xF);
    func_08003D78(4, 0x0801D865);
    func_08003D78(5, 0x0801D885);
    func_08003D78(6, 0x0801D8A5);
    func_08011F18(0, 0xC0, 0x110, 0x10, 1, 0);
    func_08008B58(0x1B6);
    func_08011F18(3, 0xA0, 0x120, 0x10, 1, 0);
    func_08011F18(3, 0xA0, 0xF0, 0x10, 1, 0);
    func_08011F18(3, 0xB0, 0xF0, 0x10, 1, 0);
    func_08000BD8(5, 2);
    func_0805EE78(0x3C);
    func_08011F18(3, 0xA0, 0xF0, 0x10, 1, 0);
    func_08011F18(3, 0xA0, 0x120, 0x10, 1, 0);
    func_08011F18(3, 0xB0, 0x120, 0x10, 1, 0);
    func_08000BD8(4, 0);
    func_08000BD8(5, 1);
    func_08008B58(0x1B7);
    if ((M2C_FIELD((u8 *)D_02007574, u16 *, 0) != 0) && (M2C_FIELD((u8 *)D_02007574, u16 *, 2) != 1))
    {
        func_08008B58(0x1B8);
        func_08037424(0x16);
        func_08037424(0x17);
        func_08000F88(0x1A4);
    }
    else
    {
        func_08008B58(0x1B9);
        func_08011F18(4, 0xD0, 0x100, 0x10, 1, 0);
        func_08003D78(4, 0x0801D8C5);
        func_08011F18(4, 0xD0, 0x110, 0x10, 1, 0);
        func_08000BD8(1, 1);
        func_08000BD8(2, 1);
        func_08000BD8(3, 1);
        func_08000BD8(4, 1);
        func_0805EE78(0xF);
        func_08008B58(0x1BA);
        func_08003D78(4, 0x0801D8F9);
        func_08011F18(4, 0xD0, 0x180, 0x10, 1, 0);
        func_08008B70(4, 0xFF, 0xFF);
    }
    func_08011E08();
    func_080076C0(0xD8, 0xA, 5, 4, D_08669B58);
    func_08008B70(0, 0xB, 5);
    func_08011E24();
    func_08008B58(0x1BB);
    func_08011E08();
    *(s32 *)D_02000000 = 0x08008025;
    func_08003DD8(3);
    func_08007188(0xB0, 0x1B, 3, 0xFFFF);
    func_080014A8(1, 0x0800BEA5);
}
