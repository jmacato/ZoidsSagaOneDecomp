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

s32 func_080079E8(u16 map, u32 raw_x, u32 raw_y, u32 raw_count, const struct Actor *actors)
{
    u16 x, y, count, saved_width;
    u32 saved_left;
    u32 saved_background, saved_twice;
    u16 scale;
    s32 margin;
    s32 horizontal;
    s32 vertical;
    register u32 left asm("r0");
    u16 top;
    const struct Background *graphics;
    register const struct Background *table asm("r9");
    register u8 *buffer asm("r10");
    const struct Map *entry;
    u16 *tilemap;
    u32 camera_left;
    u16 width;
    u16 i;
    u16 j;

    {
        register u32 value asm("r1") = (u16)raw_x;
        asm("" : : "r"(value));
        x = value;
    }
    {
        register u32 value asm("r2") = (u16)raw_y;
        asm("" : : "r"(value));
        y = value;
    }
    {
        register u32 value asm("r3") = (u16)raw_count;
        asm("" : : "r"(value));
        count = value;
    }
    func_08000D1C(1);
    D_0200000C.scale = scale = D_0831B164[map].scale;
    D_0200000C.background = D_0831B164[map].background;
    {
        register u32 initial_background asm("r4") = D_0200000C.background;
        saved_background = initial_background;
        asm("" : : "r"(initial_background));
    }
    {
        register u32 raw_scale asm("r1") = scale;
        asm("" : "+r"(raw_scale));
        scale = raw_scale;
    }
    margin = 14;
    if (scale == 4)
        margin = 13;
    {
        register u32 units asm("r0") = D_0200000C.scale;
        register u32 coordinate asm("r1");
        asm("" : : "r"(units));
        coordinate = x;
        asm("" : : "r"(units), "r"(coordinate));
        horizontal = units * coordinate - margin;
    }
    if (!(horizontal & 0x8000))
    {
        register const struct Background *definitions asm("r1") = D_081E6F94;
        register u32 background asm("r4");
        u32 twice;
        register u16 viewport_width asm("r5");
        s32 maximum;
        register u32 address asm("r0");
        asm("" : : "r"(definitions));
        background = saved_background;
        asm("" : : "r"(definitions), "r"(background));
        twice = background << 1;
        asm("" : "+l"(twice) : "r"(definitions), "r"(background), "l"(horizontal) : "r0", "r5");
        address = twice + background;
        asm("" : : "r"(address));
        address = (address << 3) + (u32)definitions;
        asm("" : : "r"(address));
        viewport_width = ((const struct Background *)address)->width;
        asm("" : : "r"(viewport_width));
        maximum = viewport_width - 31;
        saved_twice = twice;
        if (horizontal <= maximum)
            left = (u16)horizontal;
        else
            left = (u16)(viewport_width - 30);
    }
    else
    {
        register u32 background asm("r1");
        left = 0;
        asm("" : : "r"(left));
        background = saved_background;
        asm("" : : "r"(background));
        background <<= 1;
        asm("" : : "r"(left), "r"(background));
        saved_twice = background;
    }
    asm("" : : "r"(left));
    saved_left = left;
    {
        register u32 units asm("r0") = D_0200000C.scale;
        register u32 coordinate asm("r2");
        asm("" : : "r"(units));
        coordinate = y;
        asm("" : : "r"(units), "r"(coordinate));
        vertical = units * coordinate - 8;
    }
    if (!(vertical & 0x8000))
    {
        register u32 twice asm("r3") = saved_twice;
        register u32 background asm("r4") = saved_background;
        register u32 address asm("r0");
        u16 viewport_height;
        asm("" : : "r"(twice), "r"(background));
        address = twice + background;
        asm("" : : "r"(address));
        address <<= 3;
        asm("" : : "r"(address));
        address += (u32)D_081E6F94;
        asm("" : : "r"(address));
        viewport_height = ((const struct Background *)address)->height;
        if (vertical <= viewport_height - 21)
            top = (u16)vertical;
        else
            top = (u16)(viewport_height - 20);
    }
    else
        top = 0;
    asm("" : "+l"(top) : : "r5", "r7");
    {
        register const struct Background *definitions asm("r2") = D_081E6F94;
        register u32 byte_offset asm("r4");
        register u32 twice asm("r3");
        register u32 background asm("r0");
        asm("" : : "r"(definitions));
        table = definitions;
        asm("" : : "r"(table));
        twice = saved_twice;
        background = saved_background;
        asm("" : : "r"(twice), "r"(background));
        byte_offset = twice + background;
        asm("" : : "r"(byte_offset));
        byte_offset <<= 3;
        asm("" : : "r"(byte_offset), "r"(definitions));
        graphics = (const struct Background *)(byte_offset + (u32)definitions);
        asm("" : "+l"(graphics), "+r"(byte_offset) : "r"(top) : "r5");
        func_0805D288(graphics->tiles, (void *)0x05000000);
        func_08001D04(1);
        {
            register u32 address asm("r0") = (u32)table + 4;
            asm("" : : "r"(address));
            address = byte_offset + address;
            asm("" : : "r"(address));
            {
                register const void *data asm("r0") = *(const void **)address;
                asm("" : : "r"(data));
                func_0805D288(data, (void *)0x06008000);
            }
        }
        func_08001D04(1);
        {
            register u32 address asm("r0") = (u32)table + 8;
            asm("" : : "r"(address));
            address = byte_offset + address;
            asm("" : : "r"(address));
            func_0805D28C(*(const void **)address, D_0200E8A4);
        }
        func_08001D04(1);
        {
            register u32 address asm("r0") = (u32)table + 12;
            register const void *map_data asm("r0");
            register u8 *destination asm("r1");
            asm("" : : "r"(address));
            byte_offset += address;
            asm("" : : "r"(byte_offset));
            map_data = *(const void **)byte_offset;
            destination = D_02018E44;
            asm("" : : "r"(map_data), "r"(destination));
            buffer = destination;
            asm("" : : "r"(map_data), "r"(buffer), "r"(destination));
            func_0805D28C(map_data, destination);
        }
    }
    func_08001D04(1);
    func_08001D04(1);
    {
        register struct State *state asm("r4") = &D_0200000C;
        register const struct Map *maps asm("r1");
        register u32 index asm("r2");
        u16 area;
        asm("" : : "r"(state));
        maps = D_0831B164;
        index = map;
        asm("" : : "r"(maps), "r"(index));
        entry = (const struct Map *)(index * sizeof(struct Map) + (u32)maps);
        area = entry->area;
        asm("" : : "r"(area));
        D_0200000C.area = area;
        D_02000B5C.area = area;
        {
        register u32 current asm("r0") = (u8)area;
        register u32 previous asm("r3");
        asm("" : : "r"(current));
        previous = D_0200000C.previous_area;
        asm("" : : "r"(previous));
        if (current != previous)
        {
            func_08006E4C(D_0200000C.area);
            D_0200000C.previous_area = D_0200000C.area;
            func_08006DFC(D_0200000C.previous_area - 1);
        }
        }
        {
            register u32 selected_map asm("r0") = map;
            asm("" : : "r"(selected_map));
            D_0200000C.map = selected_map;
            D_0200000C.count = count;
            asm("" : : "r"(selected_map));
        }
        {
            register u32 offset asm("r2") = entry->tilemap << 1;
            register u16 *base asm("r3");
            asm("" : : "r"(offset));
            base = D_0200E8A4;
            asm("" : : "r"(base));
            D_0200000C.tilemap = (u16 *)(offset + (u32)base);
        }
        {
            asm("" : : "l"(buffer) : "r3");
            D_0200000C.buffer = buffer;
            D_0200000C.x = (u16)saved_left;
            asm("" : : "l"(buffer));
        }
        D_0200000C.y = top;
        {
            register u32 *camera asm("r1") = D_03004B9C;
            asm("" : : "r"(camera));
            camera_left = saved_left;
            camera[4] = camera_left << 19;
        }
        D_03004B9C[5] = top << 19;
        D_0200000C.width = graphics->width;
        D_0200000C.height = graphics->height;
        D_0200000C.scale = entry->scale;
        D_0200000C.music = entry->music;
        {
            register u32 zero asm("r0") = 0;
            asm("" : : "r"(zero));
            D_0200000C.field_1C = zero;
            D_0200000C.field_1E = zero;
            D_0200000C.field_20 = zero;
        }
    }
    {
        register u16 *tiles asm("r8") = D_0200000C.tilemap;
        u32 row;
        u16 limit;
        register u32 viewport_width asm("r1");
        asm("" : : "r"(tiles));
        viewport_width = graphics->width;
        saved_width = viewport_width;
        asm("" : : "r"(viewport_width));
        row = top;
        limit = top + 20;
        if (row != limit)
        {
            register u32 end_row asm("r10") = limit;
            register u32 end_column asm("r9");
            register u32 bound asm("r0") = camera_left + 30;
            asm("" : : "r"(end_row), "r"(bound));
            bound <<= 16;
            end_column = bound;
            asm("" : : "r"(end_column));
            do
            {
                u32 column = saved_left;
                u32 next_row;
                register u32 first_limit asm("r0");
                asm("" : "+l"(column) : : "r0", "r2", "r4", "r5", "r6", "r7");
                first_limit = (u16)(column + 30);
                asm("" : : "r"(first_limit));
                next_row = row + 1;
                asm("" : "+l"(next_row) : "l"(row), "l"(column), "r"(first_limit) : "r2", "r4", "r5", "r6");
                if (column != first_limit)
                {
                    register u16 *destination asm("r12");
                    register u16 *address asm("r2") = D_0300239C;
                    register u32 mask asm("r4");
                    register u32 column_limit asm("r6");
                    u32 wrapped_row;
                    u32 row_offset;
                    asm("" : : "r"(address));
                    destination = address;
                    asm("" : : "r"(destination));
                    mask = 31;
                    asm("" : : "r"(mask));
                    wrapped_row = (row & mask) << 5;
                    asm("" : "+l"(wrapped_row) : "r"(column), "r"(mask), "r"(next_row) : "r0", "r5", "r6");
                    {
                        register u32 bound_value asm("r0") = end_column;
                        asm("" : : "r"(bound_value));
                        column_limit = bound_value >> 16;
                        asm("" : : "r"(column_limit));
                    }
                    row_offset = row * saved_width;
                    do
                    {
                        u32 tile_index = wrapped_row + (column & mask) + 0x800;
                        asm("" : "+l"(tile_index));
                        destination[tile_index] = tiles[row_offset + column];
                        column = (u16)(column + 1);
                    } while (column != column_limit);
                }
                asm("" : : "r"(next_row));
                row = (u16)next_row;
            } while (row != end_row);
        }
    }
    {
        register u32 twice asm("r1") = saved_twice;
        register u32 background asm("r2") = saved_background;
        register u32 address asm("r0");
        register u32 field asm("r1");
        asm("" : : "r"(twice), "r"(background));
        address = (twice + background) << 3;
        asm("" : : "r"(address));
        field = (u32)D_081E6F94;
        asm("" : : "r"(field));
        field += 16;
        asm("" : : "r"(field));
        address += field;
        {
            register const void *data asm("r0") = *(const void **)address;
            asm("" : : "r"(data));
            func_08001150(data, 0x20, 0x20, 0x20, 0, 0x60, 0);
        }
    }
    {
        const struct Actor *first = actors;
        asm("" : "+l"(first) : : "r0", "r1", "r2");
        func_08008690(1, first->id, x, y, first->kind, 0, first->field_C, first->field_E, first->field_12,
                      first->script, first->field_10, 0xFFFF);
    }
    func_08008A94();
    func_08001D04(1);
    for (i = 1; i < D_0200000C.count; i++)
    {
        u32 slot = i + 1;
        register u32 offset asm("r0");
        register const struct Actor *array asm("r4");
        const struct Actor *actor;
        asm("" : : "l"(slot));
        offset = i * sizeof(struct Actor);
        asm("" : : "r"(offset));
        array = actors;
        asm("" : : "r"(array));
        actor = (const struct Actor *)(offset + (u32)array);
        func_08008690(slot, actor->id, actor->x, actor->y, actor->kind, i << 4, actor->field_C,
                      actor->field_E, actor->field_12, actor->script, actor->field_10, 0xFFFF);
        func_08001D04(1);
    }
}
