section .data
    digit db 0, 10

section .text
    global main

main:
    push 4
    push 8
    push 3

    pop rax
    call _printRAXDigits
    pop rax
    call _printRAXDigits
    pop rax
    call _printRAXDigits

    mov rax, 60         ; syscall: exit
    xor rdi, rdi         ; code retour 0
    syscall
    ret

_printRAXDigits:
    add rax, 48
    mov [digit], al
    mov rax, 1
    mov rdi, 1
    mov rsi, digit
    mov rdx, 2
    syscall
    ret

