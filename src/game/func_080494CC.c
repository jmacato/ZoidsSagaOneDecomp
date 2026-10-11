#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[6];
    u32 x;
    u32 y;
    u8 pad_10[0x24];
    u16 tile;
    u8 pad_36[0x16];
    u16 active;
    u16 source;
    u16 state;
    u16 pad_52;
    u16 target;
    u16 phase;
    u16 previous;
    u8 pad_5A[0x2E];
};

extern struct Sprite D_03004BBC[];
extern u8 D_0200E4EC[];
extern u32 D_0200E4F4[];
extern u32 D_0200E510[];
extern u32 D_0200E52C[];
extern u32 D_0200E548[];
extern s32 D_0200E564[];
extern s32 D_0200E580[];
extern u32 D_0200E59C[];
extern u32 D_0200E5B8[];
extern u32 D_0200E5D4[];
extern u8 D_0200E270[];
extern u16 D_0200E276[];
extern u16 D_0200E4C6[];

void func_08000BD8(u16, u16);
void func_08048EF4(u32, u32, u16);

void func_080494CC(struct Sprite *sprite)
{
    register s32 source asm("r8") = (u8)((u8)sprite->source - 2);
    register s32 target asm("r10");
    u8 track;
    u32 *copy_y;
    u32 value_x;
    struct
    {
        u32 *x;
        u32 *y;
        s32 *step_y;
        u32 *delta_x;
        u32 *delta_y;
        u8 *direction;
        u16 *phase;
    } local;
    asm("" : : "r"(source), "r"(&sprite->source));
    target = (u8)((u8)sprite->target - 14);
    asm("" : : "r"(target));

    switch (sprite->state)
    {
    case 0:
    {
        u32 offset = 0x56;
        u16 *phase_read;
        register u16 *phase asm("r9");
        asm("" : "+l"(offset));
        phase_read = (u16 *)(offset + (u32)sprite);
        phase = phase_read;
        asm("" : : "r"(phase), "r"(phase_read));
        switch (*phase_read)
        {
        case 0:
        {
            struct Sprite *first;
            struct Sprite *second;
            s32 first_index;
            s32 second_index;
            func_08000BD8(sprite->source, 0);
            D_03004BBC[sprite->source].flags |= 0x8000;
            D_03004BBC[1].tile = D_03004BBC[sprite->source].tile;
            first_index = source + 8;
            asm("" : "+r"(first_index));
            first = &D_03004BBC[first_index];
            first->tile = 0;
            first->flags &= 0x7FFF;
            second_index = source + 24;
            asm("" : "+r"(second_index));
            second = &D_03004BBC[second_index];
            second->flags &= 0x7FFF;
            func_08048EF4((u8)second_index, target, 0);
            {
                u16 *increment = phase;
                asm("" : "+l"(increment) : : "r0", "r1", "r2", "r3");
                (*increment)++;
            }
        }
        case 1:
        {
            s32 parent;
            sprite->x = D_03004BBC[sprite->source - 1].x;
            parent = sprite->source - 1;
            asm("" : "+l"(parent) : : "r0");
            copy_y = &D_03004BBC[parent].y;
            goto finish_copy;
        }
        }
        break;
    }
    case 2:
    {
        u32 offset = 0x56;
        u16 *phase_read;
        register u16 *phase asm("r9");
        asm("" : "+l"(offset));
        phase_read = (u16 *)(offset + (u32)sprite);
        phase = phase_read;
        asm("" : : "r"(phase), "r"(phase_read));
        switch (*phase_read)
        {
        case 0:
        {
            struct Sprite *first;
            struct Sprite *second;
            s32 first_index;
            s32 second_index;
            func_08000BD8(sprite->source, 0);
            D_03004BBC[sprite->source].flags &= 0x7FFF;
            first_index = source + 8;
            asm("" : "+r"(first_index));
            first = &D_03004BBC[first_index];
            first->flags &= 0x7FFF;
            second_index = source + 24;
            asm("" : "+r"(second_index));
            second = &D_03004BBC[second_index];
            second->flags &= 0x7FFF;
            first->tile = 0;
            func_08048EF4((u8)second_index, target, 0);
            {
                u16 *increment = phase;
                asm("" : "+l"(increment) : : "r0");
                (*increment)++;
            }
        }
        case 1:
            sprite->x = D_03004BBC[1].x;
            copy_y = &D_03004BBC[1].y;
        finish_copy:
            sprite->y = *copy_y;
            sprite->active = 0;
            {
                u16 *previous = &sprite->previous;
                asm("" : "+l"(previous) : : "r0");
                *previous = 255;
                asm volatile("" : : : "memory");
            }
            break;
        }
        break;
    }
    case 1:
        track = (u8)sprite->source - 1;
        {
            u16 *phase = &sprite->phase;
            register u32 value asm("r1") = *phase;
            u32 state_value;
            asm("" : : "r"(value));
            state_value = value;
            local.phase = phase;
            switch (state_value)
        {
        case 0:
            sprite->active = 1;
            D_03004BBC[sprite->source].flags |= 0x8000;
            D_0200E4F4[track] = value_x = D_03004BBC[sprite->target].x;
            {
                u32 *destination = &D_0200E510[track];
                register u32 value asm("r0");
                register u32 bias asm("r2");
                asm("" : : "r"(destination), "r"(value_x));
                value = D_03004BBC[sprite->target].y;
                asm("" : : "r"(value));
                bias = -0x190000;
                asm("" : : "r"(bias));
                *destination = value + bias;
            }
            D_0200E52C[track] = sprite->x;
            D_0200E548[track] = sprite->y;
            if (D_0200E4F4[track] > D_0200E52C[track])
            {
                D_0200E59C[track] = D_0200E4F4[track] - D_0200E52C[track];
                D_0200E564[track] = 0x10000;
            }
            else
            {
                D_0200E59C[track] = D_0200E52C[track] - D_0200E4F4[track];
                D_0200E564[track] = -0x10000;
            }
            if (D_0200E510[track] > D_0200E548[track])
            {
                D_0200E5B8[track] = D_0200E510[track] - D_0200E548[track];
                D_0200E580[track] = 0x10000;
            }
            else
            {
                D_0200E5B8[track] = D_0200E548[track] - D_0200E510[track];
                D_0200E580[track] = -0x10000;
            }
            if (D_0200E59C[track] > D_0200E5B8[track])
            {
                D_0200E4EC[track] = 0;
                D_0200E5D4[track] = D_0200E59C[track] - D_0200E5B8[track];
            }
            else
            {
                D_0200E4EC[track] = 1;
                D_0200E5D4[track] = D_0200E5B8[track] - D_0200E59C[track];
            }
            {
                u16 *increment = local.phase;
                asm("" : "+l"(increment) : : "r0", "r1", "r2");
                (*increment)++;
                asm volatile("" : : : "memory");
            }
            break;
        case 1:
        {
            register u32 count asm("r5") = 0;
            register u32 offset asm("r4");
            register u32 *error_base asm("r8");
            register u32 *delta_y_base asm("r12");
            register s32 *step_y_base asm("r10");
            u32 *delta_x_base;
            register u32 threshold asm("r6");

            asm("" : "+l"(count) : : "r0", "r1", "r2", "r3", "r4");
            {
                register u32 input asm("r0") = track;
                asm("" : "+r"(input));
                offset = input * 4;
            }
            asm("" : "+l"(offset) : : "r0", "r1", "r2", "r3");
            local.x = (u32 *)((u8 *)D_0200E4F4 + offset);
            local.y = (u32 *)((u8 *)D_0200E510 + offset);
            {
                register u32 *base asm("r1") = D_0200E5D4;
                asm("" : : "r"(base));
                error_base = base;
            }
            asm("" : : "r"(error_base));
            {
                register u32 *base asm("r2") = D_0200E5B8;
                asm("" : : "r"(base));
                delta_y_base = base;
            }
            asm("" : : "r"(delta_y_base));
            {
                register u32 *field asm("r3") = delta_y_base;
                asm("" : "+r"(field));
                field = (u32 *)(offset + (u32)field);
                local.delta_y = field;
            }
            local.direction = &D_0200E4EC[track];
            threshold = 0xFF0000;
            asm("" : : "r"(threshold));
            {
                register s32 *base asm("r0") = D_0200E580;
                asm("" : : "r"(base));
                step_y_base = base;
            }
            asm("" : : "r"(step_y_base));
            {
                register s32 *field asm("r1") = step_y_base;
                asm("" : "+r"(field));
                field = (s32 *)(offset + (u32)field);
                local.step_y = field;
            }
            {
                register u32 *base asm("r2") = D_0200E59C;
                asm("" : : "r"(base));
                delta_x_base = base;
            }
            asm("" : : "r"(delta_x_base));
            {
                register u32 *field asm("r3") = delta_x_base;
                asm("" : "+r"(field));
                field = (u32 *)(offset + (u32)field);
                local.delta_x = field;
            }
        iterate:
            {
                register u32 current asm("r1");
                register u32 *destination asm("r2");
                register u8 *direction asm("r1");
                asm("" : : : "r0", "r1", "r2", "r3");
                current = sprite->x;
                asm("" : : "r"(current));
                destination = local.x;
                asm("" : : "r"(destination));
                if (current == *destination)
                {
                    register u32 current_y asm("r1");
                    register u32 *destination_y asm("r3");
                    current_y = sprite->y;
                    asm("" : : "r"(current_y));
                    destination_y = local.y;
                    asm("" : : "r"(destination_y));
                    if (current_y == *destination_y)
                        goto arrived;
                }
                direction = local.direction;
                asm("" : : "r"(direction));
                switch (*direction)
                {
                case 0:
                {
                    register u32 base asm("r3") = (u32)error_base;
                    register u32 *error asm("r2");
                    register u32 *delta asm("r0");
                    register u32 amount asm("r0");
                    register u32 old asm("r1");
                    asm("" : "+r"(base));
                    error = (u32 *)(offset + base);
                    {
                        register u32 low asm("r1") = (u32)delta_y_base;
                        asm("" : "+r"(low) : "r"(error));
                        delta = (u32 *)(offset + low);
                    }
                    old = *error;
                    asm("" : : "r"(old), "r"(delta));
                    amount = *delta;
                    old -= amount;
                    *error = old;
                    if (old > threshold)
                    {
                        register u32 value asm("r0") = sprite->y;
                        register s32 *step asm("r3");
                        register s32 change asm("r1");
                        asm("" : : "r"(value));
                        step = local.step_y;
                        asm("" : : "r"(step));
                        change = *step;
                        value += change;
                        sprite->y = value;
                        {
                            register u32 value asm("r0") = *error;
                            register u32 *delta asm("r3");
                            register u32 change asm("r1");
                            asm("" : : "r"(value));
                            delta = local.delta_x;
                            asm("" : : "r"(delta));
                            change = *delta;
                            *error = value + change;
                        }
                    }
                    {
                        register s32 *step asm("r0") = D_0200E564;
                        register u32 value asm("r1");
                        register s32 change asm("r0");
                        asm("" : "+r"(step));
                        step = (s32 *)(offset + (u32)step);
                        value = sprite->x;
                        asm("" : : "r"(value), "r"(step));
                        change = *step;
                        value += change;
                        sprite->x = value;
                    }
                    break;
                }
                case 1:
                {
                    register u32 row asm("r2") = offset;
                    register u32 *error asm("r3");
                    register u32 *delta asm("r0");
                    register u32 amount asm("r0");
                    register u32 old asm("r1");
                    asm("" : "+r"(row));
                    {
                        register u32 base asm("r0") = (u32)error_base;
                        asm("" : "+r"(base));
                        error = (u32 *)(row + base);
                    }
                    {
                        register u32 base asm("r1") = (u32)delta_x_base;
                        asm("" : "+r"(base) : "r"(error));
                        delta = (u32 *)(row + base);
                    }
                    old = *error;
                    asm("" : : "r"(old), "r"(delta));
                    amount = *delta;
                    old -= amount;
                    *error = old;
                    if (old > threshold)
                    {
                        register s32 *step asm("r0") = D_0200E564;
                        register u32 value asm("r1");
                        register s32 change asm("r0");
                        asm("" : "+r"(step));
                        step = (s32 *)(row + (u32)step);
                        value = sprite->x;
                        asm("" : : "r"(value), "r"(step));
                        change = *step;
                        value += change;
                        sprite->x = value;
                        {
                            register u32 value asm("r0") = *error;
                            register u32 *delta asm("r2");
                            register u32 change asm("r1");
                            asm("" : : "r"(value));
                            delta = local.delta_y;
                            asm("" : : "r"(delta));
                            change = *delta;
                            *error = value + change;
                        }
                    }
                    {
                        register u32 base asm("r3") = (u32)step_y_base;
                        register s32 *step asm("r0");
                        register u32 value asm("r1");
                        register s32 change asm("r0");
                        asm("" : "+r"(base));
                        step = (s32 *)(offset + base);
                        value = sprite->y;
                        asm("" : : "r"(value), "r"(step));
                        change = *step;
                        value += change;
                        sprite->y = value;
                    }
                    break;
                }
                }
                {
                    register u32 next asm("r0") = count + 1;
                    asm("" : "+r"(next));
                    count = (u8)next;
                }
                if (count <= 9)
                    goto iterate;
            }
            break;
        }
        case 2:
        {
            register u8 *pool asm("r6");
            register u32 first_index asm("r0");
            register u32 second_index asm("r0");
            register u32 first_offset asm("r3");
            register u32 second_offset asm("r2");
            register struct Sprite *first asm("r4");
            register struct Sprite *first_saved asm("r9");
            register struct Sprite *second asm("r4");
            register u32 flags asm("r0");
            register u32 mask asm("r5");
            register u32 *x_base asm("r4");
            register u32 *first_x asm("r8");

            func_08000BD8(sprite->source, 1);
            pool = (u8 *)D_03004BBC;
            asm("" : : "r"(pool));
            first_index = source + 8;
            asm("" : "+r"(first_index));
            first_offset = first_index * 136;
            asm("" : : "r"(first_offset));
            first = (struct Sprite *)(first_offset + (u32)pool);
            first_saved = first;
            asm("" : : "r"(first), "r"(first_saved));
            flags = first->flags;
            asm("" : : "r"(flags));
            {
                register u32 bit asm("r1") = 0x8000;
                asm("" : : "r"(bit));
                mask = bit;
            }
            asm("" : : "r"(mask));
            flags |= mask;
            first->flags = flags;
            second_index = source + 24;
            asm("" : "+r"(second_index));
            second_offset = second_index * 136;
            asm("" : : "r"(second_offset));
            second = (struct Sprite *)(second_offset + (u32)pool);
            {
                register u32 flags asm("r1") = second->flags;
                asm("" : : "r"(flags));
                mask |= flags;
                second->flags = mask;
            }
            x_base = (u32 *)(pool + 8);
            {
                register u32 *field asm("r5") = (u32 *)(first_offset + (u32)x_base);
                asm("" : : "r"(field));
                first_x = field;
            }
            asm("" : : "r"(first_x));
            {
                register u32 value asm("r1") = sprite->x;
                register u32 bias asm("r5");
                asm("" : : "r"(value));
                bias = 0xF0000;
                asm("" : : "r"(bias));
                value += bias;
                {
                    register u32 *field asm("r5") = first_x;
                    asm("" : : "r"(field));
                    *field = value;
                }
            }
            pool += 12;
            {
                register u32 *field asm("r3") = (u32 *)(first_offset + (u32)pool);
                register u32 value asm("r1") = sprite->y;
                asm("" : : "r"(field), "r"(value));
                *field = value;
            }
            {
                register u32 *field asm("r4") = (u32 *)(second_offset + (u32)x_base);
                register u32 value asm("r1");
                register u32 bias asm("r3");
                asm("" : : "r"(field));
                value = sprite->x;
                asm("" : : "r"(value));
                bias = 0xA0000;
                asm("" : : "r"(bias));
                value += bias;
                *field = value;
            }
            {
                register u32 *field asm("r2") = (u32 *)(second_offset + (u32)pool);
                register u32 value asm("r1");
                register u32 bias asm("r4");
                asm("" : : "r"(field));
                value = sprite->y;
                asm("" : : "r"(value));
                bias = -0x80000;
                asm("" : : "r"(bias));
                value += bias;
                *field = value;
            }
            func_08048EF4((u8)second_index, target, 0);
            {
                register u16 *active asm("r0") = &sprite->active;
                register u32 zero asm("r5") = 0;
                asm("" : : "r"(active), "r"(zero));
                *active = zero;
            }
            if (sprite->target == sprite->previous)
            {
                register u32 four asm("r0") = 4;
                asm("" : : "r"(four));
                *local.phase = four;
            }
            else
            {
                register u32 zero asm("r3") = 0;
                register struct Sprite *first asm("r2");
                asm("" : : "r"(zero));
                first = first_saved;
                asm("" : : "r"(first));
                first->tile = zero;
                goto advance;
            }
            break;
        }
        case 3:
        {
            register u32 zero asm("r5") = 0;
            register u32 complete asm("r9");
            register struct Sprite *first asm("r2");
            register u32 index asm("r1");
            register volatile u16 *full asm("r5");
            register u16 *shown asm("r4");
            register u32 display asm("r6");
            register u32 step asm("r1");
            register u32 offset asm("r2");
            asm("" : : "r"(zero));
            complete = zero;
            asm("" : : "r"(complete));
            sprite->previous = 255;
            {
                register struct Sprite *pool asm("r2") = D_03004BBC;
                asm("" : : "r"(pool));
                index = source + 8;
                asm("" : "+r"(index));
                first = (struct Sprite *)((index * 136) + (u32)pool);
            }
            asm("" : : "r"(first));
            first->tile += 16;
            asm volatile("" : : : "memory");
            {
                register s32 current asm("r1") = first->tile;
                register s32 limit asm("r0");
                asm("" : : "r"(current));
                limit = D_0200E270[target] * 2;
                asm("" : : "r"(limit));
                if (current >= limit)
                {
                    first->tile = limit;
                    {
                        register u32 one asm("r0") = 1;
                        asm("" : : "r"(one));
                        complete = one;
                    }
                }
            }
            {
                register u16 *base asm("r0") = D_0200E276;
                asm("" : : "r"(base));
                {
                    register s32 input asm("r1") = target;
                    asm("" : : "r"(input));
                    offset = input * 2;
                }
                asm("" : : "r"(offset));
                full = (u16 *)(offset + (u32)base);
            }
            asm("" : : "r"(full));
            {
                register u32 value asm("r0") = *full;
                asm("" : : "r"(value));
                step = value >> 4;
            }
            asm("" : : "r"(step));
            if (step == 0)
                step = 1;
            {
                register u32 raw asm("r0") = source + 24;
                asm("" : "+r"(raw));
                display = (u8)raw;
            }
            asm("" : : "r"(display));
            {
                register u16 *base asm("r4") = D_0200E4C6;
                asm("" : : "r"(base));
                shown = (u16 *)(offset + (u32)base);
            }
            asm("" : : "r"(shown));
            {
                register u32 value asm("r2") = *shown;
                asm("" : : "r"(value));
                value = step + value;
                func_08048EF4(display, target, (u16)value);
            }
            {
                register u32 current asm("r0") = *shown;
                register u32 limit asm("r2");
                asm("" : : "r"(current));
                limit = *full;
                asm("" : : "r"(limit));
                if (current >= limit)
                {
                    func_08048EF4(display, target, *full);
                    {
                        register u32 next asm("r0") = complete + 1;
                        asm("" : "+r"(next));
                        complete = (u8)next;
                    }
                }
            }
            {
                register u32 value asm("r3") = complete;
                asm("" : : "r"(value));
                if (value == 2)
                    goto advance;
            }
            break;
        }
        advance:
            {
                u16 *increment = local.phase;
                asm("" : "+l"(increment) : : "r0", "r1", "r2", "r3");
                (*increment)++;
                asm volatile("" : : : "memory");
            }
            break;
        arrived:
            {
                u16 *increment = local.phase;
                asm("" : "+l"(increment) : : "r0", "r1", "r2", "r3", "r4");
                (*increment)++;
                asm volatile("" : : : "memory");
            }
            break;
        case 4:
            sprite->previous = sprite->target;
            break;
        }
        }
        break;
    }
}
