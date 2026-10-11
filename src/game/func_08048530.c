#include "types.h"

struct AttachmentSet
{
    u8 types[18];
    u16 x[18];
    u16 y[18];
    u8 pad_5A[2];
    u32 flags[18];
    u16 values[18];
    u8 callbacks[18];
    u16 animations[18];
    u8 effects[18];
};
struct Definition
{
    u8 types[5];
    u8 pad;
    u16 x;
    u16 y;
    u16 special_x;
    u16 special_y;
    u16 pad_E;
};
extern u16 D_0200DA74;
extern u8 D_0200E28C, D_0200DA94, D_0200DA97, D_0200E24B;
extern u16 D_0200EB84;
extern const struct Definition D_086E5018[];
extern const struct AttachmentSet D_086D6FE8[], D_086E8DC0[];
extern const u8 D_086E88E4[][4];
struct Sprite {
    u16 flags, attr0, attr1, attr2;
    u8 pad_8[0x4C - 8];
    u16 flag_4C, id, zero, mode, value;
    u8 pad_56[8];
    u16 animation_high, animation_low, pad_62;
    u16 active, pad_66, pad_68, palette, effect;
    u8 pad_6E[0x84 - 0x6E];
    void (*callback)(void);
};
extern struct Sprite D_03004BBC[];
extern void (*D_086D45E0[])(void);
void *func_0805ED60(void *, const void *, u32);
u32 func_08045784(u32, u32);
u32 func_080457BC(u32, u32);
u32 func_08048014(u32, u32, u32);
s32 func_08048054(u32, s32, u32);
void func_08048320(u32, u32, u32, u32, u32, s32);
u32 func_08000BD8(u32, u32);

#define FIELD(index, offset) (*(u16 *)(D_03004BBC + (index) * 136 + (offset)))
#define CALLBACK(index) (D_03004BBC[(index)].callback)

void func_08048530(u8 *actor, u16 selected, u16 mode, u8 options)
{
    struct AttachmentSet set;
    register u32 kind asm("r8");
    register u32 y asm("r9");
    register u32 variant asm("r10");
    s32 saved_flags;
    u32 special;
    u32 side;
    u32 shifted_side;
    u32 flag_offset;
    u32 field_base;
    register u32 mirror_center asm("r0");
    register u32 index asm("r6");
    u32 x;
    register u32 doubled asm("r5");
    register struct Sprite *pool asm("r4");

    D_0200DA74 = 0x180;
    D_0200E28C = 0;
    {
        u32 masked = selected & 0x1000;
        asm("" : "+r"(masked));
        special = (u32)(-masked) >> 31;
    }
    selected &= 0xFFF;
    switch ((u8)(options & 0x10))
    {
    case 0:
        {
            register const struct Definition *base asm("r0") = D_086E5018;
            register u32 offset asm("r1") = selected << 4;
            register const struct Definition *definition asm("r4");
            register u32 chosen asm("r2");
            register const struct Definition *saved_base asm("r5");
            register u32 saved_offset asm("r3");
            asm("" : : "r"(base), "r"(offset));
            definition = (const struct Definition *)(offset + (u32)base);
            chosen = definition->types[4];
            saved_base = base;
            saved_offset = offset;
            asm("" : : "r"(chosen), "r"(saved_base), "r"(saved_offset));
            if (chosen && special)
            {
                register u32 copy asm("r4") = chosen;
                asm("" : : "r"(copy));
                variant = copy;
            }
            else
            {
                register u8 *source asm("r1") = actor;
                register u32 code asm("r0");
                asm("" : : "r"(source));
                code = source[3];
                asm("" : : "r"(code));
                if (code == 7)
                {
                    register const struct Definition *entry asm("r1");
                    register u32 chosen asm("r0");
                    asm("" : "+r"(saved_offset));
                    entry = (const struct Definition *)(saved_offset + (u32)saved_base);
                    asm("" : : "r"(entry));
                    chosen = entry->types[2];
                    asm("" : "+r"(chosen));
                    if (chosen)
                    {
                        register u32 copy asm("r1") = chosen;
                        asm("" : : "r"(copy));
                        variant = copy;
                        goto ordinary_variant_ready;
                    }
                }
                {
                    register const struct Definition *entry asm("r0");
                    asm("" : "+r"(saved_offset));
                    entry = (const struct Definition *)(saved_offset + (u32)saved_base);
                    asm("" : : "r"(entry));
                    variant = entry->types[0];
                }
            }
ordinary_variant_ready:
        }
        {
            register const struct AttachmentSet *source asm("r0") = D_086D6FE8;
            asm("" : : "r"(source));
            func_0805ED60(&set, (const void *)(variant * 272 + (u32)source), 272);
        }
        break;
    case 0x10:
        {
            register u8 *source asm("r3") = actor;
            register u32 code asm("r0");
            register const struct Definition *base asm("r5");
            register u32 offset asm("r3");
            asm("" : : "r"(source));
            code = source[3];
            asm("" : : "r"(code));
            base = D_086E5018;
            asm("" : : "r"(base));
            offset = selected << 4;
            asm("" : : "r"(offset));
            if (code == 7)
            {
                register const struct Definition *entry asm("r1") =
                    (const struct Definition *)(offset + (u32)base);
                register u32 chosen asm("r0");
                asm("" : : "r"(entry));
                chosen = entry->types[3];
                asm("" : "+r"(chosen));
                if (chosen)
                {
                    register u32 copy asm("r1") = chosen;
                    asm("" : : "r"(copy));
                    variant = copy;
                    goto alternate_variant_ready;
                }
            }
            {
                register const struct Definition *entry asm("r0") =
                    (const struct Definition *)(offset + (u32)base);
                asm("" : : "r"(entry));
                variant = entry->types[1];
            }
        }
alternate_variant_ready:
        if (D_0200DA94)
        {
            register const struct AttachmentSet *source asm("r0") = D_086E8DC0;
            asm("" : : "r"(source));
            func_0805ED60(&set, (const void *)(variant * 272 + (u32)source), 272);
        }
        else
        {
            register const struct AttachmentSet *source asm("r0") = D_086D6FE8;
            asm("" : : "r"(source));
            func_0805ED60(&set, (const void *)(variant * 272 + (u32)source), 272);
        }
        break;
    }
    if (!variant)
        return;
    index = 0;
    {
        u32 raw = options;
        asm("" : "+r"(raw));
        shifted_side = (raw & 0x10) << 24;
    }
    {
        register u32 selected_side asm("r2") = shifted_side >> 24;
        asm("" : : "r"(selected_side));
        side = selected_side;
    }
    do
    {
        asm("" : : : "r4", "r5", "r7");
        kind = set.types[index];
        if (!kind)
        {
            register u8 *base asm("r3") = &D_0200DA97;
            register u32 slot asm("r1");
            register u32 address asm("r0");
            register u32 zero asm("r2");
            register u32 sprite_base asm("r1");
            asm("" : : "r"(base));
            slot = *base + index;
            address = slot * 136;
            asm("" : : "r"(address));
            sprite_base = (u32)D_03004BBC;
            asm("" : : "r"(sprite_base));
            address += sprite_base;
            address += 0x64;
            asm("" : : "r"(address));
            zero = kind;
            asm("" : : "r"(zero));
            *(u16 *)address = zero;
            slot = *base + index;
            address = slot * 136;
            {
                register u32 pool_base asm("r3") = (u32)D_03004BBC;
                asm("" : : "r"(pool_base));
                address += pool_base;
                ((struct Sprite *)address)->flag_4C = zero;
                {
                    register u8 *source asm("r0") = &D_0200DA97;
                    asm("" : : "r"(source));
                    slot = *source + index;
                }
                address = slot * 136 + pool_base;
                ((struct Sprite *)address)->value = zero;
            }
            {
                register u8 *source asm("r2") = &D_0200DA97;
                register u32 callbacks asm("r3");
                register u32 value asm("r1");
                asm("" : : "r"(source));
                slot = *source + index;
                address = slot * 136;
                callbacks = (u32)&D_03004BBC[0].callback;
                asm("" : : "r"(callbacks));
                address += callbacks;
                value = kind;
                asm("" : : "r"(value));
                *(u32 *)address = value;
            }
        }
        else
        {
            register u32 *flag_pointer asm("r4");
            register u32 flags asm("r3");
            register u32 mask asm("r1");
            register u32 offset asm("r0") = index * 4;
            asm("" : : "r"(offset));
            {
                u32 *base = set.flags;
                register u32 *selected_base asm("r2");
                asm("" : : "r"(base) : "r1");
                field_base = (u32)base;
                selected_base = base;
                asm("" : : "r"(selected_base));
                flag_pointer = (u32 *)((u32)selected_base + offset);
                asm("" : : "r"(flag_pointer));
            }
            flags = *flag_pointer;
            mask = 4;
            asm("" : : "r"(flags), "r"(mask));
            mask &= flags;
            asm("" : "+r"(mask) : "r"(offset));
            flag_offset = offset;
            if (mask)
            {
                if (D_0200E24B)
                {
                    if ((u16)(variant - 138) > 2)
                    {
                        register u8 *source asm("r2") = actor;
                        register u32 value asm("r0");
                        register u32 offset asm("r4");
                        register const u16 *field asm("r1");
                        register u32 saved_x asm("r7");
                        register const struct Definition *definition asm("r2");
                        register const struct Definition *base asm("r1");
                        asm("" : : "r"(source));
                        value = func_08045784(*(u16 *)source, 6);
                        offset = index * 2;
                        asm("" : : "r"(offset));
                        field = set.x;
                        asm("" : "+r"(field));
                        field = (const u16 *)((u32)field + offset);
                        value = (value + *field) << 16;
                        saved_x = value >> 16;
                        asm("" : : "r"(saved_x));
                        {
                            register u8 *source asm("r3") = actor;
                            asm("" : : "r"(source));
                            value = func_080457BC(*(u16 *)source, 6);
                        }
                        field = set.y;
                        asm("" : "+r"(field));
                        field = (const u16 *)((u32)field + offset);
                        value = (value + *field) << 16;
                        asm("" : "+r"(value));
                        base = D_086E5018;
                        asm("" : : "r"(base));
                        definition = (const struct Definition *)((selected << 4) + (u32)base);
                        asm("" : : "r"(definition));
                        saved_x = (u16)(saved_x + definition->x);
                        asm("" : : "r"(saved_x));
                        value = (u16)((value >> 16) + definition->y);
                        y = value;
                        asm("" : "=r"(x) : "0"(saved_x));
                        doubled = offset;
                        asm("" : : "r"(doubled));
                    }
                    else
                    {
                        register s32 decision asm("r0") = variant;
                        asm("" : : "r"(decision));
                        if (decision == 139)
                            goto variant_139;
                        if (decision > 139)
                            goto variant_upper;
                        if (decision == 138)
                            goto variant_138;
                        doubled = index * 2;
                        asm("" : : "r"(doubled));
                        goto variant_coordinates_ready;
variant_upper:
                        {
                            register s32 upper asm("r1") = variant;
                            asm("" : : "r"(upper));
                            if (upper == 140)
                                goto variant_140;
                            doubled = index * 2;
                            asm("" : : "r"(doubled));
                            if (upper != 149)
                                goto variant_coordinates_ready;
                            x = 8;
                            {
                                register u32 vertical asm("r2") = 127;
                                asm("" : : "r"(vertical));
                                y = vertical;
                            }
                            goto variant_coordinates_ready;
                        }
variant_139:
                        x = 8;
                        {
                            register u32 vertical asm("r3") = 127;
                            asm("" : : "r"(vertical));
                            y = vertical;
                        }
                        doubled = index * 2;
                        asm("" : : "r"(doubled));
                        goto variant_coordinates_ready;
variant_138:
                        x = 8;
                        {
                            register u32 vertical asm("r0") = 127;
                            asm("" : : "r"(vertical));
                            y = vertical;
                        }
                        doubled = index * 2;
                        asm("" : : "r"(doubled));
                        goto variant_coordinates_ready;
variant_140:
                        x = 8;
                        {
                            register u32 vertical asm("r1") = 122;
                            asm("" : : "r"(vertical));
                            y = vertical;
                        }
                        doubled = index * 2;
                        asm("" : : "r"(doubled));
                        goto variant_coordinates_ready;
                    }
                }
                else
                {
                    register u8 *source asm("r2") = actor;
                    register u32 value asm("r0");
                    register u32 mode_byte asm("r4");
                    register const u16 *field asm("r1");
                    register u32 saved_x asm("r7");
                    register const struct Definition *definition asm("r2");
                    register const struct Definition *base asm("r2");
                    asm("" : : "r"(source));
                    value = *(u16 *)source;
                    asm("" : : "r"(value));
                    {
                        register u32 raw_mode asm("r3") = mode;
                        asm("" : : "r"(raw_mode));
                        mode_byte = raw_mode << 24;
                        asm("" : "+r"(mode_byte));
                        mode_byte >>= 24;
                        asm("" : : "r"(mode_byte));
                    }
                    value = func_08045784(value, mode_byte);
                    doubled = index * 2;
                    asm("" : : "r"(doubled));
                    field = set.x;
                    asm("" : "+r"(field));
                    field = (const u16 *)((u32)field + doubled);
                    value = (value + *field) << 16;
                    saved_x = value >> 16;
                    asm("" : : "r"(saved_x));
                    {
                        register u8 *source asm("r1") = actor;
                        asm("" : : "r"(source));
                        value = func_080457BC(*(u16 *)source, mode_byte);
                    }
                    field = set.y;
                    asm("" : "+r"(field));
                    field = (const u16 *)((u32)field + doubled);
                    value = (value + *field) << 16;
                    asm("" : "+r"(value));
                    base = D_086E5018;
                    asm("" : : "r"(base));
                    definition = (const struct Definition *)((selected << 4) + (u32)base);
                    asm("" : : "r"(definition));
                    saved_x = (u16)(saved_x + definition->x);
                    asm("" : : "r"(saved_x));
                    value = (u16)((value >> 16) + definition->y);
                    y = value;
                    {
                        register u32 is_special asm("r3") = special;
                        asm("" : : "r"(is_special));
                        if (is_special)
                        {
                            value = definition->special_x;
                            asm("" : : "r"(value));
                            saved_x = (u16)(saved_x + value);
                            asm("" : : "r"(saved_x));
                            value = definition->special_y;
                            asm("" : : "r"(value));
                            y = (u16)(value + y);
                        }
                    }
                    asm("" : "=r"(x) : "0"(saved_x));
                }
variant_coordinates_ready:
                {
                    register u32 selected_kind asm("r0") = kind;
                    asm("" : : "r"(selected_kind), "r"(doubled));
                    if (selected_kind == 46)
                    {
                        register const u16 *field asm("r0") = set.x;
                        register u32 horizontal asm("r7");
                        asm("" : "+r"(field));
                        field = (const u16 *)((u32)field + doubled);
                        horizontal = *field;
                        asm("" : : "r"(horizontal));
                        asm("" : "=r"(x) : "0"(horizontal));
                        field = set.y;
                        asm("" : "+r"(field));
                        field = (const u16 *)((u32)field + doubled);
                        y = *field;
                    }
                }
                {
                    register u32 mask asm("r0") = 0x20;
                    register u32 raw asm("r1") = options;
                    asm("" : : "r"(mask), "r"(raw));
                    mask = (u8)(mask & raw);
                    asm("" : "+r"(mask));
                    if (!mask)
                        goto attachment_coordinates_ready;
                    if (mask != 0x20)
                        goto attachment_coordinates_ready;
                    mirror_center = 128;
                    goto mirror_coordinates;
                }
            }
            else
            {
                {
                    register u32 offset asm("r1") = index * 2;
                    register const u16 *field asm("r0") = set.x;
                    register u32 horizontal asm("r7");
                    register u32 mask asm("r0");
                    asm("" : : "r"(offset));
                    asm("" : "+r"(field));
                    field = (const u16 *)((u32)field + offset);
                    horizontal = *field;
                    asm("" : : "r"(horizontal));
                    asm("" : "=r"(x) : "0"(horizontal));
                    field = set.y;
                    asm("" : "+r"(field));
                    field = (const u16 *)((u32)field + offset);
                    y = *field;
                    mask = 0x4000;
                    asm("" : : "r"(mask));
                    flags &= mask;
                    asm("" : "+r"(flags));
                    doubled = offset;
                    asm("" : : "r"(doubled));
                    if (flags)
                        x = (u16)func_08048014(x, 64, D_086E88E4[*(u16 *)actor][0]);
                }
                if (*flag_pointer & 0x8000)
                {
                    register const u8 (*base)[4] asm("r1") = D_086E88E4;
                    asm("" : : "r"(base));
                    y = (u16)func_08048054(y, 64, base[*(u16 *)actor][1]);
                }
                {
                    register u32 mask asm("r0") = 0x20;
                    register u32 raw asm("r1") = options;
                    asm("" : : "r"(mask), "r"(raw));
                    mask = (u8)(mask & raw);
                    asm("" : "+r"(mask));
                    if (!mask)
                        goto absolute_side;
                    if (mask != 0x20)
                        goto attachment_coordinates_ready;
                    {
                        register u32 selected_side asm("r2") = side;
                        asm("" : : "r"(selected_side));
                        if (selected_side)
                            goto attachment_coordinates_ready;
                    }
                    mirror_center = 240;
                    goto mirror_coordinates;
absolute_side:
                    {
                        register u32 shifted asm("r3") = shifted_side;
                        register u32 selected_side asm("r0");
                        asm("" : : "r"(shifted));
                        selected_side = shifted >> 24;
                        asm("" : : "r"(selected_side));
                        if (!selected_side)
                            goto attachment_coordinates_ready;
                        if (selected_side != 16)
                            goto attachment_coordinates_ready;
                    }
                    mirror_center = 224;
                }
mirror_coordinates:
                x = (u16)(mirror_center - x);
            }
attachment_coordinates_ready:
            {
                saved_flags = *(u32 *)(field_base + flag_offset);
                asm("" : : "r"(x));
            }
            {
                register u32 selected_index asm("r1") = (u8)index;
                register u32 selected_kind asm("r2") = kind;
                register u32 selected_y asm("r0") = y;
                asm("" : : "r"(selected_index), "r"(selected_kind), "r"(selected_y));
                func_08048320((u32)actor, selected_index, selected_kind, x, selected_y, ({ register s32 argument asm("r3") = saved_flags; asm("" : "+r"(argument)); argument; }));
                asm("" : : "r"(doubled) : "r4", "r7");
            }
            if (D_0200E24B)
            {
                register u8 *base asm("r0") = &D_0200DA97;
                register u32 slot asm("r1");
                register struct Sprite *entry asm("r0");
                register u32 sprite_base asm("r1");
                register u32 attributes asm("r1");
                register u32 mask asm("r3");
                asm("" : : "r"(base));
                slot = *base + index;
                entry = (struct Sprite *)(slot * 136);
                asm("" : : "r"(entry));
                sprite_base = (u32)D_03004BBC;
                asm("" : : "r"(sprite_base));
                entry = (struct Sprite *)((u32)entry + sprite_base);
                attributes = entry->attr2;
                asm("" : : "r"(attributes));
                mask = 0xF3FF;
                asm("" : : "r"(mask));
                {
                    register u32 applied asm("r2") = mask;
                    asm("" : : "r"(applied));
                    entry->attr2 = attributes & applied;
                }
                {
                    register u8 *base asm("r1") = &D_0200DA97;
                    register u32 slot asm("r0");
                    register struct Sprite *entry asm("r1");
                    register u32 sprite_base asm("r2");
                    register u32 attributes asm("r2");
                    register u32 mask asm("r3");
                    register u32 applied asm("r0");
                    asm("" : : "r"(base));
                    slot = *base + index;
                    entry = (struct Sprite *)(slot * 136);
                    asm("" : : "r"(entry));
                    sprite_base = (u32)D_03004BBC;
                    asm("" : : "r"(sprite_base));
                    entry = (struct Sprite *)((u32)entry + sprite_base);
                    attributes = entry->attr2;
                    asm("" : : "r"(attributes));
                    mask = 0x800;
                    asm("" : : "r"(mask));
                    applied = mask;
                    asm("" : : "r"(applied));
                    entry->attr2 = applied | attributes;
                }
            }
            {
                register u32 mask asm("r0") = 0x20;
                register u32 raw asm("r1") = options;
                register struct Sprite *entry asm("r1");
                register u8 *base asm("r2");
                asm("" : : "r"(mask), "r"(raw));
                mask = (u8)(mask & raw);
                asm("" : "+r"(mask));
                if (!mask)
                    goto plain_attachment_flags;
                base = &D_0200DA97;
                kind = (u32)base;
                asm("" : : "r"(base), "r"(kind));
                if (mask != 0x20)
                    goto attachment_fields_ready;
                {
                    register u32 selected_side asm("r3") = side;
                    asm("" : : "r"(selected_side));
                    if (selected_side)
                        goto attachment_fields_ready;
                }
                {
                    register u8 *source asm("r1") = base;
                    register u32 slot asm("r0");
                    register u32 sprite_base asm("r2");
                    asm("" : : "r"(source));
                    slot = *source + index;
                    entry = (struct Sprite *)(slot * 136);
                    asm("" : : "r"(entry));
                    sprite_base = (u32)D_03004BBC;
                    asm("" : : "r"(sprite_base));
                    entry = (struct Sprite *)((u32)entry + sprite_base);
                    goto set_attachment_flag;
                }
plain_attachment_flags:
                {
                    register u32 shifted asm("r1") = shifted_side;
                    register u32 selected_side asm("r0");
                    register u8 *source asm("r3");
                    register u32 slot asm("r0");
                    register u32 sprite_base asm("r0");
                    asm("" : : "r"(shifted));
                    selected_side = shifted >> 24;
                    asm("" : : "r"(selected_side));
                    base = &D_0200DA97;
                    kind = (u32)base;
                    asm("" : : "r"(base), "r"(kind));
                    if (!selected_side)
                        goto attachment_fields_ready;
                    if (selected_side != 0x10)
                        goto attachment_fields_ready;
                    source = base;
                    asm("" : : "r"(source));
                    slot = *source + index;
                    entry = (struct Sprite *)(slot * 136);
                    asm("" : : "r"(entry));
                    sprite_base = (u32)D_03004BBC;
                    asm("" : : "r"(sprite_base));
                    entry = (struct Sprite *)((u32)entry + sprite_base);
                }
set_attachment_flag:
                {
                    register u32 attributes asm("r2") = entry->flags;
                    register u32 mask asm("r3") = 0x100;
                    register u32 applied asm("r0");
                    asm("" : : "r"(attributes), "r"(mask));
                    applied = mask;
                    asm("" : : "r"(applied));
                    entry->flags = applied | attributes;
                }
            }
attachment_fields_ready:
            {
                register u8 *base asm("r0") = (u8 *)kind;
                register u32 slot asm("r1");
                register u32 address asm("r0");
                register u32 sprite_base asm("r1");
                register u32 one asm("r3");
                register u32 bits asm("r2");
                register u32 mask asm("r0");
                asm("" : : "r"(base));
                slot = *base + index;
                address = slot * 136;
                asm("" : : "r"(address));
                sprite_base = (u32)D_03004BBC;
                asm("" : : "r"(sprite_base));
                address += sprite_base;
                address += 0x64;
                asm("" : : "r"(address));
                one = 1;
                asm("" : : "r"(one));
                *(u16 *)address = one;
                bits = saved_flags;
                mask = 0x10;
                asm("" : : "r"(bits), "r"(mask));
                bits &= mask;
                asm("" : "+r"(bits));
                if (bits)
                {
                    register u8 *base asm("r2") = (u8 *)kind;
                    register u32 slot asm("r1");
                    register u32 address asm("r0");
                    register u32 sprite_base asm("r1");
                    asm("" : : "r"(base));
                    slot = *base + index;
                    address = slot * 136;
                    asm("" : : "r"(address));
                    sprite_base = (u32)D_03004BBC;
                    asm("" : : "r"(sprite_base));
                    address += sprite_base;
                    address += 0x4C;
                    asm("" : : "r"(address));
                    *(u16 *)address = one;
                }
                else
                {
                    register u8 *base asm("r3") = (u8 *)kind;
                    register u32 slot asm("r1");
                    register u32 address asm("r0");
                    register u32 sprite_base asm("r1");
                    asm("" : : "r"(base));
                    slot = *base + index;
                    address = slot * 136;
                    asm("" : : "r"(address));
                    sprite_base = (u32)D_03004BBC;
                    asm("" : : "r"(sprite_base));
                    address += sprite_base;
                    address += 0x4C;
                    asm("" : : "r"(address));
                    *(u16 *)address = bits;
                }
            }
            {
                register u8 *base asm("r3");
                register u32 slot asm("r1");
                register u32 address asm("r0");
                register u32 zero asm("r2");
                pool = D_03004BBC;
                asm("" : : "r"(pool));
                base = (u8 *)kind;
                asm("" : : "r"(base));
                slot = *base + index;
                address = slot * 136 + (u32)pool;
                address += 0x4E;
                asm("" : : "r"(address));
                zero = 0;
                asm("" : : "r"(zero));
                *(u16 *)address = slot;
                slot = *base + index;
                address = slot * 136 + (u32)pool;
                *(u16 *)(address + 0x50) = zero;
                {
                    register u32 slot asm("r0") = *base + index;
                    register u32 address asm("r1");
                    register u32 mask asm("r0");
                    register u32 bits asm("r2");
                    address = slot * 136 + (u32)pool;
                    asm("" : : "r"(address));
                    mask = 0x1F00;
                    bits = saved_flags;
                    asm("" : : "r"(mask), "r"(bits));
                    mask = (mask & bits) >> 8;
                    *(u16 *)(address + 0x52) = mask;
                }
                {
                    register u32 slot asm("r0") = *base + index;
                    register u32 address asm("r1");
                    register const u16 *value asm("r0");
                    address = slot * 136 + (u32)pool;
                    asm("" : : "r"(address));
                    value = set.values;
                    asm("" : "+r"(value));
                    value = (const u16 *)((u32)value + doubled);
                    {
                        register u32 loaded asm("r0") = *value;
                        asm("" : : "r"(loaded));
                        *(u16 *)(address + 0x54) = loaded;
                    }
                }
                {
                    register u32 slot asm("r0") = *base + index;
                    register u32 address asm("r1");
                    register const u16 *animation asm("r2");
                    register u32 value asm("r0");
                    address = slot * 136 + (u32)pool;
                    asm("" : : "r"(address));
                    animation = set.animations;
                    asm("" : "+r"(animation));
                    animation = (const u16 *)((u32)animation + doubled);
                    value = *animation >> 8;
                    *(u16 *)(address + 0x5E) = value;
                    {
                        register u32 slot asm("r1") = *base + index;
                        register u32 address asm("r0");
                        register u32 value asm("r1");
                        address = slot * 136 + (u32)pool;
                        asm("" : : "r"(address));
                        value = *(u8 *)animation;
                        *(u16 *)(address + 0x60) = value;
                    }
                }
                if (!(D_0200EB84 & 0x10))
                {
                    register u32 slot asm("r0") = *base + index;
                    register u32 address asm("r1");
                    register const u8 *value asm("r0");
                    address = slot * 136 + (u32)pool;
                    asm("" : : "r"(address));
                    value = set.effects;
                    asm("" : "+r"(value));
                    value += index;
                    {
                        register u32 loaded asm("r0") = *value;
                        asm("" : : "r"(loaded));
                        *(u16 *)(address + 0x6C) = loaded;
                    }
                }
                {
                    register u32 raw_slot asm("r0") = *base;
                    register u32 slot asm("r2");
                    register struct Sprite *entry asm("r0");
                    register const u16 *animation asm("r1");
                    u32 value;
                    asm("" : : "r"(raw_slot));
                    slot = raw_slot + index;
                    asm("" : : "r"(slot));
                    entry = (struct Sprite *)(slot * 136 + (u32)pool);
                    asm("" : : "r"(entry));
                    animation = &entry->animation_low;
                    asm("" : : "r"(animation));
                    {
                        register u32 loaded asm("r0") = *animation;
                        asm("" : "=r"(value) : "0"(loaded));
                    }
                    if (value)
                    {
                        register u32 selected_animation asm("r1");
                        asm volatile("" : "=r"(selected_animation) : "0"(value));
                        func_08000BD8(slot, selected_animation);
                    }
                }
            }
            {
                register u8 *base asm("r3") = (u8 *)kind;
                register u32 slot asm("r0");
                register u32 address asm("r1");
                register u32 sprite_base asm("r0");
                register u32 bits asm("r3");
                register u32 palette asm("r2");
                register u32 mask asm("r0");
                asm("" : : "r"(base));
                slot = *base + index;
                address = slot * 136;
                asm("" : : "r"(address));
                sprite_base = (u32)D_03004BBC;
                asm("" : : "r"(sprite_base));
                address += sprite_base;
                bits = saved_flags;
                asm("" : : "r"(bits));
                palette = bits >> 16;
                mask = 15;
                asm("" : : "r"(palette), "r"(mask));
                palette &= mask;
                *(u16 *)(address + 0x6A) = palette;
                {
                    register u8 *base asm("r1") = (u8 *)kind;
                    register u32 slot asm("r0");
                    register u32 address asm("r1");
                    register u32 callbacks asm("r2");
                    register const u8 *selected asm("r0");
                    asm("" : : "r"(base));
                    slot = *base + index;
                    address = slot * 136;
                    asm("" : : "r"(address));
                    callbacks = (u32)&D_03004BBC[0].callback;
                    asm("" : : "r"(callbacks));
                    address += callbacks;
                    callbacks = (u32)D_086D45E0;
                    asm("" : : "r"(callbacks));
                    selected = set.callbacks;
                    asm("" : "+r"(selected));
                    selected += index;
                    *(u32 *)address = *(u32 *)(*selected * 4 + callbacks);
                }
            }
        }
        {
            register u32 next asm("r0") = index + 1;
            asm("" : : "r"(next));
            index = (u16)next;
        }
    } while (index <= 17);
}
