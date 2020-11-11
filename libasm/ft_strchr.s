    section .text
    global  _ft_strchr
    %define STR rdi

_ft_strchr:
    mov     rax, 0                  ; i = 0

loop:
    mov     cl, byte [STR + rax]
    cmp     cl, sil
    je      done
    cmp     cl, 0
    je      zerocheck               ; if str[i] == '\0'
    inc     rax                     ; i++
    jmp     loop

zerocheck:
    cmp     sil, 0
    je      done                    ; if char is also '\0', returns pointer
    mov     rax, 0                  ; otherwise returns NULL
    ret

done:
    lea     rax, [STR + rax]
    ret