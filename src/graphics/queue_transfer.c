#include "graphics/transfer.h"

int queue_transfer(const Transfer *transfers, u16 selector, u8 mode)
{
    register u32 count asm("r6") = transfer_count;
    int result;

    /* Slot 16 overlaps the next arrays in the original queue. */
    if (count <= 16) {
        transfer_sources[transfer_count] = transfers[selector].source;
        transfer_destinations[transfer_count] = transfers[selector].destination;
        transfer_sizes[transfer_count] = transfers[selector].byte_count;
        transfer_modes[transfer_count] = mode;
        transfer_count = count + 1;
        result = 0;
    } else {
        result = 1;
    }
    asm volatile("" : : "r"(count));
    return result;
}
