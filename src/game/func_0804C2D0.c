#include "types.h"

struct KanaEntry
{
    u16 key;
    u16 base;
    u8 count;
    u8 pad[0x83];
};

extern u8 D_030022E4;
extern u8 D_030022E5;
extern u8 D_030022E6;
extern u8 D_030022E7;
extern u16 D_030022E8[];
extern u8 D_030022F8;
extern u8 D_030022F9;
extern u16 D_0200758C[];
extern struct KanaEntry D_086D49EC[];

void func_080019EC(s32);
void func_0803E454(s32);
void func_08000BD8(s32, s32);
u16 func_0804BEF0(u8, u8, u8);
u16 func_0804C024(u16);
u8 func_0804C1C0(u8, u8, u16);
void func_0804BEC0(u8, u8);

u8 func_0804C2D0(u16 keys)
{
    u16 ch;
    u16 i;

    if (keys & 4)
    {
        func_080019EC(0x47);
        switch (D_030022E4)
        {
        case 1:
            D_030022E4 = 2;
            func_0803E454(0x1C);
            break;
        case 2:
            D_030022E4 = 3;
            func_0803E454(0x1D);
            break;
        case 3:
            D_030022E4 = 4;
            func_0803E454(0x20);
            break;
        case 4:
            D_030022E4 = 5;
            func_0803E454(0x21);
            break;
        case 5:
            D_030022E4 = 6;
            func_0803E454(0x22);
            break;
        case 6:
            D_030022E4 = 1;
            func_0803E454(0x1B);
            break;
        case 7:
            if (++D_030022F9 < D_086D49EC[D_030022F8].count)
            {
                func_0803E454((u16)(D_086D49EC[D_030022F8].base + D_030022F9));
            }
            else
            {
                D_030022E4 = 6;
                func_0803E454(0x22);
            }
            break;
        }
    }
    if (keys & 1)
    {
        func_080019EC(0x47);
        switch (D_030022E4)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            ch = func_0804BEF0(D_030022E4, D_030022E6, D_030022E7);
            ch = func_0804C024(ch);
            switch (ch)
            {
            case 0xFFFE:
            case 0xFFFF:
                D_030022E5 = func_0804C1C0(D_030022E5, D_030022E4, ch);
                break;
            default:
                *(D_0200758C + D_030022E5) = ch;
                *(D_030022E8 + D_030022E5) = ch;
                if (D_030022E5 <= 6)
                    D_030022E5++;
                break;
            }
            func_0803E454(0x1E);
            func_08000BD8(2, D_030022E5);
            break;
        case 7:
            ch = func_0804BEF0(7, D_030022E6, D_030022E7);
            ch = func_0804C024(ch);
            switch (ch)
            {
            case 0xFFFE:
            case 0xFFFF:
                D_030022E5 = func_0804C1C0(D_030022E5, D_030022E4, ch);
                break;
            default:
                *(D_0200758C + D_030022E5) = ch;
                *(D_030022E8 + D_030022E5) = ch;
                if (D_030022E5 <= 6)
                    D_030022E5++;
                break;
            }
            func_0803E454(0x1E);
            func_08000BD8(2, D_030022E5);
            D_030022E4 = 6;
            func_0803E454(0x22);
            break;
        case 6:
            ch = func_0804BEF0(6, D_030022E6, D_030022E7);
            if (ch == 0x8140)
            {
                *(D_0200758C + D_030022E5) = ch;
                *(D_030022E8 + D_030022E5) = ch;
                if (D_030022E5 <= 6)
                    D_030022E5++;
                func_0803E454(0x1E);
                func_08000BD8(2, D_030022E5);
            }
            else
            {
                for (i = 0; D_086D49EC[i].key != ch; i++)
                {
                    if (D_086D49EC[i].key == 0xFFFF)
                        break;
                }
                D_030022F8 = i;
                D_030022F9 = 0;
                func_0803E454(D_086D49EC[D_030022F8].base);
                D_030022E4 = 7;
            }
            break;
        }
    }
    if (keys & 2)
    {
        func_080019EC(0x3F);
        *(D_0200758C + D_030022E5) = 0x8140;
        *(D_030022E8 + D_030022E5) = 0x8140;
        if (D_030022E5)
            D_030022E5--;
        func_0803E454(0x1E);
        func_08000BD8(2, D_030022E5);
    }
    if (keys & 0x200)
    {
        func_080019EC(0x40);
        if (D_030022E5)
            D_030022E5--;
        else
            D_030022E5 = 7;
        func_08000BD8(1, 1);
        func_08000BD8(2, D_030022E5);
    }
    if (keys & 0x100)
    {
        func_080019EC(0x40);
        if (D_030022E5 <= 6)
            D_030022E5++;
        else
            D_030022E5 = 0;
        func_08000BD8(1, 2);
        func_08000BD8(2, D_030022E5);
    }
    if (keys & 8)
        return 0xFF;
    if (keys & 0x20)
    {
        func_080019EC(0x40);
        if (D_030022E6)
            D_030022E6--;
        else
            D_030022E6 = 12;
        func_0804BEC0(D_030022E6, D_030022E7);
    }
    if (keys & 0x10)
    {
        func_080019EC(0x40);
        if (D_030022E6 <= 11)
            D_030022E6++;
        else
            D_030022E6 = 0;
        func_0804BEC0(D_030022E6, D_030022E7);
    }
    if (keys & 0x40)
    {
        func_080019EC(0x40);
        if (D_030022E7)
            D_030022E7--;
        else
            D_030022E7 = 4;
        func_0804BEC0(D_030022E6, D_030022E7);
    }
    if (keys & 0x80)
    {
        func_080019EC(0x40);
        if (D_030022E7 <= 3)
            D_030022E7++;
        else
            D_030022E7 = 0;
        func_0804BEC0(D_030022E6, D_030022E7);
    }
}
