#include "types.h"

extern u8 D_0875B2EC[];

void func_0803E488(u8 *, s32);

s32 func_0804DD28(u32 *flags, u8 kind)
{
    switch (kind)
    {
    case 0:
        if (*flags & 0x400)
        {
            func_0803E488(D_0875B2EC, 2);
            return 1;
        }
        break;
    case 1:
        if (*flags & 0x800)
        {
            func_0803E488(D_0875B2EC, 3);
            return 1;
        }
        break;
    case 2:
        if (*flags & 0x1000)
        {
            func_0803E488(D_0875B2EC, 4);
            return 1;
        }
        break;
    case 3:
        if (*flags & 0x2000)
        {
            func_0803E488(D_0875B2EC, 5);
            return 1;
        }
        break;
    }
    return 0;
}
