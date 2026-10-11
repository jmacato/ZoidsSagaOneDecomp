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

extern struct Graphic D_0866B7F8[];

void func_08001A54(struct Transfer *, s32, s32);
void func_0805D270(void *, void *, u32);

void func_08032208(u8 id, u16 tile, u8 palette)
{
    struct Transfer transfer;

    transfer.source = D_0866B7F8[id].tiles;
    transfer.destination = (void *)(0x06010000 + tile * 32);
    func_08001A54(&transfer, 0, 1);
    func_0805D270(D_0866B7F8[id].palette, (void *)(0x05000200 + palette * 32), 16);
}
