#include "game/player_state.h"
#include "game/inventory.h"

void add_construction_parts(u8 item_id, u8 quantity)
{
    u32 quantity_bits = quantity << 24;
    u32 current;

    current = player_state.part_quantities[item_id];
    quantity_bits >>= 24;
    asm("" : "+r"(current));
    quantity_bits += current;
    player_state.part_quantities[item_id] = quantity_bits;
    if (player_state.part_quantities[item_id] > 98)
        player_state.part_quantities[item_id] = 99;
}
