#include "types.h"

struct Piece {
    u16 tile, rotation, x, y, width, height;
    s16 scale_x, scale_y;
    u16 affine_flags, pad;
};
struct Sprite {
    u16 flags, attr0, attr1, attr2;
    s32 x, y;
    u16 offset_x, offset_y;
    const u16 **animations;
    const struct Piece **frames;
    u16 tile_offset, graphics_bytes;
    void *destination;
    const void *graphics, *current_graphics;
    const u16 *animation;
    u16 animation_id, first_frame, step, timer, speed;
    u16 screen_x, screen_y, piece_x, piece_y;
    u16 affine_index;
    s16 affine_x, affine_y;
    u16 affine_rotation;
    u8 pad_4A[0x3E];
};
struct Oam { u16 attr0, attr1, attr2; s16 affine; };
struct Affine { s16 x, y; u16 rotation; u16 pad; };
struct Frame {
    struct Affine affine;
    u32 piece_index, maximum, extra_width, sprite_offset;
    struct Affine *affine_pointer;
    u16 *index_pointer;
    struct Oam *oam;
};
extern struct Sprite D_03004BBC[];
extern u32 D_03004B9C[];
extern struct Oam D_02005C7C[];
extern u16 D_03005BAC;
extern u8 D_020060A4;
u32 advance_sprite_animation(u16, u16);
s32 func_0805D280(s32, s32);
u32 func_0805D290(const void *, void *, u32, u32);

u32 build_sprite_oam(u32 input)
{
    struct Frame frame;
    register u32 result asm("r0") = input;
    u32 selector;
    register struct Sprite *sprite asm("r6");
    register u32 sprite_offset asm("r5");
    u32 flags;
    register u16 *counter asm("r4");
    register const struct Piece *pieces asm("r9");
    {
        u16 selected;
        register struct Sprite *initial asm("r4");
        register u32 initial_flags asm("r5");
        register u32 camera_x asm("r8");
        register u32 camera_y asm("r3");
        register u32 word asm("r1") = result;
        register u32 zero asm("r1");
        register u32 maximum asm("r2");
        register struct Sprite *pool asm("r2");
        register u32 offset asm("r6");
        asm("" : "+r"(word));
        selected = (u16)word;
        asm("" : "+l"(selected) : : "r1", "r2", "r3", "r4", "r5", "r6");
        zero = 0;
        camera_x = zero;
        asm("" : "+r"(camera_x) : "r"(zero), "r"(selected));
        camera_y = 0;
        maximum = 255;
        frame.maximum = maximum;
        asm("" : : "r"(maximum), "r"(camera_y), "m"(frame.maximum));
        pool = D_03004BBC;
        asm("" : "+r"(pool));
        word = (selected << 4) + selected;
        offset = word << 3;
        initial = (struct Sprite *)(offset + (u32)pool);
        initial_flags = initial->flags;
        asm("" : "+r"(initial_flags) : "r"(initial), "r"(offset));
        if (!(initial_flags & 0x8000))
            return result;
        if (initial_flags & 0x1000) {
            register u32 camera asm("r1") = (initial_flags & 3) * 2;
            register u32 *camera_pool asm("r3") = D_03004B9C;
            register u32 coordinate asm("r2");
            asm("" : "+r"(camera), "+r"(camera_pool));
            coordinate = camera_pool[camera] >> 16;
            camera_x = coordinate;
            asm("" : "+r"(camera_x) : "r"(coordinate));
            camera++;
            camera_y = camera_pool[camera] >> 16;
        }
        {
            register struct Sprite *coordinate_sprite asm("r1");
            pool = D_03004BBC;
            asm("" : "+r"(pool));
            coordinate_sprite = (struct Sprite *)((u32)pool + offset);
            asm("" : "+r"(coordinate_sprite));
            initial->screen_x = ((u32)coordinate_sprite->x >> 16) - camera_x;
            pool = D_03004BBC;
            asm("" : "+r"(pool));
            coordinate_sprite = (struct Sprite *)((u32)pool + offset);
            asm("" : "+r"(coordinate_sprite));
            initial->screen_y = ((u32)coordinate_sprite->y >> 16) - camera_y;
        }
        if (initial_flags & 0x2000) {
            if ((s32)((initial->screen_x + 56) & 0xFFFF) > 320 ||
                (s32)((initial->screen_y + 32) & 0xFFFF) > 192) {
                word = initial_flags | 16;
                initial->flags = word;
                return result;
            }
            initial->flags = initial_flags & 0xFFEF;
        }
        {
            register u32 second_offset asm("r5");
            register struct Sprite *second_pool asm("r3");
            register struct Sprite *current asm("r6");
            register u32 current_flags asm("r2");
            word = (selected << 4) + selected;
            second_offset = word << 3;
            asm("" : "+r"(second_offset));
            second_pool = D_03004BBC;
            asm("" : "+r"(second_pool));
            current = (struct Sprite *)(second_offset + (u32)second_pool);
            asm("" : "+r"(current) : "r"(second_offset));
            sprite = current;
            sprite_offset = second_offset;
            current_flags = current->flags;
            if (current_flags & 0x800) {
                register u32 animate_flags asm("r1") = 0x400;
                asm("" : "+r"(animate_flags) : "r"(current_flags));
                animate_flags &= current_flags;
                asm("" : "+r"(animate_flags));
                result = advance_sprite_animation(selected, animate_flags);
            }
        }
    }
    {
        register u32 frame_id asm("r2") = sprite->step;
        register u32 address asm("r1");
        register const u16 *animation asm("r1");
        register const struct Piece **frames asm("r1");
        register const struct Piece *loaded asm("r2");
        register u32 zero asm("r4");
        register u32 first_tile asm("r1");
        register u32 sentinel asm("r2");
        asm("" : "+r"(frame_id));
        address = (u32)D_03004BBC;
        asm("" : "+r"(address));
        address += 0x2C;
        asm("" : "+r"(address));
        address = sprite_offset + address;
        animation = *(const u16 **)address;
        frame_id = animation[frame_id];
        asm("" : "+r"(frame_id));
        address = (u32)D_03004BBC;
        asm("" : "+r"(address));
        address += 0x18;
        asm("" : "+r"(address));
        address = sprite_offset + address;
        frames = *(const struct Piece ***)address;
        loaded = frames[frame_id];
        pieces = loaded;
        asm("" : "+r"(pieces) : "r"(loaded));
        zero = 0;
        frame.piece_index = zero;
        asm("" : : "r"(zero), "m"(frame.piece_index));
        first_tile = loaded->tile;
        sentinel = 0xFFFF;
        asm("" : "+r"(first_tile) : "r"(sentinel));
        if (first_tile == sentinel)
            goto finished;
    }
    counter = &D_03005BAC;
    if (*counter > 127)
        goto finished;
    {
    register struct Sprite *persistent asm("r10");
    frame.sprite_offset = sprite_offset;
    persistent = sprite;
    {
        register u16 *index_pointer asm("r6") = &sprite->affine_index;
        struct Affine *affine_pointer;
        asm("" : "+r"(index_pointer) : "r"(persistent));
        frame.index_pointer = index_pointer;
        affine_pointer = &frame.affine;
        asm("" : "+l"(affine_pointer) : "r"(counter) : "r1", "r2", "r3", "r5", "r6");
        frame.affine_pointer = affine_pointer;
    }
loop:
    {
        register u32 byte_offset asm("r8");
        register u32 next_count asm("r2");
        register u16 *count_ip asm("r12");
        const struct Piece *piece;
        register u32 shape asm("r1");
        {
        register struct Oam *oam asm("r6");
        register u32 value asm("r1") = 0;
        register struct Oam *oam_pool asm("r2");
        register struct Sprite *sprite_copy asm("r4");
        struct Sprite *second_copy;
        register u32 attr0 asm("r3");
        register u32 attr1 asm("r4");
        register u32 sprite_flags asm("r2");
        frame.extra_width = value;
        asm("" : : "r"(value), "m"(frame.extra_width));
        value = *counter;
        value <<= 3;
        oam_pool = D_02005C7C;
        asm("" : "+r"(oam_pool));
        oam = (struct Oam *)(value + (u32)oam_pool);
        sprite_copy = persistent;
        attr0 = sprite_copy->attr0;
        oam->attr0 = attr0;
        attr1 = sprite_copy->attr1;
        oam->attr1 = attr1;
        second_copy = persistent;
        asm("" : "+l"(second_copy) : "r"(attr0), "r"(attr1), "r"(oam) : "r0", "r1", "r2", "r5");
        value = second_copy->attr2;
        oam->attr2 = value;
        sprite_flags = second_copy->flags;
        value = 0x20;
        asm("" : "+r"(value));
        value &= sprite_flags;
        if (value) {
            register u32 mask asm("r1");
            register u32 retained_attr asm("r2");
            register u16 *index_address asm("r4");
            register u32 matrix_base asm("r5");
            u32 source_base;
            register u32 source_offset asm("r3");
            register struct Sprite *flag_address asm("r2");
            register u32 flip_mask asm("r3");
            u32 offset;
            result = 0x100;
            asm("" : "+r"(result));
            result |= attr0;
            oam->attr0 = result;
            mask = 0xC1FF;
            asm("" : "+r"(mask));
            result = mask;
            retained_attr = attr1;
            asm("" : "+r"(retained_attr) : "r"(result));
            retained_attr &= result;
            oam->attr1 = retained_attr;
            index_address = &persistent->affine_index;
            value = *index_address;
            result = (value & 31) << 9;
            oam->attr1 = result | retained_attr;
            retained_attr = 255;
            frame.maximum = retained_attr;
            asm("" : "+r"(index_address) : "r"(retained_attr), "m"(frame.maximum));
            value = *index_address;
            value <<= 5;
            matrix_base = (u32)D_02005C7C;
            asm("" : "+r"(matrix_base));
            matrix_base += 6;
            asm("" : "+r"(matrix_base));
            value += matrix_base;
            source_offset = frame.sprite_offset;
            source_base = (u32)&D_03004BBC[0].affine_x;
            asm("" : "+l"(source_base) : "r"(value), "r"(source_offset), "r"(matrix_base), "r"(index_address), "r"(oam) : "r0", "r2");
            result = func_0805D290((void *)(source_offset + source_base), (void *)value, 1, 8);
            flag_address = persistent;
            value = flag_address->flags;
            flip_mask = 0x100;
            asm("" : "+r"(flip_mask));
            value &= flip_mask;
            offset = frame.piece_index;
            asm("" : "+l"(offset) : "r"(result), "r"(value) : "r2", "r3");
            offset *= 2;
            asm("" : "+l"(offset) : "r"(result), "r"(value), "r"(flag_address), "r"(flip_mask));
            byte_offset = offset;
            asm("" : "+r"(byte_offset), "+r"(result) : "r"(value));
            if (value) {
                register u32 matrix_address asm("r2");
                value = *index_address;
                matrix_address = (value << 5) + matrix_base;
                value = -*(u16 *)matrix_address;
                *(u16 *)matrix_address = value;
            }
        } else {
            register u32 index asm("r2") = frame.piece_index;
            register u32 offset asm("r1");
            register u32 base asm("r7");
            register const struct Piece *source asm("r5");
            register u32 affine_flags asm("r2");
            asm("" : "+r"(index));
            offset = index * 2;
            asm("" : "+r"(offset) : : "r7");
            base = (u32)pieces;
            asm("" : "+r"(base));
            source = (const struct Piece *)(offset + (u32)base);
            asm("" : "+r"(source));
            affine_flags = source->affine_flags;
            byte_offset = offset;
            asm("" : "+r"(byte_offset) : "r"(affine_flags));
            if (affine_flags != 255) {
            u32 destination;
            register u32 index asm("r4");
            register u16 *affine_index asm("r5");
            u8 *allocation;
            register u32 scale asm("r1");
            register u32 affine_attr asm("r2");
            register u32 double_mask asm("r3");
            affine_attr = 0x100;
            asm("" : "+r"(affine_attr));
            affine_attr |= attr0;
            oam->attr0 = affine_attr;
            scale = source->affine_flags;
            double_mask = 0x200;
            result = double_mask;
            asm("" : "+r"(result) : "r"(double_mask), "r"(scale));
            result &= scale;
            if (result) {
                affine_attr |= double_mask;
                oam->attr0 = affine_attr;
            }
            scale = (u16)source->scale_x;
            asm("" : "+r"(scale));
            result = source->scale_x;
            if ((s32)result >= 0) {
                register struct Affine *target asm("r3");
                asm("" : "+r"(source));
                scale = (u16)source->scale_x;
                result = func_0805D280(65536, scale);
                target = frame.affine_pointer;
                target->x = result;
            } else {
                register struct Affine *target asm("r4");
                scale = (u16)-scale;
                result = func_0805D280(65536, scale);
                target = frame.affine_pointer;
                target->x = result;
            }
            {
                register u32 y_address asm("r2") = byte_offset;
                register const struct Piece *y_source asm("r2");
                register u32 retained_r3 asm("r3");
                register u32 retained_r4 asm("r4");
                asm("" : "+r"(y_address));
                y_address += (u32)pieces;
                y_source = (const struct Piece *)y_address;
                scale = (u16)y_source->scale_y;
                asm("" : "=r"(retained_r3), "=r"(retained_r4));
                result = y_source->scale_y;
                asm("" : : "r"(retained_r3), "r"(retained_r4), "r"(source), "r"(oam), "r"(result));
                if ((s32)result >= 0) {
                    register struct Affine *target asm("r1");
                    asm("" : "+r"(y_source));
                    scale = (u16)y_source->scale_y;
                    result = func_0805D280(65536, scale);
                    target = frame.affine_pointer;
                    target->y = result;
                } else {
                    register struct Affine *target asm("r2");
                    scale = (u16)-scale;
                    result = -func_0805D280(65536, scale);
                    target = frame.affine_pointer;
                    target->y = result;
                }
            }
            {
                register u32 rotation asm("r1");
                register u32 constant asm("r3");
                register u32 mask asm("r2");
                register struct Affine *target asm("r4");
                register u32 maximum asm("r7");
                result = byte_offset;
                asm("" : "+r"(result));
                result += (u32)pieces;
                asm("" : "+r"(result));
                rotation = ((const struct Piece *)result)->rotation;
                constant = 0xFF00;
                asm("" : "+r"(constant) : "r"(rotation));
                mask = constant;
                asm("" : "+r"(mask));
                rotation = -(rotation & mask);
                target = frame.affine_pointer;
                target->rotation = rotation;
                index = *(const u8 *)(result + 16);
                asm("" : "+r"(index));
                maximum = frame.maximum;
                asm("" : "+r"(maximum));
                if (maximum != 255) {
                    result = frame.maximum;
                    asm("" : "+r"(result));
                    if (result >= index)
                        goto maximum_ready;
                }
                frame.maximum = index;
maximum_ready:
                affine_index = &persistent->affine_index;
                asm("" : "+r"(affine_index));
                allocation = &D_020060A4;
                asm("" : "+l"(allocation) : "r"(index), "r"(affine_index), "r"(oam) : "r0", "r1", "r2", "r3");
                scale = *allocation;
                scale = index + scale;
                mask = *affine_index;
                asm("" : "+r"(mask));
                scale += mask;
                scale <<= 5;
                constant = (u32)&D_02005C7C[0].affine;
                asm("" : "+r"(constant));
                scale += constant;
                result = func_0805D290(&frame.affine, (void *)scale, 1, 8);
                constant = oam->attr1;
                mask = 0xC1FF;
                asm("" : "+r"(mask) : "r"(constant));
                scale = mask;
                asm("" : "+r"(scale));
                constant &= scale;
                oam->attr1 = constant;
                scale = *allocation;
                scale += index;
                mask = *affine_index;
                asm("" : "+r"(mask));
                scale += mask;
                mask = 31;
                asm("" : "+r"(mask));
                scale = (scale & mask) << 9;
                scale |= constant;
                oam->attr1 = scale;

            }
            {
                register struct Sprite *flag_source asm("r3") = persistent;
                register u32 mask asm("r2");
                register u32 base asm("r3");
                register u32 allocation_value asm("r7");
                scale = flag_source->flags;
                mask = 0x100;
                asm("" : "+r"(mask));
                scale &= mask;
                if (scale) {
                    scale = *affine_index;
                    scale += index;
                    allocation_value = *allocation;
                    asm("" : "+r"(allocation_value));
                    scale += allocation_value;
                    mask = 31;
                    asm("" : "+r"(mask));
                    scale = (scale & mask) << 5;
                    base = (u32)&D_02005C7C[0].affine;
                    asm("" : "+r"(base));
                    mask = scale + base;
                    asm("" : "+r"(mask));
                    scale = -*(u16 *)mask;
                    *(u16 *)mask = scale;
                    scale = oam->attr0;
                    allocation_value = 0x200;
                    asm("" : "+r"(allocation_value));
                    mask = allocation_value;
                    asm("" : "+r"(mask));
                    scale &= mask;
                    if (scale) {
                        scale = byte_offset;
                        asm("" : "+r"(scale));
                        scale += (u32)pieces;
                        scale = ((const struct Piece *)scale)->width;
                        frame.extra_width = scale;
                    }
                }
                base = byte_offset;
                asm("" : "+r"(base));
                base += (u32)pieces;
                scale = *(const u16 *)(base + 12);
                asm("" : "+r"(scale));
                {
                    register u32 threshold asm("r5") = 0x8000;
                    asm("" : "+r"(threshold));
                    if (scale > threshold) {
                        register u16 *index_source asm("r2") = frame.index_pointer;
                        scale = *index_source;
                        mask = (u32)&D_020060A4;
                        asm("" : "+r"(mask));
                        scale += index;
                        mask = *(u8 *)mask;
                        scale += mask;
                        mask = 31;
                        asm("" : "+r"(mask));
                        scale = (scale & mask) << 5;
                        mask = (u32)&D_02005C7C[0].affine;
                        asm("" : "+r"(mask));
                        mask = scale + mask;
                        scale = -*(u16 *)mask;
                        *(u16 *)mask = scale;
                    }
                    scale = *(const u16 *)(base + 14);
                    asm("" : "+r"(scale));
                    if (scale > threshold) {
                        register u16 *index_source asm("r3") = frame.index_pointer;
                        scale = *index_source;
                        mask = (u32)&D_020060A4;
                        asm("" : "+r"(mask));
                        scale += index;
                        mask = *(u8 *)mask;
                        scale += mask;
                        mask = 31;
                        asm("" : "+r"(mask));
                        scale = (scale & mask) << 5;
                        mask = (u32)&D_02005C7C[0].affine;
                        asm("" : "+r"(mask));
                        mask = scale + mask;
                        scale = -*(u16 *)(mask + 8);
                        *(u16 *)(mask + 8) = scale;
                    }
                }
            }
        } else {
            register u32 constant asm("r7") = 0xFEFF;
            register u32 mask asm("r2");
            register u32 value asm("r1");
            register struct Sprite *flag_source asm("r3");
            asm("" : "+r"(constant));
            value = constant;
            asm("" : "+r"(value));
            value &= attr0;
            oam->attr0 = value;
            mask = 0xCFFF;
            asm("" : "+r"(mask));
            value = mask;
            asm("" : "+r"(value));
            attr1 &= value;
            oam->attr1 = attr1;
            flag_source = persistent;
            mask = flag_source->flags;
            constant = 0x300;
            asm("" : "+r"(constant));
            value = constant;
            asm("" : "+r"(value));
            mask = (mask & value) << 4;
            attr0 = source->rotation;
            value = 3;
            value = (value & attr0) << 12;
            mask ^= value;
            mask |= attr1;
            oam->attr1 = mask;
        }
        }
        {
            register u32 height asm("r2");
            register u32 width asm("r4");
            register u32 height_copy asm("r3");
            shape = byte_offset;
            asm("" : "+r"(shape));
            shape += (u32)pieces;
            height = ((const struct Piece *)shape)->height;
            width = ((const struct Piece *)shape)->width;
            shape = height << 16;
            asm("" : "+r"(shape));
            height_copy = shape >> 16;
            asm("" : "+r"(height_copy));
            if (width == height_copy) {
                shape >>= 19;
                height = shape << 16;
                asm("" : "+r"(height));
                shape = height >> 16;
                if (shape <= 2)
                    shape = (u16)(shape - 1);
                else
                    shape = (height >> 19) + 2;
            } else {
                register u32 constant asm("r3");
                register u32 other_constant asm("r4");
                asm("" : "+r"(width), "+r"(height_copy));
                if (width > height_copy) {
                    shape = oam->attr0;
                    constant = 0x4000;
                    asm("" : "+r"(constant) : "r"(shape));
                    height = constant;
                    asm("" : "+r"(height));
                } else {
                    shape = oam->attr0;
                    other_constant = 0x8000;
                    asm("" : "+r"(other_constant) : "r"(shape));
                    height = other_constant;
                    asm("" : "+r"(height));
                }
                shape |= height;
                oam->attr0 = shape;
                shape = byte_offset;
                asm("" : "+r"(shape));
                shape += (u32)pieces;
                height = ((const struct Piece *)shape)->width;
                shape = ((const struct Piece *)shape)->height;
                height += shape;
                height = ((s32)height >> 4) - 1;
                asm("" : "+r"(height));
                height <<= 16;
                asm("" : "+r"(height));
                shape = height >> 16;
                height = shape;
                asm("" : "+r"(height));
                if (shape > 3)
                    height = 3;
                shape = height;
                asm("" : "+r"(shape));
            }
            shape <<= 14;
            height = oam->attr1;
            shape |= height;
            oam->attr1 = shape;
        }
        }
        {
            register struct Oam *pool asm("r3") = D_02005C7C;
            register u16 *count_source asm("r4") = &D_03005BAC;
            register u32 value asm("r1");
            register u32 offset asm("r7");
            register struct Sprite *current asm("r6");
            register u32 tile asm("r5");
            register u32 mask asm("r2");
            asm("" : "+r"(pool));
            asm("" : "+r"(count_source));
            value = *count_source;
            value <<= 3;
            value += (u32)pool;
            frame.oam = (struct Oam *)value;
            offset = frame.sprite_offset;
            value = (u32)D_03004BBC;
            asm("" : "+r"(value));
            current = (struct Sprite *)(offset + value);
            tile = current->tile_offset;
            mask = current->flags;
            offset = 0x4000;
            asm("" : "+r"(offset) : "r"(mask));
            value = offset;
            asm("" : "+r"(value));
            mask &= value;
            count_ip = count_source;
            asm("" : "+r"(count_ip) : "r"(mask));
            if (!mask) {
                value = byte_offset;
                asm("" : "+r"(value));
                value += (u32)pieces;
                value = ((const struct Piece *)value)->tile;
                tile += value;
            }
            {
                register u32 retained_tile asm("r3");
                register struct Oam *output asm("r4");
                mask = 0x3FF;
                asm("" : "+r"(mask));
                value = mask;
                asm("" : "+r"(value));
                retained_tile = tile;
                asm("" : "+r"(retained_tile));
                retained_tile &= value;
                output = frame.oam;
                value = output->attr2;
                offset = 0xFFFFFC00;
                asm("" : "+r"(offset));
                mask = offset;
                asm("" : "+r"(mask));
                value &= mask;
                value |= retained_tile;
                output->attr2 = value;
            }
            {
                register struct Oam *output asm("r3");
                register u32 byte asm("r4");
                register const struct Piece *piece_source asm("r5");
                value = (u32)count_ip;
                asm("" : "+r"(value));
                output = (struct Oam *)((*(u16 *)value << 3));
                asm("" : "+r"(output));
                mask = (u32)D_02005C7C;
                asm("" : "+r"(mask));
                output = (struct Oam *)((u32)output + mask);
                byte = ((u8 *)output)[5];
                mask = byte >> 4;
                piece_source = (const struct Piece *)byte_offset;
                asm("" : "+r"(piece_source));
                piece_source = (const struct Piece *)((u32)piece_source + (u32)pieces);
                value = piece_source->tile >> 12;
                mask += value;
                mask <<= 4;
                value = 15;
                value &= byte;
                value |= mask;
                ((u8 *)output)[5] = value;
                output = (struct Oam *)count_ip;
                asm("" : "+r"(output));
                value = *(u16 *)output;
                value <<= 3;
                byte = (u32)D_02005C7C;
                asm("" : "+r"(byte));
                {
                    struct Oam *x_output;
                    register struct Sprite *x_sprite asm("r4");
                    register u32 screen asm("r3");
                    register u32 flip_mask asm("r6");
                    x_output = (struct Oam *)(value + byte);
                    asm("" : "+l"(x_output) : "r"(piece_source), "r"(current) : "r0", "r1", "r2", "r3", "r4");
                    x_sprite = current;
                    screen = x_sprite->screen_x;
                    value = x_sprite->flags;
                    flip_mask = 0x100;
                    asm("" : "+r"(flip_mask));
                    value &= flip_mask;
                    if (value) {
                        value = -piece_source->x;
                        mask = piece_source->width;
                        value -= mask;
                        mask = x_sprite->offset_x;
                        value -= mask;
                        mask = frame.extra_width;
                        value -= mask;
                    } else {
                        value = piece_source->x;
                        mask = x_sprite->offset_x;
                        value += mask;
                    }
                    screen += value;
                    x_sprite->piece_x = screen;
                    screen <<= 23;
                    asm("" : "+r"(screen));
                    screen >>= 23;
                    value = x_output->attr1;
                    byte = 0xFFFFFE00;
                    asm("" : "+r"(byte));
                    mask = byte;
                    asm("" : "+r"(mask));
                    value &= mask;
                    value |= screen;
                    x_output->attr1 = value;
                }
            }
            {
                register u16 *count_copy asm("r6") = count_ip;
                register u32 pool_base asm("r7");
                register struct Oam *output asm("r3");
                register struct Sprite *y_sprite asm("r5");
                register u32 screen asm("r4");
                register u32 flip_mask asm("r6");
                asm("" : "+r"(count_copy));
                value = *count_copy;
                value <<= 3;
                pool_base = (u32)D_02005C7C;
                asm("" : "+r"(pool_base));
                output = (struct Oam *)(value + pool_base);
                value = frame.sprite_offset;
                mask = (u32)D_03004BBC;
                asm("" : "+r"(mask));
                y_sprite = (struct Sprite *)(value + mask);
                screen = y_sprite->screen_y;
                value = y_sprite->flags;
                flip_mask = 0x200;
                asm("" : "+r"(flip_mask));
                mask = flip_mask;
                asm("" : "+r"(mask));
                value &= mask;
                if (value) {
                    mask = byte_offset;
                    asm("" : "+r"(mask));
                    mask += (u32)pieces;
                    value = -((const struct Piece *)mask)->y;
                    mask = ((const struct Piece *)mask)->height;
                    value -= mask;
                    mask = y_sprite->offset_y;
                    value -= mask;
                } else {
                    value = byte_offset;
                    asm("" : "+r"(value));
                    value += (u32)pieces;
                    value = ((const struct Piece *)value)->y;
                    mask = y_sprite->offset_y;
                    value += mask;
                }
                screen += value;
                value = (u32)y_sprite;
                asm("" : "+r"(value));
                *(u16 *)(value + 0x40) = screen;
                value = 0xFFFF;
                asm("" : "+r"(value));
                value &= screen;
                ((u8 *)output)[0] = value;
            }
            {
                u16 *count_copy = count_ip;
                asm("" : "+l"(count_copy) : : "r0", "r1", "r2", "r3", "r4", "r5", "r6");
                value = *count_copy;
                mask = value + 1;
                asm("" : "+r"(mask));
                *count_copy = mask;
                next_count = mask;
                asm("" : "+r"(next_count));
            }
        }
        frame.piece_index = (u16)(frame.piece_index + 10);
        {
            register u32 end_tile asm("r1");
            register u32 sentinel asm("r3");
            end_tile = *(u16 *)((u32)pieces + frame.piece_index * 2);
            asm("" : "+r"(end_tile));
            sentinel = 0xFFFF;
            asm("" : "+r"(sentinel));
            if (end_tile == sentinel)
                goto finished;
            counter = count_ip;
            asm("" : "+r"(counter));
            end_tile = (u16)next_count;
            if (end_tile > 127)
                goto finished;
        }
        goto loop;
    }
    }
finished:
    {
        register u32 maximum asm("r4") = frame.maximum;
        asm("" : "+r"(maximum));
        if (maximum != 255) {
            register u8 *allocation asm("r2") = &D_020060A4;
            register u32 value asm("r1") = *allocation;
            value++;
            asm("" : "+r"(value));
            value = maximum + value;
            *allocation = value;
        }
    }
    return result;
}
