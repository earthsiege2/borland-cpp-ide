/*++

Module Name:

    pshpack1.h

Abstract:

    This file turns 1 byte packing of structures on.  (That is, it disables
    automatic alignment of structure fields.)  An include file is needed
    because various compilers do this in different ways.  For Microsoft
    compatible compilers, this files uses the push option to the pack pragma
    so that the poppack.h include file can restore the previous packing
    reliably.

    The file poppack.h is the complement to this file.

--*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1994 by Borland International
 *      All Rights Reserved.
 *
 */
#pragma nopackwarning

#if ! (defined(lint) || defined(_lint))
#  ifndef RC_INVOKED
#    if ( _MSC_VER >= 800 ) || (defined(__BORLANDC__) && defined(__FLAT__))
#      pragma warning(disable:4103)
#      if !(defined( MIDL_PASS )) || defined( __midl )
#        pragma pack(push)
#      endif
#      pragma pack(1)
#    elif defined(__BORLANDC__) && !defined(__FLAT__)
#      pragma option -a-
#    else
#      pragma pack(1)
#    endif
#  endif // ndef RC_INVOKED
#endif // ! (defined(lint) || defined(_lint))
