/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1993, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <windows.h>
#include <_defs.h>
#include <excpt.h>

extern void _RTLENTRY _EXPFUNC __ErrorMessage(const char *errorString);

/* ---------------------------------------------------------------------------
 * UnhandledPtr is the function that will supersede the top level exception
 * handler.  If this is variable is 0, the default behavior of the
 * the UnhandledExceptionFilter() function is used.
 */
static PTOP_LEVEL_EXCEPTION_FILTER UnhandledPtr = 0;

/* ---------------------------------------------------------------------------
 * Name:        SetUnhandledExceptionFilter
 *
 * Prototype:   LPTOP_LEVEL_EXCEPTION_FILTER SetUnhandledExceptionFilter(
 *                       LPTOP_LEVEL_EXCEPTION_FILTER pTopLevelExceptionFilter)
 *
 * Description: The SetUnhandledExceptionFilter() function lets an application
 *              supersede the top level exception handler.  After calling this
 *              function, if an exception occurs in a process that is not
 *              being debugged, and the exception makes it to the unhandled
 *              exception filter, that filter will call the exception filter
 *              specified by the pTopLevelExceptionFilter parameter.
 *
 * Parameters:  pTopLevelExceptionFilter - Supplies the address of a top level
 *              exception filter function that will be called whenever
 *              UnhandledExceptionFilter() gets control, and the process is
 *              not being debugged.  A value of 0 for this paramater specifies
 *              default handling within UnhandledExceptionFilter().
 *
 * Returns:     The function returns the address of the previous exception
 *              filter established with the function.  A 0 return value means
 *              that there is no current top level exception handler.
 */
LPTOP_LEVEL_EXCEPTION_FILTER WINAPI _EXPFUNC SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER pTopLevelExceptionFilter)
{
    LPTOP_LEVEL_EXCEPTION_FILTER poldHandler = UnhandledPtr;

    UnhandledPtr = pTopLevelExceptionFilter;

    return poldHandler;
}


/* ---------------------------------------------------------------------------
 * Name:        UnhandledExceptionFilter
 *
 * Prototype:   long UnhandledExceptionFilter(
 *                   PEXCEPTION_POINTERS pexpExceptionInfo)
 *
 * Description: The UnhandledExceptionFilter() function passes unhandled
 *              exceptions to the debugger.  Otherwise, it optionally displays
 *              an error message and causes the exception handler to be
 *              executed.  This function should be called only from within the
 *              filter expression of a try-except exception handler.
 *
 * Parameters:  pexpExceptionFilter - Points to an EXCEPTION_POINTERS structure
 *              containing a description of the exception and the processor
 *              context at the time of the exception.
 *
 * Returns:     If the process is being debugged, EXCEPTION_CONTINUE_SEARCH
 *              is returned, so the exception can be passed (as second
 *              chance) to the application's debugger.  Otherwise,
 *              EXCEPTION_EXECUTE_HANDLER is returned.
 */
long WINAPI _EXPFUNC UnhandledExceptionFilter(PEXCEPTION_POINTERS pexpExceptionInfo)
{
    /* Insert code to check if process is being debugged.  If so, return
     * EXCEPTION_CONTINUE_SEARCH. */

    /* Override the actions of UnhandledExceptionFilter() if the user has
     * chosen to do so. */
    if(UnhandledPtr)
    {
        long result = UnhandledPtr(pexpExceptionInfo);

        /* If the user-defined unhandled exception filter function returns
         * EXCEPTION_CONTINUE_SEARCH, then the default actions of
         * UnhandledExceptionFilter() should be executed. */
        if(result != EXCEPTION_CONTINUE_SEARCH)
            return result;
    }

    /* Display an error message indicating that an unhandled exception was
     * encountered.  Under Windows or Win32, if the error mode is configured
     * to suppress the error message, make sure that none is displayed. */
    {
        char *errorString = "Unhandled exception encountered";

#if defined(_Windows)
        UINT oldErrorMask;  // Error mode mask.

        oldErrorMask = SetErrorMode(0);

        if(!(oldErrorMask & SEM_NOGPFAULTERRORBOX))
            __ErrorMessage(errorString);

        SetErrorMode(oldErrorMask);
#else
        __ErrorMessage(errorString);
#endif
    }

    return EXCEPTION_EXECUTE_HANDLER;
}
