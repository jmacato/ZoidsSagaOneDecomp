#include "types.h"

extern struct
{
    void *first;
} D_02000000;

extern struct
{
    u8 pad_0[0xD6];
    u16 x;
    u16 y;
} D_03004BBC;

extern u8 D_0832B2E0[];
extern u8 D_0832B330[];
extern u8 D_0832B380[];

void func_0800BEE4(void);
void func_08000FD8(s32);
s32 func_08001040(s32);
void func_080079E8(s32, s32, s32, s32, u8 *);
void func_08008B70(s32, s32, s32);
void func_0800C4D0(void);
void func_08003D78(s32, void *);
void func_08029F40(void);

void func_08029E50(void)
{
    u16 x;
    u16 y;

    func_0800BEE4();
    func_08000FD8(0x138);
    if (!func_08001040(0x137))
    {
        if (!func_08001040(0x139))
        {
            x = D_03004BBC.x;
            y = D_03004BBC.y;
            func_080079E8(0x154, x, y, 4, D_0832B2E0);
            func_08008B70(0, 2, 5);
        }
        else
        {
            x = D_03004BBC.x;
            y = D_03004BBC.y;
            func_080079E8(0x154, x, y, 4, D_0832B380);
        }
    }
    else if (!func_08001040(0x139))
    {
        x = D_03004BBC.x;
        y = D_03004BBC.y;
        func_080079E8(0x154, x, y, 4, D_0832B330);
    }
    else
    {
        x = D_03004BBC.x;
        y = D_03004BBC.y;
        func_080079E8(0x154, x, y, 4, D_0832B380);
    }
    D_02000000.first = func_0800C4D0;
    func_08003D78(3, func_08029F40);
}
