#include "types.h"

extern u16 D_0300239C[];

void func_0805EE78(s32);

void func_0800338C(void)
{
    u32 pass;
    u32 tile;
    u32 y;
    u32 x;

    for (;;)
    {
        for (pass = 0; pass < 2; pass++)
        {
            tile = 0;
            for (y = 9; y < 10; y++)
            {
                for (x = 0; x < 4; x++)
                {
                    D_0300239C[y * 32 + 0x40A + x] = tile + 0xE221;
                    tile++;
                }
            }
            func_0805EE78(0xF);
            for (y = 9; y < 10; y++)
            {
                for (x = 0; x < 5; x++)
                {
                    D_0300239C[y * 32 + 0x40E + x] = tile + 0xE221;
                    tile++;
                }
            }
            func_0805EE78(0xF);
            for (y = 9; y < 10; y++)
            {
                for (x = 0; x < 9; x++)
                {
                    D_0300239C[y * 32 + 0x40A + x] = 0x100;
                }
            }
            func_0805EE78(0xF);
        }
        for (pass = 0; pass < 2; pass++)
        {
            tile = 0;
            for (y = 9; y < 10; y++)
            {
                for (x = 0; x < 9; x++)
                {
                    D_0300239C[y * 32 + 0x40A + x] = tile + 0xE221;
                    tile++;
                }
            }
            func_0805EE78(0xF);
            for (y = 9; y < 10; y++)
            {
                for (x = 0; x < 9; x++)
                {
                    D_0300239C[y * 32 + 0x40A + x] = 0x100;
                }
            }
            func_0805EE78(0xF);
        }
    }
}
