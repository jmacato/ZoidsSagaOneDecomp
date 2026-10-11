#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[0x1E];
    void *tiles;
    u8 pad_24[0x36];
    u16 frame;
    u8 pad_5C[0x2C];
};

struct Frame
{
    u8 pad_0[4];
    const void *tiles;
    u8 pad_8[0x16];
    u16 size;
};

extern struct Sprite D_03004BBC[];
extern const struct Frame D_08318CE4[];

void func_08000C84(u16);

s32 func_08008ABC(void)
{
    u16 i;

    for (i = 0; i <= 0x1D; i++)
    {
        struct Sprite *sprite = &D_03004BBC[i];

        if (sprite->flags & 0x8000)
        {
            if (sprite->flags & 0x4000)
            {
                func_08000C84(i);
            }
            else if (D_08318CE4[sprite->frame].size != 0)
            {
                vu32 *dma = (vu32 *)0x040000D4;

                dma[0] = (u32)D_08318CE4[sprite->frame].tiles;
                dma[1] = (u32)D_03004BBC[i].tiles;
                dma[2] = 0x80000000 | (D_08318CE4[sprite->frame].size >> 1);
                dma[2];
            }
        }
    }
}
