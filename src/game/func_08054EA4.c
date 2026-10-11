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

struct Kind
{
    u8 pad_0[8];
    struct Part parts[8];
    u8 pad_28[0x24];
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[1];
} D_02000B5C;
extern u8 D_0200E7C4[];
extern const struct Kind D_0867006C[];
extern u8 D_0866C754[][24];
extern u8 D_0866634C[];
extern u8 D_08675C5C[];
extern u8 D_0875B304[];

void func_08036DE0(u8, u16, u8 *);
void func_0803E488(u8 *, s32);
void func_0804DDB4(u8 *);

void func_08054EA4(u8 pilot, u8 zoid, s16 slot)
{
    u8 *info;

    if (zoid != 0xFF)
    {
        if (D_02000B5C.zoids[zoid].parts[slot].id != 0xFFFF)
        {
            if (pilot != 0xFF)
            {
                func_08036DE0(pilot, D_02000B5C.zoids[zoid].parts[slot].id, D_0200E7C4);
                func_0803E488(D_0866634C, D_02000B5C.zoids[zoid].parts[slot].id);
                func_0803E488(D_08675C5C, 0);
                func_0804DDB4(D_0200E7C4);
            }
            else
            {
                info = D_0866C754[D_02000B5C.zoids[zoid].parts[slot].id];
                func_0803E488(D_0866634C, D_02000B5C.zoids[zoid].parts[slot].id);
                func_0803E488(D_08675C5C, 0);
                func_0804DDB4(info);
            }
        }
        else
        {
            func_0803E488(D_0875B304, 1);
        }
    }
    else
    {
        if (D_0867006C[pilot].parts[slot].id != 0xFFFF)
        {
            info = D_0866C754[D_0867006C[pilot].parts[slot].id];
            func_0803E488(D_0866634C, D_0867006C[pilot].parts[slot].id);
            func_0803E488(D_08675C5C, 0);
            func_0804DDB4(info);
        }
        else
        {
            func_0803E488(D_0875B304, 1);
        }
    }
}
