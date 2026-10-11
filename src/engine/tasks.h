#ifndef ZOIDS_SAGA_TASKS_H
#define ZOIDS_SAGA_TASKS_H

#include "types.h"

typedef void (*TaskFunction)(void);

typedef struct {
    u8 one_based_index;
    u8 remaining_updates;
    u8 unknown02[2];
    u32 saved_sp;
    u32 resume_pc;
    u32 saved_spsr;
    u32 saved_registers[15];
} TaskContext;

typedef char TaskContextSizeCheck[sizeof(TaskContext) == 0x4C ? 1 : -1];

extern TaskContext task_contexts[12];
extern TaskContext *current_task_context;
extern TaskFunction task_functions[12];
extern const u32 task_entry_points[12];

void run_task_entry(u8 slot);
void run_idle_task(void);
void initialize_tasks(void);
void start_task(u32 slot, TaskFunction function);
void stop_task(u8 slot);
void run_scheduled_tasks(void);
void yield_task_for_updates(u32 updates);

#endif
