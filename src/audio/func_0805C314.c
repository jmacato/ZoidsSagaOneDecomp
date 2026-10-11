#include "audio/m4a.h"

void func_0805C008(struct MusicPlayerInfo *);
void func_0805B60C(void);

void func_0805C314(struct MusicPlayerInfo *player, struct MusicPlayerTrack *tracks, u8 track_count)
{
    struct SoundInfo *sound;

    if (track_count == 0)
        return;
    if (track_count > 16)
        track_count = 16;
    sound = SOUND_INFO_PTR;
    if (sound->ident != ID_NUMBER)
        return;
    sound->ident++;
    func_0805C008(player);
    player->tracks = tracks;
    player->track_count = track_count;
    player->status = 0x80000000;
    while (track_count != 0)
    {
        tracks->flags = 0;
        track_count--;
        tracks++;
    }
    if (sound->main_head != 0)
    {
        player->func = sound->main_head;
        player->intp = sound->intp;
        sound->main_head = 0;
    }
    sound->intp = (u32)player;
    sound->main_head = (u32)func_0805B60C;
    sound->ident = ID_NUMBER;
    player->ident = ID_NUMBER;
}
