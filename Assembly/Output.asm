extern printf
extern fprintf

extern SurfaceSquareSphere
extern SurfaceSquareParallelepiped
extern SurfaceSquareRegtet

extern SPHERE
extern PARALLELEPIPED
extern REGTET

global OutSphere
OutSphere:
section .data
    .outfmt db "It is Sphere: r = %d. Surface square = %g", 10, 0
section .bss
    .prect resq 1
    .FILE resq 1
    .p resq 1
section .text
push rbp
mov rbp, rsp
    mov     [.prect], rdi
    mov     [.FILE], rsi
    call    SurfaceSquareSphere
    movsd   [.p], xmm0
    mov     rdi, [.FILE]
    mov     rsi, .outfmt
    mov     rax, [.prect]
    mov     edx, [rax]
    movsd   xmm0, [.p]
    mov     rax, 1
    call    fprintf
leave
ret

global OutParallelepiped
OutParallelepiped:
section .data
    .outfmt db "It is Parallelepiped: a = %d, b = %d, c = %d. Surface square = %g", 10, 0
section .bss
    .ptrian resq 1
    .FILE resq 1
    .p resq 1
section .text
push rbp
mov rbp, rsp
    mov     [.ptrian], rdi
    mov     [.FILE], rsi
    call    SurfaceSquareParallelepiped
    movsd   [.p], xmm0
    mov     rdi, [.FILE]
    mov     rsi, .outfmt
    mov     rax, [.ptrian]
    mov     edx, [rax]
    mov     ecx, [rax+4]
    mov     r8, [rax+8]
    movsd   xmm0, [.p]
    mov     rax, 1
    call    fprintf
leave
ret

global OutRegtet
OutRegtet:
section .data
    .outfmt db "It is Regular Tetrahedron: edge = %d. Surface square = %g", 10, 0
section .bss
    .ptrian resq 1
    .FILE resq 1
    .p resq 1
section .text
push rbp
mov rbp, rsp
    mov     [.ptrian], rdi
    mov     [.FILE], rsi
    call    SurfaceSquareRegtet
    movsd   [.p], xmm0
    mov     rdi, [.FILE]
    mov     rsi, .outfmt
    mov     rax, [.ptrian]
    mov     edx, [rax]
    mov     ecx, [rax+4]
    mov      r8, [rax+8]
    movsd   xmm0, [.p]
    mov     rax, 1
    call    fprintf
leave
ret

global OutShape
OutShape:
section .data
    .erShape db "Incorrect figure!", 10, 0
section .text
push rbp
mov rbp, rsp
    mov     eax, [rdi]
    cmp     eax, [SPHERE]
    je      sphereOut
    cmp     eax, [PARALLELEPIPED]
    je      parallelepipedOut
    cmp     eax, [REGTET]
    je      regtetOut
    mov     rdi, .erShape
    mov     rax, 0
    call    fprintf
    jmp     return
sphereOut:
    add     rdi, 4
    call    OutSphere
    jmp     return
parallelepipedOut:
    add     rdi, 4
    call    OutParallelepiped
    jmp     return
regtetOut:
    add     rdi, 4
    call    OutRegtet
return:
leave
ret

global OutContainer
OutContainer:
section .data
    numFmt  db  "%d: ",0
section .bss
    .pcont  resq    1
    .len    resd    1
    .FILE   resq    1
section .text
push rbp
mov rbp, rsp
    mov [.pcont], rdi
    mov [.len],   esi
    mov [.FILE],  rdx
    mov rbx, rsi
    xor ecx, ecx
    mov rsi, rdx
.loop:
    cmp     ecx, ebx
    jge     .return
    push    rbx
    push    rcx
    mov     rdi, [.FILE]
    mov     rsi, numFmt
    mov     edx, ecx
    xor     rax, rax
    call    fprintf
    mov     rdi, [.pcont]
    mov     rsi, [.FILE]
    call    OutShape
    pop     rcx
    pop     rbx
    inc     ecx
    mov     rax, [.pcont]
    add     rax, 16
    mov     [.pcont], rax
    jmp     .loop
.return:
leave
ret