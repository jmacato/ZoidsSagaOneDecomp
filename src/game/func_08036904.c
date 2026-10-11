#include "types.h"

extern const u16 D_0866B994[][5];

void func_08036904(u8 level, u8 kind, u16 *stats)
{
    stats[2] = level * D_0866B994[kind][0];
    stats[3] = level * D_0866B994[kind][1];
    stats[4] = level * D_0866B994[kind][2];
    stats[5] = level * D_0866B994[kind][3];
    stats[6] = level * D_0866B994[kind][4];
}
