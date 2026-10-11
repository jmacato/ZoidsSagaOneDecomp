#include "types.h"

struct Part
{
    u32 flags;
    u16 fixed_value;
    u8 pad_6[2];
    u32 fixed_damage;
    u16 amount;
    u8 pad_E;
    u8 valid;
    u8 pattern;
    u8 pad_11;
    u16 id;
};

struct Unit
{
    u8 pad_0[0x14];
    s32 energy;
    u8 pad_18[0x38];
    struct Part parts[6];
    u8 pad_C8[0x2C];
    u8 side;
    u8 slot;
    u8 pad_F6[0x1D6];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Member
{
    u16 flags[6];
    u16 values[6];
    s32 damage[6];
    u8 relation[6];
    u8 count;
    u8 slots[6];
    u8 pad_3D[3];
};

struct Team
{
    u8 count;
    u8 side;
    u16 amount;
    u32 flags;
    struct Member members[6];
};

extern struct Team D_02010E40[6];
extern struct Side D_0200EB8C[2];

void func_0805D270(const void *, void *, u32);
s32 func_08032A88(u32, u32);
u8 func_08038E7C(struct Part *, u8, u8);
u8 func_08038ECC(struct Part *, u8);
u16 func_08034500(struct Unit *, struct Unit *, u8, u8);
s32 func_080345EC(struct Unit *, struct Unit *, u8);

void func_08038A6C(struct Unit *unit)
{
    u8 present[6];
    u16 zero;
    u8 part_index;
    u32 group_index;
    u8 i;
    u32 side;
    u16 *values;
    u16 *zero_pointer;
    struct Team *team;
    struct Part *part;

    part_index = 0;
    {
        register u32 address asm("r1") = (u32)&zero - 8;
        asm("" : "+r"(address));
        address += 8;
        asm("" : "+r"(address));
        zero_pointer = (u16 *)address;
    }
    for (; part_index <= 5; part_index++)
    {
        {
            register u32 value asm("r0") = 0;
            register u16 *destination asm("r2");
            asm("" : "+r"(value));
            destination = zero_pointer;
            asm("" : "+r"(destination) : "r"(value));
            *destination = value;
        }
        {
        u32 initial_index;
        u32 initial_double;
        u32 offset;
        u16 identifier;
        register struct Team *initial_team asm("r5");
        {
            register u32 held0 asm("r0");
            register u32 held1 asm("r1");
            register u32 held2 asm("r2");
            asm("" : "=r"(held0), "=r"(held1), "=r"(held2));
            initial_index = part_index;
            asm("" : : "r"(initial_index), "r"(held0), "r"(held1), "r"(held2));
        }
        initial_double = initial_index * 2;
        {
            register u32 team_offset asm("r0") = ((initial_double + initial_index) * 16 + initial_index) * 8;
            register struct Team *table asm("r1");
            asm("" : : "r"(team_offset));
            table = D_02010E40;
            asm("" : : "r"(team_offset), "r"(table));
            initial_team = (struct Team *)(team_offset + (u32)table);
        }
        asm("" : : "r"(initial_double), "r"(initial_team));
        func_0805D270(zero_pointer, initial_team, 0x010000C4);
        asm("" : : "r"(initial_double), "r"(initial_team));
        {
            register struct Team *saved_team asm("r9") = initial_team;
            asm("" : "+r"(saved_team));
            team = saved_team;
        }
        {
        register u32 index_value asm("r1") = part_index;
        register u32 times_five asm("r0");
        register u32 part_offset asm("r2");
        register struct Unit *source_base asm("r3");
        register u32 invalid_id asm("r0");
        asm("" : "+r"(index_value));
        times_five = index_value * 5;
        asm("" : "+r"(times_five));
        part_offset = times_five * 4;
        asm("" : "+r"(part_offset));
        source_base = unit;
        asm("" : "+r"(source_base));
        identifier = *(u16 *)((u8 *)source_base + part_offset + 0x62);
        asm("" : "+r"(part_offset), "+r"(source_base) : "r"(identifier));
        invalid_id = 0xFFFF;
        asm("" : "+r"(invalid_id));
        if (identifier != invalid_id)
        {
            {
                register u32 flags_offset asm("r0") = part_offset + 0x50;
                asm("" : "+r"(flags_offset));
                source_base = (struct Unit *)((u8 *)source_base + flags_offset);
                asm("" : "+r"(source_base));
                part = (struct Part *)source_base;
            }
            if (part->flags & 1)
            {
                register u32 opposite asm("r1") = 0;
                asm("" : "+r"(opposite));
                if (!unit->side)
                    opposite = 1;
                asm("" : "+r"(opposite));
                side = opposite;
            }
            else
                side = unit->side != 0;
            team->amount = part->amount;
            team->side = side;
            team->flags = part->flags;
            if ((s16)part->amount > unit->energy || part->valid == 0xFF)
                team->count = 0;
            else if (part->flags & 4)
            {
                team->count = 1;
                team->members[0].count = 1;
                team->members[0].slots[0] = unit->slot;
            }
            else
            {
                switch (part->pattern)
                {
                case 0:
                {
                    u32 index;
                    team->count = 6;
                    {
                        register u32 initial_index asm("r3") = 0;
                        asm("" : "+r"(initial_index));
                        index = initial_index;
                    }
                    do
                    {
                        team->members[index].count = 1;
                        team->members[index].slots[0] = index;
                        index = (u8)(index + 1);
                    } while (index <= 5);
                    break;
                }
                case 1:
                {
                    u8 index;
                    team->count = 3;
                    for (index = 0; index <= 2; index++)
                    {
                        team->members[index].count = 2;
                        team->members[index].slots[0] = index;
                        team->members[index].slots[1] = index + 3;
                    }
                    break;
                }
                case 2:
                {
                    u32 first;
                    u8 index;
                    team->count = 2;
                    {
                        register u32 initial_first asm("r6") = 0;
                        asm("" : "+r"(initial_first));
                        first = initial_first;
                    }
                    for (index = 0; index <= 1; index++)
                    {
                        team->members[index].count = 3;
                        team->members[index].slots[0] = first;
                        team->members[index].slots[1] = first + 1;
                        team->members[index].slots[2] = first + 2;
                        first = (u8)(first + 3);
                    }
                    break;
                }
                case 3:
                    team->count = 2;
                    team->members[0].count = 4;
                    team->members[0].slots[0] = 0;
                    team->members[0].slots[1] = 1;
                    team->members[0].slots[2] = 3;
                    team->members[0].slots[3] = 4;
                    team->members[1].count = 4;
                    team->members[1].slots[0] = 1;
                    team->members[1].slots[1] = 2;
                    team->members[1].slots[2] = 4;
                    team->members[1].slots[3] = 5;
                    break;
                case 4:
                    team->count = 1;
                    team->members[0].count = 6;
                    team->members[0].slots[0] = 0;
                    team->members[0].slots[1] = 1;
                    team->members[0].slots[2] = 2;
                    team->members[0].slots[3] = 3;
                    team->members[0].slots[4] = 4;
                    team->members[0].slots[5] = 5;
                    break;
                }
            }
            for (group_index = ({
                register u32 initial_group asm("r3") = 0;
                asm("" : "+r"(initial_group));
                initial_group;
            }); group_index < team->count; group_index = (u8)(group_index + 1))
            {
                struct Member *member = &D_02010E40[part_index].members[group_index];
                u32 initial_count;
                u8 *count;
                u8 *query_count;
                for (i = 0; i <= 5; i++)
                {
                    register u32 held1 asm("r1");
                    register u32 held2 asm("r2");
                    register u8 *destination asm("r0");
                    register u32 value asm("r1");
                    register u32 mask asm("r2");
                    asm("" : "=r"(held1), "=r"(held2), "=m"(present[i]));
                    destination = &present[i];
                    asm("" : "+r"(destination) : "r"(held1), "r"(held2));
                    value = *destination;
                    asm("" : "+r"(value) : "r"(destination));
                    mask = 255;
                    asm("" : "+r"(mask) : "r"(value), "r"(destination));
                    *destination = value | mask;
                }
                {
                    register u8 *pointer asm("r0") = &member->count;
                    register u32 held1 asm("r1");
                    register u32 held2 asm("r2");
                    register u32 held3 asm("r3");
                    register u32 held4 asm("r4");
                    register u32 held5 asm("r5");
                    register u32 held6 asm("r6");
                    asm("" : "+r"(pointer), "=r"(held1), "=r"(held2), "=r"(held3), "=r"(held4), "=r"(held5), "=r"(held6));
                    initial_count = *pointer;
                    asm("" : "+r"(initial_count) : "r"(pointer), "r"(held1), "r"(held2), "r"(held3), "r"(held4), "r"(held5), "r"(held6));
                    i = 0;
                    query_count = pointer;
                    asm("" : "+r"(query_count) : "r"(pointer));
                }
                if (i < initial_count)
                {
                count = query_count;
                asm("" : "+r"(count));
                for (; i < initial_count; i++)
                {
                    u8 *slot;
                    {
                        register u8 *base asm("r0") = (u8 *)member;
                        asm("" : "+r"(base));
                        base += 55;
                        asm("" : "+r"(base));
                        slot = base + i;
                    }
                    if (func_08032A88(side, *slot))
                        present[*slot] = 1;
                    else
                    {
                        register u32 value asm("r0") = *slot;
                        asm("" : "+r"(value));
                        value |= 0xFF;
                        *slot = value;
                        (*count)--;
                    }
                }
                }
                if (*query_count)
                {
                    i = 0;
                    {
                        register u32 held0 asm("r0");
                        register u32 held1 asm("r1");
                        asm("" : "=r"(held0), "=r"(held1));
                        asm("" : : "r"(member->slots), "r"(held0), "r"(held1));
                    }
                    for (; i <= 5; i++)
                        member->slots[i] = present[i];
                    {
                    i = 0;
                    {
                        register u16 *value_base asm("r0");
                        asm volatile("" : "=r"(value_base) : "0"(member));
                        values = (u16 *)((u8 *)value_base + 12);
                    }
                    for (; i <= 5; i++)
                    {
                        if (member->slots[i] != 0xFF)
                        {
                            struct Unit *target;
                            {
                                register u32 side_stride asm("r0") = sizeof(struct Side);
                                register u32 current_side asm("r2");
                                register u32 side_offset asm("r1");
                                register u32 side_table asm("r0");
                                asm volatile("" : "+r"(side_stride));
                                current_side = side;
                                asm("" : "+r"(current_side));
                                side_offset = current_side * side_stride;
                                asm("" : "+r"(side_offset));
                                side_table = (u32)D_0200EB8C;
                                asm("" : "+r"(side_table));
                                side_offset += side_table;
                                asm("" : "+r"(side_offset));
                                target = (struct Unit *)(side_offset + i * sizeof(struct Unit));
                            }
                            member->relation[i] = func_08038E7C(part, unit->slot, target->slot);
                            if (({
                                register u32 held2 asm("r2");
                                u32 flags;
                                asm("" : "=r"(held2));
                                flags = part->flags;
                                asm("" : "+r"(flags) : "r"(held2));
                                flags;
                            }) & 1)
                            {
                                if (func_08038ECC(part, member->relation[i]) != 1)
                                    continue;
                                if (!(({
                                    register u32 held0 asm("r0");
                                    register u32 held2 asm("r2");
                                    u32 flags;
                                    asm("" : "=r"(held0), "=r"(held2));
                                    flags = part->flags;
                                    asm("" : "+r"(flags) : "r"(held0), "r"(held2));
                                    flags;
                                }) & 0x800))
                                {
                                    member->flags[i] |= 1;
                                    {
                                        u16 amount = func_08034500(unit, target, part_index, 0);
                                        u32 offset = i * 2;
                                        asm("" : "+r"(offset));
                                        *(u16 *)((u32)values + offset) = amount;
                                    }
                                    member->damage[i] = func_080345EC(unit, target, part_index);
                                    if ((member->damage[i] >> 16) >= *(s32 *)((u8 *)target + 0x10))
                                        member->flags[i] |= 0x8000;
                                    continue;
                                }
                            }
                            member->flags[i] |= 1;
                            *(u16 *)((u32)values - (0u - i * 2)) = part->fixed_value;
                            member->damage[i] = part->fixed_damage;
                        }
                    }
                    }
                }
            }
        }
        else
            initial_team->count = 0xFF;
        }
        }
    }
}
