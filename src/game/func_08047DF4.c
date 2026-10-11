#include "types.h"

extern u16 D_020143DC[];

void func_08047DF4(u8 dst, u8 src, u8 count, u8 level)
{
    u8 amount = level <= 15 ? 16 - level : level - 16;
    u8 brighten = level > 15;
    u16 *in = &D_020143DC[src * 16];
    u16 *out;
    u16 i;

    if (src <= 15)
        out = (u16 *)0x05000000 + dst * 16;
    else
        out = (u16 *)0x05000200 + (dst - 16) * 16;
    for (i = 0; i < count * 16; i++, out++, in++)
    {
        u16 r = *in & 0x1F;
        u16 g = (*in >> 5) & 0x1F;
        u16 b = (*in >> 10) & 0x1F;

        switch (brighten)
        {
        case 0:
            r -= amount * 2;
            g -= amount * 2;
            b -= amount * 2;
            if (r > 31)
                r = 0;
            if (g > 31)
                g = 0;
            if (b > 31)
                b = 0;
            break;
        case 1:
            r += amount * 2;
            g += amount * 2;
            b += amount * 2;
            if (r > 31)
                r = 31;
            if (g > 31)
                g = 31;
            if (b > 31)
                b = 31;
            break;
        }
        *out = r | (g << 5) | (b << 10);
    }
}
