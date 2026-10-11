#include "types.h"

struct MusicPlayerInfo
{
    u8 pad_0[0x24];
    u16 fade_oi;
    u16 fade_oc;
    u16 fade_ov;
    u8 pad_2A[0xA];
    u32 ident;
};

void func_0805BBFC(struct MusicPlayerInfo *info, u16 speed)
{
    if (info->ident == 0x68736D53)
    {
        info->ident++;
        info->fade_oc = speed;
        info->fade_oi = speed;
        info->fade_ov = 0x100;
        info->ident = 0x68736D53;
    }
}
