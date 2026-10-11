#include "types.h"

extern u16 D_0300239C[];

s32 func_0800C14C(u16 value, u16 position)
{
    D_0300239C[position] = ((value >> 12) & 0xF) + 0xE3DC;
    D_0300239C[position + 1] = ((value >> 8) & 0xF) + 0xE3DC;
    D_0300239C[position + 2] = ((value >> 4) & 0xF) + 0xE3DC;
    D_0300239C[position + 3] = (value & 0xF) + 0xE3DC;
}
