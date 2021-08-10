/*++

Module Name:

    poppack.h

Abstract:

    This file turns packing of structures off.  (That is, it enables
    automatic alignment of structure fields.)  An include file is needed
    because various compilers do this in different ways.

    poppack.h is the complement to pshpack?.h.  An inclusion of poppack.h
    MUST ALWAYS be preceded by an inclusion of one of pshpack?.h, in one-to-one
    correspondence.

    For Microsoft compatible compilers, this file uses the pop option
    to the pack pragma so that it can restore the previous saved by the
    pshpack?.h include file.

--*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1994, 1996 by Borland International
 *      All Rights Reserved.
 *
 */
#pragma nopackwarning

#if ! (defined(lint) || defined(_lint))
#  if ( _MSC_VER >= 800 ) || (defined(__BORLANDC__))
#    pragma warning(disable:4103)
#    if !(defined( MIDL_PASS )) || defined( __midl )
#      pragma pack(pop)
#    else
#      pragma pack()
#    endif
#  else
#    pragma pack()
#  endif
#endif // ! (defined(lint) || defined(_lint))
