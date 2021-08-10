;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; TITLE STRCOLL - ANSI C string collation code
;                 for strcoll()
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1992, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

	INCLUDE RULES.ASI

	INCLUDE _LOCALE.INC

	INCLUDE _COLLATE.MAC

Code_Seg@

	EXTRN NOLANGUAGE _GetNextKeyWeight       : NEAR
	EXTRN NOLANGUAGE _GetSubstituteString    : NEAR
	EXTRN NOLANGUAGE _GetCompressLevelWeight : NEAR
	EXTRN NOLANGUAGE _GetNextAuxChar         : NEAR
	EXTRN NOLANGUAGE _GetExpansionString     : NEAR
	EXTRN NOLANGUAGE _GetNextExpansionWeight : NEAR

	WARN PRO

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; strcoll - ANSI C string collation code
;
; int _Cdecl strcoll( const char _FAR *__s1, const char _FAR *__s2 )
;
; Returns:
;		  0  if __s1 == __s2
;		< 0  if __s1 <  __s2
;		> 0  if __s1 >  __s2
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


IFDEF   _BUILDRTLDLL                    ; DLL library

PUBLICDLL __strcoll

ELSE

PUBLIC __strcoll

ENDIF

IFDEF _WINDOWS OR _BUILDRTLDLL

    IFDEF __PAS__
    __strcoll PROC WINDOWS PASCAL DIST

    ELSE
    __strcoll PROC WINDOWS C DIST

    ENDIF

ELSE

    IFDEF __PAS__
    __strcoll PROC PASCAL DIST

    ELSE
    __strcoll PROC C DIST

    ENDIF

ENDIF

ARG __s1 : DATAPTR, __s2 : DATAPTR

;
; declare locals having scope for this entire module
;
;
	LOCAL_VARS

	push	ds es di si

IFDEF   _BUILDRTLDLL                    ; DLL library

	call	__getpLocale

	mov	[ WORD PTR _pLocale_local ], ax
	mov	[ WORD PTR _pLocale_local + SEGLOC ], dx
	mov	bx, ax
	mov	ds, dx

ELSE

	LDS_	bx, [ DPTR_ _pLocale ]

	mov	[ WORD PTR _pLocale_local ], bx
	mov	[ WORD PTR _pLocale_local + SEGLOC ], ds
ENDIF	

	mov	ax, [ WORD PTR ( LOCALEOBJECT PTR BX ).CollationCat.CollateInfo.nLevels ]

	mov	[ MAXLEVEL ], ax

	LDS_	si, [ DPTR_ ( LOCALEOBJECT PTR BX ).pClass ]

	; skip 0th byte (padding)
	inc	si

	mov	[ WORD PTR pCHARCLASS ], si
	mov	[ WORD PTR pCHARCLASS + SEGLOC ], ds

	mov	[ LEVEL ], 0		; initialize

	mov	[ LEVELOFFSET ], 0

	; point to strings
	LDS_	si, [ DPTR_ __s1 ]
	LES_	di, [ DPTR_ __s2 ]

	call	_LevelCollate

	cbw	

@@equal:

	pop	si di es ds

        ret


__strcoll ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                      ;
; PROC _LevelCollate NEAR			       ;
;                                                      ;
; DS:SI First byte of first string  __s1	       ;
; ES:DI First byte of second string __s2	       ;
;                                                      ;
; ASSUMPTIONS:                                         ;
;                                                      ;
; LOCALS LEVEL, MAXLEVEL have been set or initialized  ;
;                                                      ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


PUBLIC _LevelCollate
_LevelCollate PROC NOLANGUAGE NEAR

	; initialize local storage
	mov	[ WEIGHT_DIFFERENCE ], 0
	mov	[ POSITION_DIFFERENCE ], 0
	mov	[ ( STRINGSTATUS PTR S1_STATUS ).CURRENT_POSITION ], 0
	mov	[ ( STRINGSTATUS PTR S2_STATUS ).CURRENT_POSITION ], 0


 	push	ds

	; get locale pointer and get collation rules for current level

	lds	bx, [ dword ptr _pLocale_local ]

	mov	cx, [ LEVEL ]			; offset by level

	add	bx, cx				; add to locale

	; offset to rules
	mov	al, [ BYTE PTR ( LOCALEOBJECT PTR BX ).CollationCat.CollateInfo.LevelRules ]

	; size of offset from class to current weight level table
	add	[ LEVELOFFSET ], CODESET_SIZE + 1

	mov	ch, al

	pop	ds

	xor	dx, dx

	; AX is used for string weights
	; BX is used for offset to string status
	; DX is used for string status
	; CH is used current level rules


@@eachweight:

	; point to string 1 status
	lea	bx, S1_STATUS

	; get next string 1 weight
	call	_GetNextKeyWeight	; get weight in al

	mov	cl, al			; save string1 weight

	xchg	dl, dh			; swap string 1 and 2 rules

	; point to string 2 status
	lea	bx, S2_STATUS

	push	ds si es di

 	pop	si ds

	; get next string 2 weight
	call	_GetNextKeyWeight	; get weight in al

	push	ds si

	pop	di es si ds

	mov	ah, cl			; string 1 weight

	xchg	dl, dh			; swap string 1 and 2 rules

	; check for end of strings
	test	dx, ( ( STRING_ENDED SHL 8 ) + STRING_ENDED )
	jnz	@@lengthdifference

@@testweights:

	; handle position collation?
	test	ch, POSITION_RULE
	jnz	@@positionrule

@@weightrule:

	;
	; GET/SET DIFFERENCE IN WEIGHT
	;

	; subtract string 2 weight from string 1 weight
	sub	ah, al
	jz	@@eachweight		; equal weight, so get next weight

	; make it a word
	xor	al, al
	xchg	al, ah

	; HAVE A DIFFERENCE IN WEIGHT

	; backward or forward processing?
	test	ch, BACKWARD_RULE
	jnz	@@saveweight

@@returnresult:
	ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@@saveposition:

	;
	; SAVE POSITION DIFFERENCE FOR LATER
	;

	; always save position difference when effectively going backwards

	mov	[ POSITION_DIFFERENCE ], bx	; save any position difference

@@saveweight:

	;
	; SAVE WEIGHT DIFFERENCE FOR LATER
	;

	; always save weight difference when effectively going backwards

	mov	[ WORD PTR WEIGHT_DIFFERENCE ], ax	; save weight difference

	jmp	SHORT @@eachweight

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@@positionrule:

	;
	; GET DIFFERENCE IN POSITION
	;
	
	push	ax		; save weights


	; calculate any difference of position:
	; subtract string 2 position from string 1 position

	mov	bx, [ ( STRINGSTATUS PTR S1_STATUS ).CURRENT_POSITION ]
	mov	ax, [ ( STRINGSTATUS PTR S2_STATUS ).CURRENT_POSITION ]

	; any position difference?
	sub	bx, ax
	jz	@@weight_difference	; no, how about a weight difference?

@@isdifference:

	;
	; THERE IS A DIFFERENCE IN POSITION
	;

	pop	ax				; clean up

	; backwards or forwards?

	test	ch, BACKWARD_RULE
	jnz	@@saveposition

@@return_position_difference:

	mov	ax, bx

@@return_weight_difference:
	ret


@@weight_difference:

	;
	; GET DIFFERENCE IN WEIGHT
	;

	pop	ax			; retrieve weights


	sub	ah, al
	xor	al, al
	xchg	al, ah

	; any difference in weights?
	 test	al, al
	jz     @@eachweight

	; backwards or forwards?
	test	ch, BACKWARD_RULE
	jnz	@@saveposition		; BX == 0 position
					; AX has weight difference
	ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


@@lengthdifference:

	;
	; ONE OR BOTH STRINGS HAVE ENDED
	;

	test	ax, ax			; both zero means both ended
	jz	@@endofstrings

	; some kind of length difference
	mov	ax, LENGTH_DIFFERENCE	; have a length difference

	; did string 2 end?
	test	dh, STRING_ENDED
	jnz	@@poslength		; yes

@@neglength:
	neg	ax			; only string 1 ended

@@poslength:

	ret

@@endofstrings:

	;
	; BOTH STRINGS HAVE ENDED
	;

	; check for position rule

;;;	test	ch, POSITION_RULE
;;;  	jz	@@weightdifference		; dealing with weights only

	; is there any saved position difference
	mov	ax, [ WORD PTR POSITION_DIFFERENCE ]

	test	ax, ax
  	jz	@@weightdifference		; maybe a weight difference

	ret					; return position difference

@@weightdifference:

	; is there any saved weight difference?
	mov	ax, [ WORD PTR WEIGHT_DIFFERENCE ]

	test	ax, ax
  	jz	@@nextlevel			; call next collation level

	ret					; return weight difference

@@nextlevel:


	inc	[ LEVEL ]		; set for next level

	mov	cx, [ MAXLEVEL ]

	cmp	[ LEVEL ], cx
	jl	@@callnextlevel	

	xor	ax, ax			; all levels processed
	ret				; return equal

@@callnextlevel:

	; start at beginning of strings for next level
	LDS_	si, [ DPTR_ __s1 ]
	LES_	di, [ DPTR_ __s2 ]

	jmp	_LevelCollate		; jump to next level of collation


_LevelCollate ENDP


Code_EndS@

               END ; end module _strcoll.asm
