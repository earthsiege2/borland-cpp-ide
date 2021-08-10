;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; TITLE COLLATE - ANSI C string collation common support
;                 functions called by strcoll() & strxfrm()
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1993, 1996 by Borland International
;       All Rights Reserved.
; 

	INCLUDE RULES.ASI

	INCLUDE _LOCALE.INC

	INCLUDE _COLLATE.MAC

Header@

Code_Seg@

	EXTRN __pLocale              : FAR PTR LOCALEOBJECT

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
	; GetNextKeyWeight PROC NOLANGUAGE NEAR                ;
	;                                                      ;
	;   EBX = address of current string status information ;
	;                                                      ;
	; Optimized for non-special handling                   ;
	;                                                      ;
	; Returns next character weight in AL                  ;
	;                                                      ;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


PUBLIC GetNextKeyWeight
GetNextKeyWeight PROC NOLANGUAGE NEAR

	push    edi

@@eachchar:

	; check for special handling
	test    dl, dl
	jnz     @@specials

@@nospecials:

	; get next character from string
	movzx   eax, byte ptr [ esi ]

	inc     esi

	inc     [ ( stringstatus ptr ebx ).current_position ]

@@getclass:

	; end of string?
	test    al, al
	jz      @@endofstring

@@havecharacter:

	; point to class table
	mov     edi, dword ptr pCHARCLASS

	add     edi, eax                ; offset by character
	mov     ah,  byte ptr [ edi ]   ; get character's class
		
@@check_substitute:

	test    ah, NOT CLASS_NORMAL
	jnz     @@notnormal

@@lookup_charweight:

	;
	; POINT TO WEIGHT TABLE FOR THIS LEVEL
	; EDI is still indexing AL's (character) class
	; add the appropriate number of 257 offsets
	; because these tables are contiguous
	;


	; offset from character's class to character's level weight
	add     edi, [ leveloffset ]

	; get the weight
	mov     al, byte ptr [ edi ]

@@check_weight_type:

	; should ignore this character's weight?
	cmp     al, IGNORE_WEIGHT
	je      @@eachchar                      ; yes, fetch another

@@return_weight:

	pop     edi
	ret

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@@notnormal:

	; character of this class?
	test    ah, CLASS_SUBSTITUTE
	jz      @@check_expand          ; no

	; rule applies at this level?
	test    ch, SUBSTITUTE_RULE
	jz      @@check_expand          ; no

	; already processing a substitute string?
	; nested substitutions are not legal

	test    dl, INSUBSTITUTION
	jnz     @@check_expand


	; get a possible substitute string
	call    GetSubstituteString
	jnc     @@getsubchar

@@check_expand:

	; character of this class?
	test    ah, CLASS_EXPAND
	jz      @@check_compress

	; already processing an expansion string?
	; nested expansions are not legal

	test    dl, INEXPANSION
	jnz     @@check_compress

	; get the expansion string
	call    GetExpansionString
	jnc     @@getexpchar

@@check_compress:

	test    ah, CLASS_COMPRESS
	jz      @@lookup_charweight

	call    GetCompressLevelWeight
	jnc     @@check_weight_type
	
	xor     ah, CLASS_COMPRESS
	jmp     SHORT @@lookup_charweight

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@@endofstring:
	or      dl, STRING_ENDED
	jmp     SHORT @@return_weight

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

@@specials:
	test    dl, INSUBSTITUTION
	jz      @@nosubstitution

@@getsubchar:
	call    GetNextAuxChar          ; return character in AL
	jnc     @@havecharacter

	xor     dl, INSUBSTITUTION      ; turn off substitution processing
	
@@nosubstitution:
	test    dl, INEXPANSION
	jz      @@nospecials

@@getexpchar:

	call    GetNextExpansionWeight  ; return weight in AL
	jnc     @@check_weight_type

	xor     dl, INEXPANSION         ; turn off expansion processing
	jmp     @@nospecials


GetNextKeyWeight ENDP


	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;                                                      ;
	; GetSubstituteString PROC NOLANGUAGE NEAR             ;
	;                                                      ;
	;   ESI = string                                       ;
	;   EBX = address of current string status information ;
	;    DL = STRINGLEVELSTATE                             ;
	;                                                      ;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

GetSubstituteString PROC NOLANGUAGE NEAR

	push    edi ecx ebx

@@subtable:

	; use EDI to point to substitution table

	mov     ebx, [ dword ptr __pLocale ]

	mov     edi, dword ptr [ ( localeobject ptr ebx ).psubstitutiontbl ]

	xor     ebx, ebx                ; table index 
	
	; al still has valid character
	dec     esi                     ; has already been advanced

@@eachelement1:

	; end of table?
	cmp     [ byte ptr ( substitution ptr edi + ebx ).stringlength ], 0
	je      @@nosubstring

	; count
	movzx   ecx, [ byte ptr ( substitution ptr edi + ebx ).stringlength ]

@@compare_string_to_table2:

	; compare StringElement character with string character
	; if no match go to next StringElement

	cmp     byte ptr [ ( substitution ptr edi + ebx ).stringelement ], al
	jne     @@nextelement1
		
	; a string character matched with corresponding table character
	inc     ebx                             ; increment index
	dec     ecx                             ; decrement count

	mov     al, byte ptr [ esi + ebx ]      ; next string character

	; all characters matched for length of StringElement
	cmp     ecx, 0                  ;jecxz  @@havestringmatch
	je      @@havestringmatch

	jmp     SHORT @@compare_string_to_table2
	
@@nextelement1:
	add     edi, SIZE SUBSTITUTION  ; point to next element
	xor     ebx, ebx                ; new table index 
	jmp     SHORT @@eachelement1


@@havestringmatch:

	movzx   ecx, [ byte ptr ( substitution ptr edi ).stringlength ]

	; advance original string pointer to end of substituted string
	add     esi, ecx

	; point to ( next element - sub string )
	add     edi, ( size substitution - max_substitution_element_size )

	pop     ebx
	pop     ecx

	; save substring address
	mov     dword ptr [ ( stringstatus ptr ebx ).aux_string_addr ], edi

	dec     word ptr [ ( stringstatus ptr ebx ).current_position ]

	or      dl, INSUBSTITUTION

@@stringdone1:

	clc             ; success

	pop     edi

	ret
	

@@nosubstring:

	pop     ebx
	pop     ecx

	; restore original string position and character

	inc     esi
	mov     al, [ byte ptr esi ]

	stc             ; no substitute found

@@ExitGetSubstituteString:

	pop     edi
	
	ret

GetSubstituteString ENDP

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;                                                      ;
	; GetCompressLevelWeight PROC NOLANGUAGE NEAR          ;
	;                                                      ;
	;   ESI = string                                       ;
	;   EBX = address of current string status information ;
	;    DL = STRINGLEVELSTATE                             ;
	;                                                      ;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

GetCompressLevelWeight PROC NOLANGUAGE NEAR


	push    edi ebx ecx

	mov     ebx, [ dword ptr __pLocale ]

@@exptable:

	mov     edi, dword ptr [ ( localeobject ptr ebx ).pcompresstbl ]

	xor     ebx, ebx                        ; table index 
	xor     ecx, ecx                        

	dec     esi                     ; account for increment

	; al still has valid character
;;;     mov     al, [ BYTE PTR DS:SI ]

@@eachelement2:

	; count
	mov     cl, [ ( compression ptr edi ).elementlength ]

	; end of table?
	cmp     [ ( compression ptr edi + ebx ).elementlength ], 0
	je      @@nocmpstring

@@compare_string_to_table1:

	; compare StringElement character with string character
	; if no match go to next StringElement

	cmp     [ ( compression ptr edi + ebx ).cmpcollationelement ], al
	jne     @@nextelement2
		
	; a string character matched with corresponding table character
	inc     ebx                             ; increment index
	dec     ecx                             ; decrement count

	mov     al, [ byte ptr esi + ebx ]      ; next string character

	; all characters matched for length of ElementLength
	jcxz    @@havestringmatch2

	jmp     SHORT @@compare_string_to_table1

@@nextelement2:

	add     edi, SIZE COMPRESSION   ; point to next element
	xor     ecx, ecx                ; new count
	xor     ebx, ebx                ; new table index 
	jmp     SHORT @@eachelement2

@@havestringmatch2:

	movzx   ebx, [ word ptr level ]         ; offset by level

	; get level weight
	mov     al, [ BYTE PTR ( COMPRESSION PTR edi + ebx ).LevelWeight  ]

	movzx   ecx, [ BYTE PTR ( COMPRESSION PTR edi ).ElementLength ]

	; advance original string pointer to end of compress string
	add     esi, ecx

@@stringdone2:

	clc             ; success

@@ExitGetCompressLevelWeight:

	pop     ecx ebx edi

	ret
	
@@nocmpstring:

	; restore original character and pointer
	mov     al, [ byte ptr esi ]
	inc     esi

	stc             ; no substitute found

	jmp     SHORT @@ExitGetCompressLevelWeight


GetCompressLevelWeight ENDP

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;                                                      ;
	; GetExpansionString PROC NOLANGUAGE NEAR              ;
	;                                                      ;
	;   ESI = string                                       ;
	;   EBX = address of current string status information ;
	;    AL = character to expand                          ;
	;    DL = STRINGLEVELSTATE                             ;
	;                                                      ;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

GetExpansionString PROC NOLANGUAGE NEAR

	mov     edi, [ dword ptr __pLocale ]

	mov     edi, [ DWORD PTR ( LOCALEOBJECT PTR edi ).pExpandTbl ]

	sub     edi, SIZE EXPANSION

@@nextelement3:

	add     edi, SIZE EXPANSION             ; point to next element

	cmp     [ ( EXPANSION PTR edi ).ExpCollationElement ], 0
	je      @@noexpstring

	cmp     [ ( EXPANSION PTR edi ).ExpCollationElement ], al
	jne     @@nextelement3


	; save the length
	movzx   ax, byte ptr [ ( EXPANSION PTR edi).ExpansionLength ]
;;;     xor     ah, ah
	
;       mov     [ DWORD PTR SS:( STRINGSTATUS PTR BX ).AUX_STRING_CNT ], ax
 
	mov     word ptr [ ebx.AUX_STRING_CNT ], ax

	; a match was found, so to point to the level weights

	; **********************************************************
	; NOTE: THIS MAKES ASSUMPTIONS ABOUT THE EXPANSION STRUCTURE
	; **********************************************************

	inc     edi                     ; ExpansionLength
	inc     edi                     ; LevelWeight1

	push    ecx

	; 
	; point to level weights
	; 

	movzx   ecx, [ WORD PTR LEVEL ]
	jecxz   @@havelevel
@@add:
	add     edi, MAX_EXPANSION_ELEMENT_SIZE
	dec     ecx
	jnz     @@add

@@havelevel:

	pop     ecx

	mov     dword ptr [ ( STRINGSTATUS PTR ebx ).AUX_STRING_ADDR ], edi

	; GetNextKeyWeight incremented already
	; GetNextExpansionWeight will increment this correctly

	dec     [ ( STRINGSTATUS PTR ebx).CURRENT_POSITION ]

	or      dl, INEXPANSION         ; turn on expansion processing

	clc

	ret

@@noexpstring:

	stc

	ret

GetExpansionString ENDP




	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;                                                      ;
	; GetNextAuxChar PROC NOLANGUAGE NEAR                  ;
	;                                                      ;
	;   EBX = address of current string status information ;
	;    DL = STRINGLEVELSTATE                             ;
	;                                                      ;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

GetNextAuxChar PROC NOLANGUAGE NEAR

	mov     eax,  [ ( stringstatus ptr ebx ).aux_string_addr ]

	movzx   eax,  byte ptr [ eax ]

	test    al, al
	jz      @@endofstring1

	; increment aux string pointer
	inc     dword ptr [ ( stringstatus ptr ebx ).aux_string_addr ]

	; increment aux string position
	inc     [ ( stringstatus ptr ebx ).current_position ]

	clc

	ret

@@endofstring1:

	stc
	ret

GetNextAuxChar ENDP


	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;                                                      ;
	; GetNextExpansionWeight PROC NOLANGUAGE NEAR          ;
	;                                                      ;
	; EBX  = address of current string status information  ;
	;  DL  = STRINGLEVELSTATE                              ;
	;                                                      ;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

GetNextExpansionWeight PROC NOLANGUAGE NEAR

@@eachweight:

	mov     edi, dword ptr [ ( stringstatus ptr ebx ).aux_string_addr ]

	cmp     [ ( stringstatus ptr ebx ).aux_string_cnt ], 0
	jz      @@endofstring2

	mov     al, [ byte ptr edi ]

	inc     [ ( stringstatus ptr ebx).aux_string_addr ]

	dec     [ ( stringstatus ptr ebx ).aux_string_cnt ]

	inc     [ ( stringstatus ptr ebx ).current_position ]

	; IGNORE_WEIGHT?
	test    al, al
	jz      @@eachweight

	clc

	ret

@@endofstring2:

	stc
	ret

GetNextExpansionWeight ENDP

Code_EndS@
	       END ; end module collate.asm

