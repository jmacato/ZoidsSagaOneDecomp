#include "types.h"

struct DebugSpriteState {
    u8 pad_0[0x88];
    u16 flags;
    u8 pad_8A[0x32];
    u16 animation_step;
    u16 frame_timer;
    u16 animation_speed;
};
struct Catalog {
    u32 id;
    u8 pad_4[0x14];
    u16 count;
    u8 pad_1A[6];
};
extern struct DebugSpriteState D_03004BBC[];
extern struct Catalog D_08318CE4[];
extern u8 D_08328E38[], D_08328E30[], D_08329FB4[], D_08329FC0[], D_08318CF4[];
extern u16 D_03002358, D_0300235A;
s32 func_080019EC(u16);
void func_08000DB8(void);
void func_08000D1C(s32);
void func_080010C0(s32, s32, s32, s32, s32, s32, s32);
void func_08009EA8(u16);
void func_08009D94(u32, u32, u32);
void func_080014A8(u16, void *);
void func_08009A54(void);
void func_08009B30(u8 *, u16);
void func_08009AD4(u32, u32);
void func_08000AF8(s32, s32);
void func_08001D04(s32);
u32 func_0800175C(s32, s32);

s32 func_08009ED4(void)
{
    register u32 kind asm("r6") = 0;
    u16 selection = 0;
    register volatile u32 *dma asm("r4");
    volatile u32 zero;
    u32 pressed;
    register u16 *animation_speed asm("r8");
    register u16 *flags asm("r10");
    register struct Catalog *catalog asm("r9");
    *(volatile u16 *)0x04000000 = 0x1140;
    *(volatile u16 *)0x04000008 = 5;
    zero = selection;
    dma = (volatile u32 *)0x040000D4;
    {
        register volatile u32 *source asm("r3") = &zero;
        asm("" : : "r"(dma), "r"(source));
        dma[0] = (u32)source;
    }
    dma[1] = 0x06000000;
    dma[2] = 0x85003000;
    dma[2];
    func_080019EC(0);
    func_08000DB8();
    func_08000D1C(0);
    dma[0] = (u32)D_08328E38;
    dma[1] = 0x06004020;
    dma[2] = 0x84000138;
    dma[2];
    dma[0] = (u32)D_08328E30;
    dma[1] = 0x05000000;
    dma[2] = 0x80000004;
    dma[2];
    func_080010C0(0x27, 8, 8, 0x20, 0x14, 6, 0);
    func_08009EA8(1);
    {
        register struct DebugSpriteState *actor asm("r5") = D_03004BBC;
        register u16 *actor_flags asm("r4") = &actor->flags;
        asm("" : : "r"(actor), "r"(actor_flags));
        *actor_flags &= 0xF7FF;
        func_08009D94(1, 0, 4);
        func_080014A8(0xFFFF, func_08009A54);
        func_08009B30(D_08329FB4, 0x260);
        actor = (struct DebugSpriteState *)((u8 *)actor + 0xC0);
        asm("" : : "r"(actor));
        animation_speed = (u16 *)actor;
        flags = actor_flags;
        asm("" : : "r"(animation_speed), "r"(flags));
    }
    {
        register struct Catalog *base asm("r0") = D_08318CE4;
        asm("" : : "r"(base));
        catalog = base;
    }
    for (;;) {
        register u32 left asm("r2");
        {
            register u32 word asm("r0") = func_0800175C(0x10, 6) << 16;
            asm("" : : "r"(word));
            left = word >> 16;
            pressed = left;
            asm("" : : "r"(left), "r"(pressed));
        }
        if (D_0300235A & 8)
            break;
        {
            register u32 mask asm("r0") = 0x20;
            asm("" : : "r"(mask), "r"(left));
            left &= mask;
        }
        if (!left) {
            register u16 *keys asm("r0") = &D_03002358;
            register u32 held asm("r0");
            register u32 bit asm("r2");
            register u32 mask asm("r1");
            asm volatile("" : "+r"(keys));
            held = *keys;
            asm("" : : "r"(held));
            bit = 0x200;
            asm("" : : "r"(bit));
            mask = bit;
            asm("" : : "r"(mask));
            held &= mask;
            if (!held)
                goto skip_left;
        }
        {
            u16 alternate;
            {
                register u16 *keys asm("r0") = &D_03002358;
                asm volatile("" : "+r"(keys));
                alternate = *keys & 2;
            }
            if (alternate != 0) {
                register u32 decrement asm("r3") = 0xFFFF;
                register u32 value asm("r0");
                register u16 *source asm("r1");
                register u16 *destination asm("r2");
                asm("" : : "r"(decrement));
                value = decrement;
                asm("" : : "r"(value));
                source = animation_speed;
                {
                    register u32 coordinate asm("r1") = *source;
                    asm("" : : "r"(value), "r"(coordinate));
                    value += coordinate;
                }
                destination = animation_speed;
                asm("" : : "r"(destination));
                *destination = value;
            }
            else {
                if (kind != 0)
                {
                    register u32 word asm("r0") = (kind - 1) << 16;
                    asm("" : : "r"(word));
                    kind = word >> 16;
                }
                {
                    u32 count = catalog[kind].count;
                    if (selection >= count)
                        selection = (u16)(count - 1);
                }
                {
                    register u16 *destination asm("r3") = animation_speed;
                    asm("" : : "r"(destination));
                    *destination = alternate;
                }
                func_08009D94(1, kind, selection);
            }
        }
skip_left:
        {
            register u32 right asm("r0") = pressed & 0x10;
            register u16 *keys asm("r2");
            register u32 alternate asm("r3");
            asm("" : : "r"(right));
            keys = &D_03002358;
            asm volatile("" : "+r"(keys) : "r"(right));
            if (!right) {
                register u32 held asm("r1") = *keys;
                register u32 bit asm("r3");
                register u32 mask asm("r0");
                asm("" : : "r"(held));
                bit = 0x100;
                asm("" : : "r"(bit));
                mask = bit;
                asm("" : : "r"(mask));
                held &= mask;
                if (!held)
                    goto skip_right;
            }
            {
                register u32 raw asm("r1") = *keys;
                register u32 mask asm("r0") = 2;
                asm("" : : "r"(raw), "r"(mask), "r"(keys));
                mask &= raw;
                asm("" : "+r"(mask));
                alternate = (u16)mask;
                asm("" : : "r"(alternate));
            }
            if (alternate != 0) {
                register u16 *source asm("r1") = animation_speed;
                register u32 value asm("r0") = *source;
                asm("" : : "r"(source), "r"(value));
                *source = value + 1;
            }
            else {
                register struct Catalog *base asm("r2");
                {
                    register u32 word asm("r0") = (kind + 1) << 16;
                    asm("" : : "r"(word));
                    kind = word >> 16;
                }
                base = D_08318CE4;
                asm("" : : "r"(base));
                if (base[kind].id == 0xFFFF)
                {
                    register u32 word asm("r0") = (kind - 1) << 16;
                    asm("" : : "r"(word));
                    kind = word >> 16;
                }
                {
                    u32 count = base[kind].count;
                    if (selection >= count)
                        selection = (u16)(count - 1);
                }
                {
                    register u16 *destination asm("r2") = animation_speed;
                    asm("" : : "r"(destination), "r"(alternate));
                    *destination = alternate;
                }
                func_08009D94(1, kind, selection);
            }
        }
skip_right:
        {
        register u32 up asm("r0") = pressed & 0x40;
        register u32 offset asm("r5") = kind << 5;
        asm("" : : "r"(up), "r"(offset));
        if (up) {
            if (selection != 0)
                selection = (u16)(selection - 1);
            {
                register struct Catalog *base asm("r3") = catalog;
                register u32 address asm("r0");
                u32 count;
                asm("" : : "r"(base));
                address = offset + (u32)base;
                asm("" : : "r"(address));
                count = ((struct Catalog *)address)->count;
                if (selection >= count)
                    selection = (u16)(count - 1);
            }
            func_08009D94(1, kind, selection);
        }
        pressed &= 0x80;
        asm("" : "+r"(pressed));
        if (pressed) {
            selection = (u16)(selection + 1);
            {
                register struct Catalog *base asm("r1") = catalog;
                register u32 address asm("r0");
                u32 count;
                asm("" : : "r"(base));
                address = offset + (u32)base;
                asm("" : : "r"(address));
                count = ((struct Catalog *)address)->count;
                if (selection >= count)
                    selection = (u16)(count - 1);
            }
            func_08009D94(1, kind, selection);
        }
        if (D_0300235A & 4) {
            register u16 *address asm("r2") = flags;
            register u32 value asm("r0") = *address;
            asm("" : : "r"(address), "r"(value));
            *address = value ^ 0x100;
        }
        func_08009AD4(kind, 0x144);
        func_08009B30(D_08329FC0, 0x149);
        func_08009AD4(selection, 0x169);
        func_08009B30(D_08318CF4 + offset, 0x149);
        func_08009AD4(D_03004BBC[0].animation_step, 0x189);
        {
            register u16 *address asm("r1") = animation_speed;
            asm("" : : "r"(address));
            func_08009AD4(*address, 0x1A9);
        }
        if (D_03002358 & 1)
            D_03004BBC[0].frame_timer = 1;
        else
            func_08000AF8(1, 0);
        func_08001D04(1);
        }
    }
    return func_080019EC(0);
}
