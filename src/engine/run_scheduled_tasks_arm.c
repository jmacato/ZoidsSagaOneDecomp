#include "types.h"

// Task switches preserve the original banked CPU state and shared stack frame.
#pragma GCC optimize("no-reorder-blocks", "no-ipa-pure-const", "no-crossjumping",                  \
                     "no-tree-tail-merge")
register u32 value asm("r0");
register u32 sentinel asm("r1");
register u32 *context asm("r2");
register u32 *current asm("r3");
register u32 delay asm("r4");
register u8 *active_task asm("r5");
register u32 saved6 asm("r6");
register u32 saved7 asm("r7");
register u32 saved8 asm("r8");
register u32 saved9 asm("r9");
register u32 saved10 asm("r10");
register u32 saved11 asm("r11");
register u32 saved12 asm("r12");
register u32 *task_stack asm("sp");

void run_scheduled_tasks_arm(void)
{
    asm volatile("push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10}" : : : "memory");
    asm volatile("ldr %0, scheduler_literals" : "=r"(current));
    asm volatile("ldr %0, scheduler_literals+4" : "=r"(context));
    *current = (u32)context;
    asm volatile("ldr %0, scheduler_literals+8" : "=r"(current));
    asm volatile("str lr, [%0]" : : "r"(current) : "memory");
    asm volatile("ldr %0, scheduler_literals+12" : "=r"(current));
    *current = (u32)task_stack;
    asm volatile("" : : : "memory");
    value = 1;
    asm volatile("" : "+r"(value));
    asm volatile(".global yield_task_arm\nyield_task_arm:");
    asm volatile("push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, lr, pc}\n\t"
                 "mrs %0, spsr\n\tstmdb sp!, {%0}"
                 : "=r"(value)
                 :
                 : "memory");
    asm volatile("ldr %0, scheduler_literals+16" : "=r"(current));
    asm volatile("ldr %0, scheduler_literals+20" : "=r"(active_task));
    context = (u32 *)*current;
    asm volatile("" : "+r"(context));
    asm volatile("ldr %0, scheduler_literals+24" : "=r"(sentinel));
    value = context[2];
    asm goto("cmp %0, %1\n\tbeq %l[no_context]" : : "r"(value), "r"(sentinel) : "cc" : no_context);
    asm volatile("mov %0, lr" : "=r"(value));
    context[2] = value;
#pragma GCC unroll 16
    for (u32 offset = 3; offset < 19; offset++)
    {
        asm volatile("ldm sp!, {%0}" : "=r"(value) : : "memory");
        context[offset] = value;
        if (offset == 4)
            *((u8 *)context + 1) = value;
    }
    context[1] = (u32)task_stack;
    goto next;
no_context:
    asm volatile("add sp, sp, #64" : : : "memory");
next:
    context = (u32 *)((u8 *)context + 76);
    asm volatile("" : "+r"(context));
    *current = (u32)context;
    value = *(u8 *)context;
    asm volatile("" : "+r"(value));
    asm goto("cmp %0, #12\n\tbeq %l[finish]" : : "r"(value) : "cc" : finish);
    asm volatile("ldr lr, [%0, #8]" : : "r"(context) : "memory");
    asm goto("cmp lr, %0\n\tbeq %l[next]" : : "r"(sentinel) : "cc" : next);
    delay = *((u8 *)context + 1);
    asm volatile("" : "+r"(delay));
    asm goto("subs %0, %0, #1\n\tstrneb %0, [%1, #1]\n\tbne %l[next]"
             : "+r"(delay)
             : "r"(context)
             : "cc", "memory"
             : next);
    value--;
    asm volatile("" : "+r"(value));
    *active_task = value;
    value = context[3];
    asm volatile("msr spsr_fc, %0" : : "r"(value));
    value = context[4];
    asm volatile("" : "+r"(value) : : "memory");
    sentinel = context[6];
    asm volatile("" : "+r"(sentinel) : : "memory");
    current = (u32 *)context[7];
    asm volatile("" : "+r"(current) : : "memory");
    delay = context[8];
    asm volatile("" : "+r"(delay) : : "memory");
    active_task = (u8 *)context[9];
    asm volatile("" : "+r"(active_task) : : "memory");
    saved6 = context[10];
    asm volatile("" : "+r"(saved6) : : "memory");
    saved7 = context[11];
    asm volatile("" : "+r"(saved7) : : "memory");
    saved8 = context[12];
    asm volatile("" : "+r"(saved8) : : "memory");
    saved9 = context[13];
    asm volatile("" : "+r"(saved9) : : "memory");
    saved10 = context[14];
    asm volatile("" : "+r"(saved10) : : "memory");
    saved11 = context[15];
    asm volatile("" : "+r"(saved11) : : "memory");
    saved12 = context[16];
    asm volatile("" : "+r"(saved12) : : "memory");
    task_stack = (u32 *)context[1];
    asm volatile("" : : : "memory");
    context = (u32 *)context[5];
    asm volatile("" : "+r"(context) : : "memory");
    asm volatile("bx lr" : : : "memory");
    __builtin_unreachable();
finish:
    asm volatile("ldr %0, scheduler_literals+28" : "=r"(current));
    task_stack = (u32 *)*current;
    asm volatile("ldr %0, scheduler_literals+32" : "=r"(current));
    asm volatile("ldr lr, [%0]" : : "r"(current) : "memory");
    asm volatile("pop {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10}\n\tbx lr" : : : "memory");
    __builtin_unreachable();
}

const u32 scheduler_literals[9] __attribute__((section(".text"), aligned(4))) = {
    0x030005C8, 0x03000208, 0x03001ECC, 0x03001ED0, 0x030005C8,
    0x02000030, 0xFFFFFFFF, 0x03001ED0, 0x03001ECC};
