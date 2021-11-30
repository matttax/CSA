extern printf
extern rand

extern SPHERE
extern PARALLELEPIPED
extern REGTET

global Random
Random:     ; генератор случайных чисел по модулю 20
section .data
    .i20     dq      20
section .text
push rbp
mov rbp, rsp
    xor     rax, rax
    call    rand
    xor     rdx, rdx
    idiv    qword[.i20]
    mov     rax, rdx
    inc     rax
leave
ret

global Random3
Random3:       ; генератор случайных чисел по модулю 3
section .data
    .i3     dq      3
section .text
push rbp
mov rbp, rsp
    xor     rax, rax
    call    rand
    xor     rdx, rdx
    idiv    qword[.i3]
    mov     rax, rdx
    inc     rax
leave
ret

global InRandSphere
InRandSphere:   ; случайный ввод параметров сферы
section .bss
    .psph  resq 1
section .text
push rbp
mov rbp, rsp
    mov     [.psph], rdi
    call    Random
    mov     rbx, [.psph]
    mov     [rbx], eax
leave
ret

global InRandParallelepiped
InRandParallelepiped:   ; случайный ввод параметров параллелипипеда
section .bss
    .pppd  resq 1
section .text
push rbp
mov rbp, rsp
    mov     [.pppd], rdi
    call    Random
    mov     rbx, [.pppd]
    mov     [rbx], eax
    call    Random
    mov     rbx, [.pppd]
    mov     [rbx + 4], eax
    call    Random
    mov     rbx, [.pppd]
    mov     [rbx + 8], eax
leave
ret

global InRandRegtet
InRandRegtet:   ; случайный ввод параметров правильного тетраэдра
section .bss
    .prt  resq 1
section .text
push rbp
mov rbp, rsp
    mov     [.prt], rdi
    call    Random
    mov     rbx, [.prt]
    mov     [rbx], eax
leave
ret

global InRandShape
InRandShape:    ; случайный ввод параметров абстрактной фигуры
section .bss
    .pshape     resq    1
    .key        resd    1
section .text
push rbp
mov rbp, rsp
    mov [.pshape], rdi
    xor     rax, rax
    call    rand3
    mov     rdi, [.pshape]
    mov     [rdi], eax
    cmp     eax, [SPHERE]
    je      .sphInRand
    cmp     eax, [PARALLELEPIPED]
    je      .ppdInRand
    cmp     eax, [REGTET]
    je      .rtInRand
    xor     eax, eax
    jmp     .return
.sphInRand:
    add     rdi, 4
    call    InRandSphere
    mov     eax, 1
    jmp     .return
.ppdInRand:
    add     rdi, 4
    call    InRandParallelepiped
    mov     eax, 1
    jmp     .return
.rtInRand:
    add     rdi, 4
    call    InRandRegtet
    mov     eax, 1
.return:
leave
ret

global InRandContainer
InRandContainer:    ; рандомное заполнение контейнера
section .bss
    .pcont  resq    1
    .plen   resq    1
    .psize  resd    1
section .text
push rbp
mov rbp, rsp
    mov     [.pcont], rdi
    mov     [.plen], rsi
    mov     [.psize], edx
    xor     ebx, ebx
.loop:
    cmp     ebx, edx
    jge     .return
    push    rdi
    push    rbx
    push    rdx
    call    InRandShape
    cmp     rax, 0
    jle     .return
    pop     rdx
    pop     rbx
    inc     rbx
    pop     rdi
    add     rdi, 16
    jmp     .loop
.return:
    mov     rax, [.plen]
    mov     [rax], ebx
leave
ret
