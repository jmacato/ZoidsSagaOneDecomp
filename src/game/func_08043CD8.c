#include "types.h"

extern u8 D_0200DAA0;
extern u32 D_0200DAAC[];
extern u32 D_0200DFAC[];
extern u32 D_0200DD2C[];
extern u8 D_086F6A18[];
extern u8 D_086F6790[];
extern u8 D_085643A4[];

void func_08001A54(u8 *, u16, s32);
void func_08043D54(u8 *, u8);

void func_08043CD8(u16 tile, u8 mode)
{
    u8 i;

    D_0200DAA0 = tile;
    for (i = 0; i < 0x80; i++)
    {
        D_0200DAAC[i] = 0;
        D_0200DFAC[i] = 0;
        D_0200DD2C[i] = 0;
    }
    func_08001A54(D_086F6A18, tile, 1);
    func_08001A54(D_086F6790, tile, 1);
    func_08043D54(D_085643A4, mode);
}
