#include "types.h"

struct Window
{
    u16 id;
    u8 open;
};

extern u16 D_03002356;
extern u32 D_0200DAA4;
extern u8 D_0200E238;
extern u8 D_0200DA71;
extern u8 D_0200DAA8;

void func_08043CD8(u16, u8);
void func_08043C50(u16, u8);
void func_08041EE8(s32);

void func_08043E18(struct Window *window, u16 menu, u8 mode)
{
    D_03002356 = 0x10;
    *(vu16 *)0x04000050 = 0x3FFF;
    *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0xFFFC) | 3;
    D_0200DAA4 = 0;
    switch (mode & 0x20)
    {
    case 0:
        D_0200E238 = 0;
        break;
    case 0x20:
        D_0200E238 = 0x20;
        break;
    }
    if (mode != 0xFF)
    {
        switch (window->open)
        {
        case 0:
            func_08043CD8(menu * 3, mode);
            break;
        case 1:
            func_08043CD8(menu * 3 + 1, mode);
            break;
        case 2:
            func_08043CD8(menu * 3 + 2, mode);
            break;
        }
    }
    else
        func_08043C50(menu * 3 + 2, 0xFF);
    D_0200DA71 = menu;
    D_0200DAA8 = mode;
}

void func_08043ED8(struct Window *window, u16 menu, u8 mode)
{
    if (menu == 3)
        func_08041EE8(1);
    else
        func_08041EE8(0);
    switch (mode & 0x20)
    {
    case 0:
        D_0200E238 = 0;
        break;
    case 0x20:
        D_0200E238 = 0x20;
        break;
    }
    switch (window->open)
    {
    case 0:
        func_08043CD8(menu * 3, mode);
        break;
    case 1:
        func_08043CD8(menu * 3 + 1, mode);
        break;
    case 2:
        func_08043CD8(menu * 3 + 2, mode);
        break;
    }
    D_0200DA71 = menu;
    D_0200DAA8 = mode;
}
