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

struct Entry
{
    u8 id;
    u32 flag;
};

extern const struct Entry D_08669070[];
extern u8 D_030022E0;

s32 func_08008D28(s32);
void func_08011E04(void);
void func_0801A904(void);

void func_0801AE30(void)
{
    if (func_08008D28(D_08669070[D_030022E0].id))
    {
        func_08000BD8(1, 1);
        if (D_030022E0 <= 4)
        {
            func_08007188(0x90, 0xB, 8, 0xFFFF);
            func_080014A8(1, func_0800BEA4);
        }
        else if (D_030022E0 <= 9)
        {
            func_08007188(0x93, 0xB, 8, 0xFFFF);
            func_080014A8(1, func_0800BEA4);
        }
        else
        {
            func_08007188(0x96, 8, 4, 0xFFFF);
            func_080014A8(1, func_0800BEA4);
        }
    }
    else
    {
        func_08000F88(D_08669070[D_030022E0].flag);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_0801A904);
    }
}
