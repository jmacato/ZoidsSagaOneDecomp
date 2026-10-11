#include "game/player_state.h"
#include "game/inventory.h"

void add_recovery_items(u8 item_id, u8 quantity)
{
    u32 quantity_bits = quantity << 24;
    u32 current;

    current = player_state.recovery_quantities[item_id];
    quantity_bits >>= 24;
    asm("" : "+r"(current));
    quantity_bits += current;
    player_state.recovery_quantities[item_id] = quantity_bits;
    if (player_state.recovery_quantities[item_id] > 98)
        player_state.recovery_quantities[item_id] = 99;
}
