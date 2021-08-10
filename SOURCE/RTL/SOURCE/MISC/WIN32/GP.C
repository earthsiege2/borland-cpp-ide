/*-----------------------------------------------------------------------*
 * filename - gp.c
 *
 * function(s)
 *        __DefHandler - print registers on exception or unwind and
 *                       terminate on unhandled exception.
 *----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1992, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_USER
#include <ntbc.h>
#include <_io.h>
#include <dosexcpt.h>
#include <stdio.h>

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


