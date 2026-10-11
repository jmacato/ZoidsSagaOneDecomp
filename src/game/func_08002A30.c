#include "types.h"

struct Piece
{
    u8 layer_pos;
    u8 tiles;
    u8 pad_2[2];
} __attribute__((packed));

struct Camera
{
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1C;
};
extern struct Camera D_03004B9C;

extern u16 D_0300239C[];
extern struct Piece D_08663DBC[];
extern void *D_03000204;
extern u16 D_0200E8A4;
extern u8 D_0200E8A8;
extern u8 D_02000030;
extern const u8 D_08663E20[];

void func_0805EE78(s32);
void func_080029F0(void);
void func_08002C50(void);
void func_08003D78(s32, void *);
void func_08002F38(void);
void func_080029A0(void);
void func_08002D28(void);
void func_08002D9C(void);
void func_08002DB8(void);
void func_080029DC(void);
void func_08000CEC(s32, const void *, s32);
void func_08002C3C(void);
void func_08003DD8(u8);

void func_08002A30(void)
{
    register u32 column asm("r9") = 0;
    register u32 piece asm("r8") = 0;
    u32 i;
    u32 step;
    register u32 j asm("r1");
    register u32 k asm("r2");
    u32 pos;

    asm("" : : "r"(column), "r"(piece));
    step = 0;
    asm("" : : "l"(step) : "r0", "r1", "r2", "r3", "r4", "r5", "r6");
    for (; step <= 0x23; step++)
    {
        register struct Camera *camera asm("r1") = &D_03004B9C;
        asm("" : : "r"(camera));
        camera->field_0 += 0x10000;
        camera->field_8 += 0x10000;
        camera->field_10 -= 0x10000;
        if (!(step & 7))
        {
            u32 width;
            u32 panel_offset;
            register u32 next_column asm("r10");
            register u16 *destination asm("r12");
            {
                register u32 current asm("r5");
                register u32 twice asm("r0");
                register u32 next asm("r2");
                j = 0;
                asm("" : : "l"(j));
                current = column;
                asm("" : : "r"(current));
                twice = current << 1;
                asm("" : : "r"(twice));
                next = 1;
                asm("" : : "r"(next));
                next += column;
                asm("" : : "r"(next));
                next_column = next;
                asm("" : : "r"(next_column));
                {
                    register u32 result asm("r4") = twice + 4;
                    asm("" : : "r"(result));
                    width = result;
                }
            }
            {
                register u16 *address asm("r5") = D_0300239C;
                register u32 initial asm("r0");
                asm("" : : "r"(address));
                {
                    register u16 *result asm("r12") = address;
                    asm("" : : "r"(result));
                    destination = result;
                }
                initial = 0xB10D;
                asm("" : : "r"(initial));
                {
                    register u32 result asm("r6") = initial;
                    asm("" : : "r"(result));
                    panel_offset = result;
                }
            }
            do
            {
                register u32 base asm("r0") = width * j + 3;
                register u32 column_value asm("r2");
                register u32 next_j asm("r3");
                register u32 value asm("r1");
                register u32 tile_base asm("r5");
                register u16 *row asm("r0");
                asm("" : "+r"(base));
                column_value = column;
                asm("" : : "r"(column_value));
                base -= column_value;
                asm("" : : "r"(base));
                k = 0;
                asm("" : : "r"(k));
                next_j = j + 1;
                asm("" : : "r"(next_j));
                value = base + panel_offset;
                asm("" : : "r"(value));
                tile_base = 0xC00;
                asm("" : : "r"(tile_base));
                base += tile_base;
                asm("" : : "r"(base));
                base <<= 1;
                asm("" : : "r"(base));
                row = (u16 *)(base + (u32)destination);
                asm("" : : "r"(row));
                do
                {
                    *row = value;
                    value += 11;
                    row += 32;
                    k++;
                    asm("" : "+r"(k), "+r"(value), "+r"(row));
                } while (k <= 3);
                j = next_j;
                asm("" : "+r"(j));
            } while (j <= 1);
            column = next_column;
        }
        if (!(step & 3))
        {
            register struct Piece *entries asm("r1") = D_08663DBC;
            register u32 mirror asm("r5");
            register u16 *tiles asm("r12");
            register u32 color asm("r6");
            register struct Piece *e asm("r4");
            u32 shifted;
            register u32 byte asm("r2");
            register u32 selected asm("r1");
            asm("" : : "r"(entries));
            mirror = 0x400;
            asm("" : : "r"(mirror));
            {
                register u16 *base asm("r0") = D_0300239C;
                register u32 value asm("r2");
                register u32 offset asm("r0");
                asm("" : : "r"(base));
                tiles = base;
                asm("" : : "r"(tiles));
                value = 0xB102;
                asm("" : : "r"(value));
                color = value;
                asm("" : : "r"(color));
                value = piece;
                asm("" : : "r"(value));
                offset = value << 2;
                asm("" : : "r"(offset));
                e = (struct Piece *)(offset + (u32)entries);
                asm("" : : "r"(e));
            }
read_piece:
            {
                asm("" : "+r"(e));
                byte = e->layer_pos;
                asm("" : : "r"(byte));
                shifted = byte << 30;
                asm("" : "+l"(shifted) : "r"(byte) : "r0", "r3");
                if (shifted == 0)
                    selected = byte >> 2;
                else
                {
                    register u32 layer asm("r0") = shifted >> 30;
                    asm("" : "+r"(layer));
                    if (layer == 1)
                    {
                        layer = byte >> 2;
                        asm("" : : "r"(layer));
                        selected = layer + mirror;
                    }
                    else
                    {
                        asm("" : "+l"(shifted));
                        layer = shifted >> 30;
                        asm("" : : "r"(layer));
                        if (layer == 2)
                        {
                            register u32 offset asm("r2");
                            layer = byte >> 2;
                            asm("" : : "r"(layer));
                            offset = 0x800;
                            asm("" : : "r"(offset));
                            selected = layer + offset;
                        }
                        else
                            goto pieces_done;
                    }
                }
                {
                    register u32 address asm("r0") = selected << 1;
                    register u16 *base asm("r2");
                    register u16 *top asm("r3");
                    register u32 value asm("r0");
                    asm("" : : "r"(address));
                    base = tiles;
                    asm("" : : "r"(base));
                    top = (u16 *)(address + (u32)base);
                    asm("" : : "r"(top));
                    value = ((u32)e->tiles << 28) >> 28;
                    asm("" : : "r"(value));
                    value += color;
                    asm("" : : "r"(value));
                    *top = value;
                    address = selected + 0xA0;
                    asm("" : : "r"(address));
                    address <<= 1;
                    asm("" : : "r"(address));
                    base = (u16 *)(address + (u32)base);
                    asm("" : : "r"(base));
                    value = e->tiles >> 4;
                    asm("" : : "r"(value));
                    value += color;
                    asm("" : : "r"(value));
                    *base = value;
                    value = ((u32)e->layer_pos << 30) >> 30;
                    asm("" : : "r"(value));
                    if (value == 2)
                    {
                        register u32 existing asm("r1") = *top;
                        asm("" : : "r"(existing));
                        value = mirror;
                        asm("" : : "r"(value));
                        value |= existing;
                        *top = value;
                        existing = *base;
                        asm("" : : "r"(existing));
                        value = mirror;
                        asm("" : : "r"(value));
                        value |= existing;
                        *base = value;
                    }
                }
                e++;
                {
                    register u32 increment asm("r0") = 1;
                    asm("" : : "r"(increment));
                    piece += increment;
                    asm("" : : "r"(piece));
                }
                goto read_piece;
            }
pieces_done:
            {
                register u32 increment asm("r1") = 1;
                asm("" : : "r"(increment));
                piece += increment;
                asm("" : : "r"(piece));
            }
        }
        func_0805EE78(1);
    }
    func_080029F0();
    func_0805EE78(15);
    D_03000204 = func_08002C50;
    func_0805EE78(1);
    func_08003D78(6, func_08002F38);
    for (step = 0; step <= 0x1F; step++)
    {
        D_03004B9C.field_C += 0x10000;
        D_03004B9C.field_1C += 0x10000;
        func_0805EE78(4);
    }
    func_0805EE78(30);
    func_080029A0();
    D_0200E8A4 = 0;
    D_03000204 = func_08002D28;
    func_0805EE78(1);
    for (i = 0; i <= 15; i++)
    {
        D_0200E8A4++;
        D_03000204 = func_08002D9C;
        func_0805EE78(1);
    }
    D_03000204 = func_08002DB8;
    func_0805EE78(1);
    func_080029DC();
    func_08000CEC(1, D_08663E20, 0);
    D_03000204 = func_08002C3C;
    func_0805EE78(1);
    D_0200E8A8 |= 8;
    func_08003DD8(D_02000030);
}
