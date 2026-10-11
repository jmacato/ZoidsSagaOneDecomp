#ifndef ZOIDS_SAGA_FADE_H
#define ZOIDS_SAGA_FADE_H

#include "types.h"

extern u16 fade_counter;
extern u16 fade_level;
extern u16 display_fade_level;

u32 fade_from_white(u16 frame_mask);
u32 fade_from_black(u16 frame_mask, void (*callback)(void));
u32 fade_to_black(u16 frame_mask, void (*callback)(void));
void start_fade_from_black(u32 value);
void start_fade_to_black(u32 value);
int step_fade_from_black(u16 frame_mask);
int step_fade_to_black(u16 frame_mask);

#endif
