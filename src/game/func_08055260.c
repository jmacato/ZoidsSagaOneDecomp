#include "types.h"

struct Price
{
    u8 pad_0[4];
    u32 cost;
    u8 pad_8[4];
    u8 stock;
    u8 item_1;
    u8 item_2;
};

struct Info
{
    u8 pad_0[0x20];
    struct Price price;
    u8 pad_30[0x1C];
};

extern struct Info D_0867006C[];
extern struct
{
    u8 pad_0[0xD28];
    u32 money;
    u8 pad_D2C[0x25E0];
    u8 items[0x100];
} D_02000B5C;
extern u8 D_0200E8A1;

void func_080550E4(u16);

u8 func_08055260(u16 kind)
{
    u8 result = 0;
    struct Price *price = &D_0867006C[kind].price;

    if (price->cost > D_02000B5C.money)
        result = 1;
    if (price->stock != 0)
    {
        func_080550E4(kind);
        if (D_0200E8A1 == 0)
            result |= 2;
    }
    if (price->item_1 != 0xFF && D_02000B5C.items[price->item_1] == 0)
        result |= 4;
    if (price->item_2 != 0xFF && D_02000B5C.items[price->item_2] == 0)
        result |= 4;
    return result;
}
