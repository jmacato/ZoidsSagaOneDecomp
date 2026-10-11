#include "types.h"

extern struct
{
    u8 pad_0[0x10];
    s32 x;
    s32 y;
} D_03004B9C;

void func_0805EE78(u8);
void func_08003DD8(s32);
s32 func_08001080(void);

void func_0800C4D0(void)
{
}

void func_0800C4D4(void)
{
    u16 y;
    u16 x;
    u8 i;
    u16 dx;
    u16 dy;

    x = D_03004B9C.x >> 16;
    y = D_03004B9C.y >> 16;
    for (i = 16; i != 0xFF; i--)
    {
        if ((i & 3) == 0)
        {
            dx = i / 4;
            dy = i / 4;
        }
        else if ((i & 3) == 1)
        {
            dx = i / 4;
            dy = -i / 4;
        }
        else if ((i & 3) == 2)
        {
            dx = -i / 4;
            dy = -i / 4;
        }
        else
        {
            dx = -i / 4;
            dy = i / 4;
        }
        D_03004B9C.x = (x + dx) << 16;
        D_03004B9C.y = (y + dy) << 16;
        func_0805EE78(i / 4);
    }
    D_03004B9C.x = x << 16;
    D_03004B9C.y = y << 16;
    func_08003DD8(5);
}

void func_0800C570(void)
{
    u16 y;
    u16 x;
    u8 i;
    u16 dx;
    u16 dy;

    x = D_03004B9C.x >> 16;
    y = D_03004B9C.y >> 16;
    for (i = 12; i != 0xFF; i--)
    {
        if (func_08001080() & 1)
            dx = i;
        else
            dx = -i;
        if (func_08001080() & 1)
            dy = i;
        else
            dy = -i;
        D_03004B9C.x = (x + dx) << 16;
        D_03004B9C.y = (y + dy) << 16;
        func_0805EE78(i);
    }
    D_03004B9C.x = x << 16;
    D_03004B9C.y = y << 16;
    func_08003DD8(5);
}

void func_0800C5F8(void)
{
    u16 y;
    u16 x;
    u8 i;
    u16 dx;
    u16 dy;

    x = D_03004B9C.x >> 16;
    y = D_03004B9C.y >> 16;
    for (i = 16; i != 0xFF; i--)
    {
        if (func_08001080() & 1)
            dx = i;
        else
            dx = -i;
        if (func_08001080() & 1)
            dy = i;
        else
            dy = -i;
        D_03004B9C.x = (x + dx) << 16;
        D_03004B9C.y = (y + dy) << 16;
        func_0805EE78(i);
    }
    D_03004B9C.x = x << 16;
    D_03004B9C.y = y << 16;
    func_08003DD8(5);
}
