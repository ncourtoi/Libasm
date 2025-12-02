section .text
    global ft_strcmp

ft_strcmp:
    mov rax, 0
    mov cl, 0        

.loop:
    mov dl, [rdi + rax]
    mov cl, [rsi + rax]
    cmp dl, cl       
    jne .end
    cmp dl, 0
    je .end
    inc rax             
    jmp .loop

.end:
    sub dl, cl
    movsx rax, dl
    ret                
