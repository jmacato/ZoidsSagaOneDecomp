#include "game/player_state.h"

void recalculate_pilot_zoid_stats(u8 pilot_id)
{
    u8 slot = player_state.pilots[pilot_id].zoid_slot;

    if (slot != 0xFF)
        recalculate_zoid_stats(pilot_id, slot, &player_state.zoids[slot].stats);
}
