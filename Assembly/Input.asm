extern printf
extern fscanf

extern SPHERE
extern PARALLELEPIPED
extern REGTET

global InSphere
InSphere:       ; ввод параметров сферы из файла
section .data
    .infmt db "%d%d",0
section .bss
    .FILE   resq    1
    .sph  resq    1
section .text
push rbp
mov rbp, rsp
    mov     [.sph], rdi
    mov     [.FILE], rsi
    mov     rdi, [.FILE]
    mov     rsi, .sph
    mov     rdx, [.sph]
    mov     rax, 0
    call    fscanf
leave
ret

global InParallelepiped
InParallelepiped:   ; ввод параметров параллелипипеда из файла
section .data
    .infmt db "%d%d%d",0
section .bss
    .FILE   resq    1
    .ppd  resq    1
section .text
push rbp
mov rbp, rsp
    mov     [.ppd], rdi
    mov     [.FILE], rsi
    mov     rdi, [.FILE]
    mov     rsi, .infmt
    mov     rdx, [.ppd]
    mov     rcx, [.ppd]
    add     rcx, 4
    mov     r8, [.ppd]
    add     r8, 8
    mov     rax, 0
    call    fscanf
leave
ret

global InRegtet
InRegtet:       ; ввод параметров правильного тетраэдра из файла
section .data
    .infmt db "%d%d",0
section .bss
    .FILE   resq    1
    .rt  resq    1
section .text
push rbp
mov rbp, rsp
    mov     [.rt], rdi
    mov     [.FILE], rsi
    mov     rdi, [.FILE]
    mov     rsi, .rt
    mov     rdx, [.rt]
    mov     rax, 0
    call    fscanf
leave
ret

global InShape
InShape:        ; ввод параметров абстрактной фигуры из файла
section .data
    .tagFormat   db      "%d",0
section .bss
    .FILE       resq    1
    .pshape     resq    1
    .shapeTag   resd    1
section .text
push rbp
mov rbp, rsp
    mov     [.pshape], rdi
    mov     [.FILE], rsi
    mov     rdi, [.FILE]
    mov     rsi, .tagFormat
    mov     rdx, [.pshape]
    xor     rax, rax
    call    fscanf
    mov rcx, [.pshape]
    mov eax, [rcx]
    cmp eax, [SPHERE]
    je .sphIn
    cmp eax, [PARALLELEPIPED]
    je .ppdIn
    cmp eax, [REGTET]
    je .rtIn
    xor eax, eax
    jmp     .return
.sphIn:
    mov     rdi, [.pshape]
    add     rdi, 4
    mov     rsi, [.FILE]
    call    InSphere
    mov     rax, 1
    jmp     .return
.ppdIn:
    mov     rdi, [.pshape]
    add     rdi, 4
    mov     rsi, [.FILE]
    call    InParallelepiped
    mov     rax, 1
    jmp     .return
.trianIn:
    mov     rdi, [.pshape]
    add     rdi, 4
    mov     rsi, [.FILE]
    call    InRegtet
    mov     rax, 1
.return:
leave
ret

global InContainer
InContainer:        ; заполнение контейнера из файла
section .bss
    .pcont  resq    1
    .plen   resq    1
    .FILE   resq    1
section .text
push rbp
mov rbp, rsp
    mov     [.pcont], rdi
    mov     [.plen], rsi
    mov     [.FILE], rdx
    xor     rbx, rbx
    mov     rsi, rdx
.loop:
    push    rdi
    push    rbx
    mov     rsi, [.FILE]
    mov     rax, 0
    call    InShape
    cmp     rax, 0
    jle     .return
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
