#include "engine/bios.h"
#include "engine/task_state.h"

void initialize_game_task(u32 slot, TaskFunction function)
{
    u8 selected = slot;
    u32 zero = 0;
    TaskState *state = &task_states[selected];

    bios_cpu_set(&zero, state, 0x05000022);
    state->flags |= 3;
    start_task(selected, function);
}
