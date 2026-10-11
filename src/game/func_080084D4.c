#include "types.h"

struct Sprite
{
    u16 flags;
    u8 pad_2[0x48];
    u16 state;
    u8 pad_4C[2];
    u16 tile_x;
    u16 tile_y;
    u16 dest_x;
    u16 dest_y;
    u8 pad_56[0xA];
    u16 field_60;
    u16 type;
    u8 pad_64[0x24];
};

extern struct Sprite D_03004BBC[];

struct Field
{
    u8 pad_0[6];
    u16 count;
    u8 pad_8[0xC];
    u16 width;
    u16 height;
    u16 scale;

};

extern struct Field D_0200000C;

struct Main
{
    u8 pad_0[8];
    u16 flags;
};
extern struct Main D_02000000;

u16 func_08008498(u16, u16);

u16 func_080084D4(u16 sprite, u16 dx, u16 dy)
{
    register u32 y_delta asm("r10") = dy;
    u16 hit = 0;

    u16 px;
    register u32 py asm("r8");
    u16 tx;
    u16 ty;
    u16 result;
    u16 i;
    u16 scale;

    register s32 limit asm("r0");
    register struct Main *main asm("r12");

    asm("" : : "r"(y_delta));
    px = (dx + D_03004BBC[sprite].tile_x) * (scale = ((volatile struct Field *)&D_0200000C)->scale);
    py = (u16)((y_delta + D_03004BBC[sprite].tile_y) * scale);
    asm("" : : "r"(py));
    scale = D_0200000C.scale;
    tx = px / scale;
    ty = py / scale;
    if ((px & 0x8000) || px + scale - 1 > D_0200000C.width)
        goto bounds;
    {
        register u32 value asm("r0") = py;
        asm("" : : "r"(value));
        value &= 0x8000;
        asm("" : : "r"(value));
        if (value)
            goto bounds;
        asm("" : : : "r0");
        value = py + 3;
        {
            register struct Field *field asm("r3") = &D_0200000C;
            register u32 height asm("r3");
            asm("" : : "r"(field));
            height = field->height;
            asm("" : : "r"(value), "r"(height));
            if ((s32)value <= (s32)height)
                goto valid;
        }
    }
bounds:
    result = 0x8000;
    goto done;
valid:
    {
        register u32 initial_mask asm("r0") = 0x2000;
        u32 mask;
        asm("" : : "r"(initial_mask));
        mask = initial_mask;
        goto walk;
use_hit:
        result = hit;
        goto collide;
walk:
        result = func_08008498(tx, ty);
        if (result & mask)
        {
            {
                register u32 delta asm("r1") = dx;
                asm("" : : "r"(delta));
                {
                    register u32 sum asm("r0") = tx + delta;
                    asm("" : : "r"(sum));
                    tx = sum;
                }
            }
            {
                register u32 delta asm("r2") = y_delta;
                asm("" : : "r"(delta));
                {
                    register u32 sum asm("r0") = ty + delta;
                    asm("" : : "r"(sum));
                    ty = sum;
                }
            }
            hit = result;
            goto walk;
        }
        {
            register u32 previous asm("r3") = hit;
            asm("" : : "r"(previous));
            if (previous)
                goto use_hit;
        }
    }
collide:
    i = 1;
    limit = D_0200000C.count + 1;
    {
        register struct Main *base asm("r1") = &D_02000000;
        asm("" : : "r"(base), "r"(limit));
        main = base;
        asm("" : : "r"(main), "r"(limit));
    }
    if ((s32)i < limit)
    {
        register struct Sprite *sprites asm("r8");
        register s32 last asm("r9");
        u32 blocked;
        {
            register struct Sprite *base asm("r2") = D_03004BBC;
            asm("" : : "r"(base));
            sprites = base;
        }
        {
            register u32 flag asm("r3") = 0x8000;
            asm("" : : "r"(flag), "r"(limit));
            blocked = flag;
        }
        last = limit;
        asm("" : : "r"(sprites), "r"(blocked), "r"(last));
        do
        {
            {
                register u32 own asm("r0") = sprite;
                register u32 word asm("r2");
                register u32 address asm("r0");
                register struct Sprite *current asm("r3");
                asm("" : : "r"(own));
                if (i == own)
                    goto next_sprite;
                word = (u32)i << 4;
                address = word + i;
                asm("" : : "r"(address), "r"(word));
                address *= 8;
                {
                    register struct Sprite *base asm("r1") = D_03004BBC;
                    asm("" : : "r"(address), "r"(base));
                    current = (struct Sprite *)(address + (u32)base);
                }
                {
                    register u32 flags asm("r1") = current->flags;
                    register u32 bits asm("r0") = blocked;
                    asm("" : : "r"(flags), "r"(bits), "r"(current));
                    bits &= flags;
                    asm("" : : "r"(bits));
                    if (!bits)
                        goto next_sprite;
                }
                if ((tx == current->tile_x && ty == current->tile_y) ||
                    (tx == current->dest_x && ty == current->dest_y))
                {
                    register u32 address asm("r0") = word + i;
                    register struct Sprite *candidate asm("r2");
                    asm("" : : "r"(address), "r"(current));
                    address *= 8;
                    {
                        register struct Sprite *base asm("r3") = D_03004BBC;
                        asm("" : : "r"(address), "r"(base));
                        candidate = (struct Sprite *)(address + (u32)base);
                    }
                    asm("" : : "r"(candidate));
                    if (candidate->type != 3)
                    {
                        if (candidate->state <= 4)
                            result = i + 0x2000;
                        else
                            result = 0x8000;
                        asm("" : : "r"(candidate));
                    }
                }
            }
next_sprite:
            i++;
        } while ((s32)i < last);
    }
    {
        register struct Main *current asm("r2") = main;
        asm("" : : "r"(current));
        if (current->flags & 4)
            goto ignore_collision;
    }
    {
        register struct Sprite *base asm("r0") = D_03004BBC;
        register u32 own asm("r3") = sprite;
        asm("" : : "r"(base), "r"(own));
        if (base[own].field_60 != 0xB)
            goto done;
    }
ignore_collision:
    result = 0;
done:
    return result;
}
