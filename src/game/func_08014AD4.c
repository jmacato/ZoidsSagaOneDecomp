#include "types.h"

extern struct
{
    void *first;
} D_02000000;

extern struct
{
    u8 pad_0[0xE8];
    u16 field_E8;
} D_03004BBC;

s32 func_08001040(s32);
void func_08000BD8(s32);
void func_080019EC(s32);
void func_0805EE78(s32);
s32 func_08001A28(s32);
void func_08011E04(void);
void func_080161C0(void);
void func_08003D78(s32, void *);
void func_08000F88(s32);

void func_08014AD4(void)
{
    if (func_08001040(0x16B) == 0)
    {
        D_03004BBC.field_E8 = 1;
        func_08000BD8(2);
        func_080019EC(0x46);
        do
        {
            func_0805EE78(1);
        } while (func_08001A28(0x46) != 0);
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_080161C0);
        func_08000F88(0x16B);
    }
}
