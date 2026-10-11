#include "engine/task_state.h"

void run_task_attachments(TaskState *state)
{
    s32 index;

    for (index = 0; index <= 15; index++) {
        TaskAttachment *attachment = state->attachments[index];

        if (attachment != 0 && (attachment->flags & 3) == 3)
            attachment->callback(state, attachment);
    }
}
