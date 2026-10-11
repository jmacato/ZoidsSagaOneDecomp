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

void func_0805C278(void);
void func_0805C0E8(u32);

void func_0805C18C(u32 mode)
{
    struct SoundInfo *info = SOUND_INFO_PTR;
    u32 temp;

    if (info->ident != ID_NUMBER)
        return;

    info->ident++;

    temp = mode & 0xFF;
    if (temp)
        info->reverb = temp & 0x7F;

    temp = mode & 0xF00;
    if (temp)
    {
        struct SoundChannel *chan;

        info->max_chans = temp >> 8;
        temp = 12;
        chan = &info->chans[0];
        while (temp != 0)
        {
            chan->status_flags = 0;
            temp--;
            chan++;
        }
    }

    temp = mode & 0xF000;
    if (temp)
        info->master_volume = temp >> 12;

    temp = mode & 0xB00000;
    if (temp)
    {
        temp = (temp & 0x300000) >> 14;
        *(vu8 *)0x04000089 = (*(vu8 *)0x04000089 & 0x3F) | temp;
    }

    temp = mode & 0xF0000;
    if (temp)
    {
        func_0805C278();
        func_0805C0E8(temp);
    }

    info->ident = ID_NUMBER;
}

void func_0805C218(void)
{
    struct SoundInfo *info = SOUND_INFO_PTR;
    s32 i;
    void *chan;

    if (info->ident != ID_NUMBER)
        return;

    info->ident++;

    i = 12;
    chan = &info->chans[0];
    while (i > 0)
    {
        ((struct SoundChannel *)chan)->status_flags = 0;
        i--;
        chan = (void *)((s32)chan + sizeof(struct SoundChannel));
    }

    chan = info->cgb_chans;
    if (chan)
    {
        i = 1;
        while (i <= 4)
        {
            info->cgb_osc_off(i);
            ((struct CgbChannel *)chan)->status_flags = 0;
            i++;
            chan = (void *)((s32)chan + sizeof(struct CgbChannel));
        }
    }

    info->ident = ID_NUMBER;
}
