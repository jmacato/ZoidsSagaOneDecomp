#include "engine/tasks.h"

void stop_task(u8 slot)
{
    task_contexts[slot].saved_sp = 0xFFFFFFFF;
    task_contexts[slot].resume_pc = 0xFFFFFFFF;
}
