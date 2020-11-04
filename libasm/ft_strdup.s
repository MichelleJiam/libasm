    section .text
    global  _ft_strdup
    extern  _ft_strlen
    extern  _malloc
    extern  ___error

_ft_strdup:
    cmp     rdi, 0                  ; check if src is NULL
    je      done
    call    _ft_strlen
    push    rdi                     ; rdi is used by malloc
    inc     rax                     ; len + 1 for malloc
    mov     rdi, rax                ; len as 1st param for malloc
    call    _malloc
    cmp     rax, 0
    je      errdone                 ; ret if malloc fails, errno is set by malloc
    pop     rdi
    mov     rdx, 0                  ; i = 0

dup:
    mov     cl, byte [rdi + rdx]
    mov     byte [rax + rdx], cl
    cmp     cl, 0
    je      done
    inc     rdx
    jmp     dup                     ; loop until \0 is reached

done:
    ret

errdone:
	pop		rdi
	ret