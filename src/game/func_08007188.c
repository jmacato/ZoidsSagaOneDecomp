#include "types.h"

struct Map
{
    u16 background;
    u16 area;
    u16 scale;
    u16 tilemap;
    u16 music;
    u8 pad_A[0x12];
};

struct Background
{
    void *tiles;
    void *characters;
    void *palette;
    void *map;
    void *sprites;
    u16 width;
    u16 height;
};

struct Actor
{
    u16 id;
    u16 kind;
    u16 x;
    u16 y;
    u32 script;
    u16 field_C;
    u16 field_E;
    u16 field_10;
    u16 field_12;
};

struct State
{
    u8 area;
    u8 previous_area;
    u16 map;
    u16 background;
    u16 count;
    u16 *tilemap;
    u8 *buffer;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u16 scale;
    u16 music;
    u16 field_1C;
    u16 field_1E;
    u16 field_20;
};
extern struct State D_0200000C;

extern struct
{
    u8 pad_0[2];
    u8 area;
} D_02000B5C;

extern const struct Map D_0831B164[];
extern const struct Background D_081E6F94[];
extern u16 D_0200E8A4[];
extern u8 D_02018E44[];
extern u16 D_0300239C[];
extern u32 D_03004B9C[8];

void func_08000D1C(s32);
void func_08001D04(s32);
void func_0805D288(const void *, void *);
void func_0805D28C(const void *, void *);
void func_08006E4C(u8);
void func_08006DFC(u8);
void func_08001150(const void *, s32, s32, s32, s32, s32, s32);
void func_08008690(s32, s32, s32, s32, s32, s32, s32, s32, s32, u32, s32, s32);
s32 func_08008A94(void);
s32 func_080019B4(s32);


struct ActorGroup { u16 count; u16 pad; const struct Actor *actors; };
struct Object { u16 id; u8 x; u8 y; u16 kind; u16 index; u16 flag; u8 dir; u8 field_B; u8 field_C; u8 field_D; u8 pad_E[2]; };
struct Main { u32 flags; void *transition; };
extern struct Main D_02000000;
extern const struct ActorGroup D_0832819C[];
extern const u8 *D_08318CE4[];
extern u8 D_03004BBC[];
void func_0805D2A8(u16 *, u16 *, u16 *, void *);
s32 func_0805D29C(void *);

s32 func_08007188(u32 map_input, u32 x_input, u32 y_input, u32 direction)
{
    u16 parameters[3];
    register u32 held_direction asm("r3") = direction;
    u32 saved_width;
    union { u32 word; u16 low; } left;
    register u32 camera_left asm("r3");
    register u32 sentinel asm("r4");
    u32 saved_background;
    u32 selected_direction;
    u32 saved_twice;
    u16 scale;
    s32 horizontal, vertical;
    u32 top;
    register const struct Background *background_table asm("r8");
    register u16 *tile_buffer asm("r10");
    register u8 *map_buffer asm("r9");
    const struct Background *graphics;
    const struct Map *entry;
    register u16 *tiles asm("r9");
    register const struct Actor *actors asm("r9");
    u16 i, j, object_index;
    asm("" : "+r"(held_direction));
    {
        register u16 *first asm("r4") = parameters;
        register u16 *last asm("r1");
        *first = map_input;
        first++;
        asm("" : "+r"(first));
        *first = x_input;
        last = parameters + 2;
        asm("" : "+r"(last));
        *last = y_input;
    }
    asm("" : "+r"(held_direction) : : "memory");
    held_direction = (u16)held_direction;
    asm("" : "+r"(held_direction));
    asm volatile("" : "=m"(saved_width), "=m"(left.word), "=m"(saved_background), "=m"(selected_direction), "=m"(saved_twice));
    if (held_direction == 0xFFFF)
    {
        register u32 address asm("r0") = (u32)D_03004BBC;
        asm("" : "+r"(address));
        address += 0xB8;
        {
            register u32 value asm("r0") = *(u16 *)address;
            register u32 mask asm("r1") = 3;
            mask &= value;
            asm("" : "+r"(mask) : "r"(value));
            selected_direction = mask;
        }
    }
    else
        selected_direction = held_direction;
    func_08000D1C(1);
    asm("" : : : "r4", "r5", "r6", "r7", "r8", "r9", "r10", "memory");
    {
        register void *callback asm("r3") = D_02000000.transition;
        register u16 *map_parameter asm("r0") = parameters;
        register u16 *x_parameter asm("r1") = parameters + 1;
        register u16 *y_parameter asm("r2") = parameters + 2;
        asm("" : "+r"(map_parameter), "+r"(x_parameter), "+r"(y_parameter) : "r"(callback) : "memory");
        func_0805D2A8(map_parameter, x_parameter, y_parameter, callback);
    }
    {
        register struct State *state asm("r4") = &D_0200000C;
        register const struct Map *maps asm("r3") = D_0831B164;
        register u32 background_value asm("r0");
        asm("" : "+r"(maps) : "r"(state));
        state->scale = scale = maps[parameters[0]].scale;
        background_value = maps[parameters[0]].background;
        state->background = background_value;
        {
            register u32 selected asm("r3") = state->background;
            saved_background = selected;
            asm("" : : "r"(selected), "r"(background_value));
        }
        {
            register u32 raw_scale asm("r2") = scale;
            register s32 margin asm("r3");
            asm("" : "+r"(raw_scale));
            raw_scale = (u16)raw_scale;
            margin = 14;
            if (raw_scale == 4)
                margin = 13;
            asm("" : "+r"(margin));
            {
                register u32 parameter_base asm("r5") = (u32)parameters - 32;
                register u32 coordinate asm("r1");
                register u32 units asm("r0");
                register s32 result asm("r3");
                asm("" : "+r"(parameter_base) : "r"(margin), "r"(raw_scale), "r"(state), "r"(background_value) : "r6", "r7", "r8", "r9", "r10");
                coordinate = *(u16 *)(parameter_base + 34);
                asm("" : "+r"(coordinate) : "r"(margin), "r"(raw_scale), "r"(state), "r"(background_value));
                units = state->scale;
                units *= coordinate;
                result = units - margin;
                asm("" : "+r"(result) : "r"(units));
                horizontal = result;
            }
        }
    }
    {
        register u32 chosen_left asm("r0");
        if (!(horizontal & 0x8000))
        {
            register const struct Background *definitions asm("r1") = D_081E6F94;
            register u32 background asm("r0") = saved_background;
            register u32 twice asm("r2");
            register u32 address asm("r0");
            register u32 width asm("r5");
            register s32 maximum asm("r0");
            asm("" : "+r"(background) : "r"(definitions));
            twice = background << 1;
            asm("" : "+r"(twice) : "r"(background));
            address = twice + background;
            address = (address << 3) + (u32)definitions;
            width = ((const struct Background *)address)->width;
            maximum = width - 31;
            saved_twice = twice;
            asm("" : "+r"(maximum) : "r"(width), "r"(twice), "m"(saved_twice));
            if (horizontal <= maximum)
                chosen_left = (u16)horizontal;
            else
                chosen_left = (u16)(width - 30);
        }
        else
        {
            register u32 background asm("r1");
            chosen_left = 0;
            asm("" : "+r"(chosen_left));
            background = saved_background;
            asm("" : "+r"(background) : "r"(chosen_left));
            background <<= 1;
            saved_twice = background;
        }
        asm("" : "+r"(chosen_left));
        left.word = chosen_left;
        {
            register u32 parameter_base asm("r2") = (u32)parameters - 32;
            register u32 coordinate asm("r1");
            register u32 units asm("r0");
            register s32 result asm("r2");
            asm("" : "+r"(parameter_base) : "r"(chosen_left) : "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10");
            coordinate = *(u16 *)(parameter_base + 36);
            asm("" : "+r"(coordinate) : "r"(chosen_left));
            units = D_0200000C.scale;
            units *= coordinate;
            result = units - 8;
            asm("" : "+r"(result) : "r"(units));
            vertical = result;
        }
    }
    {
        register u32 chosen_top asm("r5");
        if (!(vertical & 0x8000))
        {
            register u32 twice asm("r3") = saved_twice;
            register u32 background asm("r4") = saved_background;
            register u32 address asm("r0");
            register const struct Background *definitions asm("r5");
            register u32 height asm("r1");
            register s32 maximum asm("r0");
            asm("" : : "r"(twice), "r"(background));
            address = twice + background;
            asm("" : "+r"(address));
            address <<= 3;
            asm("" : "+r"(address));
            definitions = D_081E6F94;
            asm("" : "+r"(definitions) : "r"(address));
            address += (u32)definitions;
            height = ((const struct Background *)address)->height;
            maximum = height - 21;
            asm("" : "+r"(maximum) : "r"(height));
            if (vertical <= maximum)
            {
                register u32 word asm("r0") = (u32)vertical << 16;
                asm("" : "+r"(word));
                chosen_top = word >> 16;
            }
            else
            {
                register u32 word asm("r0") = (height - 20) << 16;
                asm("" : "+r"(word));
                chosen_top = word >> 16;
            }
        }
        else
            chosen_top = 0;
        asm("" : "+r"(chosen_top));
        top = chosen_top;
    }
    {
        register const struct Background *definitions asm("r0") = D_081E6F94;
        register u32 twice asm("r1");
        register u32 background asm("r2");
        register u32 offset asm("r4");
        background_table = definitions;
        asm("" : "+r"(background_table) : "r"(definitions));
        twice = saved_twice;
        background = saved_background;
        asm("" : : "r"(twice), "r"(background));
        offset = twice + background;
        asm("" : "+r"(offset));
        offset <<= 3;
        graphics = (const struct Background *)(offset + (u32)definitions);
        asm("" : "+l"(graphics) : "r"(offset), "r"(top));
        func_0805D288(graphics->tiles, (void *)0x05000000);
        func_08001D04(1);
        {
            register u32 address asm("r0") = (u32)background_table + 4;
            asm("" : "+r"(address));
            address = offset + address;
            {
                register const void *data asm("r0") = *(const void **)address;
                asm("" : "+r"(data));
                func_0805D288(data, (void *)0x06008000);
            }
        }
        func_08001D04(1);
        {
            register u32 address asm("r0") = (u32)background_table + 8;
            register const void *data asm("r0");
            register u16 *destination asm("r3");
            asm("" : "+r"(address));
            address = offset + address;
            data = *(const void **)address;
            asm("" : "+r"(data));
            destination = D_0200E8A4;
            tile_buffer = destination;
            asm("" : "+r"(tile_buffer) : "r"(destination), "r"(data));
            func_0805D28C(data, tile_buffer);
        }
        func_08001D04(1);
        {
            register u32 address asm("r0") = (u32)background_table + 12;
            register const void *data asm("r0");
            register u8 *destination asm("r4");
            asm("" : "+r"(address));
            offset += address;
            data = *(const void **)offset;
            asm("" : "+r"(data));
            destination = D_02018E44;
            map_buffer = destination;
            asm("" : "+r"(map_buffer) : "r"(destination), "r"(data));
            func_0805D28C(data, map_buffer);
        }
    }
    func_08001D04(1);
    func_08001D04(1);
    {
        register struct State *state asm("r4") = &D_0200000C;
        register const struct Map *maps asm("r7") = D_0831B164;
        u16 area;
        register u16 *computed_tiles asm("r2");
        asm("" : "+r"(state), "+r"(maps));
        area = maps[parameters[0]].area;
        asm("" : : "r"(area));
        state->area = area;
        D_02000B5C.area = area;
        {
            register u32 current asm("r0") = (u8)area;
            register u32 previous asm("r1");
            asm("" : : "r"(current));
            previous = state->previous_area;
            asm("" : : "r"(previous));
            if (current != previous)
            {
                func_08006E4C(state->area);
                state->previous_area = state->area;
                func_08006DFC((u8)(state->previous_area - 1));
            }
        }
        state->map = parameters[0];
        state->count = D_0832819C[parameters[0]].count;
        computed_tiles = tile_buffer + maps[parameters[0]].tilemap;
        state->tilemap = computed_tiles;
        {
            register u8 *current_buffer asm("r3") = map_buffer;
            asm("" : "+r"(current_buffer));
            state->buffer = current_buffer;
        }
        {
            register u32 clip_base asm("r0") = (u32)&left - 44;
            asm("" : "+r"(clip_base) : "r"(state), "r"(maps), "r"(computed_tiles), "r"(top), "l"(graphics) : "r1", "r3", "r8", "r9", "r10");
            state->x = *(u16 *)(clip_base + 44);
        }
        state->y = top;
        {
            register u32 *camera asm("r1") = D_03004B9C;
            asm("" : "+r"(camera));
            camera_left = left.word;
            asm("" : "+r"(camera_left) : "r"(camera));
            camera[4] = camera_left << 19;
            camera[5] = top << 19;
        }
        state->width = graphics->width;
        state->height = graphics->height;
        state->scale = maps[parameters[0]].scale;
        state->music = maps[parameters[0]].music;
        {
            register u32 zero asm("r0") = 0;
            asm("" : "+r"(zero) : "r"(computed_tiles), "r"(camera_left));
            state->field_1C = zero;
            state->field_1E = zero;
            state->field_20 = zero;
        }
        tiles = computed_tiles;
        asm("" : "+r"(tiles) : "r"(computed_tiles));
    }
    {
        register u32 width asm("r6") = graphics->width;
        saved_width = width;
        asm("" : : "r"(width), "m"(saved_width));
    }
    {
        register u32 row asm("r1") = top;
        register u32 bound asm("r0");
        register u32 end_row asm("r12");
        register u32 end_column_word asm("r10");
        asm("" : "+r"(row));
        bound = (u16)(row + 20);
        asm("" : "+r"(bound) : "r"(row));
        if (row != bound)
        {
            end_row = bound;
            asm("" : "+r"(end_row) : "r"(bound));
            bound = (camera_left + 30) << 16;
            end_column_word = bound;
            asm("" : "+r"(end_column_word) : "r"(bound));
            do
            {
                register u32 column asm("r3") = left.word;
                register u32 first_limit asm("r0") = (u16)(column + 30);
                register u32 next_row asm("r4") = row + 1;
                asm("" : "+r"(next_row) : "r"(row), "r"(column), "r"(first_limit));
                if (column != first_limit)
                {
                    register u16 *low_base asm("r2") = D_0300239C;
                    register u16 *destination_base asm("r8");
                    register u32 mask asm("r2");
                    register u32 row_offset asm("r7");
                    register u32 end_word asm("r5");
                    register u32 column_limit asm("r6");
                    register u32 width asm("r0");
                    register u32 product asm("r5");
                    destination_base = low_base;
                    asm("" : "+r"(destination_base) : "r"(low_base));
                    mask = 31;
                    bound = row & mask;
                    asm("" : "+r"(bound) : "r"(mask));
                    row_offset = bound << 5;
                    end_word = end_column_word;
                    column_limit = end_word >> 16;
                    asm("" : "+r"(column_limit) : "r"(end_word), "r"(row_offset) : "memory");
                    width = saved_width;
                    product = row * width;
                    asm("" : "+r"(product) : "r"(width));
                    do
                    {
                        register u32 destination_address asm("r1") = row_offset + (column & mask);
                        register u32 source_address asm("r0");
                        destination_address += 0x800;
                        destination_address <<= 1;
                        destination_address += (u32)destination_base;
                        asm("" : "+r"(destination_address));
                        source_address = (product + column) << 1;
                        asm("" : "+r"(source_address));
                        source_address += (u32)tiles;
                        *(u16 *)destination_address = *(u16 *)source_address;
                        bound = (column + 1) << 16;
                        asm("" : "+r"(bound));
                        column = bound >> 16;
                        asm("" : "+r"(column));
                    } while (column != column_limit);
                }
                bound = next_row << 16;
                asm("" : "+r"(bound));
                row = bound >> 16;
                asm("" : "+r"(row));
            } while (row != end_row);
        }
    }
    {
        register u32 twice asm("r1") = saved_twice;
        register u32 background asm("r2") = saved_background;
        register u32 address asm("r0");
        register u32 definitions asm("r1");
        asm("" : : "r"(twice), "r"(background));
        address = (twice + background) << 3;
        asm("" : "+r"(address));
        definitions = (u32)D_081E6F94;
        asm("" : "+r"(definitions) : "r"(address));
        definitions += 16;
        address += definitions;
        {
            register const void *data asm("r0") = *(const void **)address;
            asm("" : "+r"(data));
            func_08001150(data, 32, 32, 32, 0, 0x60, 0);
        }
    }
    {
        register const struct Actor *first asm("r0") = D_0832819C[parameters[0]].actors;
        register u32 id asm("r1");
        register const struct Actor *tail asm("r4");
        register u32 parameter_base asm("r3");
        actors = first;
        asm("" : "+r"(actors) : "r"(first));
        id = first->id;
        asm("" : "+r"(id) : "r"(first));
        func_08008690(1, id,
                     ({ register u32 coordinate asm("r2");
                        parameter_base = (u32)parameters - 32;
                        asm("" : "+r"(parameter_base));
                        coordinate = *(u16 *)(parameter_base + 34);
                        asm("" : "+r"(coordinate) : "r"(parameter_base)); coordinate; }),
                     *(u16 *)(parameter_base + 36), first->kind, 0,
                     ({ tail = actors; asm("" : "+r"(tail)); tail->field_C; }),
                     tail->field_E, tail->field_12, tail->script,
                     ({ register u32 direction_value asm("r5") = selected_direction;
                        asm("" : : "r"(direction_value)); direction_value; }),
                     ({ sentinel = 0xFFFF; asm("" : : "r"(sentinel)); sentinel; }));
    }
    func_08008A94();
    func_08001D04(1);
    {
        register const struct Map *definitions asm("r1") = D_0831B164;
        register u32 selected_map asm("r2");
        register u32 map_flags asm("r1");
        asm("" : "+r"(definitions));
        selected_map = parameters[0];
        map_flags = definitions[selected_map].area;
        asm("" : "+r"(map_flags) : "r"(selected_map));
        if (map_flags & 0x8000)
        {
            register u32 object_index asm("r8");
            register u32 zero asm("r0") = 0;
            register u32 object_base asm("r1");
            register u32 first_id asm("r0");
            u32 member;
            register volatile u32 *dma asm("r10");
            object_index = zero;
            asm("" : "+r"(object_index) : "r"(zero));
            object_base = (u32)&D_02000B5C;
            asm("" : "+r"(object_base));
            first_id = *(u16 *)(object_base + 0x50);
            if (first_id != sentinel)
            {
                register u32 scan_base asm("r3") = object_base;
                register u32 mask asm("r5") = 0x7FFF;
                asm("" : "+r"(scan_base) : "r"(mask));
                do
                {
                    register u32 low_index asm("r1") = object_index;
                    register u32 address asm("r0");
                    register u32 value asm("r1");
                    asm("" : "+r"(low_index));
                    address = (low_index << 4) + scan_base;
                    address += 0x50;
                    first_id = *(u16 *)address;
                    value = mask;
                    value &= first_id;
                    asm("" : "+r"(value) : "r"(selected_map));
                    if (value == selected_map)
                        goto records_found;
                    if (value > selected_map)
                        goto finish;
                    address = (object_index + 1) << 16;
                    asm("" : "+r"(address));
                    address >>= 16;
                    object_index = address;
                    asm("" : : "r"(object_index), "r"(address));
                    address = (address << 4) + scan_base;
                    address += 0x50;
                    first_id = *(u16 *)address;
                } while (first_id != sentinel);
            }
records_found:
            member = 1;
            asm("" : "+l"(member));
            if (member < D_0200000C.count)
            {
                register volatile u32 *channel asm("r2") = (volatile u32 *)0x040000D4;
                dma = channel;
                asm("" : "+r"(dma) : "r"(channel));
                do
                {
                    register u8 *record asm("r6");
                    register u32 next_member asm("r5");
                    register u32 base asm("r1") = (u32)&D_02000B5C;
                    register u32 index asm("r3") = object_index;
                    register u32 address asm("r0");
                    register u32 flags asm("r0");
                    asm("" : : "r"(base), "r"(index));
                    address = index << 4;
                    record = (u8 *)(address + base);
                    address = (u32)record + 0x50;
                    flags = *(u16 *)address;
                    {
                        register u32 mask asm("r4") = 0x8000;
                        register u32 low_mask asm("r1") = mask;
                        flags &= low_mask;
                        asm("" : "+r"(flags) : "r"(mask), "r"(low_mask));
                    }
                    if (flags)
                    {
                        register u8 *position asm("r0");
                        register u32 kind asm("r1");
                        register u32 coordinate_x asm("r2");
                        register u32 coordinate_y asm("r3");
                        register const struct Actor *metadata asm("r4");
                        next_member = member + 1;
                        position = record + 0x54;
                        asm("" : "+r"(position) : "r"(next_member));
                        kind = *(u16 *)position;
                        position -= 2;
                        coordinate_x = *position++;
                        asm("" : "+r"(position) : "r"(coordinate_x), "r"(kind));
                        coordinate_y = *position;
                        asm("" : "+r"(coordinate_y) : "r"(coordinate_x), "r"(kind));
                        {
                            register u32 offset asm("r4") = member << 2;
                            asm("" : "+r"(offset));
                            offset = (offset + member) << 2;
                            asm("" : "+r"(offset));
                            metadata = (const struct Actor *)(offset + (u32)actors);
                            asm("" : "+r"(metadata));
                        }
                        func_08008690(next_member, kind, coordinate_x, coordinate_y, metadata->kind,
                                     member << 4, *(u8 *)(record + 0x5A), *(u16 *)(record + 0x58),
                                     metadata->field_12, metadata->script, metadata->field_10, object_index);
                        {
                            register u8 *base asm("r1") = D_03004BBC;
                            register u32 offset asm("r0");
                            register u8 *created asm("r2");
                            asm("" : "+r"(base));
                            offset = (next_member * 17) << 3;
                            created = (u8 *)(offset + (u32)base);
                            asm("" : "+r"(created) : "r"(offset));
                            {
                                register u8 *address asm("r0") = record + 0x5B;
                                register u32 value asm("r1") = *address;
                                asm("" : "+r"(value));
                                address = created + 0x68;
                                *(u16 *)address = value;
                            }
                            {
                                register u8 *address asm("r0") = record + 0x5C;
                                register u32 value asm("r0") = *address;
                                register u8 *destination asm("r1");
                                asm("" : "+r"(value));
                                destination = created + 0x6A;
                                *(u16 *)destination = value;
                            }
                            {
                                register u8 *address asm("r0") = record + 0x5D;
                                register u32 value asm("r1") = *address;
                                asm("" : "+r"(value));
                                address = created + 0x6C;
                                *(u16 *)address = value;
                            }
                            {
                                register u8 *address asm("r0") = record + 0x56;
                                register u32 value asm("r1") = *(u16 *)address;
                                asm("" : "+r"(value));
                                address = created + 0x70;
                                *(u16 *)address = value;
                            }
                        }
                        func_08001D04(1);
                    }
                    else
                    {
                        register const u8 **palettes asm("r2") = D_08318CE4;
                        register const struct Actor *metadata asm("r1");
                        register u32 offset asm("r1");
                        register u32 source asm("r0");
                        register volatile u32 *channel asm("r2");
                        offset = member << 2;
                        asm("" : "+r"(offset) : "r"(palettes));
                        offset = (offset + member) << 2;
                        asm("" : "+r"(offset));
                        metadata = (const struct Actor *)(offset + (u32)actors);
                        asm("" : "+r"(metadata));
                        source = (u32)palettes[metadata->id * 8];
                        channel = dma;
                        asm("" : "+r"(channel) : "r"(source));
                        channel[0] = source;
                        {
                            register u32 destination asm("r0") = metadata->kind * 32;
                            register u32 palette_base asm("r3") = 0x05000200;
                            asm("" : "+r"(palette_base) : "r"(destination));
                            channel[1] = destination + palette_base;
                        }
                        channel[2] = 0x80000010;
                        (void)channel[2];
                        next_member = member + 1;
                    }
                    {
                        register u32 word asm("r0") = next_member << 16;
                        asm("" : "+r"(word));
                        member = word >> 16;
                        asm("" : "+l"(member));
                        word = (object_index + 1) << 16;
                        asm("" : "+r"(word));
                        object_index = word >> 16;
                        asm("" : "+r"(object_index));
                    }
                } while (member < D_0200000C.count);
            }
        }
        else
        {
            register u32 member asm("r7") = 1;
            asm("" : "+l"(member));
            while (member < D_0200000C.count)
            {
                register u32 next_member asm("r5") = member + 1;
                register const struct Actor *metadata asm("r0");
                register u32 offset asm("r0") = member << 2;
                asm("" : "+r"(offset) : "r"(next_member));
                offset = (offset + member) << 2;
                asm("" : "+r"(offset));
                metadata = (const struct Actor *)(offset + (u32)actors);
                asm("" : "+r"(metadata));
                func_08008690(next_member, metadata->id, metadata->x, metadata->y, metadata->kind,
                             member << 4, metadata->field_C, metadata->field_E, metadata->field_12,
                             metadata->script, metadata->field_10, 0xFFFF);
                func_08001D04(1);
                {
                    register u32 word asm("r5") = next_member << 16;
                    asm("" : "+r"(word));
                    member = word >> 16;
                }
            }
        }
    }
finish:
    if (D_0200000C.music)
        func_080019B4(D_0200000C.music);
    {
        register u32 definitions asm("r2") = (u32)D_0831B164;
        register u32 selected asm("r1");
        register u32 offset asm("r0");
        asm("" : "+r"(definitions));
        selected = parameters[0];
        asm("" : "+r"(selected));
        offset = ((selected << 3) - selected) << 2;
        definitions += 12;
        asm("" : "+r"(definitions) : "r"(offset));
        offset += definitions;
        return func_0805D29C(*(void **)offset);
    }
}
