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

extern const XcmdFunc D_08566328[];

void func_0805CFA4(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    u32 n = *track->cmd_ptr;

    track->cmd_ptr++;
    D_08566328[n](info, track);
}
