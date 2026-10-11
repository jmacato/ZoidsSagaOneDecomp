.syntax unified
.cpu arm7tdmi
.thumb
.text
.balign 2

@ BIOS SWI 0x2A supplies the sound-driver jump table. C cannot express this interrupt.
.global func_0805BFF0
.type func_0805BFF0, %function
.thumb_func
func_0805BFF0:
    svc #0x2a
    bx lr
.size func_0805BFF0, . - func_0805BFF0
