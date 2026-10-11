#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[0x2E];
    u16 dir;
    u8 pad_32[0x1C];
    u16 tile_x;
    u16 tile_y;
    u8 pad_52[0xE];
    u16 seen;
    u8 pad_62[0x26];
};
extern struct Sprite D_03004BBC[];
extern u16 D_0866967C[][2], D_08669690[][2], D_086696A4[][2], D_086696C0[][2];
extern u8 D_030022E0;
extern u16 D_03004CA4;
extern struct { void *first; } D_02000000;
u16 func_08008498(s32, s32);
void func_08003D78(s32, void *);
void func_08011E04(void);
void func_0801BD9C(void);

void func_0801BC2C(u8 *list)
{
    struct { u8 *list; vu32 count, id, next; u16 *volatile tile_y; vu32 dy; } saved;
    register u32 i asm("r3");
    register u32 j asm("r8");
    register u16 (*offsets)[2] asm("r10");
    struct Sprite *base;
    register u32 index asm("r9");
    u8 *cursor;

    saved.list = list;
    i = 0;
    cursor = list;
    goto condition;
body:
    {
        register u8 *input asm("r1") = saved.list;
        register u8 *entry asm("r0");
        register u32 id asm("r0");
        register struct Sprite *origin asm("r2");
        register u32 sprite_index asm("r1");
        register u32 offset asm("r0");
        register struct Sprite *current asm("r2");
        register u32 flags asm("r1");
        register u32 blocked asm("r0");
        register u32 direction asm("r0");
        register u32 direction_copy asm("r1");

        asm("" : : "r"(input), "r"(i));
        entry = input + i;
        asm("" : : "r"(entry));
        id = *entry;
        saved.id = id;
        origin = D_03004BBC;
        asm("" : : "r"(origin));
        sprite_index = id;
        asm("" : "+r"(sprite_index));
        sprite_index += 1;
        asm("" : : "r"(sprite_index));
        offset = sprite_index * sizeof(struct Sprite);
        current = (struct Sprite *)(offset + (u32)origin);
        asm("" : : "r"(current));
        flags = current->flags;
        blocked = 0x10;
        asm("" : : "r"(flags), "r"(blocked));
        blocked &= flags;
        saved.next = i + 1;
        asm("" : "+r"(i) : "r"(blocked));
        if (blocked)
            goto next;
        direction = current->dir;
        direction_copy = direction;
        asm("" : : "r"(direction), "r"(direction_copy));
        if (direction == 0)
        {
            register u16 (*table)[2] asm("r2") = D_0866967C;
            register u32 limit asm("r0");
            asm("" : : "r"(table));
            offsets = table;
            asm("" : : "r"(offsets));
            limit = 5;
            asm("" : : "r"(limit));
            saved.count = limit;
        }
        else if (direction == 1)
        {
            register u16 (*table)[2] asm("r1") = D_08669690;
            register u32 limit asm("r2");
            asm("" : : "r"(table));
            offsets = table;
            asm("" : : "r"(offsets));
            limit = 5;
            asm("" : : "r"(limit));
            saved.count = limit;
        }
        else if (direction == 2)
        {
            register u16 (*table)[2] asm("r0") = D_086696A4;
            register u32 limit asm("r1");
            asm("" : : "r"(table));
            offsets = table;
            asm("" : : "r"(offsets));
            limit = 7;
            asm("" : : "r"(limit));
            saved.count = limit;
        }
        else if (direction_copy == 3)
        {
            register u16 (*table)[2] asm("r2") = D_086696C0;
            register u32 limit asm("r0");
            asm("" : : "r"(table));
            offsets = table;
            asm("" : : "r"(offsets));
            limit = 7;
            asm("" : : "r"(limit));
            saved.count = limit;
        }
        else
            goto next;
    }
    {
        register u32 zero asm("r1") = 0;
        register u32 limit asm("r2");
        register u32 next_value asm("r3");
        register u32 item asm("r3");
        asm("" : : "r"(zero));
        j = zero;
        asm("" : : "r"(j));
        next_value = i + 1;
        saved.next = next_value;
        limit = saved.count;
        asm("" : : "r"(limit));
        if (j >= limit)
            goto next;
        base = D_03004BBC;
        asm("" : "+r"(base));
        item = saved.id + 1;
        asm("" : : "r"(item));
        index = item;
    }
scan:
    {
        register u16 *row asm("r0") = offsets[j];
        register u32 dx asm("r6");
        register u32 dy asm("r3");
        register struct Sprite *current asm("r5");
        register u32 item asm("r2");
        register u32 offset asm("r0");
        register u16 *tile_x asm("r4");
        register u16 *tile_y asm("r2");
        register s32 x asm("r0");
        register s32 y asm("r1");
        register u32 collision asm("r0");
        register u32 blocked asm("r1");

        asm("" : : "r"(row), "r"(base), "r"(index));
        dx = row[0];
        dy = row[1];
        item = index;
        asm("" : : "r"(item));
        offset = item << 4;
        asm("" : "+r"(offset));
        offset += index;
        offset <<= 3;
        current = (struct Sprite *)(offset + (u32)base);
        tile_x = &current->tile_x;
        x = *tile_x + dx;
        tile_y = &current->tile_y;
        y = *tile_y + dy;
        asm("" : : "r"(tile_x), "r"(current));
        saved.tile_y = tile_y;
        saved.dy = dy;
        collision = (u32)func_08008498(x, y) << 16;
        blocked = 0xE0000000;
        asm("" : : "r"(collision), "r"(blocked));
        blocked &= collision;
        tile_y = saved.tile_y;
        dy = saved.dy;
        asm("" : : "r"(tile_y), "r"(dy), "r"(blocked));
        if (blocked)
            goto next;
        {
            register u16 *player_x asm("r1") = &base[1].tile_x;
            register u32 sum asm("r0") = dx + *tile_x;
            register u32 player asm("r1");
            asm("" : : "r"(player_x), "r"(sum));
            player = *player_x;
            sum = (u16)sum;
            if (player != sum)
                goto advance;
        }
        {
            register u16 *player_y asm("r0") = &base[1].tile_y;
            register u32 sum asm("r1");
            register u32 player asm("r0");
            asm("" : "+r"(player_y));
            sum = dy + *tile_y;
            asm("" : : "r"(sum));
            player = *player_y;
            sum = (u16)sum;
            if (player != sum)
                goto advance;
        }
        {
            register u16 *seen asm("r0") = &current->seen;
            register u32 one asm("r1") = 1;
            register u8 *output asm("r0");
            register u32 selected asm("r3");
            register u8 *frame asm("r3");
            asm("" : : "r"(seen), "r"(one));
            *seen = one;
            output = &D_030022E0;
            asm("" : : "r"(output));
            frame = (u8 *)&saved;
            asm("" : "+r"(frame));
            selected = frame[8];
            *output = selected;
            D_03004CA4 = one;
            D_02000000.first = func_08011E04;
            {
                register u32 slot asm("r0") = 3;
                register void *task asm("r1");
                asm("" : : "r"(slot));
                task = func_0801BD9C;
                func_08003D78(slot, task);
            }
            goto next;
        }
    }
advance:
    j = (u8)(j + 1);
    {
        register u32 limit asm("r1") = saved.count;
        asm("" : : "r"(limit));
        if (j < limit)
            goto scan;
    }
next:
    {
        register u32 value asm("r2") = saved.next;
        register u32 shifted asm("r0");
        register u8 *input asm("r1");
        asm("" : : "r"(value));
        shifted = value << 24;
        asm("" : : "r"(shifted));
        i = shifted >> 24;
        input = saved.list;
        asm("" : : "r"(input), "r"(i));
        cursor = input + i;
    }
condition:
    if (*cursor)
        goto body;
}
