#include "types.h"

extern u16 D_03003B9C[];
extern u8 D_03005BAE;

void func_08043D54(u16 *src, u8 flags)
{
    u16 *dst = D_03003B9C;
    u16 index = 0;
    u16 y;
    u16 x;
    u16 tile;

    switch ((u8)(flags & 0x20))
    {
    case 0:
        for (y = 0; y < 16; y++)
        {
            for (x = 0; x < 16; x++)
            {
                dst[y * 32 + x] = src[index];
                dst[y * 32 + x + 16] = src[index];
                index++;
            }
        }
        break;
    case 0x20:
        for (y = 0; y < 16; y++)
        {
            for (x = 0; x < 16; x++)
            {
                tile = src[index] ^ 0x400;
                dst[y * 32 + (15 - x)] = tile;
                dst[y * 32 + (15 - x) + 16] = tile;
                index++;
            }
        }
        break;
    }
    D_03005BAE = 2;
}
