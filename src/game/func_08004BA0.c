#include "types.h"

struct Player
{
    u16 id;
    u8 pad_2[0x16];
};

extern u32 D_03001F4C;
extern u16 D_03001ED4;
extern struct Player D_03001EEC[];

u8 func_08004BA0(void)
{
    u8 result = 0;
    u8 i = 0;

    if ((D_03001F4C & (1 << i)) && D_03001EEC[i].id == D_03001ED4)
    {
        do
            i++;
        while (i < 2 && ((D_03001F4C & (1 << i)) && D_03001EEC[i].id == D_03001ED4));
    }
    if (i == 2)
        result = 1;
    return result;
}

u8 func_08004C08(void)
{
    u8 result = 0;
    u8 i = 0;

    if (D_03001F4C & (1 << i))
    {
        do
            i++;
        while (i < 2 && (D_03001F4C & (1 << i)));
    }
    if (i == 2)
        result = 1;
    return result;
}
