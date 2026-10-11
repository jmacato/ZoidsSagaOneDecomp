#include "game/player_state.h"

void assign_player_pilot(u8 pilot_id, u8 zoid_slot)
{
    player_state.pilots[pilot_id].zoid_slot = zoid_slot;
    player_state.zoids[zoid_slot].flags |= 4;
    recalculate_zoid_stats(pilot_id, zoid_slot, &player_state.zoids[zoid_slot].stats);
}
