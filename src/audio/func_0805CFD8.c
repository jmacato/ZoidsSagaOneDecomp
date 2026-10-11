#include "types.h"

struct ToneData
{
    u8 type;
    u8 key;
    u8 length;
    u8 pan_sweep;
    void *wav;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
};

struct MusicPlayerTrack
{
    u8 flags;
    u8 pad_1[0x1D];
    u8 echo_volume;
    u8 echo_length;
    void *chan;
    struct ToneData tone;
    u8 gap[0x10];
    u8 *cmd_ptr;
    u8 pad_44[0xC];
};

struct MusicPlayerInfo
{
    u8 pad_0[0x18];
    u8 *mem_acc_area;
};

typedef void (*XcmdFunc)(struct MusicPlayerInfo *, struct MusicPlayerTrack *);

#define READ_XCMD_BYTE(var, n)          \
    {                                   \
        u32 byte = track->cmd_ptr[(n)]; \
        byte <<= n * 8;                 \
        (var) &= ~(0xFF << (n * 8));    \
        (var) |= byte;                  \
    }

void func_0805CFD8(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    u32 wav;

    READ_XCMD_BYTE(wav, 0)
    READ_XCMD_BYTE(wav, 1)
    READ_XCMD_BYTE(wav, 2)
    READ_XCMD_BYTE(wav, 3)

    track->tone.wav = (void *)wav;
    track->cmd_ptr += 4;
}

void func_0805D014(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    track->tone.type = *track->cmd_ptr;
    track->cmd_ptr++;
}

void func_0805D028(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    track->tone.attack = *track->cmd_ptr;
    track->cmd_ptr++;
}

void func_0805D03C(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    track->tone.decay = *track->cmd_ptr;
    track->cmd_ptr++;
}

void func_0805D050(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    track->tone.sustain = *track->cmd_ptr;
    track->cmd_ptr++;
}

void func_0805D064(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    track->tone.release = *track->cmd_ptr;
    track->cmd_ptr++;
}

void func_0805D078(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    track->echo_volume = *track->cmd_ptr;
    track->cmd_ptr++;
}

void func_0805D088(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    track->echo_length = *track->cmd_ptr;
    track->cmd_ptr++;
}

void func_0805D098(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    track->tone.length = *track->cmd_ptr;
    track->cmd_ptr++;
}

void func_0805D0AC(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    track->tone.pan_sweep = *track->cmd_ptr;
    track->cmd_ptr++;
}
