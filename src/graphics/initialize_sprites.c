#include "engine/bios.h"
#include "graphics/sprites.h"

typedef struct {
    u32 y:8;
    u32 affine_mode:2;
    u32 object_mode:2;
    u32 mosaic:1;
    u32 color_mode:1;
    u32 shape:2;
    u32 x:9;
    u32 matrix:5;
    u32 size:2;
    u16 tile:10;
    u16 priority:2;
    u16 palette:4;
    u16 affine_parameter;
} OamData;

extern const OamData D_0805EE80;
extern u8 sprite_order[30];
extern OamData shadow_oam[128];

u32 initialize_sprites(u16 sort_mode)
{
    OamData oam = D_0805EE80;
    u16 zero;
    u16 i;

    sprite_sort_mode = sort_mode;
    for (i = 0; i < 30; i++)
        sprite_order[i] = i;
    i = 0;
    {
        register OamData *entries asm("r12") = shadow_oam;

        asm("" : "+r"(entries));
        for (; i < 128; i++)
        {
            register OamData *entry asm("r1") = &entries[i];

            asm("" : "+r"(entry));
            *entry = oam;
            entry->affine_mode = 2;
        }
    }
    for (i = 0; i < 30; i++)
        sprite_pool[i].flags = 0;
    {
        register u16 *source asm("r0") = &zero;

        asm("" : : "r"(source));
        *source = 0;
        return bios_cpu_set(source, sprite_pool, 0x010007F8);
    }
}
