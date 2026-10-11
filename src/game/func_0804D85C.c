#include "types.h"

struct Task
{
    u32 object;
    u8 pad_4[0x84];
};

struct Object
{
    u16 flags;
    u8 pad_2[0x86];
};

extern struct Task D_0200003C[];
extern u8 D_02000030;
extern struct Object D_03004BBC[];

void func_0805EE78(s32);

void func_0804D85C(void)
{
    u8 timer = 0;

    while (1)
    {
        if (!(timer & 15))
            D_03004BBC[D_0200003C[D_02000030].object + 2].flags ^= 0x8000;
        timer++;
        func_0805EE78(1);
    }
}
