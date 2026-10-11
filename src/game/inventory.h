#ifndef ZOIDS_SAGA_INVENTORY_H
#define ZOIDS_SAGA_INVENTORY_H

#include "types.h"

void add_recovery_items(u8 item_id, u8 quantity);
void add_construction_parts(u8 item_id, u8 quantity);
void add_equipment_items(u8 item_id, u8 quantity);
s32 acquire_zoid_core(u8 core_id);
void unlock_deck_command(u8 command_id);
u8 is_deck_command_unlocked(u8 command_id);
void add_player_money(u32 amount);
void add_player_counter_0cd4(u32 amount);

#endif
