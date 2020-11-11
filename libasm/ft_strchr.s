    section .text
    global  _ft_strchr
    %define STR rdi
    %define CHR rsi

_ft_strchr:
    mov     rdx, 0                  ; i = 0

loop:
    cmp     byte [STR + rdx], rsi
    je      done
    jz      zerocheck               ; if str[i] == '\0'
    inc     rdx                     ; i++
    jmp     loop

zerocheck:
    cmp     rsi, 0
    je      done                    ; if char is also '\0', returns pointer
    mov     rax, 0                  ; otherwise returns NULL
    ret

done:
    movsx   rax, byte [STR + rdx]
    ret