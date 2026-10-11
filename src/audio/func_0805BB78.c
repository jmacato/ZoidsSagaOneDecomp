#include "types.h"

struct WaveData
{
    u16 type;
    u16 status;
    u32 freq;
};

extern const u8 D_08566110[];
extern const u32 D_085661C4[];

u32 func_0805AFE0(u32, u32);

u32 func_0805BB78(struct WaveData *wav, u8 key, u8 fine_adjust)
{
    u32 val1;
    u32 val2;
    u32 fine_adjust_shifted = fine_adjust << 24;

    if (key > 178)
    {
        key = 178;
        fine_adjust_shifted = 255 << 24;
    }

    val1 = D_08566110[key];
    val1 = D_085661C4[val1 & 0xF] >> (val1 >> 4);

    val2 = D_08566110[key + 1];
    val2 = D_085661C4[val2 & 0xF] >> (val2 >> 4);

    return func_0805AFE0(wav->freq, val1 + func_0805AFE0(val2 - val1, fine_adjust_shifted));
}

void func_0805BBDC(void)
{
}
