#include "types.h"

extern u16 D_0200E8A6;
extern u32 D_08663F54[];
extern u32 D_03000204;
extern u8 D_02000030;

void func_0805EE78(s32);
void func_08003DD8(u8);

void func_08002E48(void)
{
    u32 i;

    D_0200E8A6 = 16;
    for (i = 0; D_08663F54[i] != 0; i++)
    {
        D_03000204 = D_08663F54[i];
        D_0200E8A6--;
        func_0805EE78(1);
    }
    func_08003DD8(D_02000030);
}
