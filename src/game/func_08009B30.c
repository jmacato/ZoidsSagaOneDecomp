#include "types.h"

extern u16 D_0300239C[];
extern u16 D_08329318[];

s32 func_08009B30(u8 *text, u16 position)
{
    while (*text != 0)
    {
        D_0300239C[position] = D_08329318[*text];
        position++;
        text++;
    }
}
