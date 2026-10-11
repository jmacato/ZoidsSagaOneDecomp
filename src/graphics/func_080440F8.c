#include "types.h"

struct Transfer
{
    void *source;
    void *destination;
    u16 size;
};
struct RenderState
{
    u32 pad_0[2];
    u32 horizontal;
    u32 pad_C;
    u32 vertical;
};
extern u8 D_0200DAA0, D_0200E236;
extern u8 D_0200DA70, D_0200DA98, D_0200DA96;
extern u8 D_0200E22C, D_0200E234, D_0200E235, D_0200E238;
extern u32 D_0200DFAC[], D_0200DD2C[], D_0200DAAC[];
extern u32 D_0200DAA4, D_0200E284, D_0200E288;
extern struct RenderState D_03004B9C;
extern const u16 D_086D3FC4[], D_086D3FE4[], D_086D4044[];
extern const u16 D_086D4074[], D_086D4064[];
u16 func_08042FA4(u8);
void func_08047EF4(u32, u32, u32, u32);
void func_08001A54(void *, u16, s32);

#define NEXT_ROW() \
    { register u32 next asm("r0") = index + 1; index = (u8)next; }
#define ADD_ROWS(first, last, amount) \
    { \
        register u32 *rows asm("r3"); \
        register u32 increment asm("r2"); \
        index = (first); \
        rows = D_0200DFAC; \
        increment = (amount); \
        do { \
            register u32 address asm("r0") = index * 4 + (u32)rows; \
            register u32 value asm("r1") = *(u32 *)address; \
            value += increment; \
            *(u32 *)address = value; \
            NEXT_ROW(); \
        } while (index <= (last)); \
    }
#define ADD_GRADIENT(first, initial, step, base) \
    { \
        register u32 total asm("r2"); \
        register u32 increment asm("r6"); \
        register u32 *rows asm("r5"); \
        register u32 initial_value asm("r3"); \
        total = (initial); \
        index = (first); \
        increment = (step); \
        rows = D_0200DFAC; \
        initial_value = (base); \
        do { \
            register u32 address asm("r0"); \
            register u32 value asm("r1"); \
            total += increment; \
            address = index * 4 + (u32)rows; \
            value = *(u32 *)address; \
            value += initial_value; \
            value += total; \
            *(u32 *)address = value; \
            NEXT_ROW(); \
        } while ((s8)index >= 0); \
    }
#define ADD_RAMP(first, initial, step) \
    { \
        register u32 total asm("r2"); \
        register u32 increment asm("r5"); \
        register u32 *rows asm("r3"); \
        total = (initial); \
        index = (first); \
        increment = (step); \
        rows = D_0200DFAC; \
        do { \
            register u32 address asm("r0"); \
            register u32 value asm("r1"); \
            total += increment; \
            address = index * 4 + (u32)rows; \
            value = *(u32 *)address; \
            value += total; \
            *(u32 *)address = value; \
            NEXT_ROW(); \
        } while ((s8)index >= 0); \
    }
#define ADD_BOUNDED_RAMP(first, last, initial, step) \
    { \
        register u32 total asm("r2"); \
        register u32 increment asm("r5"); \
        register u32 *rows asm("r3"); \
        total = (initial); \
        index = (first); \
        increment = (step); \
        rows = D_0200DFAC; \
        do { \
            register u32 address asm("r0"); \
            register u32 value asm("r1"); \
            total += increment; \
            address = index * 4 + (u32)rows; \
            value = *(u32 *)address; \
            value += total; \
            *(u32 *)address = value; \
            NEXT_ROW(); \
        } while (index <= (last)); \
    }
#define WAVE_ROWS(first, last, shift) \
    { \
        register u32 *rows asm("r5"); \
        index = (first); \
        rows = D_0200DFAC; \
        do { \
            register u32 value asm("r0") = func_08042FA4((u8)(((index - 32) << 5) + D_0200E236)); \
            register u32 address asm("r1") = index * 4 + (u32)rows; \
            value = (value << 16) >> (shift); \
            *(u32 *)address = value; \
            NEXT_ROW(); \
        } while (index <= (last)); \
    }

void func_080440F8(void)
{
    struct Transfer transfer;
    register u32 index asm("r4");

    switch (D_0200DAA0)
    {
    case 3:
        ADD_ROWS(56, 63, 0x2000);
        ADD_GRADIENT(64, 0x2000, 0x300, 0x6000);
        break;
    case 4:
        ADD_ROWS(72, 79, 0x3000);
        ADD_GRADIENT(80, 0x2000, 0x400, 0x3000);
        break;
    case 5:
        ADD_ROWS(85, 95, 0x1000);
        ADD_GRADIENT(96, 0x2000, 0x300, 0x1000);
        break;
    case 6:
        ADD_ROWS(54, 104, 0x6000);
        ADD_GRADIENT(105, 0x2000, 0x800, 0x6000);
        break;
    case 7:
        ADD_ROWS(72, 112, 0x3000);
        ADD_GRADIENT(113, 0x2000, 0x800, 0x3000);
        break;
    case 8:
        ADD_ROWS(85, 91, 0x1000);
        ADD_ROWS(92, 113, 0x2000);
        ADD_GRADIENT(114, 0x4000, 0x400, 0x1000);
        break;
    case 9: case 10: case 11:
        D_0200E236 += 2;
        {
            register u32 *rows asm("r5");
            index = 0;
            rows = D_0200DFAC;
            do
            {
                register u32 value asm("r0") = func_08042FA4((u8)(index + D_0200E236));
                register u32 address asm("r1") = index * 4 + (u32)rows;
                value = ((value << 16) >> 20) << 16;
                *(u32 *)address = value;
                NEXT_ROW();
            } while ((s8)index >= 0);
        }
        break;
    case 12:
        ADD_ROWS(46, 95, 0x6000);
        ADD_GRADIENT(96, 0x2000, 0x800, 0x6000);
        break;
    case 13:
        ADD_ROWS(71, 103, 0x3000);
        ADD_GRADIENT(104, 0x2000, 0x800, 0x3000);
        break;
    case 14:
        ADD_ROWS(85, 95, 0x1000);
        ADD_ROWS(96, 114, 0x3000);
        ADD_GRADIENT(115, 0x4000, 0x800, 0x1000);
        break;
    case 15:
        D_0200E236 += 2;
        WAVE_ROWS(32, 79, 6);
        ADD_ROWS(64, 79, 0x3000);
        ADD_GRADIENT(80, 0x4000, 0x800, 0x6000);
        break;
    case 16: case 17:
        D_0200E236 += 2;
        WAVE_ROWS(32, 79, 6);
        ADD_ROWS(71, 111, 0x3000);
        ADD_GRADIENT(112, 0x3000, 0x800, 0x3000);
        break;
    case 18:
        ADD_ROWS(79, 95, 0x6000);
        ADD_GRADIENT(96, 0x2000, 0x800, 0x6000);
        break;
    case 19:
        ADD_ROWS(96, 103, 0x3000);
        ADD_GRADIENT(104, 0x2000, 0x800, 0x3000);
        break;
    case 20:
        ADD_ROWS(103, 110, 0x1000);
        ADD_GRADIENT(111, 0x4000, 0x800, 0x3000);
        break;
    case 30: case 31: case 32:
        ADD_ROWS(0, 23, 0x3000);
        ADD_BOUNDED_RAMP(59, 74, 0, 0x200);
        ADD_ROWS(75, 91, 0x2000);
        ADD_GRADIENT(92, 0, 0x400, 0x2000);
        break;
    case 33: case 34: case 35:
        D_0200E236 += 4;
        WAVE_ROWS(24, 74, 7);
        ADD_ROWS(0, 23, 0x3000);
        ADD_BOUNDED_RAMP(59, 74, 0, 0x200);
        ADD_ROWS(75, 91, 0x2000);
        ADD_GRADIENT(92, 0, 0x400, 0x2000);
        break;
    case 36: case 37: case 38:
        ADD_ROWS(72, 81, 0x1000);
        ADD_RAMP(82, 0x1000, 0x300);
        break;
    case 39: case 40: case 41:
        ADD_RAMP(86, 0x1000, 0x300);
        break;
    case 42: case 43: case 44:
        ADD_ROWS(52, 89, 0x2000);
        ADD_RAMP(90, 0x3000, 0x400);
        break;
    case 45: case 46: case 47:
        {
            register u32 *rows asm("r3");
            register u32 increment asm("r2");
            increment = 0x2000;
            index = 0;
            rows = D_0200DFAC;
            do {
                register u32 address asm("r0") = index * 4 + (u32)rows;
                register u32 value asm("r1") = *(u32 *)address;
                value += increment;
                *(u32 *)address = value;
                NEXT_ROW();
            } while ((s8)index >= 0);
        }
        break;
    case 48: case 49: case 50:
        ADD_ROWS(0, 8, 0x4000);
        ADD_ROWS(9, 22, 0x3000);
        ADD_ROWS(23, 32, 0x2000);
        ADD_ROWS(33, 39, 0x1000);
        ADD_ROWS(61, 84, 0x2000);
        ADD_RAMP(85, 0x2000, 0x400);
        break;
    case 51: case 52: case 53:
        ADD_ROWS(110, 120, 0x1000);
        ADD_ROWS(121, 143, 0x10000);
        break;
    }

    if (D_0200DA70)
    {
        if (D_0200DA98)
        {
            u32 counter = D_0200DA98 + 1;
            D_0200DA98 = counter;
            if ((u8)counter <= 15)
                func_08047EF4(31, 15, 1, (u8)(31 - counter));
            else
            {
                func_08047EF4(31, 15, 1, 16);
                if (D_0200DA98 > 16)
                    D_0200DA98 = 0;
            }
        }
    }
    else
    {
        D_0200E22C = 0;
        D_0200E234 = 0;
        D_0200E235 = 0;
    }
    if (D_0200E22C)
    {
        switch (D_0200E235)
        {
        case 1:
            D_0200DAA4 = (u32)D_086D3FC4[D_0200E234++] << 16;
            if (D_0200E234 > 15)
            {
                D_0200E22C = 0;
                {
                    register u32 zero asm("r0") = 0;
                    register u32 *address asm("r1");
                    asm("" : : "r"(zero));
                    address = &D_0200DAA4;
                    asm("" : : "r"(address));
                    *address = zero;
                }
            }
            if (D_0200DA96 && !D_0200DA98)
                D_0200DA98 = 1;
            break;
        case 4:
            D_0200DAA4 = (u32)D_086D3FE4[D_0200E234++] << 16;
            if (D_0200E234 > 47)
            {
                D_0200E22C = 0;
                {
                    register u32 zero asm("r0") = 0;
                    register u32 *address asm("r2");
                    asm("" : : "r"(zero));
                    address = &D_0200DAA4;
                    asm("" : : "r"(address));
                    *address = zero;
                }
            }
            break;
        case 2:
            D_0200DAA4 += (u32)D_086D4044[D_0200E234++] << 16;
            if (D_0200E234 > 15)
                D_0200E22C = 0;
            break;
        case 3:
            D_0200DAA4 += (u32)D_086D4074[D_0200E234++] << 16;
            if (D_0200E234 > 151)
                D_0200E22C = 0;
            break;
        case 5:
            D_0200DAA4 += (u32)D_086D4064[D_0200E234++] << 16;
            if (D_0200E234 > 7)
                D_0200E22C = 0;
            break;
        }
    }
    switch (D_0200E238)
    {
    case 0:
    {
        register struct RenderState *state asm("r9");
        register u32 *scroll asm("r8");
        register u32 *center asm("r10");
        register u32 *output asm("r12");
        u32 state_copy;
        register u32 *scroll_copy asm("r6");
        register u32 *rows asm("r5");
        index = 0;
        {
            register struct RenderState *literal asm("r0") = &D_03004B9C;
            asm("" : : "r"(literal));
            state = literal;
            asm("" : : "r"(state));
        }
        {
            register u32 *literal asm("r1") = &D_0200E284;
            asm("" : : "r"(literal));
            scroll = literal;
            asm("" : : "r"(scroll));
        }
        {
            register u32 *literal asm("r2") = &D_0200E288;
            asm("" : : "r"(literal));
            center = literal;
            asm("" : : "r"(center));
        }
        {
            register u32 *literal asm("r0") = D_0200DD2C;
            asm("" : : "r"(literal));
            output = literal;
            asm("" : : "r"(output));
        }
        state_copy = (u32)state;
        scroll_copy = scroll;
        asm("" : : "r"(state_copy), "r"(scroll_copy));
        rows = D_0200DFAC;
        do
        {
            register u32 offset asm("r2") = index * 4;
            register u32 destination_base asm("r1") = (u32)output;
            register u32 destination asm("r3");
            register u32 value asm("r1");
            register u32 delta asm("r0");
            asm("" : : "r"(destination_base));
            destination = offset + destination_base;
            value = *(u32 *)(state_copy + 16);
            delta = *scroll_copy;
            value -= delta;
            offset += (u32)rows;
            delta = *(u32 *)offset;
            value -= delta;
            *(u32 *)destination = value;
            NEXT_ROW();
        } while (index <= 143);
        {
            register u32 *address asm("r2") = scroll;
            register u32 value asm("r0") = *address;
            register u32 constant asm("r1") = 0x700000;
            register u32 center_value asm("r1");
            value += constant;
            address = center;
            center_value = *address;
            center_value -= value;
            address = &D_0200DAA4;
            value = *address;
            center_value += value;
            {
                register struct RenderState *address asm("r0") = state;
                address->horizontal = center_value;
            }
        }
    }
        break;
    case 32:
    {
        register struct RenderState *state asm("r9");
        register u32 *scroll asm("r8");
        register u32 *center asm("r10");
        register u32 *output asm("r12");
        u32 state_copy;
        register u32 *scroll_copy asm("r6");
        register u32 *rows asm("r5");
        index = 0;
        {
            register struct RenderState *literal asm("r1") = &D_03004B9C;
            asm("" : : "r"(literal));
            state = literal;
            asm("" : : "r"(state));
        }
        {
            register u32 *literal asm("r2") = &D_0200E284;
            asm("" : : "r"(literal));
            scroll = literal;
            asm("" : : "r"(scroll));
        }
        {
            register u32 *literal asm("r0") = &D_0200E288;
            asm("" : : "r"(literal));
            center = literal;
            asm("" : : "r"(center));
        }
        {
            register u32 *literal asm("r1") = D_0200DD2C;
            asm("" : : "r"(literal));
            output = literal;
            asm("" : : "r"(output));
        }
        state_copy = (u32)state;
        scroll_copy = scroll;
        asm("" : : "r"(state_copy), "r"(scroll_copy));
        rows = D_0200DFAC;
        do
        {
            register u32 offset asm("r2") = index * 4;
            register u32 destination_base asm("r0") = (u32)output;
            register u32 destination asm("r3");
            register u32 value asm("r1");
            register u32 delta asm("r0");
            asm("" : : "r"(destination_base));
            destination = offset + destination_base;
            value = *(u32 *)(state_copy + 16);
            delta = *scroll_copy;
            value += delta;
            offset += (u32)rows;
            delta = *(u32 *)offset;
            value += delta;
            *(u32 *)destination = value;
            NEXT_ROW();
        } while (index <= 143);
        {
            register u32 *address asm("r1") = scroll;
            register u32 value asm("r0") = *address;
            register u32 *center_address asm("r2") = center;
            register u32 center_value asm("r1") = *center_address;
            value -= center_value;
            center_address = &D_0200DAA4;
            center_value = *center_address;
            value -= center_value;
            {
                register struct RenderState *address asm("r1") = state;
                address->horizontal = value;
            }
        }
    }
        break;
    }
    index = 144;
    do { D_0200DD2C[index] = D_03004B9C.vertical; NEXT_ROW(); } while (index <= 159);
    {
        register u32 *source asm("r2") = D_0200DD2C;
        asm("" : : "r"(source));
        transfer.source = source;
    }
    {
        register u32 *destination asm("r0") = D_0200DAAC;
        asm("" : : "r"(destination));
        transfer.destination = destination;
    }
    transfer.size = 640;
    func_08001A54(&transfer, 0, 0);
}
