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

void func_0805C578(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    if (track->flags & 1)
    {
        s32 x;
        s32 y;

        x = (u32)(track->vol * track->vol_x) >> 5;

        if (track->mod_t == 1)
            x = (u32)(x * (track->mod_m + 128)) >> 7;

        y = 2 * track->pan + track->pan_x;

        if (track->mod_t == 2)
            y += track->mod_m;

        if (y < -128)
            y = -128;
        else if (y > 127)
            y = 127;

        track->vol_mr = (u32)((y + 128) * x) >> 8;
        track->vol_ml = (u32)((127 - y) * x) >> 8;
    }

    if (track->flags & 4)
    {
        s32 bend = track->bend * track->bend_range;
        s32 x = (track->tune + bend) * 4 + (track->key_shift << 8) + (track->key_shift_x << 8) + track->pit_x;

        if (track->mod_t == 0)
            x += 16 * track->mod_m;

        track->key_m = x >> 8;
        track->pit_m = x;
    }

    track->flags &= ~5;
}
