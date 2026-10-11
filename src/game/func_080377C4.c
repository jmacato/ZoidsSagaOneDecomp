#include "types.h"

struct Pilot
{
    u16 flags;
    u8 pad_2[2];
};

extern u8 *D_0866C72C[];
extern struct
{
    u8 pad_0[0x34A4];
    struct Pilot pilots[1];
} D_02000B5C;

void func_080377C4(u8 index)
{
    u8 *list = D_0866C72C[index];
    u8 i = 0;

    while (list[i] != 0xFF)
    {
        D_02000B5C.pilots[list[i]].flags |= 0x20;
        i++;
    }
}
