global main
extern scanf
extern printf

section .data
    d_fmt_out: db "%d", 10, 0
    d_fmt_in: db "%d", 0

section .bss
    lhs: resd 1
    rhs: resd 1

section .text
main:
    push rbp
    mov rdi, d_fmt_in
    mov rsi, dword lhs
    call scanf
    pop rbp

    push rbp
    mov rdi, d_fmt_in
    mov rsi, dword rhs
    call scanf
    pop rbp

    mov eax, dword [lhs]
    mov ebx, dword [rhs]
    sub eax, ebx

    push rbp
    mov rdi, d_fmt_out
    mov esi, eax
    call printf
    pop rbp

    mov rax, 0
    ret