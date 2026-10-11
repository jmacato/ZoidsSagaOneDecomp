#ifndef ZOIDS_SAGA_PLAYER_MENU_H
#define ZOIDS_SAGA_PLAYER_MENU_H

#include "game/player_state.h"
#include "text.h"

extern const u8 *menu_layout_scripts[];
extern const u8 *menu_status_scripts[];
extern const u32 pilot_bonus_thresholds[];

void render_text_number(s32 value, u8 columns, u16 format);
void pad_native_menu_label(const u8 **table, u16 index, u16 columns);
void render_player_zoid_hp(const PlayerZoid *zoid);
u32 get_pilot_bonus_threshold(void);
void run_player_menu(void);

#endif
