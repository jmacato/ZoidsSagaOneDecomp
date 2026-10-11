#include "ui/player_menu.h"

void render_player_zoid_hp(const PlayerZoid *zoid)
{
    if ((zoid->unknown00 & 0x800) == 0)
        render_text_number(zoid->current_hp, 4, 0);
    else
        script_run_table(menu_status_scripts, 7);
}
