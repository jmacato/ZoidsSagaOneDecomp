#include "m2c.h"

s32 func_080395E8(s32, void *);

void func_080395D0(void *arg0, s32 *arg1)
{
    *arg1 = func_080395E8((s32) M2C_FIELD(arg0, s32 *, 0x28) >> 1, arg0);
}
