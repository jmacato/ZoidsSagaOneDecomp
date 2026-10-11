#include "engine/tasks.h"

extern struct
{
    TaskFunction first;
    TaskFunction second;
    u16 counter;
} D_02000000;

struct TriggerObject
{
    u8 unknown00[0x90];
    u32 x;
    vu32 y;
    u8 unknown98[0x50];
    u16 active;
};

extern struct TriggerObject D_03004BBC;

void func_08011E04(void);
void func_0801D328(void);

void func_0801B45C(void)
{
    register struct TriggerObject *source asm("r1") = &D_03004BBC;
    register struct TriggerObject *obj asm("r2");
    register u32 boundary asm("r4");
    u32 x;
    u32 y;

    asm("" : : "r"(source));
    x = source->x;
    boundary = 0x2800000;
    asm("" : : "r"(boundary));
    obj = source;
    asm("" : "+r"(obj));
    if (x > boundary)
        return;
    y = obj->y;
    if (y != 0x1400000)
    {
        if (x != boundary)
            return;
        asm("" : "+r"(obj));
        if (obj->y != 0x1800000)
            return;
    }
    {
        register u16 *flag asm("r4") = &obj->active;
        register u16 one asm("r3") = 1;

        asm("" : : "r"(flag), "r"(one));
        D_02000000.counter |= 2;
        *flag = one;
        D_02000000.first = func_08011E04;
        start_task(3, func_0801D328);
    }
}
