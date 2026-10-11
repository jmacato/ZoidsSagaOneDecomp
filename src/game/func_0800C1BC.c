#include "types.h"

extern u16 D_0300239C[];
extern u16 D_0832A4DC[];

s32 func_0800C1BC(u8 *text, u16 position)
{
    while (*text != 0)
    {
        D_0300239C[position] = 0xE000 + D_0832A4DC[*text];
        position++;
        text++;
    }
}
