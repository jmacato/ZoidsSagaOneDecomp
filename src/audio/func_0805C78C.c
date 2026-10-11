#include "types.h"

struct CgbChannel
{
    u8 status_flags;
    u8 type;
    u8 right_volume;
    u8 left_volume;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 key;
    u8 envelope_volume;
    u8 envelope_goal;
    u8 envelope_counter;
    u8 pseudo_echo_volume;
    u8 pseudo_echo_length;
    u8 dummy1;
    u8 dummy2;
    u8 gate_time;
    u8 midi_key;
    u8 velocity;
    u8 priority;
    u8 rhythm_pan;
    u8 dummy3[3];
    u8 dummy5;
    u8 sustain_goal;
    u8 n4;
    u8 pan;
    u8 pan_mask;
    u8 modify;
    u8 length;
    u8 sweep;
    u32 frequency;
    u32 *wave_pointer;
    u32 *current_pointer;
    void *track;
    void *prev_channel_pointer;
    void *next_channel_pointer;
    u8 dummy4[8];
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
};

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
    u8 pad_16[0x3A];
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

#define ID_NUMBER 0x68736D53
#define SOUND_INFO_PTR (*(struct SoundInfo **)0x03007FF0)

extern const u8 D_085662E4[];

void func_0805C724(struct CgbChannel *);
void func_0805C6D4(u8);

void func_0805C78C(void)
{
    s32 ch;
    struct CgbChannel *channels;
    s32 ev_add;
    s32 prev_c15;
    struct SoundInfo *sound_info = SOUND_INFO_PTR;
    vu8 *nrx0ptr;
    vu8 *nrx1ptr;
    vu8 *nrx2ptr;
    vu8 *nrx3ptr;
    vu8 *nrx4ptr;
    int mask = 0xff;

    if (sound_info->c15)
        sound_info->c15--;
    else
        sound_info->c15 = 14;

    for (ch = 1, channels = sound_info->cgb_chans; ch <= 4; ch++, channels++)
    {
        if (!(channels->status_flags & 0xC7))
            continue;

        switch (ch)
        {
        case 1:
            nrx0ptr = (vu8 *)0x04000060;
            nrx1ptr = (vu8 *)0x04000062;
            nrx2ptr = (vu8 *)0x04000063;
            nrx3ptr = (vu8 *)0x04000064;
            nrx4ptr = (vu8 *)0x04000065;
            break;
        case 2:
            nrx0ptr = (vu8 *)0x04000061;
            nrx1ptr = (vu8 *)0x04000068;
            nrx2ptr = (vu8 *)0x04000069;
            nrx3ptr = (vu8 *)0x0400006C;
            nrx4ptr = (vu8 *)0x0400006D;
            break;
        case 3:
            nrx0ptr = (vu8 *)0x04000070;
            nrx1ptr = (vu8 *)0x04000072;
            nrx2ptr = (vu8 *)0x04000073;
            nrx3ptr = (vu8 *)0x04000074;
            nrx4ptr = (vu8 *)0x04000075;
            break;
        default:
            nrx0ptr = (vu8 *)0x04000071;
            nrx1ptr = (vu8 *)0x04000078;
            nrx2ptr = (vu8 *)0x04000079;
            nrx3ptr = (vu8 *)0x0400007C;
            nrx4ptr = (vu8 *)0x0400007D;
            break;
        }

        prev_c15 = sound_info->c15;
        ev_add = *nrx2ptr;

        if (channels->status_flags & 0x80)
        {
            if (!(channels->status_flags & 0x40))
            {
                channels->status_flags = 3;
                channels->modify = 3;
                func_0805C724(channels);
                switch (ch)
                {
                case 1:
                    *nrx0ptr = channels->sweep;
                case 2:
                    *nrx1ptr = ((u32)channels->wave_pointer << 6) + channels->length;
                    goto init_env_step_time_dir;
                case 3:
                    if (channels->wave_pointer != channels->current_pointer)
                    {
                        *nrx0ptr = 0x40;
                        *(vu32 *)0x04000090 = channels->wave_pointer[0];
                        *(vu32 *)0x04000094 = channels->wave_pointer[1];
                        *(vu32 *)0x04000098 = channels->wave_pointer[2];
                        *(vu32 *)0x0400009C = channels->wave_pointer[3];
                        channels->current_pointer = channels->wave_pointer;
                    }
                    *nrx0ptr = 0;
                    *nrx1ptr = channels->length;
                    if (channels->length)
                        channels->n4 = 0xC0;
                    else
                        channels->n4 = 0x80;
                    break;
                default:
                    *nrx1ptr = channels->length;
                    *nrx3ptr = (u32)channels->wave_pointer << 3;
                init_env_step_time_dir:
                    ev_add = channels->attack + 8;
                    if (channels->length)
                        channels->n4 = 0x40;
                    else
                        channels->n4 = 0x00;
                    break;
                }
                channels->envelope_counter = channels->attack;
                if ((s8)(channels->attack & mask))
                {
                    channels->envelope_volume = 0;
                    goto envelope_step_complete;
                }
                else
                {
                    goto envelope_decay_start;
                }
            }
            else
            {
                goto oscillator_off;
            }
        }
        else if (channels->status_flags & 4)
        {
            channels->pseudo_echo_length--;
            if ((s8)(channels->pseudo_echo_length & mask) <= 0)
            {
            oscillator_off:
                func_0805C6D4(ch);
                channels->status_flags = 0;
                goto channel_complete;
            }
            goto envelope_complete;
        }
        else if ((channels->status_flags & 0x40) && (channels->status_flags & 3))
        {
            channels->status_flags &= ~3;
            channels->envelope_counter = channels->release;
            if ((s8)(channels->release & mask))
            {
                channels->modify |= 1;
                if (ch != 3)
                    ev_add = channels->release;
                goto envelope_step_complete;
            }
            else
            {
                goto envelope_pseudoecho_start;
            }
        }
        else
        {
        envelope_step_repeat:
            if (channels->envelope_counter == 0)
            {
                if (ch == 3)
                    channels->modify |= 1;

                func_0805C724(channels);
                if ((channels->status_flags & 3) == 0)
                {
                    channels->envelope_volume--;
                    if ((s8)(channels->envelope_volume & mask) <= 0)
                    {
                    envelope_pseudoecho_start:
                        channels->envelope_volume = ((channels->envelope_goal * channels->pseudo_echo_volume) + 0xFF) >> 8;
                        if (channels->envelope_volume)
                        {
                            channels->status_flags |= 4;
                            channels->modify |= 1;
                            if (ch != 3)
                                ev_add = 8;
                            goto envelope_complete;
                        }
                        else
                        {
                            goto oscillator_off;
                        }
                    }
                    else
                    {
                        channels->envelope_counter = channels->release;
                    }
                }
                else if ((channels->status_flags & 3) == 1)
                {
                envelope_sustain:
                    channels->envelope_volume = channels->sustain_goal;
                    channels->envelope_counter = 7;
                }
                else if ((channels->status_flags & 3) == 2)
                {
                    int envelope_volume, sustain_goal;

                    channels->envelope_volume--;
                    envelope_volume = (s8)(channels->envelope_volume & mask);
                    sustain_goal = (s8)(channels->sustain_goal);
                    if (envelope_volume <= sustain_goal)
                    {
                    envelope_sustain_start:
                        if (channels->sustain == 0)
                        {
                            channels->status_flags &= ~3;
                            goto envelope_pseudoecho_start;
                        }
                        else
                        {
                            channels->status_flags--;
                            channels->modify |= 1;
                            if (ch != 3)
                                ev_add = 8;
                            goto envelope_sustain;
                        }
                    }
                    else
                    {
                        channels->envelope_counter = channels->decay;
                    }
                }
                else
                {
                    channels->envelope_volume++;
                    if ((u8)(channels->envelope_volume & mask) >= channels->envelope_goal)
                    {
                    envelope_decay_start:
                        channels->status_flags--;
                        channels->envelope_counter = channels->decay;
                        if ((u8)(channels->envelope_counter & mask))
                        {
                            channels->modify |= 1;
                            channels->envelope_volume = channels->envelope_goal;
                            if (ch != 3)
                                ev_add = channels->decay;
                        }
                        else
                        {
                            goto envelope_sustain_start;
                        }
                    }
                    else
                    {
                        channels->envelope_counter = channels->attack;
                    }
                }
            }
        }

    envelope_step_complete:
        channels->envelope_counter--;
        if (prev_c15 == 0)
        {
            prev_c15--;
            goto envelope_step_repeat;
        }

    envelope_complete:
        if (channels->modify & 2)
        {
            if (ch < 4 && (channels->type & 8))
            {
                int dac_pwm_rate = *(vu8 *)0x04000089;

                if (dac_pwm_rate < 0x40)
                    channels->frequency = (channels->frequency + 2) & 0x7fc;
                else if (dac_pwm_rate < 0x80)
                    channels->frequency = (channels->frequency + 1) & 0x7fe;
            }

            if (ch != 4)
                *nrx3ptr = channels->frequency;
            else
                *nrx3ptr = (*nrx3ptr & 0x08) | channels->frequency;
            channels->n4 = (channels->n4 & 0xC0) + (*((u8 *)(&channels->frequency) + 1));
            *nrx4ptr = (s8)(channels->n4 & mask);
        }

        if (channels->modify & 1)
        {
            *(vu8 *)0x04000081 = (*(vu8 *)0x04000081 & ~channels->pan_mask) | channels->pan;
            if (ch == 3)
            {
                *nrx2ptr = D_085662E4[channels->envelope_volume];
                if (channels->n4 & 0x80)
                {
                    *nrx0ptr = 0x80;
                    *nrx4ptr = channels->n4;
                    channels->n4 &= 0x7f;
                }
            }
            else
            {
                ev_add &= 0xf;
                *nrx2ptr = (channels->envelope_volume << 4) + ev_add;
                *nrx4ptr = channels->n4 | 0x80;
                if (ch == 1 && !(*nrx0ptr & 0x08))
                    *nrx4ptr = channels->n4 | 0x80;
            }
        }

    channel_complete:
        channels->modify = 0;
    }
}

void func_0805CBD8(struct MusicPlayerInfo *info, u16 tempo)
{
    if (info->ident == ID_NUMBER)
    {
        info->ident++;
        info->tempo_u = tempo;
        info->tempo_i = (info->tempo_d * info->tempo_u) >> 8;
        info->ident = ID_NUMBER;
    }
}

void func_0805CBFC(struct MusicPlayerInfo *info, u16 track_bits, u16 volume)
{
    s32 i;
    struct MusicPlayerTrack *track;
    u32 bit;

    if (info->ident != ID_NUMBER)
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
                track->vol_x = volume / 4;
                track->flags |= 3;
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    info->ident = ID_NUMBER;
}

void func_0805CC64(struct MusicPlayerInfo *info, u16 track_bits, s16 pitch)
{
    s32 i;
    struct MusicPlayerTrack *track;
    u32 bit;

    if (info->ident != ID_NUMBER)
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
                track->key_shift_x = (s16)pitch >> 8;
                track->pit_x = pitch;
                track->flags |= 0xC;
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    info->ident = ID_NUMBER;
}

void func_0805CCD8(struct MusicPlayerInfo *info, u16 track_bits, s8 pan)
{
    s32 i;
    struct MusicPlayerTrack *track;
    u32 bit;

    if (info->ident != ID_NUMBER)
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
                track->pan_x = pan;
                track->flags |= 3;
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    info->ident = ID_NUMBER;
}
