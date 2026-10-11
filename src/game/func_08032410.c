#include "types.h"

struct Unit
{
    u8 pad_0[0x108];
    u16 speed;
    u8 pad_10A[0x1C2];
};

struct Side
{
    struct Unit units[6];
    u8 pad_10C8[0x10];
};

struct Turn
{
    u8 side;
    u8 slot;
    u8 pad_2[2];
};

struct Order
{
    struct Turn turn;
    u16 speed;
};

extern struct
{
    union
    {
        struct Side sides[2];
        struct
        {
            u8 pad_0[2];
            u16 flags;
        } info;
    } u;
    u8 pad_21B0[4];
    u8 count;
    u8 current;
    u8 pad_21B6[2];
    struct Turn turns[12];
} D_0200EB84;

extern struct Order D_02011770[];

void func_08032C44(void);
u8 func_08032A88(u8, u8);
void func_080325C8(u8, struct Order *);
void func_0803262C(u8, struct Order *);
void func_08032564(u8, struct Order *);

void func_08032410(void)
{
    struct Turn unused[15];
    u8 count;
    u8 side;
    u8 i;

    func_08032C44();
    count = 0;
    for (side = 0; side < 2; side++)
    {
        for (i = 0; i < 6; i++)
        {
            if (func_08032A88(side, i))
            {
                D_0200EB84.turns[count].slot = i;
                D_0200EB84.turns[count].side = side;
                count++;
            }
        }
    }
    D_0200EB84.count = count;
    D_0200EB84.current = 0;
    for (i = 0; i < D_0200EB84.count; i++)
    {
        D_02011770[i].turn = D_0200EB84.turns[i];
        D_02011770[i].speed = D_0200EB84.u.sides[D_0200EB84.turns[i].side].units[D_0200EB84.turns[i].slot].speed;
    }
    if (D_0200EB84.u.info.flags & 8)
        func_080325C8(D_0200EB84.count, D_02011770);
    else if (D_0200EB84.u.info.flags & 0x10)
        func_0803262C(D_0200EB84.count, D_02011770);
    else
        func_08032564(D_0200EB84.count, D_02011770);
    for (i = 0; i < D_0200EB84.count; i++)
        D_0200EB84.turns[i] = D_02011770[i].turn;
}
