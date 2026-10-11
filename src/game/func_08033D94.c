#include "types.h"

extern u16 D_020143BC[];

u16 func_08001080(void);
u16 func_0805D4FC(u16, u16);

void func_08033D94(u16 range)
{
    u8 i;

    for (i = 0; i <= 15; i++)
        D_020143BC[i] = func_08001080() % range;
}
