#include "types.h"

struct Point
{
    u32 coords[2];
};

extern struct
{
    void *first;
} D_02000000;

extern struct
{
    u8 pad_0[0x330];
    u16 flags;
    u8 pad_332[0xA];
    u32 count;
} D_03004BBC;

extern const struct Point D_0866A62C[];

s32 func_08001080(void);
void func_08008B70(s32, u16, u16);
void func_08000BD8(s32, s32);
void func_080019EC(s32);
void func_0802163C(void);

void func_080215C8(void)
{
    u8 index = func_08001080() % 4;

    func_08008B70(5, D_0866A62C[index].coords[0], D_0866A62C[index].coords[1]);
    D_03004BBC.count++;
    func_08000BD8(6, 0);
    D_03004BBC.flags |= 0x400;
    func_080019EC(0x5B);
    D_02000000.first = func_0802163C;
}
