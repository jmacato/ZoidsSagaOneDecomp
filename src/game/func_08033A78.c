#include "types.h"

struct Zoid
{
    u8 pad_0[8];
    u32 active;
    u8 pad_C[0x1C];
    u32 field_28;
    u8 pad_2C[0xC];
};

extern struct
{
    u8 pad_0[0xCDC];
    u16 field_CDC;
    u16 field_CDE;
    u16 field_CE0;
    u8 pad_CE2[0x4A];
    struct Zoid zoids[4];
} D_02000B5C;

void func_08003948(void);
void func_0803699C(s32, s32);
void func_08036B4C(s32, s32);
void func_0803723C(s32, s32, s32);
void func_08037A20(s32, s32);
void func_0803702C(u16);
void func_0803B724(s32, s32);
void func_080375F0(void);
void func_080328FC(s32, s32, s32);
void func_08033CFC(s32, s32, s32, s32);
void func_080329E4(s32, s32, s32, s32);
void func_08036F80(s32, s32);

void func_08033A78(u8 mode)
{
    u16 i;

    func_08003948();
    if (mode == 1)
    {
        func_0803699C(0x50, 0);
        func_08036B4C(0, 0);
        func_0803723C(1, 2, 0x56);
        func_0803723C(2, 2, 0x38);
        func_0803723C(3, 2, 0x4E);
        func_08037A20(1, 4);
        for (i = 0; i <= 0x20; i++)
            func_0803702C(i);
        func_0803B724(0x1B, 0);
        func_0803B724(0x1C, 1);
        func_0803B724(0x1D, 2);
        func_0803B724(0x1E, 3);
        func_0803B724(0x1F, 4);
        func_0803B724(0x20, 5);
        D_02000B5C.zoids[1].field_28 = 1;
        D_02000B5C.zoids[1].active = 1;
    }
    else if (mode == 2)
    {
        func_0803699C(0x39, 0);
        func_08036B4C(0, 0);
        func_0803723C(4, 0xE, 0x3D);
        func_0803723C(5, 6, 0);
        func_0803723C(6, 0xE, 0x48);
        func_0803723C(7, 6, 0);
        func_0803699C(0x29, 0);
        func_0803699C(0x38, 0);
        func_08036B4C(5, 1);
        func_08036B4C(7, 2);
        func_08037A20(4, 1);
        func_08037A20(5, 4);
        func_08037A20(6, 0);
        func_08037A20(7, 2);
        for (i = 0; i <= 0x20; i++)
            func_0803702C(i);
        func_0803B724(6, 0);
        func_0803B724(7, 1);
        func_0803B724(8, 2);
        func_0803B724(9, 3);
        func_0803B724(0xA, 4);
        func_0803B724(0xB, 5);
    }
    else
    {
        func_0803699C(0x43, 0);
        func_08036B4C(0, 0);
        func_08037A20(0, 1);
        func_0803723C(1, 2, 0x46);
        func_0803723C(2, 2, 0x46);
        func_0803723C(3, 2, 0x46);
        D_02000B5C.field_CDC = 100;
        D_02000B5C.field_CDE = 100;
        D_02000B5C.field_CE0 = 100;
        func_080375F0();
        for (i = 0; i <= 0x20; i++)
            func_0803702C(i);
        func_0803B724(0x13, 0);
        func_0803B724(0xA, 1);
        func_0803B724(4, 2);
        func_0803B724(5, 3);
        func_0803B724(6, 4);
        func_0803B724(7, 5);
    }
    D_02000B5C.zoids[0].active = 1;
    D_02000B5C.zoids[1].active = 1;
    D_02000B5C.zoids[2].active = 1;
    D_02000B5C.zoids[3].active = 1;
    func_080328FC(0, 0, 0);
    func_08033CFC(0, 0, 4, 0);
    func_080329E4(0, 0, 1, 1);
    func_08036F80(0, 0x10);
    func_08036F80(1, 0x10);
    func_08036F80(2, 0x10);
    func_08036F80(3, 0x10);
    func_08036F80(4, 0x10);
    func_08036F80(5, 0x10);
}
