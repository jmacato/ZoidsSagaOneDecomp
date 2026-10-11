#include "types.h"

struct Task2FF
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[2];
    u32 argument;
    u32 argument2;
    u32 argument3;
    u32 command;
    u32 reply;
    u8 choice;
    u8 pad_1D[3];
    u8 choice2;
    u8 pad_21[3];
    u8 choice3;
    u8 pad_25[3];
    u32 result;
    u32 pass;
    u8 pad_30[0x58];
};
struct Unit2FF
{
    u16 state;
    u8 pad_2[6];
    u16 flags;
    u8 pad_A[0x38];
    u8 portrait;
    u8 pad_43[0xB1];
    u8 side;
};
struct Copy2FF { u32 words[9]; };
extern u8 D_02000030;
extern struct Task2FF D_02000034[];
extern u8 D_0200EB84[];
extern u8 D_02010D6C;
extern u16 D_02007574[];
extern u32 D_020002E4;
extern u32 D_0200036C;
extern u32 D_02000514;
extern u32 D_02000590;
extern u32 D_0200059C;
extern u32 D_03004B9C[];
extern const u32 D_08663D44[];
extern const u8 D_08675BEC[];
extern const u8 D_08675B68[];
extern const u8 D_08675C5C[];
extern struct Copy2FF D_02004A70;
extern const struct Copy2FF D_0866B3A8;
void func_08003DF8(u32, void (*)(void));
void func_08003E3C(u32);
void func_0803E488(const void *, u32);
void func_0805D270(const void *, void *, u32);
void func_0805EE78(u32);
void func_080329E4(u32, u32, u32, u32);
void func_080355D0(void);
void func_08030FFC(void);
void func_0802B528(void);
void func_08000DB8(void);
void func_0802F07C(void);
void func_08033718(void);
void func_080338A8(u32);
void func_08033D6C(void);
void func_0802FA58(void);
void func_08000D1C(u32);
void func_080317D0(void);
void func_0802FA6C(void);
void func_08032684(void);
void func_0802FA94(void);
void func_0802F5B8(void);
void func_08032410(void);
void func_08033D94(u32);
struct Unit2FF *func_0802B504(u32, u32);
void func_0802F8AC(struct Unit2FF *);
void func_08031598(u32);
void func_0802BBC8(void);
void func_080339C4(struct Unit2FF *);
void func_08004018(void);
u32 func_0802FA3C(void);
void func_08001DE4(u32);
void func_08031074(void);
void func_08031C64(void);
void func_08031618(struct Unit2FF *, u32);
void func_0802F8E8(void);
void func_0802F5C4(void);
void func_0802F04C(void);
void func_0802E9CC(void);
void func_0802F8F8(void);
void func_08034AA0(void);
void func_08034738(void);
void func_08004034(void);
void func_0802F09C(void);
void func_0802FD4C(void);
void func_08034D04(void);
void func_08034F24(void);
void func_0802FAA8(void);
void func_0802E814(void);
void func_0802E9C0(void);
void func_0803520C(void);
void func_0802BC98(void);
void func_0802BCA4(void);
void func_08038F30(void);
void func_080355FC(void);
void func_0803B73C(void);
void func_08035778(void);
void func_08030FD0(void);

void func_0802FF5C(void)
{
    register struct Task2FF *task asm("r5") = ({
        register u32 scaled asm("r0");
        struct Task2FF *selected_task;
        { register u32 selected asm("r1") = D_02000030;
          scaled = selected * 136; asm("" : : "r"(selected), "r"(scaled)); }
        { register struct Task2FF *base asm("r1") = D_02000034;
          asm("" : : "r"(scaled), "r"(base));
          selected_task = (struct Task2FF *)(scaled + (u32)base); }
        selected_task;
    });
    register u32 *reply asm("sb") = ({
        register u32 base asm("r0") = (u32)D_02000034;
        register u32 offset asm("r1") = 704;
        asm("" : : "r"(base), "r"(offset));
        base += offset; asm("" : : "r"(base)); (u32 *)base;
    });
    register struct Unit2FF *unit asm("sl");
    struct { vu16 zero; u16 pad; vu32 choice; vu32 response; } storage;
    u32 slot;
    u32 side;
    for (;;)
    {
        register s32 state asm("r1");
        { register u32 held asm("r0");
          asm volatile("" : "=r"(held));
          state=task->state; asm("" : "+r"(state) : "r"(held)); }
        switch (state)
        {
        case 0:
            { register vu16 *field asm("r0")=(vu16 *)&storage;
              register u32 zero asm("r4");
              asm("" : : "r"(field)); zero=0; asm("" : : "r"(zero)); *field=zero;
              func_0805D270((const void *)field,D_0200EB84,0x010015F6); }
            *(u16 *)D_0200EB84 |= 0x20;
            func_080355D0();
            func_08030FFC();
            func_08030FD0();
            func_0802B528();
            func_08000DB8();
            func_0802F07C();
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=1000; task->state=(u32 volatile)next_state; }
            break;
        case 1000:
            func_08003DF8(5, func_0802E9CC);
            func_08003DF8(8, func_0802F8F8);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=1010; task->state=(u32 volatile)next_state; }
            break;
        case 1010:
            if (({ register u32 *reply_address asm("r1")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=1200; task->state=(u32 volatile)next_state; }
            break;
        case 1200:
            func_08033718();
            func_080338A8(0);
        case 1205:
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675B68, 15);
            func_0803E488(D_08675BEC, 5);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=1208; task->state=(u32 volatile)next_state; }
            break;
        case 1208:
            func_08003DF8(5, func_08034AA0);
            { register u32 argument_value asm("r0")=0xFD01; register u32 *argument asm("r2")=&D_020002E4; *argument=argument_value; }
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=1210; task->state=(u32 volatile)next_state; }
            break;
        case 1210:
            if (({ register u32 *reply_address asm("r3")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=1300; task->state=(u32 volatile)next_state; }
            break;
        case 1300:
            func_08003DF8(5, func_08034738);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=1310; task->state=(u32 volatile)next_state; }
            break;
        case 1310:
        {
            register u32 value asm("r0");
            value = ({ register u32 *reply_address asm("r4")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; });
            if (value == 1)
            {
                func_08003E3C(5);
                func_08033D6C();
                { register u32 next_state asm("r0"); ((u32 volatile)next_state)=1350; task->state=(u32 volatile)next_state; }
                break;
            }
            if (value != 2) goto yield;
            func_08003E3C(5);
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675B68, 32);
            func_0803E488(D_08675BEC, 5);
            func_0803E488(D_08675BEC, 20);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=1205; task->state=(u32 volatile)next_state; }
            break;
        }
        case 1350:
            func_08003DF8(10, func_08004034);
            {
                register struct Task2FF *base asm("r1");
                register u32 offset asm("r2");
                register u32 *argument asm("r0");
                register u32 value asm("r1");
                ((struct Task2FF *volatile)base)=D_02000034;
                ((u32 volatile)offset)=1368;
                asm("" : : "r"(base), "r"(offset));
                argument=(u32 *)((u8 *)base+offset);

                value=1; *argument=value;
            }
            { register u32 zero asm("r0")=0;
              register u32 *field asm("r3");
              field=&D_02000590;
              *field=zero; }
            { register u32 next_state asm("r4")=1360; task->state=next_state; }
            break;
        case 1360:
            if (({ register u32 *field asm("r4"); ((u32 *volatile)field)=&D_0200059C; *((u32 *volatile)field); }) != 1) goto yield;
            func_0802FA58();
            func_08003E3C(10);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=1400; task->state=(u32 volatile)next_state; }
            break;
        case 1400:
            func_08000D1C(0);
            func_080317D0();
            func_0802FA6C();
            func_08003DF8(10, func_08004034);
            {
                register struct Task2FF *base asm("r0");
                register u32 offset asm("r2");
                register u32 *argument asm("r1");
                register u32 value asm("r0");
                ((struct Task2FF *volatile)base)=D_02000034;
                ((u32 volatile)offset)=1368;
                asm("" : : "r"(base), "r"(offset));
                argument=(u32 *)((u8 *)base+offset);

                value=0; *argument=value;
            }
            { register u32 zero asm("r0")=0;
              register u32 *field asm("r3");
              field=&D_02000590;
              *field=zero; }
            { register u32 next_state asm("r6")=1410; task->state=next_state; }
            break;
        case 1410:
            if (({ register u32 *field asm("r4"); ((u32 *volatile)field)=&D_0200059C; *((u32 *volatile)field); }) != 1) goto yield;
            func_08003E3C(10);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=1900; task->state=(u32 volatile)next_state; }
            break;
        case 1900:
            func_08032684();
            if (({ register u8 *field asm("r1")=&D_02010D6C; asm("" : : "r"(field)); *field; }) != 0)
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=9000; task->state=(u32 volatile)next_state; }
            else
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=7000; task->state=(u32 volatile)next_state; }
            break;
        case 2000:
            func_0802FA94();
            func_0802F5B8();
            func_08003DF8(5, func_0802F09C);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=2010; task->state=(u32 volatile)next_state; }
            break;
        case 2010:
            if (({ register u32 *reply_address asm("r2")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=2300; task->state=(u32 volatile)next_state; }
            break;
        case 2300:
            func_08003DF8(5, func_0802FD4C);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=2310; task->state=(u32 volatile)next_state; }
            break;
        case 2310:
            if (({ register u32 *reply_address asm("r3")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=2500; task->state=(u32 volatile)next_state; }
            break;
        case 2500:
            func_08032410();
            func_08003DF8(5, func_08034AA0);
            { register u32 argument_value asm("r0")=0xFD02; register u32 *argument asm("r1")=&D_020002E4; *argument=argument_value; }
            { register u32 next_state asm("r4")=2510; task->state=next_state; }
            break;
        case 2510:
            if (({ register u32 *reply_address asm("r2")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=2600; task->state=(u32 volatile)next_state; }
            break;
        case 2600:
            func_08003DF8(5, func_08034D04);
            { register u32 next_state asm("r6")=2610; task->state=next_state; }
            break;
        case 2610:
            if (({ register u32 *reply_address asm("r3")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3000; task->state=(u32 volatile)next_state; }
            break;
        case 3000:
        {
            register u32 value asm("r0");
            func_08033D94(100);
            func_0802FA94();
            { register u32 base asm("r2")=(u32)D_0200EB84;
              register u32 turn asm("r1");
              register u32 offset asm("r1")=0x21B5;
              register u32 selected_side asm("r0");
              (void)((u32 volatile)base); (void)((u32 volatile)offset);
              { register u32 address asm("r0")=base+offset; (void)((u32 volatile)address); turn=*(u8 *)address; }
              turn=turn*4+base;
              { register u32 side_offset asm("r2")=0x21B8;
                (void)((u32 volatile)turn); (void)((u32 volatile)side_offset);
                { register u32 address asm("r0")=turn+side_offset; (void)((u32 volatile)address); selected_side=*(u8 *)address; } }
              (void)((u32 volatile)selected_side); (void)((u32 volatile)turn);
              { register u32 slot_offset asm("r3")=0x21B9;
                asm("" : : "r"(selected_side), "r"(turn), "r"(slot_offset));
                turn=*(u8 *)(turn+slot_offset); }
              unit=func_0802B504(selected_side,turn); }
            func_0802F8AC(unit);
            func_08003DF8(5, func_08034AA0);
            { register u32 argument_value asm("r0")=0xFD03; register u32 *argument asm("r1")=&D_020002E4; *argument=argument_value; }
            { register u32 next_state asm("r4")=3010; task->state=next_state; }
            break;
        }
        case 3010:
            if (({ register u32 *reply_address asm("r2")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3014; task->state=(u32 volatile)next_state; }
            break;
        case 3014:
            func_08003DF8(5, func_08034F24);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3018; task->state=(u32 volatile)next_state; }
            break;
        case 3018:
        {
            register struct Task2FF *task_base asm("r6")=D_02000034;
            register u32 value asm("r4");
            (void)((u32 volatile)task_base);
            value=({ register u32 *field asm("r3"); ((u32 *volatile)field)=reply; *((u32 *volatile)field); });
            ((u32 volatile)value)=(u32 volatile)value;
            if (value != 1) goto yield;
            ((u32 volatile)value)=(u32 volatile)value;
            func_08003E3C(5);
            func_08003DF8(5,func_0802FAA8);
            { register u32 *field asm("r0")=&D_020002E4; *field=value; }
            { register u32 offset asm("r2")=692;
              register u32 *field asm("r1");
              register u32 argument asm("r0");
              asm("" : "+r"(offset) : "r"(task_base));
              field=(u32 *)((u8 *)task_base+offset); (void)((u32 volatile)field);
              argument=task->argument; *field=argument; }
            { register u32 next_state asm("r7")=3030; task->state=next_state; }
            break;
        }
        case 3030:
            if (({ register u32 *reply_address asm("r3")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r4")=3050; task->state=next_state; }
            break;
        case 3050:
        {
            register u32 flags asm("r2")=({ register u32 matched_state asm("r3")=3050; asm("" : : "r"(matched_state)); unit->flags; }); (void)((u32 volatile)flags);
            if (({ register u32 mask asm("r1")=0x2000; register u32 value asm("r0"); (void)((u32 volatile)mask); value=mask&flags; value; })) { { register u32 next_state asm("r0"); ((u32 volatile)next_state)=6000; task->state=(u32 volatile)next_state; } break; }
            if ((({ register struct Unit2FF *field asm("r3")=unit; register u32 bits asm("r1"); (void)((u32 volatile)field); bits=field->state; bits&1; })) || (({ register u32 mask asm("r4")=0x4000; register u32 value asm("r0"); (void)((u32 volatile)mask); value=mask&flags; value; }))) { { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3800; task->state=(u32 volatile)next_state; } break; }
            if (unit->side == 0) func_08031598(unit->portrait);
            func_08003DF8(5, func_0802E814);
            func_08003DF8(6, func_0802E9C0);
            { register u32 value asm("r0")=(u32)unit;
              register u32 *first asm("r1");
              register u32 *second asm("r2");
              (void)((u32 volatile)value); first=&D_020002E4; *first=value;
              second=&D_0200036C; *second=value; }
            { register u32 next_state asm("r6")=3100; task->state=next_state; }
            break;
        }
        case 3100:
        {
            register struct Task2FF *base asm("r1")=D_02000034;
            register u32 value asm("r0");
            (void)((u32 volatile)base);
            value=({ register u32 *field asm("r3"); ((u32 *volatile)field)=reply; *((u32 *volatile)field); });
            if (value == 0) goto yield;
            storage.response=(u8)value;
            { register u32 offset asm("r4")=708;
              register u8 *field asm("r0");
              asm("" : "+r"(offset) : "r"(base));
              field=(u8 *)base+offset; (void)((u32 volatile)field);
              storage.choice=*field; }
            func_08003E3C(5);
            func_08003E3C(6);
            if (storage.response == 1)
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3200; task->state=(u32 volatile)next_state; }
            else
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3500; task->state=(u32 volatile)next_state; }
            func_0802BBC8();
            goto yield;
        }
        case 3200:
            if (({ register u32 choice asm("r1")=storage.choice; (void)((u32 volatile)choice); choice; }) == 0) { { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3700; task->state=(u32 volatile)next_state; } break; }
            func_08003DF8(5, func_08034AA0);
            { register u32 argument_value asm("r0")=0xFD07; register u32 *argument asm("r2")=&D_020002E4; *argument=argument_value; }
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3210; task->state=(u32 volatile)next_state; }
            break;
        case 3210:
            if (({ register u32 *reply_address asm("r3")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r4")=3300; task->state=next_state; }
            break;
        case 3300:
            func_08003DF8(5, func_0803520C);
            { register u32 argument_value asm("r4")=storage.response; register u32 *argument asm("r0")=&D_020002E4; *argument=argument_value; }
            { register struct Task2FF *base asm("r1")=D_02000034;
              register u32 offset asm("r2")=692;
              register u32 *field asm("r0");
              register u32 choice asm("r3");
              asm("" : "+r"(offset) : "r"(base));
              field=(u32 *)((u8 *)base+offset); (void)((u32 volatile)field);
              choice=storage.choice; *field=choice; }
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3310; task->state=(u32 volatile)next_state; }
            break;
        case 3310:
            if (({ register u32 *reply_address asm("r4")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            task->state = 3700;
            func_08003E3C(5);
            goto yield;
        case 3500:
            func_08003DF8(5, func_08034AA0);
            { register u32 argument_value asm("r0")=0xFD07; register u32 *argument asm("r1")=&D_020002E4; *argument=argument_value; }
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3510; task->state=(u32 volatile)next_state; }
            break;
        case 3510:
            if (({ register u32 *reply_address asm("r2")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3600; task->state=(u32 volatile)next_state; }
            break;
        case 3600:
            func_08003DF8(5, func_0803520C);
            { register u32 argument_value asm("r3")=storage.response; register u32 *argument asm("r4")=&D_020002E4; *argument=argument_value; }
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3610; task->state=(u32 volatile)next_state; }
            break;
        case 3610:
        {
            register struct Task2FF *base asm("r1")=D_02000034; (void)((u32 volatile)base);
            if (({ register u32 *reply_address asm("r2")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            { register u32 offset asm("r3")=708;
              register u8 *field asm("r0");
              asm("" : "+r"(offset) : "r"(base));
              field=(u8 *)base+offset; (void)((u32 volatile)field);
              storage.choice=*field; }
            func_08003E3C(5);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3700; task->state=(u32 volatile)next_state; }
            break;
        }
        case 3700:
        {
            register s32 choice asm("r4")=storage.choice;
            (void)((u32 volatile)choice);
            if (choice == 1) goto choice_one;
            if (choice > 1) goto choice_two;
            if (choice == 0) goto choice_zero;
            goto yield;
        choice_two:
            { register s32 value asm("r0")=storage.choice;
              (void)((u32 volatile)value); if (value == 2) goto choice_two_state; }
            goto yield;
        choice_zero:
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=4000; task->state=(u32 volatile)next_state; }
            break;
        choice_two_state:
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=5500; task->state=(u32 volatile)next_state; }
            break;
        choice_one:
            task->state=4500;
            break;
        }
        case 3800:
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_080339C4(unit);
            func_0803E488(D_08675C5C, 32);
            func_0803E488(D_08675BEC, 5);
            func_08004018();
            task->state = 3810;
        case 3810:
            if (({ register u32 *field asm("r1"); ((u32 *volatile)field)=&D_02000514; *((u32 *volatile)field); }) != 1) goto yield;
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=6000; task->state=(u32 volatile)next_state; }
            break;
        case 4000:
            func_08003DF8(10, func_08004034);
            {
                register struct Task2FF *base asm("r2");
                register u32 offset asm("r3");
                register u32 *argument asm("r1");
                register u32 value asm("r0");
                ((struct Task2FF *volatile)base)=D_02000034;
                ((u32 volatile)offset)=1368;
                asm("" : : "r"(base), "r"(offset));
                argument=(u32 *)((u8 *)base+offset);

                value=1; *argument=value;
            }
            { register u32 zero asm("r0")=0;
              register u32 *field asm("r4");
              field=&D_02000590;
              *field=zero; }
            task->result = func_0802FA3C();
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=4100; task->state=(u32 volatile)next_state; }
            break;
        case 4100:
            if (({ register u32 *field asm("r1"); ((u32 *volatile)field)=&D_0200059C; *((u32 *volatile)field); }) != 1) goto yield;
            func_08003E3C(10);
            func_08003DF8(5, func_0802BC98);
            { register u32 next_state asm("r4")=4300; task->state=next_state; }
            break;
        case 4300:
        {
            register u32 value asm("r0");
            value = ({ register u32 *reply_address asm("r2")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; });
            if (value == 1)
            {
                func_08003E3C(5);
                { register u32 next_state asm("r0"); ((u32 volatile)next_state)=5000; task->state=(u32 volatile)next_state; }
                break;
            }
            if (value != 2) goto yield;
            func_08003E3C(5);
            func_08003DF8(8, func_0802F8F8);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=4400; task->state=(u32 volatile)next_state; }
            break;
        }
        case 4400:
            func_08000DB8();
            func_08000D1C(0);
            func_08001DE4(D_08663D44[24]);
            func_08031074();
            func_080317D0();
            D_03004B9C[5] = 0xFFF40000;
            func_0802F07C();
            func_0803E488(D_08675BEC, 2);
            func_08003DF8(8, func_0802F8F8);
            func_08003DF8(10, func_08004034);
            {
                register struct Task2FF *base asm("r3");
                register u32 offset asm("r4");
                register u32 *argument asm("r1");
                register u32 value asm("r0");
                ((struct Task2FF *volatile)base)=D_02000034;
                ((u32 volatile)offset)=1368;
                asm("" : : "r"(base), "r"(offset));
                argument=(u32 *)((u8 *)base+offset);

                value=0; *argument=value;
            }
            { register u32 zero asm("r0")=0;
              register u32 *field asm("r1");
              field=&D_02000590;
              *field=zero; }
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=4410; task->state=(u32 volatile)next_state; }
            break;
        case 4410:
            if (({ register u32 *field asm("r2"); ((u32 *volatile)field)=&D_0200059C; *((u32 *volatile)field); }) != 1) goto yield;
            func_08003E3C(10);
            { register u32 next_state asm("r3")=3050; task->state=next_state; }
            break;
        case 4500:
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_080339C4(unit);
            func_0803E488(D_08675C5C, 26);
            func_0803E488(D_08675BEC, 5);
            { register struct Unit2FF *field asm("r4")=unit;
              register u32 flags asm("r0");
              register u32 mask asm("r2");
              register u32 value asm("r1");
              asm("" : : "r"(field)); flags=field->flags; asm("" : : "r"(flags));
              mask=0x100; asm("" : : "r"(mask)); value=mask;
              asm("" : : "r"(value)); flags|=value; field->flags=flags; }
            func_08004018();
            task->state = 4510;
        case 4510:
            if (({ register u32 *field asm("r3"); ((u32 *volatile)field)=&D_02000514; *((u32 *volatile)field); }) != 1) goto yield;
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=6000; task->state=(u32 volatile)next_state; }
            break;
        case 5000:
            func_08003DF8(5, func_0802BCA4);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=5100; task->state=(u32 volatile)next_state; }
            break;
        case 5100:
            if (({ register u32 *reply_address asm("r4")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            func_08003DF8(8, func_0802F8F8);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=6000; task->state=(u32 volatile)next_state; }
            break;
        case 5500:
            func_08003DF8(5, func_08038F30);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=5600; task->state=(u32 volatile)next_state; }
            break;
        case 5600:
        {
            register u32 value asm("r0");
            value = ({ register u32 *reply_address asm("r1")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; });
            if (value == 1)
            {
                func_08003E3C(5);
                func_08031C64();
                { register u32 next_state asm("r4")=6000; task->state=next_state; }
                break;
            }
            if (value != 2) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r2")=3050; task->state=next_state; }
            break;
        }
        case 6000:
            if (unit->side == 0)
            {
                func_08031618(unit, 16);
                func_08031598(unit->portrait);
            }
            func_0802FA94();
            func_0802F8E8();
            func_08032684();
            {
                register u32 base asm("r1")=(u32)D_0200EB84;
                register u8 *mode_field asm("r4")=&D_02010D6C;
                register u32 mode asm("r3");
                asm("" : : "r"(base), "r"(mode_field));
                mode=*mode_field; asm("" : : "r"(mode));
                if (mode)
                { register u32 next_state asm("r0"); ((u32 volatile)next_state)=9000; task->state=(u32 volatile)next_state; }
                else
                {
                    register u32 index asm("r0")=0x21B5;
                    register u8 *pointer asm("r2");
                    register u32 count_offset asm("r4");
                    pointer=(u8 *)(base+index);
                    index=*pointer; ++index; *pointer=index;
                    count_offset=0x21B4;
                    base+=count_offset;
                    asm("" : "+r"(base) : "r"(count_offset), "r"(index), "r"(pointer), "r"(mode));
                    base=*(u8 *)base;
                    if ((u8)index >= base)
                    {
                        *pointer=mode;
                        func_0802F5C4();
                        { register u32 next_state asm("r0"); ((u32 volatile)next_state)=7000; task->state=(u32 volatile)next_state; }
                    }
                    else
                    { register u32 next_state asm("r0"); ((u32 volatile)next_state)=3000; task->state=(u32 volatile)next_state; }
                }
            }
            break;
        case 7000:
            func_08031C64();
            task->pass = 0;
        case 7100:
            task->pass++;
        case 7150:
            switch ((s32)task->pass)
            {
            case 1: { register u32 next_state asm("r0"); ((u32 volatile)next_state)=task->argument == 0 ? 8000 : 7500; task->state=(u32 volatile)next_state; } break;
            case 2: { register u32 next_state asm("r0"); ((u32 volatile)next_state)=task->argument == 0 ? 7500 : 8000; task->state=(u32 volatile)next_state; } break;
            case 3: { register u32 next_state asm("r0"); ((u32 volatile)next_state)=2000; task->state=(u32 volatile)next_state; } break;
            default: { register u32 next_state asm("r0"); ((u32 volatile)next_state)=2000; task->state=(u32 volatile)next_state; } break;
            }
            break;
        case 7500:
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675B68, 23);
            func_0803E488(D_08675B68, 22);
            func_0803E488(D_08675BEC, 5);
            { register u32 next_state asm("r6")=7505; task->state=next_state; }
            break;
        case 7505:
            func_08003DF8(5, func_08034AA0);
            { register u32 argument_value asm("r0")=0xFD0A; register u32 *argument asm("r1")=&D_020002E4; *argument=argument_value; }
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=7510; task->state=(u32 volatile)next_state; }
            break;
        case 7510:
            if (({ register u32 *reply_address asm("r2")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r4")=7600; task->state=next_state; }
            break;
        case 7600:
            func_08003DF8(5, func_080355FC);
            { register u32 argument_value asm("r0")=2; register u32 *argument asm("r3")=&D_020002E4; *argument=argument_value; }
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=7610; task->state=(u32 volatile)next_state; }
            break;
        case 7610:
        {
            register u8 *task_base asm("r4")=(u8 *)D_02000034;
            register u32 value asm("r8");
            register u32 slot asm("r7");
            register u32 side asm("r6");
            (void)((u32 volatile)task_base);
            {
                register u32 *response asm("r0")=reply;
                register u32 loaded asm("r0");
                (void)((u32 volatile)response); loaded=*response;
                value=loaded;
                (void)((u32 volatile)loaded); (void)((u32 volatile)value);
                if (loaded != 1) goto yield;
            }
            {
                register u32 offset asm("r1")=708;
                register u8 *address asm("r0");
                asm("" : "+r"(offset) : "r"(task_base));
                ((u8 *volatile)address)=task_base+offset;
                storage.choice=*(u8 *volatile)address;
            }
            {
                register u32 offset asm("r2")=712;
                register u8 *address asm("r0");
                asm("" : "+r"(offset));
                ((u8 *volatile)address)=task_base+offset;
                ((u32 volatile)slot)=*(u8 *volatile)address;
            }
            {
                register u32 offset asm("r3")=716;
                register u8 *address asm("r0");
                asm("" : "+r"(offset));
                ((u8 *volatile)address)=task_base+offset;
                ((u32 volatile)side)=*(u8 *volatile)address;
            }
            func_08003E3C(5);
            if (storage.choice == 0)
            {
                register u32 next_state asm("r0")=7100;
                (void)((u32 volatile)next_state); task->state=next_state;
                break;
            }
            func_08003DF8(5, func_0803B73C);
            {
                register u32 held_value asm("r1")=value;
                register u32 *address asm("r2")=&D_02000034[5].argument;
                asm("" : : "r"(held_value), "r"(address)); *address=held_value;
            }
            {
                register u32 offset asm("r3")=692;
                register u32 *address asm("r0");
                asm("" : "+r"(offset)); ((u32 *volatile)address)=(u32 *)(task_base+offset);
                *(u32 *volatile)address=slot;
            }
            {
                register u32 offset asm("r1")=696;
                register u32 *address asm("r0");
                asm("" : "+r"(offset)); ((u32 *volatile)address)=(u32 *)(task_base+offset);
                *(u32 *volatile)address=side;
            }
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=8100; task->state=(u32 volatile)next_state; }
            break;
        }
        case 8000:
            func_0803E488(D_08675BEC, 6);
            func_0803E488(D_08675BEC, 7);
            func_0803E488(D_08675C5C, 52);
            func_0803E488(D_08675BEC, 5);
            func_0803E488(D_08675BEC, 25);
            switch ((u32)D_02007574[1])
            {
            case 0: task->state=8500; break;
            case 1: { register u32 next_state asm("r0"); ((u32 volatile)next_state)=8050; task->state=(u32 volatile)next_state; } break;
            case 2:
                func_0802F04C();
                func_08032684();
                { register u32 next_state asm("r0"); ((u32 volatile)next_state)=9000; task->state=(u32 volatile)next_state; }
                break;
            default: goto yield;
            }
            break;
        case 8050:
            func_08003DF8(5, func_0803B73C);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=8100; task->state=(u32 volatile)next_state; }
            break;
        case 8100:
        {
            register u32 value asm("r0");
            value = ({ register u32 *reply_address asm("r2")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; });
            if (value == 1)
            {
                func_08003E3C(5);
                { register u32 next_state asm("r0"); ((u32 volatile)next_state)=7100; task->state=(u32 volatile)next_state; }
                break;
            }
            if (value != 2) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=7150; task->state=(u32 volatile)next_state; }
            break;
        }
        case 8500:
            func_08003DF8(5, func_08034AA0);
            { register u32 argument_value asm("r0")=0xFD0A; register u32 *argument asm("r3")=&D_020002E4; *argument=argument_value; }
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=8510; task->state=(u32 volatile)next_state; }
            break;
        case 8510:
            if (({ register u32 *reply_address asm("r1")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r4")=8600; task->state=next_state; }
            break;
        case 8600:
            func_08003DF8(5, func_080355FC);
            {
                register u32 one asm("r0")=1;
                register u32 *argument asm("r2")=&D_02000034[5].argument;
                 *argument=one;
            }
            {
                register u8 *base asm("r3")=(u8 *)D_02000034;
                register u32 offset asm("r4")=692;
                register u32 *address asm("r0");
                register u32 zero asm("r1");
                asm("" : "+r"(offset) : "r"(base));
                address=(u32 *)(base+offset);
                zero=0;  *address=zero;
                {
                    register u32 field_offset asm("r2")=696;
                    asm("" : "+r"(field_offset) : "r"(zero));
                    address=(u32 *)(base+field_offset);
                    *address=zero;
                }
                {
                    register u32 *command asm("r3")=&D_02000034[5].command;
                     *command=zero;
                }
            }
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=8610; task->state=(u32 volatile)next_state; }
            break;
        case 8610:
            if (({ register u32 *reply_address asm("r4")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            task->state = 7100;
            func_08003E3C(5);
            goto yield;
        case 9000:
            func_0802FA94();
            func_08003DF8(5, func_08035778);
            { register u32 next_state asm("r6")=9100; task->state=next_state; }
            break;
        case 9100:
            if (({ register u32 *reply_address asm("r1")=reply; register u32 reply_value asm("r0")=*reply_address; reply_value; }) != 1) goto yield;
            func_08003E3C(5);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=9500; task->state=(u32 volatile)next_state; }
            break;
        case 9500:
            func_08003DF8(10, func_08004034);
            {
                register struct Task2FF *base asm("r2");
                register u32 offset asm("r3");
                register u32 *argument asm("r0");
                register u32 value asm("r1");
                ((struct Task2FF *volatile)base)=D_02000034;
                ((u32 volatile)offset)=1368;
                asm("" : : "r"(base), "r"(offset));
                argument=(u32 *)((u8 *)base+offset);

                value=1; *argument=value;
            }
            { register u32 zero asm("r0")=0;
              register u32 *field asm("r1");
              field=&D_02000590;
              *field=zero; }
            task->state = 9510;
        case 9510:
            if (({ register u32 *field asm("r2"); ((u32 *volatile)field)=&D_0200059C; *((u32 *volatile)field); }) != 1) goto yield;
            func_08003E3C(10);
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=9520; task->state=(u32 volatile)next_state; }
            break;
        case 9520:
            func_0802FA3C();
            func_0803E488(D_08675BEC, 1);
            task->reply = 1;
            { register u32 next_state asm("r0"); ((u32 volatile)next_state)=9900; task->state=(u32 volatile)next_state; }
            break;
        case 9900:
            goto yield;
        default:
            goto yield;
        }
    yield:
        func_0805EE78(1);
    }
}

void func_08030FD0(void)
{
    D_02004A70 = D_0866B3A8;
    func_080329E4(0, 0, 12, 12);
}
