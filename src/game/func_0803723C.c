#include "game/player_state.h"

extern PlayerState D_02000B5C;

u8 func_0803699C(u8, u8);

void func_0803723C(u8 pilot, u16 flags, u8 kind)
{
    register u32 selector asm("r3") = kind;
    register u32 initial_zoid asm("r4") = selector;
    u8 zoid;

    /* Keep both initial selector registers live for the byte match. */
    asm("" : : "r"(selector), "r"(initial_zoid));
    zoid = initial_zoid;

    D_02000B5C.pilots[pilot].flags |= flags;
    D_02000B5C.pilots[pilot].flags |= 1;
    if (selector)
    {
        if (flags & 4)
            zoid = func_0803699C(selector, 1);
        else
            zoid = func_0803699C(zoid, 0);
        if (zoid != 0xFF)
        {
            if (flags & 4)
            {
                D_02000B5C.zoids[zoid].flags |= 8;
                D_02000B5C.zoids[zoid].training = 100;
            }
            assign_player_pilot(pilot, zoid);
            D_02000B5C.zoids[zoid].current_hp = D_02000B5C.zoids[zoid].stats.maximum_hp;
            D_02000B5C.zoids[zoid].current_ep = D_02000B5C.zoids[zoid].stats.maximum_ep;
        }
    }
}
