global main

section .data
    message db "Liberté, égalité, fraternité!",10

section .text
main:
    mov rax, 1
    mov rdi, 1
    mov rsi, message
    mov rdx, 34
    syscall

    mov rax, 60
    mov rdi, 0
    syscall