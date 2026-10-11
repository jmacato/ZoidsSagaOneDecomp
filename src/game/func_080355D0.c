#include "types.h"

extern u8 D_02003FF8[];

u8 func_080355AC(u8);

void func_080355D0(void)
{
    u8 i;
    u32 slots;

    i = 0;
    slots = (u32)D_02003FF8;
    do
    {
        if (func_080355AC(*(u8 *)(i + slots)))
            *(u8 *)(i + slots) = 0xFF;
        i++;
    } while (i <= 5);
}
