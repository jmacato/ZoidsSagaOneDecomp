#include "ui/player_selection.h"

void build_recovery_item_selection(void)
{
    s16 id;

    recovery_selection_count = 0;
    id = 0;
    do {
        if (recovery_quantities[id] != 0) {
            recovery_selection_ids[recovery_selection_count] = id;
            recovery_selection_count++;
        }
        id++;
    } while (id <= 6);
}
