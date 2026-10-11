#include "types.h"

struct Task
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 message;
    u32 data;
    u32 size;
    u32 extra;
    u32 busy;
    u32 result;
    u32 mode;
    u8 pad_24[4];
    u8 flag;
    u8 pad_29[0x5F];
};

extern u8 D_02000030;
extern struct Task D_02000034[];
extern u16 D_03001F56[];
extern u16 D_03001F6A[];
extern u8 D_020117D0[];
extern u8 D_020117D4[];
extern u8 D_020128AC[];
extern u8 D_0200EB88[];
extern u8 D_0200FC60[];
extern u32 D_020001EC;

u32 func_08034A78(u32);
u32 func_08034BF8(const u8 *src, u32 size, u8 *dst);
u16 func_08004CE8(void *values, u16 count);
void func_08034B64(void *side);
void func_0805D298(const void *, void *);
void func_0805D270(const void *, void *, u32);
void func_0805EE78(s32);

void func_08034738(void)
{
    struct Task *task = &D_02000034[D_02000030];
    vu16 zero;
    u16 checksum;
    u32 size;
    u32 length;

    for (;;)
    {
        switch (task->state)
        {
        case 0:
            task->flag = 0;
            task->state = 100;
            zero = 0;
            func_0805D270((void *)&zero, D_020117D0, 0x010015F6);
        case 100:
        {
            register u32 length asm("r4");
            {
                register u8 *source asm("r4") = D_0200EB88;
                register u32 transfer_size asm("r1") = 0x10D8;
                length = func_08034BF8(source, transfer_size, D_020117D4);
            }
            checksum = func_08004CE8(D_020117D4, 0x86C);
            size = func_08034A78(length);
            D_02000034[3].message = 4;
            D_02000034[3].data = (u32)D_020117D4;
            D_02000034[3].size = size;
            {
                register u32 *destination asm("r0") = &D_02000034[3].extra;
                register u8 *value asm("r2") = D_020128AC;
                asm("" : "+r"(destination) : "r"(value));
                *destination = (u32)value;
            }
            {
                register u32 value asm("r0") = 0xC003;
                register u32 *mode asm("r1") = &D_020001EC;
                asm("" : : "r"(value), "r"(mode));
                *mode = value;
            }
            task->state = 200;
            break;
        }
        case 200:
            switch (D_02000034[3].busy)
            {
            case 5:
            case 0xFC:
            case 0xFE:
            case 0xFF:
                task->state = 9500;
                break;
            case 4:
                task->state = 300;
                break;
            }
            break;
        case 300:
            switch (D_02000034[3].busy)
            {
            case 5:
            case 0xFC:
            case 0xFE:
            case 0xFF:
                task->state = 9500;
                break;
            case 3:
                task->state = 400;
                break;
            }
            break;
        case 400:
            D_03001F56[0] = checksum;
            D_02000034[3].message = 4;
            D_02000034[3].data = (u32)D_03001F56;
            D_02000034[3].size = 0x14;
            D_02000034[3].extra = (u32)D_03001F6A;
            D_02000034[3].mode = 0xC003;
            task->state = 500;
        case 500:
            switch (D_02000034[3].busy)
            {
            case 5:
            case 0xFC:
            case 0xFE:
            case 0xFF:
                task->state = 9500;
                break;
            case 4:
                task->state = 600;
                break;
            }
            break;
        case 600:
            switch (D_02000034[3].busy)
            {
            case 5:
            case 0xFC:
            case 0xFE:
            case 0xFF:
                task->state = 9500;
                break;
            case 3:
                task->state = 700;
                break;
            }
            break;
        case 700:
        {
            u16 received = func_08004CE8(D_020128AC, 0x86C);
            asm("" : : "r"(received));
            if (received == D_03001F6A[0])
                D_03001F56[0] = 0x1001;
            else
                D_03001F56[0] = 0x1002;
            D_02000034[3].message = 4;
            D_02000034[3].data = (u32)D_03001F56;
            D_02000034[3].size = 0x14;
            D_02000034[3].extra = (u32)D_03001F6A;
            D_02000034[3].mode = 0xC003;
            task->state = 800;
            break;
        }
        case 800:
            switch (D_02000034[3].busy)
            {
            case 5:
            case 0xFC:
            case 0xFE:
            case 0xFF:
                task->state = 9500;
                break;
            case 4:
                task->state = 900;
                break;
            }
            break;
        case 900:
            switch (D_02000034[3].busy)
            {
            case 5:
            case 0xFC:
            case 0xFE:
            case 0xFF:
                task->state = 9500;
                break;
            case 3:
                task->state = 1000;
                break;
            }
            break;
        case 1000:
            if (D_03001F56[0] == 0x1001 && D_03001F6A[0] == D_03001F56[0])
            {
                func_0805D298(D_020128AC, D_0200FC60);
                func_08034B64(D_0200FC60);
                task->state = 9000;
            }
            else
            {
                task->busy = 2;
                task->state = 9100;
            }
            break;
        case 9000:
            task->busy = 1;
            task->state = 9100;
            break;
        case 9500:
            task->busy = D_02000034[3].busy;
            task->state = 9510;
            break;
        case 9100:
        case 9510:
            break;
        }
        func_0805EE78(1);
    }
}
