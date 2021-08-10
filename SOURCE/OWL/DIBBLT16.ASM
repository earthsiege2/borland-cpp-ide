;//---------------------------------------------------------------------------
;// ObjectWindows
;// Copyright (c) 1995, 1996 by Borland International, All rights Reserved
;//
;//$Revision:   10.2  $
;//$Author:   JKLINE  $
;//$Date:   11 Feb 1996 19:19:58  $
;// 
;//   DibSpriteBlt8 : 16 Bit Non-GDI SpriteBlt for 8bpp DIBs
;//   DibCopyBlt8 :   16 Bit Non-GDI CopyBlt for 8bpp DIBs
;// 
;//---------------------------------------------------------------------------
    page ,132

    TITLE DibBlt16.asm

_TEXT   SEGMENT BYTE PUBLIC 'CODE'
_TEXT   ENDS

_DATA   SEGMENT DWORD PUBLIC 'DATA'
_DATA   ENDS

DGROUP  GROUP   _DATA

        ASSUME  CS: _TEXT, DS: DGROUP

_DATA   SEGMENT
ALIGN   4
srcOffset DD  0000  ; Source Offset.
dstOffset DD  0000  ; Destination Offset.
_DATA   ENDS

_TEXT   SEGMENT

;//---------------------------------------------------------------------------
;
;void WINAPI
;DibCopyBlt(uint8 HUGE* dstBits, uint32 width, uint32 height, uint32 dstPitch,
;           uint8 HUGE* srcBits, uint32 srcPitch);

public DIBCOPYBLT8
DIBCOPYBLT8 proc far

dstBits   EQU [bp+26]  ; Destination bits surface
wdth      EQU [bp+22]  ; Bits Width
height    EQU [bp+18]  ; Bits Height
dstPitch  EQU [bp+14]  ; Destination scan pitch

srcBits   EQU [bp+10]  ; Source bits surface
srcPitch  EQU [bp+6]   ; Source scan pitch

    .386

    push bp
    mov  bp,sp

    push ds
    push es
    push esi
    push edi

    mov ecx, wdth
    or  ecx,ecx
    jz  DCBComplete         ; No Width

    mov edx, height         ; EDX is line counter
    or edx,edx
    jz DCBComplete          ; No Width

    xor esi, esi
    lds si, srcBits         ; DS:[ESI] point to source

    xor edi, edi
    les di, dstBits         ; ES:[EDI] point to dest

    sub srcPitch,ecx
    sub dstPitch,ecx

    mov ebx,ecx
    shr ebx,2

    mov eax,ecx
    and eax,11b

DCBLoopY:

    mov ecx,ebx
    rep movs dword ptr es:[edi], dword ptr ds:[esi]
    mov ecx,eax
    rep movs byte ptr es:[edi], byte ptr ds:[esi]
    add esi,srcPitch
    add edi,dstPitch
    dec edx
    jnz short DCBLoopY

DCBComplete:

    pop edi
    pop esi
    pop es
    pop ds
    pop bp

    ret

    .286

DIBCOPYBLT8 endp

;//---------------------------------------------------------------------------
;
;void WINAPI
;DibSpriteBlt8(uint8 HUGE* dstBits, uint32 width, uint32 height, uint32 dstPitch,
;             uint8 HUGE* srcBits, uint32 srcPitch, uint8 transparent);

public DIBSPRITEBLT8
DIBSPRITEBLT8 proc far

dstBits   EQU [bp+28]  ; Destination bits surface
wdth      EQU [bp+24]  ; Bits Width
height    EQU [bp+20]  ; Bits Height
dstPitch  EQU [bp+16]  ; Destination scan pitch

srcBits   EQU [bp+12]  ; Source bits surface
srcPitch  EQU [bp+8]   ; Source scan pitch
trans     EQU [bp+6]   ; Transparent color

    .386

    push bp
    mov  bp,sp

    push ds
    push es
    push esi
    push edi

    mov ecx, wdth
    jecxz DSBComplete       ; No Source Width

    mov edx, height         ; EDX is line counter
    mov ah, trans           ; AH has transparency color

    xor esi, esi
    lds si, srcBits         ; DS:[ESI] point to source
    mov srcOffset, esi      ; save offset

    xor edi, edi
    les di, dstBits         ; ES:[EDI] point to dest
    mov dstOffset, edi      ; save offset

DSBLoopY:

    and edx, edx
    jz  DSBComplete

    mov esi, srcOffset      ; DS:[ESI] point to source
    mov edi, dstOffset      ; ES:[EDI] point to dest
    mov ecx, wdth           ; ECX is pixel counter

DSBLoopX: 

    mov al, ds:[esi]
    cmp al, ah
    jz  DSBLoopXMasked

    mov es:[edi], al

DSBLoopXMasked:

    inc esi
    inc edi

    dec ecx
    jnz DSBLoopX

; move on to the start of the next line

    mov esi, srcOffset
    add esi, srcPitch
    mov srcOffset, esi

    mov esi, dstOffset
    add esi, dstPitch
    mov dstOffset, esi

    dec edx                 ; line counter
    jmp DSBLoopY

DSBComplete:

    pop edi
    pop esi
    pop es
    pop ds
    pop bp

    ret

    .286

DIBSPRITEBLT8 endp

_TEXT   ends
        END
