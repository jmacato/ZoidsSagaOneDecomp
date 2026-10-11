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

void func_0805B874(struct MusicPlayerInfo *, struct MusicPlayerTrack *);

void func_0805C4B0(struct MusicPlayerInfo *info)
{
    s32 i;
    struct MusicPlayerTrack *track;
    u16 fade_oi = info->fade_oi;
    register u32 temp asm("r3");
    register u16 mask asm("r2");
    register u32 fade_ov asm("r7");

    if (fade_oi == 0)
        return;

    info->fade_oc--;

    temp = 0xFFFF;
    mask = temp;

    if (info->fade_oc != 0)
        return;

    info->fade_oc = fade_oi;

    if (info->fade_ov & 2)
    {
        info->fade_ov += 0x10;

        if ((u16)(info->fade_ov & mask) >= 0x100)
        {
            info->fade_ov = 0x100;
            info->fade_oi = 0;
        }
    }
    else
    {
        info->fade_ov -= 0x10;

        if ((s16)(info->fade_ov & mask) <= 0)
        {
            i = info->track_count;
            track = info->tracks;

            while (i > 0)
            {
                u32 val;

                func_0805B874(info, track);

                val = 1;
                fade_ov = info->fade_ov;
                val &= fade_ov;

                if (!val)
                    track->flags = 0;

                i--;
                track++;
            }

            if (info->fade_ov & 1)
                info->status |= 0x80000000;
            else
                info->status = 0x80000000;

            info->fade_oi = 0;
            return;
        }
    }

    i = info->track_count;
    track = info->tracks;

    while (i > 0)
    {
        if (track->flags & 0x80)
        {
            fade_ov = info->fade_ov;
            track->vol_x = fade_ov >> 2;
            track->flags |= 3;
        }

        i--;
        track++;
    }
}
