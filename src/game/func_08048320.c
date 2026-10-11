#include "types.h"

struct Sprite
{
    u16 flags;
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u32 x;
    u32 y;
    u8 pad_10[4];
    const u16 **animations;
    const void **frames;
    u16 tile_offset;
    u8 pad_1E[0x5A];
    u32 start_x;
    u32 start_y;
    u8 pad_80[8];
};

struct Definition
{
    const u32 *graphics;
    const u32 *palette;
    const u16 **animations;
    const void **frames;
};

extern struct Sprite D_03004BBC[];
extern u16 D_0200DA74;
extern u8 D_0200DA97;
extern u8 D_0200E28C;
extern u16 D_02007574[];
extern const struct Definition D_086F7FD0[];
void func_0805EDC0(void *, u32, u32);
void func_08001A54(u32 *, u16, u16);
void func_08000CEC(u32, const struct Sprite *, u32);

#define HAS_FLAG(flag) \
    ({ register u32 mask asm("r0") = (flag); \
       register u32 value asm("r4") = bits; \
       asm("" : : "r"(mask), "r"(value)); \
       mask & value; })

#define ADD_FIELD_FLAG(field, flag) \
    { register u32 attributes asm("r1") = (field); \
      register u32 mask asm("r2") = (flag); \
      register u32 value asm("r0"); \
      asm("" : : "r"(attributes), "r"(mask)); \
      value = mask; \
      asm("" : : "r"(value)); \
      (field) = value | attributes; }

void func_08048320(u32 unused, u32 selected, u32 kind, u32 x, u32 y, s32 flags)
{
    register s32 bits asm("r8");
    register u32 counter asm("r9");
    register u32 initial asm("r10");
    register u32 offset asm("r6");
    u32 saved_selected;
    u32 saved_x;
    u32 saved_y;
    u32 transfer[3];
    struct Sprite template;
    struct Sprite *sprite;

    {
        register u32 raw_y asm("r0") = y;
        register s32 raw_flags asm("r4") = flags;
        register u32 argument asm("r1") = selected;
        register u32 type asm("r2") = kind;
        register u32 raw_x asm("r3") = x;
        asm("" : : "r"(raw_y), "r"(raw_flags));
        bits = raw_flags;
        asm("" : : "r"(bits));
        asm("" : "+r"(argument));
        saved_selected = (u8)argument;
        asm("" : "+r"(type));
        offset = (u8)type;
        asm("" : : "r"(offset));
        asm("" : "+r"(raw_x));
        saved_x = (u16)raw_x;
        asm("" : "+r"(raw_y));
        saved_y = (u16)raw_y;
    }
    {
        register struct Sprite *cleared asm("r4") = &template;
        register u16 *base asm("r0");
        register u32 loaded asm("r1");
        asm("" : : "r"(cleared));
        func_0805EDC0(cleared, 0, 136);
        cleared->flags = 0x1001;
        base = &D_0200DA74;
        counter = (u32)base;
        asm("" : : "r"(base), "r"(counter));
        loaded = *base;
        asm("" : : "r"(loaded));
        initial = loaded;
        sprite = cleared;
        asm("" : "+l"(sprite) : : "r4");
    }
    {
        register s32 test asm("r2") = bits;
        asm("" : : "r"(test));
    if (test < 0)
    {
        register struct Sprite *pool asm("r5") = D_03004BBC;
        register u32 parent asm("r2") = 0x7C000000;
        register u32 raw_bits asm("r4") = bits;
        register u8 *base asm("r3");
        register u32 index asm("r1");
        register struct Sprite *field asm("r0");
        register u32 attributes asm("r4");
        asm("" : : "r"(pool), "r"(parent), "r"(raw_bits));
        parent = (parent & raw_bits) >> 26;
        base = &D_0200DA97;
        index = *base;
        index = parent + index;
        asm("" : : "r"(index));
        field = (struct Sprite *)(index * 136 + (u32)pool);
        asm("" : : "r"(field));
        index = field->tile_offset;
        asm("" : : "r"(index));
        counter = index;
        initial = counter;
        attributes = field->attr2;
        asm("" : : "r"(attributes));
        sprite->attr2 = attributes;
        {
            register u32 selected asm("r0") = *base;
            asm("" : : "r"(selected));
            parent += selected;
        }
        field = (struct Sprite *)(parent * 136 + (u32)pool);
        asm("" : : "r"(field));
        index = field->attr2;
        {
            register u32 mask asm("r0") = 0xF000;
            asm("" : : "r"(mask), "r"(index));
            mask = (mask & index) | attributes;
            sprite->attr2 = mask;
        }
        offset <<= 4;
    }
    else
    {
        register u8 *base asm("r4") = (u8 *)D_086F7FD0;
        register const struct Definition *definition asm("r5");
        asm("" : : "r"(base));
        offset <<= 4;
        definition = (const struct Definition *)(offset + (u32)base);
        asm("" : : "r"(definition));
        transfer[0] = (u32)definition->graphics;
        {
            register u32 tiles asm("r2") = initial;
            register u32 destination asm("r0");
            register u32 vram asm("r1");
            asm("" : : "r"(tiles));
            destination = tiles * 32;
            asm("" : : "r"(destination));
            vram = 0x06010000;
            asm("" : : "r"(vram));
            transfer[1] = destination + vram;
        }
        func_08001A54(transfer, 0, 1);
        {
            register u32 length asm("r0") = *definition->graphics >> 13;
            register u16 *old asm("r2");
            register u32 previous asm("r2");
            asm("" : : "r"(length));
            old = (u16 *)counter;
            asm("" : : "r"(old));
            previous = *old;
            asm("" : : "r"(previous));
            counter = (u16)(length + previous);
        }
        base += 4;
        asm("" : : "r"(base));
        base = (u8 *)(offset + (u32)base);
        transfer[0] = *(u32 *)base;
        transfer[1] = 0x05000260 + D_0200E28C * 32;
        func_08001A54(transfer, 0, 1);
        sprite->attr2 |= (D_0200E28C + 3) << 12;
        D_0200E28C++;
    }
    }
    {
        register u32 attributes asm("r1");
        register u32 priority asm("r0");
        if (D_02007574[7] != 2)
        {
            attributes = sprite->attr2;
            priority = 0x800;
            asm("" : : "r"(attributes), "r"(priority));
        }
        else
        {
            register u32 mask asm("r2");
            attributes = sprite->attr2;
            mask = 0xC00;
            asm("" : : "r"(attributes), "r"(mask));
            priority = mask;
        }
        asm("" : : "r"(attributes), "r"(priority));
        sprite->attr2 = priority | attributes;
    }
    if (HAS_FLAG(8))
        ADD_FIELD_FLAG(sprite->attr0, 0x400);
    if (HAS_FLAG(1))
        ADD_FIELD_FLAG(sprite->flags, 0x800);
    if (!HAS_FLAG(2))
        ADD_FIELD_FLAG(sprite->flags, 0x400);
    if (HAS_FLAG(4))
        ADD_FIELD_FLAG(sprite->flags, 0x1000)
    else
        sprite->flags &= 0xEFFF;
    {
        register u32 mask asm("r0") = 0x100000;
        u32 special = bits;
        asm("" : "+l"(special) : "r"(mask) : "r1", "r2", "r3");
        special &= mask;
        asm("" : "+l"(special) : : "r0", "r1", "r2", "r3");
    if (special)
    {
        register u32 attributes asm("r0") = sprite->attr2;
        register u32 mask asm("r1") = 0xF3FF;
        register u32 priority asm("r2");
        register u32 bits asm("r0");
        asm("" : : "r"(attributes), "r"(mask));
        mask &= attributes;
        asm("" : : "r"(mask));
        priority = 0xC00;
        asm("" : : "r"(priority));
        bits = priority;
        asm("" : : "r"(bits));
        mask |= bits;
        sprite->attr2 = mask;
    }
    }
    {
        register struct Sprite *destination asm("r2") = sprite;
        register u32 raw_x asm("r4") = saved_x;
        register u32 raw_y asm("r1");
        register u32 shifted asm("r0");
        register u8 *base asm("r1");
        register u8 *field asm("r0");
        register u32 tiles asm("r4");
        asm("" : : "r"(destination), "r"(raw_x));
        shifted = raw_x << 16;
        asm("" : : "r"(shifted));
        destination->start_x = shifted;
        destination->x = shifted;
        raw_y = saved_y;
        asm("" : : "r"(raw_y));
        shifted = raw_y << 16;
        asm("" : : "r"(shifted));
        destination->start_y = shifted;
        destination->y = shifted;
        base = (u8 *)D_086F7FD0;
        asm("" : : "r"(base));
        field = base + 8;
        asm("" : : "r"(field));
        field = (u8 *)(offset + (u32)field);
        destination->animations = *(const u16 ***)field;
        base += 12;
        asm("" : : "r"(base));
        base = (u8 *)(offset + (u32)base);
        destination->frames = *(const void ***)base;
        tiles = initial;
        asm("" : : "r"(tiles));
        destination->tile_offset = tiles;
    }
    if (counter > D_0200DA74)
    {
        register u32 updated asm("r2") = counter;
        asm("" : : "r"(updated));
        D_0200DA74 = updated;
    }
    {
        register u32 base asm("r0") = D_0200DA97;
        register u32 selected asm("r4") = saved_selected;
        asm("" : : "r"(base), "r"(selected));
        func_08000CEC(base + selected, sprite, 0);
    }
}
