#include "types.h"

struct Part
{
    u16 kind;
    u16 id;
};

struct Team
{
    u8 zoid;
    u8 pilot;
    u8 item;
    u8 pad_3;
    struct Part parts[3];
    u8 pad_10;
    u8 field_11;
    u8 pad_12[2];
};

struct Setup
{
    struct Team teams[2];
    u8 pad_28;
    u8 mode;
};

struct Stats
{
    u32 data[4];
};

struct Body
{
    u8 pad_0[6];
    u16 zoid;
    u8 pad_8[8];
    struct Part parts[3];
    u8 pad_1C[0x1C];
    struct Stats pilot;
    u8 pad_48[0x7E];
    u8 item;
    u8 pad_C7[0x25];
    u8 side;
    u8 slot;
    u8 pad_EE[0x1D6];
};

struct Unit
{
    u8 pad_0[8];
    struct Body body;
};

struct Side
{
    struct Unit units[6];
    u8 field_10C8;
    u8 field_10C9;
    u8 pad_10CA[0xE];
};

extern struct
{
    u16 flags;
    u8 pad_2[6];
    struct Side sides[2];
} D_0200EB84;

struct PilotDef
{
    struct Stats *stats;
    u8 pad_4[0x24];
};

extern u8 D_0867006C[][0x4C];
extern struct PilotDef D_0867B1B4[];

void func_0805D270(const void *, void *, u32);
void func_0802B9DC(void *, const void *);
void func_0802BA24(void *, void *);

void func_0803DCC0(struct Setup *setup)
{
    struct Frame
    {
        u16 zero;
        u16 pad_2;
        struct Setup *volatile setup;
        u8 *volatile side_ptr;
        u8 *volatile slot_ptr;
        vu32 next_side;
        vu32 next_slot;
        vu32 side_four;
        u8 *volatile item_ptr;
        struct Part *volatile parts;
    } frame;
    register vu16 *zero_ptr asm("r0");
    register u32 zero asm("r5");
    register u32 side asm("r10");
    register u32 slot asm("r8");
    register u32 i asm("r3");
    register u16 *flags_ptr asm("r4");
    register u32 flags asm("r1");
    register u32 flag asm("r0");

    frame.setup = setup;
    zero_ptr = &frame.zero;
    zero = 0;
    asm("" : "+r"(zero) : "r"(zero_ptr));
    *zero_ptr = zero;
    func_0805D270((void *)zero_ptr, &D_0200EB84, 0x010015F6);
    flags_ptr = (u16 *)&D_0200EB84;
    flags = *flags_ptr;
    flag = 1;
    asm("" : : "r"(flags), "r"(flag));
    flags |= flag;
    flags |= zero;
    *flags_ptr = flags;
    switch (frame.setup->mode)
    {
    case 0: flag = 6; break;
    case 1: flag = 2; break;
    case 2: flag = 4; break;
    default: goto begin_sides;
    }
    asm("" : : "r"(flag), "r"(flags));
    flags |= flag;
    *flags_ptr = flags;
begin_sides:
    asm("" : : : "r0", "r1", "r2", "r3");
    side = 0;
    do
    {
        register u32 stride asm("r0") = sizeof(struct Side);
        register u32 offset asm("r2") = side;
        register u8 *group_base asm("r1");
        register u32 field_offset asm("r3");
        register u8 *side_group asm("r2");
        register u8 *field asm("r1");
        register u32 value asm("r0");
        register u32 side_copy asm("r4");
        register u32 side_four asm("r3");
        register u32 team_offset asm("r0");
        register struct Setup *input asm("r7");
        register struct Team *raw_team asm("r0");
        register struct Team *team asm("r6");
        register u32 byte asm("r1");
        register u32 second_offset asm("r4");
        register u32 zero_slot asm("r7");
        register u32 next asm("r1");

        asm("" : : "r"(stride), "r"(offset));
        offset *= stride;
        group_base = (u8 *)&D_0200EB84;
        asm("" : : "r"(offset), "r"(group_base));
        side_group = (u8 *)(offset + (u32)group_base);
        field_offset = 0x10D0;
        asm("" : : "r"(side_group), "r"(field_offset));
        field = side_group + field_offset;
        value = 0;
        asm("" : : "r"(field), "r"(value));
        *field = value;
        side_copy = side;
        asm("" : : "r"(side_copy));
        side_four = side_copy << 2;
        team_offset = (side_four + side_copy) << 2;
        input = frame.setup;
        asm("" : : "r"(team_offset), "r"(input));
        raw_team = (struct Team *)((u8 *)input + team_offset);
        byte = raw_team->field_11;
        second_offset = 0x10D1;
        asm("" : : "r"(byte), "r"(second_offset), "r"(side_group));
        side_group += second_offset;
        *side_group = byte;
        zero_slot = 0;
        asm("" : "+r"(zero_slot) : "r"(raw_team));
        slot = zero_slot;
        frame.side_four = side_four;
        next = side + 1;
        frame.next_side = next;
        team = raw_team;
        asm("" : : "r"(team));
        do
        {
            register u32 stride asm("r0") = sizeof(struct Side);
            register u32 side_offset asm("r1") = side;
            register u8 *units asm("r2");
            register u32 slot_offset asm("r3");
            register u32 offset_copy asm("r0");
            register struct Unit *unit asm("r5");
            register u32 slot_check asm("r4");

            asm("" : : "r"(stride), "r"(side_offset));
            side_offset *= stride;
            units = (u8 *)D_0200EB84.sides;
            asm("" : : "r"(side_offset), "r"(units));
            side_offset += (u32)units;
            stride = sizeof(struct Unit);
            slot_offset = slot;
            asm("" : : "r"(stride), "r"(slot_offset));
            slot_offset *= stride;
            asm("" : : "r"(slot_offset));
            offset_copy = slot_offset;
            asm("" : : "r"(offset_copy), "r"(side_offset));
            unit = (struct Unit *)(side_offset + offset_copy);
            slot_check = slot;
            asm("" : : "r"(slot_check));
            if (slot_check == 1)
            {
                register struct Body *low_body asm("r4");
                register struct Body *body asm("r9");
                unit->body.zoid = team->zoid;
                low_body = &unit->body;
                asm("" : : "r"(low_body));
                func_0802B9DC(low_body, D_0867006C[team->zoid]);
                unit->body.pilot = *D_0867B1B4[team->pilot].stats;
                i = 0;
                body = low_body;
                asm("" : "+r"(i) : "r"(body));
                {
                    register u8 *side_ptr asm("r4") = &low_body->side;
                    register u8 *slot_ptr asm("r7");
                    register u8 *item_ptr asm("r0");
                    register u32 next asm("r1");
                    register u32 offset asm("r0");
                    register u32 part_offset asm("r12");
                    register struct Part *parts asm("r2");
                    register struct Part *input_parts asm("r4");

                    asm("" : : "r"(side_ptr));
                    frame.side_ptr = side_ptr;
                    slot_ptr = &unit->body.slot;
                    asm("" : : "r"(slot_ptr));
                    frame.slot_ptr = slot_ptr;
                    item_ptr = &unit->body.item;
                    asm("" : : "r"(item_ptr));
                    frame.item_ptr = item_ptr;
                    next = 2;
                    asm("" : : "r"(next));
                    frame.next_slot = next;
                    offset = frame.side_four;
                    offset = (offset + side) << 2;
                    part_offset = offset;
                    asm("" : : "r"(part_offset));
                    parts = unit->body.parts;
                    asm("" : : "r"(parts));
                    frame.parts = parts;
                    input_parts = (struct Part *)((u8 *)frame.setup + 4);
                    asm("" : : "r"(input_parts));
                    do
                    {
                        register u32 index asm("r1") = i << 2;
                        register u32 base_offset asm("r7") = part_offset;
                        register u32 offset asm("r2");
                        register struct Setup *input asm("r7");
                        register struct Part *entry asm("r0");
                        register u32 id asm("r0");
                        register u32 absent asm("r7");
                        register struct Part *parts asm("r7");
                        register struct Part *destination asm("r0");
                        register struct Part *source asm("r1");
                        register u32 next asm("r0");

                        asm("" : : "r"(index), "r"(base_offset));
                        offset = index + base_offset;
                        input = frame.setup;
                        asm("" : : "r"(offset), "r"(input));
                        entry = (struct Part *)((u8 *)input + offset + 4);
                        id = entry->id;
                        absent = 0xFFFF;
                        asm("" : : "r"(id), "r"(absent));
                        if (id != absent)
                        {
                            parts = frame.parts;
                            destination = (struct Part *)((u8 *)parts + index);
                            source = (struct Part *)((u8 *)input_parts + offset);
                            asm("" : : "r"(destination), "r"(source));
                            *destination = *source;
                        }
                        next = i + 1;
                        asm("" : : "r"(next));
                        i = (u8)next;
                    } while (i < 3);
                }
                func_0802BA24(body, unit);
                {
                    register u32 side_value asm("r1") = side;
                    register u8 *side_ptr asm("r0");
                    register u32 slot_value asm("r3");
                    register u8 *slot_ptr asm("r2");
                    register u32 item asm("r0");
                    register u8 *item_ptr asm("r4");

                    asm("" : : "r"(side_value));
                    side_ptr = frame.side_ptr;
                    *side_ptr = side_value;
                    slot_value = slot;
                    asm("" : : "r"(slot_value));
                    slot_ptr = frame.slot_ptr;
                    *slot_ptr = slot_value;
                    item = team->item;
                    asm("" : : "r"(item));
                    item_ptr = frame.item_ptr;
                    *item_ptr = item;
                    item = team->item;
                    if (item != 0xFF)
                    {
                        u16 *flags_ptr = (u16 *)&D_0200EB84;
                        register u32 flags asm("r1");
                        register u32 flag asm("r0");
                        asm("" : "+l"(flags_ptr) : "r"(team)
                            : "r0", "r1", "r2", "r3", "r4", "r5");
                        flags = *flags_ptr;
                        flag = 8;
                        asm("" : : "r"(flag), "r"(flags));
                        flag |= flags;
                        *flags_ptr = flag;
                    }
                }
            }
            else
            {
                unit->body.zoid = 0xFF;
                frame.next_slot = slot + 1;
            }
            {
                register u32 next asm("r1") = frame.next_slot;
                register u32 value asm("r0");
                asm("" : : "r"(next));
                value = (u8)next;
                asm("" : : "r"(value));
                slot = value;
            }
        } while (slot < 6);
        {
            register u32 next asm("r2") = frame.next_side;
            register u32 value asm("r0");
            asm("" : : "r"(next));
            value = (u8)next;
            asm("" : : "r"(value));
            side = value;
        }
    } while (side < 2);
}
