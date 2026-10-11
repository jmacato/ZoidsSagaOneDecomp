#include "types.h"

struct Part
{
    u16 level;
    u16 id;
};

struct Zoid
{
    u8 pad_0[0x10];
    struct Part parts[8];
    u8 pad_30[8];
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
    struct Pilot pilots[1];
} D_02000B5C;
extern u8 D_0200E7C4[];
extern u8 D_0866634C[];
extern u8 D_08675C5C[];
extern u8 D_0875B304[];

void func_08036DE0(u8, u16, u8 *);
void func_0803E488(u8 *, s32);
void func_0804DDB4(u8 *);

void func_0804DF38(u8 pilot, s16 slot)
{
    u8 zoid = D_02000B5C.pilots[pilot].zoid;

    if (D_02000B5C.zoids[zoid].parts[slot].id != 0xFFFF)
    {
        func_08036DE0(pilot, D_02000B5C.zoids[zoid].parts[slot].id, D_0200E7C4);
        func_0803E488(D_0866634C, D_02000B5C.zoids[zoid].parts[slot].id);
        func_0803E488(D_08675C5C, 0);
        func_0804DDB4(D_0200E7C4);
    }
    else
    {
        func_0803E488(D_0875B304, 1);
    }
}
