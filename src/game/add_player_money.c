#include "game/player_state.h"
#include "game/inventory.h"

void add_player_money(u32 amount)
{
    player_state.money += amount;
    if (player_state.money > 9999998)
        player_state.money = 9999999;
}
