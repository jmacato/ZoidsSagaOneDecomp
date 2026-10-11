#include "engine/tasks.h"

extern TaskFunction hblank_callback;

void run_hblank_callback(void)
{
    hblank_callback();
}
