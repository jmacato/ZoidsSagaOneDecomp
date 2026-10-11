#include "types.h"

struct Item
{
    u32 money;
    u8 zoid;
    u8 pad_5;
    u16 part;
    u8 pilot;
    u8 item;
    u8 pad_A[2];
};

extern const u8 D_0874FA90[];
extern const u8 D_08675BEC[];
extern const u8 D_08675C5C[];
extern const u8 D_0866634C[];
extern struct Item D_0866BB40[];

extern struct
{
    u8 pad_0[0xC];
    u16 part;
} D_02007574;

void func_0803E488(const u8 *, s32);
void func_08036FAC(u8, s32);
void func_080328E4(u8);
void func_08032800(u8);
s32 func_08037004(u8);
void func_08036FD8(u16, s32);
void func_08036F80(u8, s32);
void func_08032840(u8);
void func_0803706C(u32);
void func_08001848(u32, s32, s32);

void func_08037614(u16 index)
{
    func_0803E488(D_0874FA90, 0x1F);
    if (D_0866BB40[index].item != 0xFF)
    {
        func_08036FAC(D_0866BB40[index].item, 1);
        func_0803E488(D_08675BEC, 6);
        func_0803E488(D_08675BEC, 7);
        func_0803E488(D_08675C5C, 0x28);
        func_080328E4(D_0866BB40[index].item);
        func_0803E488(D_08675C5C, 9);
        func_0803E488(D_08675BEC, 5);
    }
    else if (D_0866BB40[index].zoid)
    {
        func_0803E488(D_08675BEC, 6);
        func_0803E488(D_08675BEC, 7);
        func_0803E488(D_08675C5C, 0x2A);
        func_08032800(D_0866BB40[index].zoid);
        func_0803E488(D_08675C5C, 0x2B);
        func_0803E488(D_08675BEC, 5);
        if (func_08037004(D_0866BB40[index].zoid))
        {
            func_0803E488(D_08675BEC, 0x14);
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675C5C, 0x2C);
            func_0803E488(D_08675BEC, 5);
        }
    }
    else if (D_0866BB40[index].part != 0xFFFF)
    {
        func_08036FD8(D_0866BB40[index].part, 1);
        func_0803E488(D_08675BEC, 6);
        func_0803E488(D_08675BEC, 7);
        func_0803E488(D_08675C5C, 0x29);
        D_02007574.part = D_0866BB40[index].part;
        func_0803E488(D_0866634C, D_02007574.part);
        func_0803E488(D_08675C5C, 9);
        func_0803E488(D_08675BEC, 5);
    }
    else if (D_0866BB40[index].pilot != 0xFF)
    {
        func_08036F80(D_0866BB40[index].pilot, 1);
        func_0803E488(D_08675BEC, 6);
        func_0803E488(D_08675BEC, 7);
        func_0803E488(D_08675C5C, 0x27);
        func_08032840(D_0866BB40[index].pilot);
        func_0803E488(D_08675C5C, 9);
        func_0803E488(D_08675BEC, 5);
    }
    else if (D_0866BB40[index].money)
    {
        func_0803706C(D_0866BB40[index].money);
        func_0803E488(D_08675BEC, 6);
        func_0803E488(D_08675BEC, 7);
        func_08001848(D_0866BB40[index].money, 7, 1);
        func_0803E488(D_08675C5C, 0xA);
        func_0803E488(D_08675BEC, 5);
    }
    func_0803E488(D_0874FA90, 0x22);
}
