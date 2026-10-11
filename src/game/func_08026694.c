#include "game/player_state.h"

struct EventCondition
{
    u16 pilot;
    u8 pad_2[2];
    u16 type;
    u8 pad_6[2];
};

extern PlayerState D_02000B5C;

extern const struct EventCondition D_0832AE10[];

void func_08000FD8(u16);
void func_08000F88(u16);
u32 func_0803E024(u8, u16, u8);

u32 func_08026694(void)
{
    u16 i;

    for (i = 0; i <= 0x1C; i++)
    {
        register u32 kind asm("r1");

        func_08000FD8(i);
        kind = D_0832AE10[i].type;
        if (kind == 0)
            func_08000F88(i);
        else if (kind == 1)
        {
            kind &= D_02000B5C.pilots[D_0832AE10[i].pilot].flags;
            /* Keep this mask separate from the other event conditions. */
            asm("" : "+r"(kind));
            if (kind)
                func_08000F88(i);
        }
        else if (kind == 2)
        {
            if (D_02000B5C.pilots[18].flags & 1)
                func_08000F88(i);
        }
        else if (kind == 3)
        {
            if (D_02000B5C.pilots[19].flags & 1)
                func_08000F88(i);
        }
    }
    func_08000F88(0x1D);
    return func_0803E024(0, 0x140, 0xB4);
}
