#include "types.h"

#pragma GCC optimize("no-toplevel-reorder", "align-functions=2", "no-reorder-blocks")

register u32 destination asm("r0");
register s32 count asm("r1");
register u32 source asm("r2");
register u32 value asm("r3");
register u32 saved_link asm("ip");

struct AudioJumpTablePool
{
    u32 start;
};

void func_0805B40C(void)
{
    asm volatile("mov %0, lr" : "=r"(saved_link));
    count = 36;
    asm("" : "+r"(count));
    asm("ldr %0, jump_table_pool" : "=r"(source));
copy:
    value = *(u32 *)source;
    asm volatile("bl func_0805B426" : "+r"(value) : "r"(source) : "memory", "cc");
    asm volatile("stmia %0!, {%1}" : "+r"(destination) : "r"(value) : "memory");
    source += 4;
    asm goto("sub %0, #1\n\tbgt %l[copy]" : "+r"(count) : : "cc" : copy);
    asm volatile("bx %0" : : "r"(saved_link));
    __builtin_unreachable();
}

static const u16 jump_table_padding __attribute__((used, section(".text"), aligned(2))) = 0;

/* This entry falls through into the guard while preserving the caller's lr. */
void func_0805B424(void)
{
    value = *(u8 *)source;
    asm volatile("" : : "r"(value));
    __builtin_unreachable();
}

void func_0805B426(void)
{
    /* Guarding a source must preserve the caller's destination register. */
    asm volatile("push {r0}" : : : "memory");
    destination = source >> 25;
    asm goto("bne %l[done]" : : "r"(destination) : : done);
    asm("ldr %0, jump_table_pool" : "=r"(destination));
    asm goto("cmp %0, %1\n\tbcc %l[clear]" : : "r"(source), "r"(destination) : "cc" : clear);
    destination = source >> 14;
    asm goto("beq %l[done]" : : "r"(destination) : : done);
clear:
    value = 0;
done:
    asm volatile("pop {r0}" : : : "memory");
}

static const struct AudioJumpTablePool jump_table_pool
    __attribute__((used, section(".text"), aligned(2))) = {0x08566080};

/* This entry loads the cursor, then falls through into the byte reader. */
void func_0805B440(void)
{
    source = *(u32 *)(count + 0x40);
    asm volatile("" : : "r"(source));
    __builtin_unreachable();
}

void func_0805B442(void)
{
    value = source + 1;
    asm("" : "+r"(value));
    *(u32 *)(count + 0x40) = value;
    value = *(u8 *)source;
    asm volatile("b func_0805B426" : : "r"(value) : "memory");
    __builtin_unreachable();
}
