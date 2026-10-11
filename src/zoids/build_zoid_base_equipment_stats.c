#include "game/player_state.h"
#include "zoids/equipment.h"

void build_zoid_base_equipment_stats(u8 pilot_id, const PlayerZoid *zoid, ZoidStats *stats)
{
    u8 slot;

    *stats = zoid_models[zoid->model_id].stats;
    slot = 0;
    do {
        u16 item_id = zoid->equipment[slot].item_id;

        if (item_id != 0xFFFF) {
            const EquipmentRecord *record = &equipment_records[item_id];

            if ((record->flags & 0x20000000) != 0) {
                if ((record->flags & 0x00004000) != 0)
                    stats->stat_0a += record->power;
                if ((record->flags & 0x00008000) != 0)
                    stats->stat_0a += record->power;
                if ((record->flags & 0x00010000) != 0)
                    stats->stat_08 += record->power;
                if ((record->flags & 0x00020000) != 0)
                    stats->stat_08 += record->power;
                if ((record->flags & 0x00800000) != 0)
                    stats->maximum_hp += record->power;
                if ((record->flags & 0x01000000) != 0)
                    stats->maximum_ep += record->power;
            }
        }
        slot++;
    } while (slot <= 5);
    if (pilot_id != 0xFF) {
        const PilotBonuses *bonuses = get_pilot_bonuses(pilot_id);

        stats->maximum_hp += calculate_stat_percentage(stats->maximum_hp, bonuses->hp_percent);
    }
    if (stats->maximum_hp > 9999)
        stats->maximum_hp = 9999;
    if (stats->maximum_ep > 999)
        stats->maximum_ep = 999;
    if (stats->stat_08 > 9999)
        stats->stat_08 = 9999;
    if (stats->stat_0a > 999)
        stats->stat_0a = 999;
}
