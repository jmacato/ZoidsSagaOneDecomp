#include "types.h"

struct Transfer
{
    void *source;
    void *destination;
    u16 size;
};

extern u8 D_0200DAA0;
extern u32 D_0200DAAC[];
extern u32 D_0200DFAC[];
extern u32 D_0200DD2C[];
extern u8 D_086F6A18[];
extern u8 D_086F6790[];
extern u8 D_0842B670[];
extern u8 D_03003B9C[];

void func_08001A54(void *, u16, s32);

void func_08043C50(u16 tile)
{
    struct Transfer transfer;
    u8 i;

    D_0200DAA0 = tile;
    for (i = 0; i < 0x80; i++)
    {
        D_0200DAAC[i] = 0;
        D_0200DFAC[i] = 0;
        D_0200DD2C[i] = 0;
    }
    func_08001A54(D_086F6A18, tile, 1);
    func_08001A54(D_086F6790, tile, 1);
    transfer.source = D_0842B670;
    transfer.destination = D_03003B9C;
    transfer.size = 0x400;
    func_08001A54(&transfer, 0, 0);
}
