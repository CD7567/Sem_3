global main
extern scanf
extern printf

section .data
    s_fmt_out: db "%s", 10, 0
    d_fmt_in: db "%llu", 0
    y_msg: db "YES", 10, 0
    n_msg: db "NO", 10, 0

section .bss
    lhs: resq 1
    rhs: resq 1

section .text
main:
    push rbp
    mov rdi, d_fmt_in
    mov rsi, qword lhs
    call scanf
    pop rbp

    push rbp
    mov rdi, d_fmt_in
    mov rsi, qword rhs
    call scanf
    pop rbp

    mov rax, qword [lhs]
    mov rbx, qword [rhs]

    add rax, rbx
    jc of_out

    push rbp
    mov rdi, s_fmt_out
    mov rsi, n_msg
    call printf
    pop rbp

    jmp end

of_out:
    push rbp
    mov rdi, s_fmt_out
    mov rsi, y_msg
    call printf
    pop rbp

end:
    mov rax, 0
    ret