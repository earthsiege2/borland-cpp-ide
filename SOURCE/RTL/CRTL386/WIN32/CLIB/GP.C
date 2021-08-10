/*-----------------------------------------------------------------------*
 * filename - gp.c
 *
 * function(s)
 *        _DefHandler - print registers on exception or unwind and
 *			terminate on unhandled exception.
 *----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1992, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_USER
#include <ntbc.h>
#include <_io.h>
#include <dosexcpt.h>
#include <stdio.h>

#define DEBUG       0       /* set to 1 to enable debug code */
#define UNWINDING   2

extern void cdecl   __doGlobalUnwind(void);
extern void         __call_terminate(void);

ERR _SetUserHandler(ERR handler);       /* in startup code */
extern unsigned _acrtused;              /* in startup code */

#pragma argsused
#pragma warn -rvl

ULONG __EHCC _DefHandler(PEXCEPTIONREPORTRECORD p,
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
            if (p->fHandlerFlags & UNWINDING)
                return (XCPT_CONTINUE_SEARCH);

            _EAX = (unsigned)q;
            _EDX = (unsigned)p;
            __doGlobalUnwind();
            __call_terminate();
    }
    GetModuleFileName(NULL, (PSTR)&filename, sizeof(filename));
    if ((progname = strrchr(filename,'\\')) == NULL &&
        (progname = strrchr(filename, ':')) == NULL)
        progname = filename;
    else
        progname++;
    sprintf(buf,"Exception %p: %s\r\n"
            "Module: %s Start address: %p\r\n"
            "EAX=%p EBX=%p ECX=%p EDX=%p ESI=%p\r\n"
            "EDI=%p EIP=%p EBP=%p ESP=%p EFL=%p",
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
