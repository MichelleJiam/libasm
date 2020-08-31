    section .text
    global  _ft_strcpy

_ft_strcpy:
    mov     rdx, 0                      ; i = 0
    jmp     check

copy:
    mov     al, byte [rsi + rdx]        ; retrieve character
    mov     byte [rdi + rdx], al        ; copy character
    inc     rdx                         ; move pointer forward

check:
    cmp     byte [rsi + rdx], 0         ; compare byte in src to NULL
    jne     copy                        ; copies if not yet at NULL
    
done:
    mov     rax, rdi                    ; return dst
    ret