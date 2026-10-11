#include "m2c.h"

extern u8 D_08675BEC[];
extern u8 D_08675C5C[];

M2C_UNK func_08001848(s16, s32, s32);
M2C_UNK func_0803E488(s32, s32);

void func_0803641C(u8 *arg0)
{
    func_0803E488(D_08675BEC, 6);
    func_0803E488(D_08675BEC, 7);
    func_0803E488(D_08675C5C, 0x2F);
    func_08001848(M2C_FIELD(arg0, s16 *, 0x36), 7, 1);
    func_0803E488(D_08675C5C, 0x30);
}
