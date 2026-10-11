#include "types.h"

struct Track
{
    u8 pad_0[4];
    s32 status;
};

struct Player
{
    struct Track *track;
    u8 pad_4[8];
};

struct Song
{
    u8 pad_0[4];
    u16 player;
    u8 pad_6[2];
};

extern struct Player D_08567594[];
extern struct Song D_085675C4[];

u8 func_08001A28(u16 song)
{
    if (D_08567594[D_085675C4[song].player].track->status < 0)
        return 1;
    return 0;
}
