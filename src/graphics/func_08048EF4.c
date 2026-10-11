#include "types.h"

struct Digit
{
    u16 tile;
    u8 pad_2[0x12];
};

struct Row
{
    struct Digit digits[4];
    u8 pad_50[4];
};

extern u16 D_0200E4C6[];
extern struct Row D_0200E2CE[];
extern vu8 D_086D45D4[];

void func_08048EF4(u32 sprite, u32 index, u32 input_value)
{
    register u32 sprite_bits asm("r0") = sprite << 24;
    register u32 index_bits asm("r1") = index << 24;
    register u32 value asm("r5") = (u16)input_value;
    register u32 shown asm("r9");
    register u32 adjustment asm("r7");
    register u32 row asm("r10");
    register u32 remainder asm("r0");
    u16 thousands;
    register u32 hundreds asm("r8");
    u16 tens;

    asm("" : : "r"(sprite_bits), "r"(index_bits), "r"(value));
    shown = 0;
    adjustment = 0xE8000000;
    asm("" : "+r"(adjustment) : "r"(shown));
    /* The row selector subtracts 24 and wraps to one byte. */
    row = (sprite_bits + adjustment) >> 24;
    {
        register u16 *base asm("r0") = D_0200E4C6;
        register u16 *field asm("r1");

        asm("" : "+r"(base));
        field = (u16 *)((index_bits >> 23) + (u32)base);
        *field = value;
    }
    asm("" : : "r"(shown), "r"(row));
    if (value <= 9999)
    {
        thousands = value / 1000;
        remainder = value - thousands * 1000;
        value = (u16)remainder;
        {
            register u32 blank asm("r0") = thousands == 0;

            asm("" : "+r"(blank));
            if (blank)
                thousands = 10;
            else
                shown = 1;
        }
        hundreds = (u16)(value / 100);
        remainder = value - hundreds * 100;
        value = (u16)remainder;
        if ((hundreds == 0) & (shown == 0))
            hundreds = 10;
        else
            shown = 1;
        tens = value / 10;
        remainder = value - tens * 10;
        value = (u16)remainder;
        if ((tens == 0) & (shown == 0))
            tens = 10;
        {
            register u8 *base asm("r3") = (u8 *)D_0200E2CE;
            register u32 stride asm("r0") = 0x54;
            register u32 offset asm("r4") = row;
            register u16 *first asm("r1");
            register vu8 *font asm("r2");
            register u32 tile asm("r0");
            register u8 *field asm("r0");
            register u32 next_tile asm("r1");
            register u32 digit asm("r7");

            asm("" : "+r"(base), "+r"(stride) : "r"(offset));
            offset *= stride;
            first = (u16 *)(offset + (u32)base);
            font = D_086D45D4;
            tile = *(vu8 *)((u32)thousands + (u32)font);
            *first = tile;
            field = base + 20;
            asm("" : "+r"(field));
            field = (u8 *)(offset + (u32)field);
            digit = hundreds;
            next_tile = *(vu8 *)(digit + (u32)font);
            asm("" : : "r"(field), "r"(next_tile), "r"(digit));
            *(u16 *)field = next_tile;
            field = base + 40;
            asm("" : "+r"(field));
            field = (u8 *)(offset + (u32)field);
            next_tile = *(vu8 *)((u32)tens + (u32)font);
            *(u16 *)field = next_tile;
            base += 60;
            offset += (u32)base;
            font = (vu8 *)((u32)value + (u32)font);
            tile = *font;
            asm("" : : "r"(base), "r"(offset), "r"(tile));
            *(u16 *)offset = tile;
        }
    }
    else
    {
        register u8 *base asm("r2") = (u8 *)D_0200E2CE;
        register u32 stride asm("r0") = 0x54;
        register u32 offset asm("r3") = row;
        register u16 *first asm("r1");
        register vu8 *font asm("r4");
        register u32 tile asm("r0");
        register u8 *field asm("r0");
        register u32 next_tile asm("r1");

        asm("" : "+r"(base), "+r"(stride) : "r"(offset));
        offset *= stride;
        first = (u16 *)(offset + (u32)base);
        font = D_086D45D4;
        tile = font[11];
        asm("" : : "r"(first), "r"(font), "r"(tile));
        *first = tile;
        field = base + 20;
        asm("" : "+r"(field));
        field = (u8 *)(offset + (u32)field);
        next_tile = font[11];
        *(u16 *)field = next_tile;
        field = base + 40;
        asm("" : "+r"(field));
        field = (u8 *)(offset + (u32)field);
        next_tile = font[11];
        *(u16 *)field = next_tile;
        base += 60;
        offset += (u32)base;
        tile = font[11];
        asm("" : : "r"(base), "r"(offset), "r"(tile));
        *(u16 *)offset = tile;
    }
}
