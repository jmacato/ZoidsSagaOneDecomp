#include "types.h"

extern u8 D_030022E8[];
extern u8 D_0200758C[];

void func_0804BDA0(void)
{
    u16 i;

    for (i = 0; i <= 15; i++)
        D_030022E8[i] = D_0200758C[i];
}
