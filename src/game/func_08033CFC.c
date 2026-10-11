#include "types.h"

struct Formation
{
    u8 row;
    u8 column;
    u8 pad_2[0x22];
};

struct Cell
{
    u8 kind;
    u8 pad_1[0x1B];
};

extern struct Formation *D_08683720[][12];
extern struct Formation D_02004A70[];
extern struct Cell D_086787A4[][32];

u8 func_08033CFC(u8 stage, u8 group, u8 slot, u8 target)
{
    struct Formation *formation;

    if (stage > 10)
        stage = 0;
    formation = D_08683720[stage][group];
    D_02004A70[target] = formation[slot];
    return D_086787A4[formation->row][formation->column].kind;
}
