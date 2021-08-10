/*
**
**      INT2F.H
**
**      This .h file contains mnemonics which should be used by
**      anyone who utilizes the services of the Int 2fh Multiplex
**      Interrupt.  Both the protected mode and real mode versions of
**      the BOSS loader are using the INT 2fh with ax = fb42h for a
**      callback mechanism to supply run time services to a client program.
**      All services supplied are compatible with both the protected mode
**      and the real mode loader so that client programs can be written
**      "transparently" with respect to which mode they are running in.
**
**      INT 2fh with ax = fb43h is a callback mechanism for communicating
**      with the debugger.  If the debugger is not present, the request is
**      ignored.
**
**      If you have any questions about the information contained in this
**      file please contact Judy Fitzgerald (ext 1926) or Gabor Ligeti
**      (ext 1934).  Comments and suggestions would also be appreciated.
**
**      Borland DPMI Loader
**
**      THIS SOURCE CODE IS BORLAND CONFIDENTIAL INFORMATION AND
**      CONSTITUTES A PROPRIETARY TRADE SECRET OF BORLAND
**      INTERNATIONAL.
**

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#define BOSSINT                         2fh
#define BOSSAPIMAX                      32
**
**    Memory Management APIs
*/
#define BOSS_GetFreeMemoryInfo          3
#define BOSS_AllocateMemory             2
#define BOSS_ResizeMemory               9
#define BOSS_DeallocateMemory           8
#define BOSS_OpenOrModifyMemoryWindow   15
#define BOSS_CloseMemoryWindow          12
#define BOSS_MapSegmentAddrToLDTDesc    16
#define BOSS_GetCodePoolSize            29
#define BOSS_SetCodePoolSize            23
#define BOSS_SetCodePoolModel           24
#define BOSS_LocateMoveableSegment      25
#define BOSS_GangLoadSegments           28

//    DLL Management APIs

#define BOSS_LoadDLL                    4
#define BOSS_GetDLLAddressByName        5
#define BOSS_GetDLLAddressByNumber      6
#define BOSS_UnloadDLL                  7

//    BOSSSTUB APIs

#define BOSS_RequestLoaderStatus        20
#define BOSS_LoadAndExecuteProcess      10
#define BOSS_RequestLoaderTerminate     21


//    Miscellaneous

#define BOSS_GetMode_IncrementValue          1
#define BOSS_GetCodeSegmentAlias             18
#define BOSS_SimulateRealModeInt             13
#define BOSS_DetermineStatusOfLoader         19
#define BOSS_GetModuleLoadCount              22
#define BOSS_GetModuleHandleByFilename       14
#define BOSS_GetFilenameByModuleHandle       17
#define BOSS_ConvertSegmentNoToSelector      19
#define BOSS_ConvertSelectorToSegmentHandle  26
#define BOSS_ConvertSegmentHandleToSelector  27
#define BOSS_ConvertSegmentIDToSegmentHandle 30
#define BOSS_GetModuleHandleByModuleName     31
#define BOSS_FreezeUnfreezeStack             32


//    TDB APIs

#define TDB_ModStart                    0
#define TDB_SegLoad                     2
#define TDB_SegUnload                   4
#define TDB_LibLoad                     6
#define TDB_ModUnloaded                 8
#define TDB_ThunkStart                  10
#define TDB_ThunkEnd                    12
#define TDB_Terminate                   14
#define TDB_SegMove                     16
#define TDB_ForceReal                   100h

//      mpb_flags values

#define NSDATA          0x0001    // Data segment (0 = code segment)

#define NSALLOCATED     0x0002    // Memory allocated (0 = memory not
                                  // allocated) BOSS_AllocateMemory  API will
                                  // NOT allocate memory if this bit is
                                  // set!!!!!

#define NSREAL          0x0004    // Real mode segment (0 = protected mode
                                  // segment) this bit respected by the
                                  // protected mode loader but ignored by real
                                  // mode loader)

#define NSMOVE          0x0010    // Moveable segment (0 = fixed segment)

#define NSDISCARD       0x1000    // Discardable segment (0 = nondiscardable)


/* mpb_retstatus values
*/
#define STSUCCESS       0       // operation successful
#define STNOMEMORY      1       // no memory available
#define STBADHANDLE     2       // invalid memory handle
#define STBADSELECTOR   4       // invalid selector
#define STNOLDT         8       // LDT allocation failure
#define STLDTW64K       16      // LDT limit greater than 64K (defaults to 64K
#define STDOSERROR      32      // DOS control blocks damaged

#define STENTRYPOINT    -1      // DLL procedure entry point not found
#define STNOTLOADED     -2      // DLL currently not loaded
#define STMAXMAP        -3      // segment address to LDT mapping table full
#define STBADEXE        -4      // invalid EXE file
#define STDOSFILEIO     -5      // error during DOS file I/O operations
#define STINTERR        -6      // internal loader error (table overflow, etc)
#define STBADSEG        -7      // invalid segment number
#define STINUSE         -8      // DLL has non-zero use count
#define STBADSEGID      -9      // invalid segment ID
#define ST20MODS        -10     // request to load more than 20 modules
#define STFILENAME      -11     // filename exceeds 79 characters
#define STMODNAME       -12     // module name exceeds 8 characters
#define STLOADIMAGE     -13     // error in load image
#define STBADPARM       -14     // invalid calling parameter

// mpb selector values

#define NULL_LDT        0       // Automatic allocation of LDT when memory
                                // allocated

#define UNUSED_LDT      0xffff  // LDT not allocated during memory allocation
                                // (used when allocating > 64K bytes of
                                // memory)

// miscellaneous

#define NULL_PTR        ((void *)0L)
#define DOSPLATFORM     0       // used by STUB to communicate with appropriate
#define DPMIPLATFORM    1       //  loader
#define REAL            0       // current mode in DPMILOAD
#define PROTECTED       1       // [Mode]

/*stack freeze/unfreeze options
*/
#define FREEZE_SP       1
#define UNFREEZE_SP     2
#define FREEZE_SS_SP    3
#define UNFREEZE_SS_SP  4

/* code pool model values

   model type
*/

#define SEPARATEPOOL         0  // overlay segments allocated ONLY in
                                //    code pool
#define SHAREDPOOL           1  // overlay segments may be allocated in
                                //    outside the code pool (at the discretion
                                //    of the code pool manager)

/* model size determination
*/
#define MANUALCODEPOOLSIZE   2  // size of code pool must be set manually
#define AUTOCODEPOOLSIZE     0  // size of code pool set automatically by
                                //    code pool manager to minimum needed

/* compacting mode
*/
#define COMPACT              0  // code pool will be compacted if fragmented
                                // free space is sufficient to load requested
                                // segment
#define NOCOMPACT            4  // code pool will not be compacted.  Instead,
                                // segments will be discarded.


// Memory Parameter Block Structure

typedef struct
{
    void *mpb_callback;         // callback notification address
    unsigned mpb_flags;         // flags: (DISCARDABLE/REAL/DATA/MOVEABLE)

    unsigned long mpb_size;     // size of memory block

    unsigned long mpb_handle;   // memory handle (segment address if REAL seg)

    unsigned long mpb_linaddress; // linear address of memory block

    union
    {
        unsigned retstatus;     // STSUCCESS = successful
        void *mpb_address;      // selector / offset for memory block
    } u;

    unsigned mpb_alias;         // alias selector for memory block
} MPB;


// Provide access to pieces of the multi-word fields via macros.

#ifndef LOWORD
#define LOWORD(l)           ((WORD)(l))
#endif
#ifndef HIWORD
#define HIWORD(l)           ((WORD)(((DWORD)(l) >> 16) & 0xFFFF))
#endif
#ifndef FP_SEG
#define FP_SEG( fp )( (unsigned )( void _seg * )( void far * )( fp ))
#endif
#ifndef FP_OFF
#define FP_OFF( fp )( (unsigned )( fp ))
#endif

#define MPB_LOWSIZE(m)          LO_WORD((m).mpb_size)
#define MPB_HIGHSIZE(m)         HI_WORD((m).mpb_size)

#define MPB_SIHANDLE(m)         LO_WORD((m).mpb_handle)
#define MPB_DIHANDLE(m)         HI_WORD((m).mpb_handle)

#define MPB_LOWLINEAR(m)        LO_WORD((m).mpb_linaddress)
#define MPB_HIGHLINEAR(m)       HI_WORD((m).mpb_linaddress)

#define MPB_OFFSET(m)           FP_SEG((m).u.mpb_address)
#define MPB_SELECTOR(m)         FP_OFF((m).u.mpb_address)
