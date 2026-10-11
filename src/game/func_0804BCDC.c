#include "types.h"

extern u8 D_0200758C[];
extern struct
{
    u8 pad_0[0xD18];
    u8 name[16];
} D_02000B5C;

void func_0804BCDC(void)
{
    u16 i;

    for (i = 0; i <= 7; i++)
    {
        D_0200758C[i * 2] = D_02000B5C.name[i * 2] = 0x40;
        D_0200758C[i * 2 + 1] = D_02000B5C.name[i * 2 + 1] = 0x81;
    }
    D_0200758C[0] = D_02000B5C.name[0] = 0x41;
    D_0200758C[1] = D_02000B5C.name[1] = 0x83;
    D_0200758C[2] = D_02000B5C.name[2] = 0x67;
    D_0200758C[3] = D_02000B5C.name[3] = 0x83;
    D_0200758C[4] = D_02000B5C.name[4] = 0x8C;
    D_0200758C[5] = D_02000B5C.name[5] = 0x83;
    D_0200758C[6] = D_02000B5C.name[6] = 0x5B;
    D_0200758C[7] = D_02000B5C.name[7] = 0x81;
}
