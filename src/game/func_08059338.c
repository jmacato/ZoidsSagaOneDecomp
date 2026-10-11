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
extern u8 D_0875BE38[];

void func_08005E74(void);
u32 func_08005E90(s32, u8 *, s32, s32, u8 *);
void func_0805EE78(s32);

u8 func_08059338(void)
{
    u8 i;
    union Result result;

    func_08005E74();
    for (i = 0; i <= 1; i++)
    {
        while ((result.raw = func_08005E90(1, D_0875BE38, i, -1, D_0200E8A4)) == 0)
            func_0805EE78(1);
    }
    return result.bits.done;
}
