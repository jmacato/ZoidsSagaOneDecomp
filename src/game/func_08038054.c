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

struct Pilot
{
    u16 flags;
    u8 zoid;
    u8 pad_3;
};

extern struct Grid D_0200E8A4;
extern struct
{
    u8 pad_0[0x34A4];
    struct Pilot pilots[0x57];
} D_02000B5C;

void func_08038054(void)
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
    for (i = 0; i < 0x57; i++)
    {
        if (D_02000B5C.pilots[i].flags & 2)
        {
            D_0200E8A4.cells[row][col] = i;
            col++;
            if (col > 4)
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
