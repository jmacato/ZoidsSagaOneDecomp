#include "types.h"

extern u8 D_0200EB84[];
extern u8 D_0200E24A;
extern const u8 D_086D41CC[2][6];
extern u8 D_0200DA80[2][8];
extern u8 D_0200E270[6];
extern u16 D_0200E276[6];
u16 func_08034500(void *, void *, u8);

typedef unsigned long long u64;
union HelperWord { u32 word; u32 parts[2]; u64 wide; };

void func_080466F0(u8 selected)
{
    register u32 part asm("r8") = selected;
    register u32 stride asm("r9");
    register u8 *units asm("r10");
    register u32 index asm("r5");
    asm("" : : "r"(part));
    index = 0;
    asm("" : : "r"(index));
    {
        register u8 *base asm("r0") = D_0200EB84;
        register u32 width asm("r1");
        asm("" : : "r"(base));
        units = base + 8;
        width = 716;
        asm("" : : "r"(width), "r"(units));
        stride = width;
        asm("" : : "r"(stride));
    }
    do
    {
        register u8 *base asm("r0") = &D_0200E24A;
        register u32 side asm("r2");
        register u32 offset asm("r0");
        register const u8 *mapping asm("r3");
        register u32 slot asm("r1");
        register u32 enabled asm("r1");
        register u32 active_base asm("r0");
        asm("" : : "r"(base));
        side = *base;
        offset = side * 6;
        asm("" : "+r"(offset));
        offset = index + offset;
        asm("" : : "r"(offset));
        mapping = &D_086D41CC[0][0];
        asm("" : : "r"(mapping));
        offset += (u32)mapping;
        slot = side * 8;
        asm("" : : "r"(slot));
        slot += *(u8 *)offset;
        asm("" : : "r"(slot));
        active_base = (u32)D_0200DA80;
        asm("" : : "r"(active_base));
        slot += active_base;
        enabled = *(u8 *)slot;
        asm("" : "+r"(enabled));
        if (enabled)
        {
            if (side == 1)
            {
                u32 base = (u32)D_0200EB84;
                register u32 width asm("r4");
                register const u8 *target asm("r6");
                register u32 offset asm("r1");
                register u8 *value_address asm("r0");
                register u32 value asm("r0");

                offset = 0x21ED;

                value_address = (u8 *)base;
                value_address += offset;
                value = (u32)value_address;

                value = *(u8 *)value;

                width = 716;

                value *= width;
                value += (u32)units;

                {
                    register union HelperWord target_base asm("r1");
                    register u32 target_offset asm("r1");
                    register u32 side_offset asm("r3");
                    register u8 *target_units asm("r2");

                    target_base.word = (u32)mapping;
                    target_base.word += 6;

                    target = (const u8 *)(index + target_base.word);

                    target_offset = *target * width;

                    side_offset = 0x10E0;

                    target_units = (u8 *)((u32)base + side_offset);

                    target_offset += (u32)target_units;
                    *(D_0200E270 + index) = func_08034500((void *)value, (void *)target_offset, part);
                }
                value = index * width + (u32)base;
                offset = 0x10E8;

                value = *(u16 *)(value + offset);
                {
                    register u32 mask asm("r2") = 0x200;
                    register union HelperWord applied asm("r1");

                    applied.word = mask;
                    value &= applied.word;
                }
                if (value)
                {
                    register u32 offset asm("r0") = index * 2;
                    register u16 *scores asm("r3") = D_0200E276;
                    register u32 score asm("r1");

                    offset += (u32)scores;
                    score = 10000;

                    *(u16 *)offset = score;
                }
                else
                {
                    register u32 offset asm("r2") = index * 2;
                    register u16 *scores asm("r0") = D_0200E276;
                    register u32 value asm("r0");
                    register u32 field_offset asm("r3");
                    register u32 target_base asm("r1");

                    offset += (u32)scores;
                    value = *target * width;

                    field_offset = 0x10F0;

                    target_base = (u32)base + field_offset;

                    value = *(u32 *)(value + target_base);
                    *(u16 *)offset = value;
                }
            }
            else
            {
                register u8 *base asm("r1") = D_0200EB84;
                register u32 selected_offset asm("r2") = 0x21ED;
                register union HelperWord value asm("r0");
                register u32 attacker_offset asm("r3");
                register u8 *mapping asm("r1");
                register const u8 *target asm("r4");

                {
                    register u8 *value_address asm("r0") = base;
                    value_address += selected_offset;
                    value.word = *value_address;
                }
                attacker_offset = stride;

                attacker_offset *= value.word;
                value.word = attacker_offset;
                value.word += (u32)units;

                mapping = (u8 *)D_086D41CC;

                target = (const u8 *)(index + (u32)mapping);

                {
                    register u32 selected_target asm("r1") = *target;
                    register u32 target_offset asm("r2");

                    target_offset = stride;

                    selected_target = target_offset * selected_target;
                    selected_target += (u32)units;
                    *(D_0200E270 + index) = func_08034500((void *)value.word, (void *)selected_target, part);
                }
                {
                    register u32 offset asm("r1") = index * 2;
                    register u16 *scores asm("r3") = D_0200E276;
                    register u32 value asm("r0");
                    register union HelperWord target_offset asm("r2");
                    register u8 *field asm("r3");

                    offset += (u32)scores;
                    value = *target;

                    target_offset.word = stride * value;
                    value = target_offset.word;
                    field = D_0200EB84 + 24;

                    value += (u32)field;
                    value = *(u32 *)value;
                    *(u16 *)offset = value;
                }
            }
        }
        else
            D_0200E270[index] = enabled;
        {
            register u32 next asm("r0") = index + 1;
            asm("" : : "r"(next));
            index = (u8)next;
        }
    } while (index <= 5);
}
