;----------------------------------------------------------------------
; _pcomp.asm -  jump stubs for the for the PCRE functions
;----------------------------------------------------------------------

; $Copyright: 1998$
; $Revision:   9.0  $

include rules.asi
include entry.inc

  Entry@ pcre_compile,_pcre_compile          , _RTLENTRY, 0

end
