#include "types.h"

struct Sprite
{
    u8 pad_0[8];
    u32 x;
    u32 y;
    u8 pad_10[0x3C];
    u16 active;
    u8 pad_4E[2];
    u16 state;
    u8 pad_52[2];
    u16 goal;
    u8 pad_56[0x32];
};

extern struct Sprite D_03004BBC[];
extern u16 *D_0200DA78;
extern u32 D_0200E4F4;
extern u32 D_0200E510;
extern u32 D_0200E52C;
extern u32 D_0200E548;
extern s32 D_0200E564;
extern s32 D_0200E580;
extern u32 D_0200E59C;
extern u32 D_0200E5B8;
extern u32 D_0200E5D4;
extern u8 D_0200E4EC;

extern struct
{
    u8 pad_0[0xA];
    u16 done;
} D_02007574;

s32 func_08045784(u16, u8);
s32 func_080457BC(u16, u8);

void func_08049248(struct Sprite *spr_arg)
{
    register struct Sprite *spr asm("r5") = spr_arg;
    u32 x;
    register u16 *state asm("r3") = &spr->state;

    asm("" : : "r"(spr));
    asm("" : "+r"(state));
    switch (*state)
    {
    case 0:
    {
        register u16 *active asm("r1") = &spr->active;
        register volatile u16 *goal asm("r6");
        register u32 raw_target asm("r1");
        register u32 target asm("r4");
        asm("" : "+r"(active));
        *active = 1;
        goal = &spr->goal;
        asm("" : "+r"(goal));
        raw_target = *goal;
        asm("" : : "r"(raw_target));
        target = raw_target;
        asm("" : : "r"(target));
        if (target <= 2)
        {
            D_0200E4F4 = D_03004BBC[*goal + 20].x + 0x700000;
            D_0200E510 = D_03004BBC[*goal + 20].y;
            if (target == 1)
            {
                register u32 bias asm("r2") = -0x100000;
                asm("" : : "r"(bias));
                {
                    register u32 value asm("r0") = D_0200E510 + bias;
                    asm("" : : "r"(value));
                    D_0200E510 = value;
                }
            }
        }
        else
        {
            u32 result_x = func_08045784(*D_0200DA78, raw_target);
            asm("" : "+r"(result_x));
            {
                register u32 *destination asm("r1") = &D_0200E4F4;
                register u32 value asm("r0") = result_x << 16;
                register u32 bias asm("r3");
                asm("" : : "r"(destination), "r"(value));
                bias = 0x700000;
                asm("" : : "r"(bias));
                *destination = value + bias;
            }
            {
                u32 result_y = func_080457BC(*D_0200DA78, *(u8 *)goal);
                asm("" : "+r"(result_y));
                D_0200E510 = result_y << 16;
            }
        }
        D_0200E52C = spr->x;
        D_0200E548 = spr->y;
        if (D_0200E4F4 > D_0200E52C)
        {
            D_0200E59C = D_0200E4F4 - D_0200E52C;
            D_0200E564 = 0x10000;
        }
        else
        {
            D_0200E59C = D_0200E52C - D_0200E4F4;
            D_0200E564 = -0x10000;
        }
        if (D_0200E510 > D_0200E548)
        {
            D_0200E5B8 = D_0200E510 - D_0200E548;
            D_0200E580 = 0x10000;
        }
        else
        {
            D_0200E5B8 = D_0200E548 - D_0200E510;
            D_0200E580 = -0x10000;
        }
        {
            register u32 difference asm("r0");
            register u32 *error asm("r1");
            if (D_0200E59C > D_0200E5B8)
            {
                D_0200E4EC = 0;
                error = &D_0200E5D4;
                asm("" : "+r"(error));
                difference = D_0200E59C - D_0200E5B8;
            }
            else
            {
                D_0200E4EC = 1;
                error = &D_0200E5D4;
                asm("" : "+r"(error));
                difference = D_0200E5B8 - D_0200E59C;
            }
            *error = difference;
        }
        goto advance;
    }
    case 1:
    {
        register u32 i asm("r6") = 0;
        register const u32 *delta_y asm("r10");
        register const s32 *step_y asm("r9");
        register const u32 *delta_x asm("r8");
        register const s32 *step_x asm("r12");
        asm("" : : "r"(i));
        x = D_0200E4F4;
        asm("" : : "m"(x));
        {
            const u32 *base = &D_0200E5B8;
            asm("" : "+l"(base) : : "r0", "r1", "r2", "r3", "r4");
            delta_y = base;
        }
        step_y = &D_0200E580;
        delta_x = &D_0200E59C;
        {
            register const s32 *base asm("r2") = &D_0200E564;
            asm("" : : "r"(base));
            step_x = base;
        }
        asm("" : : "r"(delta_y), "r"(step_y), "r"(delta_x), "r"(step_x));
    iterate:
        {
            register u32 current_x asm("r4") = spr->x;
            register u32 target_x asm("r3") = x;
            asm("" : : "r"(current_x), "r"(target_x));
            if (current_x == target_x && spr->y == D_0200E510)
                goto advance;
            switch (D_0200E4EC)
            {
            case 0:
            {
                register u32 *error asm("r3") = &D_0200E5D4;
                register u32 old asm("r1") = *error;
                const u32 *delta = delta_y;
                register u32 amount asm("r0");
                register u32 next_error asm("r2");
                asm("" : "+l"(delta) : "r"(old), "r"(error), "r"(current_x) : "r0", "r2");
                amount = *delta;
                asm("" : : "r"(amount));
                next_error = old - amount;
                *error = next_error;
                if (next_error > 0xFF0000)
                {
                    register u32 value asm("r0") = spr->y;
                    const s32 *step = step_y;
                    register s32 step_amount asm("r1");
                    asm("" : "+l"(step) : "r"(value), "r"(error), "r"(next_error), "r"(current_x) : "r1");
                    step_amount = *step;
                    value += step_amount;
                    spr->y = value;
                    {
                        register const u32 *delta asm("r1") = delta_x;
                        register u32 amount asm("r0");
                        asm("" : : "r"(delta));
                        amount = *delta;
                        *error = next_error + amount;
                    }
                }
                {
                    register const s32 *step asm("r2") = step_x;
                    register u32 value asm("r0");
                    asm("" : : "r"(step));
                    value = *step;
                    value = current_x + value;
                    asm("" : : "r"(value));
                    spr->x = value;
                }
                break;
            }
            case 1:
            {
                register u32 *error asm("r2") = &D_0200E5D4;
                register u32 old asm("r1") = *error;
                register const u32 *delta asm("r3") = delta_x;
                register u32 amount asm("r0");
                register u32 threshold asm("r7");
                asm("" : : "r"(old), "r"(delta), "r"(error));
                amount = *delta;
                old -= amount;
                *error = old;
                threshold = 0xFF0000;
                asm("" : : "r"(threshold));
                if (old > threshold)
                {
                    register const s32 *step asm("r3") = step_x;
                    register u32 value asm("r0");
                    asm("" : : "r"(step));
                    value = *step;
                    value = current_x + value;
                    spr->x = value;
                    {
                        const u32 *delta = delta_y;
                        register u32 amount asm("r0");
                        asm("" : "+l"(delta) : "r"(old), "r"(error) : "r0", "r3", "r4");
                        amount = *delta;
                        *error = old + amount;
                    }
                }
                {
                    register u32 value asm("r0") = spr->y;
                    register const s32 *step asm("r2") = step_y;
                    register s32 amount asm("r1");
                    asm("" : : "r"(value), "r"(step));
                    amount = *step;
                    spr->y = value + amount;
                }
                break;
            }
            }
        }
        {
            register u32 next asm("r0") = i + 1;
            asm("" : "+r"(next));
            i = (u8)next;
        }
        if (i <= 2)
            goto iterate;
        break;
    }
    advance:
    {
        register u16 *field asm("r1") = &spr->state;
        asm("" : "+r"(field));
        (*field)++;
        break;
    }
    case 2:
        D_02007574.done = 1;
        {
            register u16 *field asm("r0") = &spr->active;
            asm("" : "+r"(field));
            *field = 0;
        }
        (*state)++;
        break;
    }
}
