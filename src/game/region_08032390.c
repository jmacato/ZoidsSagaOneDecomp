#include "types.h"

extern const u8 *const D_0866B8EC[][4];

u8 func_08032A88(u8, u8);
void func_080019EC(s32);

void region_08032390(u8 side, u8 *cursor, u16 *keys)
{
    u8 old = *cursor;
    u8 direction = 0xFF;

    if (*keys & 0x40)
        direction = 0;
    else if (*keys & 0x80)
        direction = 1;
    else if (*keys & 0x20)
        direction = 2;
    else if (*keys & 0x10)
        direction = 3;
    if (direction != 0xFF)
    {
        const u8 *next;

        for (next = D_0866B8EC[*cursor][direction]; *next != 0xFF; next++)
        {
            if (func_08032A88(side, *next))
            {
                *cursor = *next;
                break;
            }
        }
    }
    if (old != *cursor)
        func_080019EC(0x40);
}
