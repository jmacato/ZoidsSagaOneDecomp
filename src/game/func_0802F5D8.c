#include "types.h"

struct Part
{
    u32 flags;
    u8 pad_4[8];
    u16 count;
    u8 pad_E[4];
    u16 id;
};

struct Unit
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[0x16];
    u32 base[6];
    u8 pad_38[0x20];
    struct Part parts[6];
    u8 pad_D0[0x14];
    u32 current[6];
    u8 pad_FC[0x1D0];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

extern union
{
    struct
    {
        u16 field_0;
        u16 flags;
    } head;
    struct Side sides[2];
} D_0200EB84;

void func_08033A34(void *, u32);

void func_0802F5D8(void)
{
    register u32 side asm("r9");
    register u32 slot asm("r8");
    u8 k;
    register u32 high_cache asm("r10");
    struct { vu32 side_bytes; vu32 next_side; vu32 saved_flags; } storage;

    if (({ register u32 address asm("r2") = 0x0200EB84u; asm("" : : "r"(address)); *(u16 *)(address + 2); }) & 0x20)
    {
        register u32 low_side asm("r0");
        register u32 low_slot asm("r0");
        side = 0;
            do
            {
            {
                register u32 zero asm("r1") = 0;
                asm("" : "+r"(zero));
                slot = zero;
                asm("" : "+r"(slot));
            }
            {
                register u32 low_value asm("r3") = side * sizeof(struct Side);
                asm("" : : "r"(low_value));
                high_cache = low_value;
                asm("" : "+r"(high_cache) : "r"(low_value));
            }
            do
            {
                register u32 unit_bytes asm("r2");
                register u32 copy_stride asm("r1");
                k = 0;
                copy_stride = sizeof(struct Unit);
                asm("" : "+r"(copy_stride));
                {
                    register u32 held0 asm("r0");
                    register u32 held3 asm("r3");
                    asm("" : "=r"(held0), "=r"(held3));
                    unit_bytes = slot * copy_stride;
                    asm("" : : "r"(unit_bytes), "r"(copy_stride), "r"(held0), "r"(held3));
                }
                for (; k <= 5; k++)
                {
                    u32 offset = k * 4 + unit_bytes + high_cache;
                    {
                        register u32 address asm("r3") = 0x0200EB84u + 0xE4;
                        u32 *destination;
                        asm("" : "+r"(address) : "r"(offset));
                        destination = (u32 *)(offset + address);
                        address = 0x0200EB84u + 0x20;
                        asm("" : "+r"(address) : "r"(offset), "r"(destination));
                        *destination = *(u32 *)(offset + address);
                    }
                }
                {
                    u8 *base;
                    u32 slot_bytes;
                    u32 callback_stride;
                    u32 group_bytes;
                    u8 *group;
                    k = 0;
                    base = (u8 *)0x0200EB84u;
                    asm volatile("" : "+r"(base));
                    callback_stride = sizeof(struct Unit);
                    asm("" : "+r"(callback_stride));
                    slot_bytes = slot * callback_stride;
                    group_bytes = side * sizeof(struct Side);
                    {
                        u8 *unit_base = base + 8;
                        asm("" : "+r"(unit_base));
                        group = (u8 *)(group_bytes - (0u - (u32)unit_base));
                    }
                    for (; k <= 5; k++)
                    {
                        register u32 offset asm("r0") = k * sizeof(struct Part) + slot_bytes + group_bytes;
                        u8 *flags_base;
                        u32 flags;
                        asm("" : "+r"(offset));
                        flags_base = base + 0x58;
                        asm("" : "+r"(flags_base) : "r"(offset) : "r1");
                        offset += (u32)flags_base;
                        asm("" : : "r"(offset));
                        flags = *(u32 *)offset;
                        if (flags & 0x100)
                        {
                            register u32 arg0 asm("r0") = (u32)group + slot_bytes;
                            register u32 arg1 asm("r1") = k;
                            asm("" : "+r"(arg0), "+r"(arg1) : "r"(flags_base));
                            storage.saved_flags = (u32)flags_base;
                            func_08033A34((void *)arg0, arg1);
                        }
                    }
                }

                asm("" : "+r"(slot));
                slot = (u8)(slot + 1);
            } while (slot <= 5);

                asm("" : "+r"(side));
                side = (u8)(side + 1);
            } while (side <= 1);
    }
    if (({ register u32 address asm("r0") = 0x0200EB84u; asm("" : : "r"(address)); *(u16 *)(address + 2); }) & 0x40)
    {
        {
            register u32 zero asm("r1") = 0;
            asm("" : "+r"(zero));
            side = zero;
            asm("" : : "r"(side), "r"(zero));
        }
            do
            {
            {
                register u32 zero asm("r3") = 0;
                asm("" : "+r"(zero));
                slot = zero;
                asm("" : : "r"(slot), "r"(zero));
            }
            do
            {
                if (!(({ register u32 address asm("r0") = 0x0200EB84u; asm("" : : "r"(address)); *(u16 *)(address + 2); }) & 0x20))
                {
                    register u32 stride asm("r0");
                    register u32 unit_bytes asm("r5");
                    register u32 side_bytes asm("r3");
                    register u32 source asm("r2");
                    register u32 destination asm("r6");
                    k = 0;
                    stride = sizeof(struct Unit);
                    asm("" : "+r"(stride));
                    unit_bytes = slot * stride;
                    asm("" : "+r"(unit_bytes));
                    stride = sizeof(struct Side);
                    asm("" : "+r"(stride));
                    side_bytes = side * stride;
                    asm("" : "+r"(side_bytes));
                    source = 0x0200EB84u + 0x20;
                    asm("" : "+r"(source));
                    destination = source + 0xC4;
                    asm("" : "+r"(destination) : "r"(source));
                    for (; k <= 5; k++)
                    {
                        register u32 offset asm("r0") = k * 4 + unit_bytes + side_bytes;
                        register u32 target asm("r1") = offset + destination;
                        asm("" : "+r"(offset), "+r"(target));
                        offset += source;
                        *(u32 *)target = *(u32 *)offset;
                    }
                }
                {
                    register u32 base asm("r7");
                    register u32 slot_bytes asm("r5");
                    register u32 side_bytes asm("r6");
                    register u32 group asm("r2");
                    register u32 stride asm("r0");
                    k = 0;
                    base = 0x0200EB84u;
                    asm("" : "+r"(base));
                    stride = sizeof(struct Unit);
                    asm("" : "+r"(stride));
                    slot_bytes = slot * stride;
                    asm("" : "+r"(slot_bytes));
                    stride = sizeof(struct Side);
                    asm("" : "+r"(stride));
                    side_bytes = side * stride;
                    asm("" : "+r"(side_bytes));
                    stride = base + 8;
                    asm("" : "+r"(stride));
                    group = side_bytes + stride;
                    asm("" : "+r"(group));
                    for (; k <= 5; k++)
                    {
                        register u32 offset asm("r0") = k * sizeof(struct Part) + slot_bytes + side_bytes;
                        register u32 flags asm("r1");
                        asm("" : "+r"(offset));
                        flags = base + 0x58;
                        asm("" : "+r"(flags) : "r"(offset));
                        offset += flags;
                        flags = *(u32 *)offset;
                        if (!(flags & 0x100))
                        {
                            asm("" : "+r"(flags));
                            flags &= 1;
                            asm("" : "+r"(flags));
                            if (flags)
                            {
                                register u32 arg0 asm("r0") = group + slot_bytes;
                                register u32 arg1 asm("r1") = k;
                                asm("" : "+r"(arg0), "+r"(arg1) : "r"(group));
                                storage.saved_flags = group;
                                func_08033A34((void *)arg0, arg1);
                                group = storage.saved_flags;
                                asm("" : "+r"(group));
                            }
                        }
                    }
                }

                asm("" : "+r"(slot));
                slot = (u8)(slot + 1);
            } while (slot <= 5);

                asm("" : "+r"(side));
                side = (u8)(side + 1);
            } while (side <= 1);
    }
    {
        register u32 low_side asm("r0");
        register u32 low_slot asm("r0");
        {
            register u32 zero asm("r1") = 0;
            asm("" : "+r"(zero));
            side = zero;
            asm("" : : "r"(side), "r"(zero));
        }
        do
        {
            {
                register u32 zero asm("r3") = 0;
                asm("" : "+r"(zero));
                slot = zero;
                asm("" : : "r"(slot), "r"(zero));
            }
            storage.next_side = side + 1;
            {
                register u32 stride asm("r3") = sizeof(struct Side);
                register u32 offset asm("r1") = side;
                asm("" : "+r"(stride), "+r"(offset));
                offset *= stride;
                storage.side_bytes = offset;
            }
            do
            {
                register u32 unit_bytes asm("r3");
                register u32 flag_value asm("r0");
                {
                    register u32 stride asm("r0") = sizeof(struct Unit);
                    register u32 offset asm("r0");
                    register u32 field_value asm("r1");
                    asm("" : "+r"(stride));
                    unit_bytes = slot * stride;
                    asm("" : "+r"(unit_bytes));
                    field_value = storage.side_bytes;
                    offset = unit_bytes + field_value;
                    asm("" : "+r"(offset));
                    field_value = 0x0200EB84u;
                    asm("" : "+r"(field_value));
                    offset += field_value;
                    field_value = *(u16 *)(offset + 8);
                    asm("" : "+r"(field_value));
                    offset = 8;
                    asm("" : "+r"(offset));
                    offset &= field_value;
                    asm("" : "+r"(offset));
                    flag_value = offset;
                }
                {
                    register u32 one asm("r1") = 1;
                    asm("" : "+r"(one) : "r"(flag_value));
                    slot += one;
                    asm("" : "+r"(slot) : "r"(unit_bytes), "r"(flag_value));
                }
                if (flag_value)
                {
                    register u32 base asm("r7");
                    register u32 slot_bytes asm("r6");
                    register u32 group_bytes asm("r5");
                    register u32 invalid_id asm("r12");
                    k = 0;
                    base = 0x0200EB84u;
                    asm("" : "+r"(base) : "r"(unit_bytes));
                    slot_bytes = unit_bytes;
                    asm("" : "+r"(slot_bytes));
                    {
                        register u32 stride asm("r0") = sizeof(struct Side);
                        asm("" : "+r"(stride));
                        group_bytes = side * stride;
                        asm("" : "+r"(group_bytes));
                    }
                    {
                        register u32 value asm("r3") = 0xFFFF;
                        asm("" : "+r"(value));
                        invalid_id = value;
                        asm("" : "+r"(invalid_id) : "r"(value));
                    }
                    {
                        register u32 value asm("r0") = 0x20;
                        asm("" : "+r"(value));
                        value += (u32)base;
                        high_cache = value;
                        asm("" : "+r"(high_cache) : "r"(value));
                    }
                    for (; k <= 5; k++)
                    {
                        register u32 word_bytes asm("r3") = k * 4;
                        u32 offset;
                        u8 *entry;
                        asm("" : "+r"(word_bytes));
                        offset = (word_bytes + k) * 4 + slot_bytes + group_bytes;
                        entry = (u8 *)(offset + (u32)base);
                        asm("" : "+r"(entry) : "r"(word_bytes));
                        if (*(u16 *)(entry + 0x6A) != invalid_id)
                        {
                            u32 mode = (({ register u32 address asm("r1") = 0x0200EB84u; asm("" : : "r"(address)); *(u16 *)(address + 2); }) & 0x20) | 0x40;
                            asm("" : "+r"(mode));
                            if (!mode)
                            {
                                register u32 copy_offset asm("r0") = word_bytes + slot_bytes + group_bytes;
                                u8 *destination;
                                asm("" : "+r"(copy_offset) : "r"(word_bytes));
                                destination = (u8 *)(base + 0xE4);
                                asm("" : "+r"(destination) : "r"(copy_offset));
                                {
                                    register u32 target asm("r1") = copy_offset + (u32)destination;
                                    asm("" : "+r"(target) : "r"(copy_offset));
                                    copy_offset += high_cache;
                                    asm("" : "+r"(copy_offset) : "r"(high_cache));
                                    *(u32 *)target = *(u32 *)copy_offset;
                                }
                            }
                            *(u16 *)(entry + 0x64) <<= 1;
                        }
                    }
                }
                {
                    register u32 value asm("r3") = slot;
                    asm("" : "+r"(value));
                    low_slot = (u8)value;
                    slot = low_slot;
                    asm("" : : "r"(slot), "r"(low_slot));
                }
            } while (low_slot <= 5);
            {
                register u32 value asm("r1") = storage.next_side;
                asm("" : "+r"(value));
                low_side = (u8)value;
                side = low_side;
                asm("" : : "r"(side), "r"(low_side));
            }
        } while (low_side <= 1);
    }
}
