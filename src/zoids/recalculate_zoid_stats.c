#include "game/player_state.h"
#include "zoids/equipment.h"

void recalculate_zoid_stats(u32 incoming_pilot, u32 incoming_slot, ZoidStats *stats)
{
    u8 pilot_id = (u8)incoming_pilot;
    u8 zoid_slot = (u8)incoming_slot;
    u8 slot;

    *stats = zoid_models[player_state.zoids[zoid_slot].model_id].stats;
    stats->maximum_hp += calculate_stat_percentage(stats->maximum_hp, player_state.zoids[zoid_slot].training / 2);
    stats->maximum_ep += calculate_stat_percentage(stats->maximum_ep, player_state.zoids[zoid_slot].training / 2);
    stats->stat_08 += calculate_stat_percentage(stats->stat_08, player_state.zoids[zoid_slot].training / 2);
    stats->stat_0a += calculate_stat_percentage(stats->stat_0a, player_state.zoids[zoid_slot].training / 2);

    slot = 0;
    do {
        u16 item_id = player_state.zoids[zoid_slot].equipment[slot].item_id;

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
        stats->stat_08 += calculate_stat_percentage(stats->stat_08, bonuses->stat_08_percent);
        stats->stat_0a += calculate_stat_percentage(stats->stat_0a, bonuses->stat_0a_percent);
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
