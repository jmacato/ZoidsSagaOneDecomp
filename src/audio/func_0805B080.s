/* The BIOS copies this ARM mixer to IWRAM.
 * Keep its shared frame and Thumb continuation labels.
 * This sound mixer remains an assembly exception to C completion. */
.cpu arm7tdmi
	.arch armv4t
	.text
	.align	2
	.global	func_0805B080
	.syntax unified
	.arm
	.type	func_0805B080, %function
func_0805B080:
	.syntax divided
	cmp r4, #2
	addeq r7, r0, #0x350
	addne r7, r5, r8
	.arm
	.syntax unified
	mov	r4, r8
.L2:
	ldrsb	r0, [r5]
	.syntax divided
	ldrsb r1, [r7], #1
	.arm
	.syntax unified
	add	r0, r0, r1
	.syntax divided
	mul r1, r0, r3
	.arm
	.syntax unified
	asr	r0, r1, #8
	tst	r0, #128
	addne	r0, r0, #1
	strb	r0, [r5], #1
	.syntax divided
	subs r4, r4, #1
	bgt .L2
	add r0, pc, #31
	bx r0
	.arm
	.syntax unified
	.size	func_0805B080, .-func_0805B080
	.align	1
	.global	func_0805B0C0
	.cpu arm7tdmi
	.arch armv4t
	.syntax unified
	.code	16
	.thumb_func
	.type	func_0805B0C0, %function
func_0805B0C0:
	movs	r0, #0
	mov	r1, r8
	.syntax divided
	lsr r1, r1, #3
	blo .L11
	stm r5!, {r0}
	.thumb
	.syntax unified
.L11:
	.syntax divided
	lsr r1, r1, #1
	blo .L13
	stm r5!, {r0}
	stm r5!, {r0}
	.thumb
	.syntax unified
.L13:
	.syntax divided
	stm r5!, {r0}
	stm r5!, {r0}
	stm r5!, {r0}
	stm r5!, {r0}
	sub r1, #1
	bgt .L13
	.thumb
	.syntax unified
	ldr	r4, [sp, #24]
	ldr	r0, [r4, #24]
	mov	ip, r0
	ldrb	r0, [r4, #6]
	adds	r4, r4, #80
	.syntax divided
	.global func_0805B0E8
func_0805B0E8:
	.thumb
	.syntax unified
	str	r0, [sp, #4]
	ldr	r3, [r4, #36]
	ldr	r0, [sp, #20]
	.syntax divided
	cmp r0, #0
	beq func_0805B108
	ldr r1, reverb_scanline
	.thumb
	.syntax unified
	ldrb	r1, [r1]
	.syntax divided
	cmp r1, #160
	bhs .L14
	.thumb
	.syntax unified
	adds	r1, r1, #228
.L14:
	.syntax divided
	cmp r1, r0
	blo func_0805B108
	b func_0805B38A
	.thumb
	.syntax unified
	.size	func_0805B0C0, .-func_0805B0C0
	.global	reverb_deadline_padding
	.text
	.align	1
	.type	reverb_deadline_padding, %object
	.size	reverb_deadline_padding, 2
reverb_deadline_padding:
	.space	2
	.global	reverb_scanline
	.align	2
	.type	reverb_scanline, %object
	.size	reverb_scanline, 4
reverb_scanline:
	.word	67108870
	.text
	.align	1
	.global	func_0805B108
	.syntax unified
	.code	16
	.thumb_func
	.type	func_0805B108, %function
func_0805B108:
	ldrb	r6, [r4]
	movs	r0, #199
	.syntax divided
	tst r0, r6
	bne .L21
	b func_0805B380
	.thumb
	.syntax unified
.L21:
	movs	r0, #128
	.syntax divided
	tst r0, r6
	beq .L22
	.thumb
	.syntax unified
	movs	r0, #64
	.syntax divided
	tst r0, r6
	bne .L23
	.thumb
	.syntax unified
	movs	r6, #3
	strb	r6, [r4]
	.syntax divided
	add r0, r3, #0
	.thumb
	.syntax unified
	adds	r0, r0, #16
	str	r0, [r4, #40]
	ldr	r0, [r3, #12]
	str	r0, [r4, #24]
	movs	r5, #0
	strb	r5, [r4, #9]
	str	r5, [r4, #28]
	ldrb	r2, [r3, #3]
	movs	r0, #192
	.syntax divided
	tst r0, r2
	beq .L24
	.thumb
	.syntax unified
	movs	r0, #16
	orrs	r6, r0
	strb	r6, [r4]
	b	.L24
.L22:
	ldrb	r5, [r4, #9]
	movs	r0, #4
	.syntax divided
	tst r0, r6
	beq .L25
	.thumb
	.syntax unified
	ldrb	r0, [r4, #13]
	subs	r0, r0, #1
	strb	r0, [r4, #13]
	.syntax divided
	bhi .L26
	.thumb
	.syntax unified
.L23:
	movs	r0, #0
	strb	r0, [r4]
	.syntax divided
	b func_0805B380
	.thumb
	.syntax unified
.L25:
	movs	r0, #64
	.syntax divided
	tst r0, r6
	beq .L27
	.thumb
	.syntax unified
	ldrb	r0, [r4, #7]
	.syntax divided
	mul r5, r0
	.thumb
	.syntax unified
	lsrs	r5, r5, #8
	ldrb	r0, [r4, #12]
	.syntax divided
	cmp r5, r0
	bhi .L26
	.thumb
	.syntax unified
.L28:
	ldrb	r5, [r4, #12]
	.syntax divided
	cmp r5, #0
	beq .L23
	.thumb
	.syntax unified
	movs	r0, #4
	orrs	r6, r0
	strb	r6, [r4]
	b	.L26
.L27:
	movs	r2, #3
	ands	r2, r6
	.syntax divided
	cmp r2, #2
	bne .L29
	.thumb
	.syntax unified
	ldrb	r0, [r4, #5]
	.syntax divided
	mul r5, r0
	.thumb
	.syntax unified
	lsrs	r5, r5, #8
	ldrb	r0, [r4, #6]
	.syntax divided
	cmp r5, r0
	bhi .L26
	add r5, r0, #0
	beq .L28
	.thumb
	.syntax unified
	subs	r6, r6, #1
	strb	r6, [r4]
	b	.L26
.L29:
	.syntax divided
	cmp r2, #3
	bne .L26
	.thumb
	.syntax unified
.L24:
	ldrb	r0, [r4, #4]
	adds	r5, r5, r0
	.syntax divided
	cmp r5, #255
	blo .L26
	.thumb
	.syntax unified
	movs	r5, #255
	subs	r6, r6, #1
	strb	r6, [r4]
.L26:
	strb	r5, [r4, #9]
	ldr	r0, [sp, #24]
	ldrb	r0, [r0, #7]
	adds	r0, r0, #1
	.syntax divided
	mul r0, r5
	.thumb
	.syntax unified
	lsrs	r5, r0, #4
	ldrb	r0, [r4, #2]
	ldrb	r1, [r4, #3]
	adds	r0, r0, r1
	.syntax divided
	mul r0, r5
	.thumb
	.syntax unified
	lsrs	r0, r0, #9
	strb	r0, [r4, #10]
	movs	r0, #16
	ands	r0, r6
	str	r0, [sp, #16]
	.syntax divided
	beq .L30
	add r0, r3, #0
	.thumb
	.syntax unified
	adds	r0, r0, #16
	ldr	r1, [r3, #8]
	adds	r0, r0, r1
	str	r0, [sp, #12]
	ldr	r0, [r3, #12]
	subs	r0, r0, r1
	str	r0, [sp, #16]
.L30:
	ldr	r5, [sp, #8]
	ldr	r2, [r4, #24]
	ldr	r3, [r4, #40]
	.syntax divided
	adr r0, .+6
	bx r0
	.thumb
	.syntax unified
	.size	func_0805B108, .-func_0805B108
	.global	reverb_tail_padding
	.section	.text
	.align	1
	.type	reverb_tail_padding, %object
	.size	reverb_tail_padding, 2
reverb_tail_padding:
	.space	2
	.cpu arm7tdmi
	.arch armv4t

.align 2, 0
