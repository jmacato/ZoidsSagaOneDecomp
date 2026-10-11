#include "m2c.h"

extern struct { u8 pad_0[0x229C]; s16 f_229C; s16 f_229E; } D_0200EB84;

M2C_UNK func_080316EC();
M2C_UNK func_08032C44();

void func_0802F8AC(u8 *arg0)
{
    func_08032C44();
    D_0200EB84.f_229C = 0;
    D_0200EB84.f_229E = 0;
    M2C_FIELD(arg0, u16 *, 8) = (u16) (0xFEFF & M2C_FIELD(arg0, u16 *, 8));
    func_080316EC();
}
