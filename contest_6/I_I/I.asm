global main
extern scanf
extern printf

section .data
    ld_fmt_out: db "%lld", 32, 0
    ld_fmt_in: db "%lld", 0
    end_fmt_out: db 10

section .bss
    amount: resq 1
    num: resq 1

section .text
main:
    push rbp
    mov rdi, ld_fmt_in
    mov rsi, qword amount
    call scanf
    pop rbp

    mov rbx, qword [amount]

 loop_in:
    push rbp
    mov rdi, ld_fmt_in
    mov rsi, qword num
    call scanf
    pop rbp

    mov rax, qword [num]

    push rax
    sub rsp, 8
    dec rbx
    cmp rbx, 0
    jg loop_in

    mov rbx, qword [amount]
    add rsp, 8

 loop_out:
    pop rax

    push rbp
    mov rdi, ld_fmt_out
    mov rsi, rax
    call printf
    pop rbp

    add rsp, 8

    dec rbx
    cmp rbx, 0
    jg loop_out
    
    sub rsp, 8

    push rbp
    mov rdi, end_fmt_out
    call printf
    pop rbp

    mov rax, 0
    ret