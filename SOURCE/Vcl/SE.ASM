
; *******************************************************
; *							*
; *     Delphi Runtime Library                          *
; *	Macros						*
; *							*
; *	Copyright (c) 1996,98 Inprise Corporation	*
; *							*
; *******************************************************

	LOCALS	@@

; Public variable definition macro

VAR MACRO Symbol,SType,Count
  PUBLIC Symbol
  Symbol LABEL SType
  IF Count
    DB SType * Count DUP(?)
  ENDIF
ENDM

; Parameter definition macro

ARG MACRO Symbol,SType,Count,Align
  LOCAL Offset
  LOCAL Size
  IF (@AC GE 3) OR (SType GT 4)
    Size = (SType * Count)
    IFNB <Align>
      Size = Size + (Size MOD 4)
    ENDIF
    @AP = @AP + Size
    Offset = @AP
    Symbol EQU (SType PTR [EBP+@AF-Offset])
  ELSEIF @AC EQ 0
    Symbol EQU (EAX)
  ELSEIF @AC EQ 1
    Symbol EQU (EDX)
  ELSEIF @AC EQ 2
    Symbol EQU (ECX)
  ENDIF
  IF SType LE 4
    @AC = @AC + 1
  ENDIF
ENDM

@AP = 0
@AC = 0
@AF = 8

; Local variables definition macro

LOC MACRO Symbol,SType,Count
  LOCAL Offset
  @LP = @LP + SType * Count
  Offset = @LP
  Symbol EQU (SType PTR [EBP+@LF-Offset])
ENDM

@LP = 0
@LF = 0

; Entry code generation macro

ENTRY MACRO
  IF (@AC GE 3) OR @LP
    PUSH EBP
    MOV EBP,ESP
    @AF = @AP + 8
    @LF = 0
    IF @LP
      SUB ESP,@LP
    ENDIF
  ENDIF
ENDM

; Exit code generation macro

EXIT MACRO ArgSize
  IF @LF - @LP
    MOV ESP,EBP
  ENDIF
  IF (@AP GE 3) OR (@LF - @LP)
    POP EBP
  ENDIF
  IFNB <ArgSize>
    @AP = ArgSize
  ENDIF
    RET @AP
  @AP = 0
  @LP = 0
  @AC = 0
ENDM

; *******************************************************
; *							*
; *	EQUATES						*
; *							*
; *******************************************************

; 10-Byte record

b0		EQU	(BYTE PTR 0)
b1		EQU	(BYTE PTR 1)
b2		EQU	(BYTE PTR 2)
b3		EQU	(BYTE PTR 3)
b4		EQU	(BYTE PTR 4)
b5		EQU	(BYTE PTR 5)
b6		EQU	(BYTE PTR 6)
b7		EQU	(BYTE PTR 7)
b8		EQU	(BYTE PTR 8)
b9		EQU	(BYTE PTR 9)

; 5-Word record

w0		EQU	(WORD PTR 0)
w2		EQU	(WORD PTR 2)
w4		EQU	(WORD PTR 4)
w6		EQU	(WORD PTR 6)
w8		EQU	(WORD PTR 8)

; 3-DWord record

d0		EQU	(DWORD PTR 0)
d4		EQU	(DWORD PTR 4)
d8		EQU	(DWORD PTR 8)

; 8087 status word masks

mIE		EQU	0001H
mDE		EQU	0002H
mZE		EQU	0004H
mOE		EQU	0008H
mUE		EQU	0010H
mPE		EQU	0020H
mC0		EQU	0100H
mC1		EQU	0200H
mC2		EQU	0400H
mC3		EQU	4000H
