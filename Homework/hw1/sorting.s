	.text
	.align 1,0x90
	.globl __ZNSt6chrono8durationIxSt5ratioILl1ELl1000000000EEEC1IxvEERKT_
	.weak_definition __ZNSt6chrono8durationIxSt5ratioILl1ELl1000000000EEEC1IxvEERKT_
__ZNSt6chrono8durationIxSt5ratioILl1ELl1000000000EEEC1IxvEERKT_:
LFB255:
	pushq	%rbp
LCFI0:
	movq	%rsp, %rbp
LCFI1:
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
LCFI2:
	ret
LFE255:
	.align 1,0x90
	.globl __ZNKSt6chrono8durationIxSt5ratioILl1ELl1000000000EEE5countEv
	.weak_definition __ZNKSt6chrono8durationIxSt5ratioILl1ELl1000000000EEE5countEv
__ZNKSt6chrono8durationIxSt5ratioILl1ELl1000000000EEE5countEv:
LFB259:
	pushq	%rbp
LCFI3:
	movq	%rsp, %rbp
LCFI4:
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
LCFI5:
	ret
LFE259:
	.align 1,0x90
	.globl __ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILl1ELl1000000000EEEEE16time_since_epochEv
	.weak_definition __ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILl1ELl1000000000EEEEE16time_since_epochEv
__ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILl1ELl1000000000EEEEE16time_since_epochEv:
LFB261:
	pushq	%rbp
LCFI6:
	movq	%rsp, %rbp
LCFI7:
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
LCFI8:
	ret
LFE261:
	.const
__ZStL19piecewise_construct:
	.space 1
	.static_data
__ZStL8__ioinit:
	.space	1
	.text
	.globl __ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILl1ELl1000000000EEEES2_ILl1ELl1EExLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE
	.weak_definition __ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILl1ELl1000000000EEEES2_ILl1ELl1EExLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE
__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILl1ELl1000000000EEEES2_ILl1ELl1EExLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE:
LFB1833:
	pushq	%rbp
LCFI9:
	movq	%rsp, %rbp
LCFI10:
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	__ZNKSt6chrono8durationIxSt5ratioILl1ELl1000000000EEE5countEv
	movq	%rax, -8(%rbp)
	leaq	-8(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	__ZNSt6chrono8durationIxSt5ratioILl1ELl1000000000EEEC1IxvEERKT_
	movq	-16(%rbp), %rax
	leave
LCFI11:
	ret
LFE1833:
	.globl __ZNSt6chrono13duration_castINS_8durationIxSt5ratioILl1ELl1000000000EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE
	.weak_definition __ZNSt6chrono13duration_castINS_8durationIxSt5ratioILl1ELl1000000000EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE
__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILl1ELl1000000000EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE:
LFB1832:
	pushq	%rbp
LCFI12:
	movq	%rsp, %rbp
LCFI13:
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	__ZNSt6chrono20__duration_cast_implINS_8durationIxSt5ratioILl1ELl1000000000EEEES2_ILl1ELl1EExLb1ELb1EE6__castIxS3_EES4_RKNS1_IT_T0_EE
	leave
LCFI14:
	ret
LFE1832:
	.cstring
lC0:
	.ascii "Algorithm took \0"
lC1:
	.ascii " nanoseconds to complete\0"
	.text
	.globl _main
_main:
LFB1831:
	pushq	%rbp
LCFI15:
	movq	%rsp, %rbp
LCFI16:
	pushq	%rbx
	subq	$168, %rsp
LCFI17:
	movl	$0, -160(%rbp)
	movl	$1, -156(%rbp)
	movl	$2, -152(%rbp)
	movl	$3, -148(%rbp)
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movq	%rax, -112(%rbp)
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	__ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILl1ELl1000000000EEEEE16time_since_epochEv
	movq	%rax, -128(%rbp)
	leaq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILl1ELl1000000000EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE
	movq	%rax, -144(%rbp)
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
	call	__ZNKSt6chrono8durationIxSt5ratioILl1ELl1000000000EEE5countEv
	movq	%rax, -48(%rbp)
	movl	$0, -20(%rbp)
L14:
	movl	-20(%rbp), %eax
	cltq
	cmpq	$3, %rax
	ja	L11
	cmpl	$0, -20(%rbp)
	jne	L12
	movl	-160(%rbp), %eax
	movl	%eax, -176(%rbp)
	jmp	L13
L12:
	movl	-176(%rbp), %edx
	movl	-20(%rbp), %eax
	cltq
	movl	-160(%rbp,%rax,4), %eax
	cmpl	%eax, %edx
	jge	L13
	movl	-20(%rbp), %eax
	cltq
	movl	-160(%rbp,%rax,4), %eax
	movl	%eax, -176(%rbp)
L13:
	addl	$1, -20(%rbp)
	jmp	L14
L11:
	movl	-176(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	$1, -32(%rbp)
L20:
	movl	-32(%rbp), %eax
	cltq
	cmpq	$3, %rax
	ja	L15
	movl	$0, -36(%rbp)
L19:
	movl	-36(%rbp), %eax
	cltq
	cmpq	$3, %rax
	ja	L16
	cmpl	$0, -36(%rbp)
	jne	L17
	movl	-160(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jge	L17
	movl	-160(%rbp), %eax
	movl	%eax, -28(%rbp)
	jmp	L18
L17:
	movl	-36(%rbp), %eax
	cltq
	movl	-160(%rbp,%rax,4), %eax
	cmpl	-28(%rbp), %eax
	jle	L18
	movl	-36(%rbp), %eax
	cltq
	movl	-160(%rbp,%rax,4), %eax
	cmpl	-24(%rbp), %eax
	jge	L18
	movl	-36(%rbp), %eax
	cltq
	movl	-160(%rbp,%rax,4), %eax
	movl	%eax, -28(%rbp)
L18:
	addl	$1, -36(%rbp)
	jmp	L19
L16:
	movl	-32(%rbp), %eax
	cltq
	movl	-28(%rbp), %edx
	movl	%edx, -176(%rbp,%rax,4)
	movl	-28(%rbp), %eax
	movl	%eax, -24(%rbp)
	addl	$1, -32(%rbp)
	jmp	L20
L15:
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movq	%rax, -64(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	__ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIxSt5ratioILl1ELl1000000000EEEEE16time_since_epochEv
	movq	%rax, -80(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	__ZNSt6chrono13duration_castINS_8durationIxSt5ratioILl1ELl1000000000EEEExS3_EENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES7_E4typeERKNS1_IT0_T1_EE
	movq	%rax, -96(%rbp)
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	__ZNKSt6chrono8durationIxSt5ratioILl1ELl1000000000EEE5countEv
	movq	%rax, -56(%rbp)
	movl	$0, -40(%rbp)
L22:
	movl	-40(%rbp), %eax
	cltq
	cmpq	$3, %rax
	ja	L21
	movl	-40(%rbp), %eax
	cltq
	movl	-176(%rbp,%rax,4), %eax
	movl	%eax, %esi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZNSolsEi
	movq	%rax, %rdx
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	__ZNSolsEPFRSoS_E
	addl	$1, -40(%rbp)
	jmp	L22
L21:
	movq	-56(%rbp), %rax
	subq	-48(%rbp), %rax
	movq	%rax, %rbx
	leaq	lC0(%rip), %rsi
	movq	__ZSt4cout@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	__ZNSolsEm
	leaq	lC1(%rip), %rsi
	movq	%rax, %rdi
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movq	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	__ZNSolsEPFRSoS_E
	movl	$0, %eax
	addq	$168, %rsp
	popq	%rbx
	popq	%rbp
LCFI18:
	ret
LFE1831:
__Z41__static_initialization_and_destruction_0ii:
LFB2278:
	pushq	%rbp
LCFI19:
	movq	%rsp, %rbp
LCFI20:
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	L26
	cmpl	$65535, -8(%rbp)
	jne	L26
	leaq	__ZStL8__ioinit(%rip), %rdi
	call	__ZNSt8ios_base4InitC1Ev
	leaq	___dso_handle(%rip), %rdx
	leaq	__ZStL8__ioinit(%rip), %rsi
	movq	__ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	___cxa_atexit
L26:
	nop
	leave
LCFI21:
	ret
LFE2278:
__GLOBAL__sub_I_sorting.cpp:
LFB2279:
	pushq	%rbp
LCFI22:
	movq	%rsp, %rbp
LCFI23:
	movl	$65535, %esi
	movl	$1, %edi
	call	__Z41__static_initialization_and_destruction_0ii
	popq	%rbp
LCFI24:
	ret
LFE2279:
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
	.quad	LFB255-.
	.set L$set$2,LFE255-LFB255
	.quad L$set$2
	.byte	0
	.byte	0x4
	.set L$set$3,LCFI0-LFB255
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
	.quad	LFB259-.
	.set L$set$7,LFE259-LFB259
	.quad L$set$7
	.byte	0
	.byte	0x4
	.set L$set$8,LCFI3-LFB259
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
	.quad	LFB261-.
	.set L$set$12,LFE261-LFB261
	.quad L$set$12
	.byte	0
	.byte	0x4
	.set L$set$13,LCFI6-LFB261
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
	.quad	LFB1833-.
	.set L$set$17,LFE1833-LFB1833
	.quad L$set$17
	.byte	0
	.byte	0x4
	.set L$set$18,LCFI9-LFB1833
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
	.quad	LFB1832-.
	.set L$set$22,LFE1832-LFB1832
	.quad L$set$22
	.byte	0
	.byte	0x4
	.set L$set$23,LCFI12-LFB1832
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
	.quad	LFB1831-.
	.set L$set$27,LFE1831-LFB1831
	.quad L$set$27
	.byte	0
	.byte	0x4
	.set L$set$28,LCFI15-LFB1831
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
	.byte	0x83
	.byte	0x3
	.byte	0x4
	.set L$set$31,LCFI18-LCFI17
	.long L$set$31
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE11:
LSFDE13:
	.set L$set$32,LEFDE13-LASFDE13
	.long L$set$32
LASFDE13:
	.long	LASFDE13-EH_frame1
	.quad	LFB2278-.
	.set L$set$33,LFE2278-LFB2278
	.quad L$set$33
	.byte	0
	.byte	0x4
	.set L$set$34,LCFI19-LFB2278
	.long L$set$34
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$35,LCFI20-LCFI19
	.long L$set$35
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$36,LCFI21-LCFI20
	.long L$set$36
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE13:
LSFDE15:
	.set L$set$37,LEFDE15-LASFDE15
	.long L$set$37
LASFDE15:
	.long	LASFDE15-EH_frame1
	.quad	LFB2279-.
	.set L$set$38,LFE2279-LFB2279
	.quad L$set$38
	.byte	0
	.byte	0x4
	.set L$set$39,LCFI22-LFB2279
	.long L$set$39
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$40,LCFI23-LCFI22
	.long L$set$40
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$41,LCFI24-LCFI23
	.long L$set$41
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.align 3
LEFDE15:
	.mod_init_func
	.align 3
	.quad	__GLOBAL__sub_I_sorting.cpp
	.constructor
	.destructor
	.align 1
	.subsections_via_symbols
