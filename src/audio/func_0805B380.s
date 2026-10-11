/* The Thumb continuation advances channels and restores the sound entry's saved frame. */
.cpu arm7tdmi
	.arch armv4t
	.text
	.align	1
	.global	func_0805B380
	.syntax unified
	.code	16
	.thumb_func
	.type	func_0805B380, %function
func_0805B380:
	ldr	r0, [sp, #4]
	.syntax divided
	sub r0, #1
	ble .L2
	.thumb
	.syntax unified
	adds	r4, r4, #64
	.syntax divided
	b func_0805B0E8
	.thumb
	.syntax unified
.L2:
	ldr	r0, [sp, #24]
	.syntax divided
	ldr r3, audio_magic
	.thumb
	.syntax unified
	str	r3, [r0]
	.syntax divided
	add sp, #28
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov r9, r1
	mov r10, r2
	mov r11, r3
	pop {r3}
	.thumb
	.syntax unified
	.size	func_0805B380, .-func_0805B380
	.align	1
	.global	func_0805B39E
	.syntax unified
	.code	16
	.thumb_func
	.type	func_0805B39E, %function
func_0805B39E:
	.syntax divided
	bx r3
	.thumb
	.syntax unified
	.size	func_0805B39E, .-func_0805B39E
	.global	audio_magic
	.text
	.align	1
	.type	audio_magic, %object
	.size	audio_magic, 4
audio_magic:
	.4byte	1752395091

.align 2, 0
