global main

extern printf
extern scanf
extern malloc
extern free

section .data
	size_msg:      db "Enter matrix size (rowxcol)", 10, 0	; Size msg
	matrix_in_msg: db "Enter a matrix", 10, 0		; Matrix enter msg
	matrix_msg:    db "Matrix:", 10, 0			; Matrix preview msg
	avg_row_msg:   db "Average of row %llu: %lf", 10, 0	; Row average msg
	avg_col_msg:   db "Average of column %llu: %lf", 10, 0	; Column average msg
	size_fmt:      db "%llu%*[x]%llu", 0			; Scanf matrix size fmt
	llu_fmt:       db "%llu", 0				; Scanf fmt
	matrix_fmt:    db "[%llu]", 0				; Printf fmt
	newline_fmt:   db 10, 0					; Printf fmt

section .bss
	flttmp:        resq 1					; FP buffer
	row_size:      resq 1					;|
	col_size:      resq 1					;| Matrix dimensions size
	matrix:        resq 1					; Matrix buffer pointer

section .text

main:
	push rbp						; Saving frame pointer

	mov rdi, size_msg					;|
	call printf						;| Printing size msg
	
	mov rdi, size_fmt					;|
	mov rsi, row_size					;|
	mov rdx, col_size					;|
	call scanf						;| Scanning matrix size

	mov rax, 8						;|
	mul qword [row_size]					;|
	mul qword [col_size]					;| Allocation size for malloc
	
	mov rdi, rax						;|
	call malloc						;| Allocating memory for a matrix

	mov qword [matrix], rax					; Capturing matrix pointer
	
	mov rdi, matrix_in_msg					;|
	call printf						;| Printing enter matrix msg

	mov r12, 0						; Current index
	mov r13, qword [matrix]					; Current pointer

	mov rax, qword [row_size]				;|
	mul qword [col_size]					;|
	mov r14, rax						;| Total matrix size	

	in: 							;|
		mov rdi, llu_fmt				;|
		mov rsi, r13					;|
		call scanf					;|
								;|
		add r12, 1					;|
		add r13, 8					;|
		cmp r12, r14					;|
		jl in						;| Scanning matrix
	
	
	mov r12, 0						; Row index
	mov r13, 0						; Column index
	mov r14, qword [matrix]					; Current pointer
	
	mov rdi, matrix_msg					;|
	call printf						;| Printing matrix msg

	out_row:						;|
		mov r13, 0					;|
	out_column:						;|
		mov rdi, matrix_fmt				;|
		mov rsi, [r14]					;|
		call printf					;|
		
		add r13, 1					;|
		add r14, 8					;|
		cmp r13, qword [col_size]			;|
		jl out_column					;|
		
		mov rdi, newline_fmt				;|
		call printf					;|

		add r12, 1					;|
		cmp r12, qword [row_size]			;|
		jl out_row					;| Printing matrix

	mov r12, 0						; Row index
	mov r13, 0						; Column index
	mov r14, qword [matrix]					; Current pointer

	avg_row_row:						;|
		mov r13, 0					;|
		mov rax, 0					;|
	avg_row_col:						;|
		add rax, qword [r14]				;|

		add r13, 1					;|
		add r14, 8					;|
		cmp r13, qword [col_size]			;|
		jl avg_row_col					;|

		mov qword [flttmp], rax				;|

		fild qword [flttmp]				;|
		fidiv dword [col_size]				;|
		fstp qword [flttmp]				;|

		mov rdi, avg_row_msg				;|
		mov rsi, r12					;|
		movq xmm0, qword [flttmp]			;|
		mov rax, 1					;|
		call printf					;|
		
		add r12, 1					;|
		cmp r12, qword [row_size]			;|
		jl avg_row_row					;| Calculating row avg

	mov r12, 0						; Column index
	mov r13, 0						; Row index
	mov r14, qword [matrix]					; Base pointer

	mov rax, 8						;|
	mul qword [col_size]					;|
	mov rbx, rax						;| Column offset
					
	avg_col_col:						;|
		mov r15, r14					;|
		mov r13, 0					;|
		mov rax, 0					;|
		add r14, 8					;|

	avg_col_row:						;|
		add rax, qword [r15]				;|

		add r13, 1					;|
		add r15, rbx					;|
		cmp r13, qword [row_size]			;|
		jl avg_col_row					;|

		mov qword [flttmp], rax				;|
		
		fild qword [flttmp]				;|
		fidiv dword [row_size]				;|
		fstp qword [flttmp]				;|

		mov rdi, avg_col_msg				;|
		mov rsi, r12					;|
		movq xmm0, qword [flttmp]			;|
		mov rax, 1					;|
		call printf					;|

		add r12, 1					;|
		cmp r12, qword [col_size]			;|
		jl avg_col_col					;| Calculating column avg

	mov rdi, qword [matrix]					;|
	call free						;| Freeing allocated memory
	
	pop rbp							; Restoring frame pointer

	mov rax, 0
	ret
