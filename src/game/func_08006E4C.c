#include "types.h"

typedef unsigned long long u64;
union RegisterWord { u32 word; u64 wide; };
union RegisterPointer { u32 word; u8 *pointer; };

struct Map
{
    u16 id;
    u16 key;
    u8 pad_4[0x18];
};

struct Spawn
{
    u16 kind;
    u16 pad_2;
    u16 x;
    u16 y;
    u8 pad_8[4];
    u16 dir;
    u16 flag;
    u16 pad_10;
    u16 type;
};

struct SpawnList
{
    u16 count;
    u8 pad_2[2];
    struct Spawn *spawns;

};

struct Object
{
    u16 id;
    u8 x;
    u8 y;
    u16 kind;
    u16 index;
    u16 flag;
    u8 dir;
    u8 field_B;
    u8 field_C;
    u8 field_D;
    u8 pad_E[2];
};

extern struct Map D_0831B164[];
extern struct SpawnList D_0832819C[];
extern const u8 D_08328D0C[];
extern u16 D_03002336;

extern struct
{
    u8 pad_0[0x50];
    struct Object objects[1];
} D_02000B5C;

u32 func_080328FC(s32, s32, s32);
void func_080014A8(s32, void *);
void func_08006DF8(void);
void func_0800C1BC(const u8 *, s32);
void func_0800C14C(s32, s32);
void func_08001D04(s32);

s32 func_08006E4C(u16 kind)
{
    struct Frame
    {
        u32 count;
        union { u32 word; u16 low; } index;
        struct Spawn *spawns;
        union { u32 word; u16 low; } id;
        u32 next;
    } frame;
    register u32 i asm("r4");
    register u32 j asm("r6");

    register struct Map *table asm("r3");
    register u32 map asm("r9");
    {
        register u32 word asm("r1") = (u32)kind << 16;
        asm("" : : "r"(word));
        word >>= 16;
        asm("" : : "r"(word));
        map = word;
        asm volatile("" : : "r"(map));
    }
    frame.count = 0;
    {
        register u32 zero asm("r2") = 0;
        asm("" : : "r"(zero));
        frame.index.word = zero;
    }
    i = 0;
    {
        register struct Map *base asm("r1") = D_0831B164;
        register u32 value asm("r2") = base->key;
        register u32 end asm("r5") = 0xFFFF;
        asm("" : : "r"(base), "r"(value), "r"(end));
        table = base;
        asm("" : : "r"(table));
        if (value != end)
        {
            register u32 value asm("r1") = ((volatile struct Map *)table)->key;
            register u32 mask asm("r2") = 0xFFFF7FFF;
            asm("" : : "r"(value), "r"(mask));
            value &= mask;
            if (value == map)
                goto group;
            {
                struct Map *saved = table;
                register u32 end_value asm("r6");
                register u32 mask_value asm("r5");
                asm("" : "+l"(saved) : "r"(table) : "r0", "r1", "r2", "r5", "r6");
                end_value = end;
                mask_value = mask;
                asm volatile("" : "+l"(saved) : "r"(end_value), "r"(mask_value));
                do
                {
                    register u32 offset asm("r1");
                    register struct Map *entry asm("r2");
                    offset = (i + 1) << 16;
                    asm("" : : "r"(offset));
                    i = offset >> 16;
                    asm("" : : "r"(i));
                    offset = i * 28;
                    asm("" : : "r"(offset));
                    entry = (struct Map *)(offset + (u32)saved);
                    value = entry->key;
                    asm("" : : "r"(value));
                    if (value == end_value)
                        break;
                    value &= mask_value;
                    asm("" : : "r"(value));
                } while (value != map);
            }
        }
    }
    {
        register u32 value asm("r1") = ((volatile struct Map *)table)[i].key;
        register u32 mask asm("r2") = 0xFFFF7FFF;
        asm("" : : "r"(value), "r"(mask));
        value &= mask;
        asm("" : : "r"(value));
        if (value != map)
            goto finished;
    }
    {
        u32 group_offset;
        register u32 zero asm("r8");
        register u32 map_bit asm("r3");
        register u32 map_byte asm("r10");
group:
        {
            register u32 word asm("r1") = i << 3;
            register u32 key asm("r2");
            register union RegisterWord bit asm("r5");
            key = (word - i) << 2;
            key += (u32)table;
            key = ((struct Map *)key)->key;
            bit.word = 0x8000;
            map_bit = bit.word;
            key &= map_bit;
            bit.word = i + 1;
            frame.next = bit.word;
            group_offset = word;
            if (!key)
                goto next_group;
        }
        {
            register u32 address asm("r1") = (u32)D_0832819C;
            address += 4;
            address = group_offset + address;
            frame.spawns = *(struct Spawn **)address;
        }
        j = 1;
        {
            register u32 base asm("r2") = (u32)D_0832819C;
            register u32 size asm("r1");
            size = group_offset + base;
            size = *(u16 *)size;
            if (j >= size)
                goto next_group;
        }
        i += map_bit;
        frame.id.word = i;
        {
            register union RegisterWord low_zero asm("r3");
            register union RegisterWord low_map asm("r4");
            register union RegisterWord word asm("r1");
            low_zero.word = 0;
            zero = low_zero.word;
            low_map.word = map;
            word.word = low_map.word << 24;
            word.word >>= 24;
            map_byte = word.word;
        }
        do
        {
            register struct Object *object asm("r3");
            register struct Spawn *spawn asm("r4");
            register u16 *kind_field asm("r5");
            register u16 *index_field asm("r12");
            register u32 cleared asm("r2");
            {
                register u32 base asm("r2") = (u32)&D_02000B5C;
                register u32 counter asm("r5") = frame.count;
                register u32 offset asm("r1");
                offset = counter << 4;
                object = (struct Object *)(offset + base);
            }
            {
                register u16 *address asm("r1") = (u16 *)((u32)object + 0x50);
                *address = frame.id.low;
            }
            {
                register u32 offset asm("r1") = j * 20;
                register struct Spawn *base asm("r5");
                base = frame.spawns;
                spawn = (struct Spawn *)(offset + (u32)base);
            }
            {
                register u32 value asm("r1") = spawn->x;
                register union RegisterPointer coordinate_address asm("r2");
                coordinate_address.word = (u32)object + 0x52;
                *(u8 *)coordinate_address.word = value;
                value = spawn->y;
                coordinate_address.word++;
                *(u8 *)coordinate_address.word = value;
                value = spawn->kind;
                kind_field = (u16 *)((u32)object + 0x54);
                *kind_field = value;
            }
            {
                register union RegisterWord address asm("r1");
                register u32 value asm("r2");
                address.word = 0x56;
                { u32 offset = address.word; address.word = offset + (u32)object; }
                index_field = (u16 *)address.word;
                value = 0;
                *(u16 *)address.word = value;
            }
            {
                register u32 value asm("r1") = spawn->dir;
                register u8 *address asm("r2") = (u8 *)object + 0x5A;
                *address = value;
            }
            {
                u32 value = spawn->flag;
                register u16 *address asm("r1") = (u16 *)((u32)object + 0x58);
                *address = value;
                {
                    register union RegisterWord byte asm("r1");
                    byte.word = (u32)address + 3;
                    cleared = zero;
                    *(u8 *)byte.word++ = cleared;
                    *(u8 *)byte.word++ = cleared;
                    *(u8 *)byte.word = cleared;
                }
            }
            {
                register u32 type asm("r1") = spawn->type;
                if (type == 1)
                {
                    register struct Frame *counters asm("r3") = &frame;
                    register u16 slot asm("r0") = counters->index.low;
                    register u16 *destination asm("r3");
                    destination = index_field;
                    *destination = slot;
                    {
                        register u32 kind asm("r1") = (u8)spawn->kind;
                        register u32 word asm("r3") = frame.index.word;
                        register u32 position asm("r2") = (u8)word;
                        *kind_field = func_080328FC(map_byte - 1, kind, position);
                    }
                    frame.index.word = (u16)(frame.index.word + 1);
                }
            }
            frame.count = (u16)(frame.count + 1);
            {
                register u32 step asm("r1") = j + 1;
                j = (u16)step;
            }
            {
                register u32 base asm("r4") = (u32)D_0832819C;
                register u32 size asm("r1");
                size = group_offset + base;
                size = *(u16 *)size;
                if (j >= size)
                    break;
            }
        } while (1);
next_group:
        {
            register u32 counter asm("r5") = frame.next;
            register u32 word asm("r1") = counter << 16;
            i = word >> 16;
        }
        table = D_0831B164;
        {
            register u32 key asm("r2") = table[i].key;
            register u32 mask asm("r1") = 0xFFFF7FFF;
            key &= mask;
            if (key == map)
                goto group;
        }
    }
finished:
    {
        register u32 counter asm("r2") = frame.count;
        register u32 offset asm("r1") = counter << 4;
        register u32 base asm("r3") = (u32)&D_02000B5C;
        asm("" : : "r"(counter), "r"(offset), "r"(base));
        offset += base;
        offset += 0x50;
        asm("" : : "r"(offset));
        counter = 0xFFFF;
        asm("" : : "r"(counter));
        *(u16 *)offset = counter;
    }
    {
    register u32 total asm("r4") = frame.count;
    asm("" : : "r"(total));
    if (total > 200)
    {
        D_03002336 |= 1;
        func_080014A8(0, func_08006DF8);
        func_0800C1BC(D_08328D0C, 0x500);
        func_0800C14C(total - 200, 0x514);
        for (;;)
            func_08001D04(1);
    }
    }
}
