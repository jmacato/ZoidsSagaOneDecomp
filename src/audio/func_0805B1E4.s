/* The ARM channel mixer uses the frame saved by the Thumb sound entry. */
.cpu arm7tdmi
	.arch armv4t
	.text
	.align	2
	.global	func_0805B1E4
	.syntax unified
	.arm
	.type	func_0805B1E4, %function
func_0805B1E4:
	str	r8, [sp]
	ldrb	r10, [r4, #10]
	lsl	r10, r10, #16
	ldrb	r0, [r4, #1]
	.syntax divided
	tst r0, #8
	beq .L2
	.arm
	.syntax unified
.L3:
	.syntax divided
	cmp r2, #4
	ble .L4
	subs r2, r2, r8
	movgt lr, #0
	bgt .L6
	mov lr, r8
	.arm
	.syntax unified
	add	r2, r2, r8
	sub	r8, r2, #4
	.syntax divided
	sub lr, lr, r8
	ands r2, r2, #3
	moveq r2, #4
	.arm
	.syntax unified
.L6:
	ldr	r6, [r5]
.L7:
	.syntax divided
	ldrsb r0, [r3], #1
	mul r1, r10, r0
	.arm
	.syntax unified
	bic	r1, r1, #16711680
	add	r6, r1, r6, ror #8
	.syntax divided
	adds r5, r5, #0x40000000
	blo .L7
	.arm
	.syntax unified
	str	r6, [r5], #4
	.syntax divided
	subs r8, r8, #4
	bgt .L6
	adds r8, r8, lr
	beq .L8
	.arm
	.syntax unified
.L31:
.L4:
	ldr	r6, [r5]
.L9:
	.syntax divided
	ldrsb r0, [r3], #1
	mul r1, r10, r0
	.arm
	.syntax unified
	bic	r1, r1, #16711680
	add	r6, r1, r6, ror #8
	.syntax divided
	subs r2, r2, #1
	beq .L10
	.arm
	.syntax unified
.L32:
.L11:
	.syntax divided
	adds r5, r5, #0x40000000
	blo .L9
	.arm
	.syntax unified
	str	r6, [r5], #4
	.syntax divided
	subs r8, r8, #4
	bgt .L3
	.arm
	.syntax unified
	b	.L8
.L12:
	ldr	r0, [sp, #24]
	.syntax divided
	cmp r0, #0
	beq .L13
	.arm
	.syntax unified
	ldr	r3, [sp, #20]
	rsb	r9, r2, #0
.L14:
	.syntax divided
	adds r2, r0, r2
	bgt .L15
	.arm
	.syntax unified
	sub	r9, r9, r0
	b	.L14
.L13:
	.syntax divided
	pop {r4, ip}
	.arm
	.syntax unified
	mov	r2, #0
	b	.L16
.L10:
	ldr	r2, [sp, #16]
	.syntax divided
	cmp r2, #0
	ldrne r3, [sp, #12]
	bne .L11
	.arm
	.syntax unified
.L37:
.L16:
	strb	r2, [r4]
	lsr	r0, r5, #30
	bic	r5, r5, #-1073741824
	rsb	r0, r0, #3
	lsl	r0, r0, #3
	ror	r6, r6, r0
	str	r6, [r5], #4
	b	.L17
.L2:
	.syntax divided
	push {r4, ip}
	ldr lr, [r4, #28]
	.arm
	.syntax unified
	ldr	r1, [r4, #32]
	.syntax divided
	mul r4, ip, r1
	.arm
	.syntax unified
	ldrsb	r0, [r3]
	.syntax divided
	ldrsb r1, [r3, #1]!
	.arm
	.syntax unified
	sub	r1, r1, r0
.L18:
	ldr	r6, [r5]
.L19:
	.syntax divided
	mul r9, lr, r1
	.arm
	.syntax unified
	add	r9, r0, r9, asr #23
	.syntax divided
	mul ip, r10, r9
	.arm
	.syntax unified
	bic	ip, ip, #16711680
	add	r6, ip, r6, ror #8
	.syntax divided
	add lr, lr, r4
	lsrs r9, lr, #23
	beq .L20
	bic lr, lr, #0x3f800000
	subs r2, r2, r9
	ble .L12
	subs r9, r9, #1
	addeq r0, r0, r1
	.arm
	.syntax unified
.L15:
	.syntax divided
	ldrnesb r0, [r3, r9]!
	ldrsb r1, [r3, #1]!
	.arm
	.syntax unified
	sub	r1, r1, r0
.L20:
	.syntax divided
	adds r5, r5, #0x40000000
	blo .L19
	.arm
	.syntax unified
	str	r6, [r5], #4
	.syntax divided
	subs r8, r8, #4
	bgt .L18
	.arm
	.syntax unified
	sub	r3, r3, #1
	.syntax divided
	pop {r4, ip}
	str lr, [r4, #28]
	.arm
	.syntax unified
.L8:
	str	r2, [r4, #24]
	str	r3, [r4, #40]
.L17:
	ldr	r8, [sp]
	.syntax divided
	add r0, pc, #1
	bx r0
	.arm
	.syntax unified
	.size	func_0805B1E4, .-func_0805B1E4

.align 2, 0
