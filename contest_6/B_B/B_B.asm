global main
extern scanf
extern printf

section .data
    d_fmt_out: db "%d", 10, 0
    d_fmt_in: db "%d", 0

section .bss
    num: resd 1

section .text
main:
    push rbp
    mov rdi, d_fmt_in
    mov rsi, dword num
    call scanf
    pop rbp

    mov eax, dword [num]
    and eax, 0x0000ffff

    push rbp
    mov rdi, d_fmt_out
    mov esi, eax
    call printf
    pop rbp

    mov rax, 0
    ret