#include "types.h"

struct Zoid
{
    u8 pad_0[2];
    u16 flags;
    u8 pad_4[2];
    u8 kind;
    u8 pad_7[0x31];
};

struct Entry
{
    u8 zoid;
    u8 pilot;
    u8 pad_2[2];
};

struct Info
{
    u16 flags;
    u8 pad_2[2];
    u8 type;
    u8 pad_5[0x47];
};

extern struct
{
    u8 pad_0[0xD2C];
    struct Zoid zoids[1];
    u8 pad_D64[0x3600 - 0xD64];
    struct Entry entries[6];
} D_02000B5C;
extern struct Info D_0867006C[];

u8 func_080388A4(void);

u8 func_08038674(void)
{
    u8 ok = 1;
    u8 i;

    if (func_080388A4() > 3)
        ok = 0;
    if (ok)
    {
        for (i = 0; i < 6; i++)
        {
            if (D_02000B5C.entries[i].zoid != 0xFF && D_0867006C[D_02000B5C.zoids[D_02000B5C.entries[i].zoid].kind].type != 0)
            {
                ok = 0;
                break;
            }
        }
    }
    return ok;
}

u8 func_080386E4(void)
{
    return 1;
}

u8 func_080386E8(void)
{
    return 1;
}
