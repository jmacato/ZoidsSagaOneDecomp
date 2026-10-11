#include "types.h"

struct Header
{
    u32 type:8;
    u32 size:24;
};

u32 func_08034BF8(const u8 *src, u32 size, u8 *dst)
{
    u32 out = 4;
    u32 pos;
    u32 start;
    s32 run;
    s32 length;
    u8 count;
    s32 i;
    u8 value;

    ((struct Header *)dst)->type = 0x30;
    ((struct Header *)dst)->size = size;
    for (pos = 0; pos < size - 1;)
    {
        start = pos;
        run = 1;
        while (pos < size - 1)
        {
            if (src[pos] == src[pos + 1])
                run++;
            else
            {
                if (run > 2)
                    break;
                run = 1;
            }
            pos++;
        }
        pos++;
        if (run <= 2)
            run = 0;
        length = pos - run - start;
        while (length > 0)
        {
            count = length > 0x80 ? 0x80 : length;
            length -= count;
            count--;
            dst[out++] = count;
            for (i = 0; i <= count; i++)
                dst[out++] = src[start++];
        }
        if (run > 0)
        {
            value = src[pos - run];
            length = run;
            while (length > 2)
            {
                count = length > 0x82 ? 0x82 : length;
                length -= count;
                count -= 3;
                dst[out++] = count | 0x80;
                dst[out++] = value;
            }
            pos -= length;
        }
    }
    while (out & 3)
        dst[out++] = 0;
    return out;
}
