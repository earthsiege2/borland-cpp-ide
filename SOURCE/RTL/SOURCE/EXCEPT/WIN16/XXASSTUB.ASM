;[]-----------------------------------------------------------------[]
;[]-----------------------------------------------------------------[]

        INCLUDE RULES.ASI

;	Segment and Group declarations

Header@

extrn		___InitExceptBlocksX:DIST

public		___InitExceptBlocks

_TEXT		SEGMENT

___InitExceptBlocks	PROC DIST
		mov	dx, ax
		call	___InitExceptBlocksX
		ret
		ENDP
_TEXT		ENDS

		END
