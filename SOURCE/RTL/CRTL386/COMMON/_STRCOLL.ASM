;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; TITLE STRCOLL - ANSI C string collation for strcoll()
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


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
	EXTRN __pLocale                  	: NEAR PTR LOCALEOBJECT

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

Func@   _strcoll, public, _RTLENTRY, <pointer __s1>, <pointer __s2>

;
; declare locals having scope for this entire module
;
	LOCAL_VARS

	ENTER	STACKFRAMESIZE, 0

	push	edi esi ebx

	mov	ebx, [ dword ptr __pLocale ]

	mov	ax, [ WORD PTR ( LOCALEOBJECT PTR EBX ).CollationCat.CollateInfo.nLevels ]

	mov	[ MAXLEVEL ], ax

	mov	esi, [ ( LOCALEOBJECT PTR ebx ).pClass ]

	; skip 0th byte (padding)
	inc	esi

	mov	[ DWORD PTR pCHARCLASS ], esi

	mov	[ LEVEL ], 0		; initialize

	mov	[ LEVELOFFSET ], 0

	; point to strings
	mov	esi, [ __s1 ]
	mov	edi, [ __s2 ]

	call	LevelCollate

	cwde

@@equal:

	pop	ebx esi edi

	LEAVE

        ret

EndFunc@ _strcoll


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                      ;
; LevelCollate PROC NOLANGUAGE NEAR		       ;
;                                                      ;
; ESI First byte of first string  __s1	               ;
; EDI First byte of second string __s2	               ;
;                                                      ;
; ASSUMPTIONS:                                         ;
;                                                      ;
; LOCALS LEVEL, MAXLEVEL have been set or initialized  ;
;                                                      ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


LevelCollate PROC NOLANGUAGE NEAR

	; initialize local storage
	mov	[ WEIGHT_DIFFERENCE ], 0
	mov	[ POSITION_DIFFERENCE ], 0
	mov	[ ( STRINGSTATUS PTR S1_STATUS ).CURRENT_POSITION ], 0
	mov	[ ( STRINGSTATUS PTR S2_STATUS ).CURRENT_POSITION ], 0


	; get locale pointer and get collation rules for current level

	mov	ebx, [ dword ptr __pLocale ]

	movzx	ecx, [ LEVEL ]			; offset by level

	add	ebx, ecx				; add to locale

	; offset to rules
	mov	al, [ BYTE PTR ( LOCALEOBJECT PTR ebx ).CollationCat.CollateInfo.LevelRules ]

	; size of offset from class to current weight level table
	add	[ LEVELOFFSET ], CODESET_SIZE + 1

	mov	ch, al

	xor	edx, edx

	; AX is used for string weights
	; BX is used for offset to string status
	; DX is used for string status
	; CH is used current level rules


@@eachweight:

	; point to string 1 status

	lea	ebx, S1_STATUS

	; get string 1 weight

	call	GetNextKeyWeight	; get weight in al

	mov	cl, al			; save string1 weight

	xchg	dl, dh			; swap string 1 and 2 rules

	; point to string 2 status

	lea	ebx, S2_STATUS

	push	esi edi

 	pop	esi

	; get string 2 weight

	call	GetNextKeyWeight	; get weight in al

	push	esi

	pop	edi esi

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

	xchg	al, ah

	cbw

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
	xchg	al, ah

	; any difference in weights?
	test	al, al
	jz     @@eachweight

	cbw

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
;;;	lds	si, [ __s1 ]		; start of string 1
;;;    	les	di, [ __s2 ]		; start of string 2

	mov	esi, [ __s1 ]
	mov	edi, [ __s2 ]

	jmp	LevelCollate		; jump to next level of collation


LevelCollate ENDP


Code_EndS@

               END ; end module _strcoll.asm
