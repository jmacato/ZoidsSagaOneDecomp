#include "types.h"

struct Member
{
    u16 flags[6];
    u8 pad_C[0x34];
};

struct Team
{
    u8 kind;
    u8 field_1;
    s16 field_2;
    u32 flags;
    struct Member members[6];
};

struct Unit
{
    u8 pad_0[0x10];
    s32 hp;
    u8 pad_14[0xE4];
    s32 max_hp;
    u8 pad_FC[0x1D0];
};

extern struct Team D_02010E40[];
extern struct Unit D_0200FC64[];
extern u8 D_0300232A;
extern u8 D_0300232B[];
extern u8 D_03002300[];
extern u8 D_03002306[][6];

u8 func_08059A88(u8, u8);

void func_0805A924(void)
{
    s32 best = 0;
    u8 i;
    u8 j;
    u8 k;
    s32 damage;
    struct Team *team;
    struct Member *member;
    struct Unit *unit;

    for (i = 0; i < D_0300232A; i++)
    {
        team = &D_02010E40[D_03002300[i]];
        if (team->flags & 0x80000)
        {
            for (j = 0; j < D_0300232B[i]; j++)
            {
                member = &team->members[D_03002306[i][j]];
                for (k = 0; k < 6; k++)
                {
                    if (member->flags[k] & 1)
                    {
                        unit = &D_0200FC64[k];
                        damage = unit->max_hp - unit->hp;
                        if (damage >= unit->max_hp * 2 / 3 && damage > best)
                            best = damage;
                    }
                }
            }
        }
    }
    for (i = 0; i < D_0300232A; i++)
    {
        team = &D_02010E40[D_03002300[i]];
        for (j = 0; j < D_0300232B[i]; j++)
        {
            member = &team->members[D_03002306[i][j]];
            if (!(team->flags & 0x80000) || best == 0)
            {
                k = 6;
            }
            else
            {
                for (k = 0; k < 6; k++)
                {
                    if (member->flags[k] & 1)
                    {
                        unit = &D_0200FC64[k];
                        damage = unit->max_hp - unit->hp;
                        if (damage == best)
                            break;
                    }
                }
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
