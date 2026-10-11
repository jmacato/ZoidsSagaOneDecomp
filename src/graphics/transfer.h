#ifndef ZOIDS_SAGA_TRANSFER_H
#define ZOIDS_SAGA_TRANSFER_H

#include "types.h"

typedef struct {
    const u8 *source;
    void *destination;
    u16 byte_count;
    u16 unknown0a;
} Transfer;

typedef char TransferSizeCheck[sizeof(Transfer) == 12 ? 1 : -1];

extern const u8 *transfer_sources[];
extern void *transfer_destinations[];
extern u16 transfer_sizes[];
extern u16 transfer_modes[];
extern volatile u16 transfer_count;

int queue_transfer(const Transfer *transfers, u16 selector, u8 mode);
void process_transfers(void);

#endif
