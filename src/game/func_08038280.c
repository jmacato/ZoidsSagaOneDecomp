#include "types.h"

extern struct
{
    u8 pad_0[4];
    u16 current;
    u8 grid[1][9];
} D_0200E8A4;

extern u8 D_08675BEC[];
extern u8 D_08675C5C[];

u16 func_080373F0(u8);
void func_0803E488(u8 *, s32);
void func_08032800(u16);

void func_08038280(u8 row, u8 column)
{
    u16 value = func_080373F0(D_0200E8A4.grid[row][column]);

    if (value != D_0200E8A4.current)
    {
        D_0200E8A4.current = value;
        func_0803E488(D_08675BEC, 0xC);
        func_0803E488(D_08675BEC, 0xA);
        if (value != 0xFF)
            func_08032800(value);
        else
            func_0803E488(D_08675C5C, 0x15);
        func_0803E488(D_08675BEC, 0xA);
    }
}
