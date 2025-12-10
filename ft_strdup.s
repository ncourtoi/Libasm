section .text
global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

ft_strdup:
	push rdi
	call ft_strlen

	inc rax
	mov rdi, rax
	call malloc wrt ..plt
	test rax, rax
	jz .malloc_error

.malloc_success:
	mov rdi, rax
	pop rsi

	push rdi
	call ft_strcpy

	pop rax
	ret

.malloc_error:
	add rsp, 8
	ret