#ifndef ZOIDS_SAGA_TASK_STATE_H
#define ZOIDS_SAGA_TASK_STATE_H

#include "engine/tasks.h"

struct TaskState;
struct TaskAttachment;
typedef void (*AttachmentFunction)(struct TaskState *, struct TaskAttachment *);

typedef struct TaskAttachment {
    u32 flags;
    u8 unknown04[0x24];
    AttachmentFunction callback;
    u8 unknown2c[0x20];
} TaskAttachment;

typedef struct TaskState {
    u32 flags;
    u8 unknown04[0x44];
    TaskAttachment *attachments[16];
} TaskState;

typedef char TaskAttachmentSizeCheck[sizeof(TaskAttachment) == 0x4C ? 1 : -1];
typedef char TaskStateSizeCheck[sizeof(TaskState) == 0x88 ? 1 : -1];

extern TaskState task_states[12];
extern TaskAttachment task_attachment_pool[16];

void initialize_game_task(u32 slot, TaskFunction function);
void run_task_attachments(TaskState *state);
void allocate_task_attachment(TaskState *state, u32 selector, AttachmentFunction callback);
void release_task_attachment(TaskState *state, u32 selector);
void stop_game_task(u8 slot);

#endif
