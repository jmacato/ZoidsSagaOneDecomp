#include "types.h"

extern struct
{
    u8 pad_0[0x18];
    s32 camera_x;
} D_03004B9C;

s32 func_0800BE54(void)
{
    D_03004B9C.camera_x += 0x1000;
}
