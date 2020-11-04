    section .text
    global  _ft_write
    extern  ___error

_ft_write:
    mov     rax, 0x2000004  ; write
    syscall
    jc      error          ; carry flags error in unsigned arithmetic
    ret

error:
    push    rax
    call    ___error        ; error returns address of errno
    mov     rdi, rax        ; giving rdi address of errno
    pop     rax
    mov     [rdi], rax
    mov     rax, -1         ; return -1
    ret