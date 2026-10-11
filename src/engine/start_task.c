#include "engine/tasks.h"

void start_task(u32 slot, TaskFunction function)
{
    register TaskFunction saved_function asm("r6") = function;
    register u32 saved_slot asm("r4");
    register TaskContext *contexts asm("r5");
    register u32 normalized_slot asm("r1");
    u32 offset;

    asm volatile("" : "+r"(saved_function));
    normalized_slot = (u8)slot;
    saved_slot = normalized_slot;
    contexts = task_contexts;
    if (normalized_slot != 0) {
        u32 *saved_sp_base;
        register u32 *destination asm("r2");

        offset = normalized_slot * sizeof(TaskContext);
        saved_sp_base = &contexts->saved_sp;
        destination = (u32 *)(offset + (u32)saved_sp_base);
        asm volatile("" : "+r"(destination));
        *destination = 0x030005CC + normalized_slot * 0x280;
    }
    {
        register u32 context_offset asm("r3");
        register u32 *destination asm("r1");
        register u32 function_offset asm("r2");
        TaskContext *context;
        register const u32 *entries asm("r0");

        context_offset = saved_slot * sizeof(TaskContext);
        destination = &contexts->resume_pc;
        destination = (u32 *)(context_offset + (u32)destination);
        asm volatile("" : "+r"(destination), "+r"(context_offset), "+r"(contexts));
        entries = task_entry_points;
        asm volatile("" : "+r"(entries));
        function_offset = saved_slot * 4;
        *destination = *(u32 *)(function_offset + (u32)entries);
        context = (TaskContext *)(context_offset + (u32)contexts);
        context->remaining_updates = 1;
        *(TaskFunction *)(function_offset + (u32)task_functions) = saved_function;
    }
}
