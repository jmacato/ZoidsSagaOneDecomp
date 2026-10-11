#include "types.h"

struct Graphic
{
    void *tiles;
    void *palette;
    u8 pad_8[8];
};

struct Transfer
{
    void *source;
    void *destination;
    u32 size;
};

extern struct Graphic D_086F7FD0[];

void func_08001A54(struct Transfer *, s32, s32);

void func_080321AC(u8 id, u16 tile, u8 palette)
{
    struct Transfer transfer;

    transfer.source = D_086F7FD0[id].tiles;
    transfer.destination = (void *)(0x06010000 + tile * 32);
    func_08001A54(&transfer, 0, 1);
    transfer.source = D_086F7FD0[id].palette;
    transfer.destination = (void *)(0x05000200 + palette * 32);
    func_08001A54(&transfer, 0, 1);
}
