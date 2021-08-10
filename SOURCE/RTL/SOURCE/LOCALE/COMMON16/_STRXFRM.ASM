;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; TITLE STRXFRM - ANSI C string collation transform
;                 for strxfrm()
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
; size_t _Cdecl strxfrm(char _FAR *__s1, const char _FAR *__s2, size_t __n );
;
; Returns: number of byte keys placed in __s1
;
;	   __s1 has the collation key in the following format:
;
;	   1W, 1W, .., 1W, 2W, 2W, .., 2W, 3W, 3W, .., 3W, 4W, 4W, .., 4W,
;
;	   if a rule for a level is BACKWARD_RULE then
;	   the nW sequence will be in reverse order
;
;	   if a rule for a level is POSITION_RULE then
;	   the nW sequence will be prefixed with POSTION_PREFIX
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

IFDEF   _BUILDRTLDLL                    ; DLL library

PUBLICDLL __strxfrm

ELSE

PUBLIC __strxfrm

ENDIF

IFDEF _WINDOWS OR _BUILDRTLDLL

    IFDEF __PAS__
    __strxfrm PROC WINDOWS PASCAL DIST

    ELSE
    __strxfrm PROC WINDOWS C DIST

    ENDIF

ELSE

    IFDEF __PAS__
    __strxfrm PROC PASCAL DIST

    ELSE
    __strxfrm PROC C DIST

    ENDIF

ENDIF

ARG __s1 : DATAPTR, __s2 : DATAPTR, __n : WORD

;
; declare locals having scope for this entire module
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

	inc	si

	mov	[ WORD PTR pCHARCLASS ], si
	mov	[ WORD PTR pCHARCLASS + SEGLOC ], ds

	mov	[ LEVEL ], 0		; initialize

	mov	[ LEVELOFFSET ], 0

	; point to strings
	LES_	di, [ DPTR_ __s1 ]
	LDS_	si, [ DPTR_ __s2 ]

	mov	[ MAXKEYLEN ], di

	mov	ax, [ WORD PTR __n ]
	add	[ MAXKEYLEN ], ax

	call	_LevelTransform

@@equal:

	pop	si di es ds

	ret


__strxfrm ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                      ;
; PROC _LevelTransform NEAR			       ;
;                                                      ;
; DS:SI First byte of first string  __s1	       ;
; ES:DI First byte of second string __s2	       ;
;                                                      ;
; ASSUMPTIONS:                                         ;
;                                                      ;
; LOCALS LEVEL, MAXLEVEL have been set or initialized  ;
;                                                      ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


PUBLIC _LevelTransform
_LevelTransform PROC NOLANGUAGE NEAR

	; initialize local storage
	mov	[ ( STRINGSTATUS PTR S1_STATUS ).CURRENT_POSITION ], 0h
	mov	[ ( STRINGSTATUS PTR S2_STATUS ).CURRENT_POSITION ], 0h

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

	; if position rule prefix key with the POSITION_PREFIX byte
	test	al, POSITION_RULE
	jz	@@eachweight1

	mov	BYTE PTR ES:[ DI ], POSITION_PREFIX

	; skip over the POSITION_PREFIX byte
	inc	di	

@@eachweight1:

	; save beginning offset of this key
	mov	[ ( STRINGSTATUS PTR S2_STATUS ).AUX_STRING_OFF ], di

	; AX is used for string weights
	; BX is used for offset to string status
	; DX is used for string status
	; CH is used current level rules

@@eachweight:

	; point to string 1 status
	lea	bx, S1_STATUS

	; get next string weight
	call	_GetNextKeyWeight	; get weight in al

	; put string 2 weight

	; check for end of string
	test	dl, STRING_ENDED
	jnz	@@endofstrings

@@testweights:

	; handle position key building?
	test	ch, POSITION_RULE
	jnz	@@positionrule

@@weightrule:

	;
	; STORE WEIGHT
	;

	; bump weight by one
	inc	al

@@storeweight:

	mov	BYTE PTR ES:[ DI ], al	; store weight
	inc	di				; ready for key weight

	cmp	[ MAXKEYLEN ], di		; at the maximum length?
	jne	@@eachweight

	jmp	SHORT @@atmaxkeylength
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@@positionrule:

	;
	; STORE POSITION/WEIGHT COMBINATION
	;
	
	; position in string

	mov	bx, [ ( STRINGSTATUS PTR S1_STATUS ).CURRENT_POSITION ]

	; ensure there are no zero bytes in key
	add	bx, 0101h

@@storeposition:

	mov	WORD PTR ES:[ DI ], bx	; store position

	inc	di
	inc	di				; ready for key weight

	cmp	[ MAXKEYLEN ], di	; at the maximum length
	jne	@@weightrule

	jmp	SHORT @@atmaxkeylength

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@@endofstrings:

	;
	; THE STRING HAS ENDED
	;

	test	ch, POSITION_RULE
  	jz	@@reduce
	

	; get starting offset of this position type key
	; (not including the prefix)
	mov	bx, [ ( STRINGSTATUS PTR S2_STATUS ).AUX_STRING_OFF ]


	; any key weights added for this key
	; (no advancement from start of key)

	; ES:DI points just passed end of key

	cmp	di, bx
	jne	@@checkbackward

@@setposprefix:

	; adjust end of key offset
	dec	di

	; remove position prefix
	mov	BYTE PTR ES:[ DI ], 0
	jmp	SHORT @@checkbackward	

@@reduce:

	push	ds
	push	cx

	; ES:DI points just passed end of key
	; DS:SI points to end of string

	; get end of key offset
	mov	cx, di

	; subtract start of key buffer from end for length of key
	sub	cx, [ ( STRINGSTATUS PTR S2_STATUS ).AUX_STRING_OFF ]

	jcxz	@@trimkeydone

	; first point to class table...
	lds	bx, [ DWORD PTR pCHARCLASS ]

	inc	bx

	; ...then to level weight table
	add	bx, [ LEVELOFFSET ]

	; get the lowest weight at this level (stored at table entry 0)
	mov	al, byte ptr ds:[ bx ]
	inc	al

@@trimkey:

	; point before lnext slot
	cmp	BYTE PTR ES:[ DI - 1 ], al
	 jne	@@trimkeydone

	dec	di
	loop	@@trimkey

@@trimkeydone:
	pop	cx
	pop	ds


@@checkbackward:

	; check for backward processing

	test	ch, BACKWARD_RULE
  	jnz	@@reversekey

@@nextlevel:

	inc	[ LEVEL ]		; set for next level

	mov	cx, [ MAXLEVEL ]

	cmp	[ LEVEL ], cx
	jl	@@callnextlevel	

	; zero terminate
	mov	BYTE PTR ES:[ di ], 0h

	; subtract start of key buffer from end for length of key
	sub	di, [ WORD PTR __s1 ]
	mov	ax, di

	ret				; return length of key

@@callnextlevel:

	; start at beginning of string 1 for next level

	LDS_	si, [ DPTR_ __s2 ]

	jmp	_LevelTransform		; jump to next level of collation

@@atmaxkeylength:
	mov	ax, [ WORD PTR __n ]
	ret

@@reversekey:

	test	ch, POSITION_RULE
  	jnz	@@reversepositionkey

	; ES:DI points just passed end of key

	push	di

	push	es
	pop	ds

	push	es

	mov	cx, di

	; subtract start of key buffer from end for length of key
	mov	si, [ ( STRINGSTATUS PTR S2_STATUS ).AUX_STRING_OFF ]
	sub	cx, si


	; if key is greater than 3 we use word moves
	cmp	cx, 3
	jg	short wordmoves

	; if key 0 or less then there is nothing to do
	jcxz	@@reversekeydone

	; if key 3 or less then we use byte moves

	; start and end bytes
	mov	al, BYTE PTR DS:[ SI ]
	mov	ah, BYTE PTR ES:[ DI - 1 ]

	mov	BYTE PTR DS:[ SI ], ah
	mov	BYTE PTR ES:[ DI - 1 ], al

	jmp	short @@reversekeydone
	
wordmoves:

	; div 4 (losing original odd bit, if any)
	shr	cx, 2	

	jcxz	@@reversekeydone

@@keyweight:
	mov	ax, WORD PTR DS:[ SI ]
	mov	bx, WORD PTR ES:[ DI - 2 ]

	xchg	al, ah
	xchg	bl, bh

	mov	WORD PTR DS:[ SI ], bx
	mov	WORD PTR ES:[ DI - 2 ], ax

	inc	si	
	inc	si	
	dec	di
	dec	di
	loop	@@keyweight

@@reversekeydone:
	pop	es
	pop	di
	jmp	SHORT @@nextlevel

@@reversepositionkey:

	;
	; REVSERSE POSITION
	;

	; position key format:
	;
	; POSITION_PREFIX (byte),
	; [ <POSITION>, <WEIGHT> ], [ <POSITION>, <WEIGHT> ], ...
	;

	; ES:DI points just passed end of key

	push	di

	push	es
	pop	ds

	push	es

	mov	cx, di

	; subtract start of key buffer from end for length of key
	mov	si, [ ( STRINGSTATUS PTR S2_STATUS ).AUX_STRING_OFF ]
	sub	cx, si

	; div 4 (losing original odd bit, if any)
	shr	cx, 2	

	cmp	cx, 2
	jb	@@reversepositionkeydone

	dec	cx


@@keypostion:

	; beginning of key
	mov	ax, WORD PTR DS:[ SI ]			; get position
	mov	dl, BYTE PTR DS:[ SI + 2 ]		; get weight

	; end of key
	mov	bx, WORD PTR ES:[ DI - 3 ]		; get position
	mov	dh, BYTE PTR ES:[ DI - 1 ]		; get weight

	; beginning of key
	mov	WORD PTR DS:[ SI ], bx		; store position
	mov	BYTE PTR DS:[ SI + 2 ], dh		; store weight

	; end of key
	mov	WORD PTR ES:[ DI - 3 ], ax		; store position
	mov	BYTE PTR ES:[ DI - 1 ], dl		; store weight

	REPT	3

	inc	si	
	dec	di

	ENDM

	loop	@@keypostion

@@reversepositionkeydone:
	pop	es
	pop	di
	jmp	@@nextlevel

_LevelTransform ENDP	

Code_EndS@

	END	; end module _strxfrm.asm
