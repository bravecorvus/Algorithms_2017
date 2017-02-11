	.const
__ZStL19piecewise_construct:
	.space 1
	.static_data
__ZStL8__ioinit:
	.space	1
	.globl _start_time
	.zerofill __DATA,__pu_bss3,_start_time,8,3
	.text
	.globl __Z8read_TSCv
	.weak_definition __Z8read_TSCv
__Z8read_TSCv:
LFB1507:
	pushq	%rbp
LCFI0:
	movq	%rsp, %rbp
LCFI1:
# 15 "elapsed_time.h" 1
	rdtsc
# 0 "" 2
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
LCFI2:
	ret
LFE1507:
	.globl __Z11start_timerv
	.weak_definition __Z11start_timerv
__Z11start_timerv:
LFB1508:
	pushq	%rbp
LCFI3:
	movq	%rsp, %rbp
LCFI4:
	call	__Z8read_TSCv
	movq	%rax, _start_time(%rip)
	nop
	popq	%rbp
LCFI5:
	ret
LFE1508:
	.globl __Z12elapsed_timev
	.weak_definition __Z12elapsed_timev
__Z12elapsed_timev:
LFB1509:
	pushq	%rbp
LCFI6:
	movq	%rsp, %rbp
LCFI7:
	subq	$16, %rsp
	call	__Z8read_TSCv
	movq	%rax, -8(%rbp)
	movq	_start_time(%rip), %rax
	movq	-8(%rbp), %rdx
	subq	%rax, %rdx
	movq	%rdx, %rax
	testq	%rax, %rax
	js	L5
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	jmp	L6
L5:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
L6:
	movsd	%xmm0, -16(%rbp)
	movsd	-16(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	leave
LCFI8:
	ret
LFE1509:
	.cstring
	.align 3
lC0:
	.ascii "total cycles after initializing i and x \0"
lC1:
	.ascii "total cycles at for loop \0"
lC2:
	.ascii " \0"
lC3:
	.ascii "total cycles after print \0"
	.text
	.globl _main
_main:
LFB1510:
	pushq	%rbp
LCFI9:
	movq	%rsp, %rbp
LCFI10:
	subq	$32, %rsp
	call	__Z11start_timerv
	call	__Z12elapsed_timev
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	leaq	lC0(%rip), %rsi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	__ZNSolsEd
	movq	%rax, %rdx
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	__ZNSolsEPFRSoS_E
	movl	$0, -4(%rbp)
L10:
	cmpl	$499, -4(%rbp)
	jg	L9
	call	__Z11start_timerv
	movl	-4(%rbp), %eax
	movl	%eax, -20(%rbp)
	call	__Z12elapsed_timev
	movq	%xmm0, %rax
	movq	%rax, -32(%rbp)
	leaq	lC1(%rip), %rsi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	__ZNSolsEi
	leaq	lC2(%rip), %rsi
	movq	%rax, %rdi
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	__ZNSolsEd
	movq	%rax, %rdx
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	__ZNSolsEPFRSoS_E
	addl	$1, -4(%rbp)
	jmp	L10
L9:
	call	__Z11start_timerv
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZNSolsEi
	movq	%rax, %rdx
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	__ZNSolsEPFRSoS_E
	call	__Z12elapsed_timev
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	leaq	lC3(%rip), %rsi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	__ZNSolsEd
	movq	%rax, %rdx
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	__ZNSolsEPFRSoS_E
	call	__Z11start_timerv
	movl	$0, %eax
	leave
LCFI11:
	ret
LFE1510:
__Z41__static_initialization_and_destruction_0ii:
LFB1955:
	pushq	%rbp
LCFI12:
	movq	%rsp, %rbp
LCFI13:
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	L14
	cmpl	$65535, -8(%rbp)
	jne	L14
	leaq	__ZStL8__ioinit(%rip), %rdi
	call	__ZNSt8ios_base4InitC1Ev
	leaq	___dso_handle(%rip), %rdx
	leaq	__ZStL8__ioinit(%rip), %rsi
	movq	__ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	___cxa_atexit
L14:
	nop
	leave
LCFI14:
	ret
LFE1955:
__GLOBAL__sub_I_ex3.cpp:
LFB1956:
	pushq	%rbp
LCFI15:
	movq	%rsp, %rbp
LCFI16:
	movl	$65535, %esi
	movl	$1, %edi
	call	__Z41__static_initialization_and_destruction_0ii
	popq	%rbp
LCFI17:
	ret
LFE1956:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB1507-.
	.set L$set$2,LFE1507-LFB1507
	.quad L$set$2
	.byte	0
	.byte	0x4
	.set L$set$3,LCFI0-LFB1507
	.long L$set$3
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$5,LCFI2-LCFI1
	.long L$set$5
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE1:
LSFDE3:
	.set L$set$6,LEFDE3-LASFDE3
	.long L$set$6
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB1508-.
	.set L$set$7,LFE1508-LFB1508
	.quad L$set$7
	.byte	0
	.byte	0x4
	.set L$set$8,LCFI3-LFB1508
	.long L$set$8
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$9,LCFI4-LCFI3
	.long L$set$9
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$10,LCFI5-LCFI4
	.long L$set$10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE3:
LSFDE5:
	.set L$set$11,LEFDE5-LASFDE5
	.long L$set$11
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB1509-.
	.set L$set$12,LFE1509-LFB1509
	.quad L$set$12
	.byte	0
	.byte	0x4
	.set L$set$13,LCFI6-LFB1509
	.long L$set$13
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$14,LCFI7-LCFI6
	.long L$set$14
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$15,LCFI8-LCFI7
	.long L$set$15
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE5:
LSFDE7:
	.set L$set$16,LEFDE7-LASFDE7
	.long L$set$16
LASFDE7:
	.long	LASFDE7-EH_frame1
	.quad	LFB1510-.
	.set L$set$17,LFE1510-LFB1510
	.quad L$set$17
	.byte	0
	.byte	0x4
	.set L$set$18,LCFI9-LFB1510
	.long L$set$18
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$19,LCFI10-LCFI9
	.long L$set$19
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$20,LCFI11-LCFI10
	.long L$set$20
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE7:
LSFDE9:
	.set L$set$21,LEFDE9-LASFDE9
	.long L$set$21
LASFDE9:
	.long	LASFDE9-EH_frame1
	.quad	LFB1955-.
	.set L$set$22,LFE1955-LFB1955
	.quad L$set$22
	.byte	0
	.byte	0x4
	.set L$set$23,LCFI12-LFB1955
	.long L$set$23
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$24,LCFI13-LCFI12
	.long L$set$24
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$25,LCFI14-LCFI13
	.long L$set$25
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE9:
LSFDE11:
	.set L$set$26,LEFDE11-LASFDE11
	.long L$set$26
LASFDE11:
	.long	LASFDE11-EH_frame1
	.quad	LFB1956-.
	.set L$set$27,LFE1956-LFB1956
	.quad L$set$27
	.byte	0
	.byte	0x4
	.set L$set$28,LCFI15-LFB1956
	.long L$set$28
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$29,LCFI16-LCFI15
	.long L$set$29
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$30,LCFI17-LCFI16
	.long L$set$30
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE11:
	.mod_init_func
	.align 3
	.quad	__GLOBAL__sub_I_ex3.cpp
	.constructor
	.destructor
	.align 1
	.subsections_via_symbols
