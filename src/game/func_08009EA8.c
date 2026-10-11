#include "types.h"

struct Table
{
    u8 bytes[0x88];
};

extern const struct Table D_08329F2C;

s32 func_08000CEC(u16, struct Table *, s32);

s32 func_08009EA8(u16 id)
{
    struct Table table = D_08329F2C;

    return func_08000CEC(id, &table, 0);
}
