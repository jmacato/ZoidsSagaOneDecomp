#include "types.h"

#pragma GCC optimize("no-toplevel-reorder")

struct SoundDmaState
{
    u32 magic;
    u8 remaining;
    u8 pad_05[6];
    u8 period;
};

struct SoundDmaPool
{
    volatile u8 *dma;
    u32 reload;
};

__attribute__((optimize("no-reorder-blocks"))) void func_0805B5D0(void)
{
    register struct SoundDmaState **slot asm("r0");
    register struct SoundDmaState *sound asm("r0");
    register u32 magic asm("r2");
    register u32 difference asm("r3");
    /* These loads share the sound main routine's original literal pool. */
    asm("ldr %0, [pc, #0x298]" : "=r"(slot));
    sound = *slot;
    asm("" : "+r"(sound));
    asm volatile("ldr %0, [pc, #0x298]" : "=r"(magic) : "r"(sound) : "memory");
    difference = sound->magic;
    asm("" : "+r"(difference));
    difference -= magic;
    asm("" : "+r"(difference));
    if (difference > 1)
        goto done;
    {
        register s32 remaining asm("r1") = sound->remaining;
        /* The native branch uses subtraction flags after the byte store. */
        asm("sub %0, #1" : "+r"(remaining) : : "cc");
        sound->remaining = remaining;
        asm goto("bgt %l[done]" : : "r"(remaining) : : done);
        remaining = sound->period;
        asm("" : "+r"(remaining));
        sound->remaining = remaining;
        register volatile u8 *dma asm("r2");
        register u32 flags asm("r1");
        asm("ldr %0, sound_dma_pool" : "=r"(dma));
        flags = *(volatile u32 *)(dma + 8);
        asm goto("lsl %0, %0, #7\n\tbcc %l[reset]" : "+r"(flags) : : "cc" : reset);
        asm("ldr %0, sound_dma_pool + 4" : "=r"(flags));
        *(volatile u32 *)(dma + 8) = flags;
    reset:
    {
        register u16 control asm("r1") = 4;
        asm("lsl %0, %0, #8" : "+r"(control) : : "cc");
        asm volatile("strh %0, [%1, #10]" : : "r"(control), "r"(dma) : "memory");
        asm("" : : : "memory");
        control = 0xB6;
        asm("lsl %0, %0, #8" : "+r"(control) : : "cc");
        asm volatile("strh %0, [%1, #10]" : : "r"(control), "r"(dma) : "memory");
    }
    }
done:
    return;
}

static const struct SoundDmaPool sound_dma_pool
    __attribute__((used, section(".text"), aligned(2))) = {(volatile u8 *)0x040000BC, 0x84400004};
