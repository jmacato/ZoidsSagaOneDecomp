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

extern void *D_03006F80[];
extern u8 D_00000000[];

void func_0805D270(const void *, void *, u32);
void func_0805CE4C(void);
void func_0805BB50(void);
void func_0805BB64(void);
void func_0805CFA4(void);
void func_0805BAE8(void);
void func_0805C0E8(void);
void func_0805B874(void);
void func_0805C4B0(void);
void func_0805C578(void);
void func_0805C78C(void);
void func_0805C6D4(u8);
u32 func_0805C62C(u8, u8, u8);

struct CgbChannelFull
{
    u8 status_flags;
    u8 type;
    u8 pad_2[0x1A];
    u8 pan_mask;
    u8 pad_1D[0x23];
};

void func_0805BED8(struct CgbChannelFull *cgb_chans)
{
    struct SoundInfo *info;
    u32 ident;
    vu32 zero;

    *(vu16 *)0x04000084 = 0x8F;
    *(vu16 *)0x04000080 = 0;
    *(vu8 *)0x04000063 = 8;
    *(vu8 *)0x04000069 = 8;
    *(vu8 *)0x04000079 = 8;
    *(vu8 *)0x04000065 = 0x80;
    *(vu8 *)0x0400006D = 0x80;
    *(vu8 *)0x0400007D = 0x80;
    *(vu8 *)0x04000070 = 0;
    *(vu8 *)0x04000080 = 0x77;

    info = SOUND_INFO_PTR;
    ident = info->ident;

    if (ident != ID_NUMBER)
        return;

    info->ident = ident + 1;

    D_03006F80[8] = func_0805CE4C;
    D_03006F80[17] = func_0805BB50;
    D_03006F80[19] = func_0805BB64;
    D_03006F80[28] = func_0805CFA4;
    D_03006F80[29] = func_0805BAE8;
    D_03006F80[30] = func_0805C0E8;
    D_03006F80[31] = func_0805B874;
    D_03006F80[32] = func_0805C4B0;
    D_03006F80[33] = func_0805C578;

    info->cgb_chans = (struct CgbChannel *)cgb_chans;
    info->cgb_sound = func_0805C78C;
    info->cgb_osc_off = func_0805C6D4;
    info->midi_key_to_cgb_freq = func_0805C62C;
    info->max_lines = (u32)D_00000000;

    zero = 0;
    func_0805D270((void *)&zero, cgb_chans, 0x05000040);

    cgb_chans[0].type = 1;
    cgb_chans[0].pan_mask = 0x11;
    cgb_chans[1].type = 2;
    cgb_chans[1].pan_mask = 0x22;
    cgb_chans[2].type = 3;
    cgb_chans[2].pan_mask = 0x44;
    cgb_chans[3].type = 4;
    cgb_chans[3].pan_mask = 0x88;

    info->ident = ident;
}
