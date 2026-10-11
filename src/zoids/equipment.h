#ifndef ZOIDS_SAGA_EQUIPMENT_H
#define ZOIDS_SAGA_EQUIPMENT_H

#include "types.h"

typedef struct {
    u32 flags;
    u32 unknown04;
    s16 accuracy;
    s16 unknown0a;
    s32 power;
    s16 ep_cost;
    u8 range;
    u8 area;
    u8 weight;
    u8 unknown15[3];
} EquipmentRecord;

typedef char EquipmentRecordSizeCheck[sizeof(EquipmentRecord) == 24 ? 1 : -1];

extern const EquipmentRecord equipment_records[150];

void build_equipment_stats(u8 pilot_id, u16 item_id, EquipmentRecord *stats);

#endif
