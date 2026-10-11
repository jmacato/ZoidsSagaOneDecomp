#include "types.h"

struct ToneData
{
    u8 type;
    u8 key;
    u8 length;
    u8 pan_sweep;
    void *wav;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
};

struct MusicPlayerTrack
{
    u8 flags;
    u8 pad_1[0x1D];
    u8 echo_volume;
    u8 echo_length;
    void *chan;
    struct ToneData tone;
    u8 gap[0x10];
    u8 *cmd_ptr;
    u8 pad_44[0xC];
};

struct MusicPlayerInfo
{
    u8 pad_0[0x18];
    u8 *mem_acc_area;
};

typedef void (*XcmdFunc)(struct MusicPlayerInfo *, struct MusicPlayerTrack *);

extern XcmdFunc D_03006F80[];

#define MEMACC_COND_JUMP(cond) \
    if (cond)                  \
        goto cond_true;        \
    else                       \
        goto cond_false;

void func_0805CE4C(struct MusicPlayerInfo *info, struct MusicPlayerTrack *track)
{
    u32 op;
    u8 *addr;
    u8 data;

    op = *track->cmd_ptr;
    track->cmd_ptr++;

    addr = info->mem_acc_area + *track->cmd_ptr;
    track->cmd_ptr++;

    data = *track->cmd_ptr;
    track->cmd_ptr++;

    switch (op)
    {
    case 0:
        *addr = data;
        return;
    case 1:
        *addr += data;
        return;
    case 2:
        *addr -= data;
        return;
    case 3:
        *addr = info->mem_acc_area[data];
        return;
    case 4:
        *addr += info->mem_acc_area[data];
        return;
    case 5:
        *addr -= info->mem_acc_area[data];
        return;
    case 6:
        MEMACC_COND_JUMP(*addr == data)
        return;
    case 7:
        MEMACC_COND_JUMP(*addr != data)
        return;
    case 8:
        MEMACC_COND_JUMP(*addr > data)
        return;
    case 9:
        MEMACC_COND_JUMP(*addr >= data)
        return;
    case 10:
        MEMACC_COND_JUMP(*addr <= data)
        return;
    case 11:
        MEMACC_COND_JUMP(*addr < data)
        return;
    case 12:
        MEMACC_COND_JUMP(*addr == info->mem_acc_area[data])
        return;
    case 13:
        MEMACC_COND_JUMP(*addr != info->mem_acc_area[data])
        return;
    case 14:
        MEMACC_COND_JUMP(*addr > info->mem_acc_area[data])
        return;
    case 15:
        MEMACC_COND_JUMP(*addr >= info->mem_acc_area[data])
        return;
    case 16:
        MEMACC_COND_JUMP(*addr <= info->mem_acc_area[data])
        return;
    case 17:
        MEMACC_COND_JUMP(*addr < info->mem_acc_area[data])
        return;
    default:
        return;
    }

cond_true:
    {
        XcmdFunc func = *(&D_03006F80[1]);

        func(info, track);
        return;
    }

cond_false:
    track->cmd_ptr += 4;
}
