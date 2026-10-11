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

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_08011E04(void);
void func_08015BEC(void);
void func_08015F18(void);
void func_08003D78(s32, void *);
void func_08000F88(s32);

void func_08014654(void)
{
    func_0800BEE4();
    if (func_08001040(0x165) != 0 && func_08001040(0x166) != 0 && func_08001040(0x167) != 0 &&
        func_08001040(0x168) != 0 && func_08001040(0x169) == 0)
    {
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08015BEC);
        func_08000F88(0x169);
    }
    else if (func_08001040(0x158) != 0 && func_08001040(0x169) == 0)
    {
        D_03004BBC.field_E8 = 1;
        D_02000000.first = func_08011E04;
        func_08003D78(3, func_08015F18);
    }
}
