#include "types.h"

struct Zoid
{
    u8 pad_0[2];
    u16 id;
    u8 pad_4[0x34];
};

extern struct
{
    u8 pad_0[0xD30];
    struct Zoid zoids[0xAD];
} D_02000B5C;

s32 func_0802AACC(u16 id)
{
    u16 i;

    for (i = 0; i <= 0xAC; i++)
    {
        if (D_02000B5C.zoids[i].id == id)
            return 1;
    }
    return 0;
}
