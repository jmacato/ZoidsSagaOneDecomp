#include "game/player_state.h"

extern PlayerState D_02000B5C;

u16 func_0804CCF0(s32);
u32 func_08000F88(u32);

u16 func_0804CED0(u16 base, const s32 *list)
{
    u16 count = 0;
    u16 index = 0;
    u16 group;

    for (group = 1; group <= 10; group++)
    {
        register u32 found asm("r5") = 0;
        u16 i;

        /* Keep the group marker separate from the running list index. */
        asm("" : "+r"(found));
        for (i = 0; i <= 0x13; i++, index++)
        {
            if (list[index] != 0)
            {
                u16 pilot = func_0804CCF0(list[index]);

                if (found == 0 && (D_02000B5C.pilots[pilot].flags & 0x20))
                {
                    func_08000F88(base + group);
                    count++;
                    found = 1;
                }
            }
        }
    }
    return count;
}
