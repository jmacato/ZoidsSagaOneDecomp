#include "types.h"

#define ID_NUMBER 0x68736D53

struct SongHeader
{
    u8 track_count;
    u8 block_count;
    u8 priority;
    u8 reverb;
    void *tone;
    u8 *part[1];
};

struct MusicPlayerTrack
{
    u8 flags;
    u8 pad_1[0x1F];
    void *chan;
    u8 pad_24[0x1C];
    u8 *cmd_ptr;
    u8 pad_44[0xC];
};

struct MusicPlayerInfo
{
    struct SongHeader *song_header;
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
    u32 func;
    u32 intp;
};

void func_0805B874(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void func_0805C18C(u32);

void func_0805C38C(struct MusicPlayerInfo *info, struct SongHeader *header)
{
    s32 i;
    u8 unk_B;
    struct MusicPlayerTrack *track;

    if (info->ident != ID_NUMBER)
        return;

    unk_B = info->unk_B;

    if (!unk_B
        || ((!info->song_header || !(info->tracks[0].flags & 0x40))
            && ((info->status & 0xFFFF) == 0 || (info->status & 0x80000000)))
        || (info->priority <= header->priority))
    {
        info->ident++;
        info->status = 0;
        info->song_header = header;
        info->tone = header->tone;
        info->priority = header->priority;
        info->clock = 0;
        info->tempo_d = 150;
        info->tempo_i = 150;
        info->tempo_u = 0x100;
        info->tempo_c = 0;
        info->fade_oi = 0;

        i = 0;
        track = info->tracks;

        while (i < header->track_count && i < info->track_count)
        {
            func_0805B874(info, track);
            track->flags = 0xC0;
            track->chan = 0;
            track->cmd_ptr = header->part[i];
            i++;
            track++;
        }

        while (i < info->track_count)
        {
            func_0805B874(info, track);
            track->flags = 0;
            i++;
            track++;
        }

        if (header->reverb & 0x80)
            func_0805C18C(header->reverb);

        info->ident = ID_NUMBER;
    }
}
