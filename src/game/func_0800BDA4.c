#include "types.h"

extern struct
{
    u8 pad_0[0x88];
    u16 flags;
    u8 pad_8A[0x48];
    u16 mode;
} D_03004BBC;

extern void *D_08666D34[];

void func_0805D2A0(s32, void *);
void func_08000AF8(s32, u16);

s32 func_0800BDA4(void)
{
    func_0805D2A0(1, D_08666D34[D_03004BBC.mode]);
    func_08000AF8(1, D_03004BBC.flags & 0x400);
    return 0;
}
