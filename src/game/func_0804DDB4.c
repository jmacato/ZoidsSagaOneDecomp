#include "types.h"

struct Status
{
    u32 flags;
    u8 pad_4[4];
    s16 power;
    u8 pad_A[2];
    s32 range;
    s16 weight;
    u8 type;
    u8 element;
    u8 kind;
};

extern const u8 D_0875B124[];
extern const u8 D_0875AFB8[];
extern const u8 D_0875B2EC[];
extern const u8 D_08675C5C[];
extern const u8 D_0875B244[];
extern const u8 D_0875B25C[];

void func_0803E488(const u8 *, s32);
void func_08001848(s32, s32, s32);
u8 func_0804DD28(struct Status *, u32);
void func_0804D8AC(u32, s32, u32, u32, u32, u32);

void func_0804DDB4(struct Status *status_arg)
{
    register struct Status *status asm("r5") = status_arg;
    register u32 shown asm("r8");
    register u32 i asm("r6");
    register u32 flags asm("r4") = status->flags;
    register u32 one asm("r7") = 1;
    register const u8 *primary asm("r9");
    u32 value;

    asm("" : : "r"(status), "r"(flags));
    asm("" : "+r"(one));
    if (flags & one)
    {
        shown = 0;
        i = 0;
        {
            register const u8 *table asm("r1") = D_0875B124;
            asm("" : : "r"(table));
            primary = table;
        }
        func_0803E488(primary, 3);
        {
            register s32 range asm("r1") = status->range;
            register s32 whole asm("r0") = range;
            register u32 rounded asm("r1");

            asm("" : "+r"(whole) : "r"(range));
            if (range < 0)
            {
                register u32 bias asm("r2") = 0xFFFF;

                asm("" : : "r"(bias));
                whole = range + bias;
            }
            whole >>= 16;
            asm("" : : "r"(whole));
            rounded = (((u32)range >> 15) & one) + whole;
            asm("" : : "r"(rounded));
            if (rounded > 999)
                rounded = 999;
            func_08001848(rounded, 3, 0);
        }
        func_0803E488(primary, 4);
        value = status->power;
        if (value > 999)
            value = 999;
        func_08001848(value, 3, 0);
        func_0803E488(D_0875AFB8, 0x27);
        func_0803E488(D_0875AFB8, 0x2A);
    again:
        {
            if (func_0804DD28(status, i))
            {
                {
                    register u32 mask asm("r0") = 1;
                    register u32 count asm("r2") = shown;
                    asm("" : : "r"(mask), "r"(count));
                    mask &= count;
                    if (!mask)
                        func_0803E488(D_0875AFB8, 0x2A);
                }
                shown = (u8)(shown + 1);
            }
            {
                register u32 next asm("r0") = i + 1;
                asm("" : "+r"(next));
                i = (u8)next;
            }
            if (i > 3)
                goto finished;
            {
                register u32 count asm("r0") = shown;
                asm("" : : "r"(count));
                if (count <= 1)
                    goto again;
            }
        }
    finished:
        {
            register u32 count asm("r1") = shown;
            asm("" : : "r"(count));
            if (!count)
                func_0803E488(D_0875B2EC, 1);
        }
        func_0803E488(D_08675C5C, 0);
        func_0803E488(D_0875B124, 5);
        {
            register u32 reserved asm("r1");
            register u32 number asm("r0");
            asm("" : "=r"(reserved));
            number = status->weight;
            asm("" : : "r"(number), "r"(reserved));
            func_08001848(number, 3, 0);
        }
        func_0803E488(D_0875B124, 6);
        func_0803E488(D_0875B244, status->type);
        func_0803E488(D_0875B25C, status->element);
        if (i <= 3)
        {
            const u8 *blank = D_0875AFB8;
            register u32 parity asm("r4");
            register u32 mask asm("r4");
            register u32 count asm("r0");
            asm("" : "+l"(blank));
            mask = 1;
            count = shown;
            asm("" : : "r"(mask), "r"(count));
            parity = mask & count;
            asm("" : : "r"(parity));
            do
            {
                func_0803E488(blank, 0x2A);
                if (func_0804DD28(status, i) && !parity)
                    func_0803E488(blank, 0x2A);
                {
                    register u32 next asm("r0") = i + 1;
                    asm("" : "+r"(next));
                    i = (u8)next;
                }
            } while (i <= 3);
        }
    }
    else if (flags & 0xE)
        func_0804D8AC(flags, status->range, status->power, status->weight, status->kind, one);
}
