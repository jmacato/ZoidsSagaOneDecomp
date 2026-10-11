#include "types.h"

struct Entry
{
    u16 id;
    u16 map;
    u8 pad_4[24];
};

struct Item
{
    u16 value;
    u8 pad_2[16];
    u16 type;
};

struct Group
{
    u16 count;
    u8 pad_2[2];
    struct Item *items;
};

struct Slot
{
    u8 pad_0[4];
    u16 zoid;
    u8 pad_6[10];
};

extern struct Entry D_0831B164[];
extern struct Group D_0832819C[];
extern struct
{
    u8 pad_0[0x50];
    struct Slot slots[256];
} D_02000B5C;
extern u16 D_03002336;
extern const u8 D_08328D0C[];

u32 func_080328FC(s32, s32, s32);
void func_080014A8(s32, void *);
void func_08006DF8(void);
void func_0800C1BC(const u8 *, u16);
void func_0800C14C(s32, s32);
void func_08001D04(s32);

s32 func_08007024(u16 kind)
{
    register u32 map asm("r6");
    register u32 count asm("r9");
    register u32 slot asm("r10");
    register u32 i asm("r4");

    struct Entry *table;
    {
        register u32 word asm("r1") = (u32)kind << 16;
        asm("" : : "r"(word));
        map = word >> 16;
        asm volatile("" : : "r"(map));
    }
    count = 0;
    slot = 0;
    asm("" : : "r"(count), "r"(slot));
    i = 0;
    {
        struct Entry *base = D_0831B164;
        register u32 value asm("r2") = base->map;
        register u32 end asm("r5") = 0xFFFF;
        asm("" : : "r"(value), "r"(end), "r"(base));
        table = base;
        if (value != end)
        {
            register u32 value asm("r1") = ((volatile struct Entry *)table)->map;
            register u32 mask asm("r2") = 0xFFFF7FFF;
            asm("" : : "r"(value), "r"(mask), "r"(map));
            value &= mask;
            if (value == map)
                goto group;
            {
                register struct Entry *saved asm("r8") = table;
                register u32 end_value asm("r12") = end;
                register u32 mask_value asm("r3") = mask;
                asm volatile("" : "+r"(saved) : "r"(end_value), "r"(mask_value));
                do
                {
                    register u32 offset asm("r1");
                    register struct Entry *entry asm("r2");
                    {
                        register u32 next_word asm("r1") = i + 1;
                        asm("" : : "r"(next_word));
                        i = (u16)next_word;
                    }
                    offset = i * 28;
                    {
                        register struct Entry *base asm("r5") = saved;
                        asm("" : : "r"(offset), "r"(base));
                        entry = (struct Entry *)(offset + (u32)base);
                    }
                    value = entry->map;
                    asm("" : : "r"(value), "r"(end_value));
                    if (value == end_value)
                        break;
                    value &= mask_value;
                    asm("" : : "r"(value));
                } while (value != map);
            }
        }
    }
    {
        register u32 value asm("r1") = table[i].map;
        register u32 mask asm("r2") = 0xFFFF7FFF;
        asm("" : : "r"(value), "r"(mask));
        value &= mask;
        if (value != map)
            goto finish;
    }
group:
    {
        register u32 word asm("r3") = (u32)i * 8;
        register u32 next asm("r8");
        register u32 address asm("r1");
        register u32 value asm("r2");
        register u32 flag asm("r7");
        address = (word - i) * 4 + (u32)table;
        value = *(u16 *)(address + 2);
        asm("" : : "r"(word), "r"(value));
        flag = 0x8000;
        {
            register u32 bits asm("r1") = flag;
            asm("" : : "r"(bits));
            value &= bits;
        }
        next = i + 1;
        asm("" : : "r"(value), "r"(next));
        if (value != 0)
        {
            struct Item *items;
            register u32 j asm("r4");
            register u16 *bound asm("r5");
            address = (u32)D_0832819C;
            asm("" : : "r"(address));
            address += 4;
            address = word + address;
            items = *(struct Item **)address;
            j = 1;
            {
                register u32 base asm("r2") = (u32)D_0832819C;
                asm("" : : "r"(base), "r"(word));
                address = word + base;
            }
            {
                register u32 size asm("r3") = *(u16 *)address;
                asm("" : : "r"(size));
                if (j >= size)
                    goto next_group;
            }
            {
                bound = (u16 *)address;
                asm("" : : "r"(bound));
                do
                {
                    register u32 offset asm("r1") = j * 20;
                    register struct Item *item asm("r2");
                    {
                        register struct Item *base asm("r7") = items;
                        asm("" : : "r"(offset), "r"(base));
                        item = (struct Item *)(offset + (u32)base);
                    }
                    if (item->type == 1)
                    {
                        register u32 value asm("r1") = item->value;
                        asm("" : : "r"(value));
                        D_02000B5C.slots[count].zoid = func_080328FC(map - 1, value, slot);
                        slot = (u16)(slot + 1);
                    }
                    count = (u16)(count + 1);
                    {
                        register u32 next_word asm("r1") = j + 1;
                        asm("" : : "r"(next_word));
                        j = (u16)next_word;
                    }
                } while (j < *bound);
            }
        }
next_group:
        {
            register u32 word asm("r1") = next << 16;
            asm("" : : "r"(word));
            i = word >> 16;
        }
        {
            register struct Entry *base asm("r3") = D_0831B164;
            register u32 mask asm("r1");
            register u32 value asm("r2");
            asm volatile("" : "+r"(base));
            mask = i * 28;
            asm("" : : "r"(mask));
            mask += (u32)base;
            value = *(u16 *)(mask + 2);
            asm("" : : "r"(value));
            mask = 0xFFFF7FFF;
            asm("" : : "r"(value), "r"(mask));
            value &= mask;
            table = base;
            asm("" : : "r"(value), "r"(table));
            if (value == map)
                goto group;
        }
    }
finish:
    {
        register u32 total asm("r3") = count;

        asm("" : : "r"(total));
        if (total > 200)
        {
            D_03002336 |= 1;
            func_080014A8(0, func_08006DF8);
            func_0800C1BC(D_08328D0C, 0x500);
            func_0800C14C(count - 200, 0x514);
            for (;;)
                func_08001D04(1);
        }
    }
}
