#include "types.h"

struct Entry
{
    u8 zoid;
    u8 pilot;
    u8 pad_2[2];
};

extern struct
{
    u8 pad_0[0x3600];
    struct Entry entries[6];
} D_02000B5C;

struct Member
{
    u8 pad_0[0x36];
    u8 active;
    u8 data[6];
    u8 pad_3D[3];
};

struct Team
{
    u8 kind;
    u8 side;
    u8 pad_2[6];
    struct Member members[6];
};

extern struct Team D_02010E40[];

extern struct
{
    u8 pad_0[0x22B0];
    u8 empty;
    u8 team;
    u8 pad_22B2;
    u8 side;
    u8 data[6];
} D_0200EB84;

void func_08038A6C(void);

u8 func_08038910(u8 unused, u8 *out)
{
    u8 count = 0;
    u8 i;

    for (i = 0; i < 6; i++)
    {
        if (D_02000B5C.entries[i].zoid != 0xFF)
        {
            out[count] = D_02000B5C.entries[i].pilot;
            count++;
        }
    }
    return count;
}

void func_08038958(void)
{
    u8 i;
    u8 j;
    u8 k;
    struct Team *team;

    func_08038A6C();
    for (i = 0; i < 6; i++)
    {
        team = &D_02010E40[i];
        if (team->kind != 0xFF)
            break;
    }
    D_0200EB84.empty = 1;
    if (i < 6)
    {
        for (j = 0; j < team->kind; j++)
        {
            struct Member *member = &team->members[j];

            if (member->active)
            {
                D_0200EB84.empty = 0;
                D_0200EB84.team = i;
                D_0200EB84.side = team->side;
                for (k = 0; k < 6; k++)
                    D_0200EB84.data[k] = member->data[k];
                break;
            }
        }
    }
}
