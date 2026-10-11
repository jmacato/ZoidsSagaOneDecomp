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

extern const u16 D_085661F4[];

void func_0805C2DC(void);

void func_0805C0E8(u32 freq)
{
    struct SoundInfo *info = SOUND_INFO_PTR;

    freq = (freq & 0xF0000) >> 16;
    info->freq = freq;
    info->pcm_samples_per_vblank = D_085661F4[freq - 1];
    info->pcm_dma_period = 0x630 / info->pcm_samples_per_vblank;
    info->pcm_freq = (597275 * info->pcm_samples_per_vblank + 5000) / 10000;
    info->div_freq = (16777216 / info->pcm_freq + 1) >> 1;
    *(vu16 *)0x04000102 = 0;
    *(vu16 *)0x04000100 = -(280896 / info->pcm_samples_per_vblank);
    func_0805C2DC();
    while (*(vu8 *)0x04000006 == 159)
        ;
    while (*(vu8 *)0x04000006 != 159)
        ;
    *(vu16 *)0x04000102 = 0x80;
}
