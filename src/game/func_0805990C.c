#include "types.h"

struct Member
{
    u16 flags[6];
    u8 pad_C[0x2A];
    u8 active;
    u8 units[6];
    u8 pad_3D[3];
};

struct Team
{
    u8 kind;
    u8 leader;
    u8 pad_2[6];
    struct Member members[6];
};

extern struct
{
    u8 pad_0[0x22B0];
    u8 field_22B0;
    u8 team;
    u8 field_22B2;
    u8 leader;
    u8 units[6];
    u8 pad_22BA[2];
    struct Team teams[6];
} D_0200EB84;

void func_0805990C(u8 team, u8 set)
{
    u8 i;

    D_0200EB84.field_22B0 = 0;
    D_0200EB84.team = team;
    D_0200EB84.field_22B2 = 0;
    D_0200EB84.leader = D_0200EB84.teams[team].leader;
    for (i = 0; i <= 5; i++)
        D_0200EB84.units[i] = D_0200EB84.teams[team].members[set].units[i];
}
