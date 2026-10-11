#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { s16 f_0; } D_02000B54;
extern struct { u8 pad_0[0x2A8]; u16 f_2A8; } D_03004BBC;

M2C_UNK func_08000BD8(s32, s32);
M2C_UNK func_080019B4(s32);
M2C_UNK func_080019EC(s32);
M2C_UNK func_08001A08(s32);
s32 func_08001A28(s32);
M2C_UNK func_08003D78(s32, M2C_UNK);
M2C_UNK func_08003DD8(s32);
M2C_UNK func_080076C0(s32, s32, s32, s32, s32);
M2C_UNK func_08008324(s32, s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_08008B70(s32, s32, s32);
M2C_UNK func_08011E08();
M2C_UNK func_08011E24();
M2C_UNK func_08011F18(s32, s32, s32, s32, s32, s32);
M2C_UNK func_0805EE78(s32);

void func_08023F94(void)
{
    u32 var_r4;
    u32 var_r4_2;

    func_0805EE78(0x20);
    func_08008B58(0x257);
    func_08011E08();
    func_080076C0(0xEC, 4, 0xE, 8, 0x0866AFC0);
    func_08001A08(1);
    D_02000B54.f_0 = 0;
    func_080019B4(1);
    func_08008B70(0, 0xFF, 0xFF);
    func_08011E24();
    func_08008B58(0x258);
    func_08003D78(4, 0x08024391);
    func_08003D78(5, 0x080243CD);
    func_08003D78(6, 0x08024409);
    func_08011F18(3, 0xE0, 0x1A0, 0x20, 1, 1);
    func_08011F18(3, 0x60, 0x1A0, 0x20, 1, 1);
    func_08011F18(3, 0x60, 0x1C0, 0x20, 1, 1);
    func_08000BD8(4, 3);
    func_0805EE78(0xF);
    func_08008B70(7, 4, 0xF);
    func_080019EC(0x81);
    do
    {
        func_0805EE78(1);
    } while (func_08001A28(0x81) == 0);
    func_08008B70(4, 4, 0xF);
    func_08000BD8(5, 0);
    D_03004BBC.f_2A8 |= 0x400;
    func_080019EC(0x4B);
    if (!(4 & D_03004BBC.f_2A8))
    {
        do
        {
            func_0805EE78(1);
        } while (!(4 & D_03004BBC.f_2A8));
    }
    do
    {
        func_0805EE78(1);
    } while (func_08001A28(0x4B) == 0);
    func_08008B58(0x259);
    func_08008B70(7, 0xFF, 0xFF);
    func_08003D78(4, 0x08024429);
    func_08003D78(5, 0x08024455);
    func_08011F18(3, 0x60, 0x1A0, 0x20, 1, 1);
    func_08011F18(3, 0x120, 0x1A0, 0x20, 2, 1);
    func_08008B70(3, 0xFF, 0xFF);
    var_r4 = 0;
    do
    {
        func_08008324(0x40000, 0);
        func_0805EE78(1);
        var_r4 += 1;
    } while (var_r4 <= 0x47U);
    var_r4_2 = 0;
    do
    {
        func_08008324(0, 0x40000);
        func_0805EE78(1);
        var_r4_2 += 1;
    } while (var_r4_2 <= 0xFU);
    func_08008B58(0x25A);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x08024191;
loop_11:
    func_0805EE78(1);
    goto loop_11;
}
