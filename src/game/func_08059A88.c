#include "types.h"

extern u8 D_0300232A;
extern u8 D_0300232B[];
extern u8 D_03002300[];
extern u8 D_03002306[][6];

u8 func_08059A88(u8 team, u8 slot)
{
    u8 i;
    u8 j;

    if (slot != 0xFF)
    {
        D_0300232B[team]--;
        if (D_0300232B[team] != 0)
        {
            for (i = slot; i < D_0300232B[team]; i++)
                D_03002306[team][i] = D_03002306[team][i + 1];
            return 1;
        }
    }
    D_0300232A--;
    for (i = team; i < D_0300232A; i++)
    {
        D_03002300[i] = D_03002300[i + 1];
        for (j = 0; j < 6; j++)
            D_03002306[i][j] = D_03002306[i + 1][j];
        D_0300232B[i] = D_0300232B[i + 1];
    }
    return 0;
}
