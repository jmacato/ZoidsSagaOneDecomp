#include "engine/task_state.h"

extern u8 D_02000030;
extern u16 D_03002338;

void func_08001068(u16);
void func_08009B6C(void);
void func_08009ED4(void);
void func_0800A1C8(void);
void func_08000D1C(s32);
void func_0803E024(s32, s32, s32);
void func_08009A54(void);
void func_080014A8(s32, void *);
void func_0803E454(s32);
void func_08001524(s32, void *);

s32 func_08009A58(void)
{
    TaskState *task = &task_states[D_02000030];

    func_08001068(D_03002338);
    func_08009B6C();
    func_08009ED4();
    func_0800A1C8();
    func_08000D1C(0);
    *(vu16 *)0x04000008 = 0xF04;
    func_0803E024(0, 0x140, 0xB4);
    func_080014A8(0xFFFF, func_08009A54);
    func_0803E454(1);
    func_08001524(0, func_08009A54);
    *(u32 *)&task->unknown04[0x14] = 1;
}
