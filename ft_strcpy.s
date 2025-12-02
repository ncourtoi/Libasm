section .text
    global ft_strcpy

ft_strcpy:
    mov rax , 0          

.loop:
    mov cl, [rsi + rax]
    mov [rdi + rax], cl
    cmp cl, 0
    je .end
    inc rax             
    jmp .loop

.end:
    mov rdi, rax
    ret