#include "m2c.h"

extern struct { u8 pad_0[0xCD2]; u8 f_CD2; } D_02000B5C;

M2C_UNK func_08036904(u8, s32, s32);

void func_080368BC(void)
{
    func_08036904(D_02000B5C.f_CD2, 0, ((u8 *)&D_02000B5C + 0xCE8));
    func_08036904(D_02000B5C.f_CD2, 1, ((u8 *)&D_02000B5C + 0xCF8));
    func_08036904(D_02000B5C.f_CD2, 2, ((u8 *)&D_02000B5C + 0xD08));
}
