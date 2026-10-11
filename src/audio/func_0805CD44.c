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

void func_0805CD44(struct MusicPlayerTrack *track)
{
    track->lfo_speed_c = 0;
    track->mod_m = 0;

    if (track->mod_t == 0)
        track->flags |= 0xC;
    else
        track->flags |= 3;
}

void func_0805CD64(struct MusicPlayerInfo *info, u16 track_bits, u8 mod_depth)
{
    s32 i;
    struct MusicPlayerTrack *track;
    u32 bit;

    if (info->ident != 0x68736D53)
        return;

    info->ident++;

    i = info->track_count;
    track = info->tracks;
    bit = 1;

    while (i > 0)
    {
        if (track_bits & bit)
        {
            if (track->flags & 0x80)
            {
                track->mod = mod_depth;

                if (!track->mod)
                    func_0805CD44(track);
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    info->ident = 0x68736D53;
}

void func_0805CDD8(struct MusicPlayerInfo *info, u16 track_bits, u8 lfo_speed)
{
    s32 i;
    struct MusicPlayerTrack *track;
    u32 bit;

    if (info->ident != 0x68736D53)
        return;

    info->ident++;

    i = info->track_count;
    track = info->tracks;
    bit = 1;

    while (i > 0)
    {
        if (track_bits & bit)
        {
            if (track->flags & 0x80)
            {
                track->lfo_speed = lfo_speed;

                if (!track->lfo_speed)
                    func_0805CD44(track);
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    info->ident = 0x68736D53;
}
