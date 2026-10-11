.syntax unified
.cpu arm7tdmi
.thumb
.text
.balign 2

@ These entry points invoke BIOS services. C cannot express the SWI instruction.
.global bios_cpu_fast_set
.type bios_cpu_fast_set, %function
.thumb_func
bios_cpu_fast_set:
    svc #12
    bx lr
.size bios_cpu_fast_set, . - bios_cpu_fast_set

.global bios_cpu_set
.type bios_cpu_set, %function
.thumb_func
bios_cpu_set:
    svc #11
    bx lr
.size bios_cpu_set, . - bios_cpu_set

.global func_0805D274
.type func_0805D274, %function
.thumb_func
func_0805D274:
    svc #24
    bx lr
.size func_0805D274, . - func_0805D274

.global func_0805D278
.type func_0805D278, %function
.thumb_func
func_0805D278:
    svc #23
    bx lr
.size func_0805D278, . - func_0805D278

.global func_0805D27C
.type func_0805D27C, %function
.thumb_func
func_0805D27C:
    svc #22
    bx lr
.size func_0805D27C, . - func_0805D27C

.global bios_div
.type bios_div, %function
.thumb_func
bios_div:
    svc #6
    bx lr
.size bios_div, . - bios_div

.global func_0805D284
.type func_0805D284, %function
.thumb_func
func_0805D284:
    svc #19
    bx lr
.size func_0805D284, . - func_0805D284

.global func_0805D288
.type func_0805D288, %function
.thumb_func
func_0805D288:
    svc #18
    bx lr
.size func_0805D288, . - func_0805D288

.global func_0805D28C
.type func_0805D28C, %function
.thumb_func
func_0805D28C:
    svc #17
    bx lr
.size func_0805D28C, . - func_0805D28C

.global func_0805D290
.type func_0805D290, %function
.thumb_func
func_0805D290:
    svc #15
    bx lr
.size func_0805D290, . - func_0805D290

.global func_0805D294
.type func_0805D294, %function
.thumb_func
func_0805D294:
    svc #21
    bx lr
.size func_0805D294, . - func_0805D294

.global func_0805D298
.type func_0805D298, %function
.thumb_func
func_0805D298:
    svc #20
    bx lr
.size func_0805D298, . - func_0805D298
