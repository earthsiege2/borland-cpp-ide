;//---------------------------------------------------------------------------
;// ObjectWindows
;// Copyright (c) 1995, 1996 by Borland International, All rights Reserved
;//
;//$Revision:   10.2  $
;//$Author:   JKLINE  $
;//$Date:   11 Feb 1996 19:20:28  $
;//
;//   DibSpriteBlt8 : 32 Bit Non-GDI SpriteBlt for 8bpp DIBs
;//   DibCopyBlt8 :   32 Bit Non-GDI CopyBlt for 8bpp DIBs
;//
;//---------------------------------------------------------------------------
        .386p
        model   flat
        title   DibBlt32.asm
_TEXT   segment dword public use32 'CODE'
_TEXT   ends
_DATA   segment dword public use32 'DATA'
_DATA   ends
_BSS    segment dword public use32 'BSS'
_BSS    ends

DGROUP  group   _BSS,_DATA
_TEXT   segment dword public use32 'CODE'

;//---------------------------------------------------------------------------
;
;void WINAPI
;DibCopyBlt8(uint8 HUGE* dstBits, uint32 width, uint32 height, uint32 dstPitch,
;           uint8 HUGE* srcBits, uint32 srcPitch);

public DibCopyBlt8
DibCopyBlt8 proc near

dstBits   EQU [ebp+8]   ; Destination bits surface
wdth      EQU [ebp+12]  ; Bits Width
height    EQU [ebp+16]  ; Bits Height
dstPitch  EQU [ebp+20]  ; Destination scan pitch

srcBits   EQU [ebp+24]  ; Source bits surface
srcPitch  EQU [ebp+28]  ; Source scan pitch

    push ebp
    mov  ebp,esp
    push esi
    push edi

    mov ecx, wdth           ; ECX is Width
    or  ecx,ecx
    jz  DCBComplete         ; No Source Width

    mov edx, height         ; EDX is line counter
    or edx,edx
    jz DCBComplete          ; No Source Height

    xor esi, esi            ; Clear out ESI
    mov esi, srcBits        ; ESI point to source

    xor edi, edi
    mov edi, dstBits        ; EDI point to dest

    sub srcPitch, ecx       ; Adjust for width of object.
    sub dstPitch, ecx       ; Adjust for width of object.

    mov ebx,ecx
    shr ebx,2

    mov eax,ecx
    and eax,11b

DCBLoopY:

    mov ecx,ebx
    rep movs dword ptr [edi], dword ptr [esi]
    mov ecx,eax
    rep movs byte ptr [edi], byte ptr [esi]
    add esi,srcPitch
    add edi,dstPitch
    dec edx
    jnz short DCBLoopY

DCBComplete:

    pop edi
    pop esi
    pop ebp

    ret 6*4

DibCopyBlt8 endp

;//---------------------------------------------------------------------------
;
;void WINAPI
;DibSpriteBlt8(uint8 HUGE* dstBits, uint32 width, uint32 height, uint32 dstPitch,
;             uint8 HUGE* srcBits, uint32 srcPitch, uint8 transparent);

public DibSpriteBlt8
DibSpriteBlt8 proc near

dstBits   EQU [ebp+8]   ; Destination bits surface
wdth      EQU [ebp+12]  ; Bits Width
height    EQU [ebp+16]  ; Bits Height
dstPitch  EQU [ebp+20]  ; Destination scan pitch

srcBits   EQU [ebp+24]  ; Source bits surface
srcPitch  EQU [ebp+28]  ; Source scan pitch

trans     EQU [ebp+32]  ; Transparent color

    push ebp
    mov  ebp,esp

    push esi
    push edi
    push ebx

    mov eax, trans
    mov edx, height
    mov ecx, srcPitch

    mov ebx, wdth           ; ECX is Width
    or  ebx,ebx
    jz  DSBComplete         ; No Source Width

    xor esi, esi
    mov esi, srcBits        ; ESI point to source

    xor edi, edi
    mov edi, dstBits        ; EDI point to dest

    sub ecx,ebx             ; Adjust for width of object.
    sub dstPitch,ebx         ; Adjust for width of object.

DSBLoopY:

    and edx, edx            ; Flag more height.
    jz  DSBComplete         ; Complete if no more height.

    mov ebx, wdth           ; ECX is pixel counter

DSBLoopX:

    mov ah, [esi]           ; Load pixel.
    cmp al, ah              ; Is pixel masked?
    jz  DSBLoopXMasked      ; Yes, jump past move.

    mov [edi], ah

DSBLoopXMasked:

    inc esi                 ; Increment Source.
    inc edi                 ; Increment Destination.

    dec ebx                 ; Decrement scan line.
    jnz DSBLoopX            ; Jump to next pixel of scan line.

; move on to the start of the next line

    add esi, ecx            ; Adjust to next scan line.
    add edi, dstPitch       ; Adjust to next scan line.

    dec edx                 ; line counter
    jmp DSBLoopY            ; Jump back for more height.

DSBComplete:

    pop ebx
    pop edi
    pop esi
    pop ebp

    ret 7*4

DibSpriteBlt8 endp

_TEXT   ends
        END
