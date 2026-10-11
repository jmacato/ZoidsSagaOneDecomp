/* The local alias lets the reset entry branch directly to the ARM startup stub. */
static void StartArmEntry(void) __attribute__((weakref("startup_and_irq")));

void rom_entry(void)
{
    StartArmEntry();
}
