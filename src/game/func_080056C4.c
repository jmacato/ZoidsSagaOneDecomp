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
    u8 pad_2A[2];
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

void func_080056C4(void)
{
    struct Frame { u32 clear; u32 status; } frame;
    register struct Task *task asm("r5");
    register struct Task *base asm("r8");
    register u32 timer asm("r9");
    register u32 zero asm("r10");
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
        {
            yielded = 0;
            asm("" : "+r"(yielded));
            zero = yielded;
            asm("" : "+r"(zero));
        }
    }
    for (;;)
    {
        register s32 command asm("r4") = task->state;
        asm("" : "+r"(command) : "r"(yielded));
        switch (command)
        {
        case 0:
        {
            register volatile u32 *dma asm("r1");
            frame.clear = command;
            asm("" : : "m"(frame.clear) : "r1");
            dma = (volatile u32 *)0x040000D4;
            asm("" : "+r"(dma));
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
            {
                func_0805D270(D_02001874, D_0200758C, 8);
                frame.status = (u8)func_080593C8(0);
                asm("" : : "m"(frame.status));
                if (frame.status != 1)
                {
                    D_02004A6C.second = command;
                    D_02004A6C.first = command;
                    func_08059338();
                }
            }
            else
            {
                asm("" : "+m"(frame.status));
                if (frame.status == 2)
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
            *(u32 *)((u32)base + 0x558) = zero;
            {
                register u32 value asm("r1") = zero;
                register u32 *address asm("r2") = &D_02000590;
                asm("" : "+r"(value), "+r"(address));
                *address = value;
            }
            task->state = 100;
            break;
        }
        case 100:
        {
            register u32 *fade asm("r1") = &D_0200059C;
            asm("" : "+r"(fade));
            if (*fade == 1)
            {
                func_08003E3C(10);
                {
                register u32 status asm("r2") = frame.status;
                asm("" : "+r"(status));
                if (status == 1)
                {
                    func_08003DF8(3, func_08004D18);
                    task->state = 1000;
                }
                else
                {
                    func_0803E488(D_08675BEC, 20);
                    task->state = 9000;
                }
                }
            }
            break;
        }
        case 1000:
            {
                register u32 *address asm("r1") = (u32 *)((u32)base + 0x1A0);
                register u32 value asm("r0");
                asm("" : "+r"(address));
                value = 1;
                asm("" : "+r"(value) : "r"(address));
                *address = value;
            }
            {
                register u32 value asm("r0") = 0xC003;
                register u32 *address asm("r1");
                asm("" : "+r"(value) : : "r1");
                address = &D_020001EC;
                asm("" : "+r"(address) : "r"(value));
                *address = value;
            }
            {
                register u8 *delayp asm("r0") = &task->delay;
                register u32 value asm("r2");
                asm("" : "+r"(delayp));
                value = zero;
                asm("" : "+r"(value) : "r"(delayp));
                *delayp = value;
                delayp--;
                *delayp = value;
            }
            task->state = 1100;
            {
                register u32 value asm("r0") = 0;
                asm("" : "+r"(value));
                timer = value;
            }
        case 1100:
        {
            switch (D_02000034[3].busy)
            {
            case 5: case 0xFC: case 0xFE: case 0xFF:
                task->state = 9500;
                break;
            case 4:
                {
                    register u32 value asm("r0") = D_02000034[3].result;
                    register u8 *address asm("r1");
                    asm("" : "+r"(value) : : "r1");
                    address = &task->selection;
                    asm("" : "+r"(address) : "r"(value));
                    *address = value;
                }
                task->state = 1200;
                timer = 0;
                break;
            }
            if (D_02000034[3].busy == 0)
            {
                u8 *delayp = &task->delay;

                u32 delay = *delayp + 1;
                *delayp = delay;
                delay = (u8)delay;
                if (delay > 7 && !delayp[-1])
                {
                    delayp[-1] = 1;
                    func_0803E488(D_08675BEC, 1);
                    func_0803E488(D_08675B68, 20);
                }
            }
            timer = (u16)(timer + 1);
            asm("" : "+r"(timer));
            if (timer > 599)
            {
                timer = 0xFFFF;
                goto set_error;
            }
            break;
        }
        case 1200:
            D_03001F56.first = D_02004A6C.first;
            D_03001F56.second = D_02004A6C.second;
            *(u32 *)((u32)base + 0x1a0) = 4;
            *(void * *)((u32)base + 0x1a4) = &D_03001F56;
            *(u32 *)((u32)base + 0x1a8) = 20;
            *(void * *)((u32)base + 0x1ac) = &D_03001F6A;
            {
                register u32 value asm("r0") = 0xC003;
                register u32 *address asm("r1");
                asm("" : "+r"(value) : : "r1");
                address = &D_020001EC;
                asm("" : "+r"(address) : "r"(value));
                *address = value;
            }
            task->state = 1300;
        case 1300:
            timer = (u16)(timer + 1);
            asm("" : "+r"(timer));
            if (timer > 599)
            {
                register u32 value asm("r2") = 0xFFFF;
                register u32 next asm("r0");
                asm("" : "+r"(value));
                timer = value;
                asm("" : "+r"(timer));
                next = 9500;
                asm("" : "+r"(next));
                task->state = next;
            }
            switch (*(u32 *)((u32)base + 0x1b0))
            {
            case 5: case 0xFC: case 0xFE: case 0xFF:
                {
                    register u32 next asm("r1") = 9500;
                    asm("" : "+r"(next));
                    task->state = next;
                }
                break;
            case 4:
                task->state = 1400;
                {
                    register u32 value asm("r2") = 0;
                    asm("" : "+r"(value));
                    timer = value;
                }
                break;
            }
            break;
        case 1400:
            timer = (u16)(timer + 1);
            asm("" : "+r"(timer));
            if (timer > 599)
            {
                register u32 value asm("r0") = 0xFFFF;
                register u32 next asm("r2");
                asm("" : "+r"(value));
                timer = value;
                asm("" : "+r"(timer));
                next = 9500;
                asm("" : "+r"(next));
                task->state = next;
            }
            switch (*(u32 *)((u32)base + 0x1b0))
            {
            case 5: case 0xFC: case 0xFE: case 0xFF:
                goto set_error;
            case 3:
                task->state = 1500;
                {
                    register u32 value asm("r1") = 0;
                    asm("" : "+r"(value));
                    timer = value;
                }
                break;
            }
            break;
        case 1500:
            func_0803E488(D_08675BEC, 1);
            func_0803E488(D_08675B68, 19);
            func_0803E488(D_08675BEC, 13);
            func_08005DD4(D_03001F56.first, D_03001F56.second);
            func_0803E488(D_08675BEC, 9);
            func_0803E488(D_08675BEC, 14);
            func_08005DD4(D_03001F6A.first, D_03001F6A.second);
            func_0803E488(D_08675BEC, 10);
            {
                register u8 *address asm("r0") = &task->delay;
                register u32 value asm("r2");
                asm("" : "+r"(address));
                value = zero;
                asm("" : "+r"(value) : "r"(address));
                *address = value;
            }
            task->state = 1600;
        case 1600:
        {
            register u8 *delayp asm("r1") = &task->delay;
            register u32 delay asm("r0");
            asm("" : "+r"(delayp));
            delay = *delayp + 1;
            *delayp = delay;
            delay = (u8)delay;
            if (delay > 119)
                task->state = 1700;
            break;
        }
        case 1700:
            func_08003DF8(10, func_08004034);
            {
                register u32 *address asm("r1") = (u32 *)((u32)base + 0x558);
                register u32 value asm("r0");
                asm("" : "+r"(address));
                value = 1;
                asm("" : "+r"(value) : "r"(address));
                *address = value;
            }
            {
                register u32 value asm("r0") = zero;
                register u32 *address asm("r1") = &D_02000590;
                asm("" : "+r"(value), "+r"(address));
                *address = value;
            }
            {
                register u32 next asm("r2") = 1710;
                asm("" : "+r"(next));
                task->state = next;
            }
            break;
        case 1710:
        {
            register u32 *fade asm("r1") = &D_0200059C;
            asm("" : "+r"(fade));
            if (*fade == 1)
            {
                func_08003E3C(10);
                task->state = 2000;
            }
            break;
        }
        case 2000:
            func_08003DF8(4, func_0802FF5C);
            {
                register u32 value asm("r0") = task->selection;
                register u32 *address asm("r2");
                asm("" : "+r"(value) : : "r2");
                address = &D_0200025C;
                asm("" : "+r"(address) : "r"(value));
                *address = value;
            }
            task->state = 2100;
            break;
        case 2100:
            if (D_02000034[4].busy == 1)
            {
                func_080056AC();
                func_08003E3C(4);
                task->state = 9200;
            }
            else if (D_02000034[3].auxiliary)
            {
                func_08003E3C(4);
                func_08005670();
            set_error:
                task->state = 9500;
            }
            break;
        case 9000:
            func_08003DF8(10, func_08004034);
            {
                register u32 *address asm("r0") = (u32 *)((u32)base + 0x558);
                register u32 value asm("r1");
                asm("" : "+r"(address));
                value = 1;
                asm("" : "+r"(value) : "r"(address));
                *address = value;
            }
            {
                register u32 value asm("r1") = zero;
                register u32 *address asm("r2") = &D_02000590;
                asm("" : "+r"(value), "+r"(address));
                *address = value;
            }
            task->state = 9100;
            break;
        case 9100:
        {
            register u32 *fade asm("r1") = &D_0200059C;
            asm("" : "+r"(fade));
            if (*fade == 1)
            {
                func_08003E3C(10);
                task->state = 9200;
            }
            break;
        }
        case 9200:
            task->busy = 1;
            task->state = 9300;
            break;
        case 9300:
            break;
        case 9500:
        {
            register volatile u32 *dma asm("r1");
            func_0800196C();
            {
                register u32 value asm("r2") = zero;
                asm("" : "+r"(value));
                frame.clear = value;
            }
            asm("" : : "m"(frame.clear) : "r1");
            dma = (volatile u32 *)0x040000D4;
            asm("" : "+r"(dma));
            {
                register u32 source asm("r0") = (u32)&frame.clear;
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
            func_0803E488(D_08675BEC, 1);
            func_0803E488(D_08675BEC, 2);
            func_0803E488(D_08675BEC, 5);
            switch (*(u32 *)((u32)base + 0x1b0))
            {
            case 0xFE: func_0803E488(D_08675B68, 14); break;
            case 5: func_0803E488(D_08675B68, 28); break;
            case 0xFC: func_0803E488(D_08675B68, 13); break;
            case 0xFD: case 0xFF: func_0803E488(D_08675B68, 12); break;
            default:
                if (timer == 0xFFFF)
                    func_0803E488(D_08675B68, 29);
                else
                    func_0803E488(D_08675B68, 12);
                break;
            }
            func_0803E488(D_08675BEC, 5);
            func_08003DF8(10, func_08004034);
            *(u32 *)((u32)base + 0x558) = zero;
            {
                register u32 value asm("r1") = zero;
                register u32 *address asm("r2") = &D_02000590;
                asm("" : "+r"(value), "+r"(address));
                *address = value;
            }
            task->state = 9610;
            break;
        case 9610:
        {
            register u32 *fade asm("r1") = &D_0200059C;
            asm("" : "+r"(fade));
            if (*fade == 1)
            {
                func_08003E3C(10);
                task->state = 9700;
            }
            break;
        }
        case 9700:
            func_080056AC();
            func_0803E488(D_08675BEC, 20);
            task->state = 9200;
            break;
        }
        yielded = func_0805EE78(1);
    }
}
