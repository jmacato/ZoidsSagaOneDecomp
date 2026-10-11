#include "game/player_state.h"
#include "game/inventory.h"

void add_player_counter_0cd4(u32 amount)
{
    player_state.unknown0cd4 += amount;
    if (player_state.unknown0cd4 > 9999998)
        player_state.unknown0cd4 = 9999999;
}
