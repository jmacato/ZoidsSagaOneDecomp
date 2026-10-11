#ifndef ZOIDS_SAGA_BIOS_H
#define ZOIDS_SAGA_BIOS_H

#include "types.h"

/* CpuSet returns the r0 value that the BIOS leaves after the transfer. */
u32 bios_cpu_set(const void *source, void *destination, u32 control);

#endif
