#include "engine/tasks.h"

struct SceneState
{
    TaskFunction first;
    TaskFunction second;
    u16 counter;
};

struct TriggerObject
{
    u8 unknown00[0x90];
    u32 x;
    u32 y;
    u8 unknown98[0x50];
    u16 active;
};

extern struct SceneState D_02000000;
extern struct TriggerObject D_03004BBC;
extern u16 D_02000B5C;

void func_08011E04(void);
void func_080232A4(void);
void func_08006DFC(s32);
u32 func_08000F88(u32);

void func_080214E0(void)
{
    struct TriggerObject *obj = &D_03004BBC;

    if (obj->x == 0x1800000 && obj->y > 0x27FFFFF && obj->y <= 0x2E00000)
    {
        register u16 *flag asm("r5") = &obj->active;
        register u32 bit asm("r4") = 1;
        register u16 one asm("r3") = 1;
        register struct SceneState *state asm("r2");

        asm("" : : "r"(flag), "r"(bit), "r"(one));
        state = &D_02000000;
        asm("" : : "r"(state));
        {
            register u32 counter asm("r0") = state->counter;
            register u32 mask asm("r1") = 2;

            asm("" : : "r"(counter), "r"(mask));
            state->counter = counter | mask;
        }
        *flag = one;
        state->first = func_08011E04;
        start_task(3, func_080232A4);
        func_08006DFC(0x15);
        func_08000F88(0x1BA);
        bit |= D_02000B5C;
        D_02000B5C = bit;
    }
}
