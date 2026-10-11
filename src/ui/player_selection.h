#ifndef ZOIDS_SAGA_PLAYER_SELECTION_H
#define ZOIDS_SAGA_PLAYER_SELECTION_H

#include "types.h"

extern u8 equipment_selection_count;
extern u8 equipment_selection_ids[150];
extern u8 equipment_quantities[150];
extern u8 recovery_selection_count;
extern u8 recovery_selection_ids[7];
extern u8 recovery_quantities[7];
extern u8 part_selection_count;
extern u8 part_selection_ids[64];
extern u8 part_quantities[64];
extern u8 pilot_selection_count;
extern u8 pilot_selection_ids[87];
extern u8 core_selection_count;
extern u8 core_selection_ids[153];
extern u8 core_quantities[153];

void build_player_equipment_selection(u16 mask);
void build_recovery_item_selection(void);
void build_construction_part_selection(void);
void build_player_pilot_selection(void);
void build_zoid_core_selection(void);

#endif
