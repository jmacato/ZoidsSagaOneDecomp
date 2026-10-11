#include "engine/tasks.h"

void run_idle_task(void)
{
    for (;;)
        yield_task_for_updates(1);
}
