#include "engine/bios.h"
#include "engine/task_state.h"

void release_task_attachment(TaskState *state, u32 selector)
{
    u16 zero;
    register u16 *zero_pointer asm("r2");
    register u32 zero_value asm("r0");
    TaskAttachment **attachment;

    selector <<= 24;
    asm volatile("" : "+r"(selector));
    zero_pointer = &zero;
    zero_value = 0;
    *zero_pointer = zero_value;
    asm volatile("" : "+r"(zero_pointer), "+r"(zero_value));
    selector >>= 22;
    asm volatile("" : "+r"(selector));
    attachment = state->attachments;
    attachment = (TaskAttachment **)((u32)attachment + selector);
    bios_cpu_set(&zero, *attachment, 0x01000026);
    *attachment = 0;
}
