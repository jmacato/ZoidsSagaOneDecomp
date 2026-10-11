#include "types.h"

struct MusicPlayerInfo
{
    u32 song_header;
    u32 status;
    u8 pad_8[3];
    u8 unk_B;
    u8 pad_C[0xC];
    u32 mem_acc_area;
};

struct MusicPlayer
{
    struct MusicPlayerInfo *info;
    void *track;
    u8 unk_8;
    u8 pad_9;
    u16 unk_A;
};

struct Song
{
    u32 header;
    u16 ms;
    u16 me;
};

extern const struct MusicPlayer D_08567594[];
extern const struct Song D_085675C4[];

void func_0805C38C(struct MusicPlayerInfo *, u32);

void func_0805BCA0(u16 n)
{
    const struct MusicPlayer *mplay_table = D_08567594;
    const struct Song *song_table = D_085675C4;
    const struct Song *song = &song_table[n];
    const struct MusicPlayer *mplay = &mplay_table[song->ms];

    func_0805C38C(mplay->info, song->header);
}

void func_0805BCD4(u16 n)
{
    const struct MusicPlayer *mplay_table = D_08567594;
    const struct Song *song_table = D_085675C4;
    const struct Song *song = &song_table[n];
    const struct MusicPlayer *mplay = &mplay_table[song->ms];
    struct MusicPlayerInfo *info = mplay->info;

    if (info->song_header != song->header)
    {
        func_0805C38C(info, song->header);
    }
    else
    {
        if ((info->status & 0xFFFF) == 0 || (info->status & 0x80000000))
            func_0805C38C(info, song->header);
    }
}
