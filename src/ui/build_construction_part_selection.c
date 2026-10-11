#include "ui/player_selection.h"

void build_construction_part_selection(void)
{
    s16 id;

    part_selection_count = 0;
    id = 0;
    do {
        if (part_quantities[id] != 0) {
            part_selection_ids[part_selection_count] = id;
            part_selection_count++;
        }
        id++;
    } while (id <= 63);
}
