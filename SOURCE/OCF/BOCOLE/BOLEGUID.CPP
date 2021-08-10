//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// $Revision:   2.2  $
//
//  Forces the OLE2 GUIDs to be compiled into the code segment, since 
//  compiling them into the data segment produces multi-instance problems.
//
// NOTE! This file must be compiled with the following flags for 16-bit:
//   -zE_TEXT -zFCODE    (this forces the GUIDs into the code segment)
//----------------------------------------------------------------------------
#define INITGUID		// stick the guids in this module

#ifdef	WIN32
	#include <Windows.h>
	#include <InitGUID.h>
#endif

#define INIT_BGUID		// stick the guids in this module

#include "BOle.h"

