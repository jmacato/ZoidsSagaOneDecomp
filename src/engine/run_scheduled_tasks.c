__attribute__((naked)) void run_scheduled_tasks(void)
{
    asm volatile("bx pc\n\tnop\n\t.arm\n\tb run_scheduled_tasks_arm\n\t.thumb");
}
