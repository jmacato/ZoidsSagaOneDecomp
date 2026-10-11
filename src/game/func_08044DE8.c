#include "types.h"

extern s32 D_0200E288;
extern s32 D_03004B9C[];

void func_08044DE8(u8 index, s32 first, s32 second)
{
    D_0200E288 = first;
    D_03004B9C[index * 2 + 1] = second;
}
