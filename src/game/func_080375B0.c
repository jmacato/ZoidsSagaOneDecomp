#include "game/player_state.h"

extern u8 func_0803699C(u8 id, u8 mode);
extern void func_08037A20(u8 pilot, u8 position);

void func_080375B0(u8 selector)
{
    u8 id;

    switch (selector)
    {
    case 0:
        id = 0x39;
        break;
    case 1:
        id = 0x0F;
        break;
    case 2:
        id = 0x5C;
        break;
    default:
        id = 0x39;
        break;
    }
    assign_player_pilot(0, func_0803699C(id, 0));
    func_08037A20(0, 1);
}
