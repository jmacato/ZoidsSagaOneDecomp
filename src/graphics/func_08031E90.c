#include "types.h"

void func_08031E90(u8 *data, u32 amount_input, u32 flags_input)
{
    register u8 *palette asm("r12") = data;
    register u32 raw_amount asm("r1") = amount_input;
    register u32 raw_flags asm("r2") = flags_input;
    register u32 adjustment asm("r10");
    u32 flags;
    u16 channels[3];
    u8 selected[3];
    register u8 *selection asm("r6");
    u8 i;
    register u32 pos asm("r5");
    register u32 start asm("r1");
    register u32 color asm("r2");

    asm("" : "+r"(raw_amount), "+r"(raw_flags) : "r"(palette));
    adjustment = (u8)raw_amount;
    asm("" : "+r"(raw_flags) : "r"(adjustment));
    flags = (u8)raw_flags;
    {
        register u32 index asm("r1") = 0;
        register u8 *initial asm("r4");
        register u32 zero asm("r3");

        asm("" : : "r"(index));
        selection = selected;
        asm("" : : "r"(selection));
        initial = selection;
        asm("" : : "r"(initial));
        zero = 0;
        asm("" : : "r"(zero));
        do
        {
            register u32 next asm("r0");

            initial[index] = zero;
            next = (index + 1) << 24;
            asm("" : "+r"(next));
            index = next >> 24;
            asm("" : : "r"(index));
        } while (index < 3);
    }
    if (flags & 4)
        selection[0] = 1;
    if (flags & 8)
        selection[1] = 1;
    if (flags & 0x10)
        selection[2] = 1;
    pos = 0;
    asm("" : : "r"(pos));
    {
        register u16 *channel_base asm("r4") = channels;
        register u32 subtract asm("r9") = 1;
        register u32 masked asm("r7");
        register u32 threshold asm("r8");

        asm("" : : "r"(channel_base));
        asm("" : : "r"(subtract));
        masked = subtract & flags;
        asm("" : : "r"(masked));
        subtract = masked;
        asm("" : : "r"(subtract));
        threshold = adjustment;
        asm("" : : "r"(threshold));
        do
        {
            register u8 *reader asm("r2");
            register u32 low asm("r3");
            register u32 high asm("r0");
            register u32 next asm("r0");
            register u8 *byte asm("r0");
            register u32 blue asm("r0");

            start = pos;
            asm("" : : "r"(start));
            reader = palette;
            asm("" : : "r"(reader));
            low = reader[start];
            asm("" : : "r"(low));
            next = (start + 1) << 24;
            asm("" : "+r"(next));
            pos = next >> 24;
            byte = reader + pos;
            asm("" : : "r"(byte));
            high = *byte;
            asm("" : : "r"(high));
            color = high << 8;
            asm("" : : "r"(color));
            color |= low;
            next = (pos + 1) << 24;
            asm("" : "+r"(next));
            pos = next >> 24;
            channel_base[0] = color & 0x1F;
            channel_base[1] = (color & 0x3E0) >> 5;
            color &= 0x7C00;
            blue = color >> 10;
            asm("" : : "r"(blue));
            channel_base[2] = blue;
            for (i = 0; i < 3; i++)
            {
                if (selection[i])
                {
                    if (subtract)
                    {
                        if (channels[i] <= threshold)
                            channels[i] = 0;
                        else
                            channels[i] -= adjustment;
                    }
                    else
                    {
                        channels[i] += adjustment;
                        if (channels[i] > 31)
                            channels[i] = 31;
                    }
                }
            }
            channel_base[1] <<= 5;
            channel_base[2] <<= 10;
            color = 0;
            i = 0;
            asm("" : : "r"(color), "r"(i));
            start += (u32)palette;
            asm("" : : "r"(start));
            do
            {
                color |= channels[i];
                i++;
            } while (i < 3);
            {
                u8 *destination = (u8 *)start;
                u8 high = (color & 0xFF00) >> 8;
                asm("" : : "r"(high));
                destination[0] = color;
                destination[1] = high;
            }
        } while (pos < 32);
    }
}
