
; *******************************************************
; *							*
; *     Delphi Runtime Library                          *
; *	File I/O definitions for 386 RTL		*
; *							*
; *	Copyright (c) 1996,98 Inprise Corporation	*
; *							*
; *******************************************************

; File modes

fmClosed 	EQU	0D7B0H;
fmInput 	EQU	0D7B1H;
fmOutput 	EQU	0D7B2H;
fmInOut  	EQU	0D7B3H;


; ASCII equates

bell		EQU	07H
bs		EQU	08H
tab		EQU	09H
lf		EQU	0AH
cr		EQU	0DH
eof		EQU	1AH
del		EQU	7FH


; Maximum length of a file name

fNameLen	EQU	260

TextRec	STRUC
Handle		DD	(?)			;  0
Mode		DD	(?)			;  4
BufSize		DD	(?)			;  8
BufPos		DD	(?)			; 12
BufEnd		DD	(?)			; 16
BufPtr		DD	(?)			; 20
OpenFunc	DD	(?)			; 24
InOutFunc	DD	(?)			; 28
FlushFunc	DD	(?)			; 32
CloseFunc	DD	(?)			; 36
UserData	DB	32 DUP (?)		; 40
FileName	DB	fNameLen DUP (?)	; 72
Buffer		DB	128 DUP (?)		;332
TextRec	ENDS					;460

FileRec	STRUC
Handle		DD	(?)			;  0
Mode		DD	(?)			;  4
RecSize		DD	(?)			;  8
Private		DB	28 DUP (?)		; 12
UserData	DB	32 DUP (?)		; 40
FileName	DB	fNameLen DUP (?)	; 72
FileRec	ENDS					;332

; constants for NT GetStdHandle

STD_INPUT_HANDLE	EQU	-10
STD_OUTPUT_HANDLE	EQU	-11
STD_ERROR_HANDLE	EQU	-12

; constants for NT OpenFile

OF_CREATE		EQU	00001000H
OF_READ			EQU	00000000H
OF_WRITE		EQU	00000001H

; constants for NT SetFilePointer

FILE_BEGIN		EQU	0
FILE_CURRENT		EQU	1
FILE_END		EQU	2

; constants for NT CreateFile

GENERIC_READ		EQU	80000000H
GENERIC_WRITE		EQU	40000000H

FILE_SHARE_READ		EQU	00000001H
FILE_SHARE_WRITE	EQU	00000002H

CREATE_ALWAYS		EQU	2
OPEN_EXISTING		EQU	3

FILE_ATTRIBUTE_NORMAL	EQU	00000080H


