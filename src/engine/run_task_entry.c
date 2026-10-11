#include "engine/tasks.h"

void run_task_entry(u8 slot)
{
    task_functions[slot]();
    stop_task(slot);
    for (;;)
        yield_task_for_updates(1);
}
