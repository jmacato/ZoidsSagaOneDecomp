#include "types.h"

struct Position
{
    s32 x;
    s32 y;
    s32 z;
};

struct Source
{
    u16 id;
    u8 pad_2[2];
    u8 kind;
    u8 pad_5[3];
    s32 values[6];
    u8 pad_20[0x20];
    struct Position position;
};

struct Target
{
    u16 id;
    u8 pad_2[6];
    s32 x;
    s32 y;
    s32 values[6];
    struct Position position;
    u8 pad_34;
    u8 kind;
};

void func_0802B9DC(struct Target *target, struct Source *source)
{
    u16 i;

    target->id = source->id;
    target->kind = source->kind;
    target->position = source->position;
    target->x = target->position.x;
    target->y = target->position.y;
    for (i = 0; i <= 5; i++)
        target->values[i] = source->values[i];
}
