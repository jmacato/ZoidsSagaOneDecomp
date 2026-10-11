#include "types.h"

extern struct
{
    u8 pad_0[0x10];
    u32 x;
    u32 y;
    u32 camera_x;
    u32 camera_y;
} D_03004B9C;

s32 func_0800805C(void);
s32 func_080080E0(void);
s32 func_08008168(void);
s32 func_080081EC(void);

s32 func_08008324(s32 dx, s32 dy)
{
    u16 blocked;

    if (dx != 0)
    {
        blocked = 0;
        if (!(D_03004B9C.x & 0x7FFFF))
        {
            if (dx < 0)
                blocked = func_0800805C();
            else
                blocked = func_080080E0();
        }
        if (blocked == 0)
        {
            D_03004B9C.x += dx;
            D_03004B9C.camera_x += dx;
        }
    }
    if (dy != 0)
    {
        blocked = 0;
        if (!(D_03004B9C.y & 0x7FFFF))
        {
            if (dy < 0)
                blocked = func_08008168();
            else
                blocked = func_080081EC();
        }
        if (blocked == 0)
        {
            D_03004B9C.y += dy;
            D_03004B9C.camera_y += dy;
        }
    }
}
