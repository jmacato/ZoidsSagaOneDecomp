#include "game/player_state.h"

void initialize_player_zoid(u8 model_id, PlayerZoid *zoid, u8 value04)
{
    const ZoidModel *model;
    u16 slot;
    EquipmentSlot *equipment;

    zoid->unknown04 = value04;
    zoid->model_id = model_id;
    zoid->flags = 1;
    player_state.zoid_count++;
    model = &zoid_models[zoid->model_id];
    zoid->unknown00 = model->unknown00;
    zoid->training = 0;
    zoid->stats = model->stats;
    zoid->unknown35[0] = model->unknown04;
    slot = 0;
    equipment = zoid->equipment;
    do {
        u32 offset = slot * 4;
        u32 *destination;

        destination = (u32 *)((u8 *)equipment + offset);
        *destination = model->equipment[slot];
        slot++;
    } while (slot <= 5);
    zoid->current_hp = zoid->stats.maximum_hp;
    zoid->current_ep = zoid->stats.maximum_ep;
}
