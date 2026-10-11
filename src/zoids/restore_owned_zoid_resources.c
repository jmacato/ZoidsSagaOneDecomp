#include "game/player_state.h"

void restore_owned_zoid_resources(void)
{
    u8 slot = 0;

    do {
        if ((player_state.zoids[slot].flags & 1) != 0) {
            player_state.zoids[slot].current_hp = player_state.zoids[slot].stats.maximum_hp;
            player_state.zoids[slot].current_ep = player_state.zoids[slot].stats.maximum_ep;
        }
        slot++;
    } while (slot <= 172);
}
