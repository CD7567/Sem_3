global main
extern scanf
extern printf

section .data
    ld_fmt_out: db "%lld", 10, 0
    ld_fmt_in: db "%lld%lld", 0

section .bss
    lhs: resq 1
    rhs: resq 1

section .text
main:
    push rbp
    mov rdi, ld_fmt_in
    mov rsi, qword lhs
    mov rdx, qword rhs
    call scanf
    pop rbp

    mov rdi, qword [lhs]
    mov rsi, qword [rhs]

    cmp rdi, 0
    je zero_end
    cmp rsi, 0
    je zero_end

    call gcd

    mov rbx, rax
    mov rax, qword [lhs]
    imul rax, qword [rhs] 
    idiv rbx
    jmp end

    zero_end:
        mov rax, 0
    end:
        push rbp
        mov rdi, ld_fmt_out
        mov rsi, rax
        call printf
        pop rbp


        mov rax, 0
        ret


gcd:
    cmp rdi, 0
    je gcd_end

    xchg rdi, rsi
    mov rax, rdi
    cdq
    idiv rsi
    mov rdi, rdx

    jmp gcd

    gcd_end:
        mov rax, rsi
        ret