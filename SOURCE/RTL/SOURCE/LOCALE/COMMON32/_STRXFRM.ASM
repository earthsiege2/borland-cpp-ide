;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; TITLE STRXFRM - ANSI C string collation strxfrm()
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1993, 1994 by Borland International
;       All Rights Reserved.
; 

	INCLUDE RULES.ASI

	INCLUDE _LOCALE.INC

	INCLUDE _COLLATE.MAC

Header@

Code_Seg@

	EXTRN NOLANGUAGE GetNextKeyWeight       : NEAR
	EXTRN NOLANGUAGE GetSubstituteString    : NEAR
	EXTRN NOLANGUAGE GetCompressLevelWeight : NEAR
	EXTRN NOLANGUAGE GetNextAuxChar         : NEAR
	EXTRN NOLANGUAGE GetExpansionString     : NEAR
	EXTRN NOLANGUAGE GetNextExpansionWeight : NEAR
	EXTRN __pLocale                         : NEAR PTR LOCALEOBJECT

	WARN PRO

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; TITLE STRXFRM - ANSI C string collation transform
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

Func@   _strxfrm, public, _RTLENTRY, <pointer __s1>, <pointer __s2>, <int __n>

;
; declare locals having scope for this entire module
;
	LOCAL_VARS

	ENTER	STACKFRAMESIZE, 0

	push	edi esi ebx

	mov	ebx, [ DWORD PTR __pLocale ]

	mov	ax, [ WORD PTR ( LOCALEOBJECT PTR EBX ).CollationCat.CollateInfo.nLevels ]

	mov	[ MAXLEVEL ], ax

	mov	esi, [ ( LOCALEOBJECT PTR ebx ).pClass ]

	; skip 0th byte (padding)
	inc	esi

	mov	[ dword ptr pCHARCLASS ], esi

	mov	[ LEVEL ], 0		; initialize

	mov	[ LEVELOFFSET ], 0

	; point to strings
	mov	edi, [ __s1 ]
	mov	esi, [ __s2 ]

	mov	[ MAXKEYLEN ], edi

	movzx	eax, [ word ptr __n ]

	add	[ MAXKEYLEN ], eax

	call	LevelTransform

@@equal:

	pop	ebx esi edi

	LEAVE

	ret

EndFunc@ _strxfrm

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                      ;
; LevelTransform PROC NOLANGUAGE NEAR		       ;
;                                                      ;
; ESI first byte of first string  __s1	               ;
; EDI First byte of second string __s2	               ;
;                                                      ;
; ASSUMPTIONS:                                         ;
;                                                      ;
; LOCALS LEVEL, MAXLEVEL have been set or initialized  ;
;                                                      ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


LevelTransform PROC NOLANGUAGE NEAR

	; initialize local storage
	mov	[ ( stringstatus ptr s1_status ).current_position ], 0h
	mov	[ ( stringstatus ptr s2_status ).current_position ], 0h

	; get locale pointer and get collation rules for current level

	mov	ebx, [ dword ptr __plocale ]

	movzx	ecx, [ LEVEL ]			; offset by level

	add	ebx, ecx				; add to locale

	; offset to rules
	mov	al, [ byte ptr ( localeobject ptr ebx ).collationcat.collateinfo.levelrules ]

	; size of offset from class to current weight level table
	add	[ LEVELOFFSET ], CODESET_SIZE + 1

	mov	ch, al

	xor	edx, edx

	; if position rule prefix key with the POSITION_PREFIX byte
	test	al, POSITION_RULE
	jz	@@eachweight1

	mov	byte ptr [ edi ], POSITION_PREFIX

	; skip over the POSITION_PREFIX byte
	inc	edi	

@@eachweight1:

	; save beginning offset of this key
	mov	dword ptr [ ( stringstatus ptr s2_status ).aux_string_addr ], edi

	; AX is used for string weights
	; BX is used for offset to string status
	; DX is used for string status
	; CH is used current level rules

@@eachweight:

	; point to string 1 status

	lea	ebx, S1_STATUS

	; get string weight

	call	GetNextKeyWeight	; get weight in al

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

	mov	[ byte ptr edi ], al		; store weight
	inc	edi				; ready for key weight

	cmp	[ MAXKEYLEN ], edi		; at the maximum length?
	jne	@@eachweight

	jmp	SHORT @@atmaxkeylength
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@@positionrule:

	;
	; STORE POSITION/WEIGHT COMBINATION
	;
	
	; position in string

	mov	bx, [ ( stringstatus ptr s1_status ).current_position ]

	; ensure there are no zero bytes in key
	add	bx, 0101h

@@storeposition:

	mov	[ word ptr edi ], bx		; store position

	inc	edi
	inc	edi				; ready for key weight

	cmp	[ MAXKEYLEN ], edi	; at the maximum length
	jne	@@weightrule

	jmp	SHORT @@atmaxkeylength

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@@endofstrings:

	;
	; THE STRINGS HAS ENDED
	;

	test	ch, POSITION_RULE
  	jz	@@reduce
	

	; get starting offset of this position type key
	; (not including the prefix)
	mov	ebx, [ ( stringstatus ptr s2_status ).aux_string_addr ]


	; any key weights added for this key
	; (no advancement from start of key)

	; ES:DI points just passed end of key

	cmp	edi, ebx
	jne	@@checkbackward

@@setposprefix:

	; adjust end of key offset
	dec	edi

	; remove position prefix
	mov	byte ptr [ edi ], 0
	jmp	SHORT @@checkbackward	

@@reduce:

	push	ecx

	; EDI points just passed end of key
	; ESI points to end of string

	; get end of key offset
	mov	ecx, edi

	; subtract start of key buffer from end for length of key
	sub	ecx, [ ( stringstatus ptr s2_status ).aux_string_addr ]

	jecxz	@@trimkeydone

	; first point to class table...
	mov	ebx, [ DWORD PTR pCHARCLASS ]

	inc	ebx

	; ...then to level weight table
	add	ebx, [ LEVELOFFSET ]

	; get the lowest weight at this level (stored at table entry 0)
	mov	al, [ byte ptr ebx ]
	inc	al

@@trimkey:

	; point before next slot
	cmp	[ ( byte ptr edi - 1 ) ], al
	 jne	@@trimkeydone

	dec	edi
	loop	@@trimkey

@@trimkeydone:
	pop	ecx


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
	mov	word ptr [ edi ], 0

	; subtract start of key buffer from end for length of key
	sub	edi, [ dword ptr __s1 ]
	mov	eax, edi

	ret				; return length of key

@@callnextlevel:

	; start at beginning of string 1 for next level

	mov	esi, [ dword ptr __s2 ]
	jmp	LevelTransform		; jump to next level of collation

@@atmaxkeylength:
	movzx	eax, [ word ptr __n ]
	ret

@@reversekey:

	test	ch, POSITION_RULE
  	jnz	@@reversepositionkey

	; EDI points just passed end of key

	push	edi

	mov	ecx, edi

	; subtract start of key buffer from end for length of key
	mov	esi, [ ( stringstatus ptr s2_status ).aux_string_addr ]
	sub	ecx, esi


	; if key is greater than 3 we use word moves
	cmp	ecx, 3
	jg	short wordmoves

	; if key 0 or less then there is nothing to do
	jecxz	@@reversekeydone

	; if key 3 or less then we use byte moves

	; start and end bytes
	mov	al, [ ( byte ptr esi ) ]
	mov	ah, [ ( byte ptr edi - 1 ) ]

	mov	[ ( byte ptr esi ) ], ah
	mov	[ ( byte ptr edi - 1 ) ], al

	jmp	short @@reversekeydone
	
wordmoves:

	; div 4 (losing original odd bit, if any)
	shr	ecx, 2	

	jecxz	@@reversekeydone

@@keyweight:
	mov	ax, [ ( word ptr esi ) ]
	mov	bx, [ ( word ptr edi - 2 ) ]

	xchg	al, ah
	xchg	bl, bh

	mov	[ ( word ptr esi ) ], bx
	mov	[ ( word ptr edi - 2 ) ], ax

	inc	esi	
	inc	esi	
	dec	edi
	dec	edi
	loop	@@keyweight

@@reversekeydone:
	pop	edi
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

	; EDI points just passed end of key

	push	edi

	mov	ecx, edi

	; subtract start of key buffer from end for length of key
;	mov	esi, [ ( STRINGSTATUS PTR S2_STATUS ).AUX_STRING_ADDR ]
;	sub	ecx, esi

	sub	ecx, [ ( stringstatus ptr s2_status ).aux_string_addr ]

	; div 4 (losing original odd bit, if any)
	shr	ecx, 2	

	cmp	ecx, 2
	jb	@@reversepositionkeydone

	dec	ecx


@@keypostion:

	; beginning of key
	mov	ax, [ ( word ptr esi ) ]		; get position
	mov	dl, [ ( byte ptr esi + 2 ) ]		; get weight

	; end of key
	mov	bx, [ ( word ptr edi - 3 ) ]		; get position
	mov	dh, [ ( byte ptr edi - 1 ) ]		; get weight

	; beginning of key
	mov	[ ( word ptr esi ) ], bx		; store position
	mov	[ ( byte ptr esi + 2 ) ], dh		; store weight

	; end of key
	mov	[ ( word ptr edi - 3 ) ], ax		; store position
	mov	[ ( byte ptr edi - 1 ) ], dl		; store weight

	REPT	3

	inc	esi	
	dec	edi

	ENDM

	loop	@@keypostion

@@reversepositionkeydone:
	pop	edi
	jmp	@@nextlevel

LevelTransform  ENDP	

Code_EndS@

	END	; end module _strxfrm.asm
