#include "types.h"

struct Grid
{
    u8 count;
    u8 row;
    u8 col;
    u8 pad_3;
    u16 cursor;
    u8 cells[20][9];
    u8 used[20][9];
};

extern struct Grid D_0200EA14;
extern struct
{
    u8 pad_0[0x347B];
    u8 owned[0x21];
} D_02000B5C;

u8 func_0803B5C0(u8);

void func_0803B4DC(void)
{
    u8 row;
    u8 col;
    u8 i;

    for (row = 0; row < 20; row++)
    {
        for (col = 0; col < 9; col++)
        {
            D_0200EA14.cells[row][col] |= 0xFF;
            D_0200EA14.used[row][col] |= 0xFF;
        }
    }
    row = 0;
    col = 0;
    for (i = 0; i <= 0x20; i++)
    {
        if (D_02000B5C.owned[i])
        {
            D_0200EA14.cells[row][col] = i;
            if (func_0803B5C0(i))
                D_0200EA14.used[row][col] = 1;
            col++;
            if (col > 5)
            {
                col = 0;
                row++;
                if (row > 19)
                    row--;
            }
        }
    }
    if (row != 0 && col == 0)
        row--;
    D_0200EA14.count = row;
    D_0200EA14.col = 0;
    D_0200EA14.row = 0;
    D_0200EA14.cursor = 0xFF;
}
