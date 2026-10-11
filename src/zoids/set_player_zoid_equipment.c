#include "game/player_state.h"

void set_player_zoid_equipment(u16 item_id, u8 zoid_slot, u8 equipment_slot)
{
    player_state.zoids[zoid_slot].equipment[equipment_slot].item_id = item_id;
}
