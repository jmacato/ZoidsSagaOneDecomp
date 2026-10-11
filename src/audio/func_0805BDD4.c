#include "types.h"

struct MusicPlayerTrack
{
    u8 flags;
    u8 wait;
    u8 pattern_level;
    u8 repN;
    u8 gate_time;
    u8 key;
    u8 velocity;
    u8 running_status;
    u8 key_m;
    u8 pit_m;
    s8 key_shift;
    s8 key_shift_x;
    s8 tune;
    u8 pit_x;
    s8 bend;
    u8 bend_range;
    u8 vol_mr;
    u8 vol_ml;
    u8 vol;
    u8 vol_x;
    s8 pan;
    s8 pan_x;
    s8 mod_m;
    u8 mod;
    u8 mod_t;
    u8 lfo_speed;
    u8 lfo_speed_c;
    u8 lfo_delay;
    u8 lfo_delay_c;
    u8 priority;
    u8 echo_volume;
    u8 echo_length;
    void *chan;
    u8 pad_24[0x2C];
};

struct MusicPlayerInfo
{
    void *song_header;
    u32 status;
    u8 track_count;
    u8 priority;
    u8 cmd;
    u8 unk_B;
    u32 clock;
    u8 gap[8];
    u8 *mem_acc_area;
    u16 tempo_d;
    u16 tempo_u;
    u16 tempo_i;
    u16 tempo_c;
    u16 fade_oi;
    u16 fade_oc;
    u16 fade_ov;
    struct MusicPlayerTrack *tracks;
    void *tone;
    u32 ident;
};

struct MusicPlayer
{
    struct MusicPlayerInfo *info;
    void *track;
    u8 unk_8;
    u8 pad_9;
    u16 unk_A;
};

extern const struct MusicPlayer D_08567594[];
extern u8 D_00000004[];

void func_0805C470(struct MusicPlayerInfo *);
void func_0805BBE0(struct MusicPlayerInfo *);
void func_0805BBFC(struct MusicPlayerInfo *, u16);
void func_0805C008(void *);

void func_0805BDD4(void)
{
    s32 i;

    for (i = 0; i < (u16)(u32)D_00000004; i++)
        func_0805C470(D_08567594[i].info);
}

void func_0805BDFC(struct MusicPlayerInfo *info)
{
    func_0805BBE0(info);
}

void func_0805BE08(void)
{
    s32 i;

    for (i = 0; i < (u16)(u32)D_00000004; i++)
        func_0805BBE0(D_08567594[i].info);
}

void func_0805BE30(struct MusicPlayerInfo *info, u16 speed)
{
    func_0805BBFC(info, speed);
}

void func_0805BE40(struct MusicPlayerInfo *info, u16 speed)
{
    if (info->ident == 0x68736D53)
    {
        info->ident++;
        info->fade_oc = speed;
        info->fade_oi = speed;
        info->fade_ov = 0x101;
        info->ident = 0x68736D53;
    }
}

void func_0805BE60(struct MusicPlayerInfo *info, u16 speed)
{
    if (info->ident == 0x68736D53)
    {
        info->ident++;
        info->fade_oc = speed;
        info->fade_oi = speed;
        info->fade_ov = 2;
        info->status &= ~0x80000000;
        info->ident = 0x68736D53;
    }
}

void func_0805BE88(struct MusicPlayerInfo *info)
{
    s32 track_count = info->track_count;
    struct MusicPlayerTrack *track = info->tracks;

    while (track_count > 0)
    {
        if (track->flags & 0x80)
        {
            if (track->flags & 0x40)
            {
                func_0805C008(track);
                track->flags = 0x80;
                track->bend_range = 2;
                track->vol_x = 64;
                track->lfo_speed = 22;
                *((u8 *)track + 0x24) = 1;
            }
        }

        track_count--;
        track++;
    }
}
