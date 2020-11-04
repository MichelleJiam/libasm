    section .text
    global  _ft_read
    extern  ___error

_ft_read:
    mov     rax, 0x2000003  ; read
    syscall
    jc      error
    ret

error:
    push    rax
    call    ___error        ; error returns address of errno
    mov     rdi, rax        ; giving rdi address of errno
    pop     rax
    mov     [rdi], rax      ; assigning specific errno value at rdi location
    mov     rax, -1         ; return -1
    ret