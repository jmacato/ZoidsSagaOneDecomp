#include "engine/task_state.h"

void stop_game_task(u8 slot)
{
    s32 i;

    for (i = 0; i <= 15; i++)
    {
        TaskAttachment *attachment = task_states[slot].attachments[i];

        if (attachment != 0 && (attachment->flags & 1))
            release_task_attachment(&task_states[slot], i);
    }
    task_states[slot].flags = 0;
    stop_task(slot);
}
