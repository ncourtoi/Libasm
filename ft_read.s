global ft_read
extern __errno_location

section .text

ft_read:
    mov     rax, 0          
    syscall

    cmp     rax, 0
    jge     .end

    neg     rax
    mov     rdi, rax        
    call    __errno_location wrt ..plt
    mov     [rax], rdi
    mov     rax, -1

.end:
    ret
