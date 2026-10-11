#include "types.h"

struct Zoid
{
    u8 pad_0[2];
    u16 flags;
    u8 pad_4[0x34];
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[180];
} D_02000B5C;

u8 func_08032B18(void)
{
    u8 i;

    for (i = 0;; i++)
    {
        if ((D_02000B5C.zoids[i].flags & 1) && !(D_02000B5C.zoids[i].flags & 2))
            return i;
    }
}
