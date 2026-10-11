#include "types.h"

extern struct
{
    u8 pad_0[3];
    u8 mode;
} D_02000B5C;

s32 func_08006DFC(s32 mode)
{
    D_02000B5C.mode = mode;
}
