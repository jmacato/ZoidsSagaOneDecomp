#include "types.h"

struct Zoid
{
    u16 flags;
    u8 pad_2[0x33];
    u8 mode;
    u8 pad_36[2];
};

struct Pilot
{
    u16 flags;
    u8 zoid;
    u8 pad_3;
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[1];
    u8 pad_D64[0x34A4 - 0xD64];
    struct Pilot pilots[0x57];
} D_02000B5C;

extern struct
{
    u8 pad_0[0x6B2];
    u8 count;
} D_020075A0;

extern const u8 D_08675C5C[];
extern const u8 D_08675DD4[];

void func_0803E488(const u8 *, s32);
void func_08032818(u32);

void func_08038178(u8 index)
{
    u8 zoid = D_02000B5C.pilots[index].zoid;
    struct Zoid *data = &D_02000B5C.zoids[zoid];
    s32 empty = 0;
    u8 count;
    u8 i;
    s32 text;

    if (D_02000B5C.pilots[index].flags & 0x10)
        func_0803E488(D_08675C5C, 0x11);
    else if (zoid == 0xFF)
    {
        func_0803E488(D_08675C5C, 0x16);
        empty = 1;
    }
    else if (D_02000B5C.zoids[zoid].flags & 0x800)
        func_0803E488(D_08675C5C, 0x32);
    else
        func_0803E488(D_08675DD4, 0xC);
    func_08032818(index);
    if (D_020075A0.count <= 10)
    {
        count = 10 - D_020075A0.count;
        for (i = 0; i < count; i++)
            func_0803E488(D_08675DD4, 0xC);
    }
    if (!empty)
    {
        switch (data->mode)
        {
        case 0:
            text = 0x12;
            break;
        case 2:
            text = 0x14;
            break;
        case 1:
        default:
            text = 0x13;
            break;
        }
    }
    else
        text = 0x1C;
    func_0803E488(D_08675C5C, text);
}
