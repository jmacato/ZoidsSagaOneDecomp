#include "types.h"

extern u32 D_030022FC;
extern u16 D_0300235A;
extern const u8 D_0875B330[];
extern const u8 D_0875AFB8[];

void func_0803E488(const u8 *, s32);
void print_signed_number(s32, s32, s32);
void func_080019EC(s32);
void func_0805EE78(s32);

u8 func_0805354C(u32 min, u32 max, s32 width)
{
    u8 result;

    func_0803E488(D_0875B330, 8);
    D_030022FC = min;
    result = 0;
    do
    {
        func_0803E488(D_0875AFB8, 7);
        func_0803E488(D_0875AFB8, 0x2A);
        print_signed_number(D_030022FC, width, 0);
        func_0803E488(D_0875AFB8, 0x17);
    poll:
        if (D_0300235A & 0x200)
        {
            func_080019EC(0x40);
            if (D_030022FC > 10)
                D_030022FC -= 10;
            else if (D_030022FC == min)
                D_030022FC = max;
            else
                D_030022FC = min;
            goto next;
        }
        if (D_0300235A & 0x100)
        {
            func_080019EC(0x40);
            if ((s32)D_030022FC <= (s32)(max - 10))
                D_030022FC += 10;
            else if (D_030022FC == max)
                D_030022FC = min;
            else
                D_030022FC = max;
            goto next;
        }
        if (D_0300235A & 0x20)
        {
            func_080019EC(0x40);
            if (D_030022FC > min)
                D_030022FC--;
            else
                D_030022FC = max;
            goto next;
        }
        if (D_0300235A & 0x10)
        {
            func_080019EC(0x40);
            if (D_030022FC < max)
                D_030022FC++;
            else
                D_030022FC = min;
            goto next;
        }
        if (D_0300235A & 1)
        {
            func_080019EC(0x47);
            result = 2;
            goto done;
        }
        if (D_0300235A & 2)
        {
            func_080019EC(0x3F);
            result = 1;
            goto done;
        }
        func_0805EE78(1);
        goto poll;
    next:;
    } while (result == 0);
done:
    func_0803E488(D_0875AFB8, 0xF);
    return result - 1;
}
