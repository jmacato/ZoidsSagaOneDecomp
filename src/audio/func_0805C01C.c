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
    u8 pad_8[0x14];
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

extern u8 D_03006F80[];

void func_0805D270(const void *, void *, u32);
void func_0805B8E8(void);
void func_0805D0C4(void);
void func_0805B40C(void *);
void func_0805C0E8(u32);

void func_0805C01C(struct SoundInfo *info)
{
    vu32 zero;

    info->ident = 0;
    if (*(vu32 *)0x040000C4 & (0x200 << 16))
        *(vu32 *)0x040000C4 = 0x84400004;
    *(vu16 *)0x040000C6 = 0x400;
    *(vu16 *)0x04000084 = 0x8F;
    *(vu16 *)0x04000082 = 0xB0E;
    *(vu8 *)0x04000089 = (*(vu8 *)0x04000089 & 0x3F) | 0x40;
    *(vu32 *)0x040000BC = (s32)info->pcm_buffer;
    *(vu32 *)0x040000C0 = 0x040000A0;
    SOUND_INFO_PTR = info;
    zero = 0;
    func_0805D270((void *)&zero, info, 0x05000260);
    info->max_chans = 8;
    info->master_volume = 15;
    info->plynote = (u32)func_0805B8E8;
    info->cgb_sound = func_0805D0C4;
    info->cgb_osc_off = (void (*)(u8))func_0805D0C4;
    info->midi_key_to_cgb_freq = (u32 (*)(u8, u8, u8))func_0805D0C4;
    info->ext_vol_pit = (u32)func_0805D0C4;
    func_0805B40C(D_03006F80);
    info->mplay_jump_table = (u32)D_03006F80;
    func_0805C0E8(0x40000);
    info->ident = ID_NUMBER;
}
