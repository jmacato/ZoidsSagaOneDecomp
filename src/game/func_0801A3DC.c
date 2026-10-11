#include "types.h"

extern struct { void (*first)(void); } D_02000000;
extern u16 D_02000B54;
extern u16 D_02007574[];
extern u8 D_030022E0;
extern struct { u8 pad_0[0xE8]; u16 sprite1_state; } D_03004BBC;

struct Scene
{
    u16 before;
    u16 after;
    const void *script;
    volatile u32 bytes;
};

struct Action
{
    u16 tile;
    u16 actor;
    u16 x;
    u16 y;
    u8 pad_8[8];
    u16 mode;
    u16 extra;
};

extern const struct Scene D_08668CD8[];
extern const struct Action D_08668CC4;
extern struct Action D_02019A20[];
extern const u16 D_0832ADBC[];
extern const u16 D_0832ADC0[];
extern const u16 D_0832ADC8[];
extern const u16 D_0832ADD4[];
extern const u16 D_0832ADE4[];
extern const u16 D_0832ADF8[];
extern const u8 D_08668D8C[];
extern const u8 D_08668DDC[];
extern const u8 D_08668E54[];

void *memcpy(void *, const void *, u32);
void func_08008B58(u16);
void func_08011E08(void);
void func_08011E24(void);
void func_080076C0(u16, u32, u32, u32, const void *);
void func_08001A08(u16);
s32 func_080019B4(u16);
s32 func_08008B70(u16, u16, u16);
void func_08011F18(u16, u16, u16, u8, u8, u8);
void func_08000BD8(u16, u16);
void func_0805EE78(s32);
u32 func_08000F88(u32);
u8 func_08038910(u8, u8 *);
void func_0805D270(const void *, void *, u32);
s32 func_0805D484(s32, s32);
void func_08008024(void);
void func_0801AE30(void);
void func_08003DD8(u8);

void func_0801A3DC(u8 selection)
{
    u8 pilots[6];
    u16 single[2];
    u16 pair[4];
    u16 triple[6];
    u16 four[8];
    u16 five[10];
    u16 six[12];
    u32 count;
    s32 start;
    u32 i;
    u32 size;

    memcpy(single, D_0832ADBC, 4);
    memcpy(pair, D_0832ADC0, 8);
    memcpy(triple, D_0832ADC8, 12);
    memcpy(four, D_0832ADD4, 16);
    memcpy(five, D_0832ADE4, 20);
    memcpy(six, D_0832ADF8, 24);
    {
    u16 *volatile positions[6] = {single, pair, triple, four, five, six};
    u16 *volatile *position_base;
    u16 answer;
    D_030022E0 = selection;
    func_08008B58(D_08668CD8[selection].before);
    answer = D_02007574[0];
    {
        register u16 *volatile *base asm("r4") = positions;
        asm("" : "+r"(base) : "r"(answer));
        position_base = base;
    }
    if (answer && D_02007574[1] != 1)
    {
        D_03004BBC.sprite1_state = 1;
        switch (D_030022E0)
        {
        case 4:
    func_08011E08();
    func_080076C0(0x90, 0xB, 9, 4, D_08668D8C);
    func_08001A08(0x12);
    D_02000B54 = 0;
    func_080019B4(0x12);
    func_08011E24();
    func_08008B58(0x144);
    func_08008B70(3, 9, 0xD);
    func_08011F18(3, 0x70, 0x90, 0x10, 1, 1);
    func_08000BD8(4, 3);
    func_0805EE78(0xF);
    func_08000BD8(1, 2);
    func_08000BD8(2, 2);
    func_08000BD8(3, 2);
    func_0805EE78(0xF);
    func_08008B58(0x145);
    func_08011F18(3, 0x70, 0x30, 0x10, 1, 1);
    func_08008B70(3, 0xFF, 0xFF);
    func_08008B58(0x146);
            break;
        case 9:
    func_08011E08();
    func_080076C0(0x93, 0xB, 9, 6, D_08668DDC);
    func_08001A08(0x12);
    D_02000B54 = 0;
    func_080019B4(0x12);
    func_08011E24();
    func_08008B58(0x161);
    func_08008B70(3, 9, 0xD);
    func_08011F18(3, 0x90, 0xA0, 0x10, 1, 1);
    func_08008B70(4, 8, 0xD);
    func_08011F18(4, 0x80, 0xA0, 0x10, 1, 1);
    func_08008B70(5, 8, 0xD);
    func_08011F18(5, 0x80, 0xC0, 0x10, 1, 1);
    func_08011F18(5, 0x70, 0xC0, 0x10, 1, 1);
    func_08011F18(5, 0x70, 0xA0, 0x10, 1, 1);
    func_0805EE78(0xF);
    func_08000BD8(1, 1);
    func_08000BD8(2, 1);
    func_08000BD8(3, 1);
    func_0805EE78(0xF);
    func_08008B58(0x162);
    func_08011F18(3, 0x90, 0xD0, 0x10, 1, 1);
    func_08008B70(3, 0xFF, 0xFF);
    func_08008B58(0x163);
    func_08011F18(4, 0x80, 0xD0, 0x10, 1, 1);
    func_08008B70(4, 0xFF, 0xFF);
    func_08011F18(5, 0x80, 0xA0, 0x10, 1, 1);
    func_08011F18(5, 0x80, 0xD0, 0x10, 1, 1);
    func_08008B70(5, 0xFF, 0xFF);
    func_08008B58(0x164);
            break;
        case 14:
            func_08011E08();
            func_080076C0(0x96, 8, 8, 9, D_08668E54);
            func_08008B70(0, 8, 6);
            if (!func_08000F88(0x190))
                func_08008B70(8, 0xFF, 0xFF);
            func_08011E24();
            func_08008B58(0x184);
            break;
        }
        func_08011E08();
        count = func_08038910(D_030022E0, pilots);
        func_0805D270(D_08668CD8[selection].script, D_02019A20, (D_08668CD8[selection].bytes << 10) >> 11);
        start = func_0805D484(D_08668CD8[selection].bytes, 20);
        for (i = 0; i < count; i++)
        {
            struct Action *action = &D_02019A20[start + i];
            u32 position_index = count - 1;
            u16 *volatile *position_slot;
            asm("" : "+r"(position_index));
            position_slot = position_base + position_index;
            func_0805D270(&D_08668CC4, action, 10);
            {
                u32 tile = pilots[i] + 0x98;
                register u32 mask asm("r2") = 0xFFFF8000;
                register u32 operand asm("r1");
                asm("" : "+r"(mask) : "r"(tile));
                operand = mask;
                asm("" : "+r"(operand) : "r"(tile));
                action->tile = tile | operand;
            }
            action->actor = start + i;
            action->x = (*position_slot)[i * 2];
            action->y = (*position_slot)[i * 2 + 1];
            action->mode = 2;
        }
        {
            register const struct Scene *table asm("r6") = D_08668CD8;
            u32 scene_offset;
            volatile u32 *size_pointer;
            register u8 *fields asm("r0");
            u32 additional;
            asm("" : "+r"(table));
            scene_offset = selection * sizeof(struct Scene);
            fields = (u8 *)table + 8;
            asm("" : "+r"(fields));
            size_pointer = (volatile u32 *)((u32)scene_offset + (u32)fields);
            additional = count * 20;
            asm("" : "+r"(size_pointer) : "r"(additional), "r"(scene_offset));
            size = *size_pointer;
            func_080076C0(0x98, 8, 7, func_0805D484(size + additional, 20), D_02019A20);
        func_08008B70(0, 0xFF, 0xFF);
        if (D_030022E0 == 14)
        {
            func_08008B70(2, 0xFF, 0xFF);
            func_08008B70(3, 0xFF, 0xFF);
            func_08008B70(4, 0xFF, 0xFF);
        }
        func_08011E24();
        if (D_030022E0 != 14)
        {
            asm("" : "+r"(scene_offset) : "r"(table));
            {
                register u16 *dialogue asm("r0") = (u16 *)((u32)scene_offset + (u32)table);
                asm("" : "+r"(dialogue));
                func_08008B58(dialogue[1]);
            }
        }
        else
        {
            func_08008B58(0x185);
            func_08001A08(9);
            D_02000B54 = 0;
            func_080019B4(9);
            func_08008B70(2, 1, 7);
            func_08011F18(2, 0x60, 0x70, 0x10, 1, 1);
            func_08008B70(3, 1, 6);
            func_08011F18(3, 0x50, 0x60, 0x10, 1, 1);
            func_08008B70(4, 1, 8);
            func_08011F18(4, 0x50, 0x80, 0x10, 1, 1);
            func_08008B58(0x186);
        }
        }
        D_02000000.first = func_08008024;
        func_08003DD8(3);
        D_02000000.first = func_0801AE30;
        for (;;)
            func_0805EE78(1);
    }
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_03004BBC.sprite1_state = 0;
    }
}
