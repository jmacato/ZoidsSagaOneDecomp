#include "game/player_state.h"

struct Preset
{
    PlayerZoid zoids[9];
    u8 entries[14][4];
    u8 pilots[12];
};

extern struct
{
    PlayerState player;
    u8 pad_3618[4];
    struct Preset presets[4];
    u8 selected;
} D_02000B5C;

void func_0803AED4(void)
{
    struct Preset *preset = &D_02000B5C.presets[D_02000B5C.selected];
    u8 (*entries)[4] = preset->entries;
    u16 slot;

    for (slot = 0; slot <= 5; slot++)
    {
        D_02000B5C.player.zoids[slot] = preset->zoids[slot];
        {
            u32 offset = slot * sizeof(*entries);
            PlayerState *player_slot = (PlayerState *)((u8 *)&D_02000B5C.player + offset);
            u8 *entry;

            entry = (u8 *)entries + offset;
            player_slot->team[0].zoid_slot = *entry;
            player_slot->team[0].pilot_id = preset->pilots[slot];
        }
    }
}
