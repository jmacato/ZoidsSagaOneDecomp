#include "game/player_state.h"

void detach_player_pilot(u8 pilot_id)
{
    u8 zoid_slot = player_state.pilots[pilot_id].zoid_slot;

    if (zoid_slot != 0xFF) {
        player_state.pilots[pilot_id].zoid_slot = 0xFF;
        player_state.zoids[zoid_slot].flags &= 0xFFFB;
        recalculate_zoid_stats(0xFF, zoid_slot, &player_state.zoids[zoid_slot].stats);
        if (player_state.zoids[zoid_slot].current_hp > player_state.zoids[zoid_slot].stats.maximum_hp)
            player_state.zoids[zoid_slot].current_hp = player_state.zoids[zoid_slot].stats.maximum_hp;
        if (player_state.zoids[zoid_slot].current_ep > player_state.zoids[zoid_slot].stats.maximum_ep)
            player_state.zoids[zoid_slot].current_ep = player_state.zoids[zoid_slot].stats.maximum_ep;
    }
}
