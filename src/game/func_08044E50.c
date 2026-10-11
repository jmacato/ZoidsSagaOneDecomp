#include "types.h"

extern u16 D_03002B9C[];
extern u8 D_03005BAE;

void func_08044E50(u16 *source, u8 flags)
{
    u16 *tilemap = D_03002B9C;
    u16 index = 0;
    u16 y;
    u16 x;

    switch (flags & 0x20)
    {
    case 0:
        for (y = 0; y <= 15; y++)
        {
            for (x = 0; x <= 15; x++)
            {
                tilemap[y * 32 + x] = source[index];
                index++;
            }
        }
        break;
    case 0x20:
        for (y = 0; y <= 15; y++)
        {
            for (x = 0; x <= 15; x++)
            {
                u16 tile = source[index] ^ 0x400;

                tilemap[y * 32 + (15 - x)] = tile;
                index++;
            }
        }
        break;
    }
    D_03005BAE = 2;
}
