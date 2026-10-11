#include "types.h"

s32 func_08001040(s32);

u16 func_0804CDA8(u8 kind, u8 limit)
{
    u16 skipped = 0;
    u16 count = 0;
    u16 i;

    switch (kind)
    {
    case 0:
        for (i = 1; i <= 4; i++)
        {
            if (!func_08001040(i) && limit >= skipped)
                count++;
            else
                skipped++;
        }
        break;
    case 1:
        for (i = 6; i <= 9; i++)
        {
            if (!func_08001040(i) && limit >= skipped)
                count++;
            else
                skipped++;
        }
        break;
    case 2:
        for (i = 11; i <= 14; i++)
        {
            if (!func_08001040(i) && limit >= skipped)
                count++;
            else
                skipped++;
        }
        break;
    case 3:
        for (i = 16; i <= 24; i++)
        {
            if (!func_08001040(i) && limit >= skipped)
                count++;
            else
                skipped++;
        }
        break;
    case 4:
        for (i = 26; i <= 29; i++)
        {
            if (!func_08001040(i) && limit >= skipped)
                count++;
            else
                skipped++;
        }
        break;
    }
    return count + limit;
}
