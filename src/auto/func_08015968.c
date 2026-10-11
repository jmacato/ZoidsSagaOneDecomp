#include "m2c.h"

extern struct { s32 f_0; } D_02000000;
extern struct { u8 pad_0[0xD2]; u16 f_D2; } D_03004BBC;

M2C_UNK func_08003DD8(s32);
M2C_UNK func_08008B58(s32);
M2C_UNK func_080144BC();
M2C_UNK func_0805EE78(s32);

void func_08015968(void)
{
    if (D_03004BBC.f_D2 != 0)
    {
        do
        {
            func_0805EE78(1);
        } while (D_03004BBC.f_D2 != 0);
    }
    func_08008B58(0xD4);
    D_02000000.f_0 = 0x08008025;
    func_08003DD8(3);
    D_02000000.f_0 = 0x080144DD;
    func_080144BC();
}
