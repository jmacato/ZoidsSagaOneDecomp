#include "audio/m4a.h"

void func_0805B874(struct MusicPlayerInfo *, struct MusicPlayerTrack *);

void func_0805C470(struct MusicPlayerInfo *player)
{
    s32 i;
    struct MusicPlayerTrack *track;

    if (player->ident != ID_NUMBER)
        return;
    player->ident++;
    player->status |= 0x80000000;
    i = player->track_count;
    track = player->tracks;
    while (i > 0)
    {
        func_0805B874(player, track);
        i--;
        track++;
    }
    player->ident = ID_NUMBER;
}
