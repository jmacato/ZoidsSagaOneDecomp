#include "types.h"

struct Actor
{
    u8 sprite[0x4A];
    u16 relation;
    u16 duration;
    u16 move_x;
    u16 move_y;
    u16 pad_52[2];
    u16 movement_flags;
    u16 counter;
    u16 state;
    u16 collision;
    u16 pad_5E;
    u16 mode;
    volatile u16 type;
    u8 pad_64[0x10];
    s32 velocity_x;
    s32 velocity_y;
    s32 rate;
    void *child;
    u8 pad_84[4];
};

extern struct Actor D_03004BBC[];
extern u16 D_02000000[];
extern u16 D_0200000C[];
extern u16 D_02000B5C;
extern u16 D_03004C8E;
u32 func_080084D4(u16, s32, s32);
u32 func_08008434(s32, s32, s32);
void func_08000BD8(s32, s32);
void func_080083B8(s32, u16 *, u16 *, u16 *, u16 *);
void func_0800BEC8(void);
void func_08001524(s32, void *);
void func_080014A8(s32, void *);
void func_08007188(s32, s32, s32, s32);
void func_0800990C(void);
u32 func_08001080(void);
void func_080089A0(s32, s32);
void func_080019EC(s32);
void func_08008274(s32, s32);

void func_0800AE7C(u32 index, u32 animation, s32 dx, s32 dy)
{
    struct
    {
        u16 coordinates[4];
        u32 saved_dx;
        u32 saved_dy;
        u32 movement_flags;
        s32 rate;
        volatile u32 duration;
        s32 *velocity_x;
        s32 dx;
        s32 *velocity_y;
        s32 dy;
        volatile u32 index_shift;
        struct Actor *volatile saved_base;
    } frame;
    register u32 selector asm("r6") = (u16)index;
    register u32 selected_animation asm("r10");
    register struct Actor *base asm("r4");
    register struct Actor *actor asm("r9");
    register struct Actor *other asm("r8");
    u32 flags;
    register u32 delay asm("r0");
    register struct Actor *delay_actor asm("r1");
    register struct Actor *mover asm("r4");
    register u32 player_state_value asm("r0");
    register u32 player_type asm("r1");
    register u32 other_index asm("r5");
    asm("" : "+r"(animation) : "r"(selector));
    {
        register u32 value asm("r1") = (u16)animation;
        asm("" : : "r"(value));
        selected_animation = value;
        asm("" : : "r"(selected_animation));
    }
    {
        register u32 xword asm("r2") = (u32)dx << 16;
        register u32 yword asm("r3");
        register u32 offset asm("r1");
        register u32 address asm("r0");
        asm("" : : "r"(xword));
        yword = (u32)dy << 16;
        asm("" : : "r"(yword));
        base = D_03004BBC;
        asm("" : : "r"(base));
        offset = selector * 136;
        address = (u32)base + 0x7C;
        asm("" : : "r"(offset), "r"(address));
        address = offset + address;
        frame.rate = *(s32 *)address;
        offset += (u32)base;
        actor = (struct Actor *)offset;
        asm("" : : "r"(actor));
        frame.duration = actor->duration;
        frame.movement_flags = actor->movement_flags;
        address = xword >> 16;
        frame.saved_dx = address;
        xword = (s32)xword >> 16;
        asm("" : : "r"(xword));
        offset = yword >> 16;
        frame.saved_dy = offset;
        yword = (s32)yword >> 16;
        asm("" : : "r"(yword));
        flags = (u16)func_080084D4(selector, xword, yword);
        asm("" : "+l"(flags));
    }
    if (flags & 0x2000)
    {
        if (!(D_02000000[4] & 2))
        {
            other_index = flags;
            {
                register u32 mask asm("r2") = 0xFF;
                asm("" : "+r"(other_index) : "r"(mask));
                other_index &= mask;
            }
            if (actor->type == 1)
            {
                other = &base[other_index];
                if (other->type == 1 && (*(u16 *)((u32)base + 0xE8)) == 0 &&
                    (actor->collision & 0x1000) == (other->collision & 0x1000))
                {
                    if (selector == 1)
                    {
                        flags = (u16)func_08008434(other_index, 0, 0);
                        {
                            register u16 *destination asm("r1") = D_0200000C;
                            register u32 mask asm("r3") = 0xFF;
                            asm("" : "+l"(flags) : "r"(destination), "r"(mask));
                            flags &= mask;
                            destination[0x10] = flags;
                        }
                        D_0200000C[0xF] = (*(u16 *)((u32)base + 0xE4));
                        func_08000BD8(1, selected_animation);
                        {
                            register u32 one asm("r0") = 1;
                            register u32 next asm("r1") = selected_animation;
                            next ^= one;
                            func_08000BD8(other_index, next);
                        }
                        (*(u16 *)((u32)base + 0xD2)) = 4;
                        {
                            register u16 *address asm("r0") = (u16 *)((u32)base + 0xE0);
                            asm("" : "+r"(address) : "r"(base));
                            *address = other_index;
                        }
                        other->relation = selector;
                        return;
                    }
                    if (other_index == 1 &&
                        (D_03004C8E == 0 || D_03004C8E == 2))
                    {
                        u16 *player_collision;
                        register u32 address asm("r2") = 0xE4;
                        asm("" : "+r"(address) : "r"(base));
                        address += (u32)base;
                        player_collision = (u16 *)address;
                        if (*(u16 *)address & 0x4000)
                            goto normal_collision;
                        flags = (u16)func_08008434(selector, 0, 0);
                        {
                            register u16 *destination asm("r1") = D_0200000C;
                            register u32 mask asm("r3") = 0xFF;
                            register u16 *saved asm("r2");
                            register u32 value asm("r0");
                            flags &= mask;
                            destination[0x10] = flags;
                            saved = player_collision;
                            value = *saved;
                            asm("" : "+r"(value) : "r"(saved), "r"(destination), "r"(mask), "l"(flags));
                            destination[0xF] = value;
                        }
                        func_08000BD8(selector, selected_animation);
                        {
                            register u32 one asm("r0") = 1;
                            register u32 next asm("r1") = selected_animation;
                            asm("" : "+r"(next), "+r"(one));
                            next ^= one;
                            func_08000BD8(1, next);
                        }
                        actor->relation = other_index;
                        (*(u16 *)((u32)base + 0xE0)) = selector;
                        {
                            register u32 value asm("r0") = 4;
                            register u16 *destination asm("r3") = &D_03004C8E;
                            asm("" : : "r"(value), "r"(destination), "r"(base));
                            *destination = value;
                        }
                        return;
                    }
                }
            }
        }
    }
normal_collision:
    if ((flags & 0x2000) && selector == 1)
    {
        register struct Actor *low_base asm("r2");
        register struct Actor *other_actor asm("r1");
        register u32 offset asm("r0");
        other_index = 0xFF;
        other_index &= flags;
        asm("" : "+r"(other_index) : "l"(flags));
        low_base = D_03004BBC;
        offset = other_index * 136;
        other_actor = (struct Actor *)(offset + (u32)low_base);
        asm("" : "+r"(other_actor) : "r"(low_base), "r"(offset));
        if (other_actor->type == 5)
        {
            register u16 *parent_counter asm("r4") = (u16 *)((u32)low_base + 0xE0);
            *parent_counter = other_index;
            {
                register u16 *address asm("r0") = &other_actor->relation;
                asm("" : "+r"(address) : "r"(other_actor));
                *address = selector;
            }
            {
                register u32 argument_0 asm("r0") = 1;
                register u32 argument_1 asm("r1") = selected_animation;
                asm("" : "+r"(argument_1) : "r"(argument_0), "r"(low_base));
                frame.saved_base = low_base;
                func_08000BD8(argument_0, argument_1);
            }
            {
                register u32 counter asm("r1") = *parent_counter;
                register u32 header asm("r1");
                u32 child;
                offset = counter * 136;
                low_base = frame.saved_base;
                header = (u32)low_base + 0x80;
                child = *(u32 *)(offset + header);
                asm("" : "+l"(child), "+r"(header) : "r"(low_base));
                if (!child)
                {
                    header += 0x52;
                    *(u16 *)header = 3;
                    return;
                }
                header = (u32)low_base + 0xD2;
                *(u16 *)header = 7;
                return;
            }
        }
    }
    if (selector == 1)
    {
        if ((flags & 0xC000) == 0xC000)
        {
            register u16 *coordinate_1 asm("r4");
            register u16 *coordinate_2 asm("r5");
            register u16 *coordinate_3 asm("r6");
            register void *callback asm("r8");
            func_08000BD8(1, selected_animation);
            coordinate_1 = &frame.coordinates[1];
            coordinate_2 = &frame.coordinates[2];
            coordinate_3 = &frame.coordinates[3];
            asm("" : "+r"(coordinate_1) : "r"(coordinate_2), "r"(coordinate_3));
            func_080083B8(flags, &frame.coordinates[0], coordinate_1, coordinate_2, coordinate_3);
            {
                register void *low_callback asm("r0") = func_0800BEC8;
                callback = low_callback;
                asm("" : "+r"(callback) : "r"(low_callback));
            }
            func_08001524(0, callback);
            func_08007188(frame.coordinates[0], *coordinate_1, *coordinate_2, *coordinate_3);
            func_080014A8(0, callback);
            return;
        }
        if (flags & 0x800)
        {
            func_0800990C();
            return;
        }
    }
    if (flags & 0xA000)
        goto initial_delay;
    if (flags & 0x4000)
    {
        {
            register u32 shifted asm("r1") = selector << 4;
            asm("" : "+r"(shifted));
            frame.index_shift = shifted;
        }
        if (selector == 1)
            goto player_state;
initial_delay:
        delay = func_08001080();
        {
            register struct Actor *low_base asm("r2") = D_03004BBC;
            delay_actor = (struct Actor *)(selector * 136 + (u32)low_base);
            asm("" : "+r"(delay_actor) : "r"(low_base), "r"(delay));
        }
        {
            register u32 mask asm("r2") = 0x1F;
            delay &= mask;
            asm("" : "+r"(delay) : "r"(mask), "r"(selector));
            delay += 10;
        }
        goto store_delay;
    }
    {
        register u32 shifted asm("r2") = selector << 4;
        register struct Actor *current asm("r1");
        register struct Actor *low_base asm("r0");
        asm("" : "+r"(shifted));
        frame.index_shift = shifted;
        if (selector == 1)
            goto player_state;
        low_base = D_03004BBC;
        current = (struct Actor *)((shifted + selector) * 8 + (u32)low_base);
        if (current->type != 1)
            goto after_npc;
        {
            register u16 *address asm("r0") = &current->collision;
            register u32 collision asm("r3") = *address;
            register u32 mask asm("r2");
            register u32 bits asm("r1");
            register u32 incoming asm("r0");
            asm("" : "+r"(collision) : "r"(address), "r"(current) : "r2");
            mask = 0x1000;
            bits = mask;
            asm("" : "+r"(bits) : "r"(collision), "r"(mask));
            bits &= collision;
            incoming = flags & mask;
            asm("" : "+r"(incoming) : "r"(bits), "r"(collision), "r"(mask));
            if (bits != incoming)
                goto npc_delay;
            if (collision == 6)
            {
                if (flags != 6)
                    goto npc_delay;
                goto after_npc;
            }
            if (flags != 6)
                goto after_npc;
        }
npc_delay:
        delay = func_08001080();
        {
            register struct Actor *low_base asm("r2") = D_03004BBC;
            register u32 shifted asm("r3") = frame.index_shift;
            delay_actor = (struct Actor *)((shifted + selector) * 8 + (u32)low_base);
            asm("" : "+r"(delay_actor) : "r"(low_base), "r"(shifted), "r"(delay));
        }
        {
            register u32 mask asm("r2") = 0x1F;
            delay &= mask;
            asm("" : "+r"(delay) : "r"(mask), "m"(frame.index_shift));
            delay += 10;
        }
        goto store_delay;
    }
after_npc:
    if (selector != 1)
        goto move_body;
player_state:
    {
        register struct Actor *low_base asm("r1") = D_03004BBC;
        register u32 shifted asm("r4") = frame.index_shift;
        register u32 address asm("r0") = (shifted + selector) * 8;
        asm("" : "+r"(address) : "r"(shifted), "r"(low_base));
        mover = (struct Actor *)(address + (u32)low_base);
        asm("" : "+r"(mover) : "r"(address), "r"(low_base));
    }
    {
        register u16 *address asm("r0") = &mover->type;
        player_type = *address;
        asm("" : "+r"(player_type) : "r"(address));
        if (player_type != 1)
            goto move_body;
        address -= 4;
        player_state_value = *address;
    }
    if (player_state_value)
        goto previous_state;
    if (flags != 6)
        goto move_body;
    {
        register u32 value asm("r0") = D_02000B5C;
        player_type &= value;
        asm("" : "+r"(player_type) : "r"(value));
    }
    if (player_type || mover->mode == 11)
    {
        func_080089A0(1, 150);
        func_080019EC(0x6E);
        goto move_body;
    }
    delay = func_08001080();
    {
        register u32 mask asm("r1") = 0x1F;
        delay &= mask;
        asm("" : "+r"(delay) : "r"(mask));
        delay += 10;
    }
    delay_actor = mover;
store_delay:
    asm("" : : "r"(delay), "r"(delay_actor));
    delay_actor->duration = delay;
    func_08000BD8(selector, selected_animation);
    return;
previous_state:
    if (player_state_value == 150 && !(flags & ~0xFF))
    {
        register u32 mask asm("r0") = 0xFF;
        register u32 selected_flags asm("r7") = flags & mask;
        asm("" : "+r"(selected_flags) : "r"(mask));
        if (selected_flags != 6)
        {
            func_080089A0(1, 0);
            func_080019EC(0x6E);
        }
    }
move_body:
    {
        register struct Actor *low_base asm("r2") = D_03004BBC;
        register u32 shifted asm("r0") = frame.index_shift;
        register u32 offset asm("r1");
        register u32 address asm("r0");
        asm("" : : "r"(low_base), "r"(shifted));
        offset = shifted + selector;
        asm("" : "+r"(offset) : "r"(shifted));
        offset *= 8;
        address = (u32)low_base + 0x74;
        asm("" : : "r"(offset), "r"(address));
        address = offset + address;
        frame.velocity_x = (s32 *)address;
        {
            register u32 raw asm("r3") = frame.saved_dx;
            register s32 value asm("r0");
            register s32 delta asm("r3");
            register s32 rate asm("r4");
            register s32 *destination asm("r4");
            asm("" : : "r"(raw));
            value = (s16)raw;
            frame.dx = value;
            rate = frame.rate;
            delta = value;
            asm("" : "+r"(delta) : "r"(value), "r"(rate));
            value = rate;
            asm("" : "+r"(value) : "r"(delta), "r"(low_base), "r"(offset));
            value *= delta;
            destination = frame.velocity_x;
            asm("" : "+r"(value) : "r"(destination));
            *destination = value;
        }
        address = (u32)low_base + 0x78;
        asm("" : : "r"(address), "r"(offset));
        address = offset + address;
        frame.velocity_y = (s32 *)address;
        {
            register u32 raw asm("r3") = frame.saved_dy;
            register s32 value asm("r0");
            register s32 delta asm("r3");
            register s32 rate asm("r4");
            register s32 *destination asm("r4");
            asm("" : : "r"(raw));
            value = (s16)raw;
            frame.dy = value;
            rate = frame.rate;
            delta = value;
            asm("" : "+r"(delta) : "r"(value), "r"(rate));
            value = rate;
            asm("" : "+r"(value) : "r"(delta), "r"(low_base), "r"(offset));
            value *= delta;
            destination = frame.velocity_y;
            asm("" : "+r"(value) : "r"(destination));
            *destination = value;
        }
        mover = (struct Actor *)(offset + (u32)low_base);
        asm("" : : "r"(mover));
    }
    {
        register u32 two asm("r5");
        register u16 *duration_address asm("r9");
        register u16 *counter_address asm("r8");
        register u32 half_duration asm("r7");
        {
            register u16 *address asm("r0") = &mover->relation;
            asm("" : "+r"(address) : : "r5");
            two = 2;
            *address = two;
        }
        {
            register u32 value asm("r0") = frame.duration - 1;
            register u32 address asm("r1") = 0x4C;
            asm("" : : "r"(address), "r"(value));
            address += (u32)mover;
            duration_address = (u16 *)address;
            asm("" : "+r"(duration_address) : "r"(address));
            *(u16 *)address = value;
        }
        {
            register u32 value asm("r2") = frame.duration;
            register u32 word asm("r0") = value >> 1;
            register u32 address asm("r3");
            half_duration = word - 1;
            asm("" : "+r"(half_duration) : "r"(value), "r"(word) : "r3");
            address = 0x58;
            asm("" : "+r"(address) : "r"(mover));
            address += (u32)mover;
            counter_address = (u16 *)address;
            asm("" : "+r"(counter_address) : "r"(address));
            *(u16 *)address = half_duration;
        }
        {
            register u16 *address asm("r1") = &mover->move_x;
            register u32 value asm("r0") = *address;
            register u32 delta asm("r2") = frame.saved_dx;
            asm("" : "+r"(value) : "r"(address), "r"(delta));
            *address = value + delta;
            address++;
            value = *address;
            {
                register u32 delta asm("r3") = frame.saved_dy;
                asm("" : "+r"(value) : "r"(address), "r"(delta));
                *address = value + delta;
            }
        }
        {
            register u32 current asm("r0") = *(u16 *)(mover->sprite + 0x30);
            register u32 next asm("r1") = selected_animation + 4;
            asm("" : "+r"(next) : "r"(current));
            if (current != next)
                func_08000BD8(selector, next);
        }
        if (frame.movement_flags & two)
        {
            register u32 delta asm("r1");
            register u32 product asm("r0");
            register u32 rate asm("r2");
            register s32 *destination asm("r3");
            *(u16 *)(mover->sprite + 0x38) = two;
            delta = frame.dx;
            product = delta << 1;
            rate = frame.rate;
            asm("" : "+r"(product) : "r"(delta), "r"(rate));
            product *= rate;
            destination = frame.velocity_x;
            asm("" : "+r"(product) : "r"(destination));
            *destination = product;
            {
                register u32 delta asm("r4") = frame.dy;
                register s32 *destination asm("r1");
                product = delta << 1;
                asm("" : "+r"(product) : "r"(delta), "r"(rate));
                product *= rate;
                destination = frame.velocity_y;
                asm("" : "+r"(product) : "r"(destination));
                *destination = product;
            }
            {
                register u16 *destination asm("r2") = duration_address;
                asm("" : : "r"(destination), "r"(half_duration));
                *destination = half_duration;
            }
            {
                register u32 duration asm("r3") = frame.duration;
                register u32 value asm("r0") = (duration >> 2) - 1;
                register u16 *destination asm("r4") = counter_address;
                asm("" : "+r"(value) : "r"(duration), "r"(destination));
                *destination = value;
            }
        }
        else if (mover->mode != 10)
            *(u16 *)(mover->sprite + 0x38) = 1;
    }
    if (selector == 1)
        func_08008274(D_03004BBC[1].velocity_x, D_03004BBC[1].velocity_y);
    {
        register struct Actor *low_base asm("r4") = D_03004BBC;
        register u32 shifted asm("r3") = frame.index_shift;
        register u32 offset asm("r2") = (shifted + selector) * 8;
        register u32 address asm("r3") = (u32)low_base + 8;
        register u32 velocity asm("r0");
        register u32 value asm("r1");
        address = offset + address;
        asm("" : "+r"(address) : "r"(offset), "r"(low_base));
        velocity = (u32)low_base + 0x74;
        velocity = offset + velocity;
        value = *(s32 *)address;
        velocity = *(s32 *)velocity;
        value += velocity;
        asm("" : "+r"(value) : "r"(velocity), "r"(address), "r"(offset));
        *(s32 *)address = value;
        address = (u32)low_base + 12;
        address = offset + address;
        asm("" : "+r"(address) : "r"(offset), "r"(low_base));
        velocity = (u32)low_base + 0x78;
        offset = offset + velocity;
        velocity = *(s32 *)address;
        value = *(s32 *)offset;
        *(s32 *)address = velocity + value;
    }
}
