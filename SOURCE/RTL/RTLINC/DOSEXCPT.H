/*  dosexcpt.h

    Portable functions for registering exception handlers.
    You must include <windows.h> before including this file.

*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


/* $Revision: 9.4.2.1 $ */

#ifndef __DOSEXCPT_H
#define __DOSEXCPT_H

#pragma warn -nak   /* Ignore non-ansi keywords */

#if defined(__WIN32__)
#define __EHCC __cdecl
#else
#define __EHCC __syscall
#endif

#if !defined(__OS2__)

#define XCPT_CONTINUE_EXECUTION 0
#define XCPT_CONTINUE_SEARCH    1

#define XCPT_ACCESS_VIOLATION           STATUS_ACCESS_VIOLATION
#define XCPT_ILLEGAL_INSTRUCTION        STATUS_ILLEGAL_INSTRUCTION
#define XCPT_FLOAT_DIVIDE_BY_ZERO       STATUS_FLOAT_DIVIDE_BY_ZERO
#define XCPT_FLOAT_INVALID_OPERATION    STATUS_FLOAT_INVALID_OPERATION
#define XCPT_FLOAT_OVERFLOW             STATUS_FLOAT_OVERFLOW
#define XCPT_FLOAT_STACK_CHECK          STATUS_FLOAT_STACK_CHECK
#define XCPT_FLOAT_UNDERFLOW            STATUS_FLOAT_UNDERFLOW
#define XCPT_INTEGER_DIVIDE_BY_ZERO     STATUS_INTEGER_DIVIDE_BY_ZERO
#define XCPT_PRIVILEGED_INSTRUCTION     STATUS_PRIVILEGED_INSTRUCTION
#define XCPT_UNABLE_TO_GROW_STACK       STATUS_STACK_OVERFLOW

/*
 * ExceptionReportRecord
 *
 * This structure contains machine-independent information about an
 * exception/unwind.  No system exception will ever have more than
 * EXCEPTION_MAXIMUM_PARAMETERS parameters.  User exceptions are not
 * bound to this limit.
 */

struct _EXCEPTIONREPORTRECORD
{
    ULONG   ExceptionNum;               /* exception number */
    ULONG   fHandlerFlags;
    struct  _EXCEPTIONREPORTRECORD *NestedExceptionReportRecord;
    PVOID   ExceptionAddress;
    ULONG   cParameters;                /* Size of Exception Specific Info */
    ULONG   ExceptionInfo[EXCEPTION_MAXIMUM_PARAMETERS];
                                        /* Exception Specfic Info */
};

typedef struct _EXCEPTIONREPORTRECORD EXCEPTIONREPORTRECORD;
typedef struct _EXCEPTIONREPORTRECORD *PEXCEPTIONREPORTRECORD;

/*
 * ExceptionRegistrationRecord
 *
 * These are linked together to form a chain of exception handlers that
 * will be dispatched to upon receipt of an exception.
 */

typedef struct _CONTEXT CONTEXTRECORD;
typedef struct _CONTEXT *PCONTEXTRECORD;

struct _EXCEPTIONREGISTRATIONRECORD;

typedef ULONG (__EHCC *ERR)(PEXCEPTIONREPORTRECORD,
                            struct _EXCEPTIONREGISTRATIONRECORD *,
                            PCONTEXTRECORD,
                            PVOID);

struct _EXCEPTIONREGISTRATIONRECORD
{
    struct _EXCEPTIONREGISTRATIONRECORD * volatile prev_structure;
    ERR ExceptionHandler;
};

typedef struct _EXCEPTIONREGISTRATIONRECORD EXCEPTIONREGISTRATIONRECORD;
typedef struct _EXCEPTIONREGISTRATIONRECORD *PEXCEPTIONREGISTRATIONRECORD;

#endif  /* !__OS2__ */

/* End of exception chain marker. */
#define END_OF_CHAIN        ((PEXCEPTIONREGISTRATIONRECORD) -1)

/* Functions for installing and removing exception handler. */

#ifdef __cplusplus
extern "C" {
#endif

void __cdecl _SetExceptionHandler  (PEXCEPTIONREGISTRATIONRECORD);
void __cdecl _UnsetExceptionHandler(PEXCEPTIONREGISTRATIONRECORD);
void __cdecl _UnwindException      (PEXCEPTIONREGISTRATIONRECORD,
                                     PVOID, /* target EIP */
                                     PEXCEPTIONREPORTRECORD);

#if defined(__OS2__)
ERR  __stdcall _SetUserHandler     (ERR);
#else
ERR  __cdecl _SetUserHandler       (ERR);
#endif

#ifdef  __cplusplus
}
#endif

#pragma warn .nak   /* Ignore non-ansi keywords */

#endif  /* __DOSEXCPT_H */
