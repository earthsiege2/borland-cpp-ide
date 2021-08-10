/*-----------------------------------------------------------------------*
 * filename - gp.c
 *
 * function(s)
 *        __DefHandler - print registers on exception or unwind and
 *                       terminate on unhandled exception.
 *----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

#define INCL_USER
#include <ntbc.h>
#include <_io.h>
#include <dosexcpt.h>
#include <stdio.h>
#if defined(_MBCS)
#include <tchar.h>
#endif

extern unsigned _acrtused;              /* in startup code */

#pragma argsused
#pragma warn -rvl

ULONG __EHCC __DefHandler(PEXCEPTIONREPORTRECORD p,
                        struct _EXCEPTIONREGISTRATIONRECORD *q,
                        PCONTEXTRECORD r,
                        PVOID s)
{
    static char buf[256];
    static char filename[80];
    char *progname;
    char *why;

    switch (p->ExceptionNum)
    {
        case XCPT_ACCESS_VIOLATION:
            why = "Access violation";
            break;
        case XCPT_ILLEGAL_INSTRUCTION:
            why = "Illegal instruction";
            break;
        case XCPT_INTEGER_DIVIDE_BY_ZERO:
            why = "Integer divide by zero";
            break;
        case XCPT_PRIVILEGED_INSTRUCTION:
            why = "Privileged instruction";
            break;
        default:
            return (XCPT_CONTINUE_SEARCH);
    }
    GetModuleFileName(NULL, (PSTR)&filename, sizeof(filename));
#if defined(_MBCS)
    if ((progname = _tcsrchr(filename,_TEXT('\\'))) == NULL &&
        (progname = _tcsrchr(filename,_TEXT( ':'))) == NULL)
#else
    if ((progname = strrchr(filename,'\\')) == NULL &&
        (progname = strrchr(filename, ':')) == NULL)
#endif
        progname = filename;
    else
        progname++;
    wsprintf(buf,"Exception %08X: %s\r\n"
            "Module: %s Start address: %08X\r\n"
            "EAX=%08X EBX=%08X ECX=%08X EDX=%08X ESI=%08X\r\n"
            "EDI=%08X EIP=%08X EBP=%08X ESP=%08X EFL=%08X",
            p->ExceptionNum, why,
            progname, &_acrtused,
            r->Eax, r->Ebx, r->Ecx, r->Edx, r->Esi,
            r->Edi, r->Eip, r->Ebp, r->Esp, r->EFlags);
    _ErrorExit(buf);
}

#if DEBUG
void main(void)
{
    char *p = NULL;

    printf("About to access NULL pointer\n");
    *p = 0;
}
#endif


