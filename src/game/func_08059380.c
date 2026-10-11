#include "types.h"

union Result
{
    u32 raw;
    struct
    {
        u32 done:1;
        u32 pad:3;
        u32 extra:1;
    } bits;
};

extern u8 D_0200E8A4[];
extern u8 D_0875BE30[];

void func_08005E74(void);
u32 func_08005E90(s32, u8 *, s32, s32, u8 *);
void func_0805EE78(s32);

u8 func_08059380(u8 slot)
{
    u32 result;

    func_08005E74();
    while ((result = func_08005E90(0, D_0875BE30, slot, -1, D_0200E8A4)) == 0)
        func_0805EE78(1);
    return ((union Result *)&result)->bits.done | (((union Result *)&result)->bits.extra << 1);
}
