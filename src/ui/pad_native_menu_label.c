#include "ui/player_menu.h"

void pad_native_menu_label(const u8 **table, u16 index, u16 columns)
{
    u16 count = 0;
    const u8 *text = table[index];

    if (*text == 0x20) {
        text++;
        while (*text != 0x1D) {
            text += 2;
            count++;
        }
        if (text[1] == 0x22) {
            while (count < columns) {
                script_run_table(menu_layout_scripts, 0x2A);
                count++;
            }
        }
    }
}
