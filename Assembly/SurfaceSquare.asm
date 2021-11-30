extern SPHERE
extern PARALLELEPIPED
extern REGTET

global SurfaceSquareSphere
SurfaceSquareSphere:
section .text
push rbp
mov rbp, rsp
    pi  dd  3.14
    mov     eax, [rdi]
    mov     eax, [rdi]
    mov     eax, [pi]
    mul     eax
    shl     eax, 2
    cvtsi2sd xmm0, eax
leave
ret

global SurfaceSquareParallelepiped
SurfaceSquareParallelepiped:
section .text
push rbp
mov rbp, rsp
    mov     eax, [rdi]
    mov     eax, [rdi+4]
    mul     eax
    mov     ebx, [rdi+4]
    mov     ebx, [rdi+8]
    mul     ebx
    mov     ecx, [rdi+8]
    mov     ecx, [rdi]
    mul     ecx
    add     eax, ebx
    add     eax, ecx
    shl     eax, 1
    cvtsi2sd xmm0, eax
leave
ret

global SurfaceSquareRegtet
SurfaceSquareRegtet:
section .text
push rbp
mov rbp, rsp
    sqrt3   dd  1.73
    mov     eax, [rdi]
    mov     eax, [rdi]
    mov     eax, [sqrt3]
    mul     eax
    cvtsi2sd xmm0, eax
leave
ret

global SurfaceSquarShape
SurfaceSquarShape:
section .text
push rbp
mov rbp, rsp
    mov     eax, [rdi]
    cmp     eax, [SPHERE]
    je      sphereSurfSq
    cmp     eax, [PARALLELEPIPED]
    je      parallelepipedSurfSq
    cmp     eax, [REGTET]
    je      regtetSurfSq
    xor     eax, eax
    cvtsi2sd    xmm0, eax
    jmp     return
sphereSurfSq:
    add     rdi, 4
    call    SurfaceSquareSphere
    jmp     return
parallelepipedSurfSq:
    add     rdi, 4
    call    SurfaceSquareParallelepiped
regtetSurfSq:
    add     rdi, 4
    call    SurfaceSquareRegtet
return:
leave
