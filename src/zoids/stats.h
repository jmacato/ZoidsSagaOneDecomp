#ifndef ZOIDS_SAGA_STATS_H
#define ZOIDS_SAGA_STATS_H

#include "types.h"

typedef struct {
    s32 maximum_hp;
    s32 maximum_ep;
    s16 stat_08;
    s16 stat_0a;
} ZoidStats;

typedef struct {
    u8 unknown00[4];
    s16 hp_percent;
    s16 stat_08_percent;
    s16 stat_0a_percent;
    s16 power_percent;
    s16 accuracy_percent;
    u8 unknown0e[2];
} PilotBonuses;

typedef struct {
    u16 unknown00;
    u16 unknown02;
    u8 unknown04;
    u8 unknown05[3];
    u32 equipment[6];
    u8 unknown20[0x20];
    ZoidStats stats;
} ZoidModel;

typedef char ZoidStatsSizeCheck[sizeof(ZoidStats) == 12 ? 1 : -1];
typedef char PilotBonusesSizeCheck[sizeof(PilotBonuses) == 16 ? 1 : -1];
typedef char ZoidModelSizeCheck[sizeof(ZoidModel) == 76 ? 1 : -1];

extern const ZoidModel zoid_models[];
extern const PilotBonuses *const pilot_bonus_tables[][10];

s32 signed_divide(s32 numerator, s32 denominator);
s32 calculate_stat_percentage(s32 value, s16 percentage);
const PilotBonuses *get_pilot_bonuses(u8 pilot_id);
void recalculate_zoid_stats(u32 incoming_pilot, u32 incoming_slot, ZoidStats *stats);

#endif
