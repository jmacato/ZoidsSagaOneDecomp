#include "graphics/sprites.h"

struct SpriteDefinition
{
    u16 *palette;
    void *graphics;
    u32 animations;
    u32 frame_table;
    u8 pad_10[0xA];
    u16 offset_x;
    u16 offset_y;
    u16 graphics_bytes;
};

struct SetupSprite
{
    u16 flags;
    u8 pad_2[4];
    u16 attr2;
    u8 pad_8[8];
    u16 offset_x;
    u16 offset_y;
    u32 animations;
    u32 frame_table;
    u8 pad_1C[4];
    void *graphics_destination;
    void *graphics_source;
    u8 pad_28[8];
    u16 animation_id;
    u8 pad_32[0x28];
    u16 definition_id;
    u8 pad_5C[0x2C];
};

extern struct SetupSprite D_03004BBC[];
extern struct SpriteDefinition D_08318CE4[];

u32 func_080089A0(u16 obj, u16 anim)
{
    register struct SetupSprite *pool asm("r9") = D_03004BBC;
    register u32 offset asm("r12");
    register struct SetupSprite *destination asm("r6");
    u16 palette;
    register vu32 *dma asm("r5");
    register struct SetupSprite *base asm("r2");
    register u32 size asm("r0");

    asm("" : : "r"(pool));
    offset = obj * sizeof(struct SetupSprite);
    asm("" : : "r"(offset));
    destination = (struct SetupSprite *)(offset + (u32)pool);
    palette = destination->attr2 >> 12;
    dma = (vu32 *)0x040000D4;
    dma[0] = (u32)D_08318CE4[anim].palette;
    dma[1] = 0x05000200 + palette * 32;
    dma[2] = 0x80000010;
    dma[2];
    destination->definition_id = anim;
    destination->offset_x = D_08318CE4[anim].offset_x;
    destination->offset_y = D_08318CE4[anim].offset_y;
    {
        register u32 *field asm("r1") = &pool->animations;

        asm("" : "+r"(field));
        *(u32 *)(offset + (u32)field) = D_08318CE4[anim].animations;
    }
    {
        register u32 *field asm("r1") = &pool->frame_table;

        asm("" : "+r"(field));
        *(u32 *)(offset + (u32)field) = D_08318CE4[anim].frame_table;
    }
    {
        register void **field asm("r1") = &pool->graphics_source;

        asm("" : "+r"(field));
        *(void **)(offset + (u32)field) = D_08318CE4[anim].graphics;
    }
    size = D_08318CE4[anim].graphics_bytes;
    asm("" : : "r"(size));
    base = pool;
    asm("" : "+r"(base));
    if (size)
    {
        destination->flags &= 0xBFFF;
        dma[0] = (u32)D_08318CE4[anim].graphics;
        {
            register void **field asm("r0") = &base->graphics_destination;

            asm("" : "+r"(field));
            dma[1] = (u32)*(void **)(offset + (u32)field);
        }
        dma[2] = 0x80000000 | (D_08318CE4[anim].graphics_bytes >> 1);
        dma[2];
    }
    else
    {
        destination->flags |= 0x4000;
    }
    return set_sprite_animation(obj, base[obj].animation_id & 3);
}
