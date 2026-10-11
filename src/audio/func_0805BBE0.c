#include "types.h"

struct MusicPlayerInfo
{
    u8 pad_0[4];
    u32 status;
    u8 pad_8[0x2C];
    u32 ident;
};

void func_0805BBE0(struct MusicPlayerInfo *info)
{
    if (info->ident == 0x68736D53)
    {
        info->ident++;
        info->status &= ~0x80000000;
        info->ident = 0x68736D53;
    }
}
