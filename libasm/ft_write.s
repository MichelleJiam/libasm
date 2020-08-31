    section .text
    global  _ft_write
    extern  ___error

_ft_write:
    mov     rax, 0x2000004  ; write
    syscall
    jc      error          ; carry flags error in unsigned arithmetic
    ret

error:
;    mov     r12, rax         ; saving rax
    push    rax
    call    ___error        ; error returns address of errno
    mov     rdi, rax        ; giving rdi address of errno
    pop     rax
    mov     [rdi], rax
;    mov     [rdi], r12       ; assigning specific errno value at rdi location
    mov     rax, -1         ; return -1
    ret