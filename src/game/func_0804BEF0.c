#include "types.h"

struct Page
{
    u8 pad_0[5];
    u8 text[0x83];
};

extern const struct Page D_086D49EC[];
extern const u8 D_086D46E0[][130];
extern u8 D_030022F8;
extern u8 D_030022F9;

u16 func_0804BEF0(u8 kind, u8 column, u8 row)
{
    u16 code;

    if (kind == 7)
    {
        code = D_086D49EC[D_030022F8 + D_030022F9].text[column * 2 + row * 26] | (D_086D49EC[D_030022F8 + D_030022F9].text[column * 2 + row * 26 + 1] << 8);
        if (code == 0)
            code = 0x8140;
    }
    else
        code = D_086D46E0[kind - 1][column * 2 + row * 26] | (D_086D46E0[kind - 1][column * 2 + row * 26 + 1] << 8);
    return code;
}
