#include "types.h"

extern void *D_03000204;
extern u16 D_03002356;

void func_0801D924(void);
void func_0805EE78(s32);

void func_0801D93C(void)
{
    u32 i;

    D_03000204 = func_0801D924;
    i = 0;
    do
    {
        i++;
        D_03002356 = i;
        func_0805EE78(2);
    } while (i <= 15);
}
