#include <windows.h>

/* $Revision:   8.1  $ */

DWORD _EXPDATA __ExceptionTLS;

void _InitExceptionTLS(unsigned reason)
{
    void *p;

    if (reason == DLL_PROCESS_ATTACH && !__ExceptionTLS)
        __ExceptionTLS = TlsAlloc();

    if (reason == DLL_PROCESS_ATTACH || reason == DLL_THREAD_ATTACH) 
    {
        p = LocalAlloc(LPTR, 8); 
        TlsSetValue(__ExceptionTLS, p); 
    }
}

void _ExitExceptionTLS(unsigned reason)
{
    void *p;

    if (reason == DLL_PROCESS_DETACH || reason == DLL_THREAD_DETACH)
    {
        p = TlsGetValue(__ExceptionTLS); 
        if (p != 0) 
            LocalFree((HLOCAL) p); 
    }

    if (reason == DLL_PROCESS_DETACH && __ExceptionTLS)
        TlsFree(__ExceptionTLS);
}
