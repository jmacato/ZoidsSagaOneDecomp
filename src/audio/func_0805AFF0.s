/* The SDK mixer saves its shared register frame before entering the ARM mixing loop. */
.cpu arm7tdmi
	.arch armv4t
	.text
	.align	1
	.global	func_0805AFF0
	.syntax unified
	.code	16
	.thumb_func
	.type	func_0805AFF0, %function
func_0805AFF0:
	.syntax divided
	ldr r0, sound_main_literals
	.thumb
	.syntax unified
	ldr	r0, [r0]
	.syntax divided
	ldr r2, sound_main_literals+4
	.thumb
	.syntax unified
	ldr	r3, [r0]
	.syntax divided
	cmp r2, r3
	beq .L2
	bx lr
	.thumb
	.syntax unified
.L2:
	.syntax divided
	add r3, #1
	.thumb
	.syntax unified
	str	r3, [r0]
	.syntax divided
	push {r4, r5, r6, r7, lr}
	mov r1, r8
	mov r2, r9
	mov r3, r10
	mov r4, r11
	push {r0, r1, r2, r3, r4}
	sub sp, #24
	.thumb
	.syntax unified
	ldrb	r1, [r0, #12]
	cmp	r1, #0
	beq	.L3
	.syntax divided
	ldr r2, sound_main_literals+12
	.thumb
	.syntax unified
	ldrb	r2, [r2]
	.syntax divided
	cmp r2, #160
	bhs .L4
	.thumb
	.syntax unified
	adds	r2, r2, #228
.L4:
	adds	r1, r1, r2
.L3:
	str	r1, [sp, #20]
	ldr	r3, [r0, #32]
	cmp	r3, #0
	beq	.L5
	ldr	r0, [r0, #36]
	.syntax divided
	bl func_0805B39E
	.thumb
	.syntax unified
	ldr	r0, [sp, #24]
.L5:
	ldr	r3, [r0, #40]
	.syntax divided
	bl func_0805B39E
	.thumb
	.syntax unified
	ldr	r0, [sp, #24]
	ldr	r3, [r0, #16]
	mov	r8, r3
	.syntax divided
	ldr r5, sound_main_literals+16
	add r5, r5, r0
	.thumb
	.syntax unified
	ldrb	r4, [r0, #4]
	subs	r7, r4, #1
	.syntax divided
	bls .L6
	.thumb
	.syntax unified
	ldrb	r1, [r0, #11]
	subs	r1, r1, r7
	mov	r2, r8
	.syntax divided
	mul r2, r1
	.thumb
	.syntax unified
	adds	r5, r5, r2
.L6:
	str	r5, [sp, #8]
	.syntax divided
	ldr r6, sound_main_literals+20
	ldr r3, sound_main_literals+8
	bx r3
	.thumb
	.syntax unified
	.size	func_0805AFF0, .-func_0805AFF0
	.global	sound_main_padding
	.text
	.align	1
	.type	sound_main_padding, %object
	.size	sound_main_padding, 2
sound_main_padding:
	.space	2
	.global	sound_main_literals
	.align	2
	.type	sound_main_literals, %object
	.size	sound_main_literals, 24
sound_main_literals:
	.word	50364400
	.word	1752395091
	.word	50360873
	.word	67108870
	.word	848
	.word	1584

.align 2, 0
