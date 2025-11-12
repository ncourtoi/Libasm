section .text
    global _start

_start:
    mov rax, 1          ; syscall: write
    mov rdi, 1          ; file descriptor: stdout
    mov rsi, message     ; adresse de la chaîne
    mov rdx, len         ; longueur de la chaîne
    syscall              ; appel système (écriture)

    mov rax, 60         ; syscall: exit
    xor rdi, rdi         ; code retour 0
    syscall

section .data
message: db "Hello, world!", 10
len: equ $ - message
