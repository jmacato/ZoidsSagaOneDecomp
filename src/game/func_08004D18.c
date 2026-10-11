#include "types.h"
typedef unsigned long long u64;
union PairRegister {u32 word;u32 parts[2];u64 wide;};

struct PeerTask
{
    u32 flags;
    s16 state;
    u16 pad_6;
    u32 message;
    void *source;
    u32 size;
    void *destination;
    u32 busy;
    u32 other;
    u32 command;
    u32 error;
    s16 mode;
    s16 rejected;
    u16 delay;
    s16 latched;
    u16 timer;
    u16 pad_32;
    u16 active;
    u8 pad_36[0x52];
};
struct Packet { u16 id; u16 data[10]; u16 sum; };
extern u8 D_02000030;
extern struct PeerTask D_02000034[];
extern struct Packet D_03001ED4;
extern struct Packet D_03001EEC[];
extern u32 D_03001F4C;
extern u8 D_03001F55;
extern const u8 D_08666C9C[];
u8 func_08004BA0(void);
s32 func_08004C80(u16, u16 *);
s32 receive_code_word(u32,u16 *) asm("func_08004C80");
s32 func_08004C98(u16, u16 *);
void func_08004C44(u16);
void func_08004C74(u16);
u32 func_08004CE8(u16 *, u16);
u32 checksum_ten_words(u16 *, u32) asm("func_08004CE8");
s32 func_08005E5C(u16);
void func_08005E10(void);
void func_0805D270(const void *, void *, u32);
u32 func_0805D484(u32, u32);
u32 func_0805EE78(u32);
void func_08003E3C(u32);

void func_08004D18(void)
{
    struct Frame
    {
        u16 clear[4];
        volatile u32 index;
        u8 *source;
        u8 *destination;
        u32 count;
        u16 *volatile data;
    } frame;
    register struct PeerTask *task asm("r6");
    register u32 peer asm("r9");
    register u32 packet asm("r10");
    register struct Packet *received asm("r8");
    register struct Packet *output asm("r4");
    register u16 *clear_address asm("r0");
    u32 clear_value;
    {
        register u8 *selected asm("r0") = &D_02000030;
        register u32 index asm("r1") = *selected;
        register u32 offset asm("r0");
        register struct PeerTask *address asm("r1");
        asm("" : : "r"(selected), "r"(index));
        offset = ((index << 4) + index) << 3;
        asm("" : "+r"(offset) : "r"(index));
        address = D_02000034;
        asm("" : "+r"(address) : "r"(offset));
        task = (struct PeerTask *)((u32)offset + (u32)address);
        asm("" : "+r"(task) : "r"(address));
    }
    for (;;)
    {
        if (task->latched == 0)
            task->busy = 0;
        switch (task->state)
        {
        case 0:
            D_03001F55 = 1;
            task->state = 1000;
        case 1000:
            task->active = 0;
            switch (task->message)
            {
            case 1: task->state = 3000; task->mode = 0; break;
            case 2: task->state = 3000; task->mode = 1; break;
            case 3: task->state = 3000; task->mode = 2; break;
            case 4: task->state = 3000; task->mode = 3; break;
            case 5: task->state = 2900; task->mode = 4; break;
            }
            break;
        case 3000:
            func_08005E10();
            D_03001ED4.id = 0xBED0;
            task->state = 3050;
            task->rejected = 0;
            break;
        case 3050:
            if ((u8)func_08004BA0())
            {
                register u32 one asm("r2");
                register u32 flags asm("r1");
                register u32 other asm("r0");
                task->active = 0;
                one = 1;
                task->active = one;
                flags = D_03001F4C >> 7;
                other = one & ~flags;
                task->other = other;
                peer = one;
                asm volatile("" : "+r"(peer));
                one &= flags;
                peer = one;
                if (other == 0) task->state = 3060;
                else task->state = 3070;
            }
            break;
        case 3060:
        {
            register u32 code asm("r0");
            register u32 low_peer asm("r3");
            register u32 offset asm("r1");
            register struct Packet *base asm("r2");
            register struct Packet *reply asm("r4");
            ((volatile u32)code) = 0xFEF5;
            low_peer = peer;
            offset = ((low_peer << 1) + peer) << 3;
            base = D_03001EEC;
            reply = (struct Packet *)((u32)offset + (u32)base);
            if ((u8)receive_code_word((volatile u32)code, (u16 *)reply))
            {
                task->rejected = 0;
                if ((u8)func_08004C98(task->command, (u16 *)reply))
                    func_08004C44(0xFEF4);
                else
                {
                    task->rejected = 1;
                    func_08004C44(0xFEF3);
                }
                task->state = 3065;
            }
            break;
        }
        case 3065:
            {
            register u32 code asm("r0");
            register u32 low_peer asm("r2");
            register u32 offset asm("r1");
            register struct Packet *base asm("r2");
            register struct Packet *reply asm("r1");
            ((volatile u32)code) = 0xFEF2;
            low_peer = peer;
            offset = ((low_peer << 1) + peer) << 3;
            base = D_03001EEC;
            reply = (struct Packet *)((u32)offset + (u32)base);
            if ((u8)receive_code_word((volatile u32)code, (u16 *)reply))
            {
                register u32 scratch1 asm("r1");
                register u32 scratch2 asm("r2");
                register s32 rejected asm("r0");
                asm("" : "=r"(scratch1), "=r"(scratch2));
                rejected = task->rejected;
                asm("" : "+r"(rejected) : "r"(scratch1), "r"(scratch2));
                if (rejected == 0)
                    task->state = 3100;
                else
                {
                    task->latched = 1;
                    task->busy = 5;
                    task->state = 1000;
                }
            }
            break;
            }
        case 3070:
            func_08004C44(0xFEF5);
            func_08004C74(task->command);
            task->state = 3080;
            break;
        case 3080:
        {
            register u32 code asm("r0");
            register u32 low_peer asm("r2");
            register u32 offset asm("r1");
            register struct Packet *base asm("r2");
            register struct Packet *reply asm("r4");
            ((volatile u32)code) = 0xFEF4;
            low_peer = peer;
            offset = ((low_peer << 1) + peer) << 3;
            base = D_03001EEC;
            reply = (struct Packet *)((u32)offset + (u32)base);
            if ((u8)receive_code_word((volatile u32)code, (u16 *)reply))
            {
                func_08004C44(0xFEF2);
                task->state = 3085;
            }
            else if ((u8)func_08004C80(0xFEF3, (u16 *)reply))
            {
                func_08004C44(0xFEF2);
                task->latched = 1;
                task->busy = 5;
                task->state = 1000;
            }
            break;
        }
        case 3100:
            task->busy = 4;
            {
            register volatile s32 mode asm("r0");
            mode = task->mode;
            switch (mode)
            {
            case 1: task->state = 4000; break;
            case 2: task->state = 7000; break;
            case 3: task->state = 2000; break;
            case 4: task->state = 2900; break;
            default: task->state = 1000; break;
            }
            break;
            }
        case 2900:
            task->active = 1;
            func_08004C44(task->size);
            task->state = 2910;
        case 2910:
            if ((u8)func_08004C80(task->size, (u16 *)&D_03001EEC[peer]) &&
                (u8)func_08004C80(task->size, (u16 *)&D_03001EEC[task->other]))
            {
                task->delay = 0;
                task->state = 2920;
            }
            break;
        case 2920:
            {
                register volatile u32 next asm("r0") = (u16)task->delay + 1;
                task->delay = next;
                if ((s16)next > 7)
            {
                task->busy = 3;
                task->state = 1000;
            }
            }
            break;
        case 2000:
            {
                register void *source asm("r3") = task->source;
                register volatile u32 size asm("r0");
                register void *destination asm("r1");
                register u32 zero asm("r2");
                frame.source = source;
                size = task->size;
                destination = task->destination;
                frame.destination = destination;
                frame.count = func_0805D484(size, 20);
                zero = 0;
                frame.index = zero;
                packet = zero;
            }
            if (task->other == 0) func_08004C44(0xFEFA);
            else func_08004C44(0xFEF9);
            {
                register volatile u32 next asm("r0") = 2050;
                task->state = next;
            }
            break;
        case 2050:
            if (task->other == 0)
            {
                if (D_03001EEC[peer].id == 0xFEF9)
                    task->state = 2100;
            }
            else if (D_03001EEC[peer].id == 0xFEFA)
                task->state = 2500;
            break;
        case 2100:
            task->timer = 0;
            task->state = 2110;
            break;
        case 2110:
            {
                register volatile u32 next asm("r0") = (u16)task->timer + 1;
                task->timer = next;
                if ((s16)next > 1)
                task->state = 2120;
            }
            break;
        case 2120:
            {
            register u32 count asm("r3") = frame.count;
            if (packet >= count)
            {
                D_03001ED4.id = 0xFEFB;
                frame.clear[0] = 0;
                func_0805D270(&frame.clear[0], D_03001ED4.data, 0x0100000A);
                {
                    register u32 completed asm("r0") = packet;
                    D_03001ED4.sum = completed;
                }
                if (task->other == 0) task->state = 2500;
                else task->state = 2700;
            }
            else
            {
                D_03001ED4.id = packet + 1;
                {
                    register union PairRegister low_packet asm("r1");
                    register u32 offset asm("r0");
                    register u8 *source asm("r2");
                    low_packet.wide = packet;
                    offset = (u32)(low_packet.wide << 2) + packet;
                    offset <<= 2;
                    source = frame.source;
                    func_0805D270(source + offset, D_03001ED4.data, 10);
                }
                D_03001ED4.sum = func_08004CE8(D_03001ED4.data, 10);
                task->state = 2200;
            }
            break;
            }
        case 2200:
        {
            register struct Packet *base asm("r3") = D_03001EEC;
            register u32 low_peer asm("r1");
            register u32 offset asm("r2");
            register u32 value asm("r1");
            register u16 *volatile sum_address asm("r0");
            u32 compared;
            low_peer = peer;
            {
                register u32 word asm("r0") = (low_peer << 1) + peer;

                offset = word << 3;
            }
            sum_address = (u16 *)((u32)base + 22);
            sum_address = (u16 *)((u32)offset + (u32)sum_address);
            value = *sum_address;
            compared = packet + 0x80;
            if (value == compared)
            {
                register u16 *id_address asm("r0") = (u16 *)((u32)offset + (u32)base);
                value = *id_address;
                if (value == 0xFEF5)
                {
                    packet = (u16)(packet + 1);
                    task->state = 2120;
                }
                else if (value == 0xFEF6)
                    task->state = 2120;
            }
            break;
        }
        case 2500:
        {
            register struct Packet *reply asm("r5");
            register u32 low_peer asm("r1");
            register u32 offset asm("r4");
            register struct Packet *base asm("r3") = D_03001EEC;
            register u32 value asm("r1");
            received = base;
            low_peer = peer;
            {
                register u32 word asm("r0") = (low_peer << 1) + peer;
                offset = word << 3;
            }
            reply = (struct Packet *)((u32)offset + (u32)base);
            value = reply->id;
            if (value == 0xFEFB)
            {
                if (task->other == 0) task->state = 2700;
                else task->state = 2100;
            }
            else
            {
                u32 bad = (u8)func_08005E5C(reply->id);
                if (bad == 0)
                {
                u32 checksum;
                register u32 address asm("r0");
                register u16 *data asm("r2");
                register union PairRegister length asm("r1");
                register u32 zero asm("r3");
                register u16 *volatile sum_address asm("r1");
                address = (u32)received + 2;
                data = (u16 *)(offset + address);
                address = (u32)data;
                length.parts[1] = (u32)data;
                length.word = 10;
                frame.data = data;
                checksum = checksum_ten_words((u16 *)address, length.word);
                zero = 0;
                asm volatile("" : "+l"(checksum), "+l"(bad) : "r"(zero) : "memory");
                task->timer = checksum;
                sum_address = (u16 *)((u32)received + 22);
                sum_address = (u16 *)((u32)offset + (u32)sum_address);
                checksum = (u16)checksum;
                data = frame.data;
                value = *sum_address;
                if (checksum == value)
                {
                    {
                        register union PairRegister slot asm("r5");
                        register u32 extra asm("r3");
                        register u8 *destination asm("r1");
                        slot.word = reply->id;
                        address = slot.word;
                        address = (u16)(address - 1);
                        frame.index = address;
                        address <<= 2;
                        extra = frame.index;
                        address = (address + extra) << 2;
                        extra = (u32)frame.destination;
                        destination = (u8 *)(extra + address);
                        func_0805D270(data, destination, 10);
                    }
                    output = &D_03001ED4;
                    {
                        register u32 value asm("r0") = 0xFEF5;
                        output->id = value;
                    }
                    clear_address = &frame.clear[1];
                    clear_value = bad;
                    asm("" : "+&l"(clear_value), "+r"(clear_address), "+r"(output) : "r"(task) : "r1", "r2", "r3", "r5");
                    goto clear_reply;
                }
                else
                {
                    output = &D_03001ED4;
                    {
                        register u32 value asm("r0") = 0xFEF6;
                        output->id = value;
                    }
                    clear_address = &frame.clear[2];
                    clear_value = bad;
                    goto clear_reply;
                }
                }
            }
            break;
        }
        case 3085:
            task->state = 3100;
            break;
        case 2700:
            task->timer = 0;
            task->state = 2710;
            break;
        case 2710:
            {
                register volatile u32 next asm("r0") = (u16)task->timer + 1;
                task->timer = next;
                if ((s16)next > 4)
            {
                task->busy = 3;
                task->state = 1000;
            }
            }
            break;
        case 4000:
            frame.source = task->source;
            frame.count = func_0805D484(task->size, 20);
            {
                register u32 zero asm("r1") = 0;
                frame.index = zero;
                packet = zero;
            }
            func_08004C44(0xFEF8);
            task->state = 4050;
            break;
        case 4050:
            {
                register struct Packet *base asm("r1") = D_03001EEC;
                register u32 low_peer asm("r2");
                register u32 offset asm("r0");
                register u32 value asm("r1");
                low_peer = peer;
                offset = ((low_peer << 1) + peer) << 3;
                value = *(u16 *)((u32)offset + (u32)base);
                if (value == 0xFEF7) task->state = 4100;
            }
            break;
        case 4100:
            task->timer = 0;
            task->state = 4110;
            break;
        case 4110:
            {
                register volatile u32 next asm("r0") = (u16)task->timer + 1;
                task->timer = next;
                if ((s16)next > 1)
                task->state = 4120;
            }
            break;
        case 4120:
            {
            register u32 count asm("r3") = frame.count;
            if (packet >= count)
            {
                {
                    register struct Packet *out asm("r4") = &D_03001ED4;
                    register u32 zero asm("r1") = 0;
                    register u32 id asm("r0") = 0xFEFB;
                    register u16 *clear asm("r0");
                    register u16 *volatile destination asm("r1");
                    out->id = id;
                    clear = &frame.clear[2];
                    *clear = zero;
                    destination = out->data;
                        func_0805D270(clear, destination, 0x0100000A);
                    {
                        register u32 completed asm("r0") = packet;
                        out->sum = completed;
                    }
                }
                task->state = 2700;
            }
            else
            {
                D_03001ED4.id = packet + 1;
                {
                    register union PairRegister low_packet asm("r1");
                    register u32 offset asm("r0");
                    register u8 *source asm("r2");
                    low_packet.wide = packet;
                    offset = (u32)(low_packet.wide << 2) + packet;
                    offset <<= 2;
                    source = frame.source;
                    func_0805D270(source + offset, D_03001ED4.data, 10);
                }
                D_03001ED4.sum = func_08004CE8(D_03001ED4.data, 10);
                task->state = 4200;
            }
            break;
            }
        case 4200:
        {
            register struct Packet *base asm("r3") = D_03001EEC;
            register u32 low_peer asm("r1");
            register u32 offset asm("r2");
            register u32 value asm("r1");
            register u16 *volatile sum_address asm("r0");
            u32 compared;
            low_peer = peer;
            {
                register u32 word asm("r0") = (low_peer << 1) + peer;
                offset = word << 3;
            }
            sum_address = (u16 *)((u32)base + 22);
            sum_address = (u16 *)((u32)offset + (u32)sum_address);
            value = *sum_address;
            compared = packet + 0x80;
            if (value == compared)
            {
                register u16 *id_address asm("r0") = (u16 *)((u32)offset + (u32)base);
                value = *id_address;
                if (value == 0xFEF5)
                {
                    packet = (u16)(packet + 1);
                    task->state = 4120;
                }
                else if (value == 0xFEF6)
                    task->state = 4120;
            }
            break;
        }
        case 7000:
            {
                register u8 *source asm("r2") = task->source;
                register u32 zero asm("r3");
                frame.destination = source;
                zero = 0;
                frame.index = zero;
                packet = zero;
            }
            func_08004C44(0xFEF7);
            task->state = 7050;
            break;
        case 7050:
            {
                register struct Packet *base asm("r1") = D_03001EEC;
                register u32 low_peer asm("r2");
                register u32 offset asm("r0");
                register u32 value asm("r1");
                low_peer = peer;
                offset = ((low_peer << 1) + peer) << 3;
                value = *(u16 *)((u32)offset + (u32)base);
                if (value == 0xFEF8) task->state = 7100;
            }
            break;
        case 7100:
        {
            register struct Packet *reply asm("r5");
            register u32 low_peer asm("r1");
            register u32 offset asm("r4");
            register struct Packet *base asm("r3") = D_03001EEC;
            register u32 value asm("r1");
            received = base;
            low_peer = peer;
            {
                register u32 word asm("r0") = (low_peer << 1) + peer;
                offset = word << 3;
            }
            reply = (struct Packet *)((u32)offset + (u32)base);
            value = reply->id;
            if (value == 0xFEFB)
                task->state = 2700;
            else
            {
                u32 bad = (u8)func_08005E5C(reply->id);
                if (bad == 0)
                {
                u32 checksum;
                register u32 address asm("r0");
                register u16 *data asm("r2");
                register union PairRegister length asm("r1");
                register u32 zero asm("r3");
                register u16 *volatile sum_address asm("r1");
                address = (u32)received + 2;
                data = (u16 *)(offset + address);
                address = (u32)data;
                length.parts[1] = (u32)data;
                length.word = 10;
                frame.data = data;
                checksum = checksum_ten_words((u16 *)address, length.word);
                zero = 0;
                asm volatile("" : "+l"(checksum), "+l"(bad) : "r"(zero) : "memory");
                task->timer = checksum;
                sum_address = (u16 *)((u32)received + 22);
                sum_address = (u16 *)((u32)offset + (u32)sum_address);
                checksum = (u16)checksum;
                data = frame.data;
                value = *sum_address;
                if (checksum == value)
                {
                    {
                        register union PairRegister slot asm("r5");
                        register u32 extra asm("r3");
                        register u8 *destination asm("r1");
                        slot.word = reply->id;
                        address = slot.word;
                        address = (u16)(address - 1);
                        frame.index = address;
                        address <<= 2;
                        extra = frame.index;
                        address = (address + extra) << 2;
                        extra = (u32)frame.destination;
                        destination = (u8 *)(extra + address);
                        func_0805D270(data, destination, 10);
                    }
                    output = &D_03001ED4;
                    {
                        register u32 value asm("r0") = 0xFEF5;
                        output->id = value;
                    }
                    clear_address = &frame.clear[1];
                    clear_value = bad;
                    goto clear_reply;
                }
                else
                {
                    output = &D_03001ED4;
                    {
                        register u32 value asm("r0") = 0xFEF6;
                        output->id = value;
                    }
                    clear_address = &frame.clear[3];
                    clear_value = bad;
                    goto clear_reply;
                }
                }
            }
            break;
        }
        clear_reply:
            *clear_address = clear_value;
            {
                register u16 *volatile destination asm("r1") = output->data;
                func_0805D270(clear_address, destination, 0x0100000A);
            }
            output->sum = frame.index + 0x80;
            break;
        }
        task->message = 0;
        task->error = 0;
        if (D_03001F4C & 0x2000)
        {
            task->error = 2;
            task->busy = 0xFE;
        }
        else if (D_03001F4C & 0x1000)
        {
            task->error = 1;
            task->busy = 0xFC;
        }
        if (task->error != 0)
        {
            register u32 scratch2 asm("r2");
            register u32 scratch3 asm("r3");
            register s32 latched asm("r0");
            asm("" : "=r"(scratch2), "=r"(scratch3));
            latched = task->latched;
            asm("" : "+r"(latched) : "r"(scratch2), "r"(scratch3));
            if (latched == 0)
            {
                task->latched = 1;
                task->state = 9500;
            }
        }
        func_0805EE78(1);
    }
}

void func_08005670(void)
{
    u8 i;
    for (i = 0; i < 4; i++)
    {
        u8 slot = D_08666C9C[i];
        if (D_02000034[slot].flags & 2)
            func_08003E3C(slot);
    }
}
