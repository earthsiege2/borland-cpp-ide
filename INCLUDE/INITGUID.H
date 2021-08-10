/*****************************************************************************\
*                                                                             *
* initguid.h -  Definitions for controlling GUID initialization                           *
*                                                                             *
*               OLE Version 2.0                                               *
*                                                                             *
\*****************************************************************************/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__INITGUID_H)
#define __INITGUID_H

// Include after compobj.h to enable GUID initialization.  This 
//              must be done once per exe/dll.
//
// After this file, include one or more of the GUID definition files.
//
// NOTE: ole2.lib contains references to all GUIDs defined by OLE.

#ifndef DEFINE_GUID
#error "initguid: must include compobj.h first."
#endif

#undef DEFINE_GUID

#ifdef _MAC
#define __based(a)
#endif

#if defined(WIN32) || defined(__BORLANDC__)
#define __based(a)  FAR
#endif

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
    EXTERN_C const GUID CDECL __based(__segname("_CODE")) name \
		    = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }

#endif  /* __INITGUID_H */
