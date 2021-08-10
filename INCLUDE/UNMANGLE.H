/*------------------------------------------------------------------------
 * filename - unmangle.h (C++ decorated symbol unmangler)
 *
 * function(s)
 *
 *   _rtl_unmangle
 *   _rtl_setUnmangleMode
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.4  $        */

#ifndef _UNMANGLE_
#define _UNMANGLE_

#include <_defs.h>
#define _UMAPI _RTLENTRY _EXPFUNC

typedef enum
{
    /* The kind of symbol. */

    UM_UNKNOWN       = 0x00000000,

    UM_FUNCTION      = 0x00000001,
    UM_CONSTRUCTOR   = 0x00000002,
    UM_DESTRUCTOR    = 0x00000003,
    UM_OPERATOR      = 0x00000004,
    UM_CONVERSION    = 0x00000005,

    UM_DATA          = 0x00000006,
    UM_THUNK         = 0x00000007,
    UM_TPDSC         = 0x00000008,
    UM_VTABLE        = 0x00000009,
    UM_VRDF_THUNK    = 0x0000000a,
    UM_DYN_THUNK     = 0x0000000b,

    UM_KINDMASK      = 0x000000ff,

    /* Modifier (is it a member, template?). */

    UM_QUALIFIED     = 0x00000100,
    UM_TEMPLATE      = 0x00000200,

    UM_VIRDEF_FLAG   = 0x00000400,
    UM_FRIEND_LIST   = 0x00000800,
    UM_CTCH_HNDL_TBL = 0x00001000,
    UM_OBJ_DEST_TBL  = 0x00002000,
    UM_THROW_LIST    = 0x00004000,
    UM_EXC_CTXT_TBL  = 0x00008000,
    UM_LINKER_PROC   = 0x00010000,
    UM_SPECMASK      = 0x0001fc00,

    UM_MODMASK       = 0x00ffff00,

    /* Some kind of error occurred. */

    UM_BUFOVRFLW     = 0x01000000,
    UM_HASHTRUNC     = 0x02000000,
    UM_ERROR         = 0x04000000,

    UM_ERRMASK       = 0x7f000000,

    /* This symbol is not a mangled name. */

    UM_NOT_MANGLED   = 0x80000000,
}
    _umKind;

#define _UM_MAXBUFFLEN      8192      /* maximum output length */

#ifdef __cplusplus
extern  "C"
{
#endif

_umKind _UMAPI
_rtl_unmangle(char   *       src,     /* the string to be unmangled */
              char   *       dest,    /* the unmangled output string */
              unsigned       maxlen,  /* the max length of the output string */
              char   *       qualP,   /* optional additional string to hold
                                         only the qualifiers */

              char   *       baseP,   /* optional additional string to hold
                                         only the base name */
              int            doArgs); /* handle function arguments? */

int _UMAPI _rtl_setUnmangleMode(int); /* currently not implemented */

#ifdef __cplusplus
}
#endif

#endif