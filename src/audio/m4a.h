#ifndef ZOIDS_SAGA_M4A_H
#define ZOIDS_SAGA_M4A_H

#include "types.h"

#define ID_NUMBER 0x68736D53
#define SOUND_INFO_PTR (*(struct SoundInfo **)0x03007FF0)

struct SoundInfo
{
    u32 ident;
    u8 pad_4[0x1C];
    u32 main_head;
    u32 intp;
};

struct MusicPlayerTrack
{
    u8 flags;
    u8 pad_1[0x4F];
};

struct MusicPlayerInfo
{
    u8 pad_0[4];
    u32 status;
    u8 track_count;
    u8 pad_9[0x23];
    struct MusicPlayerTrack *tracks;
    u8 pad_30[4];
    u32 ident;
    u32 func;
    u32 intp;
};

#endif
