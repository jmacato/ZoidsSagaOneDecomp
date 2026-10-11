#include "types.h"

struct Load
{
    const void *src;
    void *dst;
    u16 size;
};

extern u16 D_020143DC[];
extern u8 D_0200E28E[];

void func_08001A54(const void *, s32, s32);

void func_08047EF4(u8 unused, u8 src, u8 count, u8 level)
{
    struct Load load;
    u8 amount = level <= 15 ? 16 - level : level - 16;
    u8 brighten = level > 15;
    u16 *in = &D_020143DC[src * 16];
    u16 *buffer = (u16 *)D_0200E28E;
    u16 *out;
    u16 i;

    while ((u32)buffer & 3)
        buffer++;
    out = buffer;
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
    load.src = buffer;
    load.dst = (void *)0x050003E0;
    load.size = 0x20;
    func_08001A54(&load, 0, 0);
}
