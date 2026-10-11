#include "types.h"

extern struct
{
    void *first;
    void *second;
    u16 counter;
} D_02000000;

struct Object
{
    u8 pad_0[8];
    u32 x;
    u32 y;
    u8 pad_10[0x50];
    u16 arrived;
    u8 pad_62[0x26];
};

extern struct Object D_03004BBC[];

void func_08008B58(s32);
void func_08016CA8(s32, u32, u32);
void func_08016BC8(s32);
void func_08008024(void);
void func_08003DD8(s32);

void func_08016C38(s32 index, s32 kind)
{
    func_08008B58(0xD9);
    if (kind != -1)
        func_08016CA8(kind, D_03004BBC[index + 1].x >> 21, D_03004BBC[index + 1].y >> 21);
    func_08016BC8(index);
    D_02000000.first = func_08008024;
    func_08003DD8(3);
    D_03004BBC[1].arrived = 0;
    D_02000000.counter &= 0xFFFD;
}
