;----------------------------------------------------------------------
; _rerror.asm -  jump stubs for the for the PCRE functions
;----------------------------------------------------------------------

; $Copyright: 1998$
; $Revision: 9.3 $

include rules.asi
include entry.inc

  Entry@ regerror,_pcre_regerror             , _RTLENTRY, 0

end
