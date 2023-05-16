	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_inorder                ## -- Begin function inorder
	.p2align	4, 0x90
_inorder:                               ## @inorder
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	LBB0_2
## %bb.1:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdi
	callq	_inorder
	movq	-8(%rbp), %rax
	movl	(%rax), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-8(%rbp), %rcx
	movq	16(%rcx), %rdi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	callq	_inorder
LBB0_2:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d "

.subsections_via_symbols
