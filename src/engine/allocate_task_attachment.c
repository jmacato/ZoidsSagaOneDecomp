#include "engine/bios.h"
#include "engine/task_state.h"

void allocate_task_attachment(TaskState *state, u32 selector, AttachmentFunction callback)
{
    register AttachmentFunction saved_callback asm("r8") = callback;
    s32 index;
    register TaskAttachment *pool asm("r6");
    TaskAttachment **destination;
    register TaskAttachment **base asm("r0");
    u16 zero;

    asm volatile("" : "+r"(saved_callback));
    selector <<= 24;
    asm volatile("" : "+r"(selector));
    index = 0;
    pool = task_attachment_pool;
    selector >>= 22;
    base = state->attachments;
    asm volatile("" : "+r"(base));
    destination = (TaskAttachment **)((u32)base + selector);
    for (; index <= 15; index++) {
        register u32 offset asm("r5") = index * sizeof(TaskAttachment);
        register TaskAttachment *attachment asm("r4") = (TaskAttachment *)(offset + (u32)pool);
        u32 in_use = attachment->flags & 1;

        if (in_use == 0) {
            register AttachmentFunction *callback_address asm("r0");

            zero = in_use;
            bios_cpu_set(&zero, attachment, 0x01000026);
            *destination = attachment;
            attachment->flags |= 3;
            callback_address = &pool->callback;
            callback_address = (AttachmentFunction *)(offset + (u32)callback_address);
            asm volatile("" : "+r"(callback_address));
            *callback_address = saved_callback;
            break;
        }
    }
}
