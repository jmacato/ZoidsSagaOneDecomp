#include "types.h"

extern u32 D_08663B8C[];
extern const u8 D_083663D4[];
extern u16 D_0866B7EC[];
extern u8 D_0866B7E4[];
extern u8 D_0866B7E8[];

void func_0805D270(const void *, void *, u32);

void func_08031FB4(u32 hp, u32 energy, u8 slot)
{
    u8 hp_digits[4];
    u8 energy_digits[16];
    u8 i;
    u32 value;

    if (hp > 9999)
    {
        for (i = 0; i < 4; i++)
            hp_digits[i] = 9;
    }
    else
    {
        value = hp;
        for (i = 0; i < 3; i++)
        {
            hp_digits[i] = value / D_08663B8C[i + 3];
            value = value % D_08663B8C[i + 3];
        }
        hp_digits[i] = value;
    }
    if (energy > 999)
    {
        for (i = 0; i < 3; i++)
            energy_digits[i] = 9;
    }
    else
    {
        value = energy;
        for (i = 0; i < 2; i++)
        {
            energy_digits[i] = value / D_08663B8C[i + 4];
            value = value % D_08663B8C[i + 4];
        }
        energy_digits[i] = value;
    }
    for (i = 0; i < 4; i++)
        func_0805D270(D_083663D4 + hp_digits[i] * 32, (void *)(0x06010000 + (D_0866B7EC[slot] + D_0866B7E4[i]) * 32), 0x10);
    func_0805D270(D_083663D4 + 0x280, (void *)(0x06010060 + D_0866B7EC[slot] * 32), 0x10);
    for (i = 0; i < 3; i++)
        func_0805D270(D_083663D4 + (energy_digits[i] + 10) * 32, (void *)(0x06010000 + (D_0866B7EC[slot] + D_0866B7E8[i]) * 32), 0x10);
}
