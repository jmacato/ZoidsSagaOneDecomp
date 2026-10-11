#include "types.h"

extern struct
{
    u32 x;
    u32 y;
} D_03004C4C;

void func_0805EE78(s32);
void func_08016CA8(s32, s32, s32);

void func_0801D558(void)
{
    u32 *x = &D_03004C4C.x;
    u32 *y = &D_03004C4C.y;

    while (1)
    {
        func_0805EE78(8);
        func_08016CA8(4, (*x >> 21) + 2, (*y >> 21) - 2);
        func_0805EE78(8);
        func_08016CA8(4, (*x >> 21) - 1, (*y >> 21) - 2);
    }
}
