#ifndef ZOIDS_SAGA_PLAYER_STATE_H
#define ZOIDS_SAGA_PLAYER_STATE_H

#include "types.h"
#include "zoids/stats.h"

typedef struct {
    u16 flags;
    u16 item_id;
} EquipmentSlot;

typedef struct {
    u16 unknown00;
    u16 flags;
    u16 unknown04;
    u16 model_id;
    s32 current_hp;
    s32 current_ep;
    EquipmentSlot equipment[6];
    ZoidStats stats;
    u8 training;
    u8 unknown35[3];
} PlayerZoid;

typedef struct {
    u16 flags;
    u8 zoid_slot;
    u8 unknown03;
} PlayerPilot;

typedef char PlayerZoidSizeCheck[sizeof(PlayerZoid) == 0x38 ? 1 : -1];
typedef char PlayerPilotSizeCheck[sizeof(PlayerPilot) == 4 ? 1 : -1];

typedef struct {
    u8 zoid_slot;
    u8 pilot_id;
    u8 unknown02[2];
} PlayerTeamSlot;

typedef struct {
    u8 unknown0000[2];
    u8 chapter;
    u8 unknown0003[0xCCF];
    u8 unknown0cd2;
    u8 unknown0cd3;
    u32 unknown0cd4;
    PilotBonuses pilot_bonuses[4];
    u8 unknown0d18[0x10];
    u32 money;
    PlayerZoid zoids[173];
    u8 zoid_count;
    u8 recovery_quantities[7];
    u8 part_quantities[64];
    u8 equipment_quantities[150];
    u8 core_quantities[153];
    u8 deck_command_unlocks[33];
    u8 unknown349c[8];
    PlayerPilot pilots[87];
    PlayerTeamSlot team[6];
} PlayerState;

extern PlayerState player_state;

void set_player_zoid_equipment(u16 item_id, u8 zoid_slot, u8 equipment_slot);
void assign_player_pilot(u8 pilot_id, u8 zoid_slot);
void detach_player_pilot(u8 pilot_id);
void initialize_player_zoid(u8 model_id, PlayerZoid *zoid, u8 value04);
void recalculate_pilot_zoid_stats(u8 pilot_id);
void build_zoid_base_equipment_stats(u8 pilot_id, const PlayerZoid *zoid, ZoidStats *stats);
void restore_owned_zoid_resources(void);

#endif
