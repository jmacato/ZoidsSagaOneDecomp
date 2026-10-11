#include "types.h"

#define DIMENSIONS(a, ra, va, b, rb, vb) do { \
    register s32 first asm(#ra) = va; \
    register s32 second asm(#rb); \
    asm("" : "+r"(first)); \
    frame.a = first; \
    second = vb; \
    asm("" : "+r"(second)); \
    frame.b = second; \
} while (0)

#define SINGLE_DIMENSION(field, reg, value) do { \
    register s32 dimension asm(#reg) = value; \
    asm("" : "+r"(dimension)); \
    frame.field = dimension; \
} while (0)
#define SHARED_VALUE(field, reg, value) do { \
    register s32 dimension asm(#reg) = value; \
    asm("" : "+r"(dimension)); \
    field = dimension; \
} while (0)

void func_08053150(u32 character_block, u32 screen_block, u32 palette_offset, u32 overwrite_priority)
{
    register u32 priority asm("r2");
    struct {
        vu32 character_block, screen_block, palette_offset, overwrite_priority;
        u16 *volatile oam;
        volatile s32 width, height;
        volatile s32 x_signed, y_signed;
        vu32 character_offset;
        u16 *volatile next_oam;
        vu32 y_shift, height_shift, horizontal_shift, vertical_shift;
        vu32 priority_shift;
        u16 *volatile tilemap;
    } frame;
    register u32 x asm("r8");
    u32 y;
    u16 horizontal;
    u16 vertical;
    u32 row;
    register u32 row_shift asm("r6");
    register s32 draw_priority asm("r12");
    u32 pixel;
    register u32 pixel_shift asm("r9");
    u16 *source;
    s32 signed_width;
    register s32 tile_width asm("r10");
    s32 signed_height;
    register vu32 *dma asm("r2");

    frame.character_block = (u8)character_block;
    frame.screen_block = (u8)screen_block;
    frame.palette_offset = (u8)palette_offset;
    frame.overwrite_priority = (u8)overwrite_priority;

    dma = (vu32 *)0x040000D4;
    asm("" : : "r"(dma));
    dma[0] = 0x05000200;
    {
        register s32 palette asm("r0") = frame.palette_offset;
        register s32 palette_shift asm("r1");
        register u32 destination asm("r0");
        asm("" : : "r"(palette));
        palette_shift = palette << 5;
        destination = 0x05000000;
        asm("" : : "r"(palette_shift), "r"(destination));
        destination = palette_shift + destination;
        dma[1] = destination;
        dma[2] = ((480 - palette_shift) / 4) | 0x84000000;
    }
    dma[2];
    priority = 3;
    asm("" : : "r"(priority));
    do
    {
        register u16 *first_oam asm("r1") = (u16 *)0x070003F8;
        asm("" : : "r"(first_oam));
        frame.oam = first_oam;
        frame.priority_shift = priority << 24;
        do
        {
            register s32 attribute0 asm("r6");
            register s32 attribute1 asm("r5");
            s32 attribute2;
            register u16 *current_oam asm("r2");
            register u32 raw asm("r0");
            register s32 bits asm("r1");

            asm("" : : : "r7", "r8", "r9", "r10", "r12");
            current_oam = frame.oam;
            asm("" : : "r"(current_oam));
            raw = current_oam[0];
            bits = 0x300;
            asm("" : : "r"(raw), "r"(bits));
            bits &= raw;
            attribute0 = raw;
            asm("" : : "r"(bits), "r"(attribute0));

            frame.next_oam = current_oam - 4;
            if (bits)
                goto next_sprite;
            {
                register u16 *priority_oam asm("r3") = frame.oam;
                asm("" : : "r"(priority_oam));
                raw = priority_oam[2];
            }
            bits = 0xC00;
            asm("" : : "r"(raw), "r"(bits));
            bits = (bits & raw) >> 10;
            {
                register s32 shifted asm("r5") = frame.priority_shift;
                register s32 current_priority asm("r2");
                asm("" : : "r"(shifted));
                current_priority = shifted >> 24;
                {
                    register s32 saved asm("r7") = raw;
                    asm("" : "+r"(saved) : "r"(current_priority), "r"(bits));
                    attribute2 = saved;
                }
                if (bits != current_priority)
                    goto next_sprite;
            }
            {
                register s32 shape_mask asm("r3") = 0xC000;
                s32 shape;
                s32 shared_height;
                s32 shared_width;
                asm("" : : "r"(shape_mask));
                shape = shape_mask & attribute0;
                asm("" : : "r"(shape));
                {
                    register s32 boundary asm("r4") = 0x4000;
                    asm("" : : "r"(boundary), "r"(shape));
                }
            if (shape == 0x4000)
                goto horizontal_shape;
            if (shape > 0x4000)
                goto upper_shape;
            if (shape == 0)
                goto square_shape;
            {
                register u16 *shape_oam asm("r0") = frame.oam;
                asm("" : : "r"(shape_oam));
                attribute1 = shape_oam[1];
                asm("" : "+r"(attribute1));
            }
            goto dimensions_done;
        upper_shape:
            if (shape == 0x8000)
                goto vertical_shape;
            {
                register u16 *shape_oam asm("r1") = frame.oam;
                asm("" : : "r"(shape_oam));
                attribute1 = shape_oam[1];
                asm("" : "+r"(attribute1));
            }
            goto dimensions_done;
        square_shape:
                {
                    register u16 *shape_oam asm("r2") = frame.oam;
                    asm("" : : "r"(shape_oam));
                    raw = shape_oam[1];
                }
                bits = shape_mask;
                asm("" : : "r"(raw), "r"(bits));
                bits &= raw;
                attribute1 = raw;
                asm("" : : "r"(bits), "r"(attribute1));
                if (bits == 0x4000)
                    goto square_16;
                if (bits > 0x4000)
                    goto square_upper;
                if (bits == 0)
                    goto square_8;
                goto dimensions_done;
        square_upper:
                if (bits == 0x8000)
                    goto square_32;
                if (bits == shape_mask)
                    goto square_64;
                goto dimensions_done;
        square_8:
                DIMENSIONS(height, r3, 8, width, r0, 8);
                goto dimensions_done;
        square_16:
                DIMENSIONS(height, r1, 16, width, r2, 16);
                goto dimensions_done;
        square_32:
                DIMENSIONS(height, r3, 32, width, r0, 32);
                goto dimensions_done;
        square_64:
                DIMENSIONS(height, r1, 64, width, r2, 64);
                goto dimensions_done;
        horizontal_shape:
                {
                    register u16 *shape_oam asm("r5") = frame.oam;
                    asm("" : : "r"(shape_oam));
                    raw = shape_oam[1];
                }
                bits = shape_mask;
                asm("" : : "r"(raw), "r"(bits));
                bits &= raw;
                attribute1 = raw;
                asm("" : : "r"(bits), "r"(attribute1));
                if (bits == shape)
                    goto horizontal_32_8;
                if (bits > 0x4000)
                    goto horizontal_upper;
                if (bits == 0)
                    goto horizontal_16_8;
                goto dimensions_done;
        horizontal_upper:
                if (bits == 0x8000)
                    goto horizontal_32_16;
                if (bits == shape_mask)
                    goto horizontal_64_32;
                goto dimensions_done;
        horizontal_16_8:
                DIMENSIONS(width, r0, 16, height, r1, 8);
                goto dimensions_done;
        horizontal_32_8:
                SINGLE_DIMENSION(width, r2, 32);
                SHARED_VALUE(shared_height, r3, 8);
                goto store_shared_height;
        horizontal_32_16:
                SHARED_VALUE(shared_width, r0, 32);
                goto store_width_height_16;
        horizontal_64_32:
                SINGLE_DIMENSION(width, r2, 64);
                SHARED_VALUE(shared_height, r3, 32);
                goto store_shared_height;
        vertical_shape:
                {
                    register u16 *shape_oam asm("r5") = frame.oam;
                    asm("" : : "r"(shape_oam));
                    raw = shape_oam[1];
                }
                bits = shape_mask;
                asm("" : : "r"(raw), "r"(bits));
                bits &= raw;
                attribute1 = raw;
                asm("" : : "r"(bits), "r"(attribute1));
                if (bits == 0x4000)
                    goto vertical_8_32;
                if (bits > 0x4000)
                    goto vertical_upper;
                if (bits == 0)
                    goto vertical_8_16;
                goto dimensions_done;
        vertical_upper:
                if (bits == shape)
                    goto vertical_16_32;
                if (bits == shape_mask)
                    goto vertical_32_64;
                goto dimensions_done;
        vertical_8_16:
                SHARED_VALUE(shared_width, r0, 8);
        store_width_height_16:
                {
                    register s32 width asm("r0") = shared_width;
                    asm("" : : "r"(width));
                    frame.width = width;
                    SINGLE_DIMENSION(height, r1, 16);
                }
                goto dimensions_done;
        vertical_8_32:
                SINGLE_DIMENSION(width, r2, 8);
                SHARED_VALUE(shared_height, r3, 32);
                goto store_shared_height;
        vertical_16_32:
                DIMENSIONS(width, r0, 16, height, r1, 32);
                goto dimensions_done;
        vertical_32_64:
                SINGLE_DIMENSION(width, r2, 32);
                SHARED_VALUE(shared_height, r3, 64);
        store_shared_height:
                {
                    register s32 height asm("r3") = shared_height;
                    asm("" : : "r"(height));
                    frame.height = height;
                }
        dimensions_done:
                ;
            }
            x = 0x1FF;
            asm("" : "+r"(x));
            {
                register s32 masked asm("r1") = x;
                asm("" : : "r"(masked));
                masked &= attribute1;
                x = masked;
                asm("" : : "r"(masked), "r"(x));
                if (masked > 255)
                {
                    register u32 delta asm("r2") = 0xFFFFFE00;
                    register u32 sum asm("r0");
                    asm("" : "+r"(delta));
                    sum = delta;
                    asm("" : : "r"(sum));
                    sum = masked + sum;
                    x = (u16)sum;
                    asm("" : : "r"(x));
                }
            }
            {
                register u32 low_y asm("r3") = 0xFF;
                register s32 original_y asm("r4");
                register s32 height asm("r5");
                register u32 shifted asm("r0");
                register s32 sum asm("r2");
                register s32 limit asm("r1");
                asm("" : : "r"(low_y));
                low_y &= attribute0;
                original_y = low_y;
                asm("" : : "r"(low_y), "r"(original_y));
                height = frame.height;
                asm("" : : "r"(height));
                shifted = height << 16;
                height = (s32)shifted >> 16;
                asm("" : : "r"(height), "r"(shifted));
                sum = original_y + height;
                limit = 256;
                asm("" : : "r"(sum), "r"(limit));
                frame.height_shift = shifted;
                signed_height = height;
                if (sum > limit)
                {
                    register u32 delta asm("r1") = 0xFFFFFF00;
                    register u32 wrapped asm("r0");
                    asm("" : "+r"(delta));
                    wrapped = delta;
                    asm("" : : "r"(wrapped));
                    wrapped = original_y + wrapped;
                    low_y = (u16)wrapped;
                    asm("" : : "r"(low_y));
                }
                y = low_y;
            }
            {
                register u32 raw_x asm("r2") = x;
                register u32 shifted_x asm("r0");
                register s32 signed_x asm("r1");
                register s32 width asm("r2");
                register s32 signed_y asm("r0");
                asm("" : : "r"(raw_x));
                shifted_x = raw_x << 16;
                signed_x = (s32)shifted_x >> 16;
                asm("" : : "r"(signed_x));
                frame.next_oam = frame.oam - 4;
                if (signed_x > 127)
                    goto next_sprite;
                width = frame.width;
                asm("" : : "r"(width));
                shifted_x = width << 16;
                asm("" : : "r"(shifted_x));
                width = (s32)shifted_x >> 16;
                asm("" : : "r"(width), "r"(signed_x));
                if (signed_x <= -width)
                    goto next_sprite;
                signed_width = width;
                signed_y = (s16)y;
                asm("" : : "r"(signed_y));
                if (signed_y > 127 || signed_y < -signed_height)
                    goto next_sprite;
            }
            {
                register u32 object_offset asm("r0") = 0x3FF;
                register u32 object_base asm("r1");
                register u16 *saved_source asm("r7");
                asm("" : : "r"(object_offset));
                object_offset &= attribute2;
                object_offset <<= 5;
                object_base = 0x06010000;
                asm("" : : "r"(object_offset), "r"(object_base));
                saved_source = (u16 *)(object_offset + object_base);
                asm("" : "+r"(saved_source));
                source = saved_source;
            }
            vertical = 0;
            if ((s16)vertical >= signed_height)
                goto next_sprite;
            tile_width = signed_width;
            asm("" : : "r"(tile_width));
        next_row:
            {
                register u32 current_y asm("r3") = y;
                register u32 current_vertical asm("r4") = vertical;
                horizontal = 0;
                asm("" : : "r"(current_y), "r"(current_vertical));
                current_y <<= 16;
                frame.y_shift = current_y;
                current_vertical <<= 16;
                frame.vertical_shift = current_vertical;
                if ((s16)horizontal >= tile_width)
                    goto end_row;
                current_y = (s32)current_y >> 16;
                frame.y_signed = current_y;
                {
                    register u32 character_offset asm("r5") = frame.character_block;
                    asm("" : : "r"(character_offset));
                    character_offset <<= 14;
                    frame.character_offset = character_offset;
                }
                draw_priority = (s32)frame.priority_shift >> 24;
                asm("" : : "r"(draw_priority));
                {
                    register u16 *tilemap asm("r2") = (u16 *)0x0300239C;
                    asm("" : : "r"(tilemap));
                    frame.tilemap = tilemap;
                }
            next_tile:
                {
                    {
                        register u32 initial_row asm("r4") = 0;
                        register u32 raw_x asm("r3") = x;
                        register u32 shifted_x asm("r0");
                        register u32 shifted_horizontal asm("r1");
                        asm("" : "+r"(initial_row) : "r"(raw_x));
                        row = initial_row;
                        shifted_x = raw_x << 16;
                        shifted_horizontal = horizontal << 16;
                        asm("" : : "r"(shifted_x), "r"(shifted_horizontal));
                        frame.horizontal_shift = shifted_horizontal;
                        frame.x_signed = (s32)shifted_x >> 16;
                    }
                next_tile_row:
                    {
                        pixel = 0;
                        row_shift = row << 16;
                        asm("" : : "r"(row_shift));
                    next_pixel_body:
                        {
                            register s32 dest_x asm("r3");
                            register s32 dest_y asm("r4");
                            register s32 current_pixel asm("r1");
                            register u32 shifted_pixel asm("r0") = pixel << 16;
                            register s32 base_x asm("r5");
                            current_pixel = (s32)shifted_pixel >> 16;
                            base_x = frame.x_signed;
                            dest_x = base_x + current_pixel;
                            pixel_shift = shifted_pixel;
                            asm("" : : "r"(dest_x), "r"(pixel_shift));
                            if ((u32)dest_x <= 127)
                            {
                                register s32 color asm("r2");
                                register s32 quotient asm("r0");
                                s32 visible;
                                register s32 row_value asm("r0");
                                register s32 base_y asm("r2");
                                asm("" : "+r"(row_shift));
                                row_value = (s32)row_shift >> 16;
                                base_y = frame.y_signed;
                                dest_y = base_y + row_value;
                                if (dest_y > 127)
                                    goto next_pixel;
                                asm("" : "+r"(dest_y));
                                if (dest_y < 0)
                                    goto next_pixel;
                                color = *source;
                                quotient = current_pixel;
                                asm("" : : "r"(quotient));
                                if (current_pixel < 0)
                                {
                                    quotient = current_pixel + 3;
                                    asm("" : : "r"(quotient));
                                }
                                quotient >>= 2;
                                quotient <<= 2;
                                quotient = current_pixel - quotient;
                                quotient = (s16)quotient;
                                quotient <<= 2;
                                color >>= quotient;
                                color &= 15;
                                asm("" : "+r"(color));
                                visible = color;
                                asm("" : "+r"(visible));
                                if (visible)
                                {
                                    register u16 *destination asm("r2");
                                    register u32 new_value asm("r0");
                                    register u32 final_color asm("r5");

                                    color = visible;
                                    {
                                        register u16 *palette_oam asm("r5") = frame.oam;
                                        register u32 palette_bits asm("r1");
                                        register u32 palette_mask asm("r0");
                                        register u32 palette_arg asm("r5");
                                        palette_bits = palette_oam[2];
                                        palette_mask = 0xF000;
                                        palette_mask &= palette_bits;
                                        palette_mask >>= 8;
                                        palette_arg = frame.palette_offset;
                                        palette_bits = palette_arg << 4;
                                        palette_mask += palette_bits;
                                        color |= palette_mask;
                                        palette_mask = color << 24;
                                        final_color = palette_mask >> 24;
                                        asm("" : : "r"(final_color));
                                    }
                                    {
                                        register s32 offset asm("r0");
                                        register u32 page asm("r1");
                                        register u32 page_arg asm("r0") = frame.screen_block;
                                        register u16 *tilemap asm("r1");
                                        register u32 entry asm("r1");
                                        page = page_arg << 10;
                                        offset = dest_x;
                                        if (dest_x < 0)
                                        {
                                            offset = dest_x + 7;
                                            }
                                        offset >>= 3;
                                        offset = page + offset;
                                        page = (dest_y >> 3) << 5;
                                        offset += page;
                                        offset <<= 16;
                                        offset = (u32)offset >> 15;
                                        tilemap = frame.tilemap;
                                        offset += (u32)tilemap;
                                        entry = *(u16 *)offset;
                                        offset = 0x3FF;
                                        offset &= entry;
                                        offset <<= 6;
                                        page = 0x06000000;
                                        asm("" : "+r"(page));
                                        offset += page;
                                        page = frame.character_offset;
                                        destination = (u16 *)(page + offset);
                                        offset = dest_x;
                                        asm("" : : "r"(offset));
                                        page = 7;
                                        offset &= page;
                                        offset >>= 1;
                                        offset <<= 1;
                                        destination = (u16 *)((u32)destination + offset);
                                        dest_y &= page;
                                        offset = dest_y << 3;
                                        destination = (u16 *)((u32)destination + offset);
                                        offset = 1;
                                        dest_x &= offset;
                                        asm("" : : "r"(dest_x), "r"(destination));
                                    }
                                    if (!dest_x)
                                    {
                                        register u32 previous asm("r1") = *destination;
                                        register s32 limit asm("r3") = frame.overwrite_priority;
                                        if (draw_priority > limit && (previous & 0xFF))
                                            goto next_pixel;
                                        new_value = (previous & 0xFF00) | final_color;
                                    }
                                    else
                                    {
                                        register u32 previous asm("r1") = *destination;
                                        register s32 limit asm("r0") = frame.overwrite_priority;
                                        if (draw_priority > limit && (previous & 0xFF00))
                                            goto next_pixel;
                                        new_value = previous & 0xFF;
                                        previous = final_color << 8;
                                        new_value |= previous;
                                    }
                                    *destination = new_value;
                                }
                            }
                        next_pixel:
                            {
                                register u32 saved_pixel asm("r2") = pixel_shift;
                                register s32 counter asm("r1");
                                asm("" : : "r"(saved_pixel));
                                counter = (s32)saved_pixel >> 16;
                                asm("" : : "r"(counter));
                                pixel = counter;
                            if ((pixel & 3) == 3)
                                source++;
                            pixel = (u16)(pixel + 1);
                            if ((s16)pixel <= 7)
                                goto next_pixel_body;
                            }
                        }
                        {
                            register u32 increment asm("r3") = 1 << 16;
                            register u32 next asm("r0");
                            asm("" : : "r"(increment));
                            next = row_shift + increment;
                            asm("" : : "r"(next));
                            row = next >> 16;
                            if ((s32)next >> 16 <= 7)
                                goto next_tile_row;
                        }
                    }
                    {
                        register u32 current_x asm("r5") = x;
                        register u32 next asm("r0");
                        register u32 increment asm("r1");
                        register u32 previous_horizontal asm("r2");
                        asm("" : : "r"(current_x));
                        next = current_x << 16;
                        increment = 8 << 16;
                        asm("" : : "r"(next), "r"(increment));
                        next += increment;
                        x = next >> 16;
                        asm("" : : "r"(x));
                        previous_horizontal = frame.horizontal_shift;
                        asm("" : : "r"(previous_horizontal), "r"(increment));
                        next = previous_horizontal + increment;
                        horizontal = next >> 16;
                        if ((s32)next >> 16 < tile_width)
                            goto next_tile;
                    }
                }
            end_row:
                {
                    register u32 current_x asm("r3") = x;
                    register s32 next asm("r0");
                    register s32 width asm("r5");
                    register u32 previous_y asm("r1");
                    register u32 increment asm("r2");
                    register u32 previous_vertical asm("r5");
                    register u32 previous_height asm("r1");
                    asm("" : : "r"(current_x));
                    next = (s16)current_x;
                    asm("" : : "r"(next));
                    width = tile_width;
                    asm("" : : "r"(width));
                    next -= width;
                    x = (u16)next;
                    asm("" : : "r"(x));
                    previous_y = frame.y_shift;
                    increment = 8 << 16;
                    asm("" : : "r"(previous_y), "r"(increment));
                    next = previous_y + increment;
                    y = (u32)next >> 16;
                    previous_vertical = frame.vertical_shift;
                    asm("" : : "r"(previous_vertical), "r"(increment));
                    next = previous_vertical + increment;
                    vertical = (u32)next >> 16;
                    previous_height = frame.height_shift;
                    asm("" : : "r"(previous_height));
                    if (next < (s32)previous_height)
                        goto next_row;
                }
            }
        next_sprite:
            {
                register u16 *next asm("r2") = frame.next_oam;
                asm("" : "+r"(next));
                frame.oam = next;
                if ((u32)next <= 0x06FFFFFF)
                    break;
            }
        } while (1);
        {
            register u32 value asm("r3") = frame.priority_shift;
            register u32 step asm("r5") = 0xFF000000;
            register u32 next asm("r0");
            asm("" : : "r"(value), "r"(step));
            next = value + step;
            priority = next >> 24;
            asm("" : : "r"(priority), "r"(next));
            if ((s32)next < 0)
                break;
        }
    } while (1);
}
