#include "types.h"

extern struct
{
    u8 pad_0[0x228];
    s32 result;
} D_02000034;

void func_08003DF8(s32, void *);
void func_0804E4F8(void);
void func_0805EE78(s32);
void func_08003E3C(s32);

s32 region_0804E4A8(void)
{
    s32 result;

    func_08003DF8(4, func_0804E4F8);
    D_02000034.result = 0;
    while (D_02000034.result == 0)
        func_0805EE78(1);
    func_08003E3C(4);
    result = 0;
    if (D_02000034.result == -2)
        result = 1;
    return result;
}
