#include "types.h"

union Slot
{
    u8 kind;
    u32 value;
};

extern struct
{
    u16 flags;
    u8 pad_2[0x21B3];
    u8 phase;
    u8 pad_21B6[2];
    union Slot slots[13];
    u32 current;
    u8 pad_21F0;
    u8 field_21F1;
    u8 pad_21F2[2];
    u32 turns[6];
} D_0200EB84;

void func_0805D270(const void *, void *, u32);
void func_08038A14(void);

void func_0802BBC8(void)
{
    vu16 zero;
    s16 i;

    D_0200EB84.field_21F1 = 0;
    zero = 0;
    func_0805D270((void *)&zero, &D_0200EB84.current, 0x01000002);
    for (i = 0; i < 6; i++)
    {
        vu16 clear = 0;

        func_0805D270((void *)&clear, &D_0200EB84.turns[i], 0x01000002);
    }
    D_0200EB84.current = D_0200EB84.slots[D_0200EB84.phase].value;
    if (D_0200EB84.slots[D_0200EB84.phase].kind == 1 && !(D_0200EB84.flags & 0x20))
        func_08038A14();
}
