#include "types.h"

register u32 completed asm("r0");
register u32 next_buffer asm("r1");
register u32 zero asm("r8");
register u32 enabled asm("r9");
register u32 *buffers asm("r10");
register u8 *link_state asm("r11");
register u8 *hardware asm("ip");

u32 exchange_vblank_updates(void)
{
    asm volatile("push {r8, r9, r10, r11}" : : : "memory");
    hardware = (u8 *)0x04000000;
    asm volatile("" : "+r"(hardware));
    asm volatile("ldr %0, link_state_address" : "=r"(link_state));
    buffers = (u32 *)(link_state + 0x28);
    asm volatile("" : "+r"(buffers));
    enabled = 1;
    asm volatile("" : "+r"(enabled));
    zero = 0;
    asm volatile("" : "+r"(zero));
    hardware[0x208] = zero;
    asm volatile("ldm %2, {%0, %1}" : "=r"(completed), "=r"(next_buffer) : "r"(buffers) : "memory");
    asm volatile("stm %0!, {%1}" : "+r"(buffers) : "r"(next_buffer) : "memory");
    asm volatile("stm %0!, {%1}" : "+r"(buffers) : "r"(completed) : "memory");
    completed = link_state[5];
    asm volatile("" : "+r"(completed));
    link_state[5] = zero;
    hardware[0x208] = enabled;
    asm volatile("pop {r8, r9, r10, r11}"
                 : "+r"(zero), "+r"(enabled), "+r"(buffers), "+r"(link_state)
                 :
                 : "memory");
    return completed;
}

const u32 link_state_address __attribute__((section(".text"), aligned(4))) = 0x030021A8;
