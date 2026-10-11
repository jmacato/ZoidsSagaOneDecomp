/* The mixer callback switches from Thumb to ARM without a C call frame. */
.cpu arm7tdmi
	.arch armv4t
	.text
	.align	1
	.global	func_0805B074
	.syntax unified
	.code	16
	.thumb_func
	.type	func_0805B074, %function
func_0805B074:
	ldrb	r3, [r0, #5]
	.syntax divided
	cmp r3, #0
	beq func_0805B0C0
	adr r1, .+6
	bx r1
	.thumb
	.syntax unified
	.size	func_0805B074, .-func_0805B074
	.global	mixer_padding
	.text
	.align	1
	.type	mixer_padding, %object
	.size	mixer_padding, 2
mixer_padding:
	.space	2

.align 2, 0
