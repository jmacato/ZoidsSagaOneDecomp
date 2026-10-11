#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[6];
    u32 x;
    u8 pad_C[0x40];
    u16 field_4C;
    u8 pad_4E[2];
    u16 active;
    u16 delay;
    u16 motion;
    u16 distance;
    u16 frames;
    u8 pad_5A[0x2E];
};

extern struct Sprite D_03004BBC[];
extern u8 D_0200DA97;
s32 func_08001080(void);

void func_08049E30(struct Sprite *input)
{
    register struct Sprite *sprite asm("r12") = input;
    register u32 mask asm("r8");
    register u32 flags asm("r1") = input->flags;
    register u32 enabled asm("r0");

    asm("" : : "r"(sprite));
    mask = 0x8000;
    asm("" : : "r"(mask));
    enabled = flags & 0x8000;
    asm("" : : "r"(enabled));
    if (enabled)
    {
        u16 *active = &sprite->active;
        u32 initialized = *active;
        u16 *distance = &sprite->distance;
        register u16 *frames asm("r3") = &sprite->frames;
        u16 *motion;
        u32 speed;

        if (initialized == 0)
        {
            *distance = 0;
            *frames = 0;
            *active = 1;
            active++;
            asm("" : "+r"(active));
            *active = 0xFF;
        }
        motion = &sprite->motion;
        speed = *motion >> 8;
        {
            u32 step = speed << 16;
            register struct Sprite *current asm("r4") = sprite;

            asm("" : : "r"(step));
            current->x -= step;
        }
        {
            register u32 moved asm("r0");

            {
                register u16 *current asm("r2") = distance;

                asm("" : "+r"(current));
                *current += speed;
                (*frames)++;
                moved = *current;
            }
            if (moved > 0xA0)
            {
                u16 *delay = &sprite->delay;
                register u32 value asm("r0") = *delay;
                register u32 saved asm("r4") = value;

                asm("" : : "r"(saved));
                if (saved == 0xFF)
                    *delay = func_08001080() & 0xF;
                else if (saved != 0)
                    *delay = value - 1;
                else
                {
                    register struct Sprite *table asm("r2") = D_03004BBC;
                    register u32 index asm("r0");
                    register u32 pending asm("r3");
                    register struct Sprite *entry asm("r1");
                    u32 selected;
                    register u32 offset asm("r1");
                    register u32 found asm("r2");
                    register u32 marked asm("r0");
                    u32 updated;

                    asm("" : : "r"(table));
                    pending = 0xFF;
                    asm("" : : "r"(pending));
                    index = *(u8 *)motion;
                    asm("" : : "r"(index));
                    selected = index + D_0200DA97;
                    offset = selected * sizeof(struct Sprite);
                    asm("" : "+r"(offset));
                    entry = (struct Sprite *)(offset + (u32)table);
                    asm("" : : "r"(entry));
                    found = entry->flags;
                    asm("" : : "r"(found));
                    marked = found | mask;
                    asm("" : : "r"(marked));
                    entry->flags = marked;
                    updated = sprite->flags & 0x7FFF;
                    asm("" : : "r"(updated));
                    sprite->flags = updated;
                    *delay = pending;
                    {
                        u32 step = (u32)*distance << 16;
                        struct Sprite *current;

                        asm("" : : "r"(step));
                        current = sprite;
                        current->x += step;
                    }
                    *distance = saved;
                    sprite->field_4C = saved;
                }
            }
        }
    }
}
