#include "types.h"

struct Zoid
{
    u8 pad_0[6];
    u16 kind;
    u8 pad_8[0x30];
};

struct Kind
{
    u8 pad_0[0xC];
    vu8 group;
    u8 pad_D[0x3F];
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[0xAD];
} D_02000B5C;

extern const struct Kind D_0867008C[];
extern const u8 D_0875BE10[][8];
extern u8 D_0200E8A1;
extern u8 D_0200E7F4[];

void func_080550E4(u16 kind)
{
    vu32 saved_kind = kind;
    register const struct Kind *entry asm("r10");
    u8 *count_ptr;
    register u32 i asm("r12");
    register u32 shifted_i asm("r4");

    {
        register u32 stride asm("r0") = sizeof(struct Kind);
        register u32 selected asm("r2") = saved_kind;
        register u32 offset asm("r1") = selected;
        register const struct Kind *base asm("r0");

        asm("" : : "r"(stride), "r"(selected), "r"(offset));
        offset *= stride;
        base = D_0867008C;
        asm("" : : "r"(offset), "r"(base));
        entry = (const struct Kind *)(offset + (u32)base);
    }
    {
        register u8 *count asm("r1") = &D_0200E8A1;
        register u32 zero asm("r0") = 0;

        asm("" : : "r"(count), "r"(zero));
        *count = zero;
        asm volatile("" : "+r"(zero));
        i = 0;
        count_ptr = count;
        asm("" : "+l"(count_ptr) : "r"(i));
    }
    do
    {
        register const struct Kind *current asm("r1") = entry;
        register u32 group_byte asm("r0") = current->group;

        asm("" : : "r"(current), "r"(group_byte));
        if (group_byte < 0xFA)
        {
            register u32 current_index asm("r0") = i;
            register u32 index_word asm("r2");
            register s32 index asm("r1");
            register u32 address asm("r0");
            register u32 base asm("r1");
            register u32 adjustment asm("r1");
            register u32 stored_kind asm("r0");
            register const struct Kind *current asm("r2");
            register u32 group asm("r2");

            asm("" : : "r"(current_index));
            index_word = current_index << 16;
            index = (s32)index_word >> 16;
            address = index * sizeof(struct Zoid);
            base = (u32)&D_02000B5C;
            asm("" : "+r"(base) : "r"(address), "r"(index_word));
            address += base;
            adjustment = 0xD32;
            asm("" : "+r"(address) : "r"(adjustment), "r"(index_word));
            address += adjustment;
            stored_kind = *(u16 *)address;
            shifted_i = index_word;
            current = entry;
            group = current->group;
            asm("" : : "r"(stored_kind), "r"(shifted_i), "r"(group));
            if (stored_kind != group)
                goto next;
        found:
            {
                register u32 count asm("r0") = *count_ptr;
                register u8 *destination asm("r1") = D_0200E7F4;
                register u8 *field asm("r0");
                register u32 selected asm("r2");

                asm("" : : "r"(count), "r"(destination));
                field = (u8 *)(count + (u32)destination);
                selected = i;
                asm("" : "+r"(field) : "r"(selected));
                *field = selected;
                count = *count_ptr;
                count++;
                asm("" : : "r"(count));
                *count_ptr = count;
            }
            goto next;
        }
        else
        {
            register u32 member asm("r3") = 0;
            register const struct Kind *current asm("r0") = entry;
            register u32 group asm("r2") = current->group;
            register u32 address asm("r0");
            register const u8 *table asm("r1");
            register u32 first asm("r0");
            register u32 saved_group asm("r6");
            register const u8 *members asm("r8");
            register const u8 *next_members asm("r9");
            register u16 *kind_field asm("r5");

            asm("" : "+r"(member) : "r"(current), "r"(group));
            address = (group - 0xFA) * 8;
            table = (const u8 *)D_0875BE10;
            asm("" : : "r"(address), "r"(table));
            first = *(const u8 *)(address + (u32)table);
            shifted_i = i << 16;
            saved_group = group;
            asm("" : : "r"(first), "r"(shifted_i), "r"(saved_group));
            if (first == 0xFF)
                goto next;
            {
                register const u8 *base asm("r0") = (const u8 *)D_0875BE10;
                register s32 index asm("r1");
                register u32 address asm("r0");
                register u32 inventory asm("r1");

                asm("" : "+r"(base));
                members = base;
                index = (s32)shifted_i >> 16;
                address = index * sizeof(struct Zoid);
                inventory = (u32)&D_02000B5C;
                asm("" : "+r"(inventory) : "r"(address));
                address += inventory;
                inventory = 0xD32;
                asm("" : "+r"(address) : "r"(inventory));
                kind_field = (u16 *)(address + inventory);
                next_members = members;
                asm("" : "+r"(members), "+r"(next_members) : "r"(kind_field));
            }
            do
            {
                register u32 member_word asm("r0") = member << 16;
                register s32 signed_member asm("r3");
                register u32 address asm("r0");
                register u32 candidate asm("r1");
                register u32 own_kind asm("r2");

                asm("" : : "r"(member_word));
                signed_member = (s32)member_word >> 16;
                asm("" : : "r"(signed_member));
                address = (group - 0xFA) * 8;
                asm("" : : "r"(address));
                address = signed_member + address;
                candidate = *(const u8 *)(address + (u32)members);
                own_kind = saved_kind;
                asm("" : : "r"(candidate), "r"(own_kind));
                if (candidate != own_kind && *kind_field == candidate)
                    goto found;
                {
                    register u32 word asm("r0") = (u32)(signed_member + 1) << 16;
                    register s32 signed_next asm("r0");
                    register u32 offset asm("r1");
                    register u32 next asm("r0");

                    member = word >> 16;
                    signed_next = (s32)word >> 16;
                    asm("" : : "r"(member), "r"(signed_next));
                    group = saved_group;
                    asm("" : : "r"(group));
                    offset = group;
                    asm("" : "+r"(offset));
                    offset = (offset - 0xFA) * 8;
                    next = signed_next + offset + (u32)next_members;
                    asm("" : : "r"(next));
                    next = *(const u8 *)next;
                    if (next == 0xFF)
                        break;
                }
            } while (1);
        }
    next:
        {
            register u32 increment asm("r1") = 0x10000;
            register u32 word asm("r0");
            register u32 next_index asm("r2");

            asm("" : : "r"(increment));
            word = shifted_i + increment;
            next_index = word >> 16;
            i = next_index;
            asm("" : : "r"(next_index), "r"(i));
            if (((s32)word >> 16) > 0xAC)
                break;
        }
    } while (1);
}
