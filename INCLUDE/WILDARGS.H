/*  wildargs.h

    Support for overriding the built-in wild card handling routines
    or the entire command line processing routines.

*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1999, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


/* $Revision: 9.7.2.1 $ */

#ifndef __WILDARGS_H
#define __WILDARGS_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* _PFN_ADDARG: Typedef for the addarg function pointer.  This pfn parameter
   to the wild card processing routines will contain the function to call to
   add an argument into the argv[] array. The second parameter: _makecopy is
   a bool that specifies to the RTL whether or not this argument should have
   new memory allocated for it and then be copied into.
*/
typedef void _RTLENTRY (* _PFN_ADDARG)(void *_arg, int _makecopy);


/* _argv_expand_ptr: Pointer to wildcard expansion function.  Normally it
   points to a function that simply adds an argument without expansion. To
   cause the built-in wild card expander to be used, simply point this to
   the equivalent version of _expand_wild.  You can also point it to your
   own function and it will be called for every wild card parameter the
   start up code finds.  You can then expand it however you wish, calling
   the passed-in pointer _pfn_addarg() to insert each of the expanded items.
*/
extern void _RTLENTRY (* _RTLENTRY _argv_expand_ptr)(char *_arg, _PFN_ADDARG _pfn_addarg);
extern void _RTLENTRY (* _RTLENTRY _wargv_expand_ptr)(wchar_t *_arg, _PFN_ADDARG _pfn_addarg);


/* _expand_wild: Built-in handler for expanding wild cards.  This is the
   internal function to which _argv_expand_ptr can be pointed in order to
   have wild card arguments expanded.
*/
void _RTLENTRY _EXPFUNC _expand_wild(char *_arg, _PFN_ADDARG _pfn_addarg);
void _RTLENTRY _EXPFUNC _wexpand_wild(wchar_t *_arg, _PFN_ADDARG _pfn_addarg);


/* _handle_setargv: Built-in handler for processing the entire command line.
   This is the name of the function that handles the processing of the
   entire command line. You can implement this function to get control of
   the entire command line argument process. The exe name (for argv[0]) has
   already been allocated and formatted for you and is passed in as _argv0.
   You simply need to call _pfn_addarg(_argv0,0) on it to add it in.  The
   RTL will manage and free the memory assocated with _argv0.  Next the
   entire command line is passed in as _cmdline.  You should handle quotes
   and wild cards however you wish. For each parameter that you isolate into
   a separate string, you should call through the passed-in pointer
   _pfn_addarg() to have it added to the argv[] list.  The second parameter
   to _pfn_addarg() is a bool that specifies to the RTL whether or not this
   argument should have new memory allocated for it and then be copied into.
   Regardless of who allocates the memory for it (you or _pfn_addarg), you
   will be responsible for freeing it.  This should be done from the
   _handle_exitargv() routine.

   The return value should be zero for failure (which will cause NULL
   parameters to be passed to main) or non-zero for success.

   For an example of this handler see the source for the RTL's default
   version in: CBuilder/Source/rtl/source/process/hsargv.c

   NOTE: Only the RTL's internal version of this function will call out
   through _argv_expand_ptr upon each wild card argument found.  If you
   replace _handle_setargv then you'll have to do everything yourself.
*/
int _RTLENTRY _handle_setargv(char *_argv0, char *_cmdline, _PFN_ADDARG _pfn_addarg);
int _RTLENTRY _handle_wsetargv(wchar_t *_argv0, wchar_t *_cmdline, _PFN_ADDARG _pfn_addarg);


/* _handle_exitargv: Built-in cleanup handler for the entire command line
   processor.  Here is where all memory should be freed that you directly
   (or indirectly via _pfn_addarg) caused to be allocated during the
   _handle_setargv routine.
*/
void _RTLENTRY _handle_exitargv(void);
void _RTLENTRY _handle_wexitargv(void);


#ifdef __cplusplus
} // "C"
#endif

#endif /* __WILDARGS_H */