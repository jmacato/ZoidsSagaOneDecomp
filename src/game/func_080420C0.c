#include "types.h"

extern u8 D_0200DA80[2][8];

u32 func_080420C0(void)
{
    u8 row;
    u8 column;

    for (row = 0; row <= 1; row++)
    {
        register u32 encoded_row asm("r5");
        register u32 row_offset asm("r4");

        column = 0;
        row_offset = row * 8;
        asm("" : : "r"(row_offset));
        encoded_row = (u32)row << 29;
        for (; column <= 5; column++)
        {
            u8 *entry = (u8 *)D_0200DA80 + (column + row_offset);

            if (*entry != 0)
            {
                register u32 result asm("r0");

                asm("" : "+r"(encoded_row));
                result = (encoded_row >> 24) | column;
                asm("" : "+r"(result));
                {
                    register u32 zero asm("r1") = 0;

                    asm("" : "+r"(zero));
                    *entry = zero;
                }
                return result;
            }
        }
    }
    return 0xFF;
}
