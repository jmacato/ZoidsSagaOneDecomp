__attribute__((naked)) void yield_task_for_updates(void)
{
    asm volatile("bx pc\n\tnop\n\t.arm\n\tb yield_task_arm\n\t.thumb");
}
