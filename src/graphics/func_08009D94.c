#include "graphics/sprites.h"

struct SpriteDefinition
{
    const u16 *palette;
    const u8 *graphics;
    const u16 **animations;
    const SpritePiece **frames;
    u8 unknown10[0xA];
    u16 offset_x;
    u16 offset_y;
    u16 graphics_bytes;
};

extern const struct SpriteDefinition D_08318CE4[];
extern Sprite D_03004BBC[];

u32 func_08009D94(u16 sprite, u16 index, u16 animation)
{
    vu32 *dma = (vu32 *)0x040000D4;

    dma[0] = (u32)D_08318CE4[index].palette;
    dma[1] = 0x05000200;
    dma[2] = 0x80000010;
    dma[2];
    if (D_08318CE4[index].graphics_bytes)
    {
        D_03004BBC[sprite].flags &= 0xBFFF;
        dma[0] = (u32)D_08318CE4[index].graphics;
        dma[1] = 0x06010000;
        dma[2] = 0x80000000 | (D_08318CE4[index].graphics_bytes / 2);
        dma[2];
    }
    else
        D_03004BBC[sprite].flags |= 0x4000;
    {
        register Sprite *destination asm("r3") = &D_03004BBC[sprite];

        destination->offset_x = D_08318CE4[index].offset_x;
        destination->offset_y = D_08318CE4[index].offset_y;
        D_03004BBC[sprite].animations = D_08318CE4[index].animations;
        D_03004BBC[sprite].frames = D_08318CE4[index].frames;
        {
            register u32 zero asm("r0") = 0;

            /* Preserve the pointer and zero register until the tile offset write. */
            asm("" : "+r"(zero) : "r"(destination));
            destination->tile_offset = zero;
        }
        D_03004BBC[sprite].graphics_destination = (void *)0x06010000;
        D_03004BBC[sprite].graphics_source = D_08318CE4[index].graphics;
        return set_sprite_animation(sprite, animation);
    }
}
