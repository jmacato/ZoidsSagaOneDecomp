#include "types.h"

struct Task
{
    u32 flags;
    u8 pad_4[0x84];
};

extern struct Task D_02000034[];
extern const u8 D_08683BAC[];

void func_08003E3C(u8);

void func_0803DFE8(void)
{
    u8 i;

    for (i = 0; i <= 3; i++)
    {
        u8 id = D_08683BAC[i];

        if (D_02000034[id].flags & 2)
            func_08003E3C(id);
    }
}
