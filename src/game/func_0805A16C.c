#include "types.h"

struct Weapon
{
    u16 flags;
    u16 id;
};

struct Attack
{
    s32 power;
    s32 field_4;
};

struct Unit
{
    u8 pad_0[0x10];
    s32 hp;
    u8 pad_14[4];
    struct Weapon weapons[6];
    u8 pad_30[0xD2];
    s16 field_102;
    u8 pad_104[0x10];
    struct Attack attacks[6];
    u8 pad_144[0x188];
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
    u8 field_1;
    s16 field_2;
    u32 flags;
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

void func_0805A16C(void)
{
    s32 best = 0;
    s32 count;
    u8 i;
    u8 j;
    u8 k;
    struct Member *member;

    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            member = &D_0200EB84.teams[D_03002300[i]].members[D_03002306[i][j]];
            count = 0;
            for (k = 0; k < 6; k++)
            {
                if (member->flags[k] & 1)
                    count++;
            }
            if (count > best)
                best = count;
        }
    }
    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            member = &D_0200EB84.teams[D_03002300[i]].members[D_03002306[i][j]];
            count = 0;
            for (k = 0; k < 6; k++)
            {
                if (member->flags[k] & 1)
                    count++;
            }
            if (count != best)
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

void func_0805A2DC(void)
{
    s32 best = 0x7FFFFFFF;
    u8 i;
    u8 j;
    u8 k;
    struct Member *member;
    struct Unit *unit;

    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            member = &D_0200EB84.teams[D_03002300[i]].members[D_03002306[i][j]];
            for (k = 0; k < 6; k++)
            {
                if (member->flags[k] & 1)
                {
                    unit = &D_0200EB84.sides[0].units[k];
                    if (unit->hp < best)
                        best = unit->hp;
                }
            }
        }
    }
    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            member = &D_0200EB84.teams[D_03002300[i]].members[D_03002306[i][j]];
            for (k = 0; k < 6; k++)
            {
                if (member->flags[k] & 1)
                {
                    unit = &D_0200EB84.sides[0].units[k];
                    if (unit->hp == best)
                        break;
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

void func_0805A474(void)
{
    s32 best = 0x7FFFFFFF;
    u8 i;
    u8 j;
    u8 k;
    struct Member *member;
    struct Unit *unit;

    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            member = &D_0200EB84.teams[D_03002300[i]].members[D_03002306[i][j]];
            for (k = 0; k < 6; k++)
            {
                if (member->flags[k] & 1)
                {
                    unit = &D_0200EB84.sides[0].units[k];
                    if (unit->field_102 < best)
                        best = unit->field_102;
                }
            }
        }
    }
    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            member = &D_0200EB84.teams[D_03002300[i]].members[D_03002306[i][j]];
            for (k = 0; k < 6; k++)
            {
                if (member->flags[k] & 1)
                {
                    unit = &D_0200EB84.sides[0].units[k];
                    if (unit->field_102 == best)
                        break;
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

void func_0805A628(void)
{
    s32 best = 0;
    u8 i;
    u8 j;
    u8 k;
    u8 m;
    struct Member *member;
    struct Unit *unit;

    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            member = &D_0200EB84.teams[D_03002300[i]].members[D_03002306[i][j]];
            for (k = 0; k < 6; k++)
            {
                if (member->flags[k] & 1)
                {
                    unit = &D_0200EB84.sides[0].units[k];
                    for (m = 0; m < 6; m++)
                    {
                        if (unit->weapons[m].id != 0xFFFF && unit->attacks[m].power > best)
                            best = unit->attacks[m].power;
                    }
                }
            }
        }
    }
    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            member = &D_0200EB84.teams[D_03002300[i]].members[D_03002306[i][j]];
            for (k = 0; k < 6; k++)
            {
                if (member->flags[k] & 1)
                {
                    unit = &D_0200EB84.sides[0].units[k];
                    for (m = 0; m < 6; m++)
                    {
                        if (unit->weapons[m].id != 0xFFFF && unit->attacks[m].power == best)
                            break;
                    }
                    if (m != 6)
                        break;
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

void func_0805A818(void)
{
    u8 i;
    u8 j;
    u8 k;
    u8 m;
    struct Member *member;
    struct Unit *unit;

    for (i = 0; i < D_0300232A; i++)
    {
        for (j = 0; j < D_0300232B[i]; j++)
        {
            member = &D_0200EB84.teams[D_03002300[i]].members[D_03002306[i][j]];
            for (k = 0; k < 6; k++)
            {
                if (member->flags[k] & 1)
                {
                    unit = &D_0200EB84.sides[0].units[k];
                    for (m = 0; m < 6; m++)
                    {
                        if (unit->weapons[m].id != 0xFFFF && (unit->weapons[m].flags & 2))
                            break;
                    }
                    if (m != 6)
                        break;
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
