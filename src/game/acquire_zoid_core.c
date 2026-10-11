#include "game/player_state.h"
#include "game/inventory.h"

s32 acquire_zoid_core(u8 core_id)
{
    s32 already_owned = 1;

    if (player_state.core_quantities[core_id] == 0) {
        already_owned = 0;
        player_state.core_quantities[core_id] = 1;
    }
    return already_owned;
}
