#include "types.h"

extern u16 D_0300239C[];

void func_08002404(u32 first, u32 end)
{
    register u32 end_column asm("r4") = end;
    register u32 row asm("r2") = 0;
    register u32 tilemap_start asm("r12");

    asm("" : : "r"(end_column), "r"(row));
    tilemap_start = 0xC00;
    asm("" : "+r"(tilemap_start));
    do
    {
        u32 column = first;
        register u32 next_row asm("r5") = row + 1;

        if (column < end_column)
        {
            register u32 row_offset asm("r0") = row * 32;
            register u32 tile asm("r1") = row * 11;
            u16 *tilemap = D_0300239C;
            register u32 index asm("r2");

            asm("" : : "r"(row_offset));
            tile += 0xB10D;
            tile = column + tile;
            index = column + (row_offset + tilemap_start);
            do
            {
                asm("" : "+r"(index));
                tilemap[index] = tile;
                tile++;
                index++;
                column++;
            } while (column < end_column);
        }
        row = next_row;
    } while (row <= 3);
}
