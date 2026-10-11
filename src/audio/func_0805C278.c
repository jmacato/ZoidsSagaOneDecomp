#include "types.h"

#define ID_NUMBER 0x68736D53
#define SOUND_INFO_PTR (*(struct SoundInfo **)0x03007FF0)

struct SoundChannel
{
    u8 status_flags;
    u8 pad_1[0x3F];
};

struct CgbChannel
{
    u8 status_flags;
    u8 pad_1[0x3F];
};

struct SoundInfo
{
    u32 ident;
    vu8 pcm_dma_counter;
    u8 reverb;
    u8 max_chans;
    u8 master_volume;
    u8 freq;
    u8 mode;
    u8 c15;
    u8 pcm_dma_period;
    u8 max_lines;
    u8 gap[3];
    s32 pcm_samples_per_vblank;
    s32 pcm_freq;
    s32 div_freq;
    struct CgbChannel *cgb_chans;
    u8 pad_20[8];
    void (*cgb_sound)(void);
    void (*cgb_osc_off)(u8);
    u32 (*midi_key_to_cgb_freq)(u8, u8, u8);
    u32 mplay_jump_table;
    u32 plynote;
    u32 ext_vol_pit;
    u8 pad_40[0x10];
    struct SoundChannel chans[12];
    u8 pcm_buffer[0x630];
};

void func_0805D270(const void *, void *, u32);

void func_0805C278(void)
{
    struct SoundInfo *info = SOUND_INFO_PTR;

    if (info->ident >= ID_NUMBER && info->ident <= ID_NUMBER + 1)
    {
        vu32 zero;

        info->ident += 10;
        if (*(vu32 *)0x040000C4 & (0x200 << 16))
            *(vu32 *)0x040000C4 = 0x84400004;
        *(vu16 *)0x040000C6 = 0x400;
        zero = 0;
        func_0805D270((void *)&zero, info->pcm_buffer, 0x0500018C);
    }
}
