#include "types.h"

struct Task
{
    u32 flags;
    s16 state;
    u16 pad_6;
    u32 message;
    void *send;
    u32 size;
    void *receive;
    u32 busy;
    u32 result;
    u32 command;
    u32 auxiliary;
    u8 index;
    u8 selection;
    u8 pad_2A;
    u8 interrupted;
    u8 warned;
    u8 delay;
    u8 pad_2E[0x5A];
};

struct Header { u16 first; u16 second; };
extern u8 D_02000030;
extern struct Task D_02000034[];
extern struct Header D_02004A6C;
extern struct Header D_03001F56;
extern struct Header D_03001F6A;
extern u8 D_0200758C[];
extern const u8 D_02001874[];
extern const u8 D_08675BEC[];
extern const u8 D_08675B68[];
extern struct { u8 pad[0x60]; const void *graphics; } D_08663D44;
extern u32 D_020001EC;
extern u32 D_0200025C;
extern u32 D_02000590;
extern u32 D_0200059C;

void func_08000DB8(u32);
void func_08000D1C(u32);
void func_08001DE4(const void *);
void func_0802F07C(void);
u32 func_08059380(u32);
u32 func_080593C8(u32);
void func_08059338(void);
void func_0805D270(const void *, void *, u32);
void func_0803E488(const u8 *, u32);
void func_08003DF8(u32, void *);
void func_08003E3C(u32);
void func_08004034(void);
void func_08004D18(void);
void func_0802FF5C(void);
void func_08005DD4(u16, u16);
void func_080056AC(void);
void func_08005670(void);
void func_0800196C(void);
u32 func_0805EE78(u32);

extern u16 D_03002358;
extern u16 D_0300235A;
extern struct { u16 first; u16 selection; } D_02007574;
extern u32 D_020001E4;
extern u32 D_020001F0;
extern u32 D_03001F4C;
extern u16 D_03001ED4[];
extern u16 D_03001EEC[];
void func_08052CD8(void);
void func_080019EC(u32);
void func_08037004(void);
void func_080592F0(void);
void func_080061BC(void);
void func_08005E10(void);

void func_080041B4(void)
{
    struct Frame { u32 clear; u32 status; } frame;
    register struct Task *task asm("r6");
    register struct Task *base asm("r10");
    register const u8 *ui asm("r8");
    register u32 timer asm("r9");
    register u32 yielded asm("r0");
    {
        register u8 *selected asm("r0") = &D_02000030;
        register u32 index asm("r1") = *selected;
        register u32 offset asm("r0");
        register struct Task *address asm("r1");
        asm("" : : "r"(selected), "r"(index));
        offset = index * 136;
        asm("" : "+r"(offset) : "r"(index));
        address = D_02000034;
        asm("" : "+r"(address) : "r"(offset));
        task = (struct Task *)(offset + (u32)address);
        base = address;
        asm("" : "+r"(task), "+r"(base) : "r"(address));
        yielded = (u32)D_08675BEC;
        asm("" : "+r"(yielded));
        ui = (const u8 *)yielded;
        asm("" : "+r"(ui));
    }
    for (;;)
    {
        register s32 command asm("r1") = task->state;
        asm("" : "+r"(command) : "r"(yielded));
        {
            register s32 pivot asm("r3") = 4110;
            asm("" : "+r"(pivot));
            if (command == pivot) goto state_4110;
            if (command > pivot) goto dispatch_upper;
        }
        switch (command)
        {
        case 0: goto state_0;
        case 100: goto state_100;
        case 1000: goto state_1000;
        case 1100: goto state_1100;
        case 3000: goto state_3000;
        case 3010: goto state_3010;
        case 3020: goto state_3020;
        case 4000: goto state_4000;
        case 4005: goto state_4005;
        case 4010: goto state_4010;
        case 4020: goto state_4020;
        case 4100: goto state_4100;
        }
        goto switch_done;
        dispatch_upper:
        switch (command)
        {
        case 6000: goto state_6000;
        case 6005: goto state_6005;
        case 6010: goto state_6010;
        case 6100: goto state_6100;
        case 6110: goto state_6110;
        case 9000: goto state_9000;
        case 9100: goto state_9100;
        case 9200: goto state_9200;
        case 9300: goto state_9300;
        case 9500: goto state_9500;
        case 9600: goto state_9600;
        case 9610: goto state_9610;
        case 9700: goto state_9700;
        }
        goto switch_done;

        switch (command)
        {
        case 0:
        state_0:
        {
            register volatile u32 *dma asm("r1");
            frame.clear = command;
            asm("" : : "m"(frame.clear) : "r1");
            dma = (volatile u32 *)0x040000D4;
            {
                register u32 source asm("r2") = (u32)&frame.clear;
                asm("" : "+r"(source) : "r"(dma));
                dma[0] = source;
            }
            dma[1] = 0x06000000;
            dma[2] = 0x85006000;
            func_08000DB8(dma[2]);
            func_08000D1C(0);
            func_08001DE4(D_08663D44.graphics);
            func_0802F07C();
            frame.status = (u8)func_08059380(0);
            asm("" : : "m"(frame.status));
            if (frame.status == 1)
                func_0805D270(D_02001874, D_0200758C, 8);
            else
            {
                register u32 status asm("r3");
                asm("" : "+m"(frame.status));
                status = frame.status;
                asm("" : "+r"(status));
                if (status == 2)
            {
                func_0803E488(D_08675BEC, 1);
                func_0803E488(D_08675B68, 24);
            }
            else
            {
                func_0803E488(D_08675BEC, 1);
                func_0803E488(D_08675B68, 25);
            }
            }
            func_08003DF8(10, func_08004034);
            {
                register u32 *address asm("r0") = (u32 *)((u32)base + 0x558);
                register u32 value asm("r1");
                asm("" : "+r"(address));
                value = 0;
                asm("" : "+r"(value) : "r"(address));
                *address = value;
                {
                    register u32 *output asm("r2") = &D_02000590;
                    asm("" : "+r"(output) : "r"(value));
                    *output = value;
                }
            }
            task->state = 100;
            break;
        }
        case 100:
        state_100:
        {
            register u32 *status asm("r3") = &D_0200059C;
            asm("" : "+r"(status));
            if (*status == 1)
            {
                func_08003E3C(10);
                if (frame.status == 1)
                    {
                    register u32 next asm("r4") = 1000;
                        task->state = next;
                }
                else
                {
                    func_0803E488(D_08675BEC, 20);
                    asm("" : : "m"(task->state));
                    {
                    register u32 next asm("r1") = 9000;
                        task->state = next;
                }
                }
            }
            break;
        }
        case 1000:
        state_1000:
            func_0803E488(ui, 2);
            func_0803E488(ui, 5);
            func_0803E488(D_08675B68, 4);
            func_0803E488(ui, 5);
            func_0803E488(D_08675B68, 1);
            {
                register u8 *address asm("r0") = &task->index;
                register u32 value asm("r2");
                asm("" : "+r"(address));
                value = 0;
                asm("" : "+r"(value) : "r"(address));
                *address = value;
            }
            task->state = 1100;
        case 1100:
        state_1100:
            func_0803E488(D_08675BEC, 15);
            if (D_03002358 & 0xC0)
            {
                register u8 *index asm("r1") = &task->index;
                register void *selection asm("r4");
                register u32 current asm("r0");
                register u32 full asm("r2");
                register u32 compared asm("r3");
                asm("" : "+r"(index));
                selection = &D_02007574;
                asm("" : "+r"(selection) : "r"(index));
                current = *index;
                asm("" : "+r"(current) : "r"(selection));
                full = *(u16 *)((u32)selection + 2);
                compared = *(u8 *)((u32)selection + 2);
                asm("" : "+r"(full), "+r"(compared) : "r"(current));
                if (current != compared)
                {
                    *index = full;
                    func_0803E488(D_08675BEC, 6);
                    func_0803E488(D_08675BEC, 7);
                    switch (*(u8 *)((u32)selection + 2))
                    {
                    case 0: func_0803E488(D_08675B68, 4); break;
                    case 1: func_0803E488(D_08675B68, 5); break;
                    }
                    func_0803E488(D_08675BEC, 5);
                }
            }
            else if (D_0300235A & 1)
            {
                func_080019EC(62);
                switch ((u8)D_02007574.selection)
                {
                case 0: task->state = 3000; break;
                case 1: task->state = 6000; break;
                }
            }
            else if (D_0300235A & 2)
            {
                func_080019EC(63);
                {
                    register u32 next asm("r0") = 9000;
                        task->state = next;
                }
            }
            break;
        case 3000:
        state_3000:
            func_08003DF8(4, func_08052CD8);
            {
                    register u32 next asm("r5") = 3010;
                        task->state = next;
                }
            break;
        case 3010            :
        state_3010:
        {
            register struct Task *peers asm("r4") = D_02000034;
            register u32 busy asm("r0");
            {
                register u32 result_offset asm("r1") = 0x238;
                register u32 *result_address asm("r0");
                result_address = (u32 *)((u32)peers + result_offset);
                asm("" : "+r"(result_address) : "r"(result_offset), "r"(peers));
                busy = *result_address;
            }
            if (busy == 1)
            {
                {
                    register struct Header *header asm("r1") = &D_03001F56;
                    register u32 result_offset asm("r2");
                    register u32 *result_address asm("r0");
                    asm("" : "+r"(header));
                    result_offset = 0x23C;
                    result_address = (u32 *)((u32)peers + result_offset);
                    asm("" : "+r"(result_address) : "r"(result_offset), "r"(peers));
                    header->first = *result_address;
                }
                func_08003E3C(4);
                task->state = 4000;
            }
            else if (busy == 2)
            {
                func_08003E3C(4);
                func_0803E488(D_08675BEC, 1);
                func_08003DF8(10, func_08004034);
                {
                    register u32 offset asm("r3") = 0x558;
                    register u32 *address asm("r0");
                    register u32 value asm("r1");
                    asm("" : "+r"(offset));
                    address = (u32 *)((u32)peers + offset);
                    asm("" : "+r"(address));
                    value = 0;
                    *address = value;
                    {
                    register u32 *output asm("r2") = &D_02000590;
                    *output = value;
                }
                }
                task->state = 3020;
            }
            break;
        }
        case 3020:
        state_3020:
        {
            register u32 *status asm("r3") = &D_0200059C;
            asm("" : "+r"(status));
            if (*status == 1)
            {
                func_08003E3C(10);
                task->state = 1000;
            }
            break;
        }
        case 4000:
        state_4000:
            func_08003DF8(3, func_08004D18);
            {
                    register u32 next asm("r4") = 4005;
                        task->state = next;
                }
            break;
        case 4005:
        state_4005:
            func_0803E488(ui, 1);
            func_0803E488(ui, 2);
            func_0803E488(ui, 5);
            func_0803E488(ui, 7);
            func_0803E488(D_08675B68, 8);
            func_0803E488(ui, 5);
            func_08003DF8(10, func_08004034);
            {
                register u32 *address asm("r0") = (u32 *)((u32)base + 0x558);
                register u32 value asm("r1");
                asm("" : "+r"(address));
                value = 0;
                asm("" : "+r"(value) : "r"(address));
                *address = value;
                {
                    register u32 *output asm("r2") = &D_02000590;
                    asm("" : "+r"(output) : "r"(value));
                    *output = value;
                }
            }
            task->state = 4010;
            break;
        case 4010:
        state_4010:
        {
            register struct Task *peers asm("r5") = D_02000034;
            register u32 *fade asm("r3");
            register u32 ready asm("r4");
            asm("" : "+r"(peers));
            fade = &D_0200059C;
            asm("" : "+r"(fade));
            ready = *fade;
            if (ready == 1)
            {
                func_08003E3C(10);
                asm("" : "+r"(ready));
                *(u32 *)((u32)peers + 0x1A0) = ready;
                {
                    register u32 *address asm("r1") = (u32 *)((u32)peers + 0x1B8);
                    asm("" : "+r"(address));
                    *address = 0xC001;
                }
                task->state = 4020;
                {
                    register u32 value asm("r3") = 0;
                    asm("" : "+r"(value));
                    timer = value;
                }
            }
            break;
        }
        case 4020:
        state_4020:
        {
            register u32 *reply asm("r1") = &D_020001E4;
            register u32 *waiting asm("r3");
            register u32 value asm("r0");
            value = *reply;
            asm("" : "+r"(reply), "+r"(value));
            switch (value)
            {
            case 5: case 0xFC: case 0xFE: case 0xFF:
                {
                    register u32 next asm("r2") = 9500;
                        task->state = next;
                }
                break;
            case 4: task->state = 4100; break;
            }
            waiting = &D_020001E4;
            asm("" : "+r"(waiting));
            if (*waiting == 0)
            {
                timer = (u16)(timer+1);
                if (timer > 599)
                {
                    register u32 value asm("r0") = 0xFFFF;
                    register u32 next asm("r1");
                    asm("" : "+r"(value));
                    timer = value;
                    next = 9500;
                        task->state = next;
                }
            }
            break;
        }
        case 4100:
        state_4100:
            func_0803E488(ui, 6);
            func_0803E488(ui, 7);
            func_0803E488(D_08675B68, 9);
            func_0803E488(ui, 5);
            *(u32 *)((u32)base + 0x1A0) = 2;
            *(void **)((u32)base + 0x1A4) = &D_03001F56;
            *(u32 *)((u32)base + 0x1A8) = 20;
            *(u32 *)((u32)base + 0x1B8) = 0xC001;
            {
                register u32 value asm("r2") = 0;
                asm("" : "+r"(value));
                timer = value;
            }
            {
                register u32 next asm("r3") = 4110;
                task->state = next;
            }
            break;
        case 4110:
        state_4110:
        {
            register u32 *status asm("r1") = &D_020001E4;
            asm("" : "+r"(status));
            if (*status == 3)
            {
                func_0805EE78(10);
                func_080056AC();
                goto transfer_complete;
            }
            timer = (u16)(timer+1);
            if (timer > 1199)
            {
                {
                    register u32 value asm("r3") = 0xFFFF;
                    asm("" : "+r"(value));
                    timer = value;
                }
                func_080056AC();
                asm("" : : "m"(task->state), "m"(task->busy));
                {
                    register u32 next asm("r0") = 9500;
                    asm("" : "+r"(next));
                    task->state = next;
                }
            }
            break;
        }
        case 6000:
        state_6000:
            func_08003DF8(3, func_08004D18);
            task->state = 6005;
            break;
        case 6005:
        state_6005:
            *(u32 *)((u32)base + 0x1A0) = 1;
            *(u32 *)((u32)base + 0x1B8) = 0xC002;
            func_0803E488(ui, 6);
            func_0803E488(ui, 7);
            func_0803E488(D_08675B68, 7);
            func_0803E488(ui, 5);
            {
                    register u32 next asm("r5") = 6010;
                    asm("" : "+r"(next));
                    task->state = next;
                }
            {
                register u32 value asm("r1") = 0;
                asm("" : "+r"(value));
                timer = value;
            }
            break;
        case 6010:
        state_6010:
        {
            register u32 *reply asm("r2") = &D_020001E4;
            register u32 *waiting asm("r1");
            register u32 value asm("r0");
            value = *reply;
            asm("" : "+r"(reply), "+r"(value));
            switch (value)
            {
            case 5: case 0xFC: case 0xFE: case 0xFF:
                {
                    register u32 next asm("r3") = 9500;
                    asm("" : "+r"(next));
                    task->state = next;
                }
                break;
            case 4: task->state = 6100; break;
            }
            waiting = &D_020001E4;
            asm("" : "+r"(waiting));
            if (*waiting == 0)
            {
                timer = (u16)(timer+1);
                if (timer > 2399)
                {
                    register u32 value asm("r2") = 0xFFFF;
                    register u32 next asm("r3");
                    asm("" : "+r"(value));
                    timer = value;
                    next = 9500;
                    asm("" : "+r"(next));
                    task->state = next;
                }
            }
            break;
        }
        case 6100:
        state_6100:
            func_0803E488(ui, 6);
            func_0803E488(ui, 7);
            func_0803E488(D_08675B68, 10);
            func_0803E488(ui, 5);
            *(u32 *)((u32)base + 0x1A0) = 3;
            *(void **)((u32)base + 0x1A4) = &D_03001F56;
            *(u32 *)((u32)base + 0x1B8) = 0xC002;
            {
                register u32 value asm("r0") = 0;
                asm("" : "+r"(value));
                timer = value;
            }
            {
                    register u32 next asm("r5") = 6110;
                    asm("" : "+r"(next));
                    task->state = next;
                }
            break;
        case 6110:
        state_6110:
        {
            register u32 *status asm("r1") = &D_020001E4;
            asm("" : "+r"(status));
            if (*status == 3)
            {
                func_0805EE78(10);
                func_080056AC();
                {
                    register struct Header *header asm("r1") = &D_03001F56;
                    asm("" : "+r"(header));
                    if (header->first <= 152)
                        func_08037004();
                }
                func_080592F0();
            transfer_complete:
                func_0803E488(ui, 6);
                func_0803E488(ui, 7);
                func_0803E488(D_08675B68, 11);
                func_0803E488(ui, 5);
                func_0803E488(ui, 20);
                {
                    register u32 next asm("r2") = 9000;
                    asm("" : "+r"(next));
                    task->state = next;
                }
            }
            else
            {
                timer = (u16)(timer+1);
                if (timer > 1199)
                {
                    {
                    register u32 value asm("r3") = 0xFFFF;
                    asm("" : "+r"(value));
                    timer = value;
                }
                    func_080056AC();
                    {
                    register u32 next asm("r0") = 9500;
                    asm("" : "+r"(next));
                    task->state = next;
                }
                }
            }
            break;
        }
        case 9000:
        state_9000:
            func_08003DF8(10, func_08004034);
            *(u32 *)((u32)base + 0x558) = 1;
            {
                register u32 value asm("r1") = 0;
                asm("" : "+r"(value));
                {
                    register u32 *output asm("r2") = &D_02000590;
                    asm("" : "+r"(output) : "r"(value));
                    *output = value;
                }
            }
            {
                    register u32 next asm("r4") = 9100;
                    asm("" : "+r"(next));
                    task->state = next;
                }
            break;
        case 9100:
        state_9100:
        {
            register u32 *status asm("r3") = &D_0200059C;
            asm("" : "+r"(status));
            if (*status == 1)
            {
                func_08003E3C(10);
                task->state = 9200;
            }
            break;
        }
        case 9200:
        state_9200:
            {
                register u32 value asm("r0") = 0;
                asm("" : "+r"(value));
                D_020001F0 = value;
            }
            task->busy = 1;
            task->state = 9300;
            break;
        case 9300:
        state_9300:
            break;
        case 9500:
        state_9500:
        {
            register volatile u32 *dma asm("r1");
            func_0800196C();
            {
                register u32 value asm("r2") = 0;
                asm("" : "+r"(value));
                frame.clear = value;
            }
            asm("" : : "m"(frame.clear) : "r1");
            dma = (volatile u32 *)0x040000D4;
            {
                register u32 source asm("r3") = (u32)&frame.clear;
                asm("" : "+r"(source) : "r"(dma));
                dma[0] = source;
            }
            dma[1] = 0x06000000;
            dma[2] = 0x85006000;
            func_08000DB8(dma[2]);
            func_08000D1C(0);
            func_08001DE4(D_08663D44.graphics);
            func_0802F07C();
            task->state = 9600;
            break;
        }
        case 9600:
        state_9600:
            func_0803E488(ui, 1);
            func_0803E488(ui, 2);
            func_0803E488(ui, 5);
            {
            register u32 *status asm("r1") = &D_020001E4;
            register u32 value asm("r0") = *status;
            asm("" : "+r"(status), "+r"(value));
            switch (value)
            {
            case 0xFE: func_0803E488(D_08675B68, 14); break;
            case 5:
                if (task->index == 0)
                    func_0803E488(D_08675B68, 26);
                else
                    func_0803E488(D_08675B68, 27);
                break;
            case 0xFC: func_0803E488(D_08675B68, 13); break;
            case 0xFD: case 0xFF: func_0803E488(D_08675B68, 12); break;
            default:
                if (timer == 0xFFFF)
                    func_0803E488(D_08675B68, 29);
                else
                    func_0803E488(D_08675B68, 12);
                break;
            }
            }
            func_0803E488(D_08675BEC, 5);
            func_08003DF8(10, func_08004034);
            {
                register u32 *address asm("r0") = (u32 *)((u32)base + 0x558);
                register u32 value asm("r2");
                asm("" : "+r"(address));
                value = 0;
                asm("" : "+r"(value) : "r"(address));
                *address = value;
                {
                    register u32 *output asm("r3") = &D_02000590;
                    asm("" : "+r"(output) : "r"(value));
                    *output = value;
                }
            }
            task->state = 9610;
            break;
        case 9610:
        state_9610:
        {
            register u32 *status asm("r1") = &D_0200059C;
            asm("" : "+r"(status));
            if (*status == 1)
            {
                func_08003E3C(10);
                task->state = 9700;
            }
            break;
        }
        case 9700:
        state_9700:
            func_080056AC();
            func_0803E488(D_08675BEC, 20);
            task->state = 9200;
            break;
        }
        switch_done:
        {
            register u32 *abort asm("r2") = &D_020001F0;
            asm("" : "+r"(abort));
            if (*abort)
            {
                u8 *interrupted = &task->interrupted;
                if (!*interrupted)
                {
                    register u32 next asm("r3");
                    *interrupted = 1;
                    next = 9500;
                    asm("" : "+r"(next));
                    task->state = next;
                }
            }
        }
        {
            u32 scratch;
            asm volatile("" : "=&l"(scratch) : "l"(task) : "r0", "r1", "r2", "r3", "r4", "r5");
        }
        yielded = func_0805EE78(1);
    }
}

void func_08004B38(void)
{
    u16 clear[2];
    register u32 zero asm("r4");
    register u16 *header asm("r5");
    {
        register u32 *address asm("r0") = &D_03001F4C;
        asm("" : "+r"(address));
        zero = 0;
        asm("" : "+r"(zero) : "r"(address));
        *address = zero;
    }
    {
        register u16 *first asm("r0") = clear;
        asm("" : "+r"(first));
        *first = zero;
        header = D_03001ED4;
        asm("" : "+r"(header) : "r"(first));
        func_0805D270(first, header, 0x0100000C);
    }
    {
        register u16 *second asm("r0") = clear+1;
        asm("" : "+r"(second));
        *second = zero;
        {
            register void *destination asm("r1") = D_03001EEC;
            asm("" : "+r"(destination) : "m"(*second), "r"(second) : "r2");
            func_0805D270(second, destination, 0x01000018);
        }
    }
    func_080061BC();
    func_08005E10();
    {
        register u32 value asm("r0") = 0xBED1;
        asm("" : "+r"(value));
        *header = value;
    }
}
