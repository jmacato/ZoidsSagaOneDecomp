#include "types.h"

extern u8 D_08675C5C[];
extern u8 D_086760DC[];

void func_0803E488(u8 *, u8);

void func_08032818(u32 incoming_kind)
{
    u8 kind = (u8)incoming_kind;
    if (kind == 0)
        func_0803E488(D_08675C5C, 0x33);
    else
        func_0803E488(D_086760DC, kind);
}
