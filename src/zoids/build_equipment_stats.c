#include "zoids/equipment.h"
#include "zoids/stats.h"

void build_equipment_stats(u8 pilot_id, u16 item_id, EquipmentRecord *stats)
{
    const EquipmentRecord *records = equipment_records;
    const EquipmentRecord *record = &records[item_id];

    *stats = *record;
    if ((stats->flags & 1) != 0) {
        const PilotBonuses *bonuses = get_pilot_bonuses(pilot_id);
        s32 bonus;

        bonus = calculate_stat_percentage(equipment_records[item_id].power, bonuses->power_percent);
        stats->power = stats->power + bonus;
        bonus = calculate_stat_percentage(record->accuracy, bonuses->accuracy_percent);
        stats->accuracy = stats->accuracy + bonus;
    }
}
