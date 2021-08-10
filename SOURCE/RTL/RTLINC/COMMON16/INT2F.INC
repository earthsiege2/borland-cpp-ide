;
;       INT2F.INC
;
;       This INCLUDE file contains mnemonics which should be used by
;       anyone who utilizes the services of the Int 2fh Multiplex
;       Interrupt.  Both the protected mode and real mode versions of
;       the BOSS loader are using the INT 2fh with ax = fb42h for a
;       callback mechanism to supply run time services to a client program.
;       All services supplied are compatible with both the protected mode
;       and the real mode loader so that client programs can be written
;       "transparently" with respect to which mode they are running in.
;
;       INT 2fh with ax = fb43h is a callback mechanism for communicating
;       with the debugger.  If the debugger is not present, the request is
;       ignored.
;
;       If you have any questions about the information contained in this
;       file please contact Judy Fitzgerald (ext 1926) or Gabor Ligeti
;       (ext 1934).  Comments and suggestions would also be appreciated.
;
;       Borland DPMI Loader
;
;       THIS SOURCE CODE IS BORLAND CONFIDENTIAL INFORMATION AND
;       CONSTITUTES A PROPRIETARY TRADE SECRET OF BORLAND
;       INTERNATIONAL.
;
;

;
;       C/C++ Run Time Library - Version 7.0
; 
;       Copyright (c) 1987, 1996 by Borland International
;       All Rights Reserved.
; 

;    Memory Management APIs

BOSS_GetFreeMemoryInfo          EQU     3
BOSS_AllocateMemory             EQU     2
BOSS_ResizeMemory               EQU     9
BOSS_DeallocateMemory           EQU     8
BOSS_OpenOrModifyMemoryWindow   EQU     15
BOSS_CloseMemoryWindow          EQU     12
BOSS_MapSegmentAddrToLDTDesc    EQU     16

;    DLL Management APIs

BOSS_LoadDLL                    EQU     4
BOSS_GetDLLAddressByName        EQU     5
BOSS_GetDLLAddressByNumber      EQU     6
BOSS_UnloadDLL                  EQU     7

;    Debugger APIs

BOSS_GetModuleHandleByFilename  EQU     14
BOSS_LoadAndExecuteProcess      EQU     10
BOSS_GetFilenameByModuleHandle  EQU     17
BOSS_ConvertSegmentNoToSelector EQU     19

;    Miscellaneous

BOSS_GetMode_IncrementValue     EQU     1
BOSS_GetCodeSegmentAlias        EQU     18
BOSS_SimulateRealModeInt        EQU     13
BOSS_RequestLoaderStatus        EQU     20
BOSS_RequestLoaderTerminate     EQU     21
BOSS_GetModuleLoadCount         EQU     22

;    TDB APIs

TDB_ModStart                    EQU     0
TDB_SegLoad                     EQU     2
TDB_LibLoad                     EQU     6
TDB_ModUnloaded                 EQU     8
TDB_ThunkStart                  EQU     10
TDB_ThunkEnd                    EQU     12
TDB_Terminate                   EQU     14
TDB_ForceReal                   EQU     100h

;mpb_flags values

NSDATA          =  0001h    ; Data segment (0 = code segment)
NSALLOCATED     =  0002h    ; Memory allocated (0 = memory not allocated)
                            ; BOSS_AllocateMemory  API will NOT allocate memory
                            ;   if this bit is set!!!!!
NSREAL          =  0004h    ; Real mode segment (0 = protected mode segment)
                            ; this bit respected by the protected mode
                            ; loader but ignored by real mode loader)
NSMOVE          =  0010h    ; Moveable segment (0 = fixed segment)
NSDISCARD       =  1000h    ; Discardable segment (0 = nondiscardable)

;mpb_retstatus values

STSUCCESS       EQU     0       ; operation successful
STNOMEMORY      EQU     1       ; no memory available
STBADHANDLE     EQU     2       ; invalid memory handle
STBADSELECTOR   EQU     4       ; invalid selector
STNOLDT         EQU     8       ; LDT allocation failure
STLDTW64K       EQU     16      ; LDT limit greater than 64K (defaults to 64K)
STDOSERROR      EQU     32      ; DOS control blocks damaged
STENTRYPOINT    EQU     -1      ; DLL procedure entry point not found
STNOTLOADED     EQU     -2      ; DLL currently not loaded
STMAXMAP        EQU     -3      ; segment address to LDT mapping table full
STBADEXE        EQU     -4      ; invalid EXE file
STDOSFILEIO     EQU     -5      ; error during DOS file I/O operations
STINTERR        EQU     -6      ; internal loader error (table overflow, etc)
STBADSEG        EQU     -7      ; invalid segment number
STINUSE         EQU     -8      ; DLL has non-zero use count
;mpb selector values

NULL_LDT        EQU     0       ; Automatic allocation of LDT when memory allocated
UNUSED_LDT      EQU     0ffffh  ; LDT not allocated during memory allocation
                                ; (used when allocating > 64K bytes of memory)

;miscellaneous

NULL_PTR        EQU     0
DOSPLATFORM     EQU     0
DPMIPLATFORM    EQU     1
REAL                    EQU     0       ;current mode in DPMILOAD
PROTECTED               EQU     1       ;[Mode]

; Memory Parameter Block Structure

MPB             STRUC
mpb_callback    dd      NULL_PTR; callback notification address
mpb_flags       dw      NSDATA  ; flags (DISCARDABLE/REAL/DATA/MOVEABLE)

mpb_size        equ this dword
mpb_lowsize     dw      0       ;/  memory block
mpb_highsize    dw      0       ;\ Size of

mpb_handle      equ this dword  ; memory handle (segment address if REAL seg )
mpb_SIhandle    dw      0
mpb_DIhandle    dw      0

mpb_linaddress  equ this dword
mpb_lowlinear   dw      0       ;/  of memory block
mpb_highlinear  dw      0       ;\ Linear address
                                ; ------------------------------------------
mpb_address     equ this dword
mpb_retstatus   equ this word   ;  STSUCCESS = successful
mpb_offset      dw     STSUCCESS;  Reserved
mpb_selector    dw      NULL_LDT;\ Selector and alias
mpb_alias       dw      NULL_LDT;/  for memory block
MPB             ENDS
