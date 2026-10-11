#include "types.h"

struct Pair
{
    u32 first;
    u32 second;
};

u16 func_08001080(void);
u16 func_0805D4FC(u16, u16);

void func_0803262C(s32 count, struct Pair *pairs)
{
    s32 i;

    for (i = 0; i < count; i++)
    {
        s32 j = func_08001080() % (u16)count;
        struct Pair temp;

        if (j >= count)
            j = 0;
        temp = pairs[j];
        pairs[j] = pairs[i];
        pairs[i] = temp;
    }
}
