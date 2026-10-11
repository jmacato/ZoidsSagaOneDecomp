#include "game/player_state.h"

const PilotBonuses *get_pilot_bonuses(u8 pilot_id)
{
    u8 chapter = player_state.chapter - 1;

    if (chapter > 10)
        chapter = 0;
    switch (pilot_id) {
    case 0:
        return &player_state.pilot_bonuses[0];
    case 1:
        return &player_state.pilot_bonuses[1];
    case 2:
        return &player_state.pilot_bonuses[2];
    case 3:
        return &player_state.pilot_bonuses[3];
    default:
        /* The native selector permits chapter 10 with a ten-pointer stride. */
        return pilot_bonus_tables[pilot_id][chapter];
    }
}
