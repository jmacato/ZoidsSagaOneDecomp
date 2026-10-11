#include "types.h"

struct Task
{
    u8 pad_0[0x5E];
    vu16 limit;
    u8 pad_60[2];
    u16 count;
};

s32 func_08049B50(struct Task *task)
{
    task->count++;
    if (task->limit > task->count)
        return 0;
    return 1;
}
