#include "types.h"

struct SoundInfo
{
    u32 ident;
    vu8 pcm_dma_counter;
};

void func_0805C2DC(void)
{
    struct SoundInfo *info = *(struct SoundInfo **)0x03007FF0;
    u32 ident = info->ident;

    if (ident == 0x68736D53)
        return;
    *(vu16 *)0x040000C6 = 0xB600;
    info->pcm_dma_counter = 0;
    info->ident = ident - 10;
}
