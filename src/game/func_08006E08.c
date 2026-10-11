#include "types.h"

struct Setting
{
    u16 first;
    u16 second;
    u16 third;
    u16 pad;
};

struct Settings
{
    struct Setting entries[23];
};

extern const struct Settings D_08328C54;
extern struct
{
    u16 first;
    u16 second;
    u16 third;
} D_02007560;
extern struct
{
    u8 pad_0[3];
    u8 index;
} D_02000B5C;

s32 func_08006E08(void)
{
    struct Settings settings = D_08328C54;

    D_02007560.first = settings.entries[D_02000B5C.index].first;
    D_02007560.second = settings.entries[D_02000B5C.index].second;
    D_02007560.third = settings.entries[D_02000B5C.index].third;
}
