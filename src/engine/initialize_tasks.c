#include "engine/tasks.h"

void initialize_tasks(void)
{
    s32 index = 0;
    register TaskFunction idle_function asm("r8") = run_idle_task;
    TaskContext *contexts;
    register s32 stride asm("r12");
    s32 one;
    s32 minus_one;
    u32 *resume_pc_base;
    u32 *saved_sp_base;

    asm volatile("" : "+r"(idle_function));
    contexts = task_contexts;
    stride = sizeof(TaskContext);
    one = 1;
    minus_one = -1;
    resume_pc_base = &contexts->resume_pc;
    saved_sp_base = &contexts->saved_sp;
    do {
        register s32 offset asm("r1");
        TaskContext *context;

        offset = stride * index;
        asm volatile("" : "+r"(offset));
        context = (TaskContext *)(offset + (s32)contexts);
        index++;
        context->one_based_index = index;
        context->remaining_updates = one;
        *(u32 *)(offset + (s32)saved_sp_base) = minus_one;
        *(u32 *)(offset + (s32)resume_pc_base) = minus_one;
        index <<= 24;
        index = (u32)index >> 24;
    } while ((u32)index <= 11);
    start_task(0, idle_function);
    current_task_context = task_contexts;
}
