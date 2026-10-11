#include "types.h"

struct TargetSprite
{
    u8 prefix[0x4C];
    u16 present;
    u16 id;
    u16 state;
    u16 unused;
    u16 source;
    u16 reset;
    u8 suffix[0x88 - 0x58];
};
extern struct TargetSprite D_03004BBC[];
extern u8 D_0200DA80[2][8];
extern u8 D_0200E24A;
extern const u8 D_086D41CC[];

#define ACTIVATE(slot, unit) do { \
    register u32 address asm("r2") = (slot) * 136; \
    register const u8 *mapping asm("r3"); \
    register u8 *side_pointer asm("r0"); \
    register u32 side asm("r1"); \
    register u32 offset asm("r0"); \
    address += (u32)sprites; \
    *(u16 *)(address + 0x54) = (unit) + 14; \
    mapping = (const u8 *)D_086D41CC; \
    side_pointer = &D_0200E24A; \
    side = *side_pointer; \
    offset = side * 6; \
    mapping += (unit); \
    offset += (u32)mapping; \
    side *= 8; \
    offset = *(u8 *)offset; \
    side += offset; \
    side += (u32)flags; \
    offset = 1; \
    *(u8 *)side = offset; \
    address += 0x50; \
    *(u16 *)address = offset; \
} while (0)

#define PRESENT(slot, unit) do { \
    if (sprites[(unit) + 14].present) \
        ACTIVATE((slot), (unit)); \
} while (0)

void func_08046940(u32 incoming_command, u32 selected_value)
{
    u8 command_value = incoming_command;
    u32 command = command_value;
    register s32 selected asm("r4");
    u32 index;
    register struct TargetSprite *sprites asm("r5");
    register u8 (*flags)[8] asm("r8");
    register u32 zero asm("r3");
    register u32 wide_zero asm("r10");
    register u8 *first_row asm("r9");
    register u8 *second_row asm("r12");
    u32 last;
    register u32 final_slot asm("r0");

    asm("" : : "r"(command), "r"(selected_value));
    selected = (u8)selected_value;
    asm("" : : "r"(selected));
    index = 0;
    asm("" : : "r"(index));
    sprites = D_03004BBC;
    asm("" : : "r"(sprites));
    {
        register u8 (*base)[8] asm("r0") = D_0200DA80;
        asm("" : : "r"(base));
        flags = base;
        asm("" : : "r"(flags));
    }
    zero = 0;
    asm("" : : "r"(zero));
    {
        register u32 value asm("r1") = 0;
        asm("" : : "r"(value));
        wide_zero = value;
        asm("" : : "r"(wide_zero));
    }
    first_row = (u8 *)flags;
    asm("" : : "r"(first_row));
    {
        register u32 value asm("r0") = 8;
        asm("" : "+r"(value));
        value += (u32)flags;
        asm("" : : "r"(value));
        second_row = (u8 *)value;
        asm("" : : "r"(second_row));
    }
    last = 2;
    asm("" : : "r"(last));
    do
    {
        register u32 slot asm("r1") = index + 2;
        register u32 address asm("r0");
        register u32 base asm("r1");
        register u32 value asm("r1");
        asm("" : : "r"(slot));
        address = slot * 136;
        base = (u32)D_03004BBC;
        asm("" : : "r"(address), "r"(base));
        address += base;
        asm("" : : "r"(address));
        base = address + 0x50;
        asm("" : : "r"(base));
        *(u16 *)base = last;
        address += 0x56;
        value = wide_zero;
        asm("" : : "r"(address), "r"(value));
        *(u16 *)address = value;
        value = (u32)first_row;
        asm("" : : "r"(value));
        address = index + value;
        asm("" : : "r"(address));
        *(u8 *)address = zero;
        value = (u32)second_row;
        asm("" : : "r"(value));
        address = index + value;
        asm("" : : "r"(address));
        *(u8 *)address = zero;
        {
            register u32 next asm("r0") = index + 1;
            asm("" : : "r"(next));
            index = (u8)next;
        }
    } while (index <= 5);
    last = 7;
    asm("" : : "r"(last));
    switch (command)
    {
    case 0:
    case 5:
    case 7:
        {
            register u32 address asm("r2") = last * 136 + (u32)sprites;
            register u32 value asm("r1") = selected + 14;
            register u32 destination asm("r0");
            register const u8 *mapping asm("r3");
            register u8 *side_pointer asm("r0");
            register u32 side asm("r1");
            register u32 offset asm("r0");
            asm("" : : "r"(value), "r"(address));
            destination = address + 0x54;
            asm("" : : "r"(destination));
            *(u16 *)destination = value;
            mapping = (const u8 *)D_086D41CC;
            side_pointer = &D_0200E24A;
            side = *side_pointer;
            offset = side * 6;
            offset = selected + offset;
            offset += (u32)mapping;
            side *= 8;
            offset = *(u8 *)offset;
            side += offset;
            side += (u32)flags;
            offset = 1;
            *(u8 *)side = offset;
            address += 0x50;
            *(u16 *)address = offset;
        }
        break;
    case 1:
        switch (selected)
        {
        case 6:
            PRESENT(last, 0);
            PRESENT(last - 1, 3);
            break;
        case 7:
            PRESENT(last, 1);
            PRESENT(last - 1, 4);
            break;
        case 8:
            PRESENT(last, 2);
            if (sprites[19].present)
            {
                final_slot = last - 1;
                asm("" : : "r"(final_slot));
                goto final_unit;
            }
            goto done;
        }
        break;
    case 2:
    case 10:
    case 12:
        switch (selected)
        {
        case 9:
            PRESENT(last, 0);
            PRESENT(last - 1, 1);
            PRESENT(last - 2, 2);
            break;
        case 10:
            PRESENT(last, 3);
            PRESENT(last - 1, 4);
            if (sprites[19].present)
            {
                final_slot = last - 2;
                asm("" : : "r"(final_slot));
                goto final_unit;
            }
            goto done;
        }
        break;
    case 3:
        switch (selected)
        {
        case 11:
            PRESENT(last, 0);
            PRESENT(last - 1, 1);
            PRESENT(last - 2, 3);
            PRESENT(last - 3, 4);
            break;
        case 12:
            PRESENT(last, 1);
            PRESENT(last - 1, 2);
            PRESENT(last - 2, 4);
            if (sprites[19].present)
            {
                final_slot = last - 3;
                asm("" : : "r"(final_slot));
                goto final_unit;
            }
            goto done;
        }
        break;
    case 4:
        {
            register struct TargetSprite *base asm("r5") = sprites;
            register struct TargetSprite *sprites asm("r4") = base;
            asm("" : : "r"(sprites));
            PRESENT(last, 0);
            PRESENT(last - 1, 1);
            PRESENT(last - 2, 2);
            PRESENT(last - 3, 3);
            PRESENT(last - 4, 4);
            if (base[19].present)
            {
                final_slot = last - 5;
                asm("" : : "r"(final_slot));
                goto final_unit;
            }
            goto done;
        }
    }
    goto done;
final_unit:
    ACTIVATE(final_slot, 5);
done:
    return;
}
