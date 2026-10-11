#include "types.h"

extern u8 D_0300232A;
extern u8 D_0300232B[];
extern u8 D_03002300[];
extern u8 D_03002306[][6];
extern struct
{
    u8 pad_0[0x22B0];
    u8 refresh;
} D_0200EB84;

u8 func_08059A78(void);
s32 func_08001080(void);
void func_0805990C(u8, u8);
void func_08059980(void);
void func_08059C48(void);

void func_08059B68(void)
{
    u8 i = 0;

    for (;;)
    {
        if (func_08059A78())
        {
            u8 j;

            i = (func_08001080() * D_0300232A) / 0x10000;
            j = (D_0300232B[i] * func_08001080()) / 0x10000;
            func_0805990C(D_03002300[i], D_03002306[i][j]);
            return;
        }
        if (i == 0)
        {
            func_08059980();
            func_08059C48();
            i = 1;
        }
        else
        {
            D_0200EB84.refresh = 1;
            return;
        }
    }
}
