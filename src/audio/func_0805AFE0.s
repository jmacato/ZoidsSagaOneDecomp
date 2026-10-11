/* The mixer veneer switches from Thumb to ARM for the multiply helper. */
.cpu arm7tdmi
	.arch armv4t
	.text
	.align	1
	.p2align 2,,3
	.global	func_0805AFE0
	.syntax unified
	.code	16
	.thumb_func
	.type	func_0805AFE0, %function
func_0805AFE0:
	.syntax divided
	adr r2, . + 4
	bx r2
	.thumb
	.syntax unified
	.size	func_0805AFE0, .-func_0805AFE0

.align 2, 0
