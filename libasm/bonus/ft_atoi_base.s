    section .text
    global  _ft_atoi_base
    %define BASE rsi
    %define SIGN r12
    %define MAX r13
    %define NUM r14
    %define RES r15

_ft_atoi_base:                          ; rdi is str, rsi is str_base
    mov     rdx, -1                     ; i = -1
    mov     SIGN, 1                     ; sign = 1
    mov     MAX, BASE
    add     MAX, 86                     ; max = base - 11 + 'a'
    mov     RES, 0                      ; NUM = 0
    mov     NUM, 0                      ; n = 0
    jmp     whitespaceskip

whitespacechar:
    cmp     r14b, 9                     ; '\t'
    jl      done
                   
whitespaceskip:
    inc     rdx                         ; i++
    mov     r14b, byte [rdi + rdx]
    cmp     r14b, 0
    je      done
    cmp     r14b, 32                    ; str[i] == ' ' ?
    je      whitespaceskip
    cmp     r14b, 13                    ; '\f'
    jle     whitespacechar
    dec     rdx
    jmp     sign

setsign:
    cmp     rdx, 0                      ; if '-' is not 1st char
    jne     done
    mov     SIGN, -1

sign:
    inc     rdx
    cmp     byte [rdi + rdx], 43        ; str[i] == '+' ?
    je      sign
    cmp     byte [rdi + rdx], 45        ; str[i] == '-' ?
    je      setsign
    jmp     checkbase

setmax:
    mov     MAX, BASE
    add     MAX, 47                     ; max = base - 1 + '0'
    jmp     range

checkbase:
    cmp     BASE, 10
    jle     setmax

range:
    mov     r14b, byte [rdi + rdx]
    cmp     r14b, 0                     ; check if end
    je      done
    cmp     r14b, 48                    ; check if < '0'
    jl      done
    cmp     r14b, r13b                  ; check if > max
    jg      done

num:
    cmp     r14b, 57                    ; check if > '9'
    jg      char
    sub     NUM, 48                     ; n = str[i] - '0'
    jmp     setres

lowerc:
    cmp     byte [rdi + rdx], 122       ; 'z'
    jg      done
    movsx   NUM, byte [rdi + rdx]
    sub     NUM, 87                     ; n = str[i] + 10 - 'a'
    jmp     setres

char:
    cmp     byte [rdi + rdx], 97        ; 'a'
    jge     lowerc
    cmp     byte [rdi + rdx], 65        ; 'A'
    jl      done
    cmp     byte [rdi + rdx], 90        ; 'Z'
    jg      done
    movsx   NUM, byte [rdi + rdx]
    sub     NUM, 55                     ; n = str[i] + 10 - 'A'

setres:
    imul    RES, BASE                   ; NUM *= base
    add     RES, NUM                    ; NUM += num
    inc     rdx
    jmp     range

done:
    mov     rax, RES
    imul    rax, SIGN                   ; NUM *= sign
    ret