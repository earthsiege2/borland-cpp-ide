/*-----------------------------------------------------------------------*
 * filename - tlsdyn.c
 *
 * function(s)
 *
 *   ___CRTL_TLS_Alloc
 *   ___CRTL_TLS_Free
 *   ___CRTL_TLS_GetValue
 *   ___CRTL_TLS_SetValue
 *   ___CRTL_TLS_InitThread
 *   ___CRTL_TLS_ExitThread
 *
 *   These functions simulate the behavior of the system TLS routines, but
 *   only consume one system TLS slot for the entire process, regardless of
 *   the number of pseudo-slots these functions distribute.  These routines
 *   are linked in only when linking with the dynamic RTL (the RTLDLL import
 *   lib).  Therefore every process that uses the RTLDLL in its EXE and all
 *   it's DLLs, will consume only one real system TLS slot.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.5  $        */

#include <_defs.h>
#include <_io.h>
#include <windows.h>
#include <stdio.h>
#include <stdarg.h>

#if 0
#define LOG_TLS
#endif

#ifdef LOG_TLS
#define LOGSTR(a) a

/* This TLS stuff is a pain to debug, so here are some logging support routines
   to help aid the process.  Normally these are disabled with the absence of
   the LOG_TLS define. */

static HANDLE log_handle(void)
{
    static HANDLE rc = 0;
    if (!rc)
        rc = CreateFile("tls.log",
                       GENERIC_WRITE|GENERIC_READ,
                       FILE_SHARE_READ,
                       NULL,
                       CREATE_ALWAYS,
                       FILE_ATTRIBUTE_NORMAL | FILE_FLAG_WRITE_THROUGH,
                       NULL);
    return rc;
}

static void tls_log(char const *fmt, ...)
{
    unsigned long nw;
    char buf[1024];
    va_list ap;
    va_start(ap, fmt);
    wsprintf (buf, "thd:%08X ", GetCurrentThreadId());
    wvsprintf(&buf[strlen(buf)], fmt, ap);
    va_end(ap);
    strcat(buf, "\r\n");
    WriteFile(log_handle(), buf, strlen(buf), &nw, NULL);
}
#else /* LOG_TLS */
#define LOGSTR(a) NULL
static __inline void tls_log(char const *fmt, ...)
{
  /* The compiler should optimize out this empty inline function */
}
#endif /* LOG_TLS */


#ifdef DEBUG
static void TlsAssertFct(char const *cond, char const *file, int line)
{
    char msg[1024];

    wsprintf(msg, "Internal Assertion: %s:%d: %cond", file, line, cond);
    _ErrorExit(msg);
}
#define assert(x) (x) ? (void) 0 : TlsAssertFct(#x, __FILE__, __LINE__)
#else
#define assert(x)
#endif /* DEBUG */



#define TLS_ERROR_ID      (0xFFFFFFFF)
#define TLS_MAP_INCREMENT 4               /* # of bytes to grow TlsIndexMap */

/****************************************************************************
 WARNING!!! Don't use any un-initialized data (BSS) in this file.  This is
 because the BSS segment has not been initilized by the startup code yet, and
 will contain random values (Yikes!)  Therefore, always initialize all globals
 and statics in this file.
 ****************************************************************************/

static int SlotCount      = 8;            /* Initial # of pseudo slots */
static int CurrentlyUsed  = 0;            /* tracks the total # of slots in use */
static DWORD SystemIndex  = TLS_ERROR_ID; /* Holds the real system slot index */
static CRITICAL_SECTION _tls_lock = {0};  /* used for the thread locking */

static int StatTotal      = 0;            /* total # of blocks allocated
                                             (1 per thread) */

static struct                             /* Used for the bitmap of availible
                                             slots */
{
    unsigned char *  bitmap;
    size_t           size;
} TlsIndexMap = {0};

typedef struct                            /* Used for the DLL module TLS list
                                             (per thread) */
{
  size_t             size;
  LPVOID *           data;
  unsigned int       ref;                 /* ref count */
} RTL_TLS_DATA;

/****************************************************************************
 End of global data section.
 ****************************************************************************/

static void _lock_tls(void)
{
    static int first = 1;

/* Create the lock used to govern access to the TLS system.
   This is done with the raw Win32 APIs and *NOT* the RTLs lock table (in
   _lock.c) since the RTL table needs initialization from the start/exit
   system which may not have happened yet when we arrive here. */

    if (first)
    {
      memset (&_tls_lock, 0, sizeof (_tls_lock));
      InitializeCriticalSection (&_tls_lock);
      first = 0;
    }
    EnterCriticalSection (&_tls_lock);
}

static void _unlock_tls(void)
{
    LeaveCriticalSection (&_tls_lock);
}

/* We cannot use the RTL memory allocation routines (since they may not have
   been initilized yet), so we provide TlsMemAlloc / TlsMemRealloc /
   TlsMemFree to wrap our custom allocation routines.

   Note: do not call without first acquiring the _tls_lock

   These are some helper macros that add in the line # at which the alloc/free
   occured so that it can be logged out. */

#define TlsMemAlloc(a)       _TlsMemAlloc(__LINE__, a)
#define TlsMemRealloc(a,b)   _TlsMemRealloc(__LINE__,a,b)
#define TlsMemFree(a)        _TlsMemFree(__LINE__,a)


#if 0
static void CheckAddr (void *p)
{
  int x;
  x = HeapValidate (GetProcessHeap(), 0, p);
  tls_log(LOGSTR("       Addr check: %08X %s"), p, (x ? "Good" : "Bad"));
  if (!x)
  {
    _ErrorExit ("Danger, corrupt heap!");
  }
}
#endif

static __inline void * _TlsMemAlloc(int line, size_t n)
{
    void *p;
    p = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, n);
    tls_log(LOGSTR("Status: [%08X, %4d] MemAlloc:%X"), p, line, n);
    return p;
}

static __inline void * _TlsMemRealloc(int line, void * p, size_t n)
{
    void *ptr;
    ptr = HeapReAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, p, n);
    tls_log(LOGSTR("Status: [%08X, %4d] MemReAlloc: %X (%08X)"), p, line, n, ptr);
    return ptr;
}

static __inline void _TlsMemFree(int line, void *p)
{
    tls_log(LOGSTR("Status: [%08X, %4d] MemFree"), p, line);
    HeapFree(GetProcessHeap(), HEAP_ZERO_MEMORY, p);
}

static int TlsIndexMap_init(void)
{
    unsigned char *p = TlsMemAlloc(TLS_MAP_INCREMENT);
    if (p)
    {
        p[0] = 0xFE;  /* ensure first bit is marked allocated */
        p[1] = p[2] = p[3] =  0xFF;
        TlsIndexMap.bitmap = p;
        TlsIndexMap.size = TLS_MAP_INCREMENT;
    }
    return p != NULL;
}

static int TlsIndexMap_grow(void)
{
    size_t n = TlsIndexMap.size + TLS_MAP_INCREMENT;
    unsigned char *p = TlsMemRealloc(TlsIndexMap.bitmap, n);
    if (p) {
        assert(sizeof(size_t) == TLS_MAP_INCREMENT);
        ((size_t *)(p + TlsIndexMap.size))[0] = (~0);  // All 1's

        TlsIndexMap.bitmap = p;
        TlsIndexMap.size = n;
    }
    return p != NULL;
}

static void __inline TlsIndexMap_free(void)
{
    TlsMemFree(TlsIndexMap.bitmap);
}

static int allocTlsIndex(void)
{
    size_t ByteIndex = 0;
    register unsigned bit;
    unsigned n;

    /* Make sure we've allocated the index map */
    if (!TlsIndexMap.bitmap)
        if (!TlsIndexMap_init())
            return TLS_ERROR_ID;

    /* Find the first byte in the map that has a bit set */
    while (!TlsIndexMap.bitmap[ByteIndex] && ByteIndex < TlsIndexMap.size)
        ++ByteIndex;

    if (ByteIndex == TlsIndexMap.size)
    {
        ++ByteIndex;
        if (!TlsIndexMap_grow())
        {
            tls_log(LOGSTR("Error: TlsIndexMap_grow failed:%ld"), GetLastError());
            return TLS_ERROR_ID;
        }
    }

    /* Find the first bit set within the byte, and clear it. */
    n = TlsIndexMap.bitmap[ByteIndex];
    if      (n & 0x01) bit = 0;
    else if (n & 0x02) bit = 1;
    else if (n & 0x04) bit = 2;
    else if (n & 0x08) bit = 3;
    else if (n & 0x10) bit = 4;
    else if (n & 0x20) bit = 5;
    else if (n & 0x40) bit = 6;
    else if (n & 0x80) bit = 7;
    TlsIndexMap.bitmap[ByteIndex] &= (unsigned char) ~(1U << bit);

    /* Bit 0 in the first byte is reserved! */
    assert(ByteIndex > 0 || bit != 0);

    tls_log(LOGSTR("Status:allocTlsIndex returns:%lu"), ByteIndex * 8 + bit);
    return ByteIndex * 8 + bit;
}

static __inline void freeTlsIndex(unsigned n)
{
    tls_log(LOGSTR("Status:freeTlsIndex:%lu"), n);

    /* Simply clear the corresponding bit: don't free any memory here */
    TlsIndexMap.bitmap[n / 8] |= (unsigned char) (1 << (n % 8));
}


DWORD WINAPI _EXPFUNC ___CRTL_TLS_Alloc (void)
{
    /* The indices used are 1 based, 0 is never used (since the startup
       code uses 0 as the uninitialized value). */

    DWORD ret;

    if (SystemIndex == TLS_ERROR_ID)
    {
        SystemIndex = TlsAlloc ();
        if (SystemIndex == TLS_ERROR_ID) {
            tls_log(LOGSTR("Error: TlsAlloc failed:%ld"), GetLastError());
            return TLS_ERROR_ID;
        }
    }

    _lock_tls();
    ret = allocTlsIndex();
    if (++CurrentlyUsed >= SlotCount)
      SlotCount *= 2;

    _unlock_tls();

    tls_log(LOGSTR("Status:___CRTL_TLS_Alloc:%lu"), ret);

    if (ret == TLS_ERROR_ID)
    {
        _ErrorExit ("TLSDYN Error: allocTlsIndex failed");
    }

    return ret;
}

BOOL WINAPI _EXPFUNC ___CRTL_TLS_Free (DWORD id)
{
    _lock_tls();
    freeTlsIndex(id);
    --CurrentlyUsed;
    _unlock_tls();
    return TRUE;
}

static BOOL _resize (RTL_TLS_DATA * p)
{
    LPVOID *ptr;

    tls_log(LOGSTR("Need to resize: SlotCount:%lu Total:%lu p->size:%lu"), SlotCount, CurrentlyUsed, p->size);

    if (p->data == NULL)
        ptr = TlsMemAlloc((sizeof (LPVOID) * SlotCount));
    else
        ptr = TlsMemRealloc(p->data, (sizeof (LPVOID) * SlotCount));

    if (!ptr) {
        tls_log(LOGSTR("Error: _resize failed:%ld"), GetLastError());
        return FALSE;
    }

    p->data = ptr;
    p->size = SlotCount;
    return TRUE;
}

static LPVOID * _helper (DWORD id)
{
    RTL_TLS_DATA * p = TlsGetValue (SystemIndex);

    if (p == NULL)
    {
        tls_log(LOGSTR("Status: _helper p==NULL"));

        /* We were called from a new thread, so allocate the block: */
        p = TlsMemAlloc(sizeof (RTL_TLS_DATA));
        if (!p)
            _ErrorExit ("TLSDYN Error: TlsMemAlloc failed");

        TlsSetValue (SystemIndex, p);
        ++StatTotal;
    }

    if (id >= p->size)
    {
        /* Resize the array in this thread */
        _lock_tls();
        if (!_resize (p))
            p = NULL;
        _unlock_tls();
    }

    if (!p)
        _ErrorExit ("TLSDYN Error: resize failed");

    return &(p->data[id]);

}

LPVOID WINAPI _EXPFUNC ___CRTL_TLS_GetValue (DWORD id)
{
    LPVOID *p;
    p = _helper(id);  /* Helper will terminate if anything bad happens */
    tls_log(LOGSTR("Status:___CRTL_TLS_GetValue(%lu) returns %08X [%08X]"), id, p, p ? *p : NULL);
    return *p;
}

BOOL WINAPI _EXPFUNC ___CRTL_TLS_SetValue (DWORD id, LPVOID value)
{
    LPVOID *p;
    tls_log(LOGSTR("Status:___CRTL_TLS_SetValue(%lu, %08X)"), id, value);

    p = _helper (id);  /* Helper will terminate if anything bad happens */

    *p = value;

    return TRUE;
}


void WINAPI _EXPFUNC ___CRTL_TLS_InitThread (DWORD id)
{
    RTL_TLS_DATA * p = TlsGetValue (SystemIndex);

    if (p == NULL)
    {
        /* Should not be null here. */
        _ErrorExit ("TLSDYN Error: InitThread failed");
    }

    p->ref++;
    tls_log(LOGSTR("Status:___CRTL_TLS_InitThread(id:%lu ref:%lu)"), id, p->ref);
}

void WINAPI _EXPFUNC ___CRTL_TLS_ExitThread (DWORD id)
{
    RTL_TLS_DATA * p = TlsGetValue (SystemIndex);

    if (p)
    {
        tls_log(LOGSTR("Status:___CRTL_TLS_ExitThread(id:%lu ref:%lu)"), id, p->ref);
        if (--p->ref == 0)
        {
            if (p->data)
                TlsMemFree (p->data);
             TlsMemFree (p);
             TlsSetValue (SystemIndex, 0);
        }
    }
}

int _RTLENTRY _EXPFUNC __CRTL_TLS_GetInfo (int *af, int *st)
/* This function in used for internal testing.  It returns the number of
   DLL clients (allocations) currently in use. */
{
    /* af returns the number of allocated, but free slots. */

    if (af)
      *af = (int)(TlsIndexMap.size * 8) - CurrentlyUsed;

    /* st returns the number of blocks (one per thread) that have been
       allocated. */

    if (st)
      *st = StatTotal;

    return CurrentlyUsed;
}
