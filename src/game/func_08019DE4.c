#include "types.h"

extern struct
{
    void *first;
} D_02000000;

extern struct
{
    u8 pad_0[0x18];
    u16 delay;
} D_0200000C;

struct Obj
{
    u8 pad_0[0x88];
    u16 flags_88;
    u8 pad_8A[0x6];
    u32 x;
    u32 y;
    u8 pad_98[0x28];
    u16 field_C0;
    u8 pad_C2[0x26];
    u16 field_E8;
    u8 pad_EA[0x8];
    u16 target_x;
    u16 target_y;
    u16 delay;
    u8 pad_F8[0xC];
    u32 speed;
    u8 pad_108[0x4D0];
    u16 flags;
    u8 pad_5DA[0x32];
    u32 state;
    u8 pad_610[0x16];
    u16 field_4E;
    u16 field_50;
};

extern struct Obj D_03004BBC;
extern u16 D_02000B54;

void func_0805EE78(s32);
void func_08000BD8(s32, s32);
void func_080019EC(s32);
void func_08008B70(s32, s32, s32);
void func_08008B58(s32);
void func_08011E08(void);
void func_08011E24(void);
void func_08008024(void);
void func_08003DD8(s32);
void func_08003D78(s32, void *);
void func_08007188(s32, s32, s32, s32);
void func_080076C0(s32, s32, s32, s32, u8 *);
void func_0800BEA4(void);
void func_080014A8(s32, void *);
void func_08001A08(s32);
void func_080019B4(s32);
void func_08011F18(s32, s32, s32, s32, s32, s32);
extern u8 D_086684A4[];
extern u8 D_08668544[];
void func_08016CA8(s32, u32, u32);
void func_08037424(s32);
void func_0801A264(void);
void func_0801A288(void);
void func_0801A2B0(void);
void func_0801A15C(void);
void func_0801A188(void);
void func_0801A1B4(void);
void func_0801A1E0(void);
void func_0801A20C(void);
void func_0801A238(void);

void func_08019DE4(void)
{
    struct Obj *obj;
    u16 *flags;

    func_0805EE78(0x20);
    func_08000BD8(11, 2);
    obj = &D_03004BBC;
    flags = &obj->flags;
    obj->flags |= 0x400;
    func_080019EC(0x6F);
    while (!(D_03004BBC.flags & 4))
    {
        if (obj->state == 0x10040)
        {
            obj->flags_88 |= 0x8000;
            func_08008B70(0, obj->field_4E, obj->field_50);
            obj->field_E8 = 0xB;
            obj->target_x = 0x29;
            obj->target_y = 8;
            obj->speed = 0x10000;
            obj->delay = D_0200000C.delay << 3;
            obj->field_C0 = 1;
            func_080019EC(0x49);
        }
        func_0805EE78(1);
    }
    func_08000BD8(11, 0);
    D_03004BBC.flags &= 0xFBFF;
    func_08008B58(0x126);
    func_08011F18(0, 0x520, 0x180, 0x20, 1, 1);
    func_08016CA8(7, (D_03004BBC.x >> 21) + 1, (D_03004BBC.y >> 21) - 1);
    func_08016CA8(7, (D_03004BBC.x >> 21) - 1, (D_03004BBC.y >> 21) + 1);
    func_08016CA8(7, D_03004BBC.x >> 21, (D_03004BBC.y >> 21) + 1);
    func_08008B58(0x127);
    func_08003D78(4, func_0801A264);
    func_08003D78(5, func_0801A288);
    func_08003D78(6, func_0801A2B0);
    func_08011F18(0, 0x520, 0x1C0, 0x20, 1, 1);
    func_08003DD8(4);
    func_08003DD8(5);
    func_08003DD8(6);
    func_08008B70(7, 0xFF, 0xFF);
    func_08008B70(8, 0xFF, 0xFF);
    func_08008B70(9, 0xFF, 0xFF);
    func_08008B58(0x128);
    func_08001A08(9);
    D_02000B54 = 0;
    func_080019B4(9);
    func_08003D78(4, func_0801A15C);
    func_08003D78(5, func_0801A188);
    func_08008B70(1, 0x2D, 0xE);
    func_08011F18(1, 0x540, 0x1C0, 0x20, 1, 1);
    func_08001A08(9);
    D_02000B54 = 0;
    func_080019B4(9);
    func_08008B58(0x129);
    func_08003D78(4, func_0801A1B4);
    func_08003D78(5, func_0801A1E0);
    func_08011F18(1, 0x5A0, 0x1C0, 0x20, 2, 1);
    func_08008B70(1, 0xFF, 0xFF);
    func_0805EE78(1);
    func_08008B58(0x12A);
    func_08001A08(8);
    D_02000B54 = 0;
    func_080019B4(8);
    func_08003D78(4, func_0801A20C);
    func_08003D78(5, func_0801A238);
    func_08008B70(4, 0x24, 0xD);
    func_08011F18(4, 0x500, 0x1A0, 0x20, 1, 1);
    func_08001A08(8);
    D_02000B54 = 0;
    func_080019B4(8);
    func_08008B58(0x12B);
    func_08011E08();
    func_080076C0(0x87, 9, 3, 8, D_086684A4);
    func_08008B70(0, 8, 3);
    func_08011E24();
    func_08008B58(0x12C);
    func_08011E08();
    func_080076C0(0x88, 9, 8, 8, D_08668544);
    func_08008B70(0, 7, 7);
    func_08011E24();
    func_08008B58(0x12D);
    func_08037424(0xD);
    func_08037424(0xE);
    func_08037424(0xF);
    func_08011E08();
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    func_08007188(0x87, 0xA, 1, 0xFFFF);
    func_080014A8(1, func_0800BEA4);
}
