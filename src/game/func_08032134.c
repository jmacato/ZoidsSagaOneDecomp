#include "types.h"

struct Entry
{
    u8 kind;
    u8 a;
    u8 b;
    u8 pad_3;
    u16 c;
    u8 pad_6[2];
};

extern struct Entry D_0866B868[];

void func_080321AC(u8, u16, u8);
void func_08032208(u8, u16, u8);

void func_08032134(u8 index)
{
    if (D_0866B868[index].kind == 0)
        func_080321AC(D_0866B868[index].a, D_0866B868[index].c, D_0866B868[index].b);
    else
        func_08032208(D_0866B868[index].a, D_0866B868[index].c, D_0866B868[index].b);
}
