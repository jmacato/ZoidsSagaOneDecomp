#include "types.h"

struct Model
{
    const void *palette;
    const void *tiles;
    u32 frames;
    u32 anims;
    u8 pad_10[0xA];
    u16 x;
    u16 y;
    u16 size;
};

struct Sprite
{
    u16 flags;
    u8 pad_2[4];
    u16 attr;
    s32 x;
    s32 y;
    u16 field_10;
    u16 field_12;
    u32 frames;
    u32 anims;
    u16 tile;
    u8 pad_1E[2];
    u32 vram;
    const void *tiles;
    u8 pad_28[0x26];
    u16 tile_x;
    u16 tile_y;
    u16 dest_x;
    u16 dest_y;
    u16 field_56;
    u16 field_58;
    u16 model;
    u16 field_5C;
    u16 flag;
    u16 state;
    u16 type;
    u16 field_64;
    u16 delay;
    u16 field_68;
    u16 field_6A;
    u16 field_6C;
    u16 field_6E;
    u16 field_70;
    u8 pad_72[0xE];
    u32 script;
    u8 pad_84[4];
};

extern struct Sprite D_03004BBC[];
extern const struct Sprite D_08328D24;
extern struct Model D_08318CE4[];
extern u16 D_030022D8;

struct Field
{
    u8 pad_0[0x18];
    u16 scale;
};

extern struct Field D_0200000C;

void func_0805ED60(void *, const void *, u32);
u16 func_080373F0(u8);
void func_08000CEC(u16, struct Sprite *, u16);
u16 func_08008434(u16, s32, s32);
s32 func_08001040(s32);
void func_08000BD8(u16, u16);

s32 func_08008690(u16 id, u16 model, u16 x, u16 y, u16 palette, s32 unused, u16 state, u16 delay, u16 type, u32 script, u16 anim, u16 field_64)
{
    struct Sprite spr;
    u16 found;
    u32 model_byte_offset;

    func_0805ED60(&spr, &D_08328D24, 0x88);
    if (id == 1)
        D_030022D8 = 0;
    if (model & 0x8000)
    {
        found = func_080373F0(model + 0x68);
        if (found > 0xFE)
        {
            model &= 0x7FFF;
            if (model == 0x98)
                model = 0x39;
            else if ((u16)(model - 0x99) <= 2)
                model = 0x46;
        }
        else
            model = found;
    }
    {
        register vu32 *dma asm("r5") = (vu32 *)0x040000D4;
        register struct Model *table asm("r8");
        register struct Model *entry asm("r6");
        register u32 model_stride asm("r4");
        register u32 has_tiles asm("r0");
        asm("" : : "r"(dma));
        {
            register struct Model *base asm("r0") = D_08318CE4;
            asm("" : : "r"(base));
            table = base;
            asm("" : : "r"(table));
            model_stride = model * sizeof(struct Model);
            asm("" : : "r"(model_stride));
            entry = (struct Model *)(model_stride + (u32)base);
            asm("" : : "r"(entry));
            asm volatile("" : "+r"(table));
        }

        dma[0] = (u32)entry->palette;
        dma[1] = 0x05000200 + palette * 32;
        dma[2] = 0x80000010;
        dma[2];
        func_08000CEC(id, &spr, anim);
        has_tiles = entry->size;
        asm("" : : "r"(has_tiles));
        model_byte_offset = model_stride;
        if (has_tiles)
        {
            D_03004BBC[id].flags &= 0xBFFF;
            {
                register u32 tiles_address asm("r0") = (u32)table + 4;
                asm("" : : "r"(tiles_address));
                tiles_address += model_byte_offset;
                asm("" : : "r"(tiles_address));
                dma[0] = *(const u32 *)tiles_address;
            }
            dma[1] = 0x06010000 + D_030022D8 * 32;
            dma[2] = (entry->size >> 1) | 0x80000000;
            dma[2];
        }
    }
    D_03004BBC[id].x = ((volatile struct Field *)&D_0200000C)->scale == 2 ? (D_0200000C.scale * x << 19) + ({ register u32 adjustment asm("r1") = 0xFFF80000; asm("" : : "r"(adjustment)); adjustment; }) : D_0200000C.scale * ({ register u32 coordinate asm("r4") = x; asm("" : : "r"(coordinate)); coordinate; }) << 19;
    {
        register struct Sprite *actors asm("r6") = D_03004BBC;
        register u32 offset asm("r4");
        asm("" : : "r"(actors));
        {
            register u32 scaled_id asm("r0") = id + (id << 4);
            asm("" : : "r"(scaled_id));
            offset = scaled_id << 3;
            asm("" : : "r"(offset));
        }
        {
            register u32 field asm("r0") = (u32)actors + 12;
            register s32 *vertical_position asm("r1");
            asm("" : : "r"(field));
            vertical_position = (s32 *)(offset + field);
            asm("" : : "r"(vertical_position));
            *vertical_position = D_0200000C.scale * ({ register u32 coordinate asm("r2") = y; asm("" : : "r"(coordinate)); coordinate; }) << 19;
            if (model == 0xF7)
                (*vertical_position)++;
        }
    {
        register struct Sprite *target asm("r8");
        register u16 zero asm("r5");
        {
            register u32 address asm("r0") = offset + (u32)actors;
            asm("" : : "r"(address));
            target = (struct Sprite *)address;
            asm("" : : "r"(target));
            address += 0x4E;
            asm("" : : "r"(address));
            zero = 0;
            asm("" : "+r"(zero));
            *(u16 *)address = x;
        }
        asm("" : "+r"(target));
    target->tile_y = y;
    target->dest_x = x;
    target->dest_y = y;
    target->field_56 = zero;
    target->field_58 = zero;
    target->model = model;
    target->field_5C = func_08008434(id, 0, 0);
    {
        register u32 wide_zero asm("r5");
        register u32 mask asm("r1");
        register u32 command asm("r7");
        asm("" : "=r"(wide_zero) : "0"(zero));
        mask = 0x80000000;
        asm("" : : "r"(mask));
        command = script;
        asm("" : "+r"(command) : "r"(mask));
    if (command & mask)
    {
        {
            register u32 script_address asm("r0") = (u32)actors + 0x80;
            asm("" : : "r"(script_address));
            script_address = offset + script_address;
            asm("" : : "r"(script_address));
            *(u32 *)script_address = wide_zero;
        }
        target->flag = command;
        if (({ register u32 kind asm("r2") = type; asm("" : : "r"(kind)); kind; }) == 4)
            anim = func_08001040(target->flag + 0x1E) != 0;
    }
    else
    {
        {
            register u32 script_address asm("r0") = (u32)actors + 0x80;
            u32 stored_script;
            asm("" : : "r"(script_address));
            script_address = offset + script_address;
            asm("" : : "r"(script_address));
            stored_script = script;
            asm("" : : "r"(stored_script));
            *(u32 *)script_address = stored_script;
        }
        target->flag = 0;
    }
    }
    }
    }
    {
        register struct Sprite *actors asm("r7") = D_03004BBC;
        register u32 offset asm("r3");
        register struct Sprite *target asm("r8");
        register u16 clear asm("r1");
        register const struct Model *definitions asm("r2");
        register const struct Model *entry asm("r6");
        register u16 *allocator asm("r5");
        asm("" : : "r"(actors));
        offset = id * sizeof(struct Sprite);
        asm("" : : "r"(offset));
        {
            register u32 address asm("r0") = offset + (u32)actors;
            asm("" : : "r"(address));
            target = (struct Sprite *)address;
            asm("" : : "r"(target));
            address += 0x60;
            asm("" : : "r"(address));
            clear = 0;
            asm("" : "+r"(clear));
            *(u16 *)address = state;
        }
        asm("" : "+r"(target));
        target->type = type;
        target->field_64 = field_64;
        target->delay = delay;
        target->field_68 = clear;
        target->field_6A = clear;
        target->field_6C = clear;
        target->field_6E = clear;
        target->field_70 = clear;
        definitions = D_08318CE4;
        asm("" : : "r"(definitions));
        {
            register u32 address asm("r0") = model_byte_offset;
            asm("" : : "r"(address));
            entry = (const struct Model *)(address + (u32)definitions);
            asm("" : : "r"(entry));
        }
        {
            register u16 horizontal asm("r0") = entry->x;
            register struct Sprite *fields asm("r1");
            asm("" : : "r"(horizontal));
            fields = target;
            asm("" : : "r"(fields));
            fields->field_10 = horizontal;
            fields->field_12 = entry->y;
        }
        {
            register u32 destination asm("r1") = (u32)actors + 20;
            register u32 source asm("r0");
            asm("" : : "r"(destination));
            destination = offset + destination;
            asm("" : : "r"(destination));
            source = (u32)definitions + 8;
            asm("" : : "r"(source));
            source += model_byte_offset;
            asm("" : : "r"(source));
            *(u32 *)destination = *(const u32 *)source;
        }
        {
            register u32 destination asm("r1") = (u32)actors + 24;
            register u32 source asm("r0");
            asm("" : : "r"(destination));
            destination = offset + destination;
            asm("" : : "r"(destination));
            source = (u32)definitions + 12;
            asm("" : : "r"(source));
            source += model_byte_offset;
            asm("" : : "r"(source));
            *(u32 *)destination = *(const u32 *)source;
        }
        {
            register u32 palette_index asm("r4") = palette;
            register u32 attribute asm("r0");
            register struct Sprite *fields asm("r1");
            register struct Sprite *output asm("r4");
            asm("" : : "r"(palette_index));
            attribute = palette_index << 12;
            asm("" : : "r"(attribute));
            fields = target;
            asm("" : : "r"(fields));
            attribute += fields->attr;
            output = target;
            asm("" : : "r"(output));
            output->attr = attribute;
            allocator = &D_030022D8;
            asm("" : : "r"(allocator));
            output->tile = *allocator;
        }
        {
            register u32 destination asm("r1") = (u32)actors + 32;
            register u32 address asm("r0");
            register u32 vram asm("r4");
            asm("" : : "r"(destination));
            destination = offset + destination;
            asm("" : : "r"(destination));
            address = *allocator << 5;
            asm("" : : "r"(address));
            vram = 0x06010000;
            asm("" : : "r"(vram));
            *(u32 *)destination = address + vram;
        }
        {
            register u32 address asm("r0") = (u32)actors + 36;
            register u32 destination asm("r3");
            asm("" : : "r"(address));
            destination = offset + address;
            asm("" : : "r"(destination));
            definitions = (const struct Model *)((u32)definitions + 4);
            asm("" : : "r"(definitions));
            definitions = (const struct Model *)((u32)definitions + model_byte_offset);
            asm("" : : "r"(definitions));
            *(u32 *)destination = *(const u32 *)definitions;
        }
        func_08000BD8(id, anim);
        {
            u32 size = entry->size;
            asm("" : "+l"(size));
            if (size)
            {
                register u32 allocated asm("r7");
                size >>= 5;
                asm("" : : "r"(size));
                allocated = *allocator;
                asm("" : : "r"(allocated));
                size += allocated;
            }
            else
                size = *allocator + 16;
            *allocator = size;
        }
    }
}
