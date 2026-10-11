#include "types.h"

extern struct
{
    u8 pad_0[4];
    u16 current;
    u8 grid[1][9];
} D_0200E8A4;

extern u8 D_08675BEC[];

void func_0803E488(u8 *, s32);
void func_08032858(u8);

void func_080393B8(u8 row, u8 column)
{
    u8 value = D_0200E8A4.grid[row][column];

    if (value != D_0200E8A4.current)
    {
        D_0200E8A4.current = value;
        func_0803E488(D_08675BEC, 7);
        func_0803E488(D_08675BEC, 5);
        if (value != 0xFF)
        {
            func_08032858(value);
            func_0803E488(D_08675BEC, 5);
        }
    }
}
