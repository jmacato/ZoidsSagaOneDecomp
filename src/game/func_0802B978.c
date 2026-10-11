#include "types.h"

struct Slot
{
    u16 value;
    u16 id;
};

struct Source
{
    u16 id;
    u8 pad_2[2];
    struct Slot slots[3];
};

struct Target
{
    u8 pad_0[6];
    u16 id;
    u8 pad_8[8];
    struct Slot slots[3];
};

struct Info
{
    u8 bytes[0x4C];
};

extern struct Info D_0867006C[];

void func_0805D270(void *, void *, u32);
void func_0802B9DC(struct Target *, struct Info *);

void func_0802B978(struct Target *target, struct Source *source)
{
    vu16 zero = 0;
    u16 i;

    func_0805D270((void *)&zero, target, 0x0100001C);
    target->id = source->id;
    func_0802B9DC(target, &D_0867006C[source->id]);
    for (i = 0; i <= 2; i++)
    {
        if (source->slots[i].id != 0xFFFF)
            target->slots[i] = source->slots[i];
    }
}
