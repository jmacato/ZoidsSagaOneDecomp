#include "graphics/sprites.h"

extern u8 sprite_order[30];
extern u16 sprite_oam_count;
extern u8 sprite_affine_count;
typedef struct {
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 affine_parameter;
} SpriteOamEntry;

typedef char SpriteOamEntrySizeCheck[sizeof(SpriteOamEntry) == 8 ? 1 : -1];

extern SpriteOamEntry shadow_oam[128];

u32 update_sprites_and_build_oam(void)
{
    u16 selector;
    register u32 result asm("r0");

    maybe_sort_sprite_order();
    sprite_oam_count = 0;
    sprite_affine_count = 0;
    for (selector = 0; selector <= 29; selector++)
        result = build_sprite_oam(sprite_order[selector]);
    if (sprite_oam_count <= 126) {
        selector = sprite_oam_count;
        if (selector <= 127) {
            register SpriteOamEntry *entries asm("r5") = shadow_oam;
            register u32 hidden_bits asm("r1") = 0x200;
            u32 hidden;

            asm volatile("" : "+r"(hidden_bits));
            hidden = hidden_bits;
            do {
                SpriteOamEntry *entry = (SpriteOamEntry *)(selector * sizeof(*entries) + (u32)entries);

                entry->attr0 = hidden;
                entry->attr1 = 0;
                entry->attr2 = 0;
                selector++;
            } while (selector <= 127);
        }
    }
    return result;
}
