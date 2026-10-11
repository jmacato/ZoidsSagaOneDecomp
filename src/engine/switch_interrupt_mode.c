#include "types.h"

register u32 resume_address asm("r0");
register u32 saved_status asm("r1");

void switch_interrupt_mode(void)
{
    asm volatile("mov %0, lr\n\tmrs %1, spsr\n\tstmdb sp!, {r1}\n\tmrs r1, cpsr"
                 : "=r"(resume_address), "=r"(saved_status)
                 :
                 : "memory");
    saved_status &= ~0x9F;
    asm volatile("" : "+r"(saved_status));
    saved_status |= 0x1F;
    asm volatile("msr cpsr_fc, %0\n\tstmdb sp!, {lr}\n\tbx r0"
                 :
                 : "r"(saved_status), "r"(resume_address)
                 : "memory");
    __builtin_unreachable();
}

void func_08000400(void)
{
    asm volatile("mov %0, lr\n\tldm sp!, {lr}\n\tmrs r1, cpsr"
                 : "=r"(resume_address), "=r"(saved_status)
                 :
                 : "memory");
    saved_status &= ~0x1F;
    asm volatile("" : "+r"(saved_status));
    saved_status |= 0x92;
    asm volatile("msr cpsr_fc, %0\n\tldm sp!, {r1}\n\tmsr spsr_fc, r1\n\tbx r0"
                 : "+r"(saved_status)
                 : "r"(resume_address)
                 : "memory");
    __builtin_unreachable();
}
