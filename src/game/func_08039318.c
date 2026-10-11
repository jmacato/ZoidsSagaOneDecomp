#include "types.h"

struct Grid
{
    u8 count;
    u8 row;
    u8 col;
    u8 pad_3;
    u16 cursor;
    u8 cells[20][9];
};

extern struct Grid D_0200E8A4;
extern struct
{
    u8 pad_0[0x3305];
    u8 owned[7];
} D_02000B5C;

void func_08039318(void)
{
    u8 row;
    u8 col;
    u8 i;

    for (row = 0; row < 20; row++)
    {
        for (col = 0; col < 9; col++)
            D_0200E8A4.cells[row][col] |= 0xFF;
    }
    row = 0;
    col = 0;
    for (i = 0; i < 7; i++)
    {
        if (D_02000B5C.owned[i] && i != 6)
        {
            D_0200E8A4.cells[row][col] = i;
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
    D_0200E8A4.count = row;
    D_0200E8A4.col = 0;
    D_0200E8A4.row = 0;
    D_0200E8A4.cursor = 0xFF;
}
