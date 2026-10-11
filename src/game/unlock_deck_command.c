#include "game/player_state.h"
#include "game/inventory.h"

void unlock_deck_command(u8 command_id)
{
    player_state.deck_command_unlocks[command_id] = 1;
}
