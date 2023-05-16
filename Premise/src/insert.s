	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_insert                 ## -- Begin function insert
	.p2align	4, 0x90
_insert:                                ## @insert
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movl	%esi, -20(%rbp)
	cmpq	$0, -16(%rbp)
	jne	LBB0_2
## %bb.1:
	movl	-20(%rbp), %edi
	callq	_newNode
	movq	%rax, -8(%rbp)
	jmp	LBB0_6
LBB0_2:
	movl	-20(%rbp), %eax
	movq	-16(%rbp), %rcx
	cmpl	(%rcx), %eax
	jge	LBB0_4
## %bb.3:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdi
	movl	-20(%rbp), %esi
	callq	_insert
	movq	-16(%rbp), %rcx
	movq	%rax, 8(%rcx)
	jmp	LBB0_5
LBB0_4:
	movq	-16(%rbp), %rax
	movq	16(%rax), %rdi
	movl	-20(%rbp), %esi
	callq	_insert
	movq	-16(%rbp), %rcx
	movq	%rax, 16(%rcx)
LBB0_5:
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB0_6:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
