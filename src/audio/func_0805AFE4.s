/* The SDK multiply helper returns the high 32 bits in r0. */
.cpu arm7tdmi
	.arch armv4t
	.text
	.align	2
	.global	func_0805AFE4
	.syntax unified
	.arm
	.type	func_0805AFE4, %function
func_0805AFE4:
	umull	r2, r3, r0, r1
	.syntax divided
	add r0, r3, #0
	.arm
	.syntax unified
	bx	lr
	.size	func_0805AFE4, .-func_0805AFE4

.align 2, 0
