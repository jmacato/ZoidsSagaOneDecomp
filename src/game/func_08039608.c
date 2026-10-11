#include "types.h"

struct Task396
{
    u8 pad_0[4];
    s16 state;
    u8 pad_6[0x12];
    u32 reply;
    u8 pad_1C[0xC];
    u32 selection;
    u32 value;
    u8 pad_30[0x58];
};
struct Block396 { u32 words[7]; };
extern u8 D_02000030;
extern struct Task396 D_02000034[];
extern u8 D_02000B5C[];
extern u16 D_02007574[];
extern u32 D_030022FC;
extern const u32 D_08663D44[];
extern const u8 D_08675BEC[];
extern const u8 D_08675E08[];
extern const u8 D_08675C5C[];
extern const u8 D_08675DD4[];
extern const struct Block396 D_086764A4;
extern u8 D_02003E61[];
extern u8 D_02003FD7[];
extern u8 D_02004A68[];
extern u8 D_02004178[];
void func_08059380(u32);
void func_08000DB8(void);
void func_08000D1C(u32);
void func_08001DE4(u32);
void func_0802F07C(void);
void func_08003DF8(u32, void (*)(void));
void func_08003E3C(u32);
void func_08004034(void);
void func_080592F0(void);
void func_0803E488(const void *, u32);
void func_08001848(u32, u32, u32);
void func_0805354C(u32, u32, u32);
void func_08036A98(u32, void *, u32);
void func_0803AF4C(u32);
void func_0803AE6C(void);
void func_0803AED4(void);
void func_0802AC0C(void);
void func_0805EE78(u32);
void func_08003948(void);
void func_0803AD38(void);

#define STATE396(number) do { register u32 next_state asm("r0"); ((u32 volatile)next_state)=(number); task->state=(u32 volatile)next_state; } while (0)
#define EDIT396(command) \
    func_0803E488(D_08675BEC,7); \
    func_0803E488(D_08675BEC,5); \
    func_0803E488(D_08675E08,command); \
    func_0803E488(D_08675BEC,5)
#define STATFIELD396(type, constant, reg) ({ \
    register u32 index asm("r1"); \
    register u32 address asm("r0"); \
    register u32 field_offset asm(reg); \
    index=*selector; \
    ((u32 volatile)address)=index*572; \
    ((u32 volatile)address)=(u32 volatile)address+(u32)save; \
    ((u32 volatile)field_offset)=(constant); \
    if ((reg)[1]!='1') asm("" : : "r"(address), "r"(field_offset)); \
    *(type *)((u32 volatile)address+(u32 volatile)field_offset); })
#define STAT396(command, hp_offset, level_offset) \
    func_0803E488(stat_menu,command); \
    func_08001848(STATFIELD396(u16,hp_offset,"r1"),3,0); \
    func_0803E488(numbers,31); \
    func_08001848(STATFIELD396(u8,level_offset,"r2"),2,0)
#define STATSEP396() \
    func_0803E488(numbers,0)
#define GAP396() \
    func_0803E488(spaces,12)
#define STATBEGIN396(side, menu_reg, stat_reg) \
    register const u8 *menu asm("sb"); \
    register const u8 *menu_loaded asm(menu_reg); \
    register const u8 *stat_menu asm("r8"); \
    register u8 *save asm("r4"); \
    register u8 *selector asm("r5"); \
    register const u8 *numbers asm("r6"); \
    register const u8 *spaces asm("sl"); \
    menu_loaded=D_08675BEC; if ((menu_reg)[1]!='5') asm("" : : "r"(menu_loaded)); \
    ((const u8 *volatile)menu)=menu_loaded; \
    func_0803E488((const u8 *volatile)menu,1); \
    func_0803E488((const u8 *volatile)menu,2); \
    func_0803E488((const u8 *volatile)menu,5); \
    ((const u8 *volatile)stat_menu)=({ register const u8 *loaded asm(stat_reg)=D_08675E08; if ((menu_reg)[1]=='5') asm("" : : "r"(loaded), "r"(menu_loaded)); else asm("" : : "r"(loaded)); loaded; }); \
    func_0803E488((const u8 *volatile)stat_menu,19); \
    func_0803E488((const u8 *volatile)menu,5); \
    func_0803E488((const u8 *volatile)stat_menu,17); \
    func_0803E488((const u8 *volatile)menu,10)
#define STATFIRST396(side, hp_offset, level_offset, selector_reg, spaces_reg, hp_reg, level_reg) \
    func_0803E488((const u8 *volatile)stat_menu,11); \
    ((u8 *volatile)save)=D_02000B5C; \
    ((u8 *volatile)selector)=({ register u32 offset asm(selector_reg)=(side); asm("" : : "r"(offset)); (u8 *volatile)save+offset; }); \
    func_08001848(STATFIELD396(u16,hp_offset,hp_reg),3,0); \
    ((const u8 *volatile)numbers)=D_08675C5C; \
    func_0803E488((const u8 *volatile)numbers,31); \
    func_08001848(STATFIELD396(u8,level_offset,level_reg),2,0); \
    ((const u8 *volatile)spaces)=({ register const u8 *loaded asm(spaces_reg)=D_08675DD4; asm("" : : "r"(loaded)); loaded; })
#define STATEND396(next) \
    func_0803E488(menu,10); \
    func_0803E488(stat_menu,8); \
    task->selection=D_02007574[1]; \
    if (task->selection-6 <= 1) { STATE396(1000); } \
    else { if ((next)==4100) { STATE396(next); } else { bound=(next); goto write_bound; } }
#define SKILLFIELD396(constant, reg) ({ \
    register u8 *selected asm(reg)=selector; \
    register u32 index asm("r1"); \
    register u32 address asm("r0"); \
    register u32 field_offset asm("r1"); \
    asm("" : : "r"(selected)); \
    index=*selected; \
    ((u32 volatile)address)=index*572; \
    ((u32 volatile)address)=(u32 volatile)address+(u32)save; \
    ((u32 volatile)field_offset)=(constant); \
    asm("" : : "r"(address), "r"(field_offset)); \
    *(u8 *)((u32 volatile)address+(u32 volatile)field_offset); })
#define SKILL396(command, offset, reg) \
    func_0803E488(skill_menu,command); \
    func_0803AF4C(SKILLFIELD396(offset,reg))
#define SKILLGAP396() \
    func_0803E488(spaces,12); \
    func_0803E488(spaces,12); \
    func_0803E488(spaces,12)
#define SKILLBEGIN396(side, menu_reg) \
    register const u8 *menu asm("sl"); \
    register const u8 *skill_menu asm("r5"); \
    register u8 *save asm("r6"); \
    register u8 *selector asm("r8"); \
    register const u8 *spaces asm("r4"); \
    register const u8 *numbers asm("sb"); \
    ((const u8 *volatile)menu)=({ register const u8 *loaded asm(menu_reg)=D_08675BEC; asm("" : : "r"(loaded)); loaded; }); \
    func_0803E488((const u8 *volatile)menu,1); \
    func_0803E488((const u8 *volatile)menu,2); \
    func_0803E488((const u8 *volatile)menu,5); \
    ((const u8 *volatile)skill_menu)=D_08675E08; \
    func_0803E488((const u8 *volatile)skill_menu,9); \
    func_0803E488((const u8 *volatile)menu,5); \
    func_0803E488((const u8 *volatile)skill_menu,17); \
    func_0803E488((const u8 *volatile)menu,10)
#define SKILLFIRST396(side, command, offset, selector_reg) \
    func_0803E488((const u8 *volatile)skill_menu,command); \
    ((u8 *volatile)save)=D_02000B5C; \
    ((u8 *volatile)selector)=({ register u32 selector_offset asm(selector_reg)=(side); register u8 *selected asm(selector_reg); asm("" : : "r"(selector_offset)); selected=(u8 *)(selector_offset+(u32)save); asm("" : : "r"(selected)); selected; }); \
    func_0803AF4C(SKILLFIELD396(offset,selector_reg)); \
    ((const u8 *volatile)spaces)=D_08675DD4
#define SKILLFIRSTSEP396() \
    ((const u8 *volatile)numbers)=({ register const u8 *loaded asm("r2")=D_08675C5C; asm("" : : "r"(loaded)); loaded; }); \
    func_0803E488((const u8 *volatile)numbers,0)
#define SKILLEND396(next) \
    func_0803E488(menu,10); \
    func_0803E488(skill_menu,8); \
    task->selection=D_02007574[1]; \
    if (task->selection-6 <= 1) { STATE396(1000); } \
    else { register u32 next_state asm("r2")=(next); asm("" : : "r"(next_state)); task->state=next_state; }

#define LEFTSTORE396(field, input) do { \
    register u8 *base asm("r3"); \
    register u32 selected asm("r0"); \
    register u32 address asm("r1"); \
    register u32 member asm("r2"); \
    register u32 scaled asm("r0"); \
    register u32 value asm("r0"); \
    register u32 offset asm("r5"); \
    ((u8 *volatile)base)=D_02000B5C; \
    selected=task->selection; asm("" : : "r"(base), "r"(selected)); \
    address=selected*56; asm("" : : "r"(address)); \
    { register u32 selector_offset asm("r2")=0x3F0C; \
      register u8 *pointer asm("r0"); \
      asm("" : : "r"(selector_offset)); \
      pointer=base+selector_offset; asm("" : : "r"(pointer)); member=*pointer; } \
    scaled=member*572; asm("" : : "r"(scaled)); \
    address+=scaled; address+=(u32)base; asm("" : : "r"(address)); \
    if (input) { value=D_030022FC; asm("" : : "r"(value)); } \
    offset=(field); asm("" : : "r"(offset)); address+=offset; \
    if (!(input)) { value=0xFFFF; } \
    asm("" : : "r"(value), "r"(address)); \
    *(u16 *)address=value; \
} while (0)
#define RIGHTSTORE396(field, selector_reg, input, byte_input) do { \
    register u8 *base asm("r3"); \
    register u32 selected asm("r0"); \
    register u32 part asm("r2"); \
    register u32 member asm("r1"); \
    register u32 address asm("r0"); \
    register u32 value asm("r1"); \
    register u32 offset asm("r2"); \
    ((u8 *volatile)base)=D_02000B5C; \
    selected=task->selection; asm("" : : "r"(base), "r"(selected)); \
    part=selected*7; asm("" : : "r"(part)); \
    { register u32 selector_offset asm(selector_reg)=0x3F0D; \
      register u8 *pointer asm("r0"); \
      asm("" : : "r"(selector_offset)); \
      pointer=base+selector_offset; asm("" : : "r"(pointer)); member=*pointer; } \
    address=member*143; address+=part; address*=4; address+=(u32)base; \
    asm("" : : "r"(address)); \
    if (input) { if (byte_input) value=(u8)D_030022FC; else value=D_030022FC; asm("" : : "r"(value)); } \
    offset=(field); asm("" : : "r"(offset)); address+=offset; \
    if (!(input)) { value=0xFFFF; } \
    if (input) asm("" : : "r"(value), "r"(address)); \
    *(u16 *)address=value; \
} while (0)
#define RIGHTADDRESS396(field, selector_reg, input, byte_input) do { \
    register u8 *base asm("r3"); \
    register u32 selected asm("r0"); \
    register u32 part asm("r2"); \
    register u32 member asm("r1"); \
    register u32 address asm("r0"); \
    register u32 value asm("r1"); \
    register u32 offset asm("r2"); \
    ((u8 *volatile)base)=D_02000B5C; \
    selected=task->selection; asm("" : : "r"(base), "r"(selected)); \
    part=selected*7; asm("" : : "r"(part)); \
    { register u32 selector_offset asm(selector_reg)=0x3F0D; \
      register u8 *pointer asm("r0"); \
      asm("" : : "r"(selector_offset)); \
      pointer=base+selector_offset; asm("" : : "r"(pointer)); member=*pointer; } \
    address=member*143; address+=part; address*=4; address+=(u32)base; \
    asm("" : : "r"(address)); \
    if (input) { if (byte_input) value=(u8)D_030022FC; else value=D_030022FC; asm("" : : "r"(value)); } \
    offset=(field); asm("" : : "r"(offset)); address+=offset; \
    if (!(input)) { value=0xFFFF; } \
    if (input) asm("" : : "r"(value), "r"(address)); \
    right_address=address; right_value=value; \
} while (0)
#define BYTESTORE396(selector, selector_reg, field, field_reg) do { \
    register u8 *base asm("r2"); \
    register u32 selector_offset asm(selector_reg); \
    register u8 *pointer asm("r0"); \
    register u32 member asm("r1"); \
    register u32 scaled asm("r0"); \
    register u32 selected asm("r1"); \
    register u32 address asm("r1"); \
    register u32 field_offset asm(field_reg); \
    register u32 value asm("r0"); \
    base=D_02000B5C; asm("" : : "r"(base)); \
    selector_offset=(selector); asm("" : : "r"(selector_offset)); \
    pointer=base+selector_offset; asm("" : : "r"(pointer)); member=*pointer; \
    scaled=member*572; asm("" : : "r"(scaled)); \
    selected=task->selection; address=selected+scaled; \
    field_offset=(field); asm("" : : "r"(field_offset)); \
    base+=field_offset; asm("" : : "r"(base)); \
    address+=(u32)base; value=D_030022FC; \
    asm("" : : "r"(value), "r"(address)); *(u8 *)address=value; \
} while (0)
#define SKILLSTORE396(selector, field) do { \
    register u8 *base asm("r2"); \
    register u32 selected asm("r3"); \
    register u32 selector_offset asm("r5"); \
    register u8 *pointer asm("r0"); \
    register u32 member asm("r1"); \
    register u32 address asm("r0"); \
    register u32 value asm("r1"); \
    register u32 field_offset asm("r2"); \
    base=D_02000B5C; asm("" : : "r"(base)); \
    selected=task->selection; asm("" : : "r"(selected)); \
    selector_offset=(selector); asm("" : : "r"(selector_offset)); \
    pointer=base+selector_offset; asm("" : : "r"(pointer)); member=*pointer; \
    address=member*143; address+=selected; address*=4; address+=(u32)base; \
    asm("" : : "r"(address)); value=task->value; asm("" : : "r"(value)); \
    field_offset=(field); asm("" : : "r"(field_offset)); address+=field_offset; \
    *(u8 *)address=value; \
} while (0)
void func_08039608(void)
{
    struct Task396 *task=&D_02000034[D_02000030];
    volatile u32 zero;
    register s32 pivot asm("r0");
    register s32 bound asm("r5");
    register s32 lower asm("r2");
    register s32 menu asm("r6");
    register u8 *selector_base asm("r1");
    register u32 selector_value asm("r0");
    register u32 selector_offset asm("r2");
    register u32 right_address asm("r0");
    register u32 right_value asm("r1");
    for (;;)
    {
        register s32 state asm("r1")=task->state;
        {
            ((s32 volatile)bound)=4000;
            if (state==(s32 volatile)bound) goto state_4000;
            if (state>(s32 volatile)bound) goto upper_states;
            ((s32 volatile)bound)=2900;
            if (state==(s32 volatile)bound) goto state_2900;
            if (state>(s32 volatile)bound) goto stat_states;
            ((s32 volatile)menu)=1100;
            if (state==(s32 volatile)menu) goto state_1100;
            if (state>(s32 volatile)menu) goto selector_states;
            if (state==100) goto state_100;
            if (state>100) goto front_states;
            if (state==0) goto state_0;
            goto yield;
        front_states:
            if (state==200) goto state_200;
            ((s32 volatile)pivot)=1000;
            if (state==(s32 volatile)pivot) goto state_1000;
            goto yield;
        selector_states:
            ((s32 volatile)pivot)=2000;
            if (state==(s32 volatile)pivot) goto state_2000;
            if (state>(s32 volatile)pivot) goto selector_edits;
            ((s32 volatile)pivot)=1500;
            if (state==(s32 volatile)pivot) goto state_1500;
            goto yield;
        selector_edits:
            ((s32 volatile)pivot)=2100;
            if (state==(s32 volatile)pivot) goto state_2100;
            ((s32 volatile)pivot)+=100;
            if (state==(s32 volatile)pivot) goto state_2200;
            goto yield;
        stat_states:
            ((s32 volatile)pivot)=3400;
            if (state==(s32 volatile)pivot) goto state_3400;
            if (state>(s32 volatile)pivot) goto left_clear_states;
            ((s32 volatile)lower)=3100;
            if (state==(s32 volatile)lower) goto state_3100;
            if (state>(s32 volatile)lower) goto left_input_states;
            ((s32 volatile)pivot)=3000;
            if (state==(s32 volatile)pivot) goto state_3000;
            goto yield;
        left_input_states:
            ((s32 volatile)pivot)=3200;
            if (state==(s32 volatile)pivot) goto state_3200;
            ((s32 volatile)pivot)+=100;
            if (state==(s32 volatile)pivot) goto state_3300;
            goto yield;
        left_clear_states:
            ((s32 volatile)pivot)=3700;
            if (state==(s32 volatile)pivot) goto state_3700;
            if (state>(s32 volatile)pivot) goto left_end_states;
            ((s32 volatile)pivot)-=200;
            if (state==(s32 volatile)pivot) goto state_3500;
            ((s32 volatile)pivot)+=100;
            if (state==(s32 volatile)pivot) goto state_3600;
            goto yield;
        left_end_states:
            ((s32 volatile)pivot)=3800;
            if (state==(s32 volatile)pivot) goto state_3800;
            ((s32 volatile)pivot)+=100;
            if (state==(s32 volatile)pivot) goto state_3900;
            goto yield;
        upper_states:
            ((s32 volatile)pivot)=4950;
            if (state==(s32 volatile)pivot) goto state_4950;
            if (state>(s32 volatile)pivot) goto skill_states;
            ((s32 volatile)pivot)=4500;
            if (state==(s32 volatile)pivot) goto state_4500;
            if (state>(s32 volatile)pivot) goto right_clear_states;
            ((s32 volatile)pivot)=4200;
            if (state==(s32 volatile)pivot) goto state_4200;
            if (state>(s32 volatile)pivot) goto right_input_states;
            ((s32 volatile)pivot)-=100;
            if (state==(s32 volatile)pivot) goto state_4100;
            goto yield;
        right_input_states:
            ((s32 volatile)pivot)=4300;
            if (state==(s32 volatile)pivot) goto state_4300;
            ((s32 volatile)pivot)+=100;
            if (state==(s32 volatile)pivot) goto state_4400;
            goto yield;
        right_clear_states:
            ((s32 volatile)pivot)=4700;
            if (state==(s32 volatile)pivot) goto state_4700;
            if (state>(s32 volatile)pivot) goto right_end_states;
            ((s32 volatile)pivot)-=100;
            if (state==(s32 volatile)pivot) goto state_4600;
            goto yield;
        right_end_states:
            ((s32 volatile)pivot)=4800;
            if (state==(s32 volatile)pivot) goto state_4800;
            ((s32 volatile)pivot)+=100;
            if (state==(s32 volatile)pivot) goto state_4900;
            goto yield;
        skill_states:
            ((s32 volatile)bound)=5600;
            if (state==(s32 volatile)bound) goto state_5600;
            if (state>(s32 volatile)bound) goto finish_states;
            ((s32 volatile)pivot)=5100;
            if (state==(s32 volatile)pivot) goto state_5100;
            if (state>(s32 volatile)pivot) goto right_skill_states;
            ((s32 volatile)pivot)-=100;
            if (state==(s32 volatile)pivot) goto state_5000;
            goto yield;
        right_skill_states:
            ((s32 volatile)pivot)=5200;
            if (state==(s32 volatile)pivot) goto state_5200;
            ((s32 volatile)pivot)=5500;
            if (state==(s32 volatile)pivot) goto state_5500;
            goto yield;
        finish_states:
            ((s32 volatile)pivot)=9000;
            if (state==(s32 volatile)pivot) goto state_9000;
            if (state>(s32 volatile)pivot) goto battle_states;
            ((s32 volatile)pivot)=5700;
            if (state==(s32 volatile)pivot) goto state_5700;
            ((s32 volatile)pivot)=8000;
            if (state==(s32 volatile)pivot) goto state_8000;
            goto yield;
        battle_states:
            ((s32 volatile)pivot)=10000;
            if (state==(s32 volatile)pivot) goto state_10000;
            ((s32 volatile)pivot)+=100;
            if (state==(s32 volatile)pivot) goto state_10100;
            goto yield;
        }

        state_0:
            func_08059380(0);
        state_100:
        {
            register volatile u32 *dma asm("r1");
            register u32 zero_value asm("r4")=0;
            zero=zero_value;
            ((volatile u32 *volatile)dma)=(volatile u32 *)0x040000D4;
            { register u32 source asm("r2")=(u32)&zero; asm("" : : "r"(source)); dma[0]=source; }
            dma[1]=0x06000000;
            dma[2]=0x85006000;
            (void)dma[2];
            func_08000DB8();
            func_08000D1C(0);
            func_08001DE4(D_08663D44[24]);
            func_0802F07C();
            func_08003DF8(10,func_08004034);
            {
                register u8 *base asm("r1")=(u8 *)D_02000034;
                register u32 offset asm("r5")=1368;
                register u32 *argument asm("r0");
                asm("" : "+r"(base) : "r"(offset));
                argument=(u32 *)(base+offset); *argument=zero_value;
                { register u32 second_offset asm("r0")=1372;
                  base+=second_offset; *(u32 *)base=zero_value; }
            }
            STATE396(200);
            goto yield;
        }
        state_200:
            if (({ register u32 base asm("r0")=(u32)D_02000034; register u32 offset asm("r1")=1384; asm("" : : "r"(base), "r"(offset)); base+=offset; *(u32 *)base; })!=1) goto yield;
            func_08003E3C(10);
            STATE396(1000);
            goto yield;
        state_1000:
        {
            register u8 *save asm("r4");
            func_080592F0();
            func_0803E488(D_08675BEC,1);
            func_0803E488(D_08675BEC,2);
            func_0803E488(D_08675BEC,5);
            func_0803E488(D_08675E08,1);
            save=D_02000B5C;
            { register u32 offset asm("r2")=0x3F0C; register u8 *pointer asm("r0"); pointer=save+offset; asm("" : "+r"(save) : "r"(offset), "r"(pointer)); func_08001848(*pointer,1,0); }
            func_0803E488(D_08675E08,3);
            func_0803E488(D_08675E08,2);
            { register u32 offset asm("r0")=0x3F0D; asm("" : : "r"(offset)); save+=offset; func_08001848(*save,1,0); }
            func_0803E488(D_08675E08,4);
            task->state=menu;
        }
        state_1100:
            func_0803E488(D_08675E08,0);
            switch ((u32)D_02007574[1])
            {
            case 0: STATE396(10000); break;
            case 1: STATE396(2000); break;
            case 2: STATE396(3000); break;
            case 3: STATE396(5000); break;
            case 4: STATE396(4000); break;
            case 5: STATE396(5500); break;
            case 6: case 7: break;
            case 8: STATE396(8000); break;
            }
            goto yield;
        state_1500:
            func_080592F0();
            STATE396(1000);
            goto yield;
        state_2000:
            func_0803E488(D_08675E08,5);
            switch ((u32)D_02007574[1])
            {
            case 0: STATE396(2100); break;
            case 1: STATE396(2200); break;
            case 2: goto write_bound;
            }
            goto yield;
        state_2100:
            EDIT396(6);
            func_0805354C(0,3,1);
            selector_base=D_02000B5C; selector_value=D_030022FC; selector_offset=0x3F0C;
            goto selector_write;
            goto yield;
        state_2200:
            EDIT396(7);
            func_0805354C(0,3,1);
            selector_base=D_02000B5C; selector_value=D_030022FC; selector_offset=0x3F0D;
        selector_write:
            asm("" : : "r"(selector_base), "r"(selector_value), "r"(selector_offset));
            *(selector_base+selector_offset)=selector_value;
        write_bound:
            task->state=bound;
            goto yield;
        state_2900:
            STATE396(1000);
            goto yield;
        state_3000:
        {
            STATBEGIN396(0x3F0C,"r5","r0");
            STATFIRST396(0x3F0C,0x3622,0x384C,"r1","r2","r2","r1"); GAP396();
            STAT396(14,0x36CA,0x384F); STATSEP396();
            STAT396(12,0x365A,0x384D); GAP396();
            STAT396(15,0x3702,0x3850); STATSEP396();
            STAT396(13,0x3692,0x384E); GAP396();
            STAT396(16,0x373A,0x3851);
            STATEND396(3100);
            goto yield;
        }
        state_3100:
            EDIT396(20);
            func_0803E488(D_08675E08,18);
            task->value=D_02007574[1];
            switch ((u32)D_02007574[1])
            {
            case 0: STATE396(3200); break;
            case 1: STATE396(3300); break;
            case 2: STATE396(3400); break;
            case 3: STATE396(3500); break;
            case 4: STATE396(3600); break;
            case 5: STATE396(3700); break;
            case 6: STATE396(3800); break;
            case 7: STATE396(3900); break;
            case 8: STATE396(1000); break;
            }
            goto yield;
        state_3200:
            EDIT396(21);
            func_0805354C(2,153,3);
            {
                register u32 value asm("r0")=(u8)D_030022FC;
                register u8 *base asm("r4");
                register u32 member asm("r2");
                register u32 address asm("r1");
                register u32 selected asm("r2");
                register u32 part asm("r3");
                register u32 field_offset asm("r5");
                asm("" : : "r"(value)); base=D_02000B5C; asm("" : : "r"(base));
                { register u32 offset asm("r2")=0x3F0C; register u8 *pointer asm("r1");
                  asm("" : : "r"(offset)); pointer=base+offset; asm("" : : "r"(pointer)); member=*pointer; }
                address=member*572; asm("" : : "r"(address));
                selected=task->selection; part=selected*56; asm("" : : "r"(part));
                field_offset=0x361C; asm("" : : "r"(field_offset));
                base+=field_offset; part+=(u32)base; address+=part;
                func_08036A98(value,(void *)address,(u8)selected);
            }
            STATE396(3000);
            goto yield;
        state_3300:
            EDIT396(22);
            func_0805354C(1,150,3);
            LEFTSTORE396(0x3632,1);
            STATE396(3000);
            goto yield;
        state_3400:
            EDIT396(23);
            func_0805354C(1,150,3);
            LEFTSTORE396(0x362E,1);
            STATE396(3000);
            goto yield;
        state_3500:
            EDIT396(24);
            func_0805354C(1,150,3);
            LEFTSTORE396(0x3636,1);
            STATE396(3000);
            goto yield;
        state_3600:
            LEFTSTORE396(0x3632,0);
            STATE396(3000);
            goto yield;
        state_3700:
            LEFTSTORE396(0x362E,0);
            STATE396(3000);
            goto yield;
        state_3800:
            LEFTSTORE396(0x3636,0);
            STATE396(3000);
            goto yield;
        state_3900:
            EDIT396(25);
            func_0805354C(0,87,3);
            BYTESTORE396(0x3F0C,"r1",0x384C,"r5");
            STATE396(3000);
            goto yield;
        state_4000:
        {
            STATBEGIN396(0x3F0D,"r0","r1");
            STATFIRST396(0x3F0D,0x376C,0x3852,"r2","r0","r1","r2"); GAP396();
            STAT396(14,0x37C0,0x3855); STATSEP396();
            STAT396(12,0x3788,0x3853); GAP396();
            STAT396(15,0x37DC,0x3856); STATSEP396();
            STAT396(13,0x37A4,0x3854); GAP396();
            STAT396(16,0x37F8,0x3857);
            STATEND396(4100);
            goto yield;
        }
        state_4100:
            EDIT396(20);
            func_0803E488(D_08675E08,27);
            task->value=D_02007574[1];
            switch ((u32)D_02007574[1])
            {
            case 0: STATE396(4200); break;
            case 1: STATE396(4300); break;
            case 2: STATE396(4400); break;
            case 3: STATE396(4500); break;
            case 4: STATE396(4600); break;
            case 5: STATE396(4700); break;
            case 6: STATE396(4800); break;
            case 7: STATE396(4900); break;
            case 8: STATE396(4950); break;
            case 9: STATE396(1000); break;
            }
            goto yield;
        state_4200:
            EDIT396(21);
            func_0805354C(2,153,3);
            RIGHTADDRESS396(0x376C,"r1",1,1);
            goto right_store;
            goto yield;
        state_4300:
            EDIT396(22);
            func_0805354C(1,150,3);
            RIGHTADDRESS396(0x3776,"r1",1,0);
            goto right_store;
            goto yield;
        state_4400:
            EDIT396(23);
            func_0805354C(1,150,3);
            RIGHTSTORE396(0x3772,"r5",1,0);
            STATE396(4000);
            goto yield;
        state_4500:
            EDIT396(24);
            func_0805354C(1,150,3);
            RIGHTADDRESS396(0x377A,"r1",1,0);
            goto right_store;
            goto yield;
        state_4600:
            RIGHTSTORE396(0x3776,"r1",0,0);
            goto write_bound;
            goto yield;
        state_4700:
            RIGHTSTORE396(0x3772,"r1",0,0);
            goto write_bound;
            goto yield;
        state_4800:
            RIGHTADDRESS396(0x377A,"r1",0,0);
        right_store:
            *(u16 *)right_address=right_value;
            goto write_bound;
            goto yield;
        state_4900:
            EDIT396(25);
            func_0805354C(0,87,3);
            BYTESTORE396(0x3F0D,"r5",0x3852,"r0");
            STATE396(4000);
            goto yield;
        state_4950:
            EDIT396(26);
            func_0805354C(0,8,3);
            goto write_bound;
            goto yield;
        state_5000:
        {
            SKILLBEGIN396(0x3F0C,"r1");
            SKILLFIRST396(0x3F0C,11,0x3814,"r2"); SKILLGAP396();
            SKILL396(14,0x3820,"r2"); SKILLFIRSTSEP396();
            SKILL396(12,0x3818,"r0"); SKILLGAP396();
            SKILL396(15,0x3824,"r2"); func_0803E488(numbers,0);
            SKILL396(13,0x381C,"r2"); SKILLGAP396();
            SKILL396(16,0x3828,"r2");
            SKILLEND396(5100);
            goto yield;
        }
        state_5100:
            EDIT396(10);
            func_0803E488(D_08675E08,8);
            task->value=D_02007574[1];
            if (task->value==7) { STATE396(1000); }
            else { STATE396(5200); }
            goto yield;
        state_5200:
            if (task->value==6) task->value=255;
            SKILLSTORE396(0x3F0C,0x3814);
            func_0803E488(D_08675BEC,1);
            STATE396(5000);
            goto yield;
        state_5500:
        {
            SKILLBEGIN396(0x3F0D,"r5");
            SKILLFIRST396(0x3F0D,16,0x3844,"r0"); SKILLGAP396();
            SKILL396(13,0x3838,"r2"); SKILLFIRSTSEP396();
            SKILL396(15,0x3840,"r0"); SKILLGAP396();
            SKILL396(12,0x3834,"r2"); func_0803E488(numbers,0);
            SKILL396(14,0x383C,"r2"); SKILLGAP396();
            SKILL396(11,0x3830,"r2");
            SKILLEND396(5600);
            goto yield;
        }
        state_5600:
            EDIT396(10);
            func_0803E488(D_08675E08,8);
            task->value=D_02007574[1];
            if (task->value==7) { STATE396(1000); }
            else { STATE396(5700); }
            goto yield;
        state_5700:
            if (task->value==6) task->value=255;
            SKILLSTORE396(0x3F0D,0x3830);
            func_0803E488(D_08675BEC,1);
            STATE396(5500);
            goto yield;
        state_8000:
            func_0803AD38();
            STATE396(1000);
            goto yield;
        state_9000:
            task->reply=1;
            goto yield;
        state_10000:
            func_0803AE6C();
            func_0803AED4();
            func_08003DF8(4,func_0802AC0C);
            STATE396(10100);
            goto yield;
        state_10100:
            if (({ register u32 base asm("r0")=(u32)D_02000034; register u32 offset asm("r5")=568; asm("" : : "r"(base), "r"(offset)); base+=offset; *(u32 *)base; })!=1) goto yield;
            func_08003E3C(4);
            STATE396(100);
            goto yield;
        yield:
        func_0805EE78(1);
    }
}

void func_0803AD38(void)
{
    u16 i;
    u16 side;
    u16 j;
    u16 k;
    u8 *unit;
    func_08003948();
    {
        register u32 index asm("r2");
        register u8 *base asm("r3");
        register u32 value asm("r1");
        index=0; base=D_02003E61; value=99;
        asm("" : : "r"(index), "r"(base), "r"(value));
        do { register u32 step asm("r0"); *(u8 *)(index+(u32)base)=value; ((u32 volatile)step)=index+1; index=(u16)(u32 volatile)step; } while (index<=6);
        index=0; base=D_02003FD7; value=1;
        asm("" : : "r"(index), "r"(base), "r"(value));
        do { register u32 step asm("r0"); *(u8 *)(index+(u32)base)=value; ((u32 volatile)step)=index+1; index=(u16)(u32 volatile)step; } while (index<=32);
    }
    {
        register u32 index asm("r3");
        register u8 *base asm("r2");
        register u32 value asm("r1");
        index=0; base=D_02004A68; value=0;
        asm("" : : "r"(index), "r"(base), "r"(value));
        do { register u32 step asm("r0"); *(u8 *)(index+(u32)base)=value; ((u32 volatile)step)=index+1; index=(u16)(u32 volatile)step; } while (index<=1);
    }
    {
        register u32 side_index asm("r2");
        register u32 clear asm("r8");
        register u32 next_side asm("sb");
        register u8 *current_unit asm("r5");
        side_index=0;
        ((u32 volatile)clear)=side_index;
        asm("" : : "r"(side_index), "r"(clear));
        do
        {
            register u32 row_index asm("r3");
            register u32 next_row asm("ip");
            { register u32 scaled asm("r0")=side_index*572; register u8 *base asm("r1"); asm("" : : "r"(scaled)); base=D_02004178; asm("" : : "r"(base)); current_unit=(u8 *)(scaled+(u32)base); }
            row_index=0;
            next_side=side_index+1;
            asm("" : : "r"(current_unit), "r"(row_index), "r"(next_side));
            do
            {
                register u32 row_offset asm("r1");
                register u32 part asm("r4");
                register u32 twice_row asm("r6");
                row_offset=row_index*28;
                {
                    register u32 address asm("r0");
                    register u32 offset asm("r2");
                    register u32 value asm("r6");
                    asm("" : : "r"(current_unit), "r"(row_offset));
                    address=(u32)current_unit+row_offset;
                    asm("" : : "r"(address));
                    offset=528;
                    asm("" : : "r"(offset)); address+=offset;
                    value=(u32 volatile)clear;
                    *(u8 *)address=value;
                }
                part=0;
                { register u32 low asm("r7")=row_index+1; asm("" : : "r"(low)); next_row=low; }
                asm("" : : "r"(part), "r"(next_row));
                twice_row=row_index*2;
                asm("" : : "r"(twice_row));
                do
                {
                    register u32 address asm("r0");
                    register u32 base asm("r2");
                    register u32 offset asm("r7");
                    address=part*4; asm("" : : "r"(address)); address+=row_offset;
                    asm("" : : "r"(address), "r"(current_unit));
                    base=(u32)current_unit+address; asm("" : : "r"(base));
                    offset=504; asm("" : : "r"(offset));
                    address=base+offset; *(u8 *)address=part;
                    offset++; asm("" : : "r"(offset));
                    address=base+offset;
                    ((u32 volatile)base)=(u32 volatile)clear;
                    *(u8 *)address=(u32 volatile)base;
                    ((u32 volatile)address)=part+1;
                    part=(u16)(u32 volatile)address;
                } while (part<=5);
                part=0;
                {
                    register u32 address asm("r0");
                    register u32 offset asm("r3");
                    register u32 base asm("r2");
                    asm("" : : "r"(part));
                    address=twice_row+row_index; asm("" : : "r"(address));
                    row_offset=address*2;
                    offset=560; asm("" : : "r"(row_offset), "r"(offset));
                    base=(u32)current_unit+offset; asm("" : : "r"(base));
                    do
                    {
                        address=part+row_offset; asm("" : : "r"(address));
                        address=base+address;
                        *(u8 *)address=part;
                        ((u32 volatile)address)=part+1;
                        part=(u16)(u32 volatile)address;
                    } while (part<=5);
                }
                {
                    register u32 low asm("r6");
                    register u32 step asm("r0");
                    ((u32 volatile)low)=next_row; asm("" : : "r"(low));
                    ((u32 volatile)step)=(u32 volatile)low<<16;
                    row_index=(u32 volatile)step>>16;
                }
            } while (row_index<=1);
            {
                register u32 member asm("r4")=0;
                do
                {
                    register u32 address asm("r1")=member*56;
                    register u32 step asm("r0");
                    asm("" : : "r"(address), "r"(current_unit));
                    address=(u32)current_unit+address;
                    func_08036A98(0x39,(void *)address,member);
                    ((u32 volatile)step)=member+1;
                    member=(u16)(u32 volatile)step;
                } while (member<=5);
            }
            {
                register u32 member asm("r4")=0;
                register u32 copy_offset asm("ip");
                register const struct Block396 *source asm("r2");
                { register u32 low asm("r7")=336; asm("" : : "r"(member), "r"(low)); copy_offset=low; }
                source=&D_086764A4;
                asm("" : : "r"(copy_offset), "r"(source));
                do
                {
                    register u32 address asm("r1")=member*28;
                    register u32 step asm("r0");
                    asm("" : : "r"(address), "r"(current_unit));
                    address=(u32)current_unit+address; address+=copy_offset;
                    *(struct Block396 *)address=*source;
                    ((u32 volatile)step)=member+1;
                    member=(u16)(u32 volatile)step;
                } while (member<=5);
            }
            {
                register u32 low asm("r1");
                register u32 step asm("r0");
                ((u32 volatile)low)=next_side; asm("" : : "r"(low));
                ((u32 volatile)step)=(u32 volatile)low<<16;
                side_index=(u32 volatile)step>>16;
            }
        } while (side_index<=3);
    }
}
