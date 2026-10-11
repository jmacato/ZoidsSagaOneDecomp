#ifndef ZOIDS_SAGA_SPRITES_H
#define ZOIDS_SAGA_SPRITES_H

#include "types.h"

struct Sprite;
typedef void (*SpriteCallback)(struct Sprite *, struct Sprite *);

typedef struct {
    u16 tile;
    u16 rotation;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    s16 scale_x;
    s16 scale_y;
    u16 affine_flags;
    u16 unknown12;
} SpritePiece;

typedef struct Sprite {
    u16 flags;
    u16 attr0;
    u16 attr1;
    u16 attr2;
    s32 x;
    s32 y;
    u16 offset_x;
    u16 offset_y;
    const u16 **animations;
    const SpritePiece **frames;
    u16 tile_offset;
    u16 graphics_bytes;
    void *graphics_destination;
    const u8 *graphics_source;
    const u8 *current_graphics;
    const u16 *current_animation;
    u16 animation_id;
    u16 first_frame;
    u16 animation_step;
    u16 frame_timer;
    u16 animation_speed;
    u16 screen_x;
    u16 screen_y;
    u16 piece_x;
    u16 piece_y;
    u8 unknown42[0x42];
    SpriteCallback callback;
} Sprite;

typedef char SpriteSizeCheck[sizeof(Sprite) == 0x88 ? 1 : -1];
typedef char SpritePieceSizeCheck[sizeof(SpritePiece) == 20 ? 1 : -1];

extern Sprite sprite_pool[30];
extern u16 sprite_sort_mode;
extern s32 camera_offsets[8];
extern u8 background_tilemap[0x2800];

void sort_sprite_order(void);
void maybe_sort_sprite_order(void);
u32 update_sprites_and_build_oam(void);
u32 build_sprite_oam(u16 selector);
void advance_sprite_animation(u16 selector, u16 stop_at_end);
u32 set_sprite_animation(u32 selector, u32 animation_bits);
u32 refresh_sprite_animation(u32 selector);
void copy_sprite_and_set_animation(u16 selector, const Sprite *source, u16 animation);
u32 clear_background_tilemap(void);
u32 initialize_sprites(u16 sort_mode);
void run_sprite_callback(u16 selector);

#endif
