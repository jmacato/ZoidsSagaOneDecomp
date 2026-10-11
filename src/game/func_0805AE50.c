#include "types.h"

struct Unit
{
    u8 pad_0[0x42];
    u8 id;
    u8 pad_43[0x289];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Member
{
    u16 flags[6];
    u8 pad_C[0x34];
};

struct Team
{
    u8 kind;
    u8 side;
    u8 pad_2[6];
    struct Member members[6];
};

extern struct
{
    u8 pad_0[8];
    struct Side sides[2];
    u8 pad_21B8[0x104];
    struct Team teams[6];
} D_0200EB84;

extern u8 D_0300232A;
extern u8 D_0300232B[];
extern u8 D_03002300[];
extern u8 D_03002306[][6];

u8 func_08059A88(u8, u8);

void func_0805AE50(u8 id)
{
    u8 i;
    u8 j;
    u8 k;

    for (i = 0; i < D_0300232A; i++)
    {
        struct Team *team = &D_0200EB84.teams[D_03002300[i]];

        for (j = 0; j < D_0300232B[i]; j++)
        {
            struct Member *member = &D_0200EB84.teams[D_03002300[i]].members[D_03002306[i][j]];

            for (k = 0; k < 6; k++)
            {
                if ((member->flags[k] & 1) && (D_0200EB84.sides + team->side)->units[k].id == id)
                    break;
            }
            if (k == 6)
            {
                if (!func_08059A88(i, j))
                {
                    i--;
                    break;
                }
                j--;
            }
        }
    }
}
