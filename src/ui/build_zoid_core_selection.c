#include "ui/player_selection.h"

void build_zoid_core_selection(void)
{
    s16 id;

    core_selection_count = 0;
    id = 0;
    do {
        if (core_quantities[id] != 0) {
            core_selection_ids[core_selection_count] = id;
            core_selection_count++;
        }
        id++;
    } while (id <= 152);
}
