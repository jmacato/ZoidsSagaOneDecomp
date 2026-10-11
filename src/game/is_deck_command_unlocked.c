#include "game/player_state.h"
#include "game/inventory.h"

u8 is_deck_command_unlocked(u8 command_id)
{
    u8 unlocked = 0;

    if (player_state.deck_command_unlocks[command_id] == 1)
        unlocked = 1;
    return unlocked;
}
