    section .text
    global  _ft_strcmp

_ft_strcmp:
    mov     rdx, 0                      ; i = 0

comp:
    mov     al, byte [rdi + rdx]        ; retrieve character
    mov     cl, byte [rsi + rdx]        ; retrieve character
    or      al, al                      ; check if s1 is NULL
    jz      end                         ; jump to end if s1 is null
    inc     rdx                         ; increment i
    cmp     al, cl                      ; compare characters
    je      comp                        ; if same, loop
    jne     end                         ; if not, jump to end

end:
    sub     al, cl                      ; calculate diff
    movsx   rax, al                     ; move diff into rax as return
    ret