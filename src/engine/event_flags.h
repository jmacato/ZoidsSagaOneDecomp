#ifndef ZOIDS_SAGA_EVENT_FLAGS_H
#define ZOIDS_SAGA_EVENT_FLAGS_H

#include "types.h"

extern u8 player_state[];
extern u16 event_flags[33];
extern const u16 event_flag_masks[16];

u32 set_event_flag(u32 selector);
void clear_event_flags(void);
u32 clear_event_flag(u32 selector);
u32 toggle_event_flag(u32 selector);
u16 test_event_flag(u16 selector);

#endif
