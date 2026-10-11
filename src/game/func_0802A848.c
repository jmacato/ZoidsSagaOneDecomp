#include "types.h"

extern struct
{
    void *first;
} D_02000000;

extern struct
{
    u8 pad_0[0x170];
    u16 field_170;
} D_03004BBC;

void func_0800BEE4(void);
s32 func_08001040(s32);
void func_08008B70(s32, s32, s32);
void func_08000F88(s32);
void func_08000FD8(s32);
void func_0800C4D0(void);
void func_0802A8C8(void);
void func_08003D78(s32, void *);

void func_0802A848(void)
{
    func_0800BEE4();
    if (func_08001040(0x13C) == 0)
    {
        if (func_08001040(0x13E) == 0)
        {
            func_08008B70(1, 0xD, 4);
            D_03004BBC.field_170 = 2;
            func_08000F88(0x13E);
        }
        else
        {
            D_03004BBC.field_170 = 2;
        }
        func_08000FD8(0x13D);
        D_02000000.first = func_0800C4D0;
        func_08003D78(3, func_0802A8C8);
    }
}
