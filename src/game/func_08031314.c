#include "types.h"

struct Unit
{
    u8 pad_0[0x42];
    u8 pilot;
    u8 pad_43[0x281];
    u32 hp;
    u32 energy;
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Zoid
{
    u8 pad_0[0x28];
    u32 max_hp;
    u32 max_energy;
    u8 pad_30[8];
};

struct Member
{
    u8 zoid;
    u8 pilot;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[180];
    u8 pad_348C[0x174];
    struct Member members[7];
} D_02000B5C;

extern struct
{
    u8 pad_0[8];
    struct Side sides[2];
} D_0200EB84;

extern u16 D_0300239C[];
extern const u16 D_0866B6DE[4][6];

s32 func_080312DC(u32 value, u32 kind);
s32 func_08032A88(u32, u32);
u8 func_08031534(u32 value, u32 max, u16 *out, u16 base);
void func_0805D270(const void *, void *, u32);
void func_08032384(s32);

u32 func_08031314(u32 index, u32 member, u32 flags, u32 kind)
{
    u16 gauge[6];
    register u32 member_value asm("r5");
    register u32 kind_value asm("r1");
    register u32 flag_value asm("r2");
    register u32 held0 asm("r0");
    volatile u32 saved_flags;
    volatile u32 result;
    s32 position;
    register u32 i asm("r4");
    register u32 j asm("r2");
    register u32 tile_seed asm("r12");
    register u32 row_position asm("r0");
    register u32 source_offset asm("r1");
    register u32 second_row asm("r9");
    register u32 map_address asm("r10");
    register u32 template_address asm("r8");
    volatile u32 member_offset;
    register u32 empty asm("r6");

    asm volatile("" : : "r"(index));
    member_value = member;
    kind_value = kind;
    flag_value = flags;
    asm("" : : "r"(index), "r"(member_value), "r"(kind_value), "r"(flag_value));
    {
        register u32 width_value asm("r4") = index;
        asm("" : "+r"(width_value));
        width_value = (u8)width_value;
        asm("" : : "r"(width_value));
        index = width_value;
    }
    member_value = (u8)member_value;
    asm("" : "=r"(held0));
    flag_value = (u8)flag_value;
    asm("" : : "r"(flag_value), "r"(held0));
    saved_flags = flag_value;
    asm volatile("" : "+r"(kind_value) : "m"(saved_flags), "r"(held0));
    kind_value = (u8)kind_value;
    asm("" : : "r"(kind_value), "r"(held0));
    result = 0;
    position = func_080312DC(index, kind_value);
    asm("" : : "r"(index), "r"(member_value));
    asm volatile("" : "+r"(position));
    row_position = 0;
    j = 0;
    asm("" : : "r"(row_position), "r"(j));
    tile_seed = index * 8;
    {
        register u32 row_offset asm("r1") = 32;
        asm("" : "+r"(row_offset));
        row_offset += position;
        asm("" : : "r"(row_offset));
        second_row = row_offset;
        asm("" : : "r"(second_row));
    }
    member_value *= 4;
    asm("" : : "r"(member_value));
    member_offset = member_value;
    {
        register u32 loaded_map asm("r3") = (u32)D_0300239C;
        asm("" : : "r"(loaded_map));
        map_address = loaded_map;
        asm("" : "+r"(map_address) : "r"(loaded_map));
    }
    {
        register u32 loaded_template asm("r6") = (u32)D_0866B6DE;
        asm("" : : "r"(loaded_template));
        template_address = loaded_template;
        asm("" : "+r"(template_address) : "r"(loaded_template));
    }
    source_offset = 0;
    asm("" : : "r"(row_position), "r"(source_offset));
    asm volatile("" : "+r"(tile_seed), "+r"(second_row) : "r"(map_address), "r"(template_address));
    do
    {
        volatile u32 next_row;
        register u32 next_j asm("r5");
        const u16 *source;
        u16 *destination;
        i = 0;
        next_row = row_position + 32;
        next_j = j + 1;
        row_position += position;
        asm("" : : "r"(row_position), "r"(j), "r"(next_j), "r"(source_offset), "r"(i));
        source = (const u16 *)(source_offset - (0u - template_address));
        asm("" : : "r"(j), "r"(next_j), "r"(source));
        row_position *= 2;
        destination = (u16 *)(row_position - (0u - map_address));
        do
        {
            *destination = *source++;
            source_offset += 2;
            destination++;
            i++;
        } while (i <= 5);
        row_position = next_row;
        j = next_j;
        asm("" : : "r"(map_address), "r"(template_address), "r"(tile_seed), "r"(second_row));
    } while (j <= 3);
    asm volatile("" : "+r"(position), "+r"(second_row), "+r"(tile_seed));
    {
        register u32 tile asm("r2") = tile_seed;
        register u32 overlay_map asm("r0");
        register u32 first_value asm("r5");
        register u32 second_value asm("r6");
        u16 *first;
        u16 *second;
        asm("" : : "r"(tile));
        i = 1;
        asm("" : : "r"(i));
        overlay_map = (u32)D_0300239C;
        asm("" : : "r"(overlay_map));
        {
            register u32 value asm("r1") = 0xF000;
            asm("" : "+r"(value));
            first_value = value;
            asm("" : "+r"(first_value) : "r"(value));
        }
        {
            register u32 row asm("r3") = second_row;
            register u32 offset asm("r1");
            asm("" : : "r"(row));
            offset = row * 2;
            asm("" : "+r"(offset));
            offset += overlay_map;
            asm("" : "+r"(offset));
            second = (u16 *)(offset + 2);
        }
        {
            register u32 address asm("r1") = position * 2;
            asm("" : "+r"(address));
            address += overlay_map;
            asm("" : "+r"(address));
            address += 2;
            asm("" : : "r"(address));
            first = (u16 *)address;
            asm("" : "+r"(first) : "r"(address));
        }
        {
            register u32 value asm("r0") = 0xF001;
            asm("" : : "r"(value));
            second_value = value;
            asm("" : "+r"(second_value) : "r"(value));
        }
        do
        {
            *first = tile + first_value;
            *second = tile + second_value;
            tile += 2;
            second++;
            first++;
            i++;
        } while (i <= 4);
    }
    asm volatile("" : "+r"(position) : : "r4", "r5", "r6", "r8", "r9", "r10");
    {
        register u32 base asm("r0");
        register u32 held0 asm("r0");
        register u32 offset asm("r1");
        register u32 field asm("r2");
        register u32 held5 asm("r5");
        u8 *pilot;
        const u8 *battle;
        asm("" : "=r"(held0));
        i = 0;
        asm("" : : "r"(i), "r"(held0));
        base = (u32)&D_02000B5C;
        asm("" : "+r"(base));
        offset = member_offset;
        asm("" : : "r"(offset));
        base = offset - (0u - base);
        asm("" : "+r"(base));
        field = 0x3601;
        asm("" : : "r"(field));
        asm("" : "=r"(held5));
        pilot = (u8 *)(base + field);
        asm("" : "+r"(pilot) : "r"(held5));
        battle = (const u8 *)&D_0200EB84;
        asm("" : "+r"(battle));
        for (; i <= 5; i++)
        {
            if (func_08032A88(0, i) && *pilot == *(battle + i * sizeof(struct Unit) + 74))
                break;
        }
    }
    if (i != 6)
    {
        register u32 value asm("r0") = D_0200EB84.sides[0].units[i].hp;
        register u32 base asm("r3");
        register u32 offset asm("r6");
        register u32 address asm("r1");
        register u32 zoid asm("r2");
        asm("" : "+r"(value));
        base = (u32)&D_02000B5C;
        asm("" : "+r"(base));
        offset = member_offset;
        asm("" : : "r"(offset));
        address = offset + base;
        asm("" : "+r"(address));
        zoid = 0x3600;
        asm("" : "+r"(zoid));
        address += zoid;
        asm("" : : "r"(address));
        zoid = *(u8 *)address;
        asm("" : : "r"(zoid));
        address = zoid * 56;
        asm("" : "+r"(address));
        offset = 0xD54;
        asm("" : : "r"(offset));
        base += offset;
        asm("" : "+r"(base));
        address += base;
        empty = func_08031534(value, *(u32 *)address, gauge, 0);
    }
    else
    {
        register u32 base asm("r2") = (u32)&D_02000B5C;
        register u32 offset asm("r1");
        register u32 address asm("r0");
        register u32 zoid asm("r1");
        register u32 field asm("r3");
        register u32 max_offset asm("r6");
        register u32 maximum asm("r1");
        asm("" : "+r"(base));
        offset = member_offset;
        asm("" : : "r"(offset));
        address = offset + base;
        asm("" : "+r"(address));
        field = 0x3600;
        asm("" : "+r"(field));
        address += field;
        asm("" : : "r"(address));
        zoid = *(u8 *)address;
        asm("" : : "r"(zoid));
        address = zoid * 56;
        asm("" : "+r"(address));
        max_offset = 0xD54;
        asm("" : : "r"(max_offset));
        base += max_offset;
        asm("" : "+r"(base));
        address += base;
        asm("" : "+r"(address));
        maximum = *(u32 *)address;
        asm("" : : "r"(maximum));
        empty = func_08031534(0, maximum, gauge, 0);
    }
    asm("" : "+r"(empty));
    {
        register u32 condition asm("r0") = 1;
        register u32 flags_value asm("r1");
        asm("" : "+r"(condition));
        flags_value = saved_flags;
        asm("" : : "r"(flags_value));
        condition &= flags_value;
        if (condition && empty)
        {
            register u32 mask asm("r0") = 1;
            register u32 value asm("r2");
            asm("" : "+r"(mask));
            value = result;
            asm("" : : "r"(value));
            value |= mask;
            result = value;
        }
    else
    {
        asm volatile("" : "+r"(position));
        func_0805D270(gauge, &D_0300239C[position + 0x41], 4);
    }
    }
    {
        register u32 unit_base asm("r1") = (u32)&D_0200EB84;
        register u32 value asm("r0");
        register u32 unit_field asm("r3");
        register u32 base asm("r3");
        register u32 offset asm("r2");
        register u32 address asm("r1");
        register u32 zoid asm("r2");
        asm("" : "+r"(unit_base));
        value = i * sizeof(struct Unit);
        asm("" : "+r"(value));
        unit_field = 720;
        asm("" : "+r"(unit_field));
        unit_base += unit_field;
        asm("" : "+r"(unit_base));
        value += unit_base;
        asm("" : "+r"(value));
        value = *(u32 *)value;
        asm("" : "+r"(value));
        base = (u32)&D_02000B5C;
        asm("" : "+r"(base));
        offset = member_offset;
        asm("" : : "r"(offset));
        address = offset + base;
        asm("" : "+r"(address));
        zoid = 0x3600;
        asm("" : "+r"(zoid));
        address += zoid;
        asm("" : : "r"(address));
        zoid = *(u8 *)address;
        asm("" : : "r"(zoid));
        address = zoid * 56;
        asm("" : "+r"(address));
        offset = 0xD58;
        asm("" : : "r"(offset));
        base += offset;
        asm("" : "+r"(base));
        address += base;
        func_08031534(value, *(u32 *)address, gauge, 0x13);
    }
    {
        register u32 condition asm("r0") = 1;
        register u32 flags_value asm("r3");
        asm("" : "+r"(condition));
        flags_value = saved_flags;
        asm("" : : "r"(flags_value));
        condition &= flags_value;
        if (condition && empty)
        {
            register u32 mask asm("r0") = 2;
            register u32 value asm("r6");
            asm("" : "+r"(mask));
            value = result;
            asm("" : : "r"(value));
            value |= mask;
            asm("" : : "r"(value));
            {
                register u32 stored asm("r0") = (u8)value;
                asm("" : : "r"(stored));
                result = stored;
            }
        }
    else
    {
        asm volatile("" : "+r"(position));
        func_0805D270(gauge, &D_0300239C[position + 0x61], 4);
    }
    }
    func_08032384(1);
    return result;
}
