#include "types.h"

struct MusicPlayerInfo
{
    u32 song_header;
};

struct MusicPlayer
{
    struct MusicPlayerInfo *info;
    u8 pad_4[8];
};

struct Song
{
    u32 header;
    u16 ms;
    u16 me;
};

extern const struct MusicPlayer D_08567594[];
extern const struct Song D_085675C4[];

void func_0805C470(struct MusicPlayerInfo *);

void func_0805BD6C(u16 n)
{
    const struct MusicPlayer *mplay_table = D_08567594;
    const struct Song *song_table = D_085675C4;
    const struct Song *song = &song_table[n];
    const struct MusicPlayer *mplay = &mplay_table[song->ms];
    struct MusicPlayerInfo *info = mplay->info;

    if (info->song_header == song->header)
        func_0805C470(info);
}
