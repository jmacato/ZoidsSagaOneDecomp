#include "types.h"

extern struct
{
    u16 value;
    u16 entries[10];
    u16 last;
} D_03001ED4;

void func_0805D270(void *, void *, u32);

void func_08004C44(u16 value)
{
    u16 zero;

    D_03001ED4.value = value;
    zero = 0;
    func_0805D270(&zero, D_03001ED4.entries, 0x0100000A);
    D_03001ED4.last = value;
}
