#include "game/player_state.h"
#include "ui/player_selection.h"

void build_player_pilot_selection(void)
{
    s16 id;

    pilot_selection_count = 0;
    id = 0;
    do {
        if ((player_state.pilots[id].flags & 2) != 0) {
            pilot_selection_ids[pilot_selection_count] = id;
            pilot_selection_count++;
        }
        id++;
    } while (id <= 86);
}
