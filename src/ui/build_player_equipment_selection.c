#include "ui/player_selection.h"
#include "zoids/equipment.h"

void build_player_equipment_selection(u16 mask)
{
    s16 id;

    equipment_selection_count = 0;
    id = 0;
    do {
        const EquipmentRecord *record = &equipment_records[id];

        if (equipment_quantities[id] != 0 && (record->flags & mask) != 0) {
            equipment_selection_ids[equipment_selection_count] = id;
            equipment_selection_count++;
        }
        id++;
    } while (id <= 149);
}
