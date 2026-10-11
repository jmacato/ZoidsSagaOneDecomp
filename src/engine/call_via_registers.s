.syntax unified
.cpu arm7tdmi
.thumb
.text
.balign 2

.global _call_via_r0
.type _call_via_r0, %function
.thumb_func
_call_via_r0:
    bx r0
    nop
.size _call_via_r0, . - _call_via_r0

.global _call_via_r1
.type _call_via_r1, %function
.thumb_func
_call_via_r1:
    bx r1
    nop
.size _call_via_r1, . - _call_via_r1

.global _call_via_r2
.type _call_via_r2, %function
.thumb_func
_call_via_r2:
    bx r2
    nop
.size _call_via_r2, . - _call_via_r2

.global _call_via_r3
.type _call_via_r3, %function
.thumb_func
_call_via_r3:
    bx r3
    nop
.size _call_via_r3, . - _call_via_r3

.global _call_via_r4
.type _call_via_r4, %function
.thumb_func
_call_via_r4:
    bx r4
    nop
.size _call_via_r4, . - _call_via_r4

.global _call_via_r5
.type _call_via_r5, %function
.thumb_func
_call_via_r5:
    bx r5
    nop
.size _call_via_r5, . - _call_via_r5

.global _call_via_r6
.type _call_via_r6, %function
.thumb_func
_call_via_r6:
    bx r6
    nop
.size _call_via_r6, . - _call_via_r6

.global _call_via_r7
.type _call_via_r7, %function
.thumb_func
_call_via_r7:
    bx r7
    nop
.size _call_via_r7, . - _call_via_r7

.global _call_via_r8
.type _call_via_r8, %function
.thumb_func
_call_via_r8:
    bx r8
    nop
.size _call_via_r8, . - _call_via_r8

.global _call_via_r9
.type _call_via_r9, %function
.thumb_func
_call_via_r9:
    bx r9
    nop
.size _call_via_r9, . - _call_via_r9

.global _call_via_r10
.type _call_via_r10, %function
.thumb_func
_call_via_r10:
    bx r10
    nop
.size _call_via_r10, . - _call_via_r10

.global _call_via_r11
.type _call_via_r11, %function
.thumb_func
_call_via_r11:
    bx r11
    nop
.size _call_via_r11, . - _call_via_r11

.global _call_via_r12
.type _call_via_r12, %function
.thumb_func
_call_via_r12:
    bx ip
    nop
.size _call_via_r12, . - _call_via_r12

.global _call_via_r13
.type _call_via_r13, %function
.thumb_func
_call_via_r13:
    bx sp
    nop
.size _call_via_r13, . - _call_via_r13

.global _call_via_r14
.type _call_via_r14, %function
.thumb_func
_call_via_r14:
    bx lr
    nop
.size _call_via_r14, . - _call_via_r14
