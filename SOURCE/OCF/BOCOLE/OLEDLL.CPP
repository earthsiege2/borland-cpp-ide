//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
// $Revision:   2.3  $
//
// OleDLL.cpp -- DLL entry/exit points for BOLE.DLL
//----------------------------------------------------------------------------
#include <BOle32.h>
#include <Windows.h>
#include "OLE2UI.h"

HINSTANCE boleInst;

// This works around an RTL bug which leaves Win87EM.DLL locked
//
#if defined(__BORLANDC__) && !defined(WIN32)
	extern unsigned _LockWIN87EM;
	void WhackRTL ()	{ _LockWIN87EM = FALSE; }
	#pragma startup WhackRTL 0
#endif

OLEDBGDATA_MAIN ("BOLE")

extern "C" int FAR PASCAL LibMain( HINSTANCE hInst, WORD, WORD, LPSTR )
{
	boleInst = hInst;
	OleUIInitialize (boleInst, NULL);
	return 1;
}

extern "C" int FAR PASCAL WEP(int /*systemExit*/)
{
	OleUIUninitialize ();
	return 1;
}

#ifdef WIN32

extern "C" BOOL WINAPI DllEntryPoint( HINSTANCE hInst, DWORD dwReason, LPVOID )
{
	switch  (dwReason) {
		case DLL_PROCESS_ATTACH:
			LibMain(hInst, NULL, NULL, NULL);
			break;
		case DLL_PROCESS_DETACH:
			WEP(NULL);
			break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
			break;
	}

	return 1;
}

#endif


