#include "types.h"

struct BattleUnitState
{
    u8 pad_0[8];
    u16 flags;
    u8 pad_A[4];
    u16 kind;
};

struct BattleUnit
{
    u8 pad_0[8];
    struct BattleUnitState sub;
    u8 pad_18[0x2B4];
};

struct BattleSide
{
    struct BattleUnit units[6];
    u8 pad_10C8[0x10];
};

extern struct
{
    struct BattleSide sides[2];
} D_0200EB84;

struct SpriteDefinition
{
    u8 palette;
    u8 pad_1;
    u16 tile;
    u16 sprite;
    u8 pad_6[2];
    s32 x;
    s32 y;
};

struct ModelPalette
{
    const void *palette;
    u8 pad_4[0x48];
};

struct SpriteFlags
{
    u16 flags;
    u8 pad_2[0x86];
};

extern const struct SpriteDefinition D_0866B2E0[2][6];
extern const struct ModelPalette D_086700A0[];
extern struct SpriteFlags D_03004BBC[];

s32 func_08032A88(u32, u32);
void func_0803193C(u16, u8, u16, u16, s32, s32);
void func_0805D270(const void *, void *, u32);
void func_08031E90(u8 *, u32, u32);

void func_080317E4(u32 input)
{
    u8 palette[32];
    vu32 side = (u8)input;
    vu32 slot_index;
    vu32 definitions_offset;
    register u32 next asm("r0");

    slot_index = 0;
    definitions_offset = side * sizeof(D_0866B2E0[0]);
    do
    {
        if (func_08032A88(side, slot_index))
        {
            register u32 size asm("r0") = sizeof(struct BattleUnit);
            register u32 index asm("r3");
            register u32 product asm("r2");
            register u32 unit_offset asm("r10");
            register u32 side_index asm("r1");
            register u32 group_product asm("r4");
            register u32 side_offset asm("r9");
            register u32 kind asm("r0");
            register u32 address asm("r0");
            register u32 base asm("r2");
            register const struct SpriteDefinition *table asm("r6");
            u32 scaled;
            register u32 offset asm("r5");
            register const struct SpriteDefinition *saved_def asm("r8");
            register u32 bank asm("r1");
            register u32 tile asm("r2");
            register u32 slot asm("r3");
            register u32 low_offset asm("r4");
            register struct BattleUnitState *sub asm("r2");
            register const struct SpriteDefinition *def asm("r4");

            index = slot_index;
            asm("" : : "r"(size), "r"(index));
            product = index * size;
            unit_offset = product;
            asm("" : : "r"(product), "r"(unit_offset));
            size = sizeof(struct BattleSide);
            side_index = side;
            group_product = side_index * size;
            side_offset = group_product;
            asm("" : : "r"(group_product), "r"(side_offset));
            address = unit_offset + side_offset;
            asm("" : "+r"(address));
            base = (u32)&D_0200EB84;
            kind = ((struct BattleUnit *)(address + base))->sub.kind;
            table = &D_0866B2E0[0][0];
            asm("" : "+r"(table) : "r"(base), "r"(kind));
            scaled = index * sizeof(struct SpriteDefinition);
            asm("" : "+l"(scaled));
            index = definitions_offset;
            asm("" : : "r"(index));
            offset = scaled + index;
            def = (const struct SpriteDefinition *)(offset + (u32)table);
            saved_def = def;
            asm("" : : "r"(offset), "r"(def), "r"(saved_def));
            bank = def->palette;
            tile = def->tile;
            slot = def->sprite;
            func_0803193C(kind, bank, tile, slot,
                         ({
                             register u32 column asm("r4") = (u32)table + 8;

                             asm("" : "+r"(column));
                             *(s32 *)(offset + column);
                         }),
                         ({
                             register u32 column asm("r4") = (u32)table + 12;

                             asm("" : "+r"(column));
                             offset += column;
                             asm("" : : "r"(offset));
                             *(s32 *)offset;
                         }));
            if (side == 1)
            {
                address = scaled + 96;
                asm("" : "+r"(address));
                address += (u32)table;
                {
                    register u32 selector asm("r0") = ((const struct SpriteDefinition *)address)->sprite;
                    register u32 sprite_offset asm("r1");
                    register struct SpriteFlags *pool asm("r2");
                    register struct SpriteFlags *target asm("r1");
                    register u32 current asm("r2");
                    register u32 mask asm("r3");
                    register u32 bits asm("r0");

                    sprite_offset = selector * sizeof(struct SpriteFlags);
                    asm("" : : "r"(selector), "r"(sprite_offset));
                    pool = D_03004BBC;
                    asm("" : : "r"(pool));
                    target = (struct SpriteFlags *)(sprite_offset + (u32)pool);
                    current = target->flags;
                    mask = 0x100;
                    asm("" : "+r"(mask) : "r"(target), "r"(current));
                    bits = mask | current;
                    asm("" : : "r"(bits));
                    target->flags = bits;
                }
            }
            address = (u32)&D_0200EB84;
            asm("" : "+r"(address));
            address += 8;
            address += side_offset;
            asm("" : "+r"(address));
            low_offset = unit_offset;
            sub = (struct BattleUnitState *)(address + low_offset);
            asm("" : : "r"(low_offset), "r"(sub));
            if (sub->flags & 0x4000)
            {
                register u32 entry_offset asm("r0");
                register u32 palette_kind asm("r1");
                register const struct ModelPalette *kinds asm("r4");
                register u32 destination asm("r2");
                register u32 bank_offset asm("r1");

                palette_kind = sub->kind;
                entry_offset = palette_kind * sizeof(struct ModelPalette);
                kinds = D_086700A0;
                asm("" : : "r"(entry_offset), "r"(kinds));
                func_0805D270(((const struct ModelPalette *)(entry_offset + (u32)kinds))->palette,
                             palette, 0x10);
                func_08031E90(palette, 0x18, 0x1D);
                bank_offset = saved_def->palette * 32;
                destination = 0x05000200;
                asm("" : : "r"(bank_offset), "r"(destination));
                func_0805D270(palette, (void *)(bank_offset + destination), 0x10);
            }
        }
        else
        {
            register const struct SpriteDefinition *table asm("r1") = &D_0866B2E0[0][0];
            register u32 index asm("r3");
            register u32 address asm("r0");
            register u32 offset asm("r4");
            register u32 selector asm("r1");
            register u32 sprite_offset asm("r0");
            register struct SpriteFlags *pool asm("r1");
            register struct SpriteFlags *target asm("r2");
            register u32 current asm("r1");
            register u32 mask asm("r3");
            register u32 bits asm("r0");
            register u32 clear asm("r4");

            asm("" : : "r"(table));
            index = slot_index;
            address = index * sizeof(struct SpriteDefinition);
            asm("" : : "r"(index), "r"(address));
            offset = definitions_offset;
            asm("" : : "r"(offset));
            address += offset;
            address += (u32)table;
            selector = ((const struct SpriteDefinition *)address)->sprite;
            asm("" : : "r"(selector));
            sprite_offset = selector * sizeof(struct SpriteFlags);
            asm("" : : "r"(sprite_offset));
            pool = D_03004BBC;
            asm("" : : "r"(pool));
            target = (struct SpriteFlags *)(sprite_offset + (u32)pool);
            current = target->flags;
            asm("" : : "r"(target), "r"(current));
            mask = 0x8000;
            asm("" : "+r"(mask));
            bits = mask & current;
            asm("" : : "r"(bits));
            if (bits)
            {
                clear = 0x7FFF;
                asm("" : "+r"(clear));
                bits = clear & current;
                asm("" : : "r"(bits));
                target->flags = bits;
            }
        }
        next = (u16)(slot_index + 1);
        slot_index = next;
    } while (next < 6);
}
