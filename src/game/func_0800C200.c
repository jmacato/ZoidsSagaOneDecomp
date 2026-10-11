#include "types.h"

struct Obj
{
    u8 pad_0[0xD2];
    u16 sprite1_busy;
    u8 pad_D4[2];
    u16 sprite1_x;
    u16 sprite1_y;
    u8 pad_DA[0xA];
    u16 sprite1_field_E4;
    u8 pad_E6[2];
    u16 sprite1_state;
};

extern struct Obj D_03004BBC;

extern struct
{
    u8 pad_0[2];
    u16 area;
} D_0200000C;

extern struct
{
    u8 pad_0[3];
    u8 field_3;
} D_02000B5C;

extern const u8 D_0831B174[][28];
extern const u8 D_0832A6DC[];
extern const u8 D_0832A6E8[];
extern const u8 D_0832A6EC[];
extern const u8 D_0832A6F0[];
extern const u8 D_0832A6F8[];
extern const u8 D_0832A700[];
extern const u8 D_0832A708[];
extern const u8 D_0832A710[];

void func_0800C1BC(const u8 *, u16);
void func_0800C14C(u16, u16);
u16 func_08008434(s32, s32, s32);

s32 func_0800C200(void)
{
    *(vu16 *)0x04000000;
    func_0800C1BC(D_0832A6DC, 0x400);
    func_0800C1BC(D_0831B174[D_0200000C.area], 0x400);
    func_0800C14C(D_03004BBC.sprite1_x, 0x420);
    func_0800C14C(D_03004BBC.sprite1_y, 0x440);
    func_0800C1BC(D_0832A6E8, 0x420);
    func_0800C1BC(D_0832A6EC, 0x440);
    func_0800C1BC(D_0832A6F0, 0x460);
    func_0800C14C(func_08008434(1, 0, 0), 0x464);
    func_0800C1BC(D_0832A6F8, 0x480);
    func_0800C14C(D_03004BBC.sprite1_field_E4, 0x484);
    func_0800C14C(D_03004BBC.sprite1_busy, 0x4A1);
    func_0800C1BC(D_0832A700, 0x4A0);
    func_0800C14C(D_03004BBC.sprite1_state, 0x4C1);
    func_0800C1BC(D_0832A708, 0x4C0);
    func_0800C14C(D_02000B5C.field_3, 0x4E2);
    func_0800C1BC(D_0832A710, 0x4E0);
}
