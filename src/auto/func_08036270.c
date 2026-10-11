#include "m2c.h"

extern struct { u8 pad_0[0xCDC]; s16 f_CDC; s16 f_CDE; s16 f_CE0; s16 f_CE2; s16 f_CE4; } D_02000B5C;

M2C_UNK func_08001848(s16, s32, s32);
M2C_UNK func_0803E488(s32, s32);

void func_08036270(u8 *arg0)
{
    func_0803E488(0x08675BEC, 0xE);
    func_0803E488(0x08675BEC, 0xC);
    func_0803E488(0x08675DD4, 0xC);
    func_0803E488(0x08676490, 0);
    func_0803E488(0x08675DD4, 0xC);
    func_08001848(M2C_FIELD(arg0, s16 *, 0x28), 3, 0);
    func_0803E488(0x08675C5C, 0x2D);
    func_08001848(D_02000B5C.f_CDC, 3, 0);
    func_0803E488(0x08675C5C, 0);
    func_0803E488(0x08675DD4, 0xC);
    func_0803E488(0x08676490, 1);
    func_0803E488(0x08675DD4, 0xC);
    func_08001848(M2C_FIELD(arg0, s16 *, 0x2A), 3, 0);
    func_0803E488(0x08675C5C, 0x2D);
    func_08001848(D_02000B5C.f_CE2, 3, 0);
    func_0803E488(0x08675C5C, 0);
    func_0803E488(0x08675DD4, 0xC);
    func_0803E488(0x08676490, 2);
    func_0803E488(0x08675DD4, 0xC);
    func_08001848(M2C_FIELD(arg0, s16 *, 0x2C), 3, 0);
    func_0803E488(0x08675C5C, 0x2D);
    func_08001848(D_02000B5C.f_CE0, 3, 0);
    func_0803E488(0x08675C5C, 0);
    func_0803E488(0x08675DD4, 0xC);
    func_0803E488(0x08676490, 3);
    func_0803E488(0x08675DD4, 0xC);
    func_08001848(M2C_FIELD(arg0, s16 *, 0x2E), 3, 0);
    func_0803E488(0x08675C5C, 0x2D);
    func_08001848(D_02000B5C.f_CDE, 3, 0);
    func_0803E488(0x08675C5C, 0);
    func_0803E488(0x08675DD4, 0xC);
    func_0803E488(0x08676490, 4);
    func_0803E488(0x08675DD4, 0xC);
    func_08001848(M2C_FIELD(arg0, s16 *, 0x30), 3, 0);
    func_0803E488(0x08675C5C, 0x2D);
    func_08001848(D_02000B5C.f_CE4, 3, 0);
}
