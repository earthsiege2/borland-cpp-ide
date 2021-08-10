;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; TITLE COLLATE - ANSI C string collation common support
;                 functions called by strcoll() & strxfrm()
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

	WARN PRO

	;
	; generate relative stack offsets for this module
	;

	SET_STACKVARS

	;
	;
	;

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;                                                      ;
	; PROC _GetNextKeyWeight NEAR                           ;
	;                                                      ;
	; SS:BX = address of current string status information ;
	;                                                      ;
	; Optimized for non-special handling                   ;
	;                                                      ;
	; Returns next character weight in AL                  ;
	;                                                      ;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


PUBLIC _GetNextKeyWeight
_GetNextKeyWeight PROC NOLANGUAGE NEAR

	push	es
	push	di

@@eachchar:

	; check for special handling
	test	dl, dl
	jnz	@@specials

@@nospecials:

	; get next character from string
	mov	al, [ BYTE PTR SI ]
	inc	si

	inc	SS:[ ( STRINGSTATUS PTR BX ).CURRENT_POSITION ]

@@getclass:

	; end of string?
	test	al, al
	jz	@@endofstring

@@havecharacter:

	; point to class table
	mov	di, [ WORD PTR pCHARCLASS ]
	mov	es, [ WORD PTR pCHARCLASS + SEGLOC ]

	xor	ah, ah			; ensure zero
	add	di, ax			; offset by character
	mov	ah, BYTE PTR ES:[ DI ]	; get character's class
		
@@check_substitute:

	test	ah, NOT CLASS_NORMAL
	jnz	@@notnormal

@@lookup_charweight:

	;
	; POINT TO WEIGHT TABLE FOR THIS LEVEL
	; ES:DI is still indexing AL's (character) class
	; add the appropriate number of 257 offsets
	; because these tables are contiguous
	;


	; offset from character's class to character's level weight
	add	di, [ LEVELOFFSET ]

	; get the weight
	mov	al, BYTE PTR ES:[ DI ]

@@check_weight_type:

	; should ignore this character's weight?
	cmp	al, IGNORE_WEIGHT
	je	@@eachchar	 		; yes, fetch another

@@return_weight:

	pop	di
	pop	es

	ret

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@@notnormal:

	; character of this class?
	test	ah, CLASS_SUBSTITUTE
	jz	@@check_expand		; no

	; rule applies at this level?
	test	ch, SUBSTITUTE_RULE
	jz	@@check_expand	  	; no

	; already processing a substitute string?
	; nested substitutions are not legal

	test	dl, INSUBSTITUTION
	jnz	@@check_expand


	; get a possible substitute string
	call	_GetSubstituteString
	jnc	@@getsubchar

@@check_expand:

	; character of this class?
	test	ah, CLASS_EXPAND
	jz	@@check_compress

	; already processing an expansion string?
	; nested expansions are not legal

	test	dl, INEXPANSION
	jnz	@@check_compress

	; get the expansion string
	call	_GetExpansionString
	jnc	@@getexpchar

@@check_compress:

	test	ah, CLASS_COMPRESS
	jz	@@lookup_charweight

	call	_GetCompressLevelWeight
	jnc	@@check_weight_type
	
	xor	ah, CLASS_COMPRESS
	jmp	SHORT @@lookup_charweight

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@@endofstring:
	or	dl, STRING_ENDED
	jmp	SHORT @@return_weight

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@@specials:
	test	dl, INSUBSTITUTION
	jz	@@nosubstitution

@@getsubchar:
	call	_GetNextAuxChar		; return character in AL
	jnc	@@havecharacter

	xor	dl, INSUBSTITUTION	; turn off substitution processing
	
@@nosubstitution:
	test	dl, INEXPANSION
	jz	@@nospecials

@@getexpchar:

	call	_GetNextExpansionWeight	; return weight in AL
	jnc	@@check_weight_type

	xor	dl, INEXPANSION		; turn off expansion processing
	jmp	SHORT @@nospecials


_GetNextKeyWeight ENDP


	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;                                                      ;
	; PROC GetSubstituteString NEAR                        ;
	;                                                      ;
	; DS:SI	= string                                       ;
	; SS:BX = address of current string status information ;
	;    DL	= STRINGLEVELSTATE                             ;
	;                                                      ;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUBLIC _GetSubstituteString
_GetSubstituteString PROC NOLANGUAGE NEAR

	push	es di cx bx

@@subtable:

	; use ES:DI to point to substitution table

	les	bx, [ dword ptr _pLocale_local ]

	LES_	di, DPTR_ ES:[ ( LOCALEOBJECT PTR BX ).pSubstitutionTbl ]

	xor	bx, bx			; table index
	xor	cx, cx			
	
	; al still has valid character
	dec	si			; has already been advanced

@@eachelement:

	; count
	mov	cl, ES:[ BYTE PTR ( SUBSTITUTION PTR DI + BX ).StringLength ]

	; end of table?
	cmp	ES:[ BYTE PTR ( SUBSTITUTION PTR DI + BX ).StringLength ], 0
	je	@@nosubstring

@@compare_string_to_table:

	; compare StringElement character with string character
	; if no match go to next StringElement

	cmp	ES:[ BYTE PTR ( SUBSTITUTION PTR DI + BX ).StringElement ], al
	jne	@@nextelement
		
	; a string character matched with corresponding table character
	inc	bx				; increment index
	dec	cx				; decrement count

	mov	al, BYTE PTR DS:[ SI + BX ]	; next string character

	; all characters matched for length of StringElement
	jcxz	@@havestringmatch
	jmp	SHORT @@compare_string_to_table
	
@@nextelement:
	add	di, SIZE SUBSTITUTION	; point to next element
	xor	cx, cx			; new count
	xor	bx, bx			; new table index
	jmp	SHORT @@eachelement


@@havestringmatch:

	xor	ch, ch
	mov	cl, ES:[ BYTE PTR ( SUBSTITUTION PTR DI ).StringLength ]

	; advance original string pointer to end of substituted string
	add	si, cx

	; point to ( next element - sub string )
	add	di, ( SIZE SUBSTITUTION - MAX_SUBSTITUTION_ELEMENT_SIZE )

	pop	bx
	pop	cx

	; save substring address
	mov	SS:[ ( STRINGSTATUS PTR BX ).AUX_STRING_OFF ], di
	mov	SS:[ ( STRINGSTATUS PTR BX ).AUX_STRING_SEG ], es
	dec	SS:[ ( STRINGSTATUS PTR BX ).CURRENT_POSITION ]

	or	dl, INSUBSTITUTION

@@stringdone:

	clc		; success

	pop	di
	pop	es

	ret
	

@@nosubstring:

	pop	bx
	pop	cx

	; restore original string position and character

	inc	si
	mov	al, [ BYTE PTR SI ]

	stc		; no substitute found

@@ExitGetSubstituteString:

	pop	di
	pop	es
	
	ret

_GetSubstituteString ENDP

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;                                                      ;
	; PROC GetCompressLevelWeight NEAR                     ;
	;                                                      ;
	; DS:SI	= string                                       ;
	; SS:BX = address of current string status information ;
	;    DL	= STRINGLEVELSTATE                             ;
	;                                                      ;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUBLIC _GetCompressLevelWeight
_GetCompressLevelWeight PROC NOLANGUAGE NEAR


	push	es di bx cx

	les	bx, [ dword ptr _pLocale_local ]

	LES_	di, DPTR_ ES:[ ( LOCALEOBJECT PTR BX ).pCompressTbl ]

	xor	bx, bx			; table index
	xor	cx, cx			

	dec	si			; account for increment

	; al still has valid character

@@eachelement:

	; count
	mov	cl, ES:[ ( COMPRESSION PTR DI ).ElementLength ]

	; end of table?
	cmp	ES:[ ( COMPRESSION PTR DI + BX ).ElementLength ], 0
	je	@@nocmpstring

@@compare_string_to_table:

	; compare StringElement character with string character
	; if no match go to next StringElement

	cmp	ES:[ ( COMPRESSION PTR DI + BX ).CmpCollationElement ], al
	jne	@@nextelement
		
	; a string character matched with corresponding table character
	inc	bx				; increment index
	dec	cx				; decrement count

	mov	al, BYTE PTR DS:[ SI + BX ]	; next string character

	; all characters matched for length of ElementLength
	jcxz	@@havestringmatch

	jmp	SHORT @@compare_string_to_table

@@nextelement:

	add	di, SIZE COMPRESSION	; point to next element
	xor	cx, cx			; new count
	xor	bx, bx			; new table index
	jmp	SHORT @@eachelement

@@havestringmatch:

	mov	bx, [ WORD PTR LEVEL ]		; offset by level

	; get level weight
	mov	al, ES:[ BYTE PTR ( COMPRESSION PTR DI + BX ).LevelWeight  ]

	xor	ch, ch
	mov	cl, ES:[ BYTE PTR ( COMPRESSION PTR DI ).ElementLength ]

	; advance original string pointer to end of compress string
	add	si, cx

@@stringdone:

	clc		; success

@@ExitGetCompressLevelWeight:

	pop	cx bx di es

	ret
	
@@nocmpstring:

	; restore original character and pointer
	mov	al, [ BYTE PTR SI ]
	inc	si

	stc		; no substitute found

	jmp	SHORT @@ExitGetCompressLevelWeight


_GetCompressLevelWeight ENDP

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;                                                      ;
	; PROC GetExpansionString NEAR                         ;
	;                                                      ;
	; DS:SI	= string                                       ;
	; SS:BX = address of current string status information ;
	;    AL	= character to expand                          ;
	;    DL	= STRINGLEVELSTATE                             ;
	;                                                      ;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUBLIC _GetExpansionString
_GetExpansionString PROC NOLANGUAGE NEAR

	les	di, [ dword ptr _pLocale_local ]

	LES_	di, DPTR_ ES:[ ( LOCALEOBJECT PTR DI ).pExpandTbl ]

	sub	di, SIZE EXPANSION

@@nextelement:

	add	di, SIZE EXPANSION		; point to next element

	cmp	ES:[ ( EXPANSION PTR DI ).ExpCollationElement ], 0
	je	@@noexpstring

	cmp	ES:[ ( EXPANSION PTR DI ).ExpCollationElement ], al
	jne	@@nextelement


	; save the length
	mov	al, ES:[ ( EXPANSION PTR DI ).ExpansionLength ]
	xor	ah, ah
	mov	word ptr ss:[ bx.AUX_STRING_CNT ], ax

	; a match was found, so to point to the level weights

	; **********************************************************
	; NOTE: THIS MAKES ASSUMPTIONS ABOUT THE EXPANSION STRUCTURE
	; **********************************************************

	inc	di			; ExpansionLength
	inc	di			; LevelWeight1

	push	cx

	;
	; point to level weights
	;

	mov	cx, [ WORD PTR LEVEL ]
	jcxz	@@havelevel
@@add:
	add	di, MAX_EXPANSION_ELEMENT_SIZE
	dec	cx
	jnz	@@add

@@havelevel:

	pop	cx

	mov	SS:[ ( STRINGSTATUS PTR BX ).AUX_STRING_OFF ], di
	mov	SS:[ ( STRINGSTATUS PTR BX ).AUX_STRING_SEG ], es

	; GetNextKeyWeight incremented already
	; GetNextExpansionWeight will increment this correctly

	dec	SS:[ ( STRINGSTATUS PTR BX ).CURRENT_POSITION ]

	or	dl, INEXPANSION		; turn on expansion processing

	clc

	ret

@@noexpstring:

	stc

	ret

_GetExpansionString ENDP




	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;                                                      ;
	; PROC GetNextAuxChar NEAR                             ;
	;                                                      ;
	; SS:BX = address of current string status information ;
	;    DL	= STRINGLEVELSTATE                             ;
	;                                                      ;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUBLIC _GetNextAuxChar
_GetNextAuxChar PROC NOLANGUAGE NEAR

	mov	di, SS:[ ( STRINGSTATUS PTR BX ).AUX_STRING_OFF ]
	mov	es, SS:[ ( STRINGSTATUS PTR BX ).AUX_STRING_SEG ]

	mov	al, BYTE PTR ES:[ DI ]

	test	al, al
	jz	@@endofstring

	inc	di			; increment aux string pointer

	mov	SS:[ ( STRINGSTATUS PTR BX ).AUX_STRING_OFF ], di
	inc	SS:[ ( STRINGSTATUS PTR BX ).CURRENT_POSITION ]

	clc

	ret

@@endofstring:

	stc
	ret

_GetNextAuxChar ENDP


	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;                                                      ;
	; PROC GetNextExpansionWeight NEAR                     ;
	;                                                      ;
	; SS:BX = address of current string status information ;
	;    DL	= STRINGLEVELSTATE                             ;
	;                                                      ;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUBLIC _GetNextExpansionWeight
_GetNextExpansionWeight PROC NOLANGUAGE NEAR

	mov	es, SS:[ WORD PTR ( STRINGSTATUS PTR BX ).AUX_STRING_SEG ]

@@eachweight:

	mov	di, SS:[ WORD PTR ( STRINGSTATUS PTR BX ).AUX_STRING_OFF ]

	cmp	SS:[ ( STRINGSTATUS PTR BX ).AUX_STRING_CNT ], 0
	jz	@@endofstring

	mov	al, BYTE PTR ES:[ DI ]

	inc	SS:[ ( STRINGSTATUS PTR BX ).AUX_STRING_OFF ]

	dec	SS:[ ( STRINGSTATUS PTR BX ).AUX_STRING_CNT ]

	inc	SS:[ ( STRINGSTATUS PTR BX ).CURRENT_POSITION ]

	; IGNORE_WEIGHT?
	test	al, al
	jz	@@eachweight

	clc

	ret

@@endofstring:

	stc
	ret

_GetNextExpansionWeight ENDP


Code_EndS@
               END ; end module collate.asm

