#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

extern struct
{
    u8 pad_0[0x18];
    u16 delay;
    u16 music;
} D_0200000C;

extern u16 D_02000B54;

void func_0805EE78(s32);
void func_08000BD8(s32, s32);
void func_080019EC(s32);
void func_08008B70(s32, s32, s32);
void func_08008B58(s32);
void func_08011E08(void);
void func_08011E24(void);
void func_08008024(void);
void func_08003DD8(s32);
void func_08003D78(s32, void *);
void func_08007188(s32, s32, s32, s32);
void func_080076C0(s32, s32, s32, s32, const void *);
void func_0800BEA4(void);
void func_080014A8(s32, void *);
void func_08001A08(s32);
void func_080019B4(s32);
void func_08011F18(s32, s32, s32, s32, s32, s32);
s32 func_08001A28(s32);
void func_08000F88(s32);

extern struct
{
    u8 pad_0[0xE8];
    u16 field_E8;
} D_03004BBC;

extern struct
{
    u8 pad_0[0xA];
    u16 field_A;
} D_02000B5C;

s32 func_08001040(s32);
u8 func_08014480(void);
void func_080144BC(void);
void func_08011E04(void);
void func_08015968(void);
void func_080159B4(void);
void func_08015118(void);

void func_080144DC(void)
{
    u32 r;

    r = func_08014480();

    if (r)
    {
        if (func_08001040(0x162) && !func_08001040(0x163))
        {
            D_03004BBC.field_E8 = 1;
            D_02000000.first = func_08011E04;
            func_08003D78(3, func_08015968);
            D_02000B5C.field_A = 0;
            func_08000F88(0x163);
        }
        else if (func_08001040(0x163) && !func_08001040(0x164))
        {
            if (D_02000B54 != 4)
            {
                func_08001A08(4);
                D_02000B54 = 0;
                func_080019B4(4);
            }
            if (D_02000B5C.field_A > 2)
            {
                D_03004BBC.field_E8 = 1;
                D_02000000.first = func_08011E04;
                func_08003D78(3, func_080159B4);
                func_08000F88(0x164);
            }
            else
                func_080144BC();
        }
        else
        {
            D_03004BBC.field_E8 = 1;
            D_02000000.first = func_08011E04;
            func_08003D78(3, func_08015118);
        }
    }
    else
    {
        D_02000B5C.field_A = r;
        if (D_02000B54 == 4)
        {
            func_08001A08(D_0200000C.music);
            D_02000B54 = r;
            func_080019B4(D_0200000C.music);
        }
    }
}

void func_08014608(void)
{
}
