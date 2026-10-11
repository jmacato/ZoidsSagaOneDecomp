#include "types.h"

#pragma GCC optimize("no-reorder-blocks")
register u32 irq_value asm("r0");
register u32 irq_enabled asm("r1");
register u32 irq_control asm("r2");
register u32 irq_address asm("r3");
register u32 irq_slot asm("ip");

void startup_and_irq(void)
{
    irq_value = 0x12;
    asm volatile("msr cpsr_fc, %0\n\tldr sp, startup_irq_stack" : : "r"(irq_value) : "memory");
    irq_value = 0x1F;
    asm volatile("msr cpsr_fc, %0\n\tldr sp, startup_system_stack" : : "r"(irq_value) : "memory");
    asm volatile("ldr %0, startup_irq_vector" : "=r"(irq_enabled));
    asm volatile("adr %0, irq_dispatch" : "=r"(irq_value));
    *(u32 *)irq_enabled = irq_value;
    asm volatile("ldr %0, startup_main" : "=r"(irq_enabled) : : "memory");
    asm volatile("mov lr, pc\n\tbx r1\n\tb startup_and_irq" : : "r"(irq_enabled) : "memory");
    __builtin_unreachable();
}

const u32 startup_system_stack __attribute__((section(".text"), aligned(4))) = 0x03007AA0;
const u32 startup_irq_stack __attribute__((section(".text"), aligned(4))) = 0x03007FA0;

// Flag-setting branches preserve the original interrupt priority and CPU condition codes.
#define SELECT_IRQ(mask)                                                                           \
    asm goto("ands %0, %1, #" #mask "\n\tbne %l[dispatch]"                                         \
             : "=r"(irq_value)                                                                     \
             : "r"(irq_enabled)                                                                    \
             : "cc"                                                                                \
             : dispatch);                                                                          \
    irq_slot += 4;                                                                                 \
    asm volatile("" : "+r"(irq_slot))

void irq_dispatch(void)
{
    irq_address = 0x04000000;
    asm volatile("" : "+r"(irq_address));
    irq_address += 0x200;
    asm volatile("" : "+r"(irq_address));
    irq_control = *(u32 *)irq_address;
    asm volatile("" : "+r"(irq_control));
    irq_enabled = *(u16 *)(irq_address + 8);
    asm volatile("" : "+r"(irq_enabled));
    asm volatile("mrs %0, spsr\n\tpush {r0, r1, r2, r3, lr}"
                 : "=r"(irq_value)
                 : "r"(irq_enabled), "r"(irq_control), "r"(irq_address)
                 : "memory");
    irq_value = 1;
    asm volatile("" : "+r"(irq_value));
    *(u16 *)(irq_address + 8) = irq_value;
    irq_enabled = irq_control & (irq_control >> 16);
    asm volatile("" : "+r"(irq_enabled));
    irq_slot = 0;
    asm volatile("" : "+r"(irq_slot));
    asm volatile("ands %0, %1, #0x2000\n\tstrneb %0, [%2, #-0x17c]"
                 : "=r"(irq_value)
                 : "r"(irq_enabled), "r"(irq_address)
                 : "cc", "memory");
panic:
    asm goto("bne %l[panic]" : : : : panic);
    SELECT_IRQ(0xc0);
    SELECT_IRQ(1);
    SELECT_IRQ(4);
    SELECT_IRQ(2);
    SELECT_IRQ(8);
    SELECT_IRQ(0x10);
    SELECT_IRQ(0x20);
    SELECT_IRQ(0x40);
    SELECT_IRQ(0x100);
    SELECT_IRQ(0x200);
    SELECT_IRQ(0x400);
    SELECT_IRQ(0x800);
    SELECT_IRQ(0x1000);
dispatch:
    *(u16 *)(irq_address + 2) = irq_value;
    asm volatile("ldr %0, startup_irq_mask" : "=r"(irq_enabled) : : "memory");
    irq_control &= ~irq_value;
    asm volatile("" : "+r"(irq_control));
    irq_enabled &= irq_control;
    asm volatile("" : "+r"(irq_enabled));
    *(u16 *)irq_address = irq_enabled;
    asm volatile("mrs %0, cpsr" : "=r"(irq_address) : : "memory");
    irq_address &= ~0xDF;
    asm volatile("" : "+r"(irq_address));
    irq_address |= 0x1F;
    asm volatile("msr cpsr_fc, %0" : : "r"(irq_address) : "memory");
    asm volatile("ldr %0, startup_irq_table" : "=r"(irq_enabled));
    irq_enabled += irq_slot;
    asm volatile("" : "+r"(irq_enabled));
    irq_value = *(u32 *)irq_enabled;
    asm volatile("stmdb sp!, {lr}\n\tadd lr, pc, #0\n\tbx r0\n\tldm sp!, {lr}\n\tmrs r3, cpsr"
                 : "+r"(irq_value), "+r"(irq_enabled), "+r"(irq_control), "=r"(irq_address)
                 :
                 : "memory", "cc");
    irq_address &= ~0xDF;
    asm volatile("" : "+r"(irq_address));
    irq_address |= 0x92;
    asm volatile("msr cpsr_fc, %3\n\tpop {r0, r1, r2, r3, lr}"
                 : "=r"(irq_value), "=r"(irq_enabled), "=r"(irq_control), "+r"(irq_address)
                 :
                 : "memory");
    *(u16 *)irq_address = irq_control;
    *(u16 *)(irq_address + 8) = irq_enabled;
    asm volatile("msr spsr_fc, %0\n\tbx lr" : : "r"(irq_value) : "memory");
    __builtin_unreachable();
}

const u32 startup_irq_vector __attribute__((section(".text"), aligned(4))) = 0x03007FFC;
const u32 startup_main __attribute__((section(".text"), aligned(4))) = 0x08000E1D;
const u32 startup_irq_mask __attribute__((section(".text"), aligned(4))) = 0x20C6;
const u32 startup_irq_table __attribute__((section(".text"), aligned(4))) = 0x08663BA8;
